def solve(k,s):
    count=0
    for x in range(0,k+1):
        for y in range(0,k+1):
            if s-x-y>=0 and s-x-y<=k:
                    count+=1
    return count
k,s=input().split()
k=int(k)
s=int(s)
print(solve(k,s))
