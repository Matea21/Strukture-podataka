#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

/*. Definirati strukturu osoba (ime, prezime, godina ro?enja) i napisati program koji:
a) dinami?ki dodaje novi element na po?etak liste,
b) ispisuje listu,
c) dinami?ki dodaje novi element na kraj liste,
d) pronalazi element u listi (po prezimenu),
e) briše odre?eni element iz liste,
U zadatku se ne smiju koristiti globalne varijable.*/

struct _covjek;
typedef struct _covjek*Pozicija;
typedef struct _covjek {
	char ime[MAX];
	char prezime[MAX];
	int godinaRodenja;
	Pozicija *next;
} Covjek;

Covjek *Unos(void);
int UnosPocetak(Covjek *El, Covjek *Head);
int IspisListe(Covjek *Head);
int UnosKraj(Covjek *El, Covjek *Head);
Covjek *TraziZadnj(Covjek *Head);
Covjek*TraziPrezime(Covjek*Head, char*prezime);
Covjek*TraziPrethodni(Covjek*, Covjek*);
int BrisiElement(Covjek *El, Covjek *Head);
int DodajIzaElementa(Covjek* Head, Covjek* El);
int DodajIspredElementa(Covjek*Head, Covjek*El);
int SortitajPoPrezimenu(Covjek*Head);
int UpisiUDat(Covjek*Head);
int CitajIzDat(Covjek*Head);


int main(void)
{
	Covjek*Head;
	Head = (Covjek*)malloc(sizeof(Covjek));
	if (!Head)
		return -1;
	Head->next = NULL;

	int stanje = 0;
	do {
		int opcija = 0;
		Covjek *El = NULL;
		char prezime[MAX] ;
		char brisi[MAX];
		char iza[MAX];
		char ispred[MAX];
		Covjek*nadiprezime = NULL;
		Covjek*obrisielement = NULL;
		Covjek*dodajiza = NULL;
		Covjek*dodajispred = NULL;
		nadiprezime = (Covjek*)malloc(sizeof(Covjek));
		obrisielement = (Covjek*)malloc(sizeof(Covjek));
		dodajiza = (Covjek*)malloc(sizeof(Covjek));
		dodajispred = (Covjek*)malloc(sizeof(Covjek));

		printf("Odaberite opciju:\n");
		printf("1.Dodati novi element na pocetak liste\n");
		printf("2.Ispisati listu\n");
		printf("3.Dodati novi element na kraj liste\n");
		printf("4.Pronaci element u listi(po prezimenu)\n");
		printf("5.Brisati odredeni element\n");
		printf("6.Dodaj element iza\n");
		printf("7.Dodaj element ispred\n");
		printf("8.Sortiraj po prezimenu\n");
		printf("9.Citaj iz datoteke\n");
		printf("10.Upisi u datoteku\n");
		printf("0. ZATVORI PROGRAM\n");
		scanf("%d", &opcija);

		switch (opcija)
		{
		case(1):
			UnosPocetak(Unos(), Head);
			break;
		case(2):
			IspisListe(Head);
			break;
		case(3):
			UnosKraj(Unos(), Head);
			break;
		case(4):
			printf("Koje prezime zelite pronaci?\t");
			scanf("%s", prezime);
			nadiprezime = TraziPrezime(Head, prezime);
			printf("\nElement koji ste pretrazili:\nIme: %s\nPrezime: %s\nGodina rodenja: %d\n", nadiprezime->ime, nadiprezime->prezime, nadiprezime->godinaRodenja);
			break;
		case(5):
			printf("Koje prezime zelite obrisati?\t");
			scanf("%s", brisi);
			obrisielement = TraziPrezime(Head, brisi);
			BrisiElement(Head, obrisielement);
			break;
		case(6):
			printf("Iza kojeg elementa zelite dodati drugi element?");
			scanf("%s", iza);
			dodajiza = TraziPrezime(Head, iza);
			DodajIzaElementa(Head, dodajiza);
			break;
		case(7):
			printf("Ispred kojeg elementa zelite dodati drugi element?");
			scanf("%s", ispred);
			dodajispred = TraziPrezime(Head, ispred);
			DodajIzaElementa(Head, dodajispred);
			break;
		case(8):SortitajPoPrezimenu(Head);
			break;
		case(9):CitajIzDat(Head);
			break;
		case(10):UpisiUDat(Head);
			break;

		case(0):
			return 1;
		}
	} while (!stanje);

	return 0;
}
Covjek *Unos(void)
{
	Covjek *C = (Covjek*)malloc(sizeof(Covjek));
	printf("Unesite ime,prezime i godinu rodenja:\n");
	scanf("%s %s %d", C->ime, C->prezime, C->godinaRodenja);

	return C;
}
int UnosPocetak(Covjek *El, Covjek *Head)
{
	El->next = Head->next;
	Head->next = El;

	return 0;
}
int IspisListe(Covjek*Head)
{
	Covjek *C = Head->next;
	while (C != NULL) {
		printf("%s %s %d", C->ime, C->prezime, C->godinaRodenja);
		C = C->next;
	}
}
int UnosKraj(Covjek *El, Covjek *Head)
{
	Covjek *P = Head;
	while (P != NULL)
		P = P->next;

	El->next = NULL;
	P->next = El;

	return 0;
}
Covjek *TraziZadnj(Covjek *Head)
{
	Covjek *P = Head;

	while (P != NULL && P->next != NULL)
		P = P->next;
	
	return P;
}
Covjek *TraziPrezime(char *prezime, Covjek *Head)
{
	Covjek *P = Head->next;

	while (P != NULL && strcmp(P->prezime, prezime))
		P = P->next;

	return P;
}
Covjek*TraziPrethodni(Covjek*Head, Covjek*El) {

	Covjek* P;
	P = Head;

	while (P != NULL && P->next != El)
		P = P->next;

	return P;

}
int BrisiElement(Covjek *El, Covjek *Head)
{
	Covjek *P = NULL;
	Covjek *q = NULL;
	P = (Covjek*)malloc(sizeof(Covjek));
	q = (Covjek*)malloc(sizeof(Covjek));
	q = El;

	P = TraziPrethodni(Head, El);
	P->next = q->next;

	free(q);

	return 0;
}
int DodajIzaElementa(Covjek* Head, Covjek* El)
{
	Covjek*sljedeci;
	sljedeci = (Covjek*)malloc(sizeof(Covjek));

	printf("Ime:");
	scanf("%s", sljedeci->ime);
	printf("Prezime:");
	scanf("%s", sljedeci->prezime);
	printf("Godina rodjenja:");
	scanf("%d", &sljedeci->godinaRodenja);
	printf("\n");

	sljedeci->next = El->next;
	El->next = sljedeci;

	return 0;

}
int DodajIspredElementa(Covjek*Head, Covjek*El)
{
	Covjek*sljedeci;
	sljedeci = (Covjek*)malloc(sizeof(Covjek));
	Covjek*P = NULL;
	P = (Covjek*)malloc(sizeof(Covjek));

	P = TraziPrethodni(Head, El);
	P->next = sljedeci;
	sljedeci->next = El;

	printf("Ime:");
	scanf("%s", sljedeci->ime);
	printf("Prezime:");
	scanf("%s", sljedeci->prezime);
	printf("Godina rodenja:");
	scanf("%d", &sljedeci->godinaRodenja);
	printf("\n");

	return 0;
}
int SortitajPoPrezimenu(Covjek*Head)
{
	Covjek *p = Head;
	Covjek *q = NULL;

	Covjek *prvi = NULL;
	Covjek *zadnji = NULL;

	while (p->next != zadnji)
	{
		prvi = p;
		q = prvi->next;

		while (q->next != zadnji)
		{
			if (strcmp(q->prezime, q->next->prezime) > 0)
			{
				prvi->next = q->next;
				q->next = q->next->next;
				prvi->next->next = q;
				q = prvi->next;
			}
			prvi = q;
			q = q->next;
		}
		zadnji = q;
	}
	return 0;

}
int CitajIzDat(Covjek*Head)
{
	Covjek *q;
	Covjek *p = TraziZadnji(Head);

	FILE*fp = NULL;
	fp= fopen("raspored.txt", "r");

	int znak = 0;
	int broj = 0;
	int i = 0;
	char buffer[MAX] = { 0 };

	if (fp == NULL) {
		printf("Greska u otvaranju datoteke!\n");
		return -1;
	}
	while (fgets(buffer, MAX, fp)) {
		broj++;
	}

	rewind(fp);

	for (i = 0; i < broj; i++) {
		q = (Covjek*)malloc(sizeof(Covjek));

		q->next = NULL;
		p->next = q;
		p = p->next;

		fscanf(fp, "%s %s %d", q->ime, q->prezime, &q->godinaRodenja);
	}
	fclose(fp);

	return 0;
}
int PisiuDat(Covjek *Head)
{
	Covjek* q = NULL;
	q = (Covjek*)malloc(sizeof(Covjek));
	q = Head->next;

	FILE* fp = NULL;
	fp = fopen("pisi.txt", "w");

	if (fp == NULL) {
		printf("Greska u otvaranju datoteke!\n");
		return -1;
	}

	while (q != NULL) {
		fprintf(fp, "Ime: %s \tPrezime: %s \tGodina: %d\n", q->ime, q->prezime, q->godinaRodenja);
		q = q->next;
	}

	fclose(fp);

	return 0;
}
