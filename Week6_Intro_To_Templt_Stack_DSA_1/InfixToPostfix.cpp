#include<bits/stdc++.h>
using namespace std;
int prec(char a)
{
    if(a=='+'||a=='-')
    {
        return 0;
    }
    return 1;
}
int main()
{
    stack<int>s;
    string input,ans;
    cin>>input;
    for(int i=0;i<input.size();i++)
    {
        if(input[i]>='a' && input[i]<='z')
        {
            ans+=input[i];
        }
        else
        {
            while(s.size() && prec(s.top())>=prec(input[i]))
            {
                ans+=s.top();
                s.pop();
            }
            s.push(input[i]);
        }
    }
    while(s.size())
    {
        ans+=s.top();
        s.pop();
    }
    cout<<ans<<"\n";
}