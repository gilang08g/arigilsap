#include "header.h"

//fungsi untuk merubah string ke int
int stringtoint (string str){
    stringstream geek(str);

    int x = 0;
    geek >> x;

    return x;
}

//fungsi pengaturan inventory
void invent(){
    char loop2='y';

    while (loop2 == 'y') { //inventory system loop
		int hapus = 0, option; //selalu inisialisasi hapus dengan 0
				   //menu utama
		cout << "Inventory system : " << endl;
		cout << "1. Tampilkan inventory " << endl;
		cout << "2. Hapus item" << endl;
		cout << "3. Tutup" << endl;
		cout << "Masukkan pilihan Anda : ";
		cin >> option; //baca pilihan user dari menu utama

		switch (option) {
            case 1: //tampilkan inventory
            {
                //jika kosong
                if (inventory.empty()) {
                    cout << "Inventory masih kosong." << endl;
                }
                else {
                    //jika ada isinya
                    cout << "\nIsi inventory : ";
                    for (iter1 = inventory.begin(); iter1 != inventory.end();++iter1) {
                        cout << " " << endl;
                        for (iter2 = iter1->begin(); iter2 != iter1->end(); ++iter2) {
                            cout << *iter2<< " ";
                        }
                        cout << endl;
                    }

                }

                cout << "\nMasih ingin menggunakan menu inventory [y/n] ? ";
                cin >> loop2;
                cout << endl;
                break;
            }

            case 2: //hapus item dari inventory
            {
                //jika belum punya item
                if (jumlahInventory <= 0) {
                    cout << "Anda belum punya item" << endl;
                }
                else {
                    cout << "Hapus item ke- : ";
                    cin >> hapus;///input item nomor berapa yang dihapus
							     ///jika nomor item yang dihapus tidak ada
                    if (hapus > jumlahInventory) {
                        cout << "Item yang akan dihapus tidak ada." << endl;
                    }
                    else {
                        //hapus item
                        inventory.erase(inventory.begin() + (hapus - 1));
                        jumlahInventory--; //kurangi jumlah inventory
                        cout << "Jumlah inventory sekarang : " << jumlahInventory << endl; //tampilkan jumlah inventory
                    }
                }
                cout << "\nMasih ingin menggunakan menu inventory [y/n] ? ";
                cin >> loop2;
                cout << endl;
                break;
            }
            default :
            {
                loop2='n';
                break;
            }
        }
    }

}

//fungsi random
void random(){
    //jika isi inventory penuh
    if (jumlahInventory >= maksInventory) {
        cout << "Inventory penuh ! " << endl;
    }
    else {
        //jika masih ada ruang di inventory

        //acak item terpilih dari item pool
        srand((unsigned)time(0));
        irand = (rand() % maksItem);

        //tampilkan item yang diambil
        cout << "Anda mendapat : " << items[irand][0] << " . Stat : " << items[irand][1] << endl;

        //tambahkan item terpilih ke inventory
        inventory.push_back(vector<string>({ items[irand][0]}));
        inventory[jumlahInventory].push_back(items[irand][1]);
        jumlahInventory++;//tambah jumlah inventory
    }
}


//fungi mencari senjata terkuat
void maxim (){
    int i=0, weapStats, maxStats;
    while (i < jumlahInventory){
        weapStats = stringtoint(inventory[i][1]);
        maxStats = stringtoint(maximum[1]);
        if (weapStats >= maxStats){
            maximum = inventory[i];

        }
        else{
        }
        i++;
    }
     cout << "Stat senjata yang Anda pakai : " << maximum[1] << endl;
    /*for (iter1 = weapon.begin(); iter1 != weapon.end();++iter1) {
        for (iter2 = iter1->begin(); iter2 != iter1->end(); iter2++) {
            weapStats = stringtoint(iter2[1]);
            maxStats = stringtoint(max1[1]);
            if (weapStats >= maxStats){
                max1 = iter2[1];
                return max1;
            }
            else{
            }
        }
    }*/
}

//fungsi pertarungan
void battle (vector<string> ene, vector<string> self){
    int selfStats, eneStats;
    selfStats=stringtoint(self[1]);
    eneStats=stringtoint(ene[1]);

    if (selfStats > eneStats){
        cout << ene[0] <<" kalah!" << endl;

    }
    else{
        cout << "Anda kalah!" << endl;
        cout << endl;
        cout << "Anda dipaksa kembali ke lantai 2" << endl;
        floor=2;
    }
}

//fungsi puzzle
void puzzle (){
    string answer, rand_word, guess;
    char temp;
    int life;
    rand_word = "semarang";
    answer = rand_word;

    srand(time(0));
    for (int a=0; a<rand_word.size(); a++){
        int randomed = rand()%(rand_word.size());

        temp = rand_word[a];
        rand_word[a] = rand_word[randomed];
        rand_word[randomed] = temp;
    }

    life = 5;

    while (life!=0){
        cout << "\nNyawa Anda : " << life << endl;
        cout << "Puzzle : " << rand_word << endl;
        cout << "(Hint : Ibu kota Jateng)" << endl;
        cout << "Masukkan tebakan anda : "; cin >> guess;
        if (guess == answer){
            cout << "\nTebakan anda benar!\nAnda menang!" << endl;
            life=0;
        }else{
            cout << "Tebakan anda salah." << endl;
            if (life==1)
            {
                cout << "\nAnda Kalah!!!" << endl;
                cout << endl;
                cout << "Anda dipaksa kembali ke lantai 2" << endl;
                floor=2;
            }
            life--;
        }
    }
}


void prolog ()
{
     string text =  "di suatu dunia yang amat damai, terdapat sebuah desa\n"
                    "kecil suatu hari ada monster yang menginvasi desa tersebut\n"
                    "sehingga mengakitbatkan desa tersebut menjadi hancur.\n"
                    "di suatu desa tersebut tersisa satu anak kecil yang tidak tau apa apa\n"
                    "dan ingin balas dendam terhadap monster yang menghancurkan desa\n"
                    "yang dicintainya terutama balas dendam karna orangtuanya\n"
                    "telah terbunuh saat penginvasian tersebut...";
    string text2 =  "...anak tersebut diadopsi oleh seorang kesatria kerajaan dan diajari cara menggunakan\n"
                    "senjata hingga beberapa tahun telah berlalu...\n"
                    "anak tersebut menjadi remaja yang sudah lihai mengayunkan senjata.\n"
                    "sudah tiba saatnya dia bersiap meninggalkan istana itu untuk mencari dalang dibalik invasi desanya\n"
                    "ditemani teman baiknya dan ayah angkatnya yang dahulu pernah mengajarinya menggunakan senjata,\n"
                    "dia mencari dalang dibalik semua kejadian tersebut dengan mengunjungi dungeon\n"
                    "yang konon katanya dungeon tersebut merupakan sarang monster yang dulu pernah menyerang desanya\n";

    string text3 =  "Inilah ceritanya ... ";

    cout << "Prolog" << endl;
    cout << text << endl;
    cout << " " << endl;
    system("pause");
    cout << " " << endl;
    cout << text2 << endl;
    system("pause");
    cout << " " << endl;
    cout << text3 << endl;
    cout << " " << endl;
    system("pause");
    system("cls");
}

void plot_twist()
{
    string text5 =  "Temanku mengeluarkan aura aneh pada lantai ini !!";
    string text6 =  "King Minotaur : HAHAHA...AKU LAH YANG TELAH MENGINVANSI DESAMU PADA DAHULU KALA\n"
                    "DAN AKU JUGA YANG TERMASUK MEMBUNUH KEDUA ORANGTUAMU ";

    string text7 =  "TEMANKU BERUBAH!!";
    string text10 = "Ternyata temanku lah dalang dibalik semuanya..\n"
                    "...tapi aku harus tetap membunuhnya walaupun dia teman baikku";


    cout << text5 << endl;
    cout << " " << endl;
    cout << text7 << endl;
    cout << " " << endl;
    cout << text6 << endl;
    cout << " " << endl;
    cout << text10 << endl;
    cout << " " << endl;
}

void epilog()
{
    string text12 = "Keluar dungeon...";
    string text13 = "Terlihat kesatria yang sedang berdiri disana mulai mendekatiku";
    string text4  = "Kesatria : Kamu berhasil !! dan kamu mendapat Pedang ini !!\n"
                    "Pedang ini adalah peninggalan orang tua mu dahulu\n"
                    "Dahulu orang tuamu adalah seorang adventurer yang sangat terkenal\n"
                    "Tolong jagalah benda peninggalan ini demi orang tuamu\n";
    string text14 = "Meraka berdua pun pulang ke istana...";

    cout << text12 << endl;
    cout << " " << endl;
    cout << text13 << endl;
    cout << " " << endl;
    cout << text4 << endl;
    cout << " " << endl;
    cout << text14 << endl;

}
