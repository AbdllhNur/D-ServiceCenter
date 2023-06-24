#include <stdio.h>
#include <string.h>
#include <windows.h>

//general
void header();
void main_menu();
void sortingantrian();
void sortingtagihan();

//admin
void admin_login();
void admin_menu();
void admin_tagihan();
void admin_antrian();
void lihatreview();

//user
void user_signup();
void user_login();
void kerja_barang();
void user_tagihan();
void lapor();
void user_menu();
void user_antrian();
void user_masuk();
void tambahreview();
void identitas();

struct User{
    char nama[100], pass[100], konfirm[100],alamat[100],jeniskelamin[50],umur[50];
    char barang[100], keluhan[500];
    char kangserpis[50], penyebab[500], solusi[500], biaya[100], beli[100];
    char userrev[100], teknisi[50], testirev[100], tiprev[100];
}user,sort[250], temp;

char uname[50],pass[50];
char loginuname[50], loginpass[50]; 

//=============general================
int main()
{
    main_menu();
}

void header(){
    printf("========D'Service Center========\n");
}

void main_menu(){
    int pilih;
    fflush(stdin);
    system("cls");
    header();
    printf("\t\tmain menu\n");
    printf("silahkan pilih tipe akun\n");
    printf("1. Admin\n");
    printf("2. User\n");
    printf("masukan pilihan anda : ");
    scanf("%d", &pilih);

    switch (pilih){
    case 1:
    admin_login(); break;

    case 2:
    user_masuk(); break;
    
    default: 
    printf("pilihan tidak tersedia silahkan coba lagi\n"); system("pause");
    main_menu();
    break;
    }
}

void sortingantrian(){
    FILE* listtagihan;
    FILE* tempo;

    int j,k;
    listtagihan = fopen("datauser1.dat", "rb");
    tempo = fopen("temp.dat","wb");
    int n = 0;
    while(fread(&user, sizeof(user), 1, listtagihan)==1){
        strcpy(sort[n].nama, user.nama);
        strcpy(sort[n].barang, user.barang);
        strcpy(sort[n].keluhan, user.keluhan);
        strcpy(sort[n].penyebab, user.penyebab);
        strcpy(sort[n].solusi, user.solusi);
        strcpy(sort[n].beli, user.beli);
        strcpy(sort[n].biaya, user.biaya);
        strcpy(sort[n].kangserpis, user.kangserpis);
        strcpy(sort[n].userrev, user.userrev);
        strcpy(sort[n].teknisi, user.teknisi);
        strcpy(sort[n].testirev, user.testirev);
        strcpy(sort[n].tiprev, user.tiprev);
        n++;
    }
    for(j=n-1;j>=1;j--){
        for(k=1; k<=j; k++){
			if(strcmp(sort[k-1].nama, sort[k].nama) > 0){
				temp = sort[k-1];
				sort[k-1] = sort[k];
				sort[k] = temp;
			}
		}
    }
    for (j=0;j<n;j++){
        strcpy(user.nama,sort[j].nama);
        strcpy(user.barang,sort[j].barang);
        strcpy(user.keluhan,sort[j].keluhan);
        strcpy(user.penyebab,sort[j].penyebab);
        strcpy(user.solusi,sort[j].solusi);
        strcpy(user.beli,sort[j].beli);
        strcpy(user.biaya,sort[j].biaya);
        strcpy(user.kangserpis,sort[j].kangserpis);
        strcpy(user.userrev, sort[j].userrev);
        strcpy(user.teknisi, sort[j].teknisi);
        strcpy(user.testirev, sort[j].testirev);
        strcpy(user.tiprev, sort[j].tiprev);
        fwrite(&user, sizeof(user), 1, tempo);
    }
    fclose(listtagihan);
    fclose(tempo);
    remove("datauser1.dat");
    rename("temp.dat","datauser1.dat");
}


void sortingtagihan(){
    FILE* listtagihan;
    FILE* tempo;

    int j,k;
    listtagihan = fopen("hasil.dat", "rb");
    tempo = fopen("temp.dat","wb");
    int n = 0;
    while(fread(&user, sizeof(user), 1, listtagihan)==1){
        strcpy(sort[n].nama, user.nama);
        strcpy(sort[n].barang, user.barang);
        strcpy(sort[n].keluhan, user.keluhan);
        strcpy(sort[n].penyebab, user.penyebab);
        strcpy(sort[n].solusi, user.solusi);
        strcpy(sort[n].beli, user.beli);
        strcpy(sort[n].biaya, user.biaya);
        strcpy(sort[n].kangserpis, user.kangserpis);
        strcpy(sort[n].userrev, user.userrev);
        strcpy(sort[n].teknisi, user.teknisi);
        strcpy(sort[n].testirev, user.testirev);
        strcpy(sort[n].tiprev, user.tiprev);
        n++;
    }
    for(j=n-1;j>=1;j--){
        for(k=1; k<=j; k++){
			if(strcmp(sort[k-1].nama, sort[k].nama) > 0){
				temp = sort[k-1];
				sort[k-1] = sort[k];
				sort[k] = temp;
			}
		}
    }
    for (j=0;j<n;j++){
        strcpy(user.nama,sort[j].nama);
        strcpy(user.barang,sort[j].barang);
        strcpy(user.keluhan,sort[j].keluhan);
        strcpy(user.penyebab,sort[j].penyebab);
        strcpy(user.solusi,sort[j].solusi);
        strcpy(user.beli,sort[j].beli);
        strcpy(user.biaya,sort[j].biaya);
        strcpy(user.kangserpis,sort[j].kangserpis);
        strcpy(user.userrev, sort[n].userrev);
        strcpy(user.teknisi, sort[n].teknisi);
        strcpy(user.testirev, sort[n].testirev);
        strcpy(user.tiprev, sort[n].tiprev);
        fwrite(&user, sizeof(user), 1, tempo);
    }
    fclose(listtagihan);
    fclose(tempo);
    remove("hasil.dat");
    rename("temp.dat","hasil.dat");
}

//===================admin=====================

void admin_login(){
    system ("cls");
    fflush(stdin);

    printf("===login admin===\n");
    printf("masukkan userame : "); gets(uname);
    printf("masukkan password : "); gets(pass);

    if(strcmp(uname , "admin")==0&&strcmp(pass, "admin")==0){
        printf("login berhasil!\nsilahkan klik tombol apa saja untuk melanjutkan\n");
        system("pause");
        system("cls");
        admin_menu();
    }
    else{
        printf("username atau password salah\nsilahkan masukan kembali username dan password anda\n");
        admin_login();
    }
}

void admin_menu(){

    fflush(stdin);
    int pilih;
    system("cls");
    header();
    printf("\tmenu admin\n");
    printf("1. lihat daftar pesanan\n");
    printf("2. kerjakan pesanan\n");
    printf("3. lihat tagihan\n");
    printf("4. lihat review\n");
    printf("5. kembali\n");
    printf("masukkan pilihan anda : ");
    scanf("%d", &pilih);
    switch (pilih)
    {
    case 1:
        admin_antrian();
        break;
        
    case 2:
        kerja_barang();
        break;

    case 3:
        admin_tagihan();
        break;

    case 4:
        lihatreview();
        break;

    case 5:
        main_menu();
        break;
    default:
        printf("pilihan yang anda masukan tidak tersedia");
        system("pause"); break;
    }
}

void user_masuk(){
    system("cls");
    int pilih;
    header();
    printf("pilih proses masuk : \n");
    printf("1. daftar akun\n");
    printf("2. login akun\n");
    printf("3. kembali\n");
    printf("masukkan pilihan anda : ");
    scanf("%d", &pilih);
    
    switch (pilih)
    {
    case 1:
        user_signup();
        break;
    
    case 2:
        user_login();
        break;

    case 3:
        main_menu();
        break;

    default:
        printf("pilihan tidak ada"); system("pause");
        user_menu();
    }
}

void lapor(){
    system("cls");
    fflush(stdin);

    FILE*laporkeluhan;
    laporkeluhan = fopen("datauser1.dat","ab");

    header();
    printf("nama barang : "); gets(user.barang);
    printf("keluhan     : "); gets(user.keluhan);

    fwrite(&user, sizeof(user),1,laporkeluhan);
    printf("keluhan anda sudah terkirim, barang yang sudah selesai dikerjakan akan muncul di menu tagihan\n");
    system("pause");

    fclose(laporkeluhan);
    user_menu();
}

void kerja_barang(){
    system("cls");
    fflush(stdin);

    int i=0;
    int ada;
    char cari[50];
    FILE*kerja;
    FILE*hasil;
    FILE*temp;

    kerja = fopen("datauser1.dat", "rb");

    header();
    printf("list antrian : \n");
    while(fread(&user, sizeof(user), 1, kerja)==1){
        printf("\n%d. Nama user : %s", i+1, user.nama);
        printf("\n   Nama Barang : %s", user.barang);
        printf("\n   Keluhan\t : %s", user.keluhan);
        i++;
    }
    fclose(kerja);
    printf("\n");

    fflush(stdin);
    printf("pilih nama barang yang mau diperbaiki : "); gets(cari);
    kerja = fopen("datauser1.dat", "rb");
    hasil = fopen("hasil.dat", "ab");
    temp = fopen("temp.dat", "wb");
    printf("\n");

    ada = 0;
    while(fread(&user, sizeof(user), 1,kerja)==1){
        if(strcmp(user.barang, cari)==0){
        ada = 1; break;
        }
        else if(strcmp(user.barang, cari)!=0){
        ada = 0;
        }
    }
    fclose(kerja); 

    if(ada==1){
        kerja = fopen("datauser1.dat", "rb");
        while(fread(&user, sizeof(user), 1,kerja)==1){
            if(strcmp(user.barang, cari)==0){
                printf("masukkan nama yang memperbaiki barang      : "); gets(user.kangserpis);
                printf("masukkan penyebab barang rusak             : "); gets(user.penyebab);
                printf("masukkan solusi perbaikan barang           : "); gets(user.solusi);
                printf("masukkan barang tambahan yang harus dibeli : "); gets(user.beli);
                printf("masukkan total harga yang harus dibayar    : "); gets(user.biaya);
                fwrite(&user, sizeof(user), 1, hasil);
            } else {
                fwrite(&user, sizeof(user), 1, temp);
            }
        }
        fclose(kerja); 
    } 
    else if(ada==0){
        printf("barang tidak ditemukan!\n");
        system("pause");
        fclose(hasil);
        fclose(temp);
        admin_menu();
        return;
    }
    fclose(kerja);
    fclose(hasil);
    fclose(temp);

    remove("datauser1.dat");
    rename("temp.dat","datauser1.dat");
    remove("temp.dat");

    printf("proses perbaikan sudah selesai, barang akan dimasukkan ke list tagihan\n");
    printf("klik tombol apa saja untuk kembali ke menu\n");
    system("pause");
    admin_menu();
}

void admin_tagihan(){
    system("cls");
    fflush(stdin);

    sortingtagihan();

    FILE*listtagihan;
    listtagihan = fopen("hasil.dat", "rb");
    int i=0;
    header();
    while (fread(&user, sizeof(user), 1, listtagihan)==1){
        printf("\n%d. Nama user\t\t : %s", i+1, user.nama);
        printf("\n   Nama Barang\t\t : %s", user.barang);
        printf("\n   Keluhan\t\t : %s", user.keluhan);
        printf("\n   Penyebab\t\t : %s", user.penyebab);
        printf("\n   Solusi\t\t : %s", user.solusi);
        printf("\n   Barang yang dibeli\t : %s", user.beli);
        printf("\n   Biaya total\t\t : %s", user.biaya);
        printf("\n   Dikerjakan oleh\t : %s", user.kangserpis);
        printf("\n"); i++;
    }

    fclose(listtagihan);
    printf("\nklik tombol apa saja untuk kembali ke menu\n");
    system("pause"); 
    admin_menu();    
}

void admin_antrian(){
    system("cls");
    fflush(stdin);

    sortingantrian();
    
    FILE*antrian;
    int i=0;
    antrian = fopen("datauser1.dat", "rb");
    header();
    printf("list antrian : \n");
    while(fread(&user, sizeof(user), 1, antrian)==1){
        printf("\n%d. Nama user : %s", i+1, user.nama);
        printf("\n   Nama Barang : %s", user.barang);
        printf("\n   Keluhan\t : %s", user.keluhan);
        i++;
    }
    fclose(antrian);
    printf("\n");
    printf("klik tombol apa saja untuk kembali ke menu utama\n");
    system("pause");
    admin_menu();
}

void lihatreview(){
    system("cls");
    fflush(stdin);
    header();

    FILE*lihatreview;
    lihatreview = fopen("testimoni.dat","rb");
    int i=0;
    while (fread(&user, sizeof(user),1,lihatreview)==1)
    {
        printf("%d.nama teknisi       : %s\n", i+1 ,user.teknisi);
        printf("  testimoni customer : %s\n", user.testirev);
        printf("  tip yang diterima  : %s\n", user.tiprev);
        printf("  nama customer      : %s\n", user.userrev);
        i++;    
    }
    fclose(lihatreview);
    printf("klik tombol apa saja untuk kembali ke menu utama");
    printf("\n"); system("pause"); admin_menu();
}

//=======================user=====================

void user_signup(){
    fflush(stdin);
    FILE*daftaruser;
    daftaruser = fopen("datauser.dat","ab");
    system("cls");
    header();
    printf("masukkan username       : "); gets(user.nama); 
    printf("masukkan alamat         : "); gets(user.alamat);
    printf("masukkan jenis kelamin  : "); gets(user.jeniskelamin);
    printf("masukkan umur           : "); gets(user.umur);
    printf("masukkan password       : "); gets(user.pass);
    printf("konfirmasi password     : "); gets(user.konfirm);

    if(strcmp(user.pass, user.konfirm)==0){
        fwrite(&user,sizeof(user), 1, daftaruser);
        printf("pendaftaran berhasil! silahkan login!\n");
        system("pause"); 
        fclose(daftaruser);
        user_login();
    }
    else if(strcmp(user.pass, user.konfirm)!=0){
        printf("password dan konfirmasi tidak cocok!\nsilahkan coba lagi");
        system("pause");
        user_signup();
    }
    fclose(daftaruser);
}

void user_login(){
    FILE *loginuser;
    loginuser = fopen("datauser.dat","rb");

    int i = 3, z=0;

    system("cls");
    header();
    fflush(stdin);
    printf("masukkan nama       : ");
    gets(loginuname);
    fflush(stdin);

    while (fread(&user, sizeof(user), 1 ,loginuser)==1)
    {
        if(strcmp(loginuname,user.nama)==0){
            z = 1;
            while (i>0)
            {
                printf("masukkan password   : ");
                gets(loginpass);
                if(strcmp(loginpass,user.pass)==0){
                    printf("login berhasil!\n");
                    system("pause");
                    user_menu(); 
                    fclose(loginuser);
                    return;
                }
                else if(strcmp(loginpass, user.pass)!=0){
                    printf("password salah, tersisa %d kesempatan\n", i-1);
                    i--;
                    if(i==0){
                    printf("kesempatan sudah habis, silahkan kembali ke menu utama!\n");
                    system("pause");
                    fclose(loginuser);
                    main_menu();
                    return;
                    }
                }
            }          
        }
    }

    if(!z){
        printf("username tidak terdaftar, silahkan coba lagi\n");
        system("pause");
        fclose(loginuser);
        user_login();
    }
    fclose(loginuser);
}

void user_menu(){
    int c;
    fflush(stdin);
    system("cls");
    header();
    printf("    user menu   \n");
    printf("1. lihat informasi akun\n");
    printf("2. buat laporan kerusakan \n");
    printf("3. lihat antrian\n");
    printf("4. lihat tagihan\n");
    printf("5. tambahkan review\n");
    printf("6. kembali\n");
    printf("masukkan pilihan : ");
    scanf("%d", &c);

    switch (c)
    {
    case 1: 
        identitas();
        break;
    case 2:
        lapor();
        break;
    case 3:
        user_antrian();
        break;
    case 4:
        user_tagihan();
        break;  
    case 5:
        tambahreview();
        break;
    case 6:
        main_menu();
        break;
    default:
        printf("pilihan yang anda masukkan tidak ada, coba lagi!\n");
        system("pause"); user_menu();        
        break;
    }
}

void identitas(){
    system("cls");
    fflush(stdin);

    FILE*datadiri;
    datadiri = fopen("datauser.dat", "rb");
    header();
    printf("    informasi akun\n");

    while(fread(&user, sizeof(user), 1, datadiri)==1){
        if(strcmp(loginuname,user.nama)==0){
            printf("\nnama            : %s", user.nama);
            printf("\nalammat         : %s", user.alamat);
            printf("\njenis kelamin   : %s", user.jeniskelamin);
            printf("\numur            : %s", user.umur);
        }
    }
    fclose(datadiri);

    printf("\nklik tombol apa saja untuk kembali ke menu utama : ");
    printf("\n"); system("pause"); user_menu();
}

void tambahreview(){
    system("cls");
    fflush(stdin);

    FILE*tambahreview;
    tambahreview = fopen("testimoni.dat", "ab");

    header();
    strcpy(user.userrev, loginuname);
    printf("masukkan nama teknisi                       : "); gets(user.teknisi);
    printf("masukkan testimoni anda                     : "); gets(user.tiprev);
    printf("masukkan jumlah tip yang ingin anda berikan : "); gets(user.testirev);
    fwrite(&user, sizeof(user), 1, tambahreview);
    fclose(tambahreview);

    printf("testimoni anda sudah terkirim, terima kasih sudah karena sudah\nmenggunakan aplikasi kami ");
    printf("\n"); system("pause");

    user_menu();
}

void user_tagihan(){
    system("cls");
    fflush(stdin);

    sortingtagihan();

    FILE*listtagihan;
    listtagihan = fopen("hasil.dat", "rb");
    int i=0;
    header();
    while (fread(&user, sizeof(user), 1, listtagihan)==1){
        printf("\n%d. Nama user\t\t : %s", i+1, user.nama);
        printf("\n   Nama Barang\t\t : %s", user.barang);
        printf("\n   Keluhan\t\t : %s", user.keluhan);
        printf("\n   Penyebab\t\t : %s", user.penyebab);
        printf("\n   Solusi\t\t : %s", user.solusi);
        printf("\n   Barang yang dibeli\t : %s", user.beli);
        printf("\n   Biaya total\t\t : %s", user.biaya);
        printf("\n   Dikerjakan oleh\t : %s", user.kangserpis);
        printf("\n"); i++;
    }

    fclose(listtagihan);
    printf("\nklik tombol apa saja untuk kembali ke menu\n");
    system("pause");   
    user_menu(); 
}

void user_antrian(){
    system("cls");
    fflush(stdin);

    sortingantrian();

    FILE*antrian;
    int i=0;
    antrian = fopen("datauser1.dat", "rb");
    header();
    printf("list antrian : \n");
    while(fread(&user, sizeof(user), 1, antrian)==1){
        printf("\n%d. Nama user : %s", i+1, user.nama);
        printf("\n   Nama Barang : %s", user.barang);
        printf("\n   Keluhan\t : %s", user.keluhan);
        i++;
    }
    fclose(antrian);
    printf("\n");
    printf("klik tombol apa saja untuk kembali ke menu utama\n");
    system("pause");
    user_menu();
}