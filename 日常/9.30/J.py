n = int(raw_input());
import math;
ans = math.factorial(n - 2);
for i in range(1,n + 1):
    x = int(raw_input())
    ans = ans / math.factorial(x - 1);
print ans;
