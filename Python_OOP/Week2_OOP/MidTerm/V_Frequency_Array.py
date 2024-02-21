n,m=input().split()
n=int(n)
m=int(m)
a = list(map(int,input().strip().split()))[:n]
freq=[0]*(m+1)
for i in a:
    freq[i]=freq[i]+1
for i in range(1,m+1):
    print(freq[i])