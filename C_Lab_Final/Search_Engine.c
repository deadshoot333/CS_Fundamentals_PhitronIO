#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        int n;
        scanf("%d",&n);
        int a[n];
        int freq[1000];
        for(int i=0;i<1000;i++)
        {
            freq[i]=-1;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(freq[a[i]]!=-1)
            {
                continue;
            }
            freq[a[i]]=i+1;
        }
        int q;
        scanf("%d",&q);
            if(freq[q]!=-1)
            {
                printf("Case %d: %d\n",test,freq[q]);
            }
            else
            {
                printf("Case %d: Not Found\n",test);
            }
        
    }
    return 0;
}