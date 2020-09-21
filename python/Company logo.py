import itertools

if __name__ == '__main__':
    s = input()
    hash = {}
    for x in s:
        if x not in hash:
            hash[x] = 1
        else:
            hash[x] += 1

    hash = {k : v for k, v in sorted(hash.items(), key=lambda item: item[0])}
    hash = {k : v for k, v in sorted(hash.items(), key=lambda item: item[1], reverse = True)}

    hash = dict(itertools.islice(hash.items(), 3))

    for x, y in hash.items():
        print(x, y)
