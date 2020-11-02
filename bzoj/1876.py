a = input()
b = input()
while(b != 0):
    t = a;
    a = b;
    b = t % b;
print a;
