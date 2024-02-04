#include<stdio.h>
#include<stdbool.h>
bool countPrime(int n)
{
    int count=0;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            count++;
        }
    }
    if(count==2)
    {
        return true;
    }
    return false;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        for(int i=l;i<=r;i++)
        {
            if(countPrime(i) || i==1)
            {
                printf("%d ",i);
            }
        }
        printf("\n");
    }
}