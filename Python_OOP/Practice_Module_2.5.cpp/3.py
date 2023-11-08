def fibo(i):
    if(i==1):
        return 0
    if(i==2):
        print(i)
        return 1
    return fibo(i-1)+fibo(i-2)
def print_fibo(n):
    a=0
    b=1
    for i in range(3,n+1):
        c=a+b
        print(c,end=" ")
        a=b
        b=c
n=int(input())
if n==1:
    print("0")
else:
    print("0 1",end=" ")
    print_fibo(n)
    