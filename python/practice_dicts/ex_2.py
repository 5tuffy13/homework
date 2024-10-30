n = int(input())
s=""
for i in range(n):
    s+=input()+" "
s=s.split(" ")[:-1]
data = {}
for item in enumerate(s):
    data[item[1]]=s.count(item[1])
srt = sorted(data.items(), key=lambda item: (-item[1], item[0]))
print(srt)
