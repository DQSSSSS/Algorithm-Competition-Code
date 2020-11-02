#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-12;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

char s[SZ],s2[SZ];
char get(char a,char b) { return 'R'+'G'+'B'-a-b; }

int main() {
    int n = read(),ans = 0;
    scanf("%s",s + 1);
    for(int l = 1,r;l <= n;l = r + 1) {
        r = l;
        while(r <= n && s[l] == s[r]) r ++;
        r --;

        char c;
        if(l == 1 && r == n) {
            if(s[l] == 'R') c = 'G';
            else c = 'R';
        }
        else if(l == 1) c = get(s[l],s[r+1]);
        else if(r == n) c = get(s[l-1],s[l]);
        else if(s[l-1] == s[r+1]) c = get(s[l],s[r+1]);
        else c = s[l-1];
        int f = 0;
        for(int j = l;j <= r;j ++,f ^= 1) {
            if(f) s[j] = c,ans ++;
        }
    }
    cout << ans << endl;
    cout << s + 1 << endl;
}

