#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1e5 + 10;
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

int n,m;

multiset<int> card[210];
stack<int> S;

void init() {
	for(int i = 1;i <= n;i ++) card[i].clear();
	while(S.size()) S.pop();
}

void get_card(int id,int num) {
    while(S.size() && num --) {
        int x = S.top(); S.pop();
		card[id].insert(x);
    }
}

int fapai(int id,int x) {
	if(x == 2) return 233;
	if(card[id].empty()) return 233;
	if(x == 233) {
		multiset<int> :: iterator it;
		bool flag = 0;
		for(int i = 3;i <= 15;i ++) {
        	int x = i > 13 ? i - 13 : i;
            if(card[id].find(x) != card[id].end()) {
            	it = card[id].find(x);
            	break;
            }
        }
        int ans = *it;
        card[id].erase(it);
		return ans;
    }
    int now;
    if(x == 13) now = 1;
    else now = x + 1;
    if(card[id].find(now) == card[id].end()) {
		multiset<int> :: iterator it = card[id].find(2);
        if(it == card[id].end()) return 233;
		int ans = *it;
        card[id].erase(it);
		return ans;
    }
    else {
		multiset<int> :: iterator it = card[id].find(now);
		int ans = *it;
        card[id].erase(it);
		return ans;
    }
}

bool no_card(int id) {
	return card[id].empty();
}

int card_sum(int id) {
	int ans = 0;
    for(multiset<int> :: iterator it = card[id].begin();it != card[id].end();it ++)
    	ans += *it;
    return ans;
}

void print(int id) {
    for(multiset<int> :: iterator it = card[id].begin();it != card[id].end();it ++)
    	cout << *it << " ";
}

int a[233333];

int main() {
	freopen("in.txt","r",stdin);
	freopen("my.txt","w",stdout);
	int T = read(),cc = 0;
	while(T --) {
        n = read(),m = read();
        init();
		for(int i = 1;i <= m;i ++) {
            a[i] = read();
		}
		for(int i = m;i >= 1;i --) {
            S.push(a[i]);
		}
		for(int i = 1;i <= n;i ++)
            get_card(i,5);
        int now = 233,id = 0,winner,tot = 0;
        while(233) {
        	id ++;
        	if(id == n + 1) id = 1;
			if(tot == n - 1) {
                get_card(id,1);
				for(int i = id + 1;;i ++) {
					if(i == n + 1) i = 1;
					if(i == id) break;
					if(S.empty()) break;
					//cout << i << endl;
					get_card(i,1);
				}
				//	cout << id << " " << tot << endl;
	    	    //    for(int i = 1;i <= n;i ++) print(i),puts("");
				tot = 0;
				now = fapai(id,233);
				if(no_card(id)) { winner = id; break; }
				continue;
			}
		//	cout << id << " " << tot << endl;
          //  for(int i = 1;i <= n;i ++) print(i),puts("");
            int ncard = fapai(id,now);
            //cout << now << " " << id << " " << ncard << endl;
            if(no_card(id)) { winner = id; break; }
            if(ncard == 233) {
            	tot ++;
			}
            else {
                now = ncard;
            	tot = 0;
            }
        }
		printf("Case #%d:\n",++ cc);
        for(int i = 1;i <= n;i ++) {
        	if(winner == i) { puts("Winner"); continue; }
        	printf("%d\n",card_sum(i));
        }
	}
	return 0;
}
/**
1000
3 21
4 5 12 5 2 6 11 7 4 6 6 13 1 10 10 9 9 2 1 6 8
*/
