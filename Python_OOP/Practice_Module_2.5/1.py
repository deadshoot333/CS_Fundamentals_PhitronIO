t=int(input())
for i in range(0,t):
    n=input()
#     if n==0:
#         print(f"{n}")
#     else:
#         while n!=0:
#             print(f"{n%10}",end=" ")
#             n//=10
#     print()
    for j in range(len(n)-1,-1,-1):
        print(f"{n[j]}",end=" ")
    print()

'''Solve these problems using Python
1. https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/Q
2. https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/S
3. https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/Y
4. https://codeforces.com/group/MWSDmqGsZm/contest/223205/problem/F
5. https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/Z
'''