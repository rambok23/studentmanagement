#include<stdio.h>
#include<conio.h>
#define ff fflush(stdin)

FILE *fp;
struct data
{
	char username[10];
	char password[10];
}a;

void write()
{
	fp=fopen("d.txt","w");
	printf("Enter the username::");
	ff;
	gets(a.username);
	printf("Enter the Password::");
	ff;
	gets(a.password);

	fwrite(&a,sizeof(a),1,fp);

	printf("\nSucessfully");
	fclose(fp);
}
void read()
{
	fp=fopen("d.txt","r");
	fread(&a,sizeof(a),1,fp);
	while(!feof(fp))
	{
		puts(a.username);
		printf("\n");
		puts(a.password);
		fread(&a,sizeof(a),1,fp);
	}
	fclose(fp);
}
void main()
{
	clrscr();
	write();
	read();
	getch();
}