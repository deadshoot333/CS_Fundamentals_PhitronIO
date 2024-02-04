#include<bits/stdc++.h>
using namespace std;
class PostFix
{
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
    public:
    string infixToPostfix(string input)
    {
        stack<int>s;
        string ans;
        for(int i=0;i<input.size();i++)
        {
            if(input[i]>='0' && input[i]<='9')
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
        return ans;
    }
};
int calulate(string postfix)
{
    stack<int>s;
    int result;
    for(int i=0;i<postfix.size();i++)
    {
        if(postfix[i]>='0'&& postfix[i]<='9')
        {
            s.push(postfix[i]-'0');
        }
        else if(postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='*'||postfix[i]=='/')
        {
            int op2=s.top();
            s.pop();
            int op1=s.top();
            s.pop();
            switch(postfix[i])
            {
                case '+':
                {
                    result=op1+op2;
                    break;
                }
                case '-':
                {
                    result=op1-op2;
                    break;
                }
                case '/':
                {
                    result=op1/op2;
                    break;
                }
                case '*':
                {
                    result=op1*op2;
                    break;
                }
            }
            s.push(result);
        }
    }
    return s.top();
}
int main()
{
    string input;
    cin>>input;
    PostFix p;  
    cout<<calulate(p.infixToPostfix(input))<<"\n";
}
