#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char fileName[20],ipadd[20];;
long int start,end;

void user_work();
long int login_time();
void login_user();
void new_choice();
void see_feedback();
void new_pc();
void print_bill();
void delete_customer();
void display();
void insert();
void admin_work();
void admin();
void choice_admin();

int main(){
	int ch;
	printf("\n \n \t\t\t 1)Login as Admin");
	printf("\n \n \t\t\t 2)Login as User");
	printf("\n \n \n \t\t Enter Your choice(1/2):");
	scanf("%d",&ch);
	fflush(stdin);
	switch(ch){
		case 1:
			printf("\n\n\t-------------------------------------------------------------------------------------");
			printf("\n\t\t\t\t\t --ADMIN LOGIN--");
			printf("\n\t-------------------------------------------------------------------------------------");
			choice_admin();
			break;
		case 2:
			printf("\n\n\t-------------------------------------------------------------------------------------");
			printf("\n\t\t\t\t\t --USER LOGIN--");
			printf("\n\t-------------------------------------------------------------------------------------");
			login_user();
			break;
		default: printf("\n\n ENTER VALID NUMBER");
			main();
	}
	return 0;
}

void choice_admin(){
	char adminName[20],password[10];
	printf("\n\t Enter User Name:");
	gets(adminName);
	printf("\n\t Enter Password:");
	gets(password);
	if(strcmp(adminName,"Group15")==0)
	{
		if(strcmp(password,"123456789")==0)
		{
			printf("\n\n\t-------------------------------------------------------------------------------------");
			printf("\n\t-------------------------------------------------------------------------------------");
			printf("\n\t\t\t\t\t WELCOME BACK ADMIN");
			printf("\n\t-------------------------------------------------------------------------------------");
			printf("\n\t-------------------------------------------------------------------------------------");
			admin();
		}
		else
		{
			printf("\n\t Entered Password Was Wrong! Fail to login!!\n");
			choice_admin();
		}
	}
	else
	{
		printf("\n\t Entered User Name Was Wrong! Fail to login!!\n");
		choice_admin();
	}
}

void admin(){
	int no;
	printf("\n  Whether you want to add no of computers in your shop(1st time)(1-yes,any number for no):");
	scanf("%d",&no);
	fflush(stdin);
	if(no==1)
	{
		char ipA[20];
		int NoOfCom,i;
		FILE *filePointer;
		filePointer=fopen("IPaddress.txt","w");
		printf("\n enter no of PC/Laptops:");
		scanf("%d",&NoOfCom);
		fflush(stdin);
		for(i=0;i<NoOfCom;i++)
		{
			printf("\n enter your computer %d ip address:",i+1);
			gets(ipA);
			fprintf(filePointer,"%s\n",ipA);
			FILE *creFileIp;
			strcat(ipA,".txt");
			creFileIp=fopen(ipA,"w");
			fclose(creFileIp);
		}
		fclose(filePointer);
	}
	admin_work();
}

void admin_work(){
	int adminChoice;
	printf("\n\t\t\t\t\t   ----------");
	printf("\n\t\t\t\t\t   Admin Work");
	printf("\n\t\t\t\t\t   ----------");
	printf("\n\t\t\t 1)Insert New Customer Details");
	printf("\n\t\t\t 2)Display Customer Details");
	printf("\n\t\t\t 3)Delete Customer Details");
	printf("\n\t\t\t 4)Print Bill");
	printf("\n\t\t\t 5)Add new PC/Laptop");
	printf("\n\t\t\t 6)See Feedback");
	printf("\n\t\t\t 7)GOTO Main");
	printf("\n\t\t\t 8)exit");
	printf("\n\n\t Enter Your Choice:");
	scanf("%d",&adminChoice);
	fflush(stdin);
	switch(adminChoice)
	{
		case 1:
			insert();
			break;
		case 2:
			display();
			break;
		case 3:
			display();
			delete_customer();
			display();
			break;
		case 4:
			print_bill();
			break;
		case 5:
			new_pc();
			break;
		case 6:
			see_feedback();
			break;
		case 7:
			main();
			break;
		case 8:
			exit(0);
			break;
		default:printf("\n\t Enter valid Number!!");
			admin_work();
	}
	new_choice();
}

void insert(){
	FILE *ins_point,*fp;
	int i=0;
	char h,ipAd[20],matter,ipAdCopy[20],custName[20],custPhone[11],custPass[10];
	ipAdCopy[0]='\0';
	ins_point=fopen("IPaddress.txt","r");
	h=fgetc(ins_point);
	for(;h!=EOF;)
	{
		if(h!='\n')
		{
			ipAd[i]=h;
			i++;
		}
		else
		{
			ipAd[i]='\0';
			strcat(ipAd,".txt");
			fp=fopen(ipAd,"r");
			matter=fgetc(fp);
			if(matter==EOF)
			{
				strcpy(ipAdCopy,ipAd);
				ipAdCopy[i]='\0';
				printf("\n\t\t %s PC is unfilled",ipAdCopy);
			}
			fclose(fp);
			i=0;
		}
		h=fgetc(ins_point);
	}
	fclose(ins_point);
	if(ipAdCopy[0]=='\0')
	{
		printf("\n\n\t There Are No PC's Left. Please Wait For Some Time");
	}
	else
	{
		fflush(stdin);
		printf("\n\n\n\t\t Enter Customer Name:");
		gets(custName);
		printf("\n\t\t Enter Customer Phone Number:");
		gets(custPhone);
		printf("\n\t\t Enter Customer Password :");
		gets(custPass);
		strcat(ipAdCopy,".txt");
		ins_point=fopen(ipAdCopy,"w");
		fprintf(ins_point,"%s\n",custName);
		fprintf(ins_point,"%s\n",custPhone);
		fprintf(ins_point,"%s\n",custPass);
		fclose(ins_point);
		for(i=0;ipAdCopy[i]!='t';i++);
		ipAdCopy[i-1]='\0';
		printf("\n\n\t Congratulations!! %s has been alloated %s PC",custName,ipAdCopy);
		printf("\n\t------------------------------------------------------------------ ");
	}	
}

void display(){
	int i=0,j;
	char h,ipa[20],matter;
	FILE *ipAddress,*fileSearch;
	ipAddress=fopen("IPaddress.txt","r");
	h=fgetc(ipAddress);
	for(;h!=EOF;)
	{
		if(h!='\n')
		{
			ipa[i]=h;
			i++;
		}
		else
		{
			ipa[i]='\0';
			strcat(ipa,".txt");
			fileSearch=fopen(ipa,"r");
			matter=fgetc(fileSearch);
			for(j=0;ipa[j]!='t';j++);
			ipa[j-1]='\0';
			if(matter!=EOF)
			{
				printf("\n\n\t The details of %s customer are:\n",ipa);
				for(;matter!=EOF;)
				{
					printf("%c",matter);
					matter=fgetc(fileSearch);
				}
				printf("\n");
			}
			else
			{	
				printf("\n\t %s is empty",ipa);
			}
			fclose(fileSearch);
			i=0;
		}
		h=fgetc(ipAddress);
	}
	fclose(ipAddress);
}

void delete_customer(){
	int i=0;
	char h,ipDel[20],delIp[20];
	printf("\n\t Enter IP address of PC to be Deleted:");
	gets(delIp);
	FILE *IpAdFile,*fp;
	IpAdFile=fopen("IPaddress.txt","r");
	h=fgetc(IpAdFile);
	for(;h!=EOF;)
	{
		if(h!='\n')
		{
			ipDel[i]=h;
			i++;
		}
		else
		{
			ipDel[i]='\0';
			if(strcmp(ipDel,delIp)==0)
			{
				strcat(ipDel,".txt");
				fp=fopen(ipDel,"w");
				fclose(fp);
				printf("\n\t Congratulations Your Customer Details are deleted!!");
			}
			i=0;
		}
		h=fgetc(IpAdFile);
	}
	fclose(IpAdFile);
}

void print_bill(){
	long int res;
	res=end-start;
	if(res>=1)
	{
		res=res*0.01667;
	}
	printf("\n\n\t\t\t------------------------------------------------------------");
	printf("\n %s --YOUR BILL IS %ld Rupee(s)",fileName,res);
	printf("\n\t\t\t------------------------------------------------------------");
}

void new_pc(){
	char ipA[20];
	int NoOfCom,i;
	FILE *filePointer;
	filePointer=fopen("IPaddress.txt","a");
	printf("\n enter no of PC/Laptops to add:");
	scanf("%d",&NoOfCom);
	fflush(stdin);
	for(i=0;i<NoOfCom;i++)
	{
		printf("\n enter your computer %d ip address:",i+1);
		gets(ipA);
		fprintf(filePointer,"%s\n",ipA);
		FILE *creFileIp;
		strcat(ipA,".txt");
		creFileIp=fopen(ipA,"w");
		fclose(creFileIp);
	}
	fclose(filePointer);
	printf("\n\n\t SUCCESFULLY ADDED NEW PC/LAPTOP");
}

void see_feedback(){
	printf("\n\n");
	char h;
	FILE *p;
	p=fopen("feedBack.txt","r");
	h=fgetc(p);
	for(;h!=EOF;)
	{
		printf("%c",h);
		h=fgetc(p);
	}
	fclose(p);
}

void new_choice(){
	int choice;
	printf("\n\n\n\t\t\t 0)ENTER 0 TO EXIT");
	printf("\n\t\t\t 1)ENTER 1 TO GO TO MAIN");
	printf("\n\t\t\t 2)ENTER 2 TO GO TO BACK TO ADMIN WORK");
	printf("\n Enter:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			main();
			break;
		case 2:
			admin_work();
			break;
		case 0:
			exit(0);
		default:printf("\n Enter valid number!!"); 
			new_choice();
	}
}

void login_user(){
	char fb[30];
	int i=0,j=0,f=0;
	FILE *fileOpen,*feed;
	char Password[10],s[20],h,filePass[10],filePhone[11];
	printf("\n\t Enter Your IP Address:");
	gets(ipadd);
	printf("\n\t Enter Password given by admin:");
	gets(Password);
	strcat(ipadd,".txt");
	fileOpen=fopen(ipadd,"r");
	if(fileOpen==NULL)
	{
		printf("\n\n\t\t PLEASE ENTER VALID IP ADDRESS");
		main();
	}
	else
	{
		h=fgetc(fileOpen);
		if(h==EOF)
		{
			printf("\n\n\t\tYOUR DETAILS ARE NOT UPLOADED. PLEASE WAIT OR PLEASE ENTER VALID IP ADDRESS");
			main();
		}
		for(;h!=EOF;)
		{
			if(h!='\n')
			{
				s[i]=h;
				i++;
			}
			else
			{
				s[i]='\0';
				if(j==0)
				{
					strcpy(fileName,s);
					j++;
				}
				else if(j==1)
				{
					strcpy(filePhone,s);
					j++;
				}
				else if(j==2)
				{
					if(strcmp(s,Password)!=0)
					{
						printf("\n\n\t!!ENTERED PASSWORD IS INCORRECT!!");
						login_user();
					}
					else
					{
						printf("\n\n\t\t\t\t Welcome %s",fileName);
						fclose(fileOpen);
						f++;
						start=login_time();
						user_work();
						end=login_time();
					}
				}
				i=0;
			}
			h=fgetc(fileOpen);
		}
	}
	if(f==0)
	{
		fclose(fileOpen);
	}
	printf("\n\n\t\t THANK YOU FOR COIMING TO OUR SHOP");
	printf("\n Can You Please give your feedback:");
	feed=fopen("feedBack.txt","a");
	printf("enter your feedback:");
	gets(fb);
	fprintf(feed,"%s\t%s\t%s\n",fileName,filePhone,fb);
	fclose(feed);
	main();
}

long int login_time(){
	FILE *fileOpen;
	time_t ti;
	ti=time(NULL);
	char *h=ctime(&ti);
	fileOpen=fopen(ipadd,"a");
	fprintf(fileOpen,"%s",h);
	fclose(fileOpen);
	return ti;
}

void user_work(){
	char h;
	printf("\n\nEnter Anything to do Your Work(Enter ' 'ctrl+z' +Enter' after completion of your work):");
	h=getchar();
	for(;h!=EOF;)
	{
		h=getchar();
	}
}
