#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    map<string,int>mp;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        if (mp.count(s))
        {
            cout<<mp[s]<<"\n";
        }
        else
        {
            cout<<"-1\n";
        }
        mp[s]=i;
        
    }
    
}