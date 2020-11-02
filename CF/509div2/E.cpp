#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200010;
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

struct haha {
	int f,t;
}l[SZ];

int n,a[SZ],b[SZ],t[SZ],edgetot = 0;
set<int> s;

bool check() {
	for(int i = 1;i < n;i ++) {
		if(a[i] != n) return false;
		if(a[i] == b[i]) return false;
	}
	sort(b + 1,b + n);
	for(int i = n - 1;i >= 1;i --) {
		t[b[i]] ++;
	}
	for(int i = n;i >= 1;i --) if(!t[i]) s.insert(-i);
	//for(int i = n - 1,tot = 0;i >= 1;i --) cout << b[i] << endl;
	for(int i = n - 1,tot = 0;i >= 1;i --) {
		tot ++;
		//cout << b[i] <<" haha " << i << " " << tot << endl;
		if(i == 1 || b[i - 1] != b[i]) {
			int now = n;
			while(tot --) {
				int newnode;
				//cout << i << " " << tot << endl;
				if(tot) {
					set<int> :: iterator it = s.lower_bound(-b[i]);
					if(it == s.end()) return false;
					newnode = -*it;
					s.erase(it);
				}
				else {
					newnode = b[i];
				}
				//cout << now << " " << newnode << endl;
				l[++ edgetot] = (haha){now,newnode};
				now = newnode;
			}
			tot = 0;
		}
	}	
	return true;
}

int main() {
	n = read();
	for(int i = 1;i < n;i ++) {
		a[i] = read(),b[i] = read();
		if(a[i] < b[i]) swap(a[i],b[i]);
	}
	if(!check()) puts("NO");
	else {
		puts("YES");
		for(int i = 1;i < n;i ++)
			printf("%d %d\n",l[i].f,l[i].t);
	}
}
