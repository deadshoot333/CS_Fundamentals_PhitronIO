#include<bits/stdc++.h>
using namespace std;
void print(list<int>&l)
{
    list<int>::iterator temp=l.begin();
    while(temp!=l.end())
    {
        cout<<*temp<<" ";
        temp++;
    }
    cout<<"\n";
}
void Insert(list<int>&l,int index,int value)
{
    list<int>::iterator temp=l.begin();
    advance(temp,index);
    l.insert(temp,value);
}
void remove(list<int>&l,int index)
{
    list<int>::iterator temp=l.begin();
    advance(temp,index);
    l.erase(temp);
}
int main()
{
    list<int>l;
    l.push_front(10);  //push_front is equivalent to insert at head
    l.push_front(20);
    l.push_front(30);
    print(l);
    l.push_back(40);
    l.push_back(50);   //push_back is equivalent to insert at tail
    print(l);
    l.pop_front();     //pop_front is equivalent to delete at head
    l.pop_back();      //pop_back is equivalent to delete at tail
    print(l);
    Insert(l,1,100);
    print(l);
    remove(l,1);
    print(l);
}