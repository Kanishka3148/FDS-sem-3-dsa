#include <stdio.h>
#include<string.h>
#include <stdlib.h>
int n;
struct cricket
{
char name[15], country[15], category[15];
int age, odi, twenty, batscore, wkts;
};

void bat_country(struct cricket a[]);
void bowl_country(struct cricket a[]);
void maxwickets(struct cricket a[]);
void display_one(struct cricket a[]);
void max_avg_score(struct cricket a[]);
int main()
{
struct cricket s[10];
int i, choice;
char cntry[15], nm[15];
printf("\n## C program to display the information about cricekt player##\n");
printf("\nEnter number of players ");
scanf("%d",&n);
printf("\nEnter data of %d players\n",n);
for(i=0;i<n;i++)
{
printf("Enter name of the player ");
scanf("%s", s[i].name);
printf("Enter age of the player ");
scanf("%d", &s[i].age);
printf("Enter country of the player ");
scanf("%s", s[i].country);
printf("Enter category of the player ");
scanf("%s", s[i].category);
printf("Enter Number of ODIs played ");
scanf("%d", &s[i].odi);
printf("Enter Number of International 20-20s played ");
scanf("%d", &s[i].twenty);
printf("Enter Average batting score ");
scanf("%d", &s[i].batscore);
printf("Enter Total number of wickets taken ");
scanf("%d", &s[i].wkts);
printf("\n");
}

do
{
printf("\n\nPerform following queries \n1) Number of batsman of a particular country \n");
printf("2) Number of bowlers of a particular country  \n");
printf("3) Bowler that has taken maximum no of wickets \n");
printf("4) Show a particular players entire -Display board information \n");
printf("5) Display player with maximum average batting score.\n");
printf("6) Exit \n");

printf("Enter you choice");
scanf("%d",&choice);

switch(choice)
{
  case 1: bat_country(s);
  break;

  case 2: bowl_country(s);
  break;

  case 3: maxwickets(s);
  break;

  case 4: display_one(s);
  break;

  case 5: max_avg_score(s);
  break;
}
}while(choice!=6);
}

void bat_country(struct cricket a[])
{
  int ctr;
  char cntry[15];
  ctr=0;
printf("\nEnter country to display number of batsman: ");
scanf("%s",cntry);
for(int i=0; i<n; i++)
{
if((strcmp(cntry,a[i].country)==0)&&(strcmp("batsman",a[i].category)==0))
ctr++;
}
printf("\nNumber of batsman of country %s = %d ", cntry,ctr);
}

void bowl_country(struct cricket a[])
{
  int i,ctr=0;
  char cntry[15];
printf("\nEnter country to display number of bowlers: ");
scanf("%s", cntry);
for(int i=0; i<n; i++)
{
if((strcmp(cntry,a[i].country)==0)&&(strcmp("bowler",a[i].category)==0))
{
printf("Name \tCountry \tCategory \tAge \tOdi \t20-20s \tBatscore \tWickets\n");
printf("%s \t\t%s \t\t%s \t\t%-6d ",a[i].name, a[i].country,a[i].category, a[i].age);
printf("\t%-4d \t%-4d \t%-4d \t\t%d\n",a[i].odi,a[i].twenty ,a[i].batscore, a[i].wkts);
ctr++;
}
}
printf("\nNumber of bowlers of country %s= %d\n", cntry,ctr);
}


void maxwickets(struct cricket a[])
{
int k=0;
int ctr=0;
int index=0;
for(int i=0; i<n; i++)
{
if(strcmp("bowler",a[i].category)==0)
{
if (a[i].wkts>ctr)

{
ctr=a[i].wkts;
index=i;
k++;
}
}
else
{
 k=0;
}
}
if(k!=0)
{
printf("\n Name of Bowler who has taken maximum no of wickets is %s\n", a[index].name);

for(int i=0; i<n; i++)
{
if(strcmp(a[index].name,a[i].name)==0)
{
printf("Name \tCountry \tCategory \tAge \tOdi \t20-20s \tBatscore \tWickets\n");
printf("%s \t\t%s \t\t%s \t\t%-6d ",a[i].name, a[i].country,a[i].category, a[i].age);
printf("\t%-4d \t%-4d \t%-4d \t\t%d\n",a[i].odi,a[i].twenty ,a[i].batscore, a[i].wkts);
}
}
}
else
{
  printf("No bowlers present");
}
}

void display_one(struct cricket a[])
{
char nm[15];
printf("\n Enter Name of player to display data ");
scanf("%s", nm);
for(int i=0; i<n; i++)
{
if(strcmp(nm,a[i].name)==0)
{
printf("Name \tCountry \tCategory \tAge \tOdi \t20-20s \tBatscore \tWickets\n");
printf("%s \t\t%s \t\t%s \t%-6d ",a[i].name, a[i].country,a[i].category, a[i].age);
printf("\t%-4d \t%-4d \t%-4d \t\t%d\n",a[i].odi,a[i].twenty ,a[i].batscore, a[i].wkts);
}
}
}

void max_avg_score(struct cricket a[])
{
int ctr=a[0].batscore;
int index=0;
for(int i=0; i<n; i++)
{
if(strcmp("batsman",a[i].category)==0)
{
if (a[i].batscore>ctr)
{
ctr=a[i].batscore;
index=i;
}
}
}
printf("\n Name of Batsman with highest average score is %s with score %d\n",a[index].name,ctr);
for(int i=0; i<n; i++)
{
if(strcmp(a[index].name,a[i].name)==0)
{
printf("Name \tCountry \tCategory \tAge \tOdi \t20-20s \tBatscore \tWickets\n");
printf("%s \t\t%s \t\t%s \t%-6d ",a[i].name, a[i].country,a[i].category, a[i].age);
printf("\t%-4d \t%-4d \t%-4d \t\t%d\n",a[i].odi,a[i].twenty ,a[i].batscore, a[i].wkts);
}
}
}