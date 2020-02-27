#include "header.h"
#include "Feature.h"

int main()
{
    char loop='y'; //looping untuk mengulangi perintah lantai
    char mau;
    int x=0, i=0; //iterasi untuk lantai
    string item_pus = "Urumi";

    //Cerita
    string text8 =  "Temanku mulai bertingkah aneh..";

    string text9 =  "Temanku mulai semakin bertingkah aneh..";

    string text11 = "Kesatria : Terimalah senjata ini untuk modal kamu melawan monster di dalam dungeon ini\n"
                    "Aku akan berjaga di luar apabila terjadi sesuatu yang tidak terduga , aku akan datang\n"
                    "Semoga berhasil,nak\n";

    prolog();
    while (loop == 'y'){
        floor = floor+1; //setiap loop akan menaikkan lantai 1 level
        cout << "Saat ini Anda sedang di lantai " << floor <<endl;
        cout << " " << endl;
        //switch case untuk event yang terjadi di suatu lantai
        switch (floor) {
            case 1 :
                if(first==true)
                {
                    cout << text11 << endl;
                    cout << " " << endl;
                    system("pause");
                    system("cls");
                    cout << "Selamat Anda Dapat Item !!" << endl;
                    cout << " " << endl;
                    cout << "KNIFE 3 Didapatkan";
                    cout << " " << endl;
                    inventory.push_back(vector<string>({items[0][0]}));
                    inventory[jumlahInventory].push_back(items[0][1]);
                    //senjata modal awal
                    jumlahInventory++;//tambah jumlah inventory
                    cout << " " << endl;
                    cout << "WARNING : Maksimal senjata yang dapat kamu Bawa : 5 " << endl;
                    cout << " " << endl;
                    invent();
                }
                    ///cerita
                break;
            case 2 :
                cout << "Lantai ini kosong!" << endl;
                cout << " " << endl;
                invent();
                if(first == true)
                {
                    cout << " " << endl;
                    cout << text8 << endl;
                }
                break;
            case 3 :
                cout << "Ada chest!" << endl;

                random();
                invent();
                break;
            case 4 :
                invent();
                cout << " " << endl;
                cout << "Ada Mid Boss!" << endl;
                cout << "Nama : " << enemy[0][0] << endl;
                cout << "Stat musuh : " << enemy[0][1] << endl;
                maxim();
                cout << "Warning : Jika Stat musuh Sama dengan stat Anda , Anda kalah" << endl;
                cout << " " << endl;
                cout << "Ingin melawan mid boss? (y/n)";
                cin >> mau;
                if(mau =='y')
                {
                    system("pause");
                    cout << " " << endl;
                    battle(enemy[0], maximum);
                }
                else
                {
                    cout << " " << endl;
                    cout << "Kembali ke lantai 2" << endl;
                    floor = 2;
                }
                break;
            case 5 :
                cout << "Ada chest!" << endl;

                random();
                invent();
                break;
            case 6 :
                cout << "Ada puzzle!" << endl;
                puzzle();
                cout << " " << endl;
                invent();
                if(first==true)
                {
                    cout << " " << endl;
                    cout << text9 << endl;
                }
                break;
            case 7 :
                if(first==true)
                {
                    plot_twist();
                    system("pause");
                    system("cls");
                }
                cout << "Final Boss" << endl;
                cout << " " << endl;
                invent();
                cout << " " << endl;
                cout << "Nama Musuh : " << enemy[1][0] << endl;
                cout << "Stat musuh : " << enemy[1][1] << endl;
                maxim();
                cout << "Warning : Jika Stat musuh Sama dengan stat Anda , Anda kalah" << endl;
                cout << " " << endl;
                cout << "Ingin melawan boss? (y/n)";
                cin >> mau;
                if(mau == 'y')
                {
                    system("pause");
                    system("cls");
                    first = false;
                    battle(enemy[1], maximum);
                }
                else
                {
                    cout << " " << endl;
                    cout << "Kembali ke lantai 2" << endl;
                    floor = 2;
                    first = false;
                }
                break;
        }
        //kondisi ketika lantai mencapai level 7, maka looping berhenti
        if (floor <7){
            cout << " " << endl;
            cout << "Apakah mau lanjut ke lantai " << floor+1 << "?(y/n) "; cin >> loop;
            system("cls");
        }
        else{
            cout << " " << endl;
            cout << "Selamat , Anda telah memenangkan game ini !!!" << endl;
            cout << " " << endl;
            cout << "Anda mendapat item !!" << endl;
            cout << " " << endl;
            cout << "Pedang legendaris " << item_pus <<  " Didapatkan" << endl;
            cout << " " << endl;
            system("pause");
            system("cls");
            epilog();
            loop = 'n';
        }
    }

    return 0;
}
