
def gcd(a,b):
    return a if(b == 0) else gcd(b,a%b)

T = int(input())
for cc in range(1,T+1):
    n,m = map(int,input().split())
    a = [int(x) for x in input().split()]
    ans = []
    words = set()
    for i in range(0,m-1):
        if(a[i] != a[i+1]):
            x = gcd(a[i],a[i+1])
            words.add(x)
            words.add(int(a[i]/x))
            words.add(int(a[i+1]/x))
        
            
    id = -1
    for i in range(0,m-1):
        if(a[i] != a[i+1]):
            id = i
            break

    x = gcd(a[id],a[id+1])
    words.add(x)
    for i in range(0,id+1):
        words.add(int(a[0] / x))
        x = int(a[0] / x)
    y = x
    x = gcd(a[id],a[id+1])
    for i in range(id+1,m):
        #print(str(a[i]) + " " + str(x))
        words.add(int(a[i] / x))
        x = int(a[i] / x)
    
    ans.append(y)
    for i in range(0,m):
        ans.append(int(a[i] / y))
        y = int(a[i] / y)
        
    words = list(words)
    words.sort()
    wordslist = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

    #print(words)
    #print(len(words))
    #print(wordslist)
    #print(len(wordslist))
    #print(ans)

    #for i in range(0,26):
    #    print(wordslist[i] + " " + str(words[i]))

    s = "Case #%d: " %cc
    for x in ans:
        for i in range(0,len(words)):
            if(words[i] == x):
                s += wordslist[i]
                break
    print(s)

    
