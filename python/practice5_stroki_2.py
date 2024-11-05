n=[int(i) for i in input().split(" ")]
s=input()
words=[]
for i in range(n[0]-n[1]):
    w=s[i:n[1]+i]
    print(w)
    if w not in words:
        words.append(w)
print(len(words),words)
