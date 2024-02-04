#include<bits/stdc++.h>
using namespace std;

void deleteValue(list<int>&l,int value)
{
  for(auto i=l.begin();i!=l.end();i++)
  {
    if(*i==value)
    {
        l.erase(i);
        break;
    }
  }  
}
int main()
{
    list<int>l;
    l.push_back(7);
    l.push_back(3);
    l.push_back(8);
    l.push_back(4);
    l.push_back(5);
    l.push_back(4);
    cout<<"Before removing = ";
    for(auto i=l.begin();i!=l.end();i++)
    {
        cout<<*i<<" ";
    }
    int value=4;
    deleteValue(l,value);
    cout<<"\nAfter removing = ";
    for(auto i=l.begin();i!=l.end();i++)
    {
        cout<<*i<<" ";
    }
}