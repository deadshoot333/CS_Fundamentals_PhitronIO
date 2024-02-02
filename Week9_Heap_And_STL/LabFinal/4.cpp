#include <bits/stdc++.h>
using namespace std;
int main()
{
    string input;
    cin >> input;
    stack<char> s;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '(' || input[i] == '{' || input[i] == '[')
        {
            s.push(input[i]);
        }
        else
        {
            if (s.empty())
            {
                cout << "NO\n";
                return 0;
            }
            else if (input[i] == ')' && s.top() == '(')
            {
                s.pop();
            }
            else if (input[i] == '}' && s.top() == '{')
            {
                s.pop();
            }
            else if (input[i] == ']' && s.top() == '[')
            {
                s.pop();
            }
            else
            {
                cout << "NO\n";
                return 0;
            }
        }
    }
    if (!s.empty())
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
}