def f(s):
    if s[4]=='x' and s[1]=='+':
        return (int(s[0])+int(s[2]))
    
    elif s[4]=='x' and s[1]=='-':
        return (int(s[0])-int(s[2]))
    
    elif s[0]=='x' and s[1]=='+':
        return (int(s[4])-int(s[2]))
    
    elif s[0]=='x' and s[1]=='-':
        return (int(s[2])+int(s[4]))
    
    elif s[2]=='x' and s[1]=='+':
        return (int(s[4])-int(s[0]))
    else:
        return (int(s[0])-int(s[4]))

s=input()
print(f(s))
