#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
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

set<int> s;

int main() {
    int n = read();
    LL ans = 1;
    int posl = -1,posr = -1;
    for(int i = 1;i <= n;i ++) {
		char opt[22];
        int x;
        scanf("%s",opt);
		x = read();
        if(opt[1] == 'D') {
            s.insert(x);
        }
        else {
        	bool flag = 0;
            if(posr != -1) {
            	set<int> :: iterator it = s.find(posr);
            	if(it != s.end()) {
            		if(*it < x) { puts("0"); return 0; }
            		if(*it == x) flag = 1;
            	}
            	else posr = -1;
            }
            if(posl != -1) {
                set<int> :: iterator it = s.find(posl);
            	if(it != s.end()) {
            		if(*it > x) { puts("0"); return 0; }
                    if(*it == x) flag = 1;
            	}
            	else posl = -1;
            }
            set<int> :: iterator it = s.find(x);
            s.erase(x);
            if(!flag) (ans *= 2) %= mod;
            if(!s.size()) { posl = posr = -1; continue; }
            it = s.lower_bound(x);
            if(it == s.end()) posr = -1; else posr = *it;
           	if(*s.begin() < x) {
				it --;
				posl = *it;
			}
			else posl = -1;
        }
    }
   	LL t = 1;
    for(set<int> :: iterator it = s.begin();it != s.end();it ++) {
        int x = *it;
        if((posl == -1 || x > posl) && (posr == -1 || x < posr))
            t ++;
    }
    (ans *= t) %= mod;
	cout << ans << endl;
    return 0;
}
/**
10
ADD 1
ADD 2
ADD 4
ADD 8
ADD 9
ACCEPT 4
ACCEPT 8
ACCEPT 9
ADD 3
ADD 4

*/
