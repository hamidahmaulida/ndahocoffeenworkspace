#include <iostream>
#include <windows.h>
#include <ctime>
#define MAX 100
using namespace std;

int i;
time_t now = time(0);
char* dt = ctime(&now);

struct Menu {
	string kopi[7]={"Americano", "Macchiato", "Cappucino", "Espresso", "Tiramisu", "Greentea", "Vanilla"} ;
	int hargaKopi[7]={18000, 15000, 22000, 12000, 24000, 27000, 19000};
} mn;

struct Sort {
	int tukar;
	int n=7;
} srt;

struct Record {
	int kopi[MAX];
	int jumlah[MAX];
	string nama[MAX];
	int depan;
	int belakang;
} rcd;


//Sorting start
void sortingMenu() {
	for (int i = 0; i < srt.n-1; i++) {
        srt.tukar = i;
        string temp;
        for(int j = i+1; j < srt.n; j++){
            if(mn.kopi[j] < mn.kopi[srt.tukar]){
                srt.tukar = j;
            }
        }   

        temp = mn.kopi[srt.tukar];
        mn.kopi[srt.tukar] = mn.kopi[i];
        mn.kopi[i] = temp;
        
    }

    for(int i = 0; i < srt.n; i++){
    	if(mn.kopi[i]=="Greentea") {
    		cout << i+1<<". "<<mn.kopi[i] << "\t\t : "<<mn.hargaKopi[i]<<endl;
    		continue;
		}
        cout << i+1<<". "<< mn.kopi[i] << "\t\t : "<<mn.hargaKopi[i]<<endl;
    }
}
//Sorting end

//Queue start
struct Queue {
	int depan;
	int belakang;
	int kopi[MAX];
	int jumlah[MAX];
} queue;

struct Customer {
	string nama[MAX];
	int nomer=1;
	int antrian[MAX];
}cstm;

bool isEmpty() {
	return(queue.belakang==-1);
}

bool isFull() {
	return(queue.belakang>=(MAX-1) );
}

void inisialisasi() {
	queue.depan = queue.belakang = -1;
	rcd.depan = rcd.belakang = -1;
}

//Nota start
void nota(int i) {
	int harga;
	int bayar;
	cout<<"\n\n\n\n\t\t\tNota Pemesanan Kopi"<<endl;
		cout<<" ======================================================================";
		cout<<"\n\t\tNo Antrian		: "<<cstm.antrian[i];
		cout<<"\n\t\tNama Pemesan		: "<<cstm.nama[i];
		if(queue.kopi[i]==1) {
			cout<<"\n\t\tKopi			: Americano";   
			harga=18000;
		} else if(queue.kopi[i]==2) {
			cout<<"\n\t\tKopi			: Macchiato";   
			harga=15000;
		} else if(queue.kopi[i]==3) {
			cout<<"\n\t\tKopi			: Capuccino";   
			harga=22000;
		} else if(queue.kopi[i]==4) {
			cout<<"\n\t\tKopi			: Espresso";   
			harga=12000;
		} else if(queue.kopi[i]==5) {
			cout<<"\n\t\tKopi			: Greentea";   
			harga=27000;
		}else if(queue.kopi[i]==6) {
			cout<<"\n\t\tKopi			: Tiramisu";   
			harga=24000;
		}else if(queue.kopi[i]==7) {
			cout<<"\n\t\tKopi			: Vanilla";   
			harga=19000;
		}

		cout<<"\n\t\tJumlah			: "<<queue.jumlah[i];
		
        cout<<"\n\t\tTanggal Pesan		: "<<dt;
        cout<<" ======================================================================";
        
        
        cout<<"\n\t\tBiaya Total		: Rp. "<<queue.jumlah[i]*harga;
        cout<<"\n\t\tBayar			: Rp. ";cin>>bayar;
        cout<<"\n\t\tKembali			: Rp. "<<bayar-(queue.jumlah[i]*harga);


        cout<<"\n ======================================================================";
               
        cout<<"\n\n\t\tTerima Kasih Telah Membeli Kopi di Ndaho Coffee & Workspace\n\n";
}
//Nota end

void enqueue(int kopi, int jumlah, string nama) {
	if(isFull()) {
		cout<<"Antrian sudah penuh!!!\n";
	} else {
		queue.depan = 0;
		queue.belakang++;
		queue.kopi[queue.belakang]=kopi;
		queue.jumlah[queue.belakang]=jumlah;
		cstm.nama[queue.belakang]=nama;
		cstm.antrian[queue.belakang]=cstm.nomer++;
		
		rcd.depan = 0;
		rcd.belakang++;
		rcd.kopi[rcd.belakang]=kopi;
		rcd.jumlah[rcd.belakang]=jumlah;
		rcd.nama[rcd.belakang]=nama;
		
		system("cls"); 
		nota(queue.belakang);
	}
	
}

void dequeue() {
	cout<<"Antrian "<<cstm.antrian[queue.depan]<<" atas nama "<<cstm.nama[queue.depan]<<" sudah dihapus"<<endl<<endl;
	
	for(int i=queue.depan; i<=queue.belakang; i++) {
		queue.kopi[i]=queue.kopi[i+1];
		queue.jumlah[i]=queue.jumlah[i+1];
		cstm.nama[i]=cstm.nama[i+1];
		cstm.antrian[i]=cstm.antrian[i+1];
	}
	queue.belakang--;
}

void clear() {
	queue.depan = queue.belakang = -1;
	cout<<"Antrian sudah dikosongkan"<<endl<<endl;
}

void print() {
	int no=1;
	if(isEmpty()) {
		cout<<"Antrian masih kosong!!!\n";
	} else {
		cout<<"Isi pesanan : \n";
		for(int i=queue.depan; i<=queue.belakang; i++) {
			if(queue.kopi[i]==1) {
				cout<<cstm.antrian[i]<<". "<<cstm.nama[i]<<" : Americano sejumlah "<<queue.jumlah[i];
			} else if(queue.kopi[i]==2) {
				cout<<cstm.antrian[i]<<". "<<cstm.nama[i]<<" : Macchiato sejumlah "<<queue.jumlah[i];
			} else if(queue.kopi[i]==3) {
				cout<<cstm.antrian[i]<<". "<<cstm.nama[i]<<" : Cappucino sejumlah "<<queue.jumlah[i];
			} else if(queue.kopi[i]==4) {
				cout<<cstm.antrian[i]<<". "<<cstm.nama[i]<<" : Esspreso sejumlah "<<queue.jumlah[i];
			} else if(queue.kopi[i]==5) {
				cout<<cstm.antrian[i]<<". "<<cstm.nama[i]<<" : Tiramisu sejumlah "<<queue.jumlah[i];
			} else if(queue.kopi[i]==6) {
				cout<<cstm.antrian[i]<<". "<<cstm.nama[i]<<" : Greentea sejumlah "<<queue.jumlah[i];
			} else if(queue.kopi[i]==7) {
				cout<<cstm.antrian[i]<<". "<<cstm.nama[i]<<" : Vanilla sejumlah "<<queue.jumlah[i];
			}
			cout<<endl;
		}
		cout<<endl<<endl;
		
	}
}
//Queue end

//Search start
void searchKopi() {
	bool found{false};
	int key, total=0, no=1;
	cout << "\nMasukkan pesanan kopi yang ingin dicari : ";
	cin >> key;
	
	for (int i=rcd.depan; i<=rcd.belakang; i++)
	{
		if (rcd.kopi[i] == key)
		{
			if(rcd.kopi[i]==1) {
				cout<<no<<". "<<rcd.nama[i]<<" : Americano sejumlah "<<rcd.jumlah[i];
			} else if(rcd.kopi[i]==2) {
				cout<<no<<". "<<rcd.nama[i]<<" : Macchiato  sejumlah "<<rcd.jumlah[i];
			} else if(rcd.kopi[i]==3) {
				cout<<no<<". "<<rcd.nama[i]<<" : Cappucino sejumlah "<<rcd.jumlah[i];
			} else if(rcd.kopi[i]==4) {
				cout<<no<<". "<<rcd.nama[i]<<" : Espresso sejumlah "<<rcd.jumlah[i];
			} else if(rcd.kopi[i]==5) {
				cout<<no<<". "<<rcd.nama[i]<<" : Tiramisu sejumlah "<<rcd.jumlah[i];
			} else if(rcd.kopi[i]==6) {
				cout<<no<<". "<<rcd.nama[i]<<" : Greentea sejumlah "<<rcd.jumlah[i];
			} else if(rcd.kopi[i]==7) {
				cout<<no<<". "<<rcd.nama[i]<<" : Vanilla sejumlah "<<rcd.jumlah[i];
			}
			cout<<endl;
			found=true;
			total+=rcd.jumlah[i];
			no++;
			continue;
		}
	}
	
	if(found==false) {
		cout<<"Data yang Anda cari tidak ditemukan!";
	}
	
	cout<<"\n\nTotal pesanan kopi yang dicari ada : "<<total<<endl<<endl;

}
//Search end


int main(){
	inisialisasi();
	int pilihan;
	int kopi;
	int jumlah;
	string nama;
	
	main:
	system("cls"); 
	cout<<"\n\n=========================================================\n\n";
	cout<<"\t\tNdaho Coffee & Workspace\n";
	cout<<"=========================================================\n\n";
	
	cout<<"1. Menu Kopi\n";
	cout<<"2. Pesan Kopi\n";
	cout<<"3. Hapus Antrian\n";
	cout<<"4. List Antrian\n";
	cout<<"5. Cari Penjualan Kopi\n";
	cout<<"6. Keluar";
	
	cout<<endl<<endl;
	
	cout<<"Pilih nomor: ";
	cin>>pilihan;
	
	if(pilihan==1) {
		sortingMenu();
		
        system("pause");
    	goto main;
	} else if(pilihan==2) {
		sortingMenu();
		cout<<"Nama pemesan : ";
		cin>>nama;
		cout<<"Masukkan nomor pilihan kopi : ";
		cin>>kopi;
		cout<<"Jumlah kopi : ";
		cin>>jumlah;
		enqueue(kopi, jumlah, nama);
		
        system("pause");
    	goto main;
	} else if(pilihan==3) {
		dequeue();
		
        system("pause");
    	goto main;
	} else if(pilihan==4) {
		print();
		
        system("pause");
    	goto main;
	} else if(pilihan==5) {
		sortingMenu();
		searchKopi();
		
		system("pause");
    	goto main;
	}else if(pilihan==6) {
		cout<<"Terima Kasih!\n\n";
		system("cls");
	}
	
	return 0;
}


