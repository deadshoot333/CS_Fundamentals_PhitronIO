#include<bits/stdc++.h>
using namespace std;
int prec(char a)
{
    if(a=='+'||a=='-')
    {
        return 1;
    }
    else if(a=='*'||a=='/')
    {
        return 2;
    }
    return 0;
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
        else if(input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/')
        {
            
            {
                while(!s.empty() && prec(s.top())>=prec(input[i]))
                {
                    ans+=s.top();
                    s.pop();
                }
                s.push(input[i]);
            }
        }
        else if(input[i]=='(')
        {
            s.push(input[i]);
        }
        else if(input[i]==')')
        {
            while(!s.empty() && s.top()!='(')
            {
                ans+=s.top();
                s.pop();
            }
            s.pop();
        }
    }
    while(s.size())
    {
        ans+=s.top();
        s.pop();
    }
    cout<<ans<<"\n";
}