k = input()
n = input()
l = 0; r = 1;
while(r**k <= n):
    l = r
    r = r * 2
while(r - l > 1):
    mid = (l + r) / 2
    if(mid**k <= n):
        l = mid;
    else:
        r = mid;
print l;
