t=int(input())
for i in range(0,t):
    x,y=input().split()
    temp_x=int(x)
    temp_y=int(y)
    ans=0
    if temp_x>temp_y:
        temp=temp_x
        temp_x=temp_y
        temp_y=temp 
    for j in range(temp_x+1,temp_y):
        if j%2==1:
            ans+=j
    print(ans) 