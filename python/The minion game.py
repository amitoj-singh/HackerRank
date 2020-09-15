def minion_game(string):
    # your code goes here
    l = len(string)
    # print(l);
    stuart = 0
    kevin = 0
    vowels = ['A','E','I','O','U']
    for i in range(l):
        pos = l-i
        if (string[i] in vowels):
            kevin += pos
        else:
            stuart += pos
    
    if (stuart > kevin):
        print("Stuart", stuart)
    elif (kevin > stuart):
        print("Kevin", kevin)
    else:
        print("Draw")


if __name__ == '__main__':
    s = input()
    minion_game(s)
