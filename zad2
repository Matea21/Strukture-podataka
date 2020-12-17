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
int Brisi(student*, student*);

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

	printf("Opcije za izbor:\n");
	printf("1 -Unos elemenata na pocetak liste\n");
	printf("2- Ispis liste\n");
	printf("3 -Unos elementa na kraj liste\n");
	printf("4 -Pronadi studenta u listi po prezimenu\n");
	printf("5 -Izbrisi studenta iz liste\n");

	while (1) {
		printf("\nIzaberite zeljenu opciju \n Za ponovni ispis upisite 0\n");
		scanf("%d", &izbor);

		switch (izbor) {
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
