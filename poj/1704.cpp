//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 1000010;
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

int a[SZ];

int main() {
	int T = read();
	while(T --) {
		int n = read();
        for(int i = 1;i <= n;i ++) {
            a[i] = read();
        }
        sort(a + 1,a + 1 + n);
        int ans = 0;
        for(int i = n;i >= 1;i -= 2)
			ans ^= a[i] - a[i - 1] - 1;
        if(ans) puts("Georgia will win");
        else puts("Bob will win");
	}
}
