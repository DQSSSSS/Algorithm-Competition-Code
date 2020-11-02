#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

void print(int x) {
    for(int i = 31;i >= 0;i --)
        printf("%d",x >> i & 1);
}

LL a[SZ],sum[SZ];
map<LL,int> mp;

int main() {
	int n = 256,m = log2(n) + 1;
    a[1] = 0; mp[1] = 1;
    for(int i = 2;i <= n;i ++) {
        if(i * (i + 1) / 2 % 2 == 0)
	    	a[i] = a[i >> 1] + 1;
	    else
	    	a[i] = a[i >> 1] - 1;
	    mp[a[i]] ++;
    }
    for(int i = 0;i <= m;i ++) {
    	cout << i << endl;
    	int t = 0;
        for(int j = 1;j <= n;j ++)
            if(abs(a[j]) == i) {
            	t ++;
                printf("%6d ",j);
                print(j); puts("");
            }
        cout << t << endl;
        puts("");
    }
    /*cout << maxn <<endl;
	//for(int i = 1;i <= 100;i ++) cout << i << " " << i * (i + 1) / 2 % 2 << endl;
    for(int i = 1;i <= 1000000;i ++) sum[i] = sum[i - 1] + abs(a[i]);

	for(int i = 0;i <= 1000;i ++) cout << i << " " << a[i] << endl;

	puts("4k");
	for(int i = 0;i <= 1000;i += 4)
	    print(i),cout << " ",print(abs(a[i])),puts("");
	puts("4k+1");
	for(int i = 1;i <= 100;i += 4)
	    print(i),cout << " ",print(abs(a[i])),puts("");
	puts("4k+2");
	for(int i = 2;i <= 100;i += 4)
	    print(i),cout << " ",print(abs(a[i])),puts("");
	puts("4k+3");
	for(int i = 3;i <= 100;i += 4)
	    print(i),cout << " ",print(abs(a[i])),puts("");
	puts("");
	for(int i = 1;i <= 100;i ++)
	    print(i),cout << " ",print(abs(sum[i])),puts("");*/
}
