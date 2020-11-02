a = [0] * 2010
b = [0] * 1010
a[1] = 2; a[2] = 12;
b[1] = 6; b[2] = 84;

for i in range(3,2001):
    a[i] = a[i - 1] * 6 - a[i - 2]

for i in range(3,1001):
    b[i] = b[i - 1] * 14 - b[i - 2]

m = (int)(raw_input())

ans = 0

for i in range(1,2001):
    if a[i] >= m:
        ans = a[i];
        break;

for i in range(1,1001):
    if b[i] >= m:
        if(b[i] < ans):
            ans = b[i]
        break;
print ans
