T = int(input())
for t in range(T):

    n = int(input())
    ls = list(map(int, input().split()))

    i, j, result, top = 0, n-1, "Yes", -1

    while i <= j:
            
        if ls[i] < ls[j]:
            if (top != -1) and top < ls[j]:
                result = "No"
                break                
            top = ls[j]
            j -= 1
        else:
            if (top != -1) and top < ls[i]:
                result = "No"
                break
            top = ls[i]
            i += 1

    print(result)
