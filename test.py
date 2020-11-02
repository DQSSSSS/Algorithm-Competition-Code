import math

a = 1
b = 1
cnt = 2
while 233:
    cnt += 1
    c = a + b
    if(len(str(c)) >= 1000): break
    a = b
    b = c

print cnt
