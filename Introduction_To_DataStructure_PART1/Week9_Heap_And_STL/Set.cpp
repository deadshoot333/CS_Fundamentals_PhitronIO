// In set values are distinct are always in sorted order
#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<int> st;
    //Insert O(logN)
    st.insert(5);
    st.insert(3);
    st.insert(7);
    st.insert(5);
    st.insert(4);
    for(auto i:st) // method to print set
    {
        cout<<i<<" ";
    }
    cout<<"\n";
    for(auto it=st.begin();it!=st.end();it++)// printing using pointer
    {
        cout<<*it<<" ";
    }
    cout<<"\nSet size = "<<st.size()<<"\n";
    cout<<"5 Erased\n";
    st.erase(5);//O(logN)
    for(auto i:st) // method to print set
    {
        cout<<i<<" ";
    }
    cout<<"\n";
    //Find O(logN)
    if(st.find(7)!=st.end())  //{3,4,7}<-- set.end() is the last iterator of the set after the last element which indicates nothing
    {
        cout<<"7 found\n";
    }
    else
    {
        cout<<"7 not found\n";
    }
    if(st.find(5)==st.end())
    {
        cout<<"5 not found\n";
    }
    else
    {
        cout<<"5 Found\n";
    }
}