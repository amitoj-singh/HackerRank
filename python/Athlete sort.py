nm = input().split()
n = int(nm[0])
m = int(nm[1])

arr = []
for _ in range(n):
    arr.append(list(map(int, input().rstrip().split())))
    
k = int(input())

for i in range (n):
    for j in range (n - 1 - i):
        if arr[j][k] > arr[j+1][k]:
            temp = arr[j]
            arr[j] = arr[j+1]
            arr[j+1] = temp

for i in range (n):
    print(*arr[i])
