#include<stdio.h>
int freq[26];
int main()
{
    int n;
    scanf("%d",&n);
    char s[n];
    scanf("%s",s);
    for(int i=0;i<n;i++)
    {
        freq[s[i]-'a']++;
    }
    int count=0;
    for(int i=0;i<26;i++)
    {
        if(freq[i]==1)
        {
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}