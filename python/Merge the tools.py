def merge_the_tools(s, k):
    # your code goes here
    n = len(s)
    t = ""

    for i in range(n):
        if s[i] not in t :
            t += s[i];
        if (i+1)%k == 0:
            print(t)
            t = ""
        

if __name__ == '__main__':
    string, k = input(), int(input())
    merge_the_tools(string, k)
