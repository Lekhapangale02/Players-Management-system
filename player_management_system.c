#include<stdio.h>
#include<stdlib.h>
typedef struct date
{
	int day;
	int month;
	int year;
}date;
typedef struct players
{
	char name[30];
	char gender[10];
	int matches;
	char team[10];
	int jersey_no;
	int runs;
	int wickets;
	int age;
	char position[15];
	date dob;
	
}players;
void store (players*,int);
void display (players*,int);
void search (players*,int,int);
void show (players*,int);
void update (players*,int,int);
void deleat (players*,int,int);
int max_run(players* ,int);
int max_wkt(players* ,int);
void add_player(players*,int*);
void main()
{
	printf("\n_________PLAYER MANAGEMENT SYSTEM_________");
	printf("\n\n Do you want to continue.....");
	char ch='y';
	scanf(" %c",&ch);
	int n,choice,jersy,place,res=0;
	players* p;
	printf("\n Enter the number of players:");
	scanf("%d",&n);
	p=(players*)malloc(n*sizeof(players));
	while(ch!='n')
	{
		printf("\n-----------------------------------");
		printf("\n 1.store players details");
		printf("\n 2.Display players details");
		printf("\n 3.search by jersy number");
		printf("\n 4.update by jersy number");
		printf("\n 5.deleat by jersy number");
		printf("\n 6.max number of runs");
		printf("\n 7.max number of wicket");
		printf("\n 8.Add number of player");
		printf("\n\n Enter you choice: ");
		scanf(" %d",&choice);
		printf("\n------------------------------------");
		switch(choice)
		{
		case 1:
			store(p,n);
		break;
		
		case 2:
			display(p,n);
		break;
		
		case 3://search
			printf("\n plzz Enter jersy number:");
			scanf("%d",&jersy);
			search(p,n,jersy);
		break;
		
		case 4://update
			printf("\n plzz Enter jersy number:");
			scanf("%d",&jersy);
			update(p,n,jersy);
		break;
		
		case 5://deleat
			printf("\n plzz Enter jersy number:");
			scanf("%d",&jersy);
			deleat(p,n,jersy);
		break;
		
		case 6://max runs
			res=max_run(p,n);
			show(p,res);
		break;
		
		case 7://max wikets
			res=max_wkt(p,n);
			show(p,res);
		break;
		
		case 8://add
			add_player(p,&n);
			
		break;
		
		default:
			printf("\n invalid choice!!");
		
		}
		printf("\n Do you want to continue y / n:");
		scanf(" %c",&ch);
		fflush(stdin);
	}
}
void store(players* p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nEnter the details of player %d:",i+1);
		fflush(stdin);
		printf("\nName of player:");
		gets(p[i].name);
		printf("Enter your Gender:");
		gets(p[i].gender);
		printf("Total matches played:");
		scanf("%d",&p[i].matches);
		fflush(stdin);
		printf("Enter the name of your Team:");
		gets(p[i].team);
		printf("Enter jesry number:");
		scanf("%d",&p[i].jersey_no);
		printf("Number of runs:");
		scanf("%d",&p[i].runs);
		printf("Number of wickets:");
		scanf("%d",&p[i].wickets);
		printf("Enter your Age: ");
		scanf("%d",&p[i].age);
		fflush(stdin);
		printf("Enter your birth date:\n");
		scanf("%d",&p[i].dob.day);
		scanf("%d",&p[i].dob.month);
		scanf("%d",&p[i].dob.year);
		printf("\n--------------------------------------\n");
	}
}
void display(players* p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\n Details of player %d:",i+1);
		printf("\n Name of player:%s",p[i].name);
		printf("\n Gender of player:%s",p[i].gender);
		printf("\n Total matches played:%d",p[i].matches);
		printf("\n Name of the Team:%s",p[i].team);
		printf("\n jesry number of player:%d",p[i].jersey_no);
		printf("\n Number of runs:%d",p[i].runs);
		printf("\n Number of wickets:%d",p[i].wickets);
		printf("\n Age of a player:%d",p[i].age);
		printf("\n Birth date of player: %d/%d/%d",p[i].dob.day,p[i].dob.month,p[i].dob.year);
		printf("\n");
		printf("\n----------------------------------------\n");
	}
}
void search(players* p,int n,int jersy)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(jersy==p[i].jersey_no)
		{
			printf("\n Details of player with jersy number %d\n",p[i].jersey_no);
			show(p,i);
			break;
		}
		else if(i==n-1)
		printf("\n jersy number %d is not found!!",jersy);
		printf("\n----------------------------------------------\n");
	}
}
void show(players* p,int i)
{
		printf("\n Name of player:%s",p[i].name);
		printf("\n Gender of player:%s",p[i].gender);
		printf("\n Total matches played:%d",p[i].matches);
		printf("\n Name of the Team:%s",p[i].team);
		printf("\n jesry number of player:%d",p[i].jersey_no);
		printf("\n Number of runs:%d",p[i].runs);
		printf("\n Number of wickets:%d",p[i].wickets);
		printf("\n Age of a player:%d",p[i].age);
		printf("\n Birth date of player: %d/%d/%d",p[i].dob.day,p[i].dob.month,p[i].dob.year);
		printf("\n");
}
void update(players* p,int n,int jersy)
{
	int select,i;
	char ch='y';
	for(i=0;i<n;i++)
	{
		if(jersy==p[i].jersey_no)
		{
			show(p,i);
	while(ch!='n')
	{
	printf("\n-----------------------------------");
	printf("\n 1.Name of player:");
	printf("\n 2.Gender of player:");
	printf("\n 3.Total matches played:");
	printf("\n 4.Name of team:");
	printf("\n 5.jersy number:");
	printf("\n 6.Number of runs:");
	printf("\n 7.Number id wickets:");
	printf("\n 8.Age of a player:");
	printf("\n 9.Birth date of player:\n");
	printf("\n Enter your choice which Attribute you want to update:");
	scanf("%d",&select);
	fflush(stdin);
	printf("\n-----------------------------------");
	switch(select)
	{
		case 1:
		printf("\n Enter Name to update:");
		gets(p[i].name);
		fflush(stdin);
		break;
		case 2:
		printf("\n Enter gender of player to update:");
		gets(p[i].gender);
		fflush(stdin);
		break;
		case 3:
		printf("\n Update of total matches played:");
		scanf("%d",p[i].matches);
		fflush(stdin);
		break;
		case 4:
		printf("\n Enter the name of Updated Team:");
		gets(p[i].team);
		fflush(stdin);
		break;
		case 5:
		printf("\n Enter updated jersey number:");
		scanf("%d",p[i].jersey_no);
		fflush(stdin);
		break;
		case 6:
		printf("\n Enter the updated runs:");
		scanf("%d",p[i].runs);
		fflush(stdin);
		break;
		case 7:
		printf("\n Enter the updated wicket:");
		scanf("%d",p[i].wickets);
		fflush(stdin);
		break;
		case 8:
		printf("\n Enter updated age:");
		scanf("%d",p[i].age);
		fflush(stdin);
		break;
		case 9:
		printf("\n Enter updated birthdate:");
		scanf("%d%d%d",&p[i].dob.day,&p[i].dob.month,&p[i].dob.year);
		fflush(stdin);
		break;
	default:
		printf("\n Invalid choice..");
	}
	printf("\n updated details of player");
	show(p,i);
	printf("\n Congratulations!! information updated succesfully...");
	printf("\n Any more player details you want to update y/n: ");
	scanf("%c",&ch);
	fflush(stdin);
	printf("\n-------------------------------------------------\n");
	}
	}
}
}
void deleat (players* p,int n,int jersy)
{
	int i,a;
	for(i=0;i<n;i++)
	{
		if(p[i].jersey_no==jersy)
		{
			printf("\n jersy number is %d at position %d we are deleating",jersy,i+1);
			n=n-1;
			for(a=i;a<n;a++)
			p[a]=p[a+1];
		}
		else if (i==n-1)
		printf("\n jersy number %d is not found!!",jersy);
	}
	printf("\n Record of remaning players\n");
	display(p,n);
}
int max_run(players* p,int n)
{
	int max_rn=0,i,a=0;
	for(i=0;i<n;i++)
	{
		if(p[i].runs>max_rn)
		{
			max_rn=p[i].runs;
			a=i;
		}
	}
	printf("\n Details of player who gets maximum runs\n");
	return a;
}
int max_wkt(players* p,int n)
{
	int max_wkt=0,i,j=0;
	for(i=0;i<n;i++)
	{
		if(p[i].wickets>max_wkt)
		{
			max_wkt=p[i].runs;
			j=i;
		}
	}
	printf("\n details of player who gets maximum wickets\n");
	return j;
}
void add_player(players* p,int* n)
{
	int i,j,num;
	printf("\n How many players you want to add:");
	scanf("%d",&num);
	i=*n;
	*n=*n+num;
	for(j=i;j<(*n);j++)
	{
		printf("\n Information of New added player:");
		fflush(stdin);
		printf("\nName of player:");
		gets(p[j].name);
		printf("Enter your Gender:");
		gets(p[j].gender);
		printf("Total matches played:");
		scanf("%d",&p[j].matches);
		fflush(stdin);
		printf("Enter the name of your Team:");
		gets(p[j].team);
		printf("Enter jesry number:");
		scanf("%d",&p[j].jersey_no);
		printf("Number of runs:");
		scanf("%d",&p[j].runs);
		printf("Number of wickets:");
		scanf("%d",&p[j].wickets);
		printf("Enter your Age: ");
		scanf("%d",&p[j].age);
		fflush(stdin);
		printf("Enter your birth date:\n");
		scanf("%d",&p[j].dob.day);
		scanf("%d",&p[j].dob.month);
		scanf("%d",&p[j].dob.year);
		fflush(stdin);
		printf("\n------------------------------------------------");
	}
}







