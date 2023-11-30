###https://codeforces.com/group/MWSDmqGsZm/contest/219856/problem/S?fbclid=IwAR1qi6o8WBDOrdzcZ--U5YO_40SSQmmLbZ8jggB6CFIRqog1ukVL_Z2wK2s
input=input()
ans=""
currSub=""
leftCount=0
rightCount=0
count=0
ans_List=[]
for i in input:
    if i=='L':
        leftCount+=1
        currSub+=i
    if i=='R':
        rightCount+=1
        currSub+=i
    if leftCount==rightCount:
        ans+=currSub
        ans_List.append(ans)
        currSub=""
        leftCount=0
        rightCount=0  
        ans=""
print(len(ans_List))
for i in ans_List:
    print(i)