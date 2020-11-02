#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
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

stack<int> S;
char s[SZ];

int main() {
    scanf("%s",s+1);
    int n = strlen(s+1),ans = 0;
    for(int i = 1;i <= n;i ++) {
        if(S.size() >= 2) {
            int x = S.top(); S.pop();
            int y = S.top(); S.pop();
            if(s[x] == s[y] && s[y] == s[i]) ans ++;
            else {
                S.push(y);
                S.push(x);
                S.push(i);
            }
        }
        else S.push(i);
    }
    cout << ans << endl;
}

/**
ABBBABBBABBBABBBABBBA
*/
