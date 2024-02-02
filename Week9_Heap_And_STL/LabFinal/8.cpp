#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
public:
    vector<int> nodes;
    void up_heapify(int index)
    {
        while (index > 0 && nodes[index] > nodes[(index - 1) / 2])
        {
            swap(nodes[index], nodes[(index - 1) / 2]);
            index = index - 1 / 2;
        }
    }
    void down_heapify(int index)
    {
        while (1)
        {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            if (left < nodes.size() && nodes[largest] < nodes[left])
            {
                largest = left;
            }
            else if (right < nodes.size() && nodes[largest] < nodes[right])
            {
                largest = right;
            }
            if (largest != index)
            {
                swap(nodes[index], nodes[largest]);
                index = largest;
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
        up_heapify(nodes.size() - 1);
    }
    void Delete(int index)
    {
        if (index > nodes.size() - 1)
        {
            return;
        }
        swap(nodes[index], nodes[nodes.size() - 1]);
        nodes.pop_back();
        down_heapify(index);
    }
    int getMax()
    {
        if (nodes.empty())
        {
            return rand();
        }
        return nodes[0];
    }
    void PrintHeap()
    {
        for (auto it : nodes)
        {
            cout << it << " ";
        }
        cout << "\n";
    }
};
class MinHeap
{
public:
    MaxHeap mx;
    void insert(int x)
    {
        mx.Insert(-1 * x);
    }
    void Delete(int idx)
    {
        mx.Delete(idx);
    }
    int getMin()
    {
        return -1 * mx.getMax();
    }
};

int main()
{
    MinHeap mn;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mn.insert(x);
    }
    cout << "\n";
    for (int i = 0; i < mn.mx.nodes.size(); i++)
    {
        cout << -1 * mn.mx.nodes[i] << " ";
    }
    cout << "\nAfter Deleting 3rd index\n";
    mn.Delete(3);
    for (int i = 0; i < mn.mx.nodes.size(); i++)
    {
        cout << -1 * mn.mx.nodes[i] << " ";
    }
    cout << "\nThe minimum value : " << mn.getMin();
    cout << "\n";
}