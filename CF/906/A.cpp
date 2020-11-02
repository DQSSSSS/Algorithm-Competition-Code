#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
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

int Not[33],maybe[33],ok;
char s[SZ];

int main() {
    int m = read(),sum = 0;
    for(int i = 0;i < 26;i ++) maybe[i] = 1;
    ok = -1;
    while(m --) {
        scanf("%s",s);
        if(s[0] == '!') {
            if(ok != -1) sum ++;
            scanf("%s",s);
            int n = strlen(s);
            int use[33] = {};
            int b[33] = {};
            for(int i = 0;i < n;i ++) {
                int c = s[i] - 'a';
                use[c] = 1;
            }
            for(int i = 0;i < 26;i ++) {
                if(use[i] && maybe[i]) b[i] = 1;
            }
            for(int i = 0;i < 26;i ++) maybe[i] = b[i];
        }
        else if(s[0] == '.') {
            scanf("%s",s);
            int n = strlen(s);
            for(int i = 0;i < n;i ++) {
                int c = s[i] - 'a';
                maybe[c] = 0;
            }
        }
        else if(s[0] == '?') {
            scanf("%s",s);
            int c = s[0] - 'a';
            if(ok != -1) {
                if(c == ok) break;
                else sum ++;
            }
            else {
                maybe[c] = 0;
            }
        }
        int ans = 0,t = 0;
        for(int i = 0;i < 26;i ++) {
            if(maybe[i]) t ++,ans = i;
        }
        if(t == 1) ok = ans;
      //  for(int i = 0;i < 26;i ++) printf("%d ",maybe[i]); puts("");
       // for(int i = 0;i < 26;i ++) printf("%d ",Not[i]); puts("");
    }
    cout << sum << endl;
}
