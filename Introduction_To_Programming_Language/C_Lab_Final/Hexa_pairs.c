#include<stdio.h>
int GCD(int a,int b)
{
    int gcd;
    for(int i=1;i<=a,i<=b;i++)
    {
        if(a%i==0 && b%i==0)
        {
            gcd=i;
        }
    }
    return gcd;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        int count=0;
        scanf("%d",&n);
        int a[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(GCD(a[i],a[j])==1)
                {
                    count++;
                }
            }
        }
        printf("%d\n",count*2);
    }
    return 0;

}