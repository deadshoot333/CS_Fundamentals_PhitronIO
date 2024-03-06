#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[1000];

int fibo(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    if (a[n] != 0)
    {
        return a[n];
    }
    a[n] = fibo(n - 1) + fibo(n - 2);
    return a[n];
}
// Time complexity O(n)
int32_t main()
{
    cout << "Enter the nth number = ";
    int n;
    cin >> n;
    cout << fibo(n) << "\n";
}