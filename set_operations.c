#include <stdio.h>
int SIZE;
void accept(int *ptr);
void display(int *p,int n);
int Union(int *p,int *q,int *un);
void intersection(int *a,int *b);
int difference(int *a,int *b,int *d);
void symdiff(int *p,int *q);

int main(void)
{
  int here;
  int choice;
  printf("Enter the size of both the arrays: ");
  scanf("%d",&SIZE);
  int a[SIZE],b[SIZE],n,u[SIZE],intersect[SIZE],diff[SIZE];
  

  printf("Enter set A elements ");
  accept(a);
  printf("Enter set B elements ");
  accept(b);
  printf("SET A:");
  display(a,SIZE);
  printf("\nSET B:");
  display(b,SIZE);
  here: printf("\n\n1.Union\n");
        printf("2.Intersection\n");
        printf("3.Difference A-B\n");
        printf("4.Difference B-A\n");
        printf("5.Symmetric difference\n");
        printf("6.End\n");
        printf("\nPlease select a choice number: ");
        scanf("%d",&choice);
  
switch(choice)
    {
        case 1: printf("\nThe union of two sets is: ");
        Union(a,b,u);
        goto here;
 
        case 2:  printf("\nThe intersection of two sets is: ");
        intersection(a,b);
        goto here;

        case 3: printf("\nThe Difference of A-B is: ");
        difference(a,b,diff);
        goto here;
      
        case 4: printf("\nThe Difference of B-A is: ");
        difference(b,a,diff);
        goto here;

        case 5: printf("\nThe symmetric difference is: ");
        symdiff(a,b);
        goto here;

        case 6: printf("*****The program ends here*****");
        break;
 
        default:printf("Please enter valid choice");;
        goto here;
 
  return 0;
}
}

void accept(int *ptr)
{
  for (int i = 0; i < SIZE; i++)
  {
        scanf("%d", ptr+i);
  }
}

void display(int *p,int n)
{
  printf("{");
  for (int i = 0; i < n; i++)
  {
        printf("%d\t", *(p+i));
  }
  printf("}");
}

int Union(int *p,int *q,int *un)
{
int j;
int k=0;
for(int i=0;i<SIZE;i++)
{
 *(un+k)=*(p+i);
 k++;
}
for(int i=0;i<SIZE;i++)
{
  for(j=0;j<SIZE;j++)
  {
    if(q[i]==p[j])
    break;
  }
  if(j==SIZE)
  {
  *(un+k)=*(q+i);
  k++;
  }
}
display(un,k);
return 0;
}

void intersection(int *a,int *b)
{
int k=0;
int i=0;
int j=0;
printf("{");
for(i = 0;i < SIZE;i++)
{
    for(j = 0;j < SIZE;j++)
    {
      if(b[i] == a[j])
        {
          k = 1;
        }
    }
       if(k == 1)
        {
        
          printf("%d\t ", b[i]);
          
        }
          k= 0;
  }
  printf("}");
}

int difference(int *a,int *b,int *d)
{
  int i,j,k;
  i=j=k=0;
  for(i=0;i<SIZE;i++)
  {
    for(j=0;j<SIZE;j++)
    {
      if(a[i]==b[j])
      {
        break;
      }
    }
  if(j==SIZE)
  {
    *(d+k)=*(a+i);
    k++;
  }
  }
  display(d,k);
  return 0;
}

void symdiff(int *p, int *q)
{
    int k = 0;
    int size = 0;
    int temp[2 * SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        k = 0;
        for (int j = 0; j < SIZE; j++)
        {
            if (p[i] != q[j])
            {
                k++;
            }
        }
        if (k == SIZE)
        {
            temp[size] = p[i];
            size++;
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        k = 0;
        for (int j = 0; j < SIZE; j++)
        {
            if (q[i] != p[j])
            {
                k++;
            }
        }
        if (k == SIZE)
        {
            temp[size] = q[i];
            size++;
        }
    }
    for (int i = size; i < 2 * SIZE; i++)
    {
        temp[i] = 0;
    }
    display(temp, size);
}
