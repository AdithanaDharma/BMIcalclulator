#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
using namespace std;

struct DataBMI {
    float berat;
    float tinggi;
    float nilaibmi;
    string status;
    string datajeniskelamin;
    string waktu;
};

void hitungBMI(float *berat, float *tinggi, float *bmi) {
    *bmi= (*berat) / ((*tinggi / 100) * ((*tinggi / 100)));
}

    char lanjut;
    char jeniskelamin;
    char kembali;
    string masatubuh;
    string pilihanjeniskelamin;
    float bmi;
    DataBMI riwayatBMI[10];
    int jumlahData = 0;

int main()
{
    awal:
    system("cls");
    int pilihan;
    cout << "MENU KALKULATOR BMI" << endl;
    cout << "   1.HITUNG BMI" << endl;
    cout << "   2.RIWAYAT" << endl;
    cout << "   3.TENTANG KAMI" << endl;
    cout << "   4.KELUAR" << endl << endl;
    cout << "Masukkan Pilihan: "; cin>>pilihan;

    switch(pilihan){
    case 1:
        do {perulangan:
        system("cls");
        float beratBadan, tinggiBadan;
        cout << "Masukkan berat badan (kg)      : ";cin >> beratBadan;
        cout << "Masukkan tinggi badan (cm)     : ";cin >> tinggiBadan;
        cout << "Masukkan jenis kelamin (L/P)   : ";cin >> jeniskelamin;

        hitungBMI(&beratBadan, &tinggiBadan,&bmi);

        if (jeniskelamin == 'P'||jeniskelamin == 'p') {
            if (bmi < 17) {
                cout <<endl<<"BMI Anda: "<<bmi<<endl<<"Status: Kurus" << endl;
                masatubuh="kurus";
            } else if (bmi < 23) {
                cout <<endl<<"BMI Anda: "<<bmi<<endl<< "Status: Normal" << endl;
                masatubuh="normal";
            } else if (bmi < 27) {
                cout <<endl<<"BMI Anda: "<<bmi<<endl<< "Status: Kegemukan" << endl;
                masatubuh="kegemukan";
            } else {
                cout <<"BMI Anda: "<<bmi<<endl<< "Status: Obesitas" << endl;
                masatubuh="obesitas";
            }}

        else if (jeniskelamin == 'L'||jeniskelamin == 'l') {
            if (bmi < 18) {
                cout <<endl<<"BMI Anda: "<<bmi<<endl<<"Status: Kurus" << endl;
                masatubuh="kurus";
            } else if (bmi < 25) {
                cout <<endl<<"BMI Anda: "<<bmi<<endl<< "Status: Normal" << endl;
                masatubuh="normal";
            } else if (bmi < 30) {
                cout <<endl<<"BMI Anda: "<<bmi<<endl<< "Status: Kegemukan" << endl;
                masatubuh="kegemukan";
            } else {
                cout <<"BMI Anda: "<<bmi<<endl<< "Status: Obesitas" << endl;
                masatubuh="obesitas";
            }}

            else {
            cout << "Jenis kelamin tidak valid." << endl;sleep(3);
            goto perulangan;
        }

        if (jeniskelamin == 'L'||jeniskelamin == 'l'){
            pilihanjeniskelamin= "Laki-Laki";}
        else if (jeniskelamin == 'P'||jeniskelamin == 'p'){
            pilihanjeniskelamin= "Perempuan";}

        time_t waktu=time(0);
        string localtime=ctime(&waktu);

        riwayatBMI[jumlahData].berat = beratBadan;
        riwayatBMI[jumlahData].tinggi = tinggiBadan;
        riwayatBMI[jumlahData].nilaibmi = bmi;
        riwayatBMI[jumlahData].status = masatubuh;
        riwayatBMI[jumlahData].datajeniskelamin = pilihanjeniskelamin;
        riwayatBMI[jumlahData].waktu = localtime;
        jumlahData++;

        if (jumlahData >=10){
            cout <<endl<< "Riwayat BMI penuh!!. Kembali ke menu utama dalam 5 detik";
            sleep(5);goto awal;
        }

        cout << "Ingin menghitung lagi? (y/n): ";
        cin >> lanjut;

        if(lanjut=='n'|| lanjut == 'N'){
            goto awal;
        }}while (lanjut == 'y' || lanjut == 'Y');
        break;

    case 2:
        system("cls");
        cout << "Riwayat perhitungan BMI:" << endl<<endl;
        for (int i = 0; i < jumlahData; i++) {
        cout << "Data ke-" << i + 1 << ":" << endl<<endl;
        cout << "waktu perhitungan: "<< riwayatBMI[i].waktu;
        cout << "jenis kelamin    : " << riwayatBMI[i].datajeniskelamin << endl;
        cout << "Berat badan      : " << riwayatBMI[i].berat << " kg" << endl;
        cout << "Tinggi badan     : " << riwayatBMI[i].tinggi << " cm" << endl;
        cout << "status           : " << riwayatBMI[i].status<< endl;
        cout << "BMI              : " << riwayatBMI[i].nilaibmi << endl<<endl;
        }
        cout<<endl<<"apakah anda ingin kembali ke menu utama?(Y/N):  ";cin>>kembali;
        if (kembali=='Y'||kembali=='y'){
            goto awal;}
        break;

    case 3:
        cout<<endl;
        cout << "                               =ABOUT US=     "<< endl;
        cout << "                                MADE BY:      "<< endl;
        cout << "                       Adithana Dharma Putra  "<< endl;
        cout << "                            Hendwi Saputra    "<< endl;
        cout << "                       Muhammad Ihab Aufa Rafi"<< endl << endl;
        cout << "                           12 Desember 2023   "<< endl;
        cout << "            Copyright @2023. Kelompok 4. All Right Reserved."<<endl;
        cout<<endl<<"            Apakah anda ingin kembali ke menu utama?(Y/N): ";cin>>kembali;
        if (kembali=='Y'||kembali=='y'){
            goto awal;}
        break;

    case 4:
        exit(0);
        break;

    default:
        cout<<"masukkan input yang sesuai!";
        sleep(3);
        goto awal;}

    return 0;
}
