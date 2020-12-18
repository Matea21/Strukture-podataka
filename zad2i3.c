#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>
#define MAX 200

typedef struct _student {
	char ime[MAX];
	char prezime[MAX];
	int godina;
	struct _student* next;
} student;

int Menu(student*);
int UnosNaPocetak(student*);
int Ispis(student*);
int UnosNaKraj(student*);
student* TraziPrezime(student*, char*);
student* TraziPrethodnog(student*, student*);
student* TraziZadnji(student*);
int Brisi(student*, student*);
int UnosIza(student*, student*);
int UnosIspred(student*, student*);
int Sortiraj(student*);
int PisiUDat(student*);
int CitajIzDat(student*);

int main()
{
	student* head;
	head = (student*)malloc(sizeof(student));
	head->next = NULL;
	int status = 0;

	do {
		status = Menu(head);
	} while (!status);

	return 0;
}

int Menu(student* head)
{
	int izbor = 0;

	char prezime[MAX];
	student* nadi_prezime = NULL;
	nadi_prezime = (student*)malloc(sizeof(student));

	char brisi[MAX];
	student* brisiel = NULL;
	brisiel = (student*)malloc(sizeof(student));

	char noviel[MAX];
	student* unesi_iza = NULL;
	unesi_iza = (student*)malloc(sizeof(student));

	char dodajispred[MAX];
	student* unesi_ispred = NULL;
	unesi_ispred= (student*)malloc(sizeof(student));


	printf("Opcije za izbor:\n");
	printf("1 -Unos elemenata na pocetak liste\n");
	printf("2- Ispis liste\n");
	printf("3 -Unos elementa na kraj liste\n");
	printf("4 -Pronadi studenta u listi po prezimenu\n");
	printf("5 -Izbrisi studenta iz liste\n");
	printf("6 -Dodaj novi element iza odredenog elementa\n");
	printf("7 -Dodaj novi element ispred određenog\n");
	printf("8 -Sortiraj listu po prezimenu\n");
	printf("9 -Upisi listu u datoteku \n");
	printf("10 -Citaj listu iz dtoteke\n");
	printf("11 -Iskljuci program\n");

	while (1) {
		printf("\nIzaberite zeljenu opciju \n Za ponovni ispis upisite 0\n");
		scanf("%d", &izbor);

		switch (izbor) {
		case(0):
			return 0;
		case(1):UnosNaPocetak(head);
			break;
		case(2):Ispis(head);
			break;
		case(3):UnosNaKraj(head);
			break;
		case(4):
			printf("Unesite prezime koje zelite pronaci:");
			scanf("%s", prezime);
			nadi_prezime = TraziPrezime(head, prezime);
			printf("Pretrazili ste:\n Ime:%s \n Prezime:%s\n Godina:%d\n", nadi_prezime->ime, nadi_prezime->prezime, nadi_prezime->godina);
			break;
		case(5):
			printf("Unesite prezime studenta koje zelite obrisati");
			scanf("%s", brisi);
			brisiel = TraziPrezime(head, brisi);
			Brisi(head, brisiel);
			break;
		case(6):
			printf("Unesite element iza kojeg zelite dodati novi elemet");
			scanf("%s", noviel);
			unesi_iza = TraziPrezime(head, noviel);
			UnosIza(head, unesi_iza);
		case(7):
			printf("Unesite element ispred kojeg zelite dodati novi element");
			scanf("%s", dodajispred);
			unesi_ispred = TraziPrezime(head, dodajispred);
			UnosIspred(head, unesi_ispred);
		case(8):
			Sortiraj(head);
			break;
		case(9):
			PisiUDat(head);
			break;
		case(10):
			CitajIzDat(head);
			break;
		case(11):
			return -1;
		default:printf("\nKrivi unos!Pokusajte ponovo.");
		}
	}
}
int UnosNaPocetak(student* head)
{
	student* s;
	s = (student*)malloc(sizeof(student));

	s->next = head->next;
	head->next = s;

	printf("Unesite ime:");
	scanf("%s", s->ime);
	printf("Unesite prezime:");
	scanf("%s", s->prezime);
	printf("Unesite godinu:");
	scanf("%d", &s->godina);

	return 0;
}
int Ispis(student* head)
{
	student* s = head->next;

	printf("	ISPIS LISTE			\n");
	while (s != NULL) {
		printf("Ime:%s \n Prezime:%s \n Godina:%d \n", s->ime, s->prezime, s->godina);
		s = s->next;
	}

	return 0;
}
int UnosNaKraj(student* head)
{
	student* s;
	s = (student*)malloc(sizeof(student));

	while (head->next != NULL)
		head = head->next;

	s->next = head->next;
	head->next = s;

	printf("Unesite ime:");
	scanf("%s", s->ime);
	printf("Unesite prezime:");
	scanf("%s", s->prezime);
	printf("Unesite godinu");
	scanf("%d", &s->godina);

	return 0;
}
student* TraziPrezime(student* head, char* prezime)
{
	student* s = head->next;
	while (s != NULL && strcmp(s->prezime, prezime))
		s = s->next;

	return s;
}
student* TraziPrethodnog(student* head, student* el)
{
	student* p = head;

	while (p != NULL && p->next != el)
		p = p->next;

	return p;
}
student* TraziZadnji(student* head)
{
	student* s = head;
	while (s != NULL && s->next != NULL)
		s = s->next;

	return s;
}
int Brisi(student* head, student* el)
{
	student* s;
	student* p;

	s = (student*)malloc(sizeof(student));
	p= (student*)malloc(sizeof(student));

	s = TraziPrethodnog(head, el);
	s->next = p->next;
	free(p);

	return 0;
}
int UnosIza(student* head, student* el)
{
	student* s;
	s = (student*)malloc(sizeof(student));

	printf("Unesite ime:");
	scanf("%s", s->ime);
	printf("Unesite prezime:");
	scanf("%s", s->prezime);
	printf("Unesite godinu");
	scanf("%d", &s->godina);

	s->next = el->next;
	el->next = s;

	return 0;
}
int UnosIspred(student* head, student* el)
{
	student* s;
	student* p;
	s = (student*)malloc(sizeof(student));
	p = (student*)malloc(sizeof(student));

	p = TraziPrethodnog(head, el);

	p->next = s;
	s->next = el;

	printf("Unesite ime:");
	scanf("%s", s->ime);
	printf("Unesite prezime:");
	scanf("%s", s->prezime);
	printf("Unesite godinu");
	scanf("%d", &s->godina);

	return 0;

}
int Sortiraj(student* head)
{
	student* s = head;
	student* p = NULL;
	student* pret = NULL;
	student* poslj = NULL;

	while (s->next != poslj)
	{
		pret = s;
		p = pret->next;

		while (p->next != poslj)
		{
			if (strcmp(p->prezime, q->next->prezime) > 0)
			{
				pret->next = p->next;
				p->next = p->next->next;
				pret->next->next = p;
				p = pret->next;

			}
			pret = p;
			p = p->next;
		}
		poslj = p;
	}
	return 0;
}
int PisiUDat(student* head)
{
	student* s = NULL;
	s = (student*)malloc(sizeof(student));
	s = head->next;

	FILE* fp = NULL;
	fp = fopen("studenti.txt", "w");

	if (fp == NULL) {
		printf("Greska!\n");
		return -1;
	}
	while (s != NULL) {
		fprintf(fp, "Ime:%s \n Prezime:%s \n Godina:%d \n ", s->ime, s->prezime, s->godina);
		s = s->next;
	}

	fclose(fp);
}
int CitajIzDat(student* head)
{
	student* s;
	student* p = TraziZadnji(head);

	FILE* fp = NULL;
	fp = fopen("citaj.txt", "r");

	int znak = 0;
	int broj = 0;
	int i = 0;
	char buffer[MAX] = { 0 };

	if (fp == NULL) {
		printf("Greska u otvaranju datoteke!\n");
		return -1;
	}
	while (fgets(buffer, MAX, fp))
		broj++;

	rewind(fp);

	for (i = 0; i < broj; i++) {
		s = (student*)malloc(sizeof(student));

		s->next = NULL;
		p->next = s;
		p = p -> next;

		fscanf(fp, "%s %s %d", s->ime, s->prezime, &s->godina);
	}

	fclose(fp);

	return 0;
}
