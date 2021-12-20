#include <stdio.h>
#include<string.h>
int n;
struct stu
{
  int rollno;
  char name[50];
  char divi[10];
  char add[50];
};

void accept(struct stu e[20],int n)
{
  for(int i=0;i<n;i++)
  {
    printf("Enter Student Roll No. ,Name ,Division and address: ");
    scanf("\n%d\n%s\n%s\n%s",&e[i].rollno,e[i].name,e[i].divi,e[i].add);
  }
  n++;
}
void writefile(struct stu e[20],int n)
{
  int i,ch;
  FILE *fp;
  fp=fopen("dataStudent.txt","a");

  if(fp==NULL)
  {
    printf("Error");
  }
  else
  {
    for(i=0;i<n;i++)
    {
      fprintf(fp,"%d %s %s %s \n",e[i].rollno, e[i].name, e[i].divi, e[i].add);

    }
  }
  fclose(fp);
}

void readfile(int n)
{
    FILE *fp;
    fp = fopen("dataStudent.txt", "r");
    struct stu std;
    if (fp == NULL)
    {
        printf("Error");
        return;
    }
    else 
    {
        for (int i = 0; i < n; i++)
        {
            fscanf(fp, "%d %s %s %s", &std.rollno, std.name, std.divi, std.add);
            fputs("\n", fp);
            printf("%d %s %s %s \n", std.rollno, std.name, std.divi, std.add);
        }
    }
    fclose(fp);
}

void search(int n)
{
  FILE *fp;
  fp=fopen("dataStudent.txt","r");
  struct stu students[20];
  if(fp==NULL)
  {
    printf("Error");
    return;
  }
  else
  {
    for(int i=0;i<n;i++)
    {
      fscanf(fp,"%d %s %s %s",&students[i].rollno,students[i].name,students[i].divi,students[i].add);
      fputs("\n",fp);
    }
  }
  fclose(fp);
  char name[20];
  printf("Enter the name of the student: ");
  scanf("%s",name);
  for(int i=0;i<n;i++)
  {
    if(strcmp(students[i].name,name)==0)
    {
      printf("%d %s %s %s",students[i].rollno,students[i].name,students[i].divi,students[i].add);
    }
  }
}

void delete_data()
{
  int m;
  FILE *fp;
  fp=fopen("dataStudent.txt","r");
  struct stu students[30];
  if(fp==NULL)
  {
    printf("Error");
    return;
  }
  else
  {
   m=0;
   while(fscanf(fp,"%d %s %s %s",&students[m].rollno,students[m].name,students[m].divi,students[m].add)!=EOF)
   {
     m++;
   }
  }
  fclose(fp);

  for(int i=0;i<m;i++)
  {
    printf("%d %s %s %s",students[i].rollno,students[i].name,students[i].divi,students[i].add);
    printf("\n");
  }
  printf("\n");
  char name[20];
  printf("Enter the name of the student: ");
  scanf("%s",name);
  FILE *fp2;
  fp2=fopen("dataStudent.txt","w");
  if(fp2==NULL)
  {
    printf("Error");
    return;
  }
  else
  {
    for(int i=0;i<m;i++)
    {
      if(strcmp(students[i].name,name)==0)
      {
        continue;
      }
      else
      {
     fprintf(fp,"%d %s %s %s",students[i].rollno,students[i].name,students[i].divi,students[i].add);
      }
    }
  }
  fclose(fp2);
  n--;
}

int main(void) {
  struct stu e[20];
  int choice;
  printf("Enter total number of students: ");
  scanf("%d",&n);
  here:printf("1.Accept data\n");
  printf("2.Write file\n");
  printf("3.Read file\n");
  printf("4.Search from file\n");
  printf("5.Delete from file\n");
  printf("6.Exit\n");
  printf("Enter your choice:");
  scanf("%d",&choice);
  switch(choice)
  {
  case 1:accept(e,n);
  printf("\n");
  goto here;

  case 2:writefile(e,n);
  printf("\n");
  goto here;

  case 3:readfile(n);
  printf("\n");
  goto here;

  case 4:search(n);
  printf("\n\n");
  goto here;

  case 5:delete_data();
  printf("\n");
  goto here;
  
  case 6:
  break;
  
  }
}