#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 2e5 + 10;
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

int c[SZ];
char a[SZ],b[SZ];

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) c[i] = read();
    scanf("%s",a+1);
    scanf("%s",b+1);
    vector<int> f,g,h;
    LL nn = 0;
    for(int i = 1;i <= n;i ++) {
        if(a[i] == '1' && b[i] == '0') {
            f.push_back(c[i]);
        }
        if(a[i] == '0' && b[i] == '1') {
            g.push_back(c[i]);
        }
        if(a[i] == '1' && b[i] == '1') {
            h.push_back(c[i]);
        }
        if(a[i] == '1') nn += c[i];
    }
    sort(h.begin(),h.end());
    reverse(h.begin(),h.end());
    LL sum = 1e18;
    for(int i = -1;i < (int)h.size();i ++) {
        if(i != -1) {
            f.push_back(h[i]);
            g.push_back(h[i]);
        }
        sort(f.begin(),f.end());
        reverse(f.begin(),f.end());
        sort(g.begin(),g.end());

        LL now = nn,ans = 0;
        for(int x : f) {
            now -= x;
            ans += now;
        }

        for(int x : g) {
            now += x;
            ans += now;
        }
        sum = min(sum,ans);
    }
    cout << sum << endl;
}
