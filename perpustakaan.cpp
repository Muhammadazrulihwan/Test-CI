#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <iomanip>
using namespace std;

int main();
void perpus() {
    int pilihanMenu[0], jp, i, tgl_pinjam, tgl_kembali;
    char kode_buku;
    string judul_buku, nama, nim, myData;
    // Membaca dari file teks 
    fstream MyReadFile("data_pinjam.txt", ios::in | ios::out);

    do {
        cout << "\n====================================================== \n";  
        cout << "    Selamat Datang Di Perpustakaan eLibrary               \n";  
        cout << "\n======================================================\n";
        cout << "                         MENU                       ";
        cout << "\n======================================================\n";
        cout << "1. Daftar Buku \n";
        cout << "2. Pinjam Buku \n";
        cout << "3. Data Peminjam \n";
        cout << "4. Keluar \n";
    
        cout << "\nPilih menu : "; cin >> pilihanMenu[0];

        switch (pilihanMenu[0]) {
			//arkan
            case 1:
                cout <<"       =========================================== \n";
                cout <<"        Daftar Buku \n";
                cout <<"       =========================================== \n";
                cout <<"        a: Sejarah Hukum Indonesia \n";
                cout <<"        b: Media & Dinamika Demokrasi \n";
                cout <<"        c: Kuasa Wanita Jawa \n";
                cout <<"        d: Makna Budaya Dalam Komunikasi Antar Budaya \n";
                cout <<"        e: Dasar Dasar Uroginekologi \n";
                cout <<"       =========================================== \n";
                pilihanMenu[0] = 3;
                cout << endl;
                system("pause");
                break;
				//azrul
            case 2:
                cout << "no 2" << endl;
                cout <<"       Jumlah pinjam buku   	     	: ";cin>>jp;                
                for(i=1; i<=jp; i++)
                    cout<<endl;
        
                    cout <<"       =========================================== \n";
                    cout <<"       Perpustakaan eLibrary \n";
                    cout <<"       =========================================== \n";
                    cout <<"       Data peminjam ke          	: "<< i << "\n";
                    cout <<"       Masukkan Nama	     		: "; cin >> ws; getline(cin, nama);
                    cout <<"       Masukkan NIM    	   		: "; cin>>nim;
                    cout <<"       =========================================== \n";
                    cout <<"        Daftar Buku \n";
                    cout <<"       =========================================== \n";
                    cout <<"        a: Sejarah Hukum Indonesia \n";
                    cout <<"        b: Media & Dinamika Demokrasi \n";
                    cout <<"        c: Kuasa Wanita Jawa \n";
                    cout <<"        d: Makna Budaya Dalam Komunikasi Antar Budaya \n";
                    cout <<"        e: Dasar Dasar Uroginekologi \n";
                    cout <<"       =========================================== \n";
                    cout <<"       Masukkan kode buku (a/b/c/d/e)  	: ";cin>>kode_buku;
                    if(kode_buku=='a'){
                        judul_buku=" Sejarah Hukum Indonesia";
                    } else if(kode_buku=='b'){
                        judul_buku=" Media & Dinamika Demokrasi";
                    } else if(kode_buku=='c'){
                        judul_buku=" Kuasa Wanita Jawa";
                    } else if(kode_buku=='d'){
                        judul_buku=" Makna Budaya Dalam Komunikasi Antar Budaya";
                    } else if(kode_buku=='e'){
                        judul_buku=" Dasar Dasar Uroginekologi";
                    }
                    cout<<"       Judul buku                  	:"<<judul_buku<< "\n";
                    cout<<"       Masukkan tanggal peminjaman 	: ";cin>>tgl_pinjam;
                    if(tgl_pinjam>=24){tgl_kembali=(tgl_pinjam+7)-31;}else
                    if(tgl_pinjam<=24){tgl_kembali=tgl_pinjam+7;}
                    cout<<"       Tanggal kembali             	: "<<tgl_kembali<<"\n";

                    ofstream data("data_pinjam.txt", ios::app); 
                    data << nama << ',' << nim << ',' << kode_buku << ',' << judul_buku << ',' << tgl_pinjam << ',' << tgl_kembali << endl;
                    
                    data.close();
                }
                break;
				//firza
            case 3 :
                if(MyReadFile.is_open()) {
                    cout << left << setw(30) << "Nama" << setw(15) << "NIM" << setw(15) << "Kode Buku" << setw(50) << "Judul Buku" << setw(15) << "Tgl. Pinjam" << setw(15) << "Tgl. Kembali" << endl;

                    // Gunakan while loop bersama dengan fungsi getline() untuk membaca file per baris
                    while (getline (MyReadFile, myData)) {
                        // Output teks dari file
                        stringstream ss(myData);
                        string nama, nim, kode_buku, judul_buku, tgl_pinjam, tgl_kembali;
                        getline(ss, nama, ',');
                        getline(ss, nim, ',');
                        getline(ss, kode_buku, ',');
                        getline(ss, judul_buku, ',');
                        getline(ss, tgl_pinjam, ',');
                        getline(ss, tgl_kembali, ',');

                        cout << left << setw(30) << nama << setw(15) << nim << setw(15) << kode_buku << setw(50) << judul_buku << setw(15) << tgl_pinjam << setw(15) << tgl_kembali << endl;
                    }
                    // Tutup file
                    MyReadFile.close();
                }else {
                    cout << "Gagal membuka file" << endl;
                }
                cout << endl;
                system("pause");
                break;
            case 4 :
                system("cls");
                cout << "Terimakasih sudah meminjam buku di perpustakaan kami !\n";
                exit(0);
                // break;
            default:
                system("cls");
                cout << "Nomor yang anda masukkan salah \n";
                system("pause");
                break;
        }
    } while(pilihanMenu[0]!=1 && pilihanMenu[0]!=2);
        system("cls");
}
//amel
void login(){ 
    string nama, pw, id, pass; 
    int count;

    cout << "Masukkan Username dan Password : " << endl;
    cout << " " << endl;
    cout << "Username : "; cin >> ws; getline(cin, nama); 
    cout << "Password : "; getline(cin, pw);

    ifstream input ("users.txt");

    while(input >> id >> pass) { 
        if(id==nama && pass==pw){
            count = 1; system("cls");
        } 
    }
    input.close();

    if (count==1){
        cout << nama << " " << "Login Anda Telah Berhasil !";
        system("cls"); perpus(); 
    } else {
        cout << "Login Gagal! Periksa Kembali Username dan Password anda" << endl;
        main();
    }
} 
//nadya
void registration() {
    //string rpw, rpass; string
    string rnama, rpw, rpass, rid;
    system("cls");
    cout << "Masukkan Username : "; cin >> ws; getline(cin, rnama);
    cout << "Masukkan Password : "; getline(cin, rpw);

    ofstream f1("users.txt", ios::app); f1 << rnama << ' ' << rpw << endl;
    //output.close();

    cout << "Registrasi Anda Telah Berhasil" << endl; main();
}
//wira
int main() {
    int pilihan;

    cout <<"       =========================================== \n";
    cout <<"        Login Page \n";
    cout <<"       =========================================== \n";
    cout << "         1.Login" << endl; 
    cout << "         2.Register" << endl;
    cout << "         Masukkan PIlihan Anda : "; cin >> pilihan; 
    system("cls");
    switch(pilihan) { 
        case 1: 
            login();
            break;
        case 2: 
            registration();
            break;
        default:
            cin.ignore();
            cout << "INPUT YANG ANDA MASUKKAN SALAH! TEKAN ENTER UNTUK KELUAR";
            cin.get(); system("cls");
    }
}