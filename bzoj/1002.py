n = input();
a = [0] * 200;
a[1] = 1;
for i in range(2,n + 1) :
    a[i] = 3 * a[i - 1] - a[i - 2] + 2
print a[n]
