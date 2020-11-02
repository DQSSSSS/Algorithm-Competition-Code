#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-8;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int a[22];
int bb[] = {1,4,2,3};

bool cmp(int a,int b) {
    a %= 4; b %= 4;
    return bb[a] > bb[b];
}

char get(int x) {
    if(x % 4 == 1) return 'A';
    if(x % 4 == 3) return 'B';
    if(x % 4 == 2) return 'C';
    if(x % 4 == 0) return 'D';
}

int main() {
    int n = read();
    a[1] = n;
    a[2] = n+1;
    a[3] = n+2;
    sort(a+1,a+4,cmp);
    cout << a[1] - n << " " << get(a[1]);
}
