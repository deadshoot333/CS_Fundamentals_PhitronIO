def foo(n,i):
    if i==1:
        return 0
    ans=pow(n,i)
    return ans+foo(n,i//2)
def foo1(n,i):
    s=0
    for j in range(2,i+1,2):
        s+=n**j
    return s
temp_x,temp_n=input().split()
x=int(temp_x)
n=int(temp_n)
if n==0:
    print(0)
elif n%2==1:
    print(foo1(x,n))
else:
    print(foo1(x,n))
##print(foo1(x,n))