#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 2e6 + 10;
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

LL work(const string &s) {
    int p;
    for(int i = 0;i < s.length();i ++) {
        if(s[i] == ' ') p = i;
    }
    string type;
    for(int i = 0;i < p;i ++) type += s[i];
    int d;
    if(type == "char" || type == "bool") d = 1;
    else if(type == "int" || type == "float") d = 4;
    else if(type == "long long" || type == "double") d = 8;
    else if(type == "__int128" || type == "long double") d = 16;
    int p2 = 0;
    for(int i = p+1;i < s.length();i ++) {
        if(s[i] == '[') { p2 = i; break; }
    }
    if(p2 == 0) return d;
    int t = 0;
    for(int i = p2+1;i < s.length();i ++) {
        if(s[i] != ']') {
            t = t * 10 + s[i] - '0';
        }
        else break;
    }
    return t * d;
}

int main(){
    int T = read(),cc = 0;
    while(T --) {
        int n = read();
        LL ans = 0;
        while(n --) {
            string s;
            char c = getchar();
            while(c != '\n') s += c,c = getchar();
            ans += work(s);
        }
       // cout << ans << endl;
        ans = (ans + 1023) / 1024;
        //ans = max(ans,1ll);
        printf("Case #%d: %lld\n",++ cc,ans);
    }
}

