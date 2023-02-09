#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <locale.h>


void MenuYazdir()	// Menu Yazidirma Fonk 
{
	printf("\tMen�\n");
	printf("1-) Kay�t Ekle\n");
	printf("2-) Kay�tlari Listele\n");
	printf("3-) Ba�ar� Notlar�n� Hesapla\n");
	printf("4-) Kay�tlar� Ba�ar� Notuna G�re S�rala\n");
	printf("5-) �statistiki Bilgiler\n");
	printf("6-) ��k��\n");
	printf("\nBir Se�im Yap�n�z : ");
}

int OgrOrtalama(float not1,float not2 , float not3) // ogrenci genel ortalamasini hesapla
{
	float ortalama2;	// ondal�kl� ortalama hesaplamak icin deger
	int ortalama;	// int ortalama 
	ortalama2 = (not1/5)+((not2*3)/10)+(not3/2); //ondal�kl� ortalama hesapla
	ortalama = ortalama2;		// int ortalamaya ata (virg�lden sonras� kaybolur)
	ortalama2 -=0.5;	// virgulden sonras� buyukluk kontrolu icin ondalikli ort azalt
	
	
	if(ortalama <= ortalama2){ortalama++;}	//virgulden sonras� buyukluk kontrolu
	
	return ortalama;	// ortalama dondur
}

struct ogrenci	// ogrenci yapisi
 	{
 	char isim[15];
 	char soy_isim[15];
 	int vize1;
 	int vize2;
 	int final;
 	int nott;
 	};

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "Turkish");	// t�rk�e karakter kullanma
	
	int kontrol = 0;
	
	struct ogrenci ogrenciler[100];
	int secim = 0;
	int i;
	
	int sayac;
	FILE *fsayacp;
	fsayacp = fopen("sayactutucu.txt","r");
	fscanf(fsayacp,"%d",&sayac);
	fclose(fsayacp);
	FILE *fisimAc,*fsoyAc,*fnot1Ac,*fnot2Ac,*fFinalAc,*fnotAc;
	
	fisimAc = fopen("isimtutucu.txt","a");
	fclose(fisimAc);
	
	fsoyAc = fopen("soytutucu.txt","a");
	fclose(fsoyAc);
	
	fnot1Ac = fopen("not1tutucu.txt","a");
	fclose(fnot1Ac);
	
	fnot2Ac = fopen("not2tutucu.txt","a");
	fclose(fnot2Ac);
	
	fFinalAc = fopen("finaltutucu.txt","a");
	fclose(fFinalAc);
	
	fnot1Ac = fopen("notTutucu.txt","a");
	fclose(fnotAc);
	
	//-------------------------------------------------------------------
	FILE *fisimp;	//isim
	fisimp = fopen("isimtutucu.txt","r");
	for(i = 0;i<sayac;i++)
	{
		fscanf(fisimp, "%s\n",ogrenciler[i].isim);
	}
	fclose(fisimp);
	for(i = 0;i<sayac;i++)
	{
		printf("%s",ogrenciler[i].isim);
	}
	FILE *fsoyp = fopen("soyisimtutucu.txt","r");//soy isim
	for(i=0;i<sayac;i++)
	{
		fscanf(fsoyp, "%s\n",ogrenciler[i].soy_isim);
	}
	fclose(fsoyp);
	
	FILE *fnot1p = fopen("not1tutucu.txt","r");//vize1
	for(i=0;i<sayac;i++)
	{
		fscanf(fnot1p, "%d\n",&ogrenciler[i].vize1);
	}
	fclose(fnot1p);
	
	FILE *fnot2p = fopen("not2tutucu.txt","r");//vize2
	for(i=0;i<sayac;i++)
	{
		fscanf(fnot2p, "%d\n",&ogrenciler[i].vize2);
	}
	fclose(fnot2p);
	
	FILE *fFinalp = fopen("finaltutucu.txt","r");
	for(i=0;i<sayac;i++)
	{
		fscanf(fFinalp, "%d\n",&ogrenciler[i].final);
	}
	fclose(fFinalp);
	
	FILE *fnotp = fopen("notTutucu.txt","r");
	for(i=0;i<sayac;i++)
	{
		fscanf(fnotp, "%d\n",&ogrenciler[i].nott);
	}
	fclose(fnotp);
	
	//------------------------------------------------------
	
	do
	{
		scanf("%d",&secim);	//secim yapt�r
		if(secim <=6 && secim >=1)	// secim kontrol
		{
			if(secim == 1)	// kayit
			{
				float sinav1A,sinav2A,sonSinavA;	//ortalama hesabi icin float not degiskenleri gerekli
				
				printf("Ad� : ");
				scanf("%s",ogrenciler[sayac].isim);
				printf("Soyad� : ");
				scanf("%s",ogrenciler[sayac].soy_isim);
				printf("Ogrenci Notunu (1.s�nav(bosluk)2.s�nav(bosluk)final) fomat�nda giriniz .\n");
				printf("1.S�nav 2.S�nav Final : ");
				scanf("%f %f %f",&sinav1A,&sinav2A,&sonSinavA);
				
				int sart = 0;
				if(sinav1A<0 || sinav1A>100 || sinav2A<0 || sinav2A>100 || sonSinavA<0 || sonSinavA>100 )
				{
					printf("Hatal� Not Giri�i Yapt�n�z . Notlar 0-100 aral���nda olmal�d�r .\nL�tfen Tekrar Not Giriniz ... \n ");
					while(sart != 1)
					{
						printf("1.S�nav 2.S�nav Final : ");
						scanf("%f %f %f",&sinav1A,&sinav2A,&sonSinavA);
						if(sinav1A<0 || sinav1A>100 || sinav2A<0 || sinav2A>100 || sonSinavA<0 || sonSinavA>100 )
						{printf("Hatal� Not Giri�i Yapt�n�z . Notlar 0-100 aral���nda olmal�d�r .\nL�tfen Tekrar Not Giriniz ... \n ");}
						else{sart++;}
					}
	}
				
				ogrenciler[sayac].vize1 = sinav1A;	// float not degiskenlerini ortalama hesab�ndan sonra int a  ata
				ogrenciler[sayac].vize2 = sinav2A;
				ogrenciler[sayac].final = sonSinavA;
				
				ogrenciler[sayac].nott = OgrOrtalama(sinav1A,sinav2A,sonSinavA);
				sayac++;	// eklenen ogrenci say�s�n� artt�r .
							// dizi 0. indeksten baslayacagii i�in	dizi de ogrenci aranmak isterse sayac �n 1 eksiigi kadar indeks olur toplam �grenci sayiisi sayac a esit olur
				MenuYazdir();// tekrar menu yazd�r�p secim yapt�r
				
			}
			if(secim == 2)	// listele
			{	
				if(sayac>0)	//s�n�fta en az 1 tane ogrenci varm�
				{
					int i;	
					for(i = 0;i<sayac;i++)// ogrenciler dizisindeki indeks sayisi sayac �n 1 eksisigi oldugundan i<sayac yap�l�rsa butun elemanlara bak�l�r
					{
						printf("%s\t%s\t%d\t%d\t%d\t%d\t",ogrenciler[i].isim,ogrenciler[i].soy_isim,ogrenciler[i].vize1,ogrenciler[i].vize2,ogrenciler[i].final,ogrenciler[i].nott);
						// ogrenci bilgileri yazdir
						if(ogrenciler[i].nott>=90) {printf("AA\tGecti\n");}	// harf notlarini ve gecti kaldi durumlarini yazdir
						if(ogrenciler[i].nott>=85 && ogrenciler[i].nott <90) {printf("AB\tGecti\n");}
						if(ogrenciler[i].nott>=75 && ogrenciler[i].nott <85) {printf("BB\tGecti\n");}
						if(ogrenciler[i].nott>=70 && ogrenciler[i].nott <75) {printf("CB\tGecti\n");}
						if(ogrenciler[i].nott>=60 && ogrenciler[i].nott <70) {printf("CC\tGecti\n");}
						if(ogrenciler[i].nott>=55 && ogrenciler[i].nott <60) {printf("DC\tGecti\n");}
						if(ogrenciler[i].nott>=45 && ogrenciler[i].nott <55) {printf("DD\tGecti\n");}
						if(ogrenciler[i].nott>=40 && ogrenciler[i].nott <45) {printf("DF\t�artl� Gecti\n");}
						if(ogrenciler[i].nott <40) {printf("FF\tKald�\n");}
						
					}
					kontrol++;// liste en az 1 kere bast�r�lm�sm� kontrol etmeye yardimci olacak
					MenuYazdir();	// menu yazdir secim yaptir
					
				}
				
				else{printf("Hen�z Kay�tl� ��renci Yok ! \n");	MenuYazdir();}	// kayitli ogrenci yoksa hata mesaj�
			
			}
			if(secim == 3)	// not listele
			{
				if(kontrol>0)
				{
					int i;
					for(i = 0;i<sayac;i++)
					{
						printf("%s\t%s\t%d\t",ogrenciler[i].isim,ogrenciler[i].soy_isim,ogrenciler[i].nott);
						if(ogrenciler[i].nott>45) {printf("Gecti\n");}
						if(ogrenciler[i].nott>=40 && ogrenciler[i].nott <45) {printf("�artl� Gecti\n");}
						if(ogrenciler[i].nott <40) {printf("Kald�\n");}
						
					}
				MenuYazdir();
				}
				else{printf("�nce En Az 1 Kere 2. Se�im ile Kay�tlar� Listelemelisiniz . \n");	MenuYazdir();}
			}
			if(secim == 4)
			{
				if(kontrol>0)
				{
					int indeks = sayac-1;
					int i,j,s;
					struct ogrenci ogrencilerA[10];
					for(j = 0;j<sayac;j++)
					{
						for(i = 0;i<sayac-1;i++) {if(ogrenciler[i].nott>ogrenciler[i+1].nott){s = i;}}
						if(ogrenciler[sayac-1].nott>ogrenciler[s].nott) {s = sayac-1;}
						ogrencilerA[j] = ogrenciler[s];
						ogrenciler[s].nott = 0;
					}
					
					for(i = 0;i<sayac;i++) {ogrenciler[i] = ogrencilerA[i]; }
					
					printf("Ba�ar�yla S�ralama Yap�ld� . \n");
					printf("S�ralanm�� Yeni Listeyi G�rmek ��in 2. Se�im �le Kay�tlar� Listeleyiniz .\n");
					MenuYazdir();
				}
				else{printf("�nce En Az 1 Kere 2. Se�im ile Kay�tlar� Listelemelisiniz . \n");	MenuYazdir();}
			}
			if(secim == 5)
			{
				if(kontrol>0)
				{
					int ortalama,toplam = 0;
					int sayi = sayac - 1;
					int i;
					for(i = 0;i<sayac;i++) {toplam = toplam + ogrenciler[i].nott;}
					ortalama = toplam/sayi;
					printf("S�n�f Ortalamas� : %d\t",ortalama);
				
					
					int sToplam = 0;
					for(i = 0;i<sayac;i++) {sToplam = sToplam + pow((ortalama - ogrenciler[i].nott),2);}
					
					int karekok = sqrt(sToplam);
					printf("Standart Sapma : %d\n",karekok);
					
					
					int min = 100,max = 0;
					for(i = 0;i<sayac;i++) {if(ogrenciler[i].nott > max){max = ogrenciler[i].nott; } }
					for(i = 0;i<sayac;i++) {if(ogrenciler[i].nott < min){min = ogrenciler[i].nott; } }
					printf("En Y�ksek Not : %d\t En D���k Not : %d\n",max,min);
					
					
					int ortUstu = 0;
					for(i = 0;i<sayac;i++) {if(ogrenciler[i].nott > ortalama){ortUstu++; } }
					
					
					int gecenOgr = 0;
					for(i = 0;i<sayac;i++) {if(ogrenciler[i].nott >= 45){gecenOgr++; } }
					float BasariOrt = gecenOgr*5/sayi;
					
					printf("Ortalama �st� Not Alan ��renci Say�s� : %d \tGecen Ogrenci Sayisi : %d \t Basari Ortalamasi : %%%f",ortUstu,gecenOgr,BasariOrt);
					printf("\n");
					MenuYazdir();
				}
				else{printf("�nce En Az 1 Kere 2. Se�im ile Kay�tlar� Listelemelisiniz . \n");	MenuYazdir();}
				if(secim == 6)
				{
				printf("Cikis Saglaniyor ...");
				FILE *fsayacYazp = fopen("sayactutucu.txt","w");
				fprintf(fsayacYazp,"%d",sayac);
				fclose(fsayacYazp);
				}
			}
			if(secim == 6)	// cikis
			{
				printf("Cikis Saglaniyor ... ");
				FILE *fisimA = fopen("isimtutucu.txt","w");
				for(i=0;i<sayac;i++)
				{
					fprintf(fisimA, "%s\n",ogrenciler[i].isim);
				}
				fclose(fisimA);
				
				FILE *fsoyA = fopen("soytutucu.txt","w");
				for(i=0;i<sayac;i++)
				{
					fprintf(fsoyA, "%s\n",ogrenciler[i].soy_isim);
				}
				fclose(fsoyA);
				
				FILE *fnot1A = fopen("not1tutucu.txt","w");
				for(i=0;i<sayac;i++)
				{
					fprintf(fnot1A, "%s\n",ogrenciler[i].vize1);
				}
				fclose(fnot1A);
				
				FILE *fnot2A = fopen("not2tutucu.txt","w");
				for(i=0;i<sayac;i++)
				{
					fprintf(fnot2A, "%s\n",ogrenciler[i].vize2);
				}
				fclose(fnot2A);
				
				FILE *fFinalA = fopen("finaltutucu.txt","w");
				for(i=0;i<sayac;i++)
				{
					fprintf(fFinalA, "%s\n",ogrenciler[i].final);
				}
				fclose(fFinalA);
				
				FILE *fnotA = fopen("notTutucu.txt","w");
				for(i=0;i<sayac;i++)
				{
					fprintf(fnotA, "%s\n",ogrenciler[i].nott);
				}
				fclose(fnotA);
			}
		}
	}
	while(secim != 6);
	
	return 0;
	}
			
