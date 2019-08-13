
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>

COORD coord= {0,0}; // this is global variable
void cursor(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
FILE*fp,*fp1,*f1,*f2;
struct hospital{
		char name[20],address[20],ch;
		int age,roomno;
		char disease[30],department[20];
		char recommendation[50],category[30];

		float am_return,deposit,fee;
		float balance;
		}p;
char fn1[]="opd12.patient";
char fn2[]="oopd12.patient";
typedef struct hospital alka;

int main()
{
     int n,i;
     screen1();
    screen2();
    screen3();
     printf("\n\nEnter your choice\n");
     scanf("%d",&n);
     switch(n)
     {
         case 1:
                fp=fopen("test2.txt","a");
                printf("Adding a new record\n\n");
                printf("Enter 1 for opd and 2 for emergency\n");
                scanf("%d",&i);
                if(i!=1 && i!=2)
                {
                    printf("Invalid option selected\n");
                }
                else if(i==1)
                {
                        system("cls");

                       cursor(40,5);
                       printf("ADDING NEW O.P.D.PATIENT RECORD");
                       cursor(40,6);
                       printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

                       newrecord();
                       newrecord1();
                       strcpy(p.category,"O.P.D.Patient");
                       strcpy(p.recommendation,"Admitted to O.P.D.");
                       printf("\n\nThe list of expenditure to the patient :\n\n");
                       printf("O.P.D Charge = Rs.200.0\n");
                       p.fee=200.0;
                       printf("Total amount deposited = Rs");
                       scanf("%f",&p.deposit);
                       if(p.deposit<200)
                       {
                           p.balance=200.0-p.deposit;
                           p.am_return=0;
                       }
                       else
                       {
                           p.balance=0;
                           p.am_return=p.deposit-200;
                       }

                       //printf("\nBalance amount =%f",p.balance);
                       //printf("\nMoney to be returned = Rs.%f\n",p.am_return);
                       /*printf("%s",p.name);
                       printf("%s",p.address);
                       printf("%d",p.age);
                       printf("%c",)*/
                       //printf("%s,%s,%d,%d,%c,%s,%s,%s,%s,%f,%f,%f,%f",p.name,p.address,p.age,p.roomno,p.ch,p.disease,p.department,p.recommendation,p.category,p.am_return,p.deposit,p.fee,p.balance);
                       fwrite(&p,sizeof(p),1,fp);
                       fclose(fp);
                       screen4();
                       //system("cls");
                       //view();



                }
                else if(i==2)
                {
                    system("cls");
                    cursor(40,5);
                    fp1=fopen("test3.txt","a");
                    printf("ADDING NEW EMERGENCY PATIENT RECORD");
                   cursor(23,12);
				 printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				 newrecord();
                newrecord1();
                strcpy(p.category,"Emergency Patient");
                       strcpy(p.recommendation,"Admitted to Emergency");
                       printf("\n\nThe list of expenditure to the patient :\n\n");
                       printf("Emergency Charge = Rs.1000.0\n");
                       printf("Total amount deposited = Rs");
                       scanf("%f",&p.deposit);
                       p.fee=1000.0;
                       if(p.deposit<1000)
                       {
                           p.balance=1000.0-p.deposit;
                           p.am_return=0;
                       }
                       else
                       {
                           p.balance=0;
                           p.am_return=p.deposit-1000;
                       }
                       //printf("\nBalance amount =%f",p.balance);
                       //printf("\nMoney to be returned = Rs.%f\n",p.am_return);
                      // printf("%s,%s,%d,%d,%c,%s,%s,%s,%s,%f,%f,%f,%f",p.name,p.address,p.age,p.roomno,p.ch,p.disease,p.department,p.recommendation,p.category,p.am_return,p.deposit,p.fee,p.balance);
                       fwrite(&p,sizeof(p),1,fp1);
                       fclose(fp1);
                       screen4();

                }
                break;
        case 3:  viewrecord();
                break;
        case 2: editrecord();
                break;
        case 4:exit(0);
     }

}
void screen1()
{
    system("color B6");
       int a=40,b=80,c=13,d=20,i,j;
       cursor(30,9);
       for(i=1;i<=50;i++)
       {
           printf("*");
       }

       cursor(30,10);

       for(i=1;i<=10;i++)
       {
           printf("*");
       }

       printf("   Hospital Mangement Sytem   ");
       for(i=1;i<=10;i++)
       {
           printf("*");
       }
       cursor(30,11);
       for(i=1;i<=50;i++)
       {
           printf("*");
       }

       for (i=a; i<=b; i++)
    {

        cursor(i,c);
        printf("\xcd");
        cursor(i,d);
        printf("\xcd");
    }

    for(i=c; i<=d; i++)
    {
        cursor(a,i);
        printf("\xba");
        cursor(b,i);
        printf("\xba");
    }
    cursor(a,c);
    printf("\xc9");
    cursor(a,d);
    printf("\xc8");
    cursor(b,c);
    printf("\xbb");
    cursor(b,d);
    printf("\xbc");

    cursor(a+6,c+1);
    printf("SHEKHAR HOSPITALS\n");
    cursor(a+6,c+3);
    printf("Srinivasanagar, Bengaluru");
        cursor(a+6,c+5);
        printf("Contact us: 08026753100/101/102");


}
void screen2()
{
     int a,b,c,d,i;
    a=70;
        b=105;
        c=21;
        d=29;


               for (i=a; i<=b; i++)
    {

        cursor(i,c);
        printf("\xcd");
        cursor(i,d);
        printf("\xcd");
    }

    for(i=c; i<=d; i++)
    {
        cursor(a,i);
        printf("\xba");
        cursor(b,i);
        printf("\xba");
    }
    cursor(a,c);
    printf("\xc9");
    cursor(a,d);
    printf("\xc8");
    cursor(b,c);
    printf("\xbb");
    cursor(b,d);
    printf("\xbc");
    cursor(a,c);



       cursor(a+3,c+2);
       printf("Immediate Care Clinics");
             cursor(a+3,c+4);
       printf("Medical Emergency Resources");
              cursor(a+3,c+6);
       printf("Health and Patient Services");

}
void screen3()
{
     int a,b,c,d,i;
    a=40;
    b=80;
    c=32;
    d=42;

       for (i=a; i<=b; i++)
    {

        cursor(i,c);
        printf("\xcd");
        cursor(i,d);
        printf("\xcd");
    }

    for(i=c; i<=d; i++)
    {
        cursor(a,i);
        printf("\xba");
        cursor(b,i);
        printf("\xba");
    }
    cursor(a,c);
    printf("\xc9");
    cursor(a,d);
    printf("\xc8");
    cursor(b,c);
    printf("\xbb");
    cursor(b,d);
    printf("\xbc");
    cursor(a,c);

   cursor(a,c);

       cursor(a+6,c+1);
    printf("1).Add a new record\n");
    cursor(a+6,c+3);
    printf("2).Search or edit record\n");
    cursor(a+6,c+5);
    printf("3).Display the records\n");

    cursor(a+6,c+7);
    printf("4).Exit from the program\n");



}
void screen4()
{
    int n;
    system("cls");

    printf("Thanks for the visit\n");
    printf("Hope you liked our service\n");
    printf("Please rate us on a scale of 5\n");

     int a,b,c,d,i;
        a=40;
        b=78;
        c=25;
        d=37;


               for (i=a; i<=b; i++)
    {

        cursor(i,c);
        printf("\xcd");
        cursor(i,d);
        printf("\xcd");
    }

    for(i=c; i<=d; i++)
    {
        cursor(a,i);
        printf("\xba");
        cursor(b,i);
        printf("\xba");
    }
    cursor(a,c);
    printf("\xc9");
    cursor(a,d);
    printf("\xc8");
    cursor(b,c);
    printf("\xbb");
    cursor(b,d);
    printf("\xbc");
    cursor(a,c);



       cursor(a+3,c+2);
       printf("1.Unsatisfactory");
             cursor(a+3,c+4);
       printf("2.Satisfactory");
              cursor(a+3,c+6);
       printf("3.Good can do better");
       cursor(a+3,c+8);
    printf("4.Excellent service");
    cursor(a+3,c+10);
    printf("5.Outstanding loved a lot\n");
    cursor(a+3,c+15);
    printf("Please enter a valid rating\n");
    scanf("%d",&n);
    switch(n)
    {

        case 1:printf("Unsatisfactory\n");
               break;
        case 2:printf("Satisfactory\n");
               break;
        case 3:printf("Good can do better\n");
              break;
        case 4:printf("Excellent service\n");
              break;
        case 5:printf("Outstanding loved a lot\n");
             break;
        default:printf("Please enter a valid rating\n");
              break;

    }
    cursor(6,48);
    printf("Thanks for the review \n");
    printf("We'll take in the necessary inputs and improve ourselves");
}

void displaydepartment()
{
	int i;
	cursor(48,14);
	printf(":Specialists:");
	cursor(47,15);
	printf("---------------");
	cursor(70,14);
	printf("Room No.");
	cursor(67,15);
	printf("----------");
	cursor(48,17);
	printf("1.General Physician");
	cursor(70,17);
	printf("201,202");
	cursor(48,19);
	printf("2.E.N.T");
	cursor(70,19);
	printf("302");
	cursor(48,21);
	printf("3.Cardiologist");
	cursor(70,21);
	printf("509");
	cursor(48,23);
	printf("4.Dermatologist");
	cursor(70,23);
	printf("406");
	cursor(48,25);
	printf("5.Gastroenterologist");
	cursor(70,25);
	printf("308");
	cursor(48,27);
	printf("6.Pediatrician");
	cursor(70,27);
    printf("207");
	cursor(48,29);
	printf("7.EYE Specialist");
	cursor(70,29);
	printf("102");
	cursor(48,31);
	printf("8.Nephrologist");
	cursor(70,31);
	printf("109");
	cursor(48,33);
	printf("9.General Surgeon");
	cursor(70,33);
	printf("407,408");
	cursor(70,35);
	printf("412,413");
	cursor(48,37);
	printf("10.Accupuncturist");
	cursor(70,37);
	printf("123,119");
}
void newrecord()

{
     displaydepartment();
     cursor(5,14);
    printf("Record of patient no:");


	cursor(5,17);
	printf("Name:");

	cursor(5,20);
	printf("Address:");

	cursor(5,23);
	printf("Age: ");

	cursor(5,26);
	printf("Sex(m/f): ");

	cursor(5,29);
	printf("Disease Descrp:");
	cursor(9,30);
	printf("(In Short)");

	cursor(5,33);
	printf("Reff. Specialist no:");
	cursor(10,17);
	fflush(stdin);
	scanf("%[^\n]",p.name);
   p.name[0]=toupper(p.name[0]);
    cursor(14,20);
	fflush(stdin);
	scanf("%[^\n]",p.address);
	cursor(10,23);
	fflush(stdin);
	scanf("%d",&p.age);
	cursor(15,26);
	fflush(stdin);
	scanf("%c",&p.ch);
	fflush(stdin);

	fflush(stdin);cursor(22,29);
	scanf("%[^\n]",p.disease);
}

void newrecord1()
{

	  int k;
	  system("cls");
	printf("Enter");
	 cursor(20,13);
	scanf("%d",&k);
	switch(k)
	{
		case 1:
			{      	cursor(5,36);
			       printf("Reff.Specialist:");
			       printf("Generalphysician");
                   strcpy(p.department,"General Physician");
			       cursor(5,39);
				   printf("Room no:");
				   scanf("%d",&p.roomno);



				break;

			}
		case 2:
			{      cursor(5,36);
			       printf("Reff.Specialist:");
			       printf("E.N.T.");
			       strcpy(p.department,"E.N.T");
			       cursor(5,39);
			       printf("Room no:");
			       printf("302");
			       p.roomno=302;


				break;
			}
			case 3:
			{      cursor(5,36);
			       printf("Reff.Specialist:");
			       printf("Cardiologist");
			       strcpy(p.department,"Cardiologist");
			       cursor(5,39);
			       printf("Room no:");
			       printf("509");
			       p.roomno=509;
				break;
			}
			case 4:
			{      cursor(5,36);
			       printf("Reff.Specialist:");
			       printf("Dermatologist");
			       strcpy(p.department,"Dermatologist");
			       cursor(5,39);
			       printf("Room no:");
			       printf("406");
			       p.roomno=406;

				break;
			}

			case 5:
			{      cursor(5,36);
			       printf("Reff.Specialist:");
			       printf("Gastroenteroiogist");
			       strcpy(p.department,"Gastroenteroiogist");
			       cursor(5,39);
			       printf("Room no:");
			       printf("308");
			       p.roomno=308;

				break;
			}
			case 6:
			{      cursor(5,36);
			       printf("Reff.Specialist:");
			       printf("Pediatrician");
			       strcpy(p.department,"Pediatrician");
			       cursor(5,39);
			       printf("Room no:");
			       printf("207");
			       p.roomno=207;

				break;
			}
			case 7:
			{      cursor(5,36);
			       printf("Reff.Specialist:");
			       printf("EYE Specialist");
			       strcpy(p.department,"EYE Specialist");
			       cursor(5,39);
			       printf("Room no:");
			       printf("102");
			       p.roomno=102;

				break;
			}
			case 8:
			{      cursor(5,36);
			       printf("Reff.Specialist:");
			       printf("Nephrologist");
			       strcpy(p.department,"Nephrologist");
			       cursor(5,39);
			       printf("Room no:");
			       printf("109");
			       p.roomno=109;

				break;
			}
			case 9:
			{      cursor(5,36);
			       printf("Reff.Specialist:");
			       printf("General Surgeon");
                   strcpy(p.department,"General Surgeon");
			       cursor(5,39);
				   printf("Room no:");
				   scanf("%d",&p.roomno);



				break;
			}
			case 10:
			{      cursor(5,36);
			       printf("Reff.Specialist:");
			       printf("Accumpunturist");
                   strcpy(p.department,"Accumpunturist");
			       cursor(5,39);
				    printf("Room no:");
				    scanf("%d",&p.roomno);




				break;
			}
		default:
			{
			printf("Invalid number entered\n");
			return;
			}
	}
}
void view()
{
    fp=fopen(fn1,"rb");
    while(fread(&p,sizeof(alka),1,fp))
    {
      display();
    }
    fclose(fp);
}
void display_test()
{
    int i;
	cursor(50,10);
	system("cls");
    printf("::ADDING SERVICES::");cursor(45,11);
	printf("----------------------------");
	cursor(9,10);
	printf(":PRICE LIST:");

	cursor(4,11);
	printf("---------------------");
	cursor(5,14);
	printf("1.X-Ray");
	cursor(30,14);
	printf("Rs. 300.00");
	cursor(5,16);
	printf("2.Ultra-sound");
	cursor(30,16);
	printf("Rs. 500.00");
	cursor(5,18);
	printf("3.C.T.Scan");
	cursor(30,18);
	printf("Rs.1800.00");
	cursor(5,20);
	printf("4.TC,DC,HB");
	cursor(30,20);
	printf("Rs.  90.00");
	cursor(5,22);
	printf("5.Urine R/E");
	cursor(30,22);
	printf("Rs.  80.00");
	cursor(5,24);
	printf("6.Blood C/S");
	cursor(30,24);
	printf("Rs. 250.00");
	cursor(5,26);
	printf("7.Biliribin D/T");
	cursor(30,26);
	printf("Rs. 200.00");
	cursor(5,28);
	printf("8.Stool Test");
	cursor(30,28);
	printf("Rs.  60.00");
	cursor(5,30);
	printf("9.Bed Charge");
	cursor(30,30);
	printf("Rs. 150.00");
	cursor(5,32);
	printf("10.Sugar Test");
	cursor(30,32);
	printf("Rs. 400.00");

	for(i=10;i<=46;i++)
	{
		cursor(41,i);
		printf("|");

	}

    int n,k;
    float t;
    cursor(60,10);
    printf("Enter the services u require\n");
    cursor(60,12);
    scanf("%d",&n);
    switch(n)
    {
    case 1:t=300.0;
          break;
    case 2:t=500.0;
          break;
    case 3:t=1800;
              break;
    case 4:t=90.0;
         break;
    case 5:t=80.0;
            break;
    case 6:t=250.0;
            break;
    case 7:t=200.0;
           break;
    case 8:t=60.0;
           break;
    case 9:t=150.0;
           break;
    case 10:t=400.0;
            break;

    default:printf("Invalid option\n");


    }
    cursor(60,14);
    printf("Additional amount to be paid for test charges : %f\n",t);

    p.balance=p.balance+t;
    p.fee=p.fee+t;
    cursor(60,16);
    printf("Total amount to be paid is %f\n",p.fee);
    cursor(60,18);
    printf("Total balance amount is %f\n",p.balance);
    cursor(60,20);
    printf("Press 1 to exit\n");
   cursor(60,22);

    scanf("%d",&k);
    if(k==1)
    {
        screen4();
    }
    else
    {

        printf("invalid\n");
    }


}


void display()
{
	cursor(29,10);
	printf("DISPLAYING RECORDS");
	cursor(28,11);
	printf("--------------------");
	cursor(10,14);
		printf("Name:");cursor(15,17);
	printf(" %s",p.name);cursor(10,20);
	printf("Address:");cursor(18,20);
    printf(" %s",p.address);cursor(10,23);
    printf("Age:");
	printf("%d",p.age);
	printf("Sex:");cursor(14,26);
	printf(" %c",p.ch);cursor(10,29);

	printf("Department:");cursor(21,35);
	printf(" %s",p.department);cursor(10,38);
	printf("Category:");cursor(19,38);
	printf(" %s",p.category);
	printf("Room no:");
	printf(" %d",p.roomno);

}
void viewrecord()
{
     int n;
     system("cls");
     screen1();
     cursor(0,25);
     printf("1.Records of O.P.D patients\n");
     printf("2.Records of Emergency patients\n");
     printf("Enter ur option \n");

     scanf("%d",&n);
     if(n==1)
     {

    fp1=fopen("test2.txt","r");
    while(fread(&p,sizeof(p),1,fp1)>0)
    {
        printf("Name: %s\nAddress: %s\nAge: %d\nRoom.No: %d\nGender:%c\nDisease: %s\nDepartment: %s\nRecomendation: %s\nCategory: %s\nAmount to be returned: %f\nAmount to be deposited: %f\nTotal fee: %f\nBalance amount: %f\n\n\n",p.name,p.address,p.age,p.roomno,p.ch,p.disease,p.department,p.recommendation,p.category,p.am_return,p.deposit,p.fee,p.balance);

    }
    fclose(fp1);
     }
     else if(n==2)
     {
        fp1=fopen("test3.txt","r");
    while(fread(&p,sizeof(p),1,fp1)>0)
    {
        printf("Name: %s\nAddress: %s\nAge: %d\nRoom.No: %d\nGender:%c\nDisease: %s\nDepartment: %s\nRecomendation: %s\nCategory: %s\nAmount to be returned: %f\nAmount to be deposited: %f\nTotal fee: %f\nBalance amount: %f\n\n\n",p.name,p.address,p.age,p.roomno,p.ch,p.disease,p.department,p.recommendation,p.category,p.am_return,p.deposit,p.fee,p.balance);

    }
    fclose(fp1);
     }
    else
    {
        printf("Invalid option\n");
    }



}
void editrecord()
{
   int n,x;
     char ch[100];
     system("cls");


     printf("1.Records of O.P.D patients\n");
     printf("2.Records of Emergency patients\n");

     printf("Enter ur option \n");
      scanf("%d",&n);
     printf("Enter name of the patient\n");
     scanf("%s",ch);

     if(n==1)
     {

    fp1=fopen("test2.txt","r");
    while(fread(&p,sizeof(p),1,fp1)>0)
    {
        if((strcmp(ch,p.name)==0))
        {
        printf("Name: %s\nAddress: %s\nAge: %d\nRoom.No: %d\nGender:%c\nDisease: %s\nDepartment: %s\nRecomendation: %s\nCategory: %s\nAmount to be returned: %f\nAmount to be deposited: %f\nTotal fee: %f\nBalance amount: %f\n\n\n",p.name,p.address,p.age,p.roomno,p.ch,p.disease,p.department,p.recommendation,p.category,p.am_return,p.deposit,p.fee,p.balance);
        printf("Press `1'to edit or add any additional details\n");
        scanf("%d",&x);
             if(x==1)
              {
                 switch1();
              }
              else
              {
                  printf("Invalid option\n");
              }
        }

    }
    printf("Invalid person name\n");

    fclose(fp1);
     }
     else if(n==2)
     {
        fp1=fopen("test3.txt","r");
    while(fread(&p,sizeof(p),1,fp1)>0)
    {
        if((strcmp(ch,p.name)==0))
         {
        printf("Name: %s\nAddress: %s\nAge: %d\nRoom.No: %d\nGender:%c\nDisease: %s\nDepartment: %s\nRecomendation: %s\nCategory: %s\nAmount to be returned: %f\nAmount to be deposited: %f\nTotal fee: %f\nBalance amount: %f\n\n\n",p.name,p.address,p.age,p.roomno,p.ch,p.disease,p.department,p.recommendation,p.category,p.am_return,p.deposit,p.fee,p.balance);
        printf("Press `1'to edit or add any additional details\n");
        scanf("%d",&x);
             if(x==1)
              {
                 switch1();
              }
              else
              {
                  printf("Invalid option\n");
              }
        }
    }
    printf("Invalid person name\n");

    fclose(fp1);



}
}
void switch1()
{
	int x,i,k;
	float d,lk;
	char v;
	char string[100];
	label2:
	cursor(30,15);
	system("cls");
	printf("Enter");cursor(30,18);
	printf("1.Add Details");
	cursor(30,20);
	printf("2.Change Specialist");
	cursor(30,22);
	printf("3.Deposit balance");cursor(30,24);
	printf("4.Add test");
	cursor(30,26);
	printf("5.Return to main menu");
	cursor(35,39);
	fflush(stdin);
	scanf("%d",&x);
	switch(x)
	{
		case 1:
		      {
			system("cls");

			cursor(31,10);
			printf("ADDING DETAILS");
			cursor(30,11);
			printf("----------------");
			cursor(15,25);

			printf("Previous Details:");
			cursor(32,25);
			printf(" %s ",p.recommendation);
			cursor(15,28);
			strcat(p.recommendation,"-> ");
			printf("New Details:");
			fflush(stdin);
			scanf("%[^\n]",string);
			cursor(18,31);
			printf("Succesfully completed\n");
			strcat(p.recommendation,string);
			cursor(18,33);
			printf("Enter 1 to exit\n");
			cursor(18,35);
			scanf("%d",&k);
			if(k==1)
            {
                screen4();

            }
            else
            {

                printf("Invalid\n");
            }
			break;
		      }
		case 2:
		      {
			system("cls");

			displaydepartment();
			cursor(28,10);
			printf("CHANGING SPECIALIST");
			cursor(27,11);
			printf("---------------------");
			cursor(5,20);

			printf("Previous Specialist:");
			cursor(26,20);
			printf(" %s ",p.department);
			cursor(5,27);
			printf(":Enter the new changed Specialist;");
			cursor(5,33);
			printf("Reff. Specialist no:");
			newrecord1();
			cursor(50,58);
			printf("Succesfully completed\n");
			cursor(50,60);
			printf("Enter 1 to exit\n");
			cursor(50,62);
			scanf("%d",&k);
			if(k==1)
            {
                screen4();

            }
            else
            {

                printf("Invalid\n");
            }

			break;
		      }
		case 3:
		      {
		       system("cls");
		       cursor(28,10);
		       printf("DEPOSITING MONEY");
		       cursor(27,11);
		       printf("---------------------");
		       cursor(20,20);

		       printf("Deposited balance: Rs.");
		       fflush(stdin);
		       scanf("%f",&d);
		       p.balance=p.balance-d;
		       printf("Remaining balance is %f\n",p.balance);
		       cursor(50,40);
			printf("Succesfully completed\n");
			cursor(50,42);
			printf("Enter 1 to exit\n");
			cursor(50,44);
			scanf("%d",&k);
			if(k==1)
            {
                screen4();

            }
            else
            {

                printf("Invalid\n");
            }
		       break;
		      }
		case 4:{  display_test();
		      break;
		}
		case 5:
              {

                  system("cls");
                  screen1();
                    screen2();
                      screen3();
              }

	}
}
