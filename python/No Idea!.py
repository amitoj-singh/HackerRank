# Enter your code here. Read input from STDIN. Print output to STDOUT
n, m = input().split()
n = int(n)

arr = input().split()
A = set(input().split())
B = set(input().split())

happiness = 0

for i in range(n):
    if arr[i] in A:
        happiness += 1
    elif arr[i] in B:
        happiness -= 1

print(happiness)
