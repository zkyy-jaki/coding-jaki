#include <iostream>
using namespace std;

string account[10][3];
string namaCustomer[100];
int subtotalHarga[100];
int totalHarga[100];
int daftarKode[100];
int jumlahUser = 0;
int jumlahPesanan = 0;
int percobaan = 3;
bool keluar = false;
void menuUtama();
int kodeBarang[11] = {1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010, 1011};
string jenisBarang[11] = {"Ayam Goreng", "Lotek", "Gado-Gado", "Wagyu A5", "Gurame Bakar", "Bebek Peking", "Telur Triceratops", "Daging Zombie", "Magelangan Mba Lis", "Babi Guling", "Unagi"};
int hargaBarang[11] = {18750, 12190, 10680, 767250, 45328, 31313, 56570, 123456, 12100, 27894, 60456};

int cekKode(int &kode) {
    int i;
    for (i = 0; i < 11; i++) {
        if (kodeBarang[i] == kode) {
            return i;
        }
    }
}

bool cekLogin(string user, string pass) {
    for (int i = 0; i < jumlahUser; i++) {
        for (int j = 0; j < 3; j++) {
            if (user == account[i][j + 1] && pass == account[i][j + 2]) {
                return true;
            } else {
                return false;
            }
        }
    }
}

void daftar() {
    string nama, username, password;
    system("cls");
    cout << "Silahkan Daftar Akun" << endl;
    cout << "Masukkan Nama\t\t: ";
    cin >> account[jumlahUser][jumlahUser];
    cout << "Masukkan Username\t: ";
    cin >> account[jumlahUser][jumlahUser + 1];
    cout << "Masukkan Password\t: ";
    cin >> account[jumlahUser][jumlahUser + 2];
    jumlahUser++;
}

void lihatPesanan() {
    system("cls");
    cout << "Lihat Pesanan" << endl;
    for (int i = 0; i < jumlahPesanan; i++) {
        cout << "Nama : " << namaCustomer[i] << endl;
        cout << "Jenis Barang : " << jenisBarang[daftarKode[i]] << endl;
        cout << "Harga Satuan : " << hargaBarang[daftarKode[i]] << endl;
        cout << "Harga subtotal : " << subtotalHarga[i] << endl;
        cout << "Harga Total : " << totalHarga[i] << endl;
        system("pause");
    }
}

void tambahPesanan() {
    int barang, kode, jumlah, total;

    system("cls");
    cout << "Silahkan Memilih Pesanan" << endl;
    cout << "Nama : ";
    cin >> namaCustomer[jumlahPesanan];
    do {
        cout << "Masukkan kode barang : ";
        cin >> barang;
        kode = cekKode(barang);
        if (kode == -1) {
            cout << "\nKode barang tidak ditemukan" << endl;
        }
    } while (kode == -1);
    daftarKode[jumlahPesanan] = kode;
    cout << "Masukkan Jumlah Barang : ";
    cin >> jumlah;
    subtotalHarga[jumlahPesanan] = hargaBarang[kode] * jumlah;
    total = subtotalHarga[jumlahPesanan] * 0.1;
    totalHarga[jumlahPesanan] = total + subtotalHarga[jumlahPesanan];

    cout << "\n\nNama Barang : " << jenisBarang[kode] << endl;
    cout << "Harga Satuan : " << hargaBarang[kode] << endl;
    cout << "Harga Subtotal : " << subtotalHarga[jumlahPesanan] << endl;
    cout << "Harga total : " << totalHarga[jumlahPesanan] << endl;
    system("pause");
    jumlahPesanan++;
    menuUtama();
}

void menuUtama() {
    int pilih;
    do {
        system("cls");
        cout << "Menu Utama\n";
        cout << "[1] Tambah Pesanan" << endl;
        cout << "[2] Lihat Daftar Pesanan" << endl;
        cout << "[3] Keluar" << endl;
        cout << "Menu > ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                tambahPesanan();
                break;
            case 2:
                lihatPesanan();
                break;
            case 3:
                keluar = true;
                break;
        }
    } while (pilih != 3);
}

void login() {
    string username, password;
    system("cls");
    cout << "Selamat Datang! Silahkan Login" << endl;

    do {
        cout << "Username : ";
        cin >> username;
        cout << "Password : ";
        cin >> password;

        if (!cekLogin(username, password)) {
            percobaan--;
            cout << "Kesempatan anda tersisa " << percobaan << " kali lagi" << endl;
        }
        if (cekLogin(username, password)) menuUtama();
    } while (!cekLogin(username, password) && percobaan > 0);
    if (percobaan == 0)
        keluar = true;
}

void menu() {
    int pilih;

    do {
        system("cls");
        cout << "Selamat Datang! Silahkan Pilih" << endl;
        cout << "[1] Login" << endl;
        cout << "[2] Daftar" << endl;
        cout << "[3] Keluar" << endl;
        cout << "Menu > ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                login();
                break;
            case 2:
                daftar();
                break;
            case 3:
                keluar = true;
                break;
            default:
                cout << "Menu yang anda pilih tidak ada!\n";
                system("pause");
                break;
        }

    } while (!keluar);
}

int main() {
    menu();
}