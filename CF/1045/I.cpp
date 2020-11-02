#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

char input[SZ];
int a[100010];

unordered_map<int,int> b[2];

int main() {
	int n = read();
	for(int i = 1;i <= n;i ++) {
		scanf("%s",input);
		int len = strlen(input);
		for(int j = 0;j < len;j ++) {
			a[i] ^= 1 << (input[j] - 'a');
		}
		b[0][a[i]] ++;
	}
	LL ans = 0;
	for(unordered_map<int,int> :: iterator it = b[0].begin();it != b[0].end();it ++)
		ans += 1ll * it -> second * (it -> second - 1) / 2;
	for(int i = 0;i < 26;i ++) {
		b[0].clear(); b[1].clear();
		for(int j = 1;j <= n;j ++) {
			if(a[j] & (1 << i)) b[1][a[j] ^ (1 << i)] ++;
			else b[0][a[j]] ++;
		}
		for(unordered_map<int,int> :: iterator it = b[0].begin();it != b[0].end();it ++)
			ans += 1ll * it -> second * b[1][it -> first];
	}	
	cout << ans << endl;
	return 0;
}
