#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char ime[20];
	char prezime[30];
	int bodovi;
} student;

int brojiretke(char*);
void Unos(int,student*,char*);
void Ispis(int,student*,int);


int main()
{	
	int brojstudenata=0;
	int maxbrbod=0;
	student*s;
	char filename[]="studenti.txt";
	
	brojstudenata=brojiretke(filename);
	s=(student*)malloc(brojstudenata*sizeof(student));
	
	Unos(brojstudenata,s,filename);
	
	printf("Unesite maksimalan broj bodova");
	scanf("%d",&maxbrbod);
	Ispis(brojstudenata,s,maxbrbod);
	
	return 0;

}
int brojiretke(char*filename)
{
	int n;
	int br_red;
	FILE *fp=NULL;
	fp = fopen(filename, "r");
	
	if(fp==NULL)
		return -1;
	while(getc(fp)!='\n')
		continue;
	
	
	for (n = getc(fp); n != EOF; n = getc(fp)) {
		if (n == '\n')
			br_red++;
	}
	rewind(fp);

	return br_red;

}
void Unos(int br,student*stud,char*filename)
{	
	int i;
	FILE*fp=NULL;
	fp=fopen(filename,"r");
	
	if(fp==NULL)
		exit(1);
	
	for(i=0;i<br;i++){
		fscanf(fp,"%s",stud[i].ime);
		fscanf(fp,"%s",stud[i].prezime);
		fscanf(fp,"%d",&stud[i].bodovi);
	}
		
	


}
void Ispis(int brojstudenata,student*s,int maxbrbod)
{
	int i;
	printf("IME	PREZIME	BODOVI		RELATIVAN BROJ BODOVA\n");
	for(i=0;i<brojstudenata;i++)
	{
		double relbrbod=(double)s[i].bodovi/maxbrbod*100;
		printf("%s\t%s\t%d\t\t%lf\n",s[i].ime,s[i].prezime,s[i].bodovi,relbrbod);
		
	}

}
