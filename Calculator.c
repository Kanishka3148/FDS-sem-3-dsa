#include<stdio.h>
#include<math.h>
int main()
{
    char operator;
    int x;
    float a,b,c,n,here;
    float i,fact=1.0;
    do{
       printf("SPECIFY THE OPERATOR(+,-,*,/,^,!)");
       scanf(" %c",&operator);
    
    if(operator=='!')
    {
        printf("ENTER A NUMBER");
        scanf("%f",&n);
    }
    else
    {
        printf("ENTER TWO NUMBERS\n");
        scanf("%f%f",&a,&b);
    }
    switch(operator)
    {
        case '+': c=a+b;
        printf("%f",c);
        goto here;
 
        case '-': c=a-b;
        printf("%f",c);
        goto here;

        case '*': c=a*b;
        printf("%f",c);
        goto here;
 
        case '/': c=a/b;
        printf("%f",c);
        goto here;
 
        case '^': c=pow(a,b);
        printf("power is %f",c);
        goto here;
 
        case '!':
        for(i=1.0;i<=n;i++)
        {
            fact=fact*i;
        }
        printf("fact is %f",fact);
        goto here;
        default:printf("please enter valid operator");
        goto here;

        here: printf("\ndo u want to continue??put 1 for yes and 0 for no");
        scanf("\n%d",&x);
    }
  }while(x!=0);
    return 0;
}
