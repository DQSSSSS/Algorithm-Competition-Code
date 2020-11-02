#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

void build(int f,int t) {
	cout << f << " " << t << endl;
}
int n,k;
set<pair<int,int> > s;

int main() {
    n = read(),k = read();
    s.insert(make_pair(0,0));
    for(int i = 1;i <= n;i ++) {
		int x = read();
		set<pair<int,int> > :: iterator it = s.lower_bound(make_pair(x - 1,i));
		it --;
		build(it -> second,i);
		s.insert(make_pair(x,i));
    }
	return 0;
}
