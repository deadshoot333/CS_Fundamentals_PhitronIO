#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        while(n!=0)
        {
            int letter=n%10;
            if(letter==1)
            {
                printf("A");
            }
            else if(letter==2)
            {
                printf("B");
            }
            else if(letter==3)
            {
                printf("C");
            }
            else if(letter==4)
            {
                printf("D");
            }
            else if(letter==5)
            {
                printf("E");
            }
            else if(letter==6)
            {
                printf("F");
            }
            else if(letter==7)
            {
                printf("G");
            }
            else if(letter==8)
            {
                printf("H");
            }
            else if(letter==9)
            {
                printf("I");
            }
        n/=10;
        }
       printf("\n"); 
    }
}