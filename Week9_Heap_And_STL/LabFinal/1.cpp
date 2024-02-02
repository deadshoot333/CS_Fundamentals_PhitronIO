#include<bits/stdc++.h>
using namespace std;
vector<string>merge_sort(vector<string>&a)
{
	if(a.size()<=1)
	{
		return a;
	}
	int mid=a.size()/2;
	vector<string>b;
	vector<string>c;
	for(int i=0;i<mid;i++)
	{
		b.push_back(a[i]);
	}
	for(int i=mid;i<a.size();i++)
	{
		c.push_back(a[i]);
	}
	vector<string>sorted_b=merge_sort(b);
	vector<string>sorted_c=merge_sort(c);
	int indx1=0;
	int indx2=0;
	vector<string>ans;
	for(int i=0;i<a.size();i++)
	{
		if(indx1==sorted_b.size())
		{
			ans.push_back(sorted_c[indx2]);
			indx2++;
		}
		else if(indx2==sorted_c.size())
		{
			ans.push_back(sorted_b[indx1]);
			indx1++;
		}
		else if(sorted_b[indx1]<sorted_c[indx2])
		{
			ans.push_back(sorted_b[indx1]);
			indx1++;
		}
		else 
		{
			ans.push_back(sorted_c[indx2]);
			indx2++;
		}
	}
	return ans;
}
int main()
{
    vector<string>s;
    int count;
    cin>>count;
    for (int i = 0; i < count; i++)
    {
        string x;
        cin>>x;
        s.push_back(x);
    }
    vector<string>result=merge_sort(s);   
    for (int i = 0; i < count; i++)
    {
        cout<<result[i]<<"   ";
        
    }
    cout<<"\n";
}