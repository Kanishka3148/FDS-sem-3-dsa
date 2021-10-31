#include <stdio.h>

void prime(int,int);

int main(void) 
{
  int start,end;
  printf("Enter the start point: ");
  scanf("%d",&start);
  printf("Enter the end point: ");
  scanf("%d",&end);

  printf("The prime numbers are as follows:\n");
  prime(start,end);
}

void prime(int start,int end)
{
  int count;
  for(int i=start;i<=end;i++)
    {
      count=0;
      for(int j=1;j<=i;j++)
        {
            if(i%j==0)
            {
                count++;
            }
        }

            if(count==2)
            {
              printf("%d\n",i);
            }
            else
            {
              continue;
            }
            
    }
}
