//{1,2,3,3,4,4} is a multi set values are sorted and not distinct
#include<bits/stdc++.h>
using namespace std;

int main()
{
    multiset<int>a;
    //Insert O(logN)
    a.insert(3);
    a.insert(5);
    a.insert(3);
    a.insert(2);
    a.insert(1);
    a.insert(4);
    a.insert(4);
    for(auto i:a)
    {
        cout<<i<<" ";
    }
    //multiset.erase(3) will delete all the occurence of 3
    a.erase(3);// erase all occurence
    a.erase(a.find(4));// delete the first occurence of 4 from the set find(4) returns an iterator and using the location 3 is deleted 
    // we cannot send a.end iterator to erase or it will crash
    cout<<"\n";
    for(auto i:a)
    {
        cout<<i<<" ";
    }

}