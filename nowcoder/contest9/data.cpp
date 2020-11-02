#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 300010;
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

const int B = 2;

void randstr(int n) {
	for(int i = 1;i <= n;i ++)
		cout << (char)(rand() % B + 'a');
	puts("");
}

int main() {
	freopen("haha.txt","w",stdout);
	srand(time(0));
    int n = 4;
    cout << n << endl;
    int len = 1e5 / 4;
	for(int i = 1;i <= n;i ++)
		randstr(len);
	for(int i = 1;i <= 1e5;i ++) {
		int x = rand() % (B + 1);
		char c;
		if(x == B) c = '-';
		else c = x + 'a';
		cout << c;
	}
}
