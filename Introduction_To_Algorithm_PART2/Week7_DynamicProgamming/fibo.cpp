#include <bits/stdc++.h>
using namespace std;
int fibo(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    return fibo(n - 1) + fibo(n - 2);
}
// Time complexity O(2^n)
int main()
{
    cout << "Enter the nth number of fibonacchi series: ";
    int n;
    cin >> n;
    cout << fibo(n) << " ";
}