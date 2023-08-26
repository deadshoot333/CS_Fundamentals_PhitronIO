#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<char>s;
    string input;
    cin>>input;
    for(int i=0;i<input.size();i++)
    {
        if(input[i]=='('||input[i]=='{'||input[i]=='[')
        {
            s.push(input[i]);
        }
    }
    if(s.empty())
    {
        cout<<"NO\n";
        return 0;
    }
    for(int i=0;i<input.size();i++)
    {
        if(input[i]=='}' && s.top()=='{')
        {
            s.pop();
        }
        else if(input[i]==')' && s.top()=='(')
        {
            s.pop();
        }
        else if(input[i]==']' && s.top()=='[')
        {
            s.pop();
        }
    }
    if(!s.empty())
    {
        cout<<"NO\n";
    }
    else
    {
        cout<<"YES\n";
    }
}