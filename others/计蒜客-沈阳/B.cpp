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

int pr[SZ];

bool isnum(char c) {
	return '0' <= c && c <= '9';
}

int get_pri(char c) {
    if(c == '+' || c == '-') return 1;
    if(c == '*') return 2;
    if(c == 'd') return 3;
    if(c == '(' || c == ')') return 4;
}
///(1d5-4*(1+2))

pii work(pii ans,pii now,char lstc) {
    /*if(ans == make_pair(1e10,1e10) || now == make_pair(1e10,1e10)) {
        if(ans == make_pair(1e10,1e10) && now == make_pair(1e10,1e10)) return make_pair(0,0);
        if(ans == make_pair(1e10,1e10)) {

		}
    }*/
	if(lstc == '+') ans.first += now.first,ans.second += now.second;
	if(lstc == '-') ans.first -= now.second,ans.second -= now.first;
	if(lstc == '*') {
		int a = ans.first * now.first,b = ans.second * now.first;
		int c = ans.first * now.second,d = ans.second * now.second;
		ans.first = min(min(a,b),min(c,d));
		ans.second = max(max(a,b),max(c,d));
	}
	if(lstc == 'd') {
		int x = ans.first,y = ans.second;
		int z = now.first,w = now.second;
		x = max(x,0); y = max(y,0);
		z = max(z,1); w = max(w,1);
		ans.first = x * 1; ans.second = y * w;
	}
	return ans;
}

char s[SZ];

pii dfs(int l,int r) {
	//if(l > r) return make_pair(1e10,1e10);
	while(l <= r && s[l] == '(' && s[r] == ')' && pr[r] == l) l ++,r --;
	//cout << l << " " << r << " "; for(int i = l;i <= r;i ++) cout << s[i]; puts("");
    int minpri = 233;
    for(int i = l,d = 0;i <= r;i ++) {
    	char c = s[i];
    	if(isnum(c)) continue;
    	if(c == '(') d ++;
    	if(c == ')') d --;
    	if(d) continue;
		minpri = min(minpri,get_pri(c));
    }
    if(minpri == 233) {
		int x = 0;
		for(int i = l;i <= r;i ++) x = x * 10 + s[i] - '0';
		return make_pair(x,x);
    }
 //  	cout << minpri << endl;
    pii ans = make_pair(0,0);
    char lstc = 0;
    for(int i = l,lst = l,d = 0;i <= r;i ++) {
    	char c = s[i];
    	if(c == '(') d ++;
    	if(c == ')') d --;
    	if(d) continue;
        if(i == r || (!isnum(s[i]) && get_pri(s[i]) == minpri)) {
            int L = lst,R = i == r ? r : i - 1; lst = i + 1;
            //while(L <= R && !isnum(s[L])) L ++;
            //while(L <= R && !isnum(s[R])) R --;
       //     cout << "haha " << L << " " << R << endl;
            //if(L > R) continue;
            pii now = dfs(L,R);
            if(lstc == 0) ans = now;
            else {
				ans = work(ans,now,lstc);
            }
            //int p = i;
            //while(p <= r && !isnum(s[p]) && get_pri(s[p]) == -1) p ++;
            //if(p > r || isnum(s[p])) continue;
            lstc = s[i];
        }
    }
    //cout << l << " " << r << " " << ans.first << " " << ans.second << endl;
   // for(int i = l;i <= r;i ++) cout << s[i]; puts("");
    return ans;
}

stack<int> S;

int main() {
    while(~scanf("%s",s + 1)) {
		int n = strlen(s + 1);
        for(int i = 1;i <= n;i ++) pr[i] = 0;
        for(int i = 1;i <= n;i ++) {
        	char c = s[i];
            if(c == '(') S.push(i);
            if(c == ')') {
                pr[i] = S.top(); S.pop();
            }
        }
        pii a = dfs(1,n);
        printf("%lld %lld\n",a.first,a.second);
    }
    return 0;
}
/**
(1d5-2*(1+2))d(1-2d3)d(1+2)
*/
