#include<bits/stdc++.h>
using namespace std;
void FastIO()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}
int solve(int a[],int n)
{
    if(n==0)
    {
        return a[n];
    }
    return a[n]+solve(a,n-1);
}
int main()
{ 
     
    FastIO();
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }   
    cout<<solve(a,n-1);
}