#include <iostream>
#include <string>
using namespace std;

struct package {
    string packageName;
    int price;
    int id;
    string dataQuota;
    package *next, *prev;
};
package *headPackage = NULL, *tailPackage = NULL, *tempPackage = NULL;
int idPackage = 6;

struct customer {
    int Id;
    string customerName;
    string customerPhone;
    package packages[2];
    customer *next, *prev;
};
customer *headCustomer = NULL, *tailCustomer = NULL, *tempCustomer = NULL;
int idCustomer = 1;


bool isIdFinded(int id, char type ) {
    if(type == 'C') {
        tempCustomer = headCustomer;
        while(tempCustomer != NULL) {
            if(tempCustomer->Id == id) {
                return false;
            };
            tempCustomer = tempCustomer->next;
        };
        return true;
    } else {
        tempPackage = headPackage;
        while(tempPackage != NULL) {
            if(tempPackage->id == id) {
                return false;
            };
            tempPackage = tempPackage->next;
        };
        return true;
    };
};

void showPackages() {
    system("cls");
    tempPackage = headPackage;

    cout << "\t\t Paket yang tersedia" << endl << endl;
    if(!tempPackage) cout << "Saat ini tidak ada paket yang tersedia" << endl;

    while (tempPackage != NULL) {
        cout << "ID: " << tempPackage->id << " | Nama paket: " << tempPackage->packageName << ", harga: " << tempPackage->price << ", kuota: " << tempPackage->dataQuota << endl;
        tempPackage = tempPackage->next;
    };
    cout << endl;
};

void showCustomers() {
    system("cls");
    tempCustomer = headCustomer;

    cout << "\t\t Pelanggan yang terdaftar" << endl << endl;
    if(!tempCustomer) cout << "Tidak ada pelanggan yang terdaftar!" << endl;

    while(tempCustomer != NULL) {
        cout << "| ID pelanggan : " << tempCustomer->Id << endl;
        cout << "| Nama pelanggan : " << tempCustomer->customerName << endl;
        cout << "| Nomor pelanggan : " << tempCustomer->customerPhone << endl;
        cout << "| Paket terdaftar : " << endl;
        for(int i = 0; i < 2; i++) {
            if(tempCustomer->packages[i].id == 0) {
                cout << "";
            } else {
                cout << "\tPaket ke-" << i+1 << ". Nama paket: " << tempCustomer->packages[i].packageName << ", harga: " << tempCustomer->packages[i].price << ", kuota: " << tempCustomer->packages[i].dataQuota << endl;
            };
        };
        tempCustomer = tempCustomer->next;
    cout << endl;
    };
    cout << endl;
};

// void addPackage() {
//     system("cls");
//     string name;
//     string quota;
//     int price;
//     package *newPackage = new package;

//     cout << "Masukkan nama paket : "; getline(cin, name);
//     cout << "Masukkan harga paket : "; cin >> price;
//     cout << "Masukkan jumlah kuota paket : "; getline(cin, quota);

//     newPackage->packageName = name;
//     newPackage->price = price;
//     newPackage->dataQuota = quota;

//     if(!headPackage){
//         headPackage = tailPackage = newPackage;
//     } else {
//         tailPackage->next = newPackage;
//         tailPackage = newPackage;
//     };
//     newPackage = NULL;
// };

package addPackageToCustomer () {
    int id;
    tempPackage = headPackage;
    package *currPackage = new package;

    cout << "Masukkan paket untuk pelanggan berdasarkan nomor/id" << endl;
    cout << "Pilihan : "; cin >> id;

    while(tempPackage != NULL) {
        if(tempPackage->id == id) {
            currPackage = tempPackage;
            return *currPackage;
        };
        tempPackage = tempPackage->next;
    };
    cout << "Paket dengan ID " << id << " tidak ditemukan! Silahkan ulangi" << endl;
    system("pause");
    return *currPackage;
};

void addCustomer() {
    system("cls");
    int choises;
    string name;
    string phone;
    customer *newCustomer = new customer;

    cout << "\t\tMenambahkan pelanggan baru" << endl << endl;
    cout << "Masukkan nama pelanggan : "; getline(cin, name);
    cout << "Masukkan nomor hp pelanggan : "; getline(cin, phone);

    newCustomer->Id = idCustomer;
    newCustomer->customerName = name;
    newCustomer->customerPhone = phone;
    newCustomer->next = NULL;

    cout << "Masukkan pilihan paket untuk pelanggan : " << endl;
    cout << "1. Paket ke-1" << endl;
    cout << "2. Paket ke-2" << endl;
    cout << "Plihan : "; cin >> choises;
    showPackages();

    package packageCustomer;
    do{
        packageCustomer = addPackageToCustomer();
    } while(packageCustomer.id == 0);

    switch (choises) {
    case 1:
        newCustomer->packages[0] = packageCustomer;
        newCustomer->packages[1].id = 0;
        break;
    case 2:
        newCustomer->packages[1] = packageCustomer;
        newCustomer->packages[0].id = 0;
        break;
    default:
        break;
    };

    if(!headCustomer) {
        headCustomer = tailCustomer = newCustomer;
    } else {
        tailCustomer->next = newCustomer;
        tailCustomer = newCustomer;
    };
    idCustomer++;

    cout << endl << name << " telah ditambahkan" << endl;
    system("pause");
};

void updateCustomer() {
    customer *tempCustomer2 = headCustomer;
    int choisesCustomer;
    char type = 'C';

    if(headCustomer == NULL) {
        system("cls");
        cout << "\t\tBelum ada pengguna yang terdaftar!" << endl << endl;
        system("pause");
        return;
    }

    // Menampilkan semua data pengguna agar mudah dalam menemukan ID nya.
    do {
        tempCustomer = headCustomer;
        system("cls");
        cout << "\t\tData pelanggan " << endl << endl;
        while(tempCustomer != NULL) {
            cout << "| ID: " << tempCustomer->Id << ". " << tempCustomer->customerName << endl;
            tempCustomer = tempCustomer->next;
        };
        cout << endl << "Pilih ID pelanggan yang ingin diupdate datanya" << endl;
        cout << "Pilihan : "; cin >> choisesCustomer;

    } while (isIdFinded(choisesCustomer, type));
    
    tempCustomer = headCustomer;
    // Mencari dan menampilkan data customer yang akan diubah.
    while(tempCustomer != NULL) {
        if(tempCustomer->Id == choisesCustomer) {
            int choises;
            do {
                system("cls");
                cout << "\t\t Data pelanggan" << endl;
                cout << "\t\t ==============" << endl << endl;
                cout << "| ID pelanggan : " << tempCustomer->Id << endl;
                cout << "| Nama pelanggan : " << tempCustomer->customerName << endl;
                cout << "| Nomor pelanggan : " << tempCustomer->customerPhone << endl;
                cout << "| Paket terdaftar : " << endl;
                for(int i = 0; i < 2; i++) {
                    if(tempCustomer->packages[i].id == 0) {
                        cout << "";
                    } else {
                        cout << "\t" << "Paket ke-" << i+1 << ". Nama paket: " << tempCustomer->packages[i].packageName << ", harga: " << tempCustomer->packages[i].price << ", kuota: " << tempCustomer->packages[i].dataQuota << endl;
                    };
                };

                cout << endl << "Apa yang ingin dirubah?" << endl;
                cout << "|======================" << endl;
                cout << "| 1. Data pengguna" << endl;
                cout << "| 2. Kuota pengguna" << endl;
                cout << "|======================" << endl;
                cout << "| 0. Kembali" << endl;
                cout << "|======================" << endl;
                cout << "Pilihan : "; cin >> choises; cin.ignore();

                if(choises == 0) break;
            } while (choises < 1 || choises > 2);

            // 2 Kategori perubahan yang akan diupdate
            switch (choises) {
            case 1 : {
                int choises2;
                string newData;
                do {
                    system("cls");
                    cout << endl << "| 1. Update nama pengguna." << endl;
                    cout << "| 2. Update nomor pengguna." << endl;
                    cout << "Pilihan : "; cin >> choises2; cin.ignore();

                    // pengkondisian untuk merubah nama atau nomor.
                    if(choises2 == 1) {
                        cout << "Masukkan nama baru : "; getline(cin, newData);
                        while (tempCustomer2 != NULL) {
                            if(tempCustomer2->Id == choisesCustomer) {
                                tempCustomer2->customerName = newData;
                                cout << "Nama telah diupdate!" << endl;
                            };
                            tempCustomer2 = tempCustomer2->next;
                        };
                    } else {
                        cout << "Masukkan nomor baru : "; getline(cin, newData);
                        while (tempCustomer2 != NULL) {
                            if(tempCustomer2->Id == choisesCustomer) {
                                tempCustomer2->customerPhone = newData;
                                cout << "Nomor telah diupdate!" << endl;
                            };
                            tempCustomer2 = tempCustomer2->next;
                        };
                    }
                } while (choises2 < 1 || choises2 > 2);
                system("pause");
                break;
            }
            case 2: {
                int choises2, choises3;            

                do {
                    system("cls");
                    cout << "Paket yang ingin dirubah : " << endl;
                    cout << "| 1. Paket ke-1" << endl;
                    cout << "| 2. Paket ke-2" << endl;
                    cout << "Pilihan : "; cin >> choises2;
                } while(choises2 < 1 || choises2 > 2);
                
                showPackages();
                cout << "Pilih paket berdasarkan ID : "; cin >> choises3; cin.ignore();

                // Menemukan ID pengguna yang akan dirubah dan mencari paket sesuai id.
                while(tempCustomer2 != NULL) {
                    if(tempCustomer2->Id == choisesCustomer) {
                        tempPackage = headPackage;
                        while (tempPackage != NULL) {
                            if(tempPackage->id == choises3) {
                                tempCustomer2->packages[choises2-1] = *tempPackage;
                                cout << "Kuota telah diupdate!" << endl;
                            };
                            tempPackage = tempPackage->next;
                        };
                    }
                    tempCustomer2 = tempCustomer2->next;
                }
                system("pause");
                break;
            }
            default:
                break;
            }
        };
        tempCustomer = tempCustomer->next;
    };
};

void deleteCustomer() {
    customer *nextCustomer = NULL, *previousCustomer = NULL;
    tempCustomer = headCustomer;
    int choisesCustomer;
    char type = 'C';

    if(tempCustomer == NULL) {
        system("cls");
        cout << "\t\tBelum ada pengguna yang terdaftar!" << endl << endl;
        system("pause");
        return;
    };

    do {
        tempCustomer = headCustomer;
        system("cls");
        cout << "\t\tData pengguna " << endl << endl;
        while(tempCustomer != NULL) {
            cout << "| ID: " << tempCustomer->Id << ". " << tempCustomer->customerName << endl;
            tempCustomer = tempCustomer->next;
        };

        cout << endl << "Pilih ID pelanggan yang ingin dihapus" << endl;
        cout << "Pilihan : "; cin >> choisesCustomer; cin.ignore();

        
    } while (isIdFinded(choisesCustomer, type));

    // Mencari dan menghapus pengguna jika ditemukan.
    if(headCustomer->Id == choisesCustomer) {
        tempCustomer = headCustomer;
        headCustomer = headCustomer->next;
        cout << endl << tempCustomer->customerName << " berhasil dihapus!" << endl;
        delete tempCustomer;
        system("pause");
        return;
    };

    tempCustomer = headCustomer;
    while(tempCustomer != NULL) {
        if(tempCustomer->Id == choisesCustomer) {
            previousCustomer->next = nextCustomer->next;
            cout << endl << tempCustomer->customerName << " berhasil dihapus!" << endl;
            delete nextCustomer;
            system("pause");
            break;
        };
        previousCustomer = tempCustomer;
        nextCustomer = tempCustomer->next;
        
        tempCustomer = tempCustomer->next;
    };
};

void addPackage() {
    system("cls");
    int price;
    string name, kuota;

    package *newPackage = new package;
    cout << "\t\t Menambahkan paket baru" << endl << endl;
    cout << "Masukkan nama paket : "; getline(cin, name);
    cout << "Masukkan jumlah kuota : "; getline(cin, kuota);
    cout << "Masukkan harga paket : "; cin >> price;

    newPackage->id = idPackage;
    newPackage->packageName = name;
    newPackage->dataQuota = kuota;
    newPackage->price = price;
    newPackage->next = NULL;

    if(!headPackage) {
        headPackage = tailPackage = newPackage;
    } else {
        tailPackage->next = newPackage;
        tailPackage = newPackage;
    };
    cout << endl << name << " telah ditambahkan !" << endl << endl;
    system("pause");
    idPackage++;
};

void deletePackage() {
    package *nextPackage = NULL, *prevPackage = NULL;
    int choises;
    char type = 'P';

    if(!headPackage) {
        system("cls");
        cout << "\t\tBelum ada paket kuota yang terdaftar!" << endl << endl;
        system("pause");
        return;
    };

    // Mencari dan memvalidasi ID yang dikirimkan
    do {
        showPackages();
        cout << endl << "Pilih ID paket yang ingin dihapus" << endl;
        cout << "Pilihan : "; cin >> choises;
    }  while (isIdFinded(choises, type));
    
    // Menghapus paket berdasarkan ID yang telah divalidasi
    if(headPackage->id == choises) {
        tempPackage = headPackage;
        headPackage = headPackage->next;
        cout << endl << "Paket " << tempPackage->packageName << " telah dihapus." << endl;
        delete tempCustomer;
        system("pause");
        return;
    };

    tempPackage = headPackage;
    while(tempPackage != NULL) {

        if(tempPackage->id == choises) {
            prevPackage->next = nextPackage->next;
            cout << endl << "Paket " << tempPackage->packageName << " telah dihapus." << endl;
            delete nextPackage;
            system("pause");
            break;
        };
        prevPackage = tempPackage;
        nextPackage = tempPackage->next;

        tempPackage = tempPackage->next;
    };
};

void addDefaultDatas() {
    package *newPackage = new package;
    customer *newCostumer = new customer;

    newPackage->id = 1;
    newPackage->packageName = "Extra Combo VIP 30 hari";
    newPackage->dataQuota = "43GB";
    newPackage->price = 87000;
    newPackage->next = NULL;
    headPackage = tailPackage = newPackage;
    
    newPackage = new package;
    newPackage->id = 2;
    newPackage->packageName = "Extra Combo VIP 30 hari";
    newPackage->dataQuota = "27GB";
    newPackage->price = 60000;
    newPackage->next = NULL;
    tailPackage->next = newPackage;
    tailPackage = newPackage;

    newPackage = new package;
    newPackage->id = 3;
    newPackage->packageName = "Extra Combo Reguler 30 hari";
    newPackage->dataQuota = "30GB";
    newPackage->price = 50000;
    newPackage->next = NULL;
    tailPackage->next = newPackage;
    tailPackage = newPackage;

    newPackage = new package;
    newPackage->id = 4;
    newPackage->packageName = "Extra Combo Reguler 15 hari";
    newPackage->dataQuota = "15GB";
    newPackage->price = 25000;
    newPackage->next = NULL;
    tailPackage->next = newPackage;
    tailPackage = newPackage;

    newPackage = new package;
    newPackage->id = 5;
    newPackage->packageName = "Extra Combo Hemat 7 hari";
    newPackage->dataQuota = "7GB";
    newPackage->price = 10000;
    newPackage->next = NULL;
    tailPackage->next = newPackage;
    tailPackage = newPackage;


    newCostumer->customerName = "Irzi Rahmatullah";
    newCostumer->customerPhone = "087881814198";
    newCostumer->Id = 101;
    newCostumer->packages[0].id = 1;
    newCostumer->packages[0].packageName = "Extra Combo VIP 30 Hari";
    newCostumer->packages[0].dataQuota = "50GB";
    newCostumer->packages[0].price = 100000;
    newCostumer->next = NULL;
    headCustomer = tailCustomer = newCostumer;

    newCostumer = new customer;
    newCostumer->customerName = "Zaxchaxs Secondid";
    newCostumer->customerPhone = "088764678812";
    newCostumer->Id = 102;
    newCostumer->packages[0].id = 101;
    newCostumer->packages[0].packageName = "Extra kombo VIP Medium 30 Hari";
    newCostumer->packages[0].dataQuota = "30GB";
    newCostumer->packages[0].price = 54000;
    newCostumer->packages[1].id = 101;
    newCostumer->packages[1].packageName = "Extra kombo Mini";
    newCostumer->packages[1].dataQuota = "150GB";
    newCostumer->packages[1].price = 150000;
    newCostumer->next = NULL;
    tailCustomer->next = newCostumer;
    tailCustomer = newCostumer;
};


int main() {
    int pilihan;
    addDefaultDatas();
    do {
        system("cls");
        cout << "=========================================" << endl;
        cout << "|    Program Provider Telekomunikasi    |" << endl;
        cout << "=========================================" << endl;
        cout << "| 1. Tambahkan pelanggan\t\t|" << endl;
        cout << "| 2. Update data pelanggan\t\t|" << endl;
        cout << "| 3. hapus data pelanggan\t\t|" << endl;
        cout << "| 4. Lihat semua pelanggan\t\t|" << endl;
        cout << "=========================================" << endl;
        cout << "| 5. Tambahkan paket\t\t\t|" << endl;
        cout << "| 6. hapus paket\t\t\t|" << endl;
        cout << "| 7. Lihat semua paket\t\t\t|" << endl;
        cout << "=========================================" << endl;
        cout << "| 0. Keluar\t\t\t\t|" << endl;
        cout << "=========================================" << endl;
        cout << "Pilihan : "; cin >> pilihan; cin.ignore();

        switch (pilihan) {
        case 1 :
            addCustomer();
            break;
        case 2 :
            updateCustomer();
            break;
        case 3 : 
            deleteCustomer();
            break;
        case 4 : 
            showCustomers();
            system("pause");
            break;
        case 5 : 
            addPackage();
            break;
        case 6 : 
            deletePackage();
            break;
        case 7 : 
            showPackages();
            system("pause");
            break;
        default:

            break;
        }
    } while (pilihan != 0);

    return 0;
};