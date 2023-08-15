#include<bits/stdc++.h>
using namespace std;
bool Pallindrome(string s,int start,int end)
{
    if(start>=end)
    {
        return true;
    }
    if(s[start]!=s[end])
    {
        return false;
    }
    
    return Pallindrome(s,start+1,end-1);
    
}
int main()
{
    string s;
    cin>>s;
    if(Pallindrome(s,0,s.size()-1))
    {
        cout<<s<<" is pallindrome\n";
    }
    else
    {
        cout<<s<<" is not pallindrome\n";
    }
    return 0;
}