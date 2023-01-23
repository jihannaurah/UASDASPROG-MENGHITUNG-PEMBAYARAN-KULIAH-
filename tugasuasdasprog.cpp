/* program menghitung pembayaran kuliah mahasiswa menggunakan struktur, diketahui :
a. S1
    -SPP tetap Rp4.000.000
    -SKS = Rp 6.ooo

*/

#include <iostream>
#include <vector>

using namespace std;

struct Semester{
    string semester;
    int jumlahSks;
    long spp;
};

vector<Semester> daftarSemester{
    {
        "Satu",
        20,
        4000000,
    },
    {
        "Dua",
        16,
        4000000,
    },
};

struct Fakultas{
    string nama;
    vector<string> daftarProgramStudi;
};

vector<Fakultas> daftarFakultas{
    {
      "Sains & Teknologi",
      {
          "Teknik Sipil",
          "Teknik Informatika",
          "Kimia",
      },
    },
};

struct Mahasiswa{
	string namaLengkap,
        fakultas,
        programStudi;
    unsigned int nim;
};

Mahasiswa mahasiswa;

void tampilkanDetailPembayaran(Mahasiswa mahasiswa, Semester semester) {
    cout << "== Rincian Pembayaran ==\n\n";
    cout << "Nama mahasiswa : " << mahasiswa.namaLengkap << "\n";
    cout << "NIM : " << mahasiswa.nim << "\n";
    cout << "Fakultas : " << mahasiswa.fakultas << "\n";
    cout << "Program Studi : " << mahasiswa.programStudi << "\n";
    cout << "Semester : " << semester.semester << "\n";
    cout << "SPP : Rp " << semester.spp << "\n";
    cout << "SKS : Rp " << semester.jumlahSks * 6000 << "\n";
    cout << "Total bayar : Rp " << semester.spp + (semester.jumlahSks * 6000) << "\n";
}

int main() {
    string namaLengkap;
    int nomorFakultas, nomorProgramStudi, nomorSemester;
    unsigned int nim;

    cout << "==== Sistem Perhitungan Pembayaran Kuliah ====\n\n";

    cout << "Masukkan nama lengkap : ";
    getline(cin, namaLengkap);
    mahasiswa.namaLengkap = namaLengkap;


    cout << "Masukkan NIM : ";
    cin >> nim;
    mahasiswa.nim = nim;

    cout << "\nDaftar fakultas : ";
    for (int i = 0; i < daftarFakultas.size(); i++) {
        cout << i + 1 << ". " << daftarFakultas[i].nama << endl;
    }
    cout << "Pilih fakultas : ";
    cin >> nomorFakultas;
    mahasiswa.fakultas = daftarFakultas[nomorFakultas - 1].nama;

    cout << "\nDaftar program studi : ";
    for (int i = 0; i < daftarFakultas[nomorFakultas - 1].daftarProgramStudi.size(); i++) {
        cout << i + 1 << ". " << daftarFakultas[nomorFakultas - 1].daftarProgramStudi[i] << endl;
    }
    cout << "Pilih program studi : ";
    cin >> nomorProgramStudi;
    mahasiswa.programStudi = daftarFakultas[nomorFakultas - 1].daftarProgramStudi[nomorProgramStudi -1];

    cout << "\nDaftar semester : ";
    for (int i = 0; i < daftarSemester.size(); i++) {
        cout << i + 1 << ". " << daftarSemester[i].semester << endl;
    }
    cout << "Pilih semester : ";
    cin >> nomorSemester;

    system("cls");

    if (nomorSemester > 0 && nomorSemester <= daftarSemester.size()) {
        tampilkanDetailPembayaran(mahasiswa, daftarSemester[nomorSemester - 1]);
    } else {
        cout << "Masukkan semester dengan benar!";
    }
}



