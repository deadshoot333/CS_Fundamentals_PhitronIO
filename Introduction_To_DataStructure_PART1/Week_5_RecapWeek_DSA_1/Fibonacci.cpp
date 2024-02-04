#include<bits/stdc++.h>
using namespace std;

int Fibo(int i)
{
    if(i==0)
    {
        return 0;
    }
    if(i==1)
    {
        return 1;
    }
    return Fibo(i-1)+Fibo(i-2);
}
int main()
{
    int n;
    cin>>n;
    cout<<Fibo(n)<<"\n";
}