#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define jml 5
//Natania Regina Clarabella Serafina

typedef char string[90];

typedef struct {
	string nama;
	float berat;
} Barang;

typedef struct {
	string nama;
	string noTelp;
	string tglLahir;
	int noRek;
	int pin;
	double saldo;
	Barang barang[3];
} Nasabah;

//prosedur
void tampilMenu();
void initData(Nasabah N[]);
void menu2();
void showsemua(Nasabah N[]);
//fungsi

int getEmptyN(Nasabah N[]);

int main(int argc, char *argv[]) {
	Nasabah N[jml];

	int menu, index, rekening, opsi2, caripin, carinorek, pin, cari, i, j, indexbarang;
	string nasabah, notelp, lahir, barang, ambil;
	float berat;
	double saldo, tarik, setor, sisa;
	initData(N);

	

	do {
		tampilMenu();
		printf("\n>> ");
		scanf("%d", &menu);
		switch(menu) {
			case 1:
				if(getEmptyN(N)!=-1) {
					index = getEmptyN(N);
					printf("\n\tNasabah ke %d", index+1);
					printf("\n\nMasukan Nama Nasabah\t:");
					fflush(stdin);
					gets(nasabah);
					while(strlen(nasabah)==0 || strcmp(nasabah, "-")==0) {
						printf("\n\t[!] Nama Tidak Boleh Kosong");
						printf("\nMasukan Nama Nasabah\t:");
						fflush(stdin);
						gets(nasabah);
					}
					printf("\nMasukan Nomor Telepon Nasabah\t:");
					fflush(stdin);
					gets(notelp);
					while(strlen(notelp)<10 || strlen(notelp)>13 || strcmpi(notelp, N[jml].noTelp)==0) {
						if(strcmpi(notelp, N[jml].noTelp)==0) {
							printf("\n\t[!] Nomor Telepon Sudah Pernah diinput sebelumnya");
							printf("\nMasukan Nomor Telepon Nasabah\t:");
							fflush(stdin);
							gets(notelp);
						} else {
							printf("\n\t[!] Nomor Telepon Harus 10-13 Digit");
							printf("\nMasukan Nomor Telepon Nasabah\t:");
							fflush(stdin);
							gets(notelp);
						}
					}
					printf("\nMasukan Tanggal Lahir Nasabah\t:");
					fflush(stdin);
					gets(lahir);
					while(strlen(lahir)==0) {
						printf("\n[!] Tanggal Lahir Tidak Boleh Kosong");
						printf("\nMasukan Tanggal Lahir Nasabah\t:");
						fflush(stdin);
						gets(lahir);
					}

					rekening= (rand()%(9999-1000+1)+1000);
					printf("\n\tNo Rekening Anda\t: %d", rekening);
					printf("\nMasukan PIN\t: ");
					scanf("%d", &pin);
					while(pin<1000 || pin>9999) {
						printf("\n\t[!] PIN Harus 4 Digit");
						printf("\nMasukan PIN\t: ");
						scanf("%s", &pin);
					}
					printf("\nMasukan Saldo\t: ");
					scanf("%lf", &saldo);
					while(saldo<100000) {
						printf("\n\t[!] Minimal Input Saldo Rp. 100.000");
						printf("\nMasukan Saldo\t: ");
						scanf("%lf", &saldo);
					}
					printf("\n\n[!] Input Berhasil [!]");

					strcpy(N[index].nama, nasabah);
					strcpy(N[index].noTelp, notelp);
					strcpy(N[index].tglLahir, lahir);
					N[index].pin = pin;
					N[index].noRek = rekening;
					N[index].saldo = saldo;

				} else {
					printf("\n\tDATA PENUH [!]");
				}
				break;

			case 2:
				if(cekisi(N)!=-1) {
					do {
						menu2();
						printf("\n>> ");
						scanf("%d", &opsi2);

						switch(opsi2) {
							case 1:
								showsemua(N);
								break;

							case 2:
								printf("\nMasukan Nomor Rekening : ");
								scanf("%d", &cari);
								if(cariRek(N, cari)!=-1) {
									index=cariRek(N,cari);
									printf("\n======== [Rekening Anda] ========");
									printf("\n\nNama\t: %s", N[index].nama);
									printf("\n\nNo Telpon\t: %s", N[index].noTelp);
									printf("\n\nTanggal Lahir\t: %s", N[index].tglLahir);
									printf("\n\nNomor Rekening\t: %d", N[index].noRek);
									printf("\n\nSaldo\t: Rp. %.2lf", N[index].saldo);
								} else {
									printf("\n\tDATA TIDAK DITEMUKAN [!]");
								}
								break;

							case 0:
								break;

							default:
								printf("\n[!] Menu tidak ada");
								break;

						}
						getche();
					} while(opsi2!=0);

				} else {
					printf("\n\t DATA MASIH KOSONG [!]");
				}
				break;

			case 3:
				if(cekisi(N)!=-1) {

					printf("\nMasukan Nomor Rekening : ");
					scanf("%d", &carinorek);
					printf("\nMasukan PIN : ");
					scanf("%d", &caripin);
					if(cekcaripin(N, caripin)==-1 || cekcarirek(N, carinorek)==-1) {
						printf("\n\tNO REK ATAU PIN SALAH [!]");
					} else {
						index=cekcaripin(N, caripin);
						printf("\nMasukan Nama Nasabah\t:");
						fflush(stdin);
						gets(nasabah);
						while(strlen(nasabah)==0 || strcmp(nasabah, "-")==0) {
							printf("\n\t[!] Nama Tidak Boleh Kosong");
							printf("\nMasukan Nama Nasabah\t:");
							fflush(stdin);
							gets(nasabah);
						}
						printf("\nMasukan Nomor Telepon Nasabah\t:");
						fflush(stdin);
						gets(notelp);
						while(strlen(notelp)<10 || strlen(notelp)>13 || strcmpi(notelp, N[jml].noTelp)==0) {
							if(strcmpi(notelp, N[jml].noTelp)==0) {
								printf("\n\t[!] Nomor Telepon Sudah Pernah diinput sebelumnya");
								printf("\nMasukan Nomor Telepon Nasabah\t:");
								fflush(stdin);
								gets(notelp);
							} else {
								printf("\n\t[!] Nomor Telepon Harus 10-13 Digit");
								printf("\nMasukan Nomor Telepon Nasabah\t:");
								fflush(stdin);
								gets(notelp);
							}
						}
						printf("\nMasukan Tanggal Lahir Nasabah\t:");
						fflush(stdin);
						gets(lahir);
						while(strlen(lahir)==0) {
							printf("\n[!] Tanggal Lahir Tidak Boleh Kosong");
							printf("\nMasukan Tanggal Lahir Nasabah\t:");
							fflush(stdin);
							gets(lahir);
						}

						rekening= (rand()%(9999-1000+1)+1000);
						printf("\n\tNo Rekening Anda\t: %d", rekening);
						printf("\nMasukan PIN\t: ");
						scanf("%d", &pin);
						while(pin<1000 || pin>9999) {
							printf("\n\t[!] PIN Harus 4 Digit");
							printf("\nMasukan PIN\t: ");
							scanf("%d", &pin);
						}
						printf("\nMasukan Saldo\t: ");
						scanf("%lf", &saldo);
						while(saldo<100000) {
							printf("\n\t[!] Minimal Input Saldo Rp. 100.000");
							printf("\nMasukan Saldo\t: ");
							scanf("%lf", &saldo);
						}
						printf("\n\n[!] Berhasil Mengedit Data Nasabah");

						strcpy(N[index].nama, nasabah);
						strcpy(N[index].noTelp, notelp);
						strcpy(N[index].tglLahir, lahir);
						N[index].pin = pin;
						N[index].saldo = saldo;
					}

				} else {
					printf("\n[!] Data Nasabah Belum Diisi");
				}
				break;

			case 4:
				if(cekisi(N)!=-1) {
					printf("\nMasukan Nomor Rekening : ");
					scanf("%d", &carinorek);
					printf("\nMasukan Pin : ");
					scanf("%d", &caripin);
					if(cekcaripin(N, caripin)==-1 || cekcarirek(N, carinorek)==-1) {
						printf("\n\tNO REK ATAU PIN SALAH [!]");
					} else {
						index=cekcaripin(N, caripin);
						N[index].saldo = 0;
						N[index].noRek = 0;
						strcpy(N[index].tglLahir, "");
						N[index].pin = 0;
						strcpy(N[index].noTelp, "");
						strcpy(N[index].nama, "");
						printf("\n[!] Data Berhasil Dihapus");
					}
				} else {
					printf("\n[!] Data Nasabah Belum Diisi");

				}
				break;

			case 5:
				if(cekisi(N)!=-1) {
					if(cekslotbarang(N)!=-1) {
						printf("\nMasukan Nomor Rekening : ");
						scanf("%d", &carinorek);
						printf("\nMasukan PIN : ");
						scanf("%d", &caripin);
						if(cekcaripin(N, caripin)==-1 || cekcarirek(N, carinorek)==-1) {
							printf("\n\tNO REK ATAU PIN SALAH [!]");
						} else {
							index=cekcaripin(N, caripin);
							indexbarang=isibarang(N);
							printf("\n\tBarang ke %d", indexbarang+1);
							printf("\n\nMasukan Nama Barang\t:");
							fflush(stdin);
							gets(barang);
							while(strlen(barang)==0) {
								printf("\n[!] Nama Tidak Boleh Kosong");
								printf("\n\nMasukan Nama Barang\t:");
								fflush(stdin);
								gets(barang);
							}
							printf("\nMasukan Berat Barang\t:");
							scanf("%f", &berat);
							while(berat<=0) {
								printf("\n\t[!] Berat Tidak Boleh <= 0");
								printf("\nMasukan Berat Barang\t:");
								scanf("%f", &berat);
							}
							printf("\n\n[!] Input Berhasil [!]");

							strcpy(N[index].barang[index].nama, barang);
							N[index].barang[index].berat = berat;
						}
					} else {
						printf("\nDATA PENUH [!]");
					}

				} else {
					printf("\nData Belum Tersedia");
				}

				break;

			case 6:
				if(cekisi(N)!=-1) {
					printf("\nMasukan Nomor Rekening : ");
					scanf("%d", &carinorek);
					printf("\nMasukan Pin : ");
					scanf("%d", &caripin);
					if(cekcaripin(N, caripin)==-1 || cekcarirek(N, carinorek)==-1) {
						printf("\n\tNO REK ATAU PIN SALAH [!]");
					} else {
						index=cekcaripin(N, caripin);
						system("cls");
						printf("\n========== [Rekening Anda] =============");
						printf("\n\nNama\t: %s", N[index].nama);
						printf("\nNo Telpon\t: %s", N[index].noTelp);
						printf("\nTanggal Lahir\t: %s", N[index].tglLahir);
						printf("\nNomor Rekening\t: %d", N[index].noRek);
						printf("\nSaldo\t: Rp. %.2lf", N[index].saldo);
						for(j=0; j<3; j++) {
							if(strcmpi(N[i].barang[j].nama, "")!=0) {
								printf("\n\t\t== [Barang Nasabah %d] ==", i+1);
								printf("\n\tNama : %s", N[i].barang[j].nama);
								printf("\n\tBerat : %.2f", N[i].barang[j].berat);
							}
						}
						printf("\n\tMasukkan Nama Barang : ");
						fflush(stdin);
						gets(ambil);
						if(cekcaribarang(N)==-1) {
							index=cekcaribarang(N);
							N[i].barang[index].berat-= 1;
						} else {
							printf("\n\tDATA TIDAK DITEMUKAN [!]");
						}
					}
				} else if(cekbarang(N)==-1) {
					printf("\n\tDATA MASIH KOSONG");
				} else {
					printf("\nData Belum Tersedia");
				}

				break;

			case 7:
				if(cekisi(N)!=-1) {
					printf("\nMasukan Nomor Rekening : ");
					scanf("%d", &carinorek);
					printf("\nMasukan Pin : ");
					scanf("%d", &caripin);
					if(cekcaripin(N, caripin)==-1 || cekcarirek(N, carinorek)==-1) {
						printf("\n\tNO REK ATAU PIN SALAH [!]");
					} else {
						index=cekcaripin(N, caripin);
						printf("\nSaldo Anda : Rp.%.2lf", N[index].saldo);
						while(tarik<100000||tarik>N[index].saldo) {
							printf("\nMasukkan Nominal yang ingin anda tarik :");
							scanf("%lf", &tarik);
							if(tarik<100000) {
								printf("\n\tTIDAK BISA AMBIL UANG < Rp.100.000 [!]");
							} else if(tarik>N[index].saldo) {
								printf("\n\tSALDO ANDA TIDAK MENCUKUPI [!]");
								printf("\nSaldo Anda : Rp.%.2lf", N[index].saldo);
							}
						}
						printf("\nSilahkan Ambil Uang Anda ^-^");
						sisa =  N[index].saldo-tarik;
						printf("\nSisa Saldo Anda :Rp. %.2lf", N[index].saldo-tarik);

						N[index].saldo = sisa;

					}
				} else {
					printf("\nDATA MASIH KOSONG [!]");
				}
				break;

			case 8:
				if(cekisi(N)!=-1) {
					printf("\nMasukan Nomor Rekening : ");
					scanf("%d", &carinorek);
					printf("\nMasukan Pin : ");
					scanf("%d", &caripin);
					if(cekcaripin(N, caripin)==-1 || cekcarirek(N, carinorek)==-1) {
						printf("\n\tNO REK ATAU PIN SALAH [!]");
					} else {
						index=cekcaripin(N, caripin);
						printf("\nSaldo Anda : Rp. %.2lf", N[index].saldo);
						printf("\nMasukkan Nominal yang ingin anda setor : ");
						scanf("%lf", &setor);
						while(setor<100000) {
							printf("\nNOMINAL TIDAK BOLEH < Rp 100.000 [!]");
							printf("\nSaldo anda : Rp. %.2lf", N[index].saldo);
						}
						sisa = N[index].saldo+setor;
						printf("\nSaldo Rekening Anda : Rp %.2lf", N[index].saldo+setor);
						N[index].saldo = sisa;
					}
				} else {
					printf("\nDATA MASIH KOSONG [!]");
				}
				break;

			case 0:
				printf("\nNATANIA REGINA CLARBELLA SERAFINA ");
				break;

			default:
				printf("\n[!] Menu tidak ada");
				break;

		}
		getch();
	} while(menu!=0);

	return 0;
}

void tampilMenu() {
	system("cls");
	printf("\n===[ BANK CENTRAL ATMA ]===");
	printf("\n[1]. Buka Rekening");
	printf("\n[2]. Info Rekening");
	printf("\n[3]. Update Rekening");
	printf("\n[4]. Tutup Rekening");
	printf("\n[5]. Input Barang");
	printf("\n[6]. Ambil Barang");
	printf("\n===========================");
	printf("\n[7]. Tarik Saldo");
	printf("\n[8]. Setor Tunai");
	printf("\n===========================");
	printf("\n[0]. Exit");
}


void initData(Nasabah N[]) {
	int i, j;

	for (i = 0; i < jml; i++) {
		N[i].saldo = 0;
		N[i].noRek = 0;
		strcpy(N[i].tglLahir, "");
		N[i].pin = 0;
		strcpy(N[i].noTelp, "");
		strcpy(N[i].nama, "");
		for (j = 0; j < jml; j++) {
			N[i].barang[j].berat= 0;
			strcpy(N[i].barang[j].nama, "");
		}
	}
}

int cekslotbarang(Nasabah N[]) {
	int i,j;

	for(i=0; i<jml; i++) {
		for(j=0; j<3; j++) {
			if(N[i].barang[j].berat==0) {
				return i;
			}
		}
	}
	return -1;
}
void menu2() {
	system("cls");
	printf("\n===[ Tampil Rekening ]===");
	printf("\n[1]. Seluruh");
	printf("\n[2]. Salah satu");
	printf("\n=========================");
	printf("\n[0]. Main Menu");
}

int cekisi(Nasabah N[]) {
	int i;

	for(i = 0; i<jml; i++) {
		if(N[i].noRek!=0)
			return i;
	}
	return -1;
}

int getEmptyN(Nasabah N[]) {
	int i;

	for (i = 0; i < jml; i++) {
		if (N[i].noRek==0)
			return i;
	}
	return -1;
}

int cekcaribarang(Nasabah N[], string ambil) {
	int i,j;

	for(i=0; i<jml; i++) {
		for(j=0; j<3; j++) {
			if(strcmpi(ambil, N[i].barang[j].nama)==0) {
				return i;
			}
		}
	}
	return -1;
}
void showsemua(Nasabah N[]) {
	int i,j;

	for(i=0; i<jml; i++) {
		if(N[i].noRek!=0) {
			printf("\n===============================");
			printf("\n\tNasabah %d", i+1);
			printf("\n===============================");
			printf("\nNama          : %s", N[i].nama);
			printf("\nNo Telpon     : %s", N[i].noTelp);
			printf("\nTanggal Lahir : %s", N[i].tglLahir);
			printf("\n\nNomor Rekening   : %d", N[i].noRek);
			printf("\nPin              : %d", N[i].pin);
			printf("\n\nSaldo            : %lf", N[i].saldo);
			for(j=0; j<3; j++) {
				if(N[i].barang[j].berat!=0) {
					printf("\n\t\t== [Barang Nasabah %d]", i+1);
					printf("\n\tNama\t: %s", N[i].barang[j].nama);
					printf("\n\tBerat\t: %.2f", N[i].barang[j].berat);
				}
			}
		}
		printf("\n");
	}
}

int findN(Nasabah N[], int cari) {
	int i;

	for(i=0; i<jml; i++) {
		if(cari == N[i].noRek);
		return i;
	}
	return -1;
}

void tutupRek(Nasabah N[]) {
	int i,j;

	for (i = 0; i < jml; i++) {

		N[i].saldo = 0;
		N[i].noRek = 0;
		strcpy(N[i].tglLahir, "");
		N[i].pin = 0;
		strcpy(N[i].noTelp, "");
		strcpy(N[i].nama, "");
		for (j = 0; j < jml; j++) {
			N[i].barang[j].berat= 0;
			strcpy(N[i].barang[j].nama, "");
		}
	}
}

int cariRek(Nasabah N[], int cari) {
	int i;
	for(i = 0; i < jml; i++) {
		if(N[i].noRek==cari) {
			return i;
		}
	}
	return -1;
}

int cekcaripin(Nasabah N[], int caripin) {
	int i;
	for(i =0; i <jml; i++) {
		if(caripin==N[i].pin) {
			return i;
		}
	}
	return -1;
}
int cekcarirek(Nasabah N[], int carirek) {
	int i;
	for(i =0; i <jml; i++) {
		if(carirek==N[i].noRek) {
			return i;
		}
	}
	return -1;
}
int isibarang(Nasabah N[]) {
	int i,j;

	for(i=0; i<jml; i++) {
		for(j=0; j<3; j++) {
			if(N[i].barang[j].berat==0) {
				return i;
			}
		}
	}
	return -1;
}
int cekbarang(Nasabah N[]) {
	int i,j;

	for(i=0; i<5; i++) {
		for(j=0; j<5; j++) {
			if(N[i].barang[j].berat==0) {
				return i;
			}
		}
	}
	return -1;
}
