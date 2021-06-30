/*							This is student Record System Project.

			Description:
							In this Project,We have mainly 6 Functions
							
							1.Add Record
							2.Display Record
							3.Update Record
							4.Delete Record
							5.Include Student Marksheet
							
			NOTE:			All Information is Stored in File.
*/

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#define p printf
#define s scanf
#define c cprintf
#define ff fflush(stdin);

FILE *fptr;
FILE *fp,*fp1;

struct student
{
	char Fname[23],Lname[23],Div[10],Dob[23],Cno[10],Sid[10];
	int Sem;

}st;
struct new
{
	int seme;
	char firstn[23],laname[23],divi[10],dofb[23],cono[10],stu_id[10];
	struct new *next;
}*ptr,*ptr1,*start;

struct Marks
{
	int Sid,sooadm,java,wdt,bs,sem1;
	char name[20],status[5];
	float total;
	float per,avg;
	char grade;
}*add;


struct login
{
	char username[10];
	char password[10];
}l;

void login()
{
	char username[25];
	char password[25];
	int check=0,i;
	clrscr();

	do{
		p("\n\t\t\tLOGIN\t\t\n\n");
		p("Enter User Name: ");
		gets(username);


		p("\nEnter Password: ");
//		gets(password);

		for(i=0;i<5;i++)
  {
   password[i]=getch();
   printf("*");
  }
  password[i]='\0';

		check=0;

		fp1=fopen("d.txt","r+");
			fread(&l,sizeof(l),1,fp1);

		while(!feof(fp1))
		{
			if(strcmp(username,l.username)==0)
			{
				if(strcmp(password,l.password)==0)
				{

					check=1;
					break;
				}

			}

				fread(&l,sizeof(l),1,fp1);
		}

		fclose(fp1);
		if(check==0)
		{
			check=0;
			p("Invalid Username or Password\n");
		}

	}while(check==0);
	getch();
}

void border()
{
	int row=24,col=79;
	int i,j;
	clrscr();
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(i==0 || i==row-1 || j==0 || j==col-1)
			{
				textcolor(BLUE);
				cprintf("*");
			}
			else
				printf(" ");
		}
		printf("\n");
	}
	getch();
}


void input()
{
	int flag=0,var,i,length,fail;
	char ch;
	float extra;
	clrscr();
	fp=fopen("stud.dat","ab");

	do{
			do
			{

				fail=0;
				p("\nFirst Name : ");
				s("%s",st.Fname);
				length=strlen(&st.Fname);

					for (i=0;i<length;i++)
					{
					if(!isalpha(st.Fname[i]))
					{
						p("Entered Name is invalid!!\n");
						fail = 1;
						break;
					}
				}

			}while(fail);


			do
			{
				fail=0;
				p("\nLast Name : ");
				s("%s",st.Lname);
				length=strlen(&st.Lname);

					for (i=0;i<length;i++)
					{
					if(!isalpha(st.Lname[i]))
					{
						p("Entered Name is invalid!!\n");
						fail = 1;
						break;
					}
				}

			}while(fail);


			do
			{
				fail=0;
				p("\nDivision : ");
				ff
				s("%s",st.Div);
				length=strlen(&st.Div);

				if(length == 3)
				{
					for (i=0;i<3;i++)
					if(!isalpha(st.Div[i]))
					{
						p("Entered Division is not valid!!\n");
						fail = 1;
						break;
					}
				}
				
				else
				{
					p("Enter Division in Alphabets !!\n");
					fail=1;
				}
			
			}while(fail);

			p("\nEnter DOB  [DD/MM/YYYY] : ");
			ff
			s("%s",&st.Dob);




			/*p("\nEnter Contact No: ");
			ff
			s("%s",&st.Cno);*/

			do
			{
				fail=0;
				p("\nContact No : ");
				ff
				s("%s",st.Cno);
				length=strlen(st.Cno);

				if(length == 10)
				{
					for (i=0;i<length;i++)
					if (!isdigit(st.Cno[i]))
					{
						p("Entered mobile number  is not valid!!\n");
						fail = 1;
						break;
					}
				}

				else
				{
					p("Enter 10 digit mobile number!!\n");
					fail=1;
				}
			}while(fail);

			p("\nEnter Student Id : ");
			ff
			s("%s",&st.Sid);


			p("\nEnter Semester : ");
			ff
			s("%d",&st.Sem);

			if(flag==0)
			{
				p("\n\n\t\tAdded Successfully ");
			}

			else
			{
				p("\n\n\t\tNot Added ");
			}
			//ptr->next=NULL;
			flag=fwrite(&st,sizeof(st),1,fp);

			p("\n\n\tDo you want to continue ?: ");
			ff
			ch=getche();
			clrscr();



	}while(ch!='n');


	fclose(fp);
}

void display()
{
	clrscr();
	fp=fopen("stud.dat","rb");
	ptr=(struct new *)malloc(sizeof(struct new));
	start=ptr;
	ptr->next=NULL;

	if(fp != NULL)
	{

		fread(&st,sizeof(st),1,fp);
	       while(!feof(fp))
			{
				strcpy(ptr->firstn,st.Fname);
				strcpy(ptr->laname,st.Lname);
				strcpy(ptr->divi,st.Div);
				strcpy(ptr->dofb,st.Dob);
				strcpy(ptr->cono,st.Cno);
				strcpy(ptr->stu_id,st.Sid);
				ptr->seme=st.Sem;

				fread(&st,sizeof(st),1,fp);
				if(!feof(fp))
				{
					ptr1=(struct new *)malloc(sizeof(struct new));
					ptr1->next=NULL;
					ptr->next=ptr1;
					ptr=ptr1;
				}

			}

			ptr->next=NULL;
			ptr=start;
	
			p("\t\t\t===================================");
			p("\n\t\t\t\tStudent's Records:-");
			p("\n\t\t\t===================================");
			p("\n\nFirst Name   Last Name   Division    DOB     Contact no  Student ID     Semester\n");

			while(ptr != NULL)
			{
				p("\n%s\t\t",ptr->firstn);
				p("%s\t",ptr->laname);
				p("%s\t",ptr->divi);
				p("%s\t",ptr->dofb);
				p("%s\t",ptr->cono);
				p("%s\t",ptr->stu_id);
				p("%d\t",ptr->seme);
				p("\n");
				ptr=ptr->next;
			}
	}
	
	else
	{

		p("\nFile is Empty!!! ");
	}

	fclose(fp);
	getch();
}

void Delete()
{
	int found=0;
	char search[10];
	FILE *fp1;
	clrscr();

	fp=fopen("stud.dat","rb");
	fp1=fopen("temp.dat","ab");
	
	p("\nEnter Student Id u want to Delete: ");
	ff;
	s("%s",search);
	
	fread(&st,sizeof(st),1,fp) ;

	while(!feof(fp))
	{
		if (strcmp(search,st.Sid)!=0)
		{
			fwrite(&st,sizeof(st),1,fp1);
		}

		else
		{
			found=1;
		}
		fread(&st,sizeof(st),1,fp);
	}
	fclose(fp1);
	remove("stud.dat");
	rename("temp.dat","stud.dat");

	if(found==0)
	{
		p("\n%s Not Found :(",search);
	}

	else
	{
		p("\nRecord Deleted Successfully :) ");
	}
	getch();
}

void update()
{
	int records=0;
	int che;
	char id[10];
	clrscr();

	fp=fopen("stud.dat","rb+");

	p("Enter Student Id to Modify: ");
	s("%s",id);
	while(fread(&st,sizeof(st),1,fp)==1)
	{
		if(strcmp(id,st.Sid)==0)
		{
			gotoxy(2,3);
			p("1)Update First Name");
			gotoxy(2,5);
			p("2)Update Last Name");
			gotoxy(2,7);
			p("3)Update Div");
			gotoxy(2,9);
			p("4)Update DOB");
			gotoxy(2,11);
			p("5)Update Contact No");
			gotoxy(2,13);
			p("6)Update Sem");
			gotoxy(2,15);
			p("7)Exit");
			gotoxy(2,18);
			p("\nEnter Your Choice:- ");
			s("%d",&che);
			switch(che)
			{
				case 1:
				p("\n\tEnter New First Name::");
				ff
				s("%s",&st.Fname);
				break;

				case 2:
				p("\n\tEnter New Last Name::");
				ff
				s("%s",&st.Lname);
				break;

				case 3:
				p("\n\tEnter New Division::");
				ff
				s("%s",&st.Div);
				break;

				case 4:
				p("\n\tEnter New DOB::");
				ff
				s("%s",&st.Dob);
				break;

				case 5:
				p("\n\tEnter New Contact No::");
				ff
				s("%s",&st.Cno);
				break;

				case 6:
				p("\n\tEnter New Semester::");
				ff
				s("%d	",&st.Sem);
				break;

				case 7:
					break;

				default:
					p("Invalid Selection....!!!");
			}


			fseek(fp,sizeof(struct student)*records,SEEK_SET);//This is key line..

			if(fwrite(&st,sizeof(st),1,fp))
			{
				p("Record Modified Successfully :)");
			}

			else
			{
				p("Not Modified :(");
			}
		}
	records++; // in the while loop...
    }
    fclose(fp);
}

void search()
{
		char ide;
		clrscr();
		p("Enter Sid::");
		s("%s",&ide);
		fp=fopen("stud.dat","rb");
		fread(&st,sizeof(st),1,fp);

		while(!feof(fp))
		{
			if(strcmp(ide,st.Sid))
			{
				p("\n\nStudent ID is Found");
				p("\n");
				p("\nSid : %s",st.Sid);
				p("\n\nFirst Name : %s ",st.Fname);

				p("\n\nLast Name : %s",st.Lname);

				p("\n\nDiv : %s",st.Div);

				p("\n\nDOB : %s",st.Dob);

				p("\n\nContact No : %s",st.Cno);

				p("\n\nSemester : %d",st.Sem);
			}
			fread(&st,sizeof(st),1,fp);
		}
		fclose(fp);
		getch();
}

void print()
{
	clrscr();
	border();

	gotoxy(3,1);
	textcolor(LIGHTBLUE);
	//cp("=============================================================================");
	gotoxy(22,2);
	textcolor(LIGHTCYAN);
	c("L.J Institute of Computer Applicatios");
	gotoxy(16,3);
	textcolor(LIGHTCYAN);
	c("LJ CAMPUS,BETWEEN SARKHEJ CIRCLE & KATARIA MOTORS");
	gotoxy(26,4);
	textcolor(LIGHTCYAN);
	c("S.G.ROAD,AHMEDABAD-382210");


	gotoxy(3,5);
	textcolor(BLUE);
	//cp("============================================================================");
	 c("*****************************************************************************");
	gotoxy(22,6);

	textcolor(LIGHTCYAN);
	c("---- Student Record System ----");

	gotoxy(22,7);
	textcolor(LIGHTBLUE);
	c("-------------------------------");


	gotoxy(5,9);

	textcolor(BROWN);
	c("1. Add Student Record");
	gotoxy(5,11);

	textcolor(BROWN);
	c("2. Display Student Record");
	gotoxy(5,13);

	textcolor(BROWN);
	c("3. Modify Student Record");
	gotoxy(5,15);

	textcolor(BROWN);
	c("4. Delete Student Record");
	gotoxy(5,17);

	textcolor(BROWN);
	c("5. Generate & View Student Marksheet");
	gotoxy(5,19);

	textcolor(BROWN);
	c("6. Search Record By Sid");
	gotoxy(5,21);

	c("7. Exit");

	gotoxy(5,23);

	textcolor(LIGHTMAGENTA);
	c("Enter Your Choice: ");

}

void print1(){
	clrscr();
	p("\n\n1.MID EXAMINATION");
	p("\n\n2.ODI EXAMINATION");
	p("\n\n3.PRACTICAL EXAMINATION");
	p("\n\n4.View MID Marksheet");
	p("\n\n5.View ODI Marksheet");
	p("\n\n6.View PRACTICAL Marksheet");
	p("\n\n7.Exit");
	p("\n\n\nEnter Your Choice::");
}

void Practical()
{
	char id[10];
	clrscr();
	fptr=fopen("practical.txt","a");
	if(fptr==NULL) {
		printf("Error!");
		exit(1);
	}

	p("Enter The Student ID: ");
	s("%d",&add->Sid);

	p("\nEnter Name: ");
	s("%s",add->name);

	p("\nEnter Semester: ");
	s("%d",&add->sem1);

	p("\nEnter Marks Of Sooadm::");
	s("%d",&add->sooadm);

	p("\nEnter Marks Of Java::");
	s("%d",&add->java);

	p("\nEnter Marks Of WDT::");
	s("%d",&add->wdt);

	p("\nEnter Marks Of BS::");
	s("%d",&add->bs);

	p("\n\n\t\tStudent Marksheet Created!!!");



	add->total=add->sooadm+add->java+add->wdt+add->bs;
	if(add->total>60 && add->total<=80)
		add->grade='A';
	else if(add->total>40 && add->total<=60)
		add->grade='B';
	else if(add->total>=20 && add->total<=40)
		add->grade='C';
	else
		add->grade='F';



	fprintf(fptr,"\n=============================================================================");

	fprintf(fptr,"\n\t\tL.J Institute of Computer Applicatios");

	fprintf(fptr,"\n\t\tLJ CAMPUS,BETWEEN SARKHEJ CIRCLE & KATARIA MOTORS");

	fprintf(fptr,"\n\t\tS.G.ROAD,AHMEDABAD-382210");

	fprintf(fptr,"\n=============================================================================");

	fprintf(fptr,"\n\n\t\tRoll No: %d \t  Name : %s\t  Sem:%d\n",add->Sid,add->name,add->sem1);
	fprintf(fptr,"\t\t-----------------------------------------------------\n");
	fprintf(fptr,"\t\tSubject             Max      Min            Obt.Marks\n");
	fprintf(fptr,"\t\t-----------------------------------------------------\n");
	fprintf(fptr,"\t\tsooadm              20       8              %d\n",add->sooadm);
	fprintf(fptr,"\t\tjava                20       8              %d\n",add->java);
	fprintf(fptr,"\t\twdt                 20       8              %d\n",add->wdt);
	fprintf(fptr,"\t\tbs                  20       8              %d\n",add->bs);
	fprintf(fptr,"\t\t-----------------------------------------------------\n");
	fprintf(fptr,"\t\tGrade:%c			     Total:%2.f\n",add->grade,add->total);

	fprintf(fptr,"\t\t-----------------------------------------------------\n");
	if(add->grade=='F')
	{

		fprintf(fptr,"\n\n\t\tSorry!!! You Have Fail in This Exam.",add->grade);
	}
	else{
		fprintf(fptr,"\n\n\t\tCongratulations!!! You Have Passed This Exam.",add->grade);
	}
	fclose(fptr);

}
void practicaldisplay()
{

	int temp;
	clrscr();

	fptr=fopen("practical.txt","r");

	p("Enter Sid to Find a Marksheet :");
	s("%d",&temp);

	if(strcmp(temp,add->Sid)==0)
	{
	

	gotoxy(3,1);
	p("=============================================================================");
	gotoxy(22,2);
	p("L.J Institute of Computer Applicatios");
	gotoxy(16,3);
	p("LJ CAMPUS,BETWEEN SARKHEJ CIRCLE & KATARIA MOTORS");
	gotoxy(26,4);
	p("S.G.ROAD,AHMEDABAD-382210");
	gotoxy(3,5);
	p("=============================================================================");


	gotoxy(22,6);

	printf("\n\n\t\tRoll No: %d \t  Name : %s\t  Sem:%d\n",add->Sid,add->name,add->sem1);
	printf("\t\t-----------------------------------------------------\n");
	printf("\t\tSubject             Max      Min            Obt.Marks\n");
	printf("\t\t-----------------------------------------------------\n");
	printf("\t\tsooadm              20       8              %d\n",add->sooadm);
	printf("\t\tjava                20       8              %d\n",add->java);
	printf("\t\twdt                 20       8              %d\n",add->wdt);
	printf("\t\tbs                  20       8              %d\n",add->bs);
	printf("\t\t-----------------------------------------------------\n");
	printf("\t\tGrade: %c			     Total: %2.f\n",add->grade,add->total);

	printf("\t\t-----------------------------------------------------\n");
	if(add->grade=='F')
	{

		p("\n\n\t\tSorry!!! You Have Fail in This Exam.");
	}
	else{
		p("\n\n\t\tCongratulations!!! You Have Passed This Exam.");
	}

	}
}

void ODE()
{
	clrscr();
	fptr=fopen("ode.txt","a");
	if(fptr==NULL) {
		printf("Error!");
		exit(1);
	}

	p("Enter The Student ID: ");
	s("%d",&add->Sid);

	p("\nEnter Name: ");
	s("%s",add->name);

	p("\nEnter Semester: ");
	s("%d",&add->sem1);

	p("\nEnter Marks Of Sooadm::");
	s("%d",&add->sooadm);

	p("\nEnter Marks Of Java::");
	s("%d",&add->java);

	p("\nEnter Marks Of WDT::");
	s("%d",&add->wdt);

	p("\nEnter Marks Of BS::");
	s("%d",&add->bs);

	p("\n\n\t\tStudent Marksheet Created!!!");

	add->total=add->sooadm+add->java+add->wdt+add->bs;
	add->avg=(add->sooadm+add->java+add->wdt+add->bs)/4.0;
	if(add->avg>=24)
		add->grade='A';
	else if(add->avg>=18 && add->avg<24)
		add->grade='B';
	else if(add->avg>=12 && add->avg<18)
		add->grade='C';
	else
		add->grade='F';



	fprintf(fptr,"\n=============================================================================");

	fprintf(fptr,"\n\t\tL.J Institute of Computer Applicatios");

	fprintf(fptr,"\n\t\tLJ CAMPUS,BETWEEN SARKHEJ CIRCLE & KATARIA MOTORS");

	fprintf(fptr,"\n\t\tS.G.ROAD,AHMEDABAD-382210");

	fprintf(fptr,"\n=============================================================================");

	fprintf(fptr,"\n\n\t\tRoll No: %d \t  Name : %s\t  Sem:%d\n",add->Sid,add->name,add->sem1);
	fprintf(fptr,"\t\t-----------------------------------------------------\n");
	fprintf(fptr,"\t\tSubject             Max      Min            Obt.Marks\n");
	fprintf(fptr,"\t\t-----------------------------------------------------\n");
	fprintf(fptr,"\t\tsooadm              28       12              %d\n",add->sooadm);
	fprintf(fptr,"\t\tjava                28       12              %d\n",add->java);
	fprintf(fptr,"\t\twdt                 28       12              %d\n",add->wdt);
	fprintf(fptr,"\t\tbs                  28       12              %d\n",add->bs);
	fprintf(fptr,"\t\t-----------------------------------------------------\n");
	fprintf(fptr,"\t\tGrade:%c			     Total:%2.f\n",add->grade,add->total);

	fprintf(fptr,"\t\t-----------------------------------------------------\n");
	if(add->grade=='F')
	{

		fprintf(fptr,"\n\n\t\tSorry!!! You Have Fail in This Exam.",add->grade);
	}
	else{
		fprintf(fptr,"\n\n\t\tCongratulations!!! You Have Passed This Exam.",add->grade);
	}
	fclose(fptr);

	getch();
}
void odedisplay()
{
	int temp;
	clrscr();

	fptr=fopen("ode.txt","r");

	p("Enter Sid to Find a Marksheet :");
	s("%d",&temp);

	if(strcmp(temp,add->Sid)==0)
	{
	
	
	gotoxy(3,1);
	p("=============================================================================");
	gotoxy(22,2);
	p("L.J Institute of Computer Applicatios");
	gotoxy(16,3);
	p("LJ CAMPUS,BETWEEN SARKHEJ CIRCLE & KATARIA MOTORS");
	gotoxy(26,4);
	p("S.G.ROAD,AHMEDABAD-382210");
	gotoxy(3,5);
	p("=============================================================================");


	gotoxy(22,6);



	printf("\n\n\t\tRoll No: %d \t  Name : %s\t  Sem:%d\n",add->Sid,add->name,add->sem1);
	printf("\t\t------------------------------------------------------\n");
	printf("\t\tSubject             Max      Min            Obt.Marks\n");
	printf("\t\t-----------------------------------------------------\n");
	printf("\t\tsooadm              28       12              %d\n",add->sooadm);
	printf("\t\tjava                28       12              %d\n",add->java);
	printf("\t\twdt                 28       12              %d\n",add->wdt);
	printf("\t\tbs                  28       12              %d\n",add->bs);
	printf("\t\t-----------------------------------------------------\n");
	printf("\t\t			      Total: %2.f\n",add->total);
	printf("\t\tAverage:  %f                 Grade: %c\n",add->avg,add->grade);
	printf("\t\t-----------------------------------------------------\n");
	if(add->grade=='F')
	{

		p("\n\n\t\tSorry!!! You Have Fail in This Exam.");
	}
	else{
		p("\n\n\t\tCongratulations!!! You Have Passed This Exam.");
	}

	getch();
   }

}

void Midsem()
{
	clrscr();
	fptr=fopen("midsem.txt","a");
	if(fptr==NULL) {
		printf("Error!");
		exit(1);
	}

	p("Enter The Student ID: ");
	s("%d",&add->Sid);

	p("\nEnter Name: ");
	s("%s",add->name);

	p("\nEnter Semester: ");
	s("%d",&add->sem1);

	p("\nEnter Marks Of Sooadm::");
	s("%d",&add->sooadm);

	p("\nEnter Marks Of Java::");
	s("%d",&add->java);

	p("\nEnter Marks Of WDT::");
	s("%d",&add->wdt);

	p("\nEnter Marks Of BS::");
	s("%d",&add->bs);

	p("\n\n\t\tStudent Marksheet Created!!!");

	add->total=add->sooadm+add->java+add->wdt+add->bs;
	add->per=(add->sooadm+add->java+add->wdt+add->bs)*100/280;


	if(add->per>80 && add->per<=100)
		add->grade='A';
	else if(add->per>60 && add->per<=80)
		add->grade='B';
	else if(add->grade>=33 && add->grade<=60)
		add->grade='C';
	else
		add->grade='F';




	fprintf(fptr,"\n=============================================================================");

	fprintf(fptr,"\n\t\tL.J Institute of Computer Applicatios");

	fprintf(fptr,"\n\t\tLJ CAMPUS,BETWEEN SARKHEJ CIRCLE & KATARIA MOTORS");

	fprintf(fptr,"\n\t\tS.G.ROAD,AHMEDABAD-382210");

	fprintf(fptr,"\n=============================================================================");

	fprintf(fptr,"\n\n\t\tRoll No: %d \t  Name : %s\t  Sem:%d\n",add->Sid,add->name,add->sem1);
	fprintf(fptr,"\t\t-----------------------------------------------------\n");
	fprintf(fptr,"\t\tSubject             Max      Min            Obt.Marks\n");
	fprintf(fptr,"\t\t-----------------------------------------------------\n");
	fprintf(fptr,"\t\tsooadm              70       28              %d\n",add->sooadm);
	fprintf(fptr,"\t\tjava                70       28              %d\n",add->java);
	fprintf(fptr,"\t\twdt                 70       28              %d\n",add->wdt);
	fprintf(fptr,"\t\tbs                  70       28              %d\n",add->bs);
	fprintf(fptr,"\t\t-----------------------------------------------------\n");
	fprintf(fptr,"\t\t			      Total: %2.f\n",add->total);
	fprintf(fptr,"\t\tPer:  %.2f%%                   Grade: %c\n",add->per,add->grade);


	fprintf(fptr,"\t\t-----------------------------------------------------\n");
	if(add->grade=='F')
	{

		fprintf(fptr,"\n\n\t\tSorry!!! You Have Fail in This Exam.",add->grade);
	}
	else{
		fprintf(fptr,"\n\n\t\tCongratulations!!! You Have Passed This Exam.",add->grade);
	}
	fclose(fptr);


}
void middisplay()
{
	int temp;
	clrscr();

	fptr=fopen("midsem.txt","r");

	p("Enter Sid to Find a Marksheet :");
	s("%d",&temp);

	if(strcmp(temp,add->Sid)==0)
	{
	gotoxy(3,1);
	p("=============================================================================");
	gotoxy(22,2);
	p("L.J Institute of Computer Applicatios");
	gotoxy(16,3);
	p("LJ CAMPUS,BETWEEN SARKHEJ CIRCLE & KATARIA MOTORS");
	gotoxy(26,4);
	p("S.G.ROAD,AHMEDABAD-382210");
	gotoxy(3,5);
	p("=============================================================================");


	gotoxy(22,6);



	printf("\n\n\t\tRoll No: %d \t  Name : %s\t  Sem:%d\n",add->Sid,add->name,add->sem1);
	printf("\t\t------------------------------------------------------\n");
	printf("\t\tSubject             Max      Min            Obt.Marks\n");
	printf("\t\t------------------------------------------------------\n");
	printf("\t\tsooadm              70       28              %d\n",add->sooadm);
	printf("\t\tjava                70       28              %d\n",add->java);
	printf("\t\twdt                 70       28              %d\n",add->wdt);
	printf("\t\tbs                  70       28              %d\n",add->bs);
	printf("\t\t------------------------------------------------------\n");
	printf("\t\t			      Total: %2.f\n",add->total);
	printf("\t\tPer:  %.2f%%                   Grade: %c\n",add->per,add->grade);
	printf("\t\t------------------------------------------------------\n");
	if(add->grade=='F')
	{

		p("\n\n\t\tSorry!!! You Have Fail in This Exam.");
	}
	else{
		p("\n\n\t\tCongratulations!!! You Have Passed This Exam.");
	}

	getch();
	}
}

void load()
{
	int inti,gd=DETECT,gm;
	int i;
	initgraph(&gd,&gm,"c:\\tc\\bgi");

	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	outtextxy(177,180,"Loading,Please Wait....");

	for(i=190;i<510;i++)
	{
		delay(5);
		line(i,210,i,230);
	}
	closegraph();
	getch();
}


void smiley()
{
	int graphicdriver=DETECT,graphicmode;
	initgraph(&graphicdriver,&graphicmode,"c:\\tc\\bgi");
	outtextxy(260,100 + 100,"GOOD BYE!!");
	outtextxy(200,130 + 130,"Please Enter To Continue....!!!");

	setcolor(YELLOW);

	circle(300,100,40);
	setfillstyle(SOLID_FILL,YELLOW);
	floodfill(300,100,YELLOW);

	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);

	fillellipse(310,85,2,6);
	fillellipse(290,85,2,6);

	ellipse(300,100,205,335,20,9);
	ellipse(300,100,205,335,20,10);
	ellipse(300,100,205,335,20,11);

	getch();

}


void main()
{
	int choice,menu1;
	login();
	load();
	clrscr();

	do{
		print();
		s("%d",&choice);
		switch(choice)
		{
			 case 1://Create
					input();
					break;

			 case 2://Display
					display();
					break;

			 case 3://Update
					update();
					break;

			case 4://Delete
					Delete();
					break;

			case 5://Marksheet
					print1();
					s("%d",&menu1);
					switch(menu1)
					{

							case 1:
								Midsem();
								//load();
								break;

							case 2:
								ODE();
								//load();
								break;

							case 3:
								Practical();
								//load();
								break;

							case 4:
								middisplay();
								break;


							case 5:
								odedisplay();
								break;


							case 6:
								practicaldisplay();
								break;

							case 7:
								break;

							default:
								p("Invalid Choice");

					}

					break;


			case 6://Search
					search();
					break;
					
			case 7://Exit
					exit();
					break;
					
			
			default:p("\n You entered incorrect choice !");
		}

	}while(choice!=7);
	free(ptr);
	free(start);
	free(ptr1);
}

