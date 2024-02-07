//https://docs.google.com/document/d/1uOwt4eKdmrxpuYj7B_uwh8c_ejXJyFi99vrYZaCV3cc/edit
#include<bits/stdc++.h>
using namespace std;
void FastIO()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}
 
int main()
{ 
     
    FastIO();
    int n;
    cin>>n;
    int matrix[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>matrix[i][j];
        }
    }   
    vector<int>adj_list[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if (matrix[i][j])
            {
                adj_list[i].push_back(j);
            }
            
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<i<<": ";
        for(int j:adj_list[i])
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}