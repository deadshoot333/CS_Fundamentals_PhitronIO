def solve(a=[]):
    elements={}
    for i in a:
        if i not in elements:
            elements[i]=0
        elements[i]+=1
    rmCount=0
    for count,i in elements.items():
        if count!=i:
            rmCount+=abs(count-i)
    return rmCount
n=int(input())
a=list(map(int,input().strip().split()))[:n]
result=solve(a)
print(result)
        
    

