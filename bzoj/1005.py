n = int(raw_input());
d = [0] * 1010;
sum = 0;
import sys;
for i in range(1,n + 1):
    d[i] = input();
    if d[i] == -1:
        sum = sum + 1;
    else :
        if d[i] == 0 :
            print 0;
            sys.exit();
        
import math;
ans = math.factorial(n - 2);

rst = 0;
for i in range(1,n + 1):
    if d[i] != -1:
        ans = ans / math.factorial(d[i] - 1);
        rst = rst + d[i] - 1;
print ans / math.factorial(n - 2 - rst) * (sum ** (n - 2 - rst));
