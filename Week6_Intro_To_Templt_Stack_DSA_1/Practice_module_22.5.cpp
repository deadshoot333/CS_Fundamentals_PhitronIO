#include<bits/stdc++.h>
using namespace std;
bool cmp(const int & value)
{
    return value==0;
}
void deleteZero(list<int>&l)
{
    l.remove_if(cmp);
}
int main()
{                                                 //answer to the question no:3
    list<int>l;
    l.push_back(0);                                  ///https://docs.google.com/document/d/1CI5PpnXD-JSXFFY6U32TQQ-ot7CrSF5nAspEHTigWmw/edit 
    l.push_back(5);
    l.push_back(4);
    l.push_back(0);
    l.push_back(0);
    l.push_back(1);
    l.push_back(0);
    deleteZero(l);
    for(auto it=l.begin();it!=l.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<"\n";
}