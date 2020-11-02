#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 500010;
const LL INF = 1e18;
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

char s[SZ];

int main() {
    freopen("3435.in","r",stdin);
    int t = 0;
    while(gets(s)) {
        int len = strlen(s);
        string ans;
        for(int i = 0;i < len;i ++) {
            if(i+1 < len) {
                if(s[i] == '*' && s[i+1] == '/') {
                    t = 0; i ++;
                }
                else if(s[i] == '/' && s[i+1] == '*') {
                    if(i+2<len&&s[i+2]=='/') {
                        if(!t) t=1;
                        else t=0;
                        i += 2;
                    }
                    else t = 1,i ++;
                }
                else if(s[i] == '/' && s[i+1] == '/') {
                    if(!t) break;
                }
                else {
                    if(!t) ans += s[i];
                }
            }
            else {
                if(!t) ans += s[i];
            }
        }
        if(ans.size() || (!t && len == 0)) ans += "\n";
        printf("%s",ans.c_str());
    }
}

/*/ /*/

