from itertools import groupby

ls = input()

for group, items in groupby(ls):
    X = str(len(list(items)))
    result = '(' + X + ', ' + group + ')'
    print(result, end=" ")
