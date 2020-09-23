n = int(input())
lst = input().split()
k = int(input())
m = lst.count('a')
p = 1
for i in range(k):
    p *= (1-m/(n-i))
print(1-p)
