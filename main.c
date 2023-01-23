#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAXCHAR 1000


/*STRUCT DECLARATIONS*/
typedef struct Ogrenci { char ogrID[9]; char ad[30]; char soyad[30]; int puan; struct Ogrenci *next; struct Ogrenci *prev;} Ogrenci;
typedef struct Yazar { int yazarID; char yazarAd[30]; char yazarSoyad[30]; struct Yazar *next;}Yazar;
typedef struct KitapOrnek { char EtiketNo[20]; char Durum[9]; struct KitapOrnek *next;} KitapOrnek;
typedef struct Kitap {char kitapAdi[30]; char ISBN[14]; int adet; struct Kitap *next; struct KitapOrnek *head;} Kitap;
typedef struct Tarih{ unsigned int gun:5; unsigned int ay:4; unsigned int yil:12;} Tarih;
typedef struct KitapOdunc{ char EtiketNo[20]; char ogrID[9]; int islemTipi:2; struct Tarih islemTarihi;} KitapOdunc;
typedef struct KitapYazar{ char ISBN[14]; int YazarID;} KitapYazar;


typedef struct listO {Ogrenci* head;} ListOgrenci;
typedef struct listY {Yazar* head;} ListYazar;
typedef struct listK {Kitap* head;} ListKitap;
/*END*/

/*LINKLIST DECLARATIONS*/
/***OGRENCI***/
Ogrenci* createNodeOgrenci(char ogrID[9], char ad[30], char soyad[30], int puan);
ListOgrenci* createListOgrenci();
void addOgrenci(char ogrID[9], char ad[30], char soyad[30], int puan,ListOgrenci* list);
void displayOgrenciler(ListOgrenci* list);
void displayOgrenci(char ogrID[9],ListOgrenci* list);
void deleteNodeOgrenci(char ogrID[9],ListOgrenci* list); 
Ogrenci* findOgrenci(char ogrID[9],ListOgrenci* list);

/***YAZARLAR***/
Yazar* createNodeYazar(int yazarID,char yazarAd[30],char yazarSoyad[30]);
ListYazar* createListYazar();
void addYazar(int yazarID,char yazarAd[30],char yazarSoyad[30],ListYazar* list);
void displayYazarlar(ListYazar* list);
void deleteNodeYazar(int yazarID,ListYazar* list,int* yazarCounter);
Yazar* findYazar(int yazarID,ListYazar* list);

/***KÝTAPLAR***/
ListKitap* createListKitap();
Kitap* createNodeKitap(char kitapAdi[30], char ISBN[14],int adet);
KitapOrnek* createOrnekKitapNode(KitapOdunc* koArray,int* kitapOduncCounter,char ISBN[14],char Durum[],int i);
void addOrnekKitap(KitapOdunc* koArray,int* kitapOduncCounter,char Durum[9],int i,Kitap* kitap);
Kitap* addKitap(KitapOdunc* koArray,int* kitapOduncCounter,char kitapAdi[30], char ISBN[14], int adet,ListKitap* list) ;
void displayOrnekKitaplar(Kitap* kitap);
void displayKitaplar(ListKitap* list);
void loopOrnekKitap(KitapOdunc* koArray,int* kitapOduncCounter,Kitap* kitap) ;
Kitap* findKitap(char ISBN[14],ListKitap* list);
void deleteNodeKitap(ListKitap* list,char ISBN[14]);

/***KÝTAP-YAZAR***/
KitapYazar* createKitapYazarNode(char ISBN[14],int yazarID);
void displayKitapYazar(KitapYazar* array,int* kitapYazarCounter);
void deleteKitapYazarID(KitapYazar* array,int* kitapYazarCounter,int yazarID);

/***KÝTAP-ODUNC***/
KitapOdunc* createKitapOduncNode(char EtiketNo[20],char ogrID[9],int islemTipi,unsigned int gun, unsigned int ay,unsigned int yil);
/*END*/


/*READ-WRITE FILE DECLARATIONS*/
void readOgrenci(ListOgrenci* list);
void readYazarlar(ListYazar* list,int*);
void readKitaplar(KitapOdunc* koArray,int* kitapOduncCounter,ListKitap* list);
void readOduncKitaplar(int* kitapOduncCounter,KitapOdunc* koArray,ListKitap* List);
void readKitapYazar(KitapYazar*,int*);

void updateKitapYazar(KitapYazar* kyArray,int* kitapYazarCounter);
void updateOgrenciler(ListOgrenci* listOgrenciler);
void updateYazarlar(ListYazar* list,int* yazarCounter);
void updateKitaplar(ListKitap* list);
void updateKitapOdunc(KitapOdunc* koArray,int* kitapOduncCounter);

void updateAllCsv(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler, ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter);
/*END*/

/*FUNCTIONALITY DECLARATIONS*/
void searchOgrenci(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter);
void ekleOgrenci(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter);
void deleteOgrenci(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter);
void updateOgrenci(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter);
void tumOgrenciler(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter);
void ekleYazar(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter);
void deleteYazar(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter);
void searchYazar(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter);
void updateYazar(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter);
void ekleKitap(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter);
void searchKitap(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter);
void raftakiKitap(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter);
void deleteKitap(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter);
void updateKitap(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter);
void kitapYazarEslestir(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter);
void kitapYazarGuncelle(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter);
void teslimNone(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter);
void oduncTeslim(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter);
void upToDateTeslim(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter);
void forbiddenStudent(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter);
/*END*/

/*FUNCTION DECLARATIONS*/
void menu(KitapOdunc*,KitapYazar*,ListOgrenci*,ListYazar*,ListKitap*,int*,int*,int*);
void subMenu(KitapOdunc*,KitapYazar*,ListOgrenci*,ListYazar*,ListKitap*,int*,int*,int*,int*);
void menuController(KitapOdunc*,KitapYazar*,ListOgrenci*,ListYazar*,ListKitap*,int*,int*,int*,int*,int*);
void CRUDmenu(KitapOdunc*,KitapYazar*,ListOgrenci*,ListYazar*,ListKitap*,int*, int*,int*,int*,int*);
/*END*/

int main() {
	//system("COLOR 0A");
	KitapYazar* kyArray = (KitapYazar*) malloc(sizeof(KitapYazar)*100);
	KitapOdunc* koArray = (KitapOdunc*) malloc(sizeof(KitapOdunc)*100);
	int kitapYazarCounter = 0;
	int kitapOduncCounter=0;
	int yazarCounter = 1;
	ListOgrenci* listOgrenciler = createListOgrenci();
	ListYazar* listYazarlar = createListYazar();
	ListKitap* listKitaplar = createListKitap();
	readOduncKitaplar(&kitapOduncCounter,koArray,listKitaplar);
	readYazarlar(listYazarlar,&yazarCounter);
	readOgrenci(listOgrenciler);
	readKitaplar(koArray,&kitapOduncCounter,listKitaplar);
	readKitapYazar(kyArray,&kitapYazarCounter);

	while(true) {
		menu(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,&yazarCounter,&kitapYazarCounter,&kitapOduncCounter);	
	}	
	free(kyArray);
	return 0;
}

//*********************************** READ/WRITE FILE *******************************//

void readKitapYazar(KitapYazar* array,int* kitapYazarCounter) {
	FILE *fp;
	char row[MAXCHAR];
	char temp[2][14];
	int i;
	
	fp = fopen("KitapYazar.csv","r");


    while (fgets(row, MAXCHAR, fp))
    {
    	i=0;
		char *p = strtok(row, ",");
		strcpy(temp[i],p);
        i++;
        while(p != NULL && i<2){
			p = strtok(NULL, ",");
			strcpy(temp[i],p);
			i++; 
		}
		KitapYazar* n = createKitapYazarNode(temp[0],atoi(temp[1]));
		strcpy(array[*kitapYazarCounter].ISBN,n->ISBN);
		array[*kitapYazarCounter].YazarID = n->YazarID;
		(*kitapYazarCounter) = (*kitapYazarCounter) + 1;
		free(n);
    }
    
    fclose(fp);
	
}

void readOgrenci(ListOgrenci* list) {
	FILE *fp;
    char row[MAXCHAR];
    char temp[4][30];
    int i;
    
    // OGRENCI READING HANDLE //
    fp = fopen("Ogrenciler.csv","r");


    while (fgets(row, MAXCHAR, fp))
    {
    	i=0;
		char *p = strtok(row, ",");
		strcpy(temp[i],p);
        i++;
        while(p != NULL && i<4){
			p = strtok(NULL, ",");
			strcpy(temp[i],p);
			i++; 
		}
		addOgrenci(temp[0],temp[1],temp[2],atoi(temp[3]),list);
    }
    
    fclose(fp);
}

void readYazarlar(ListYazar* list,int* yazarCounter) {
	FILE *fp;
    char row[MAXCHAR];
    char temp[3][30];
    int i;
    
    *yazarCounter = 1;
    
    // OGRENCI READING HANDLE //
    fp = fopen("Yazarlar.csv","r");


    while (fgets(row, MAXCHAR, fp))
    {
    	i=0;
		char *p = strtok(row, ",");
		strcpy(temp[i],p);
        i++;
        while(p != NULL && i<3){
			p = strtok(NULL, ",");
			strcpy(temp[i],p);
			i++; 
		}
		temp[2][strlen(temp[2])-1] = '\0';
		addYazar(atoi(temp[0]),temp[1],temp[2],list);
		(*yazarCounter) = atoi(temp[0]) + 1;
    }
    
    fclose(fp);
}

void readKitaplar(KitapOdunc* koArray,int* kitapOduncCounter,ListKitap* list) {
	FILE *fp;
    char row[MAXCHAR];
    char temp[3][30];
    int i;
    
    // OGRENCI READING HANDLE //
    fp = fopen("Kitaplar.csv","r");


    while (fgets(row, MAXCHAR, fp))
    {
    	i=0;
		char *p = strtok(row, ",");
		strcpy(temp[i],p);
        i++;
        while(p != NULL && i<3){
			p = strtok(NULL, ",");
			strcpy(temp[i],p);
			i++; 
		}
		addKitap(koArray,kitapOduncCounter,temp[0],temp[1],atoi(temp[2]),list);
    }
    
    fclose(fp);
}

void readOduncKitaplar(int* kitapOduncCounter,KitapOdunc* koArray,ListKitap* List) {
	FILE *fp;
    char row[MAXCHAR];
    char rowTwo[MAXCHAR];
    char temp[3][20];
    char dateTemp[3][4];
    int i,j;
    char *k;
    int counter;
    
    // OGRENCI READING HANDLE //
    fp = fopen("KitapOdunc.csv","r");


    while (fgets(row, MAXCHAR, fp))
    {
    	i=0;
    	j=0;
		char *p = strtok(row, ",");
		strcpy(temp[i],p);
        i++;
        while(p != NULL && i<4){
			p = strtok(NULL, ",");
			strcpy(temp[i],p);
			i++;
			}
		k = strtok(temp[3],".");
		strcpy(dateTemp[j],k);
		j++;
		while(k!=NULL && j<3) {
			k = strtok(NULL,".");
			strcpy(dateTemp[j],k);
			j++;	
		}
		KitapOdunc* n = createKitapOduncNode(temp[0],temp[1],atoi(temp[2]),atoi(dateTemp[0]),atoi(dateTemp[1]),atoi(dateTemp[2]));
		strcpy(koArray[*kitapOduncCounter].EtiketNo,n->EtiketNo);
		strcpy(koArray[*kitapOduncCounter].ogrID,n->ogrID);
		koArray[*kitapOduncCounter].islemTipi = n->islemTipi;
		koArray[*kitapOduncCounter].islemTarihi = n->islemTarihi; 
		(*kitapOduncCounter) = (*kitapOduncCounter) + 1;
		
    }
    fclose(fp);
}


void updateKitapYazar(KitapYazar* kyArray,int* kitapYazarCounter) {
	int i=0;
	FILE *fp;
	
	fp = fopen("KitapYazar.csv","w");
	
	for(;i<(*kitapYazarCounter);i++) {
		fprintf(fp,"%s,%d\n",kyArray[i].ISBN,kyArray[i].YazarID);
	}
	
	fclose(fp);
}

void updateOgrenciler(ListOgrenci* listOgrenciler) {
	FILE *fp;
	
	fp = fopen("Ogrenciler.csv","w");
	
	Ogrenci* current = listOgrenciler->head;
	if(listOgrenciler->head==NULL) {
		return;
	}
	for(;current!=NULL;current=current->next) {
		fprintf(fp,"%s,%s,%s,%d \n",current->ogrID,current->ad,current->soyad,current->puan);
	}
	
	
	fclose(fp);
}

void updateYazarlar(ListYazar* list,int* yazarCounter) {
	FILE *fp;
	fp = fopen("Yazarlar.csv","w+");
	
	if(!fp) {
		printf("Dosya bulunamadi");
		return;
	}
	
	Yazar* current = list->head;
	while(current){
		fprintf(fp,"%d,%s,%s",current->yazarID,current->yazarAd,current->yazarSoyad);
		current = current->next;
	}
	
	fclose(fp);
}

void updateAllCsv(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler, ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter) {
	updateKitapOdunc(koArray,kitapOduncCounter);
	updateOgrenciler(listOgrenciler);
	updateKitaplar(listKitaplar);
	updateYazarlar(listYazarlar,yazarCounter);
	updateKitapYazar(kyArray,kitapYazarCounter);
}

void updateKitapOdunc(KitapOdunc* koArray,int* kitapOduncCounter) {
    int i=0;
    char tarihTemp[1024];
    char buffer[256];
	FILE *fp;
	
	fp = fopen("KitapOdunc.csv","w");
	
	for(;i<(*kitapOduncCounter);i++) {
		strcat(tarihTemp,itoa(koArray[i].islemTarihi.gun,buffer,10));
		strcat(tarihTemp,".");
		strcat(tarihTemp,itoa(koArray[i].islemTarihi.ay,buffer,10));
		strcat(tarihTemp,".");
		strcat(tarihTemp,itoa(koArray[i].islemTarihi.yil,buffer,10));
		fprintf(fp,"%s,%s,%d,%s\n",koArray[i].EtiketNo,koArray[i].ogrID,koArray[i].islemTipi,tarihTemp);
		strcpy(tarihTemp,"");
		strcpy(buffer,"");
	}
	
	fclose(fp);
}

void updateKitaplar(ListKitap* list) {
	FILE *fp;
	fp=fopen("Kitaplar.csv","w");
	
	Kitap* current = list->head;
	if(list->head==NULL) {
		return;
	}
	for(;current!=NULL;current=current->next) {
		fprintf(fp,"%s,%s,%d\n",current->kitapAdi,current->ISBN,current->adet);
	}
	
	fclose(fp);
}
//*********************************** LINKED LIST ***********************************//
//*********KITAP-ODUNC*********//
KitapOdunc* createKitapOduncNode(char EtiketNo[20],char ogrID[9],int islemTipi,unsigned int gun, unsigned int ay,unsigned int yil) {
	KitapOdunc* n = malloc(sizeof(KitapOdunc));
	Tarih m;
	if(!n) {
		return NULL;
	}
	m.gun = gun;
	m.ay = ay;
	m.yil = yil;
	strcpy(n->EtiketNo,EtiketNo);
	strcpy(n->ogrID,ogrID);
	n->islemTipi = islemTipi;
	n->islemTarihi = m;
	
	return n;
}
//*********KITAPY-YAZAR********//
KitapYazar* createKitapYazarNode(char ISBN[14],int yazarID) {
	KitapYazar* n = malloc(sizeof(KitapYazar));
	if(!n) {
		return NULL;
	}
	strcpy(n->ISBN,ISBN);
	n->YazarID = yazarID;
	
	return n;
}

void deleteKitapYazarID(KitapYazar* array,int* kitapYazarCounter,int yazarID) {
	int c;
	for(c=0;c<(*kitapYazarCounter);c++) {
		if(array[c].YazarID == yazarID) {
			array[c].YazarID = -1;
		}
	}
}


void displayKitapYazar(KitapYazar* array,int* kitapYazarCounter) {
	int c;
	for(c=0;c<(*kitapYazarCounter);c++) {
		printf("THE %s and %d1""\n",array[c].ISBN, array[c].YazarID);
	}
}
//**********OGRENCI************//
Ogrenci* createNodeOgrenci(char ogrID[9],char ad[30],char soyad[30], int puan) {
	Ogrenci* n = malloc(sizeof(Ogrenci));
	if(!n) {
		return NULL;
	};	
	strncpy(n->ad,ad,30);
	strncpy(n->ogrID,ogrID,9);
	strncpy(n->soyad,soyad,30);
	n->puan = puan;
	n->next = NULL;
	n->prev=NULL;
	
	return n;
}

Ogrenci* findOgrenci(char ogrID[9],ListOgrenci* list) {
	Ogrenci* current = list->head;
	while(current!=NULL) {
		if(!strcmp(current->ogrID,ogrID)) {
			return current;
		} else {
			current = current->next;
		}
	}
	return NULL;
}

void displayOgrenci(char ogrID[9],ListOgrenci* list) {
	Ogrenci* current = findOgrenci(ogrID,list);
	if(current!=NULL) {
		printf("%s,%s,%s,%d\n",current->ogrID,current->ad,current->soyad,current->puan);
	}
	
}

ListOgrenci* createListOgrenci() {
	ListOgrenci* list = malloc(sizeof(ListOgrenci));
	if(!list) {
		return NULL;
	}
	list->head = NULL;
	return list;
}

void addOgrenci(char ogrID[9], char ad[30], char soyad[30], int puan,ListOgrenci* list) {
	Ogrenci* current = NULL;
	if(list->head == NULL) {
		list->head = createNodeOgrenci(ogrID,ad,soyad,puan);
		list->head->prev = NULL;
	} else {
		current = list->head;
		while(current->next != NULL ){
			current = current->next;
		}
		current -> next = createNodeOgrenci(ogrID,ad,soyad,puan);
		current->next->prev = current;
	}
}

void displayOgrenciler(ListOgrenci* list) {
	Ogrenci* current = list->head;
	if(list->head==NULL) {
		return;
	}
	for(;current!=NULL;current=current->next) {
		printf("ID: %s, ISIM: %s, SOYISIM: %s, PUAN: %d\n",current->ogrID,current->ad,current->soyad,current->puan);
	}
}
void deleteNodeOgrenci(char ogrID[9],ListOgrenci* list) {
	Ogrenci* current = list->head;
	Ogrenci* next = list->head->next;
	Ogrenci* previous = current;
	while(current!=NULL) {
		//== for strings look at the memory location while strcmp function looks at the content
		if(!strcmp(current->ogrID,ogrID)) {
			previous->next = current->next;
			next->prev = previous;
			if(current==list->head) {
				list->head = current->next;
			}
			free(current);
			
		}
		previous = current;
		current = current->next;
	}
}



//************YAZARLAR*************//
Yazar* createNodeYazar(int yazarID,char yazarAd[30],char yazarSoyad[30]) {
	Yazar* n = malloc(sizeof(Yazar));
	if(!n) {
		return NULL;
	}
	n->yazarID = yazarID;
	strcpy(n->yazarAd,yazarAd);
	strcpy(n->yazarSoyad,yazarSoyad);
	strcat(n->yazarSoyad,"\n");
	n->next = NULL;
	
	return n;
}

ListYazar* createListYazar() {
	ListYazar* list = malloc(sizeof(ListYazar));
	if(!list) {
		return NULL;
	}
	list->head = NULL;
	return list;
}

void addYazar(int yazarID,char yazarAd[30],char yazarSoyad[30],ListYazar* list) {
	Yazar* current = NULL;
	if(list->head == NULL) {
		list->head = createNodeYazar(yazarID,yazarAd,yazarSoyad);
	} else {
		current = list->head;
		while(current->next!=NULL){
			current = current->next;
		}
		current->next = createNodeYazar(yazarID,yazarAd,yazarSoyad);
	}
}

void displayYazarlar(ListYazar* list) {
	Yazar* current = list->head;
	if(list->head == NULL) {
		return;
	}
	while(current!= NULL) {
		printf("%d,%s,%s",current->yazarID,current->yazarAd,current->yazarSoyad);
		current=current->next;
	}
}
void deleteNodeYazar(int yazarID, ListYazar* list,int* yazarCounter) {
	Yazar* current = list->head;
	Yazar* next = current->next;
	Yazar* previous = list->head;
	
	while(current!=NULL) {
		if(current->yazarID==yazarID) {
			previous->next = current->next;
			if(list->head == current) {
				list->head = current->next;
			}
			next = current->next;
			free(current);
			
		}
		previous = current;
		current = current->next;
		}
	
	
}

Yazar* findYazar(int yazarID,ListYazar* list) {
	Yazar* current = list->head;
	while(current!=NULL) {
		if(current->yazarID == yazarID) {
			return current;
		} else {
			current = current->next;
	    }
	}
	return NULL;
}


/************************* KÝTAP ******************************/

void displayKitaplar(ListKitap* list) {
	Kitap* current = list->head;
	if(list->head == NULL) {
		return;
	}
	while(current!= NULL) {
		printf("\n%s,%s,%d\n",current->ISBN,current->kitapAdi,current->adet);
		displayOrnekKitaplar(current);
		current=current->next;
	}
}

void displayOrnekKitaplar(Kitap* kitap) {
	KitapOrnek* current = kitap->head;
	if(kitap->head == NULL) {
		return;
	}
	while(current!=NULL) {
		printf("----> Kitap Ornek Numarasi: %s, Suanki Konumu : %s\n",current->EtiketNo,current->Durum);
		current=current->next;
	}
}
Kitap* createNodeKitap(char kitapAdi[30], char ISBN[14],int adet) {
	Kitap* n = malloc(sizeof(Kitap));
	if(!n) {
		return NULL;
	}
	strcpy(n->kitapAdi,kitapAdi);
	strcpy(n->ISBN,ISBN);
	n->adet = adet;
	
	n->next = NULL;
	n->head = NULL;
	
	return n;
}

Kitap* addKitap(KitapOdunc* koArray,int* kitapOduncCounter,char kitapAdi[30], char ISBN[14], int adet,ListKitap* list) {
	Kitap* current = NULL;
	if(list->head == NULL) {
		list->head = createNodeKitap(kitapAdi,ISBN,adet);
		loopOrnekKitap(koArray,kitapOduncCounter,list->head);
		return list->head;
	} else {
		current = list->head;
		while(current->next != NULL) {
			current = current->next;
		}
		 current->next = createNodeKitap(kitapAdi,ISBN,adet);
		 loopOrnekKitap(koArray,kitapOduncCounter,current->next);
	}
	return current->next;
}

void loopOrnekKitap(KitapOdunc* koArray,int* kitapOduncCounter,Kitap* kitap) {
	int c;
	for(c = 1;c<=kitap->adet;c++) {
		addOrnekKitap(koArray,kitapOduncCounter,"RAFTA",c,kitap);
	}
}

void addOrnekKitap(KitapOdunc* koArray,int* kitapOduncCounter,char Durum[9],int i,Kitap* kitap) {
	KitapOrnek* current = NULL;
	if(kitap->head == NULL) {
		kitap->head = createOrnekKitapNode(koArray,kitapOduncCounter,kitap->ISBN,Durum,i);
	} else {
		current = kitap->head;
		while(current->next != NULL) {
			current = current->next;
		}
		current->next = createOrnekKitapNode(koArray,kitapOduncCounter,kitap->ISBN,Durum,i);
	}
}

void deleteNodeKitap(ListKitap* list,char ISBN[14]) {
	Kitap* current = list->head;
	Kitap* next = list->head->next;
	Kitap* previous = current;
	while(current!=NULL) {
		//== for strings look at the memory location while strcmp function looks at the content
		if(!strcmp(current->ISBN,ISBN)) {
			previous->next = current->next;
			if(current==list->head) {
				list->head = current->next;
			}
			free(current);
			
		}
		previous = current;
		current = current->next;
	}
}

KitapOrnek* createOrnekKitapNode(KitapOdunc* koArray,int* kitapOduncCounter,char ISBN[14],char Durum[9],int i) {
	int v;
	KitapOrnek* n = malloc(sizeof(KitapOrnek));
	if(!n) {
		return NULL;
	};
	// CREATING THE NEW ISBN
	char newISBN[20];
	char number[6];
	sprintf(number, "%d", i);
	strcpy(newISBN,ISBN);
	strcat(newISBN,"_");
	strcat(newISBN,number);
	//
	strcpy(n->EtiketNo,newISBN);
	for(v=0;v<(*kitapOduncCounter);v++) {
		if(!strcmp(koArray[v].EtiketNo,n->EtiketNo) && koArray[v].islemTipi == 0) {
			strcpy(n->Durum,koArray[v].ogrID);
			n->next = NULL;
			return n;
		}
	}
	strcpy(n->Durum,Durum);
	n->next = NULL;
	
	return n;
};

Kitap* findKitap(char ISBN[14],ListKitap* list) {
	Kitap* current = list->head;
	while(current!=NULL) {
		if(!strcmp(current->ISBN,ISBN)) {
			return current;
		} else {
			current = current->next;
		}
	}
	return NULL;
}


ListKitap* createListKitap() {
	ListKitap* list = malloc(sizeof(ListKitap));
	if(!list) {
		return NULL;
	}
	list->head = NULL;
	return list;
}

//*********************************** MENU *************************************//

void menu(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler, ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter) {
	int menuCounter = 0;
	printf("Kutuphane Otomasyon Sistemine Hosgeldin\n");
	printf("\n1) Ogrenci Islemleri\n");
	printf("2) Kitap Islemleri\n");
	printf("3) Yazar Islemleri\n\n");
	printf("Bir islem secmek icin islem numarasini giriniz[-1 ile programdan cikiniz]: \t");
	scanf("%d",&menuCounter);
	while(menuCounter<1 || menuCounter>3) {
		if(menuCounter==-1) {
		system("cls");
		printf("_____SISTEM KAPATILIYOR_____");
		exit(0);
	} else {
		printf("Lutfen gecerli bir islem numarasi giriniz: \t");
		scanf("%d",&menuCounter);
	}
	}
	system("cls");
	subMenu(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,&menuCounter,yazarCounter,kitapYazarCounter,kitapOduncCounter);
}

void subMenu(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* menuCounter,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter) {
	int submenuCounter=0;
		if(*menuCounter==1) {
			printf("Ogrenci Islemlerine Hosgeldiniz (Ust menuye cikmak icin 0 yaziniz)\n");
				printf("\n1) Ogrenci Ekle, Sil, Guncelle\n");
				printf("2) Ogrenci Bilgisi Goruntuleme\n");
				printf("3) Kitap Teslim Etmemis Ogrencileri Listele:\n");
				printf("4) Cezali Ogrencileri Listele\n");
				printf("5) Tum ogrencileri listele\n");
				printf("6) Kitap Odunc Al/Teslim Et\n\n");
				printf("Bir islem secmek icin islem numarasini giriniz: \t");
				scanf("%d",&submenuCounter);
				while(submenuCounter<0 || submenuCounter>6) {
				   printf("Lutfen gecerli bir islem numarasi giriniz: \t");
				   scanf("%d",&submenuCounter);
				}
				menuController(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,menuCounter,&submenuCounter,yazarCounter,kitapYazarCounter,kitapOduncCounter);
		} 
		if(*menuCounter==2) {
				printf("Kitap Islemlerine Hosgeldiniz (Ust menuye cikmak için 0 yaziniz)\n");
				printf("\n1) Kitap Ekle, Sil, Guncelle\n");
				printf("2) Kitap Bilgisi Goruntuleme\n");
				printf("3) Raftaki Kitaplari Listele:\n");
				printf("4) Zamaninda Teslim Edilmeyen Kitaplari Listele\n");
				printf("5) Kitap-Yazar eslestir\n");
				printf("6) Kitabin yazarini guncelle\n\n");
				printf("Bir islem secmek icin islem numarasini giriniz: \t");
				scanf("%d",&submenuCounter);
				while(submenuCounter<0 || submenuCounter>6) {
				   printf("Lutfen gecerli bir islem numarasi giriniz: \t");
				   scanf("%d",&submenuCounter);
				}
				menuController(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,menuCounter,&submenuCounter,yazarCounter,kitapYazarCounter,kitapOduncCounter);
		}
		if(*menuCounter==3) {
        		printf("Yazar Islemlerine Hosgeldiniz (Ust menuye cikmak icin 0 yaziniz)\n");
				printf("\n1) Yazar Ekle, Sil, Guncelle\n");
				printf("2) Yazar Bilgisi Goruntuleme\n\n");
				printf("Bir islem secmek icin islem numarasini giriniz: \t");
				scanf("%d",&submenuCounter);
				while(submenuCounter<0 || submenuCounter>2) {
				   printf("Lutfen gecerli bir islem numarasi giriniz: \t");
				   scanf("%d",&submenuCounter);
				}
				menuController(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,menuCounter,&submenuCounter,yazarCounter,kitapYazarCounter,kitapOduncCounter);				
	}
}

void menuController(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* menuCounter,int* submenuCounter,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter) {
	if(*menuCounter == 1) {
	   switch (*submenuCounter){
	    	case 0:
		    	system("cls");
			    break;
			case 1:
				CRUDmenu(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,menuCounter,submenuCounter,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				break;
			case 2:
				system("cls");
				searchOgrenci(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				system("cls");
				break;
			case 3:
				system("cls");
				teslimNone(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				system("cls");
				break;
			case 4:
				system("cls");
				forbiddenStudent(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				system("cls");
				break;
			case 5:
				system("cls");
				tumOgrenciler(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				system("cls");
				break;
			case 6:
				system("cls");
				oduncTeslim(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				updateAllCsv(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				system("cls");
			    break;
			}
		}
	if(*menuCounter == 2) {
		switch(*submenuCounter) {
			case 0:
				system("cls");
				break;
			case 1:
				CRUDmenu(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,menuCounter,submenuCounter,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				break;
			case 2:
				system("cls");
				searchKitap(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				system("cls");
				break;
			case 3:
				system("cls");
				raftakiKitap(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				system("pause");
				system("cls");
				break;
			case 4:
				system("cls");
				upToDateTeslim(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				system("pause");
				system("cls");
				break;
			case 5:
				system("cls");
				kitapYazarEslestir(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				updateAllCsv(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				system("pause");
				system("cls");
				break;
			case 6:
				system("cls");
				kitapYazarGuncelle(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				updateAllCsv(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				system("pause");
				system("cls");
				break;
		}
	}
	if(*menuCounter == 3) {
		switch(*submenuCounter) {
			case 0:
				system("cls");
				break;
			case 1:
				CRUDmenu(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,menuCounter,submenuCounter,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				updateAllCsv(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				break;
			case 2:
				system("cls");
				searchYazar(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				system("cls");
				break;
		}
	}
}

void CRUDmenu(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* menuCounter, int* submenuCounter,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter) {
	int altOpt;
	system("cls");
	printf("---CRUD OPERASYONLARI---\n");
	printf("1) EKLE\n");
	printf("2) SIL\n");
	printf("3) GUNCELLE\n\n");
	printf("Hangi CRUD islemini yapmak istersiniz:\t");
	scanf("%d",&altOpt);
	while(altOpt<0||altOpt>3) {
		printf("Lutfen gecerli bir CRUD islem numarasi giriniz:\t");
		scanf("%d",&altOpt);
	}
	
	switch(altOpt) {
		case 0:
			system("cls");
			break;
		case 1:
			if(*menuCounter == 1) {
				system("cls");
			    ekleOgrenci(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
			    updateAllCsv(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
			    system("cls");
			} else if (*menuCounter == 2) {
			    system("cls");
			    ekleKitap(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
			    updateAllCsv(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				system("cls");
			} else if(*menuCounter == 3) {
				system("cls");
				ekleYazar(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				updateAllCsv(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				system("cls");
			}
			break;
		case 2:
			if(*menuCounter == 1) {
				system("cls");
			    deleteOgrenci(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				updateAllCsv(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
			    system("cls");
			} else if(*menuCounter==2){
				system("cls");
				deleteKitap(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				updateAllCsv(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				system("cls");
			}
			 else if(*menuCounter==3) {
				system("cls");
				deleteYazar(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				updateAllCsv(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				system("cls");
			}
			break;
		case 3:
			if(*menuCounter == 1) {
				system("cls");
				updateOgrenci(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				updateAllCsv(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				system("cls");
			} else if(*menuCounter==2) {
				system("cls");
				updateKitap(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				updateAllCsv(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				system("cls");
			} 
			else if(*menuCounter==3) {
				system("cls");
				updateYazar(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				updateAllCsv(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
				system("cls");
			}
			break;
	}
}


//************************************************** FUNCTIONALITY **********************************************//
//OGRENCI//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void searchOgrenci(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter) {
	char ogrID[9];
	printf("-Sorgulamak istediginiz ogrencinin IDsini giriniz:\t");
	scanf("%8s",&ogrID);
	Ogrenci* found = findOgrenci(ogrID,listOgrenciler);
	while(!found && strcmp(ogrID,"0")) {
		printf("-Boyle bir kullanici bulunamadi, lutfen gecerli bir ID giriniz:\t");
		scanf("%8s",ogrID);
		found = findOgrenci(ogrID,listOgrenciler);
	}
	if(!strcmp(ogrID,"0")) {
		system("cls");
		menu(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
		return;
	}
	system("cls");
	printf("Aradiginiz kullanici bulundu:\n\n");
	printf("ID:%s\nAD:%s\nSOYAD:%s\nPUAN:%d\n",found->ogrID,found->ad,found->soyad,found->puan);
	system("pause");
}

void ekleOgrenci(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter) {
	char ogrID[9];
	char ad[30];
	char soyad[30];
	printf("KULLANICI EKLEME\n");
	printf("ID (8 karakter olmak zorundadir):\t");
	scanf("%8s",ogrID);
	printf("AD (Maksimum 29 karakter):\t");
	scanf("%29s",ad);
	printf("SOYAD (Maksimum 29 karakter):\t");
	scanf("%29s",soyad);
	printf("\n........Isleminiz faaliyete alinmistir.....\n");
	addOgrenci(ogrID,ad,soyad,100,listOgrenciler);
	printf("\n///ISLEM TAMAMLANDI////\n");
	system("pause");
}


void deleteOgrenci(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter) {
	char ogrID[9];
	int switcher;
	printf("-Silmek istediginiz ogrencinin IDsini giriniz:\t");
	scanf("%8s",&ogrID);
	Ogrenci* found = findOgrenci(ogrID,listOgrenciler);
	while(!found) {
		printf("-Boyle bir kullanici bulunamadi, lutfen gecerli bir ID giriniz:\t");
		scanf("%8s",ogrID);
		found = findOgrenci(ogrID,listOgrenciler);
	}
	system("cls");
	printf("Aradiginiz kullanici bulundu:\n\n");
	printf("ID:%s\nAD:%s\nSOYAD:%s\nPUAN:%d\n",found->ogrID,found->ad,found->soyad,found->puan);
	system("pause");
	printf("Silmek istediginizden emin misiniz[1,0]:\t");
	scanf("%d",&switcher);
	while(switcher!=0 && switcher!=1) {
		printf("Lutfen gecerli bir cevap giriniz. Silmek istediginizden emin misiniz[1,0]:\t");
	    scanf("%d",&switcher);
	}
	
	if(switcher == 0) {
		system("cls");
		menu(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
	} else if(switcher==1) {
		printf("%s",ogrID);
		deleteNodeOgrenci(ogrID,listOgrenciler);
		updateOgrenciler(listOgrenciler);
		printf("\n//// ISLEM TAMAMLANDI ///");
		system("pause");
	}
	
}

void updateOgrenci(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter)  {
	char ogrID[9];
	printf("-Guncellemek istediginiz ogrencinin IDsini giriniz:\t");
	scanf("%8s",ogrID);
	Ogrenci* found = findOgrenci(ogrID,listOgrenciler);
	while(!found) {
		printf("-Boyle bir ogrenci bulunamadi, lutfen gecerli bir ID giriniz:\t");
		scanf("%8s",ogrID);
		found = findOgrenci(ogrID,listOgrenciler);
	}
	if(!strcmp(ogrID,"0")) {
	    system("cls");
		menu(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
		return;
	}
	char ad[30];
	char soyad[30];
	system("cls");
		printf("Uzerinde islem yapilan kullanici: \n");
	printf("ID:%s\nAD:%s\nSOYAD:%s\nPUAN:%d\n\n",found->ogrID,found->ad,found->soyad,found->puan);
	printf("-Guncelleme parametreleri yerine 0 yazarsaniz yazarin eskiden var olan degerleri degistirilmez.\n");
	printf("\nAd (maksimum 29 karakter):\t");
	scanf("%s",ad);
	printf("\nSoyad (maksimum 29 karakter):\t");
    scanf("%s",soyad);
	printf("\n.........Islem Suruyor............\n");
	if(!strcmp(ad,"0")){
		strcpy(found->soyad,soyad);
	} else if (!strcmp(soyad,"0")) {
		strcpy(found->ad,ad);
	} else {
	  strcpy(found->soyad,soyad);
	  strcpy(found->ad,ad);	
	}
	updateOgrenciler(listOgrenciler);
	printf("//// ISLEM TAMAMLANDI ////\n");
	system("pause");
}

void tumOgrenciler(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter)  {
	printf("--- OGRENCI PANELI ---\n\n");
	printf("Sistemde kayitli tum ogrencilerin listesi :\n\n");
	displayOgrenciler(listOgrenciler);
	printf("\n");
	system("pause");
}
//YAZAR//
////////////////////////////////////////////////////////////////////////////////////////////////////
void ekleYazar(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter)  {
    int yazarID = (*yazarCounter);
	char yazarAd[30];
	char yazarSoyad[30];
	printf("YAZ4AR EKLEME\n");
	printf("ID:\t\%d\n",*yazarCounter);
	printf("AD (Maksimum 29 karakter):\t");
	scanf("%29s",yazarAd);
	printf("SOYAD (Maksimum 29 karakter):\t");
	scanf("%29s",yazarSoyad);
	printf("\n........Isleminiz faaliyete alinmistir.....\n");
	addYazar((*yazarCounter),yazarAd,yazarSoyad,listYazarlar);
	(*yazarCounter) = (*yazarCounter) + 1;
	printf("\n///ISLEM TAMAMLANDI////\n");
	system("pause");
	
}

void deleteYazar(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter)  {
	int switcher;
	int yazarID;
	printf("-Silmek istediginiz yazarin IDsini giriniz:\t");
	scanf("%d",&yazarID);
	Yazar* found = findYazar(yazarID,listYazarlar);
	while(!found) {
		printf("-Boyle bir yazar bulunamadi, lutfen gecerli bir ID giriniz:\t");
		scanf("%d",yazarID);
		found = findYazar(yazarID,listYazarlar);
	}
	system("cls");
	printf("Aradiginiz kullanici bulundu:\n\n");
	printf("ID:%d\nAD:%s\nSOYAD:%s\n",found->yazarID,found->yazarAd,found->yazarSoyad);
	system("pause");
	printf("Silmek istediginizden emin misiniz[1,0]:\t");
	scanf("%d",&switcher);
	while(switcher!=0 && switcher!=1) {
		printf("Lutfen gecerli bir cevap giriniz. Silmek istediginizden emin misiniz[1,0]:\t");
	    scanf("%d",&switcher);
	}
	
	if(switcher == 0) {
		system("cls");
		menu(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
	} else if(switcher==1) {
		printf("%d",yazarID);
		deleteNodeYazar(yazarID,listYazarlar,yazarCounter);
		deleteKitapYazarID(kyArray,kitapYazarCounter,yazarID);
		printf("\n//// ISLEM TAMAMLANDI ///");
		system("pause");
			}
	
}

void searchYazar(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter)  {
	int yazarID;
	int counter = 0;
	printf("-Sorgulamak istediginiz yazarin IDsini giriniz:\t");
	scanf("%d",&yazarID);
	Yazar* found = findYazar(yazarID,listYazarlar);
	while(!found && yazarID!=0) {
		printf("-Boyle bir kullanici bulunamadi, lutfen gecerli bir ID giriniz:\t");
		scanf("%d",&yazarID);
		found = findYazar(yazarID,listYazarlar);
	}
	if(yazarID==0) {
		system("cls");
		menu(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
		return;
	}
	system("cls");
	
	printf("Aradiginiz kullanici bulundu:\n\n");
	printf("ID:%d\nAD:%s\nSOYAD:%s\n",found->yazarID,found->yazarAd,found->yazarSoyad);
	printf("Yazara ait kitaplar:\n");
		Kitap* result = (Kitap*) malloc(sizeof(Kitap));
		while(counter<=(*kitapYazarCounter)) {
		
			if(kyArray[counter].YazarID == found->yazarID) {
				result = findKitap(kyArray[counter].ISBN,listKitaplar);
				printf("%s numarali ve %s isimli kitabin yazaridir. Kutuphanemizde %d adet bulunmaktadir.\n",result->ISBN,result->kitapAdi,result->adet);
			}
			counter++;
	}
	free(result);
	system("pause");
}

void updateYazar(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter)  {
	int yazarID;
	printf("-Guncellemek istediginiz yazarin IDsini giriniz:\t");
	scanf("%d",&yazarID);
	Yazar* found = findYazar(yazarID,listYazarlar);
	while(!found && yazarID!=0) {
		printf("-Boyle bir kullanici bulunamadi, lutfen gecerli bir ID giriniz:\t");
		scanf("%d",&yazarID);
		found = findYazar(yazarID,listYazarlar);
	}
	if(yazarID==0) {
	    system("cls");
		menu(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
		return;
	}
	char yazarAd[30];
	char yazarSoyad[30];
	system("cls");
		printf("Uzerinde islem yapilan kullanici: \n");
	printf("ID:%d\nAD:%s\nSOYAD:%s\n\n",found->yazarID,found->yazarAd,found->yazarSoyad);
	printf("-Guncelleme parametreleri yerine 0 yazarsaniz yazarin eskiden var olan degerleri degistirilmez.\n");
	printf("\nAd (maksimum 29 karakter):\t");
	scanf("%s",yazarAd);
	printf("\nSoyad (maksimum 29 karakter):\t");
    scanf("%s",yazarSoyad);
	printf("\n.........Islem Suruyor............\n");
	if(!strcmp(yazarAd,"0")){
		strcpy(found->yazarSoyad,yazarSoyad);
	} else if (!strcmp(yazarSoyad,"0")) {
		strcpy(found->yazarAd,yazarAd);
	} else {
	  strcpy(found->yazarSoyad,yazarSoyad);
	  strcpy(found->yazarAd,yazarAd);	
	}
	printf("//// ISLEM TAMAMLANDI ////\n");
	system("pause");
}

//KÝTAPLAR//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ekleKitap(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter)  {
	char kitapAdi[30];
	char ISBN[14];
	int adet;
	printf("KITAP EKLEME\n");
	printf("\nKitap Adi (maksimum 29 karakter):\t");
	scanf("%s",kitapAdi);
	printf("\nKitabin ISBN numarasini giriniz (maksimum 12 karakter):\t");
	scanf("%s",ISBN);
	printf("\nKitaptan kac adet oldugunu giriniz:\t");
	scanf("%d",&adet);
	printf("\n------ISLEMINIZ SURUYOR-------\n");
	addKitap(koArray,kitapOduncCounter,kitapAdi,ISBN,adet,listKitaplar);
	printf("\n/////// ISLEM TAMAMLANDI //////////\n");
	system("pause");
}

void searchKitap(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter)  {
	char ISBN[14];
	printf("-Sorgulamak istediginiz kitabin ISBNsini giriniz:\t");
	scanf("%13s",&ISBN);
	Kitap* found = findKitap(ISBN,listKitaplar);
	while(!found && strcmp(ISBN,"0")) {
		printf("-Boyle bir kitap bulunamadi, lutfen gecerli bir ISBN giriniz:\t");
		scanf("%13s",ISBN);
		found = findKitap(ISBN,listKitaplar);
	}
	if(!strcmp(ISBN,"0")) {
		system("cls");
		menu(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
		return;
	}
	system("cls");
	printf("Aradiginiz kitap bulundu:\n\n");
	printf("------------------- KITAP ----------------------------\n");
	printf("KITAP ADI:%s\nISBN:%s\nADET:%d\n",found->kitapAdi,found->ISBN,found->adet);
	printf("------------------- STOK DURUMU ----------------------\n");
	displayOrnekKitaplar(found);
	
	system("pause");
}

void updateKitap(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter)  {
	char ISBN[14];
	printf("-Guncellemek istediginiz kitabin ISBNsini giriniz:\t");
	scanf("%13s",ISBN);
	Kitap* found = findKitap(ISBN,listKitaplar);
	while(!found) {
		printf("-Boyle bir kitap bulunamadi, lutfen gecerli bir ISBN giriniz:\t");
		scanf("%13s",ISBN);
		found = findKitap(ISBN,listKitaplar);
	}
	if(!strcmp(ISBN,"0")) {
	    system("cls");
		menu(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
		return;
	}
	char kitapAdi[30];
	system("cls");
	printf("Uzerinde islem yapilan kitap: \n");
	printf("ISBN:%d\nAD:%s\nADET:%d\n\n",found->ISBN,found->kitapAdi,found->adet);
	printf("-Guncelleme parametreleri yerine 0 yazarsaniz yazarin eskiden var olan degerleri degistirilmez.\n");
	printf("\nAd (maksimum 29 karakter):\t");
	scanf("%29s",kitapAdi);
	printf("\n.........Islem Suruyor............\n");
	if(strcmp(kitapAdi,"0")){
		strcpy(found->kitapAdi,kitapAdi);
	} 
	updateKitaplar(listKitaplar);
	printf("//// ISLEM TAMAMLANDI ////\n");
	system("pause");
}

void deleteKitap(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter)  {
	int switcher;
	char ISBN[14];
	printf("-Silmek istediginiz kitabin ISBNsini giriniz:\t");
	scanf("%14s",ISBN);
	Kitap* found = findKitap(ISBN,listKitaplar);
	while(!found) {
		printf("-Boyle bir kitap bulunamadi, lutfen gecerli bir ISBN giriniz:\t");
		scanf("%14s",ISBN);
		found = findKitap(ISBN,listKitaplar);
	}
	system("cls");
	printf("Aradiginiz kitap bulundu:\n\n");
	printf("ISBN:%s\nAD:%s\nADET:%d\n",found->ISBN,found->kitapAdi,found->adet);
	system("pause");
	printf("Silmek istediginizden emin misiniz[1,0]:\t");
	scanf("%d",&switcher);
	while(switcher!=0 && switcher!=1) {
		printf("Lutfen gecerli bir cevap giriniz. Silmek istediginizden emin misiniz[1,0]:\t");
	    scanf("%d",&switcher);
	}
	
	if(switcher == 0) {
		system("cls");
		menu(koArray,kyArray,listOgrenciler,listYazarlar,listKitaplar,yazarCounter,kitapYazarCounter,kitapOduncCounter);
	} else if(switcher==1) {
		printf("%s",ISBN);
		deleteNodeKitap(listKitaplar,ISBN);
		printf("\n//// ISLEM TAMAMLANDI ///");
		system("pause");
	}
	
}

void raftakiKitap(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter) {
	int c;
	printf("--------RAFTAKI KITAPLAR--------\n\n");
	Kitap* current = listKitaplar->head;
	KitapOrnek* currentOrnek = NULL;
	if(current == NULL) {
		printf("Kitap bulunamadi....\n");
	} else {
		while(current!=NULL) {
			currentOrnek = current->head;
			printf("/ %s isimli ve %s ISBN numarali kitap:\n",current->kitapAdi,current->ISBN);
			for(c=1;c<=current->adet;c++) {
				if(!strcmp(currentOrnek->Durum,"RAFTA")) {
					printf("--- ETIKET: %s, DURUM: %s\n",currentOrnek->EtiketNo,currentOrnek->Durum);
				}
				currentOrnek = currentOrnek->next;
			}
			printf("\n");
			current=current->next;
		}
	}
}


//KÝTAP-YAZAR//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void kitapYazarEslestir(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter) {
	int yazarID;
	char ISBN[14];
	printf("--------ESLESTIRME SISTEMI--------\n");
	printf("Eslestirmek istediginiz kitap ISBN numarasini giriniz:\t");
	scanf("%14s",ISBN);
	Kitap* result = findKitap(ISBN,listKitaplar);
	while(result == NULL) {
		printf("Lutfen gecerli bir ISBN numarasi giriniz:\t");
		scanf("%14s",ISBN);
		result = findKitap(ISBN,listKitaplar);
	}
	printf("Eslestirilmek istenen kitap sistemde bulundu !\n\n");
	printf("Eslestirmek istediginiz yazarin IDsini giriniz:\t");
	scanf("%d",&yazarID);
	Yazar* resultTwo = findYazar(yazarID,listYazarlar);
	while(resultTwo == NULL) {
		printf("Lutfen gecerli bir yazarID giriniz:\t");
		scanf("%d",&yazarID);
		resultTwo = findYazar(yazarID,listYazarlar);
	}
	KitapYazar *matched = createKitapYazarNode(ISBN,yazarID);
	strcpy(kyArray[*kitapYazarCounter].ISBN, matched->ISBN);
	kyArray[*kitapYazarCounter].YazarID = matched->YazarID;
	(*kitapYazarCounter) = (*kitapYazarCounter) + 1;
	printf("\n------Eslestirme basariyla tamamlandi.\n\n");
	
}

void kitapYazarGuncelle(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter)  {
	char ISBN[14];
	int yazarID;
	int nYazarID;
	int i=0,j=0;
	bool flag = false;
	printf("-----------KITAP-YAZAR GUNCELLEME ISLEM SAYFASI------------\n");
	printf("Yeniden Eslestirme istediginiz kitap ISBN numarasini giriniz:\t");
	scanf("%14s",ISBN);
	Kitap* result = findKitap(ISBN,listKitaplar);
	while(result == NULL) {
		printf("Lutfen gecerli bir ISBN numarasi giriniz:\t");
		scanf("%14s",ISBN);
		result = findKitap(ISBN,listKitaplar);
	}
	printf("Eslestirilmek istenen kitap sistemde bulundu !\n\n");
	printf("Eslestirmede degistirmek istediginiz yazarin IDsini giriniz\n");
	Yazar* resultTwo = NULL;
	while(resultTwo == NULL) {
		printf("Gecerli bir yazarIDsi giriniz[YAZAR-KITAP KAYDI OLMALIDIR]:\t");
		scanf("%d",&yazarID);
		resultTwo = findYazar(yazarID,listYazarlar);
		while(resultTwo!=NULL && j<(*kitapYazarCounter) && !flag) {
			if((!strcmp(kyArray[j].ISBN,ISBN)) && (kyArray[j].YazarID == yazarID)) {
				flag = true;
			} else {
				j++;
			}
		}
		if(!flag) {
			resultTwo = NULL;
		}
		j==0;
	}
 	printf("\nYeniden eslestirmeye tabi tutulacak yazar bulundu !\n\n");
	
	printf("Eslestirmek istediginiz yazarin ID'sini giriniz:\t");
	scanf("%d",&nYazarID);
	Yazar* resultThree = findYazar(nYazarID,listYazarlar);
	while(resultThree == NULL) {
		printf("Lutfen gecerli bir yazarID giriniz:\t");
		scanf("%d",&nYazarID);
		resultThree = findYazar(nYazarID,listYazarlar);
	}
	printf("Eslestirmek istediginiz yazar bulundu !\n\n");
	kyArray[j].YazarID = nYazarID;

}

//KITAP-ODUNC//
void teslimNone(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter) {
	printf("%d",*kitapOduncCounter);
	int kitapOdunc = (*kitapOduncCounter);
	int counter = 0;
	Ogrenci* n;
	printf("---KITAP TESLIM SISTEMI---\n\n");
	printf("Teslim Etmeyen Ogrenciler Listesi:\n");
	for(;counter<5;counter++) {
		if(koArray[counter].islemTipi == 0) {
			n = findOgrenci(koArray[counter].ogrID,listOgrenciler);
			printf("ID:%s, AD:%s, SOYAD:%s, PUAN:%d ve TESLIM EDILMEYEN KITAP:%s\n",n->ogrID,n->ad,n->soyad,n->puan,koArray[counter].EtiketNo);
		}
	}
	system("pause");
}

void oduncTeslim(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter) {
    //TIME STAMPS
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    
    timeinfo->tm_year = timeinfo->tm_year + 1900;
    timeinfo->tm_mon = timeinfo->tm_mon + 1;
    
	bool flag = false;
	bool flagOdunc = false;
	int switcher;
    char ogrID[9];
    char ISBN[14];
    char ETIKET_NO[20];
    int counter = 0,counterTwo = 0;
	printf("----- ODUNC / TESLIM SISTEMINE HOSGELDINIZ -----\n");
	printf("1)ODUNC AL\n");
	printf("2)TESLIM ET\n");
	printf("\nYapmak istediginiz islem numarasini giriniz[0 ile menuden cikis]:\t");
	scanf("%d",&switcher);	
	while(switcher>2 || switcher<0) {
		printf("Lutfen gecerli bir islem numarasi giriniz:\t");
		scanf("%d",&switcher);
	}
	
	if(switcher == 0) {
		return;
	} else if(switcher == 1) {
		system("cls");
		printf("---ODUNC ALMA SISTEMI---\n\n");
		printf("Ogrenci IDnizi giriniz:\t");
		scanf("%8s",ogrID);
		Ogrenci* n = findOgrenci(ogrID,listOgrenciler);
		while(n==NULL) {	
		   printf("Lutfen gecerli bir ogrenci IDsi giriniz:\t");
		   scanf("%8s",ogrID);
		   n = findOgrenci(ogrID,listOgrenciler);
		}
		printf("Ogrenci bulundu...\n\n");
		printf("Odunc Almak istediginiz kitabin ISBN numarasini giriniiz:\t");
		scanf("%13s",ISBN);
		Kitap* m = findKitap(ISBN,listKitaplar);
		while(m==NULL) {
			printf("Lutfen gecerli bir ISBN numarasini giriniz:\t");
		    scanf("%13s",ISBN);
		    Kitap* m = findKitap(ISBN,listKitaplar);
		}
		printf("Kitap bulundu...\n");
		KitapOrnek* l=m->head;
		for(;counter<m->adet;counter++) {
			if(!strcmp(l->Durum,"RAFTA")) {
				KitapOdunc* borrow = createKitapOduncNode(l->EtiketNo,ogrID,0,timeinfo->tm_mday,timeinfo->tm_mon,timeinfo->tm_year);
				strcpy(koArray[*kitapOduncCounter].EtiketNo,borrow->EtiketNo);
		        strcpy(koArray[*kitapOduncCounter].ogrID,borrow->ogrID);
		        koArray[*kitapOduncCounter].islemTipi = borrow->islemTipi;
		        koArray[*kitapOduncCounter].islemTarihi = borrow->islemTarihi; 
		        (*kitapOduncCounter) = (*kitapOduncCounter) + 1;
		        strcpy(l->Durum,borrow->ogrID);
		        flagOdunc = true;
		        counter=m->adet;
			} else {
				l = l->next;
			}
		}
		if(!flagOdunc) {
			printf("Bu ISBN numarali kitabin verilecek ornegi 'RAFTA' bulunmamaktadir...\n");
		} else {
	     	printf("Odunc verilen kitabin ISBN numarasi:\t%s\n",l->EtiketNo);	

		}
		system("pause");
	} else if(switcher==2) {
		system("cls");
		printf("---TESLIM ETME SISTEMI---\n\n");
		printf("Ogrenci IDnizi giriniz:\t");
		scanf("%8s",ogrID);
		Ogrenci* n = findOgrenci(ogrID,listOgrenciler);
		while(n==NULL) {	
		   printf("Lutfen gecerli bir ogrenci IDsi giriniz:\t");
		   scanf("%8s",ogrID);
		   n = findOgrenci(ogrID,listOgrenciler);
		}
		printf("Ogrenci bulundu...\n\n");
		printf("Elinizdeki kitaplarin etiket numaralari:\n");
		for(counterTwo=0;counterTwo<(*kitapOduncCounter);counterTwo++) {
			if(!strcmp(koArray[counterTwo].ogrID,ogrID) && koArray[counterTwo].islemTipi == 0) {
				printf("ETIKET_NO : %s\n",koArray[counterTwo].EtiketNo);
			}
		}
	    printf("\nIade Etmek istediginiz kitabin ISBN numarasini giriniz:\t");
		scanf("%13s",ISBN);
		Kitap* m = findKitap(ISBN,listKitaplar);
		while(m==NULL) {
			printf("Lutfen gecerli bir ISBN numarasini giriniiz:\t");
		    scanf("%13s",ISBN);
		    Kitap* m = findKitap(ISBN,listKitaplar);
		}
		printf("Kitap bulundu...\n\n");
		
		KitapOrnek* l=m->head;
		counterTwo = 0;
		int ornekCounter = 0;
		printf("\n Iade etmek istediginiz kitabin Etiket No giriniz:\t");
		scanf("%19s",ETIKET_NO);
		while(counterTwo<(*kitapOduncCounter) && !flag) {
			if(!strcmp(koArray[counterTwo].ogrID,ogrID) && !strcmp(koArray[counterTwo].EtiketNo,ETIKET_NO)) {
				if((timeinfo->tm_mday - koArray[counterTwo].islemTarihi.gun > 15) && (timeinfo->tm_mon == koArray[counterTwo].islemTarihi.ay) && (timeinfo->tm_year==koArray[counterTwo].islemTarihi.yil)) {
					n->puan = n->puan - 10;	
				} else if(((timeinfo->tm_mon - koArray[counterTwo].islemTarihi.ay >= 2) && (timeinfo->tm_year==koArray[counterTwo].islemTarihi.yil)) || ((timeinfo->tm_mon + 12 - koArray[counterTwo].islemTarihi.ay >=2) && (timeinfo->tm_year - koArray[counterTwo].islemTarihi.yil == 1))) {
					n->puan= n->puan - 10;
				} else if ((timeinfo->tm_year - koArray[counterTwo].islemTarihi.yil == 1) && (timeinfo->tm_mday+28-koArray[counterTwo].islemTarihi.gun > 15) && (timeinfo->tm_mon+12-koArray[counterTwo].islemTarihi.ay ==1)) {
					n->puan= n->puan - 10;
				} else if(((timeinfo->tm_year - koArray[counterTwo].islemTarihi.yil == 1) && (timeinfo->tm_mon+12-koArray[counterTwo].islemTarihi.ay >= 2)) || ((timeinfo->tm_year - koArray[counterTwo].islemTarihi.yil >=2))) {
					n->puan= n->puan - 10;
				}
				koArray[counterTwo].islemTipi = 1;
				koArray[counterTwo].islemTarihi.gun = timeinfo->tm_mday;
				koArray[counterTwo].islemTarihi.ay = timeinfo->tm_mon;
				koArray[counterTwo].islemTarihi.yil = timeinfo->tm_year;
				flag=true;
				for(;ornekCounter<m->adet;ornekCounter++) {
					if(!strcmp(ETIKET_NO,l->EtiketNo)) {
						strcpy(l->Durum,"RAFTA");
						ornekCounter=m->adet;
					} else {
						l=l->next;
					}
				}
			}
			else {
				counterTwo++;
			}
		}
		
		if(flag) {
			printf("\n....Kitap iade edildi....\n");
		} else {
			printf("\n!!!!!!!!!!!! Kitap yazar eslesmesi bulunmamaktadir !!!!!!!!!!!!!\n");
		}
		system("pause");
	}
}

void upToDateTeslim(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter) {
	//TIME STAMPS//
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    
    timeinfo->tm_mon = timeinfo->tm_mon + 1;
    timeinfo->tm_year = timeinfo->tm_year + 1900;
    
        ////
    int counterTwo;
    for(counterTwo=0;counterTwo<(*kitapOduncCounter);counterTwo++) {
    	if(koArray[counterTwo].islemTipi == 0) {
		   if((timeinfo->tm_mday - koArray[counterTwo].islemTarihi.gun > 15) && (timeinfo->tm_mon == koArray[counterTwo].islemTarihi.ay) && (timeinfo->tm_year==koArray[counterTwo].islemTarihi.yil)) {
					printf("ETIKET_NO:%s, OGRENCI_ID:%s, ODUNC ALMA TARIHI:%d.%d.%d\n",koArray[counterTwo].EtiketNo,koArray[counterTwo].ogrID,koArray[counterTwo].islemTarihi.gun,koArray[counterTwo].islemTarihi.ay,koArray[counterTwo].islemTarihi.yil);
				} else if(((timeinfo->tm_mon - koArray[counterTwo].islemTarihi.ay >= 2) && (timeinfo->tm_year==koArray[counterTwo].islemTarihi.yil))) {
					printf("ETIKET_NO:%s, OGRENCI_ID:%s, ODUNC ALMA TARIHI:%d.%d.%d\n",koArray[counterTwo].EtiketNo,koArray[counterTwo].ogrID,koArray[counterTwo].islemTarihi.gun,koArray[counterTwo].islemTarihi.ay,koArray[counterTwo].islemTarihi.yil);
				} else if( ((timeinfo->tm_mon + 12 - koArray[counterTwo].islemTarihi.ay >=2) && (timeinfo->tm_year - koArray[counterTwo].islemTarihi.yil == 1))) {
					printf("ETIKET_NO:%s, OGRENCI_ID:%s, ODUNC ALMA TARIHI:%d.%d.%d\n",koArray[counterTwo].EtiketNo,koArray[counterTwo].ogrID,koArray[counterTwo].islemTarihi.gun,koArray[counterTwo].islemTarihi.ay,koArray[counterTwo].islemTarihi.yil);	
				} else if ((timeinfo->tm_year - koArray[counterTwo].islemTarihi.yil == 1) && (timeinfo->tm_mday+28-koArray[counterTwo].islemTarihi.gun > 15) && (timeinfo->tm_mon+12-koArray[counterTwo].islemTarihi.ay ==1)) {
					printf("ETIKET_NO:%s, OGRENCI_ID:%s, ODUNC ALMA TARIHI:%d.%d.%d\n",koArray[counterTwo].EtiketNo,koArray[counterTwo].ogrID,koArray[counterTwo].islemTarihi.gun,koArray[counterTwo].islemTarihi.ay,koArray[counterTwo].islemTarihi.yil);
				} else if(((timeinfo->tm_year - koArray[counterTwo].islemTarihi.yil == 1) && (timeinfo->tm_mon+12-koArray[counterTwo].islemTarihi.ay >= 2))) {
					printf("ETIKET_NO:%s, OGRENCI_ID:%s, ODUNC ALMA TARIHI:%d.%d.%d\n",koArray[counterTwo].EtiketNo,koArray[counterTwo].ogrID,koArray[counterTwo].islemTarihi.gun,koArray[counterTwo].islemTarihi.ay,koArray[counterTwo].islemTarihi.yil);
				} else if ( ((timeinfo->tm_year - koArray[counterTwo].islemTarihi.yil >=2))) {
					printf("ETIKET_NO:%s, OGRENCI_ID:%s, ODUNC ALMA TARIHI:%d.%d.%d\n",koArray[counterTwo].EtiketNo,koArray[counterTwo].ogrID,koArray[counterTwo].islemTarihi.gun,koArray[counterTwo].islemTarihi.ay,koArray[counterTwo].islemTarihi.yil);
				}
		}
    	
	}
	printf("%d",timeinfo->tm_year);
}

void forbiddenStudent(KitapOdunc* koArray,KitapYazar* kyArray,ListOgrenci* listOgrenciler,ListYazar* listYazarlar,ListKitap* listKitaplar,int* yazarCounter,int* kitapYazarCounter,int* kitapOduncCounter) {
	Ogrenci* current = listOgrenciler->head;
	printf("----CEZALI OGRENCILER----\n");
	while(current!=NULL) {
		if((current->puan)<50) {
			printf("ID:%s ,AD:%s , SOYAD:%s ,PUAN:%d\n",current->ogrID,current->ad,current->soyad,current->puan);
		}
		current = current->next;
	}
	
	system("pause");
}
