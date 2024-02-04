//Queue is a linear data structure but Priority Queue is a non linear data structure
#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    public:
    vector<int>nodes;
    MaxHeap()
    {

    }
    int size()
    {
        return nodes.size();    
    }
    void up_heapify(int index) //up_heapify is bottom up
    {
        while(index>0 && nodes[index]>nodes[(index-1)/2])
        {
            swap(nodes[index],nodes[(index-1)/2]); //(index-1)/2 is the parent of index
            index=(index-1)/2;
        }
    }
    void down_heapify(int index) //Top to bottom
    {
        while(1)
        {
            int largest=index;
            int left=2*index+1;
            int right=2*index+2;
            if(left<nodes.size() && nodes[largest]<nodes[left])
            {
                largest=left;
            }
            if(right<nodes.size() && nodes[largest]<nodes[right])
            {
                largest=right;
            }
            if(largest!=index)
            {
                swap(nodes[index],nodes[largest]);
                index=largest;
            }
            else
            {
                break;
            }
        }
    }
    void Insert(int value)
    {
        nodes.push_back(value);
        up_heapify(nodes.size()-1);
    }
    void Delete(int index) // In Heap the targeted nodes get replaced by the last node and then the last node is removed
    {
        if(index>nodes.size()-1)
        {
            return;
        }
        swap(nodes[index],nodes[nodes.size()-1]);
        nodes.pop_back();
        down_heapify(index);
    }
    int getMax()
    {
        if(nodes.empty())
        {
            return rand();
        }
        return nodes[0];
    }
    int ExtractMax()
    {
        if(nodes.empty())
        {
            return rand();
        }
        int fetch=nodes[0];
        Delete(0);
        return fetch;
    }
    void BuildHeap(vector<int>&a)
    {
        this->nodes=a;
        int n=nodes.size();
        for(int i=n/2-1;i>=0;i--)
        {
            down_heapify(i);
        }
    }
    vector<int>HeapSort(vector<int>a)
    {
        this->BuildHeap(a);
        vector<int>result;
        for(int i=0;i<a.size();i++)
        {
            result.push_back(this->ExtractMax());
        }
        reverse(result.begin(),result.end());//it contains array in decending order so reversed it
        return result;
    }
    void PrintHeap()
    {
        for(auto it:nodes)
        {
            cout<<it<<" ";
        }
        cout<<"\n";
    }
};
class PriorityQueue
{
    public:
    MaxHeap m;
    void push(int x)
    {
        m.Insert(x);
    }
    void pop()
    {
        m.Delete(0);
    }
    int top()
    {
        return m.getMax();
    }
    int size()
    {
        return m.size();
    }
};
int main()
{
    // MaxHeap mxHP;
    // vector<int>a={1,2,3,4,10,9,8,7};
    // vector<int>Sorted_a=mxHP.HeapSort(a);
    // mxHP.BuildHeap(a);
    // mxHP.PrintHeap();
    // cout<<"\n";
    // for(int i=0;i<Sorted_a.size();i++)
    // {
    //     cout<<Sorted_a[i]<<" ";
    // }
    PriorityQueue pq;
    pq.push(10);
    pq.push(1);
    pq.push(2);
    pq.push(19);
    pq.push(6);
    pq.push(7);
    while(pq.size()!=0)
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    ///Priority Queue using STL
    priority_queue<int>p;
    p.push(10); 
    p.push(1); 
    p.push(2); 
    p.push(19); 
    p.push(6); 
    p.push(7); 
    cout<<"\n";
    while(p.size()!=0)
    {
        cout<<p.top()<<" ";
        p.pop();
    }
}