
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 100010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}


int main()
{
    int a,b;
    cin >> a >> b;
    cout << a = b <<endl;
    return 0;
}
/*
1
4 10 2 2333
1 2 1
1 2 0
1 2 2
2 3 0
2 3 0
2 3 3
3 4 0
3 4 1
3 4 3
1 4 50
*/
