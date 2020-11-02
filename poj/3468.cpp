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

LL tree[5][SZ],a[SZ];
int n,m;

void add(LL tree[],int x,LL d) {
    for(int i = x;i <= n;i += i & -i)
    	tree[i] += d;
}

LL ask(LL tree[],int x) {
	LL ans = 0;
	for(int i = x;i > 0;i -= i & -i)
        ans += tree[i];
    return ans;
}

LL askSum(int x) {
	return (x + 1) * ask(tree[1],x) - ask(tree[2],x);
}

LL askSum(int l,int r) {
    return askSum(r) - askSum(l - 1);
}

int main() {
    n = read(),m = read();
    for(int i = 1;i <= n;i ++) {
		a[i] = read();
        add(tree[1],i,a[i] - a[i - 1]);
        add(tree[2],i,i * (a[i] - a[i - 1]));
    }
    for(int i = 1;i <= m;i ++) {
    	char opt[2];
    	scanf("%s",opt);
		int l = read(),r = read();
		if(opt[0] == 'Q') {
			printf("%lld\n",askSum(l,r));
		}
		else {
			LL d = read();
            add(tree[1],l,d); add(tree[1],r + 1,-d);
            add(tree[2],l,l * d); add(tree[2],r + 1,-(r + 1) * d);
		}
    }
    return 0;
}
