def f(n,s):
    words=[]
    for i in range(n[0]-n[1]):
        w=s[i:n[1]+i]
        if w not in words:
            words.append(w)
    return (len(words))
n=[int(i) for i in input().split(" ")]
s=input()
print(f(n,s))
