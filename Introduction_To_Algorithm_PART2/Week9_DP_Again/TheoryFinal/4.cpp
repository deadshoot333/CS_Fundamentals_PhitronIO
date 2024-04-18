#include <bits/stdc++.h>
#define int long long
using namespace std;
void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int32_t main()
{

    FastIO();
    int n, target;
    cin >> n >> target;
    int a[n];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(mp.count(target-a[i]))
        {
            cout<<i+1<<" "<<mp[target-a[i]]<<"\n";
            return 0;
        }
        mp[a[i]]=i+1;
    }
    cout<<"IMPOSSIBLE\n";
}