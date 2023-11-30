def max_operations(n, a): 
    count = 0
    while True: 
        if all(x % 2 == 0 for x in a): 
            count += 1
            a = [x // 2 for x in a] 
        else: 
            break
    return count
n = int(input())
a = list(map(int,input().strip().split()))[:n]
print(max_operations(n, a))
