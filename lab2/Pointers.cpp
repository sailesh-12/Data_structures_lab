#include<iostream>
#include<cstdlib>
#include<math.h>
using namespace std;

void PerfectNumber(int *num);//prototype for perfect Number
void Palindrome(int *num);//prototype for Palindrome Number
void ArmstrongNumber(int *num);//prototype for Armstrong number
int main()
{
    int *num=(int *)malloc(sizeof(int));
    *num=0;
    
    while(1)
    {
        printf("1.Perfect_Number\n2.Palindrome_checking\n3.Armstrong_Number_checking\n4.Exit\n");

        int *choice=(int *)malloc(sizeof(int));
        if(*choice==NULL)
        {
            printf("Failed to allocate memory");
        }

        printf("Enter a choice:\n");
        scanf("%d",choice);

        

        switch (*choice)
        {
        case 1:
            printf("Enter a number:\n");
            scanf("%d",num);
            PerfectNumber(num);
            break;
        case 2:
              printf("Enter a number:\n");
              scanf("%d",num);
              Palindrome(num);
              break;
        case 3:
              printf("Enter a number:\n");
              scanf("%d",num);
              ArmstrongNumber(num);
              break;
            
        case 4:
        printf("Thank you for visiting my Program");
            exit(1);
            break;
        }
    }
    


}

void PerfectNumber(int *num){
    int *temp=(int *)malloc(sizeof(int));
    if(*temp==NULL)
    {
            printf("Failed to allocate memory");
    }
    int *sum=(int *)malloc(sizeof(int));
    if(*sum==NULL)
    {
        printf("Failed to allocate memory");
    }
    *sum=0;
    int *i=(int *)malloc(sizeof(int));
    if(*i=NULL)
    {
        printf("Failed to allocate memory");
    }

    for(*i=1;(*i)<(*num);(*i)++)
    {
        if((*num)%(*i)==0)
        {
            *sum=*sum+*i;
        }
    }

    if(*sum==(*num))
    {
        printf("Yes the given number is a perfect Number\n");
    }else{
        printf("No it is not a perfect Number");
    }
}
void Palindrome(int *num)
{
    int *temp=(int *)malloc(sizeof(int));
    if(*temp==NULL)
    {
        printf("Failed to allocate memory");
    }
    int *rev=(int *)malloc(sizeof(int));
    if(*rev==NULL)
    {
            printf("Failed to allocate memory");
    }
    *rev=0;

    int *org=(int *)malloc(sizeof(int));
    if(*org==NULL)
    {
       printf("Failed to allocate memory");
    }
    *org=*num;
    while((*num)!=0)
    {
        *temp=(*num)%10;
        *rev=(*rev)*10+*temp;
        *num=(*num)/10;
    }
    if(*rev==(*org))
    {
        printf("Yes it is a Palindrome\n");
    }else{
        printf("No it is not a Palindrome\n");
    }

}
void ArmstrongNumber(int *num)
{
    int *temp=(int *)malloc(sizeof(int));
    if(*temp==NULL)
    {
        printf("Failed to allocate memory");
    }
    int *sum=(int *)malloc(sizeof(int));
    if(*sum==NULL)
    {
        printf("Failed to allocate memory");
    }
    int *org=(int *)malloc(sizeof(int));
    if(*org==NULL)
    {
            printf("Failed to allocate memory");
    }
    
    int *org1=(int *)malloc(sizeof(int));
    if(*org1==NULL)
    {
            printf("Failed to allocate memory");
    }
    *org=*num;
    *org1=*num;

    int *count=(int *)malloc(sizeof(int));
    if(*count==NULL)
    {
            printf("Failed to allocate memory");
    }
    *count=0;
    while((*num)!=0)
    {
        *temp=(*num)%10;
        *count=*count+1;
        *num=(*num)/10;
    }
    
    while((*org)!=0)
    {
        *temp=(*org)%10;
        *sum=*sum+pow(*temp,*count);
        *org=(*org)/10;

    }
    if((*sum)==*org1)
    {
        printf("Yes the given number is an Armstrong number\n");
    }
    else{
        printf("No the given number is not an Armstrong number\n");
    }
   
    
}