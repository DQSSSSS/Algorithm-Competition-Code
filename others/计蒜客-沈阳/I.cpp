#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
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

int ask_num(char c) {
	if(c >= '0' && c <= '9') return c - '0';
	if(c >= 'a' && c <= 'z') c -= 32;
	return c - 'A' + 10;
}

map<string,char> mp;

char s[SZ],ans[SZ * 4];
bool zo[SZ * 4];

int main() {
	int T = read();
	while(T --) {
        int m = read(),n = read();
        mp.clear();
        for(int i = 1;i <= n;i ++) {
            int x = read();
            char s[22]; scanf("%s",s);
            string S = s;
            mp[S] = (char)x;
         //   cout << mp[S] << endl;
        }
        scanf("%s",s);
        int len = strlen(s),len2 = 0;
        for(int i = 0;i < len;i ++) {
            int x = ask_num(s[i]);
            zo[len2 ++] = x >> 3 & 1;
            zo[len2 ++] = x >> 2 & 1;
            zo[len2 ++] = x >> 1 & 1;
            zo[len2 ++] = x & 1;
        }
        int anslen = 0;
        for(int i = 0,t = 0;i < len2;i ++) {
            if(zo[i]) t ++;
            if((i + 1) % 9 == 0) {
                if(zo[i]) t --;
                if(t & 1 && zo[i] == 0) {
                    for(int j = i - 8;j < i;j ++) ans[anslen ++] = zo[j] + '0';
                }
                if(!(t & 1) && zo[i]) {
                	for(int j = i - 8;j < i;j ++) ans[anslen ++] = zo[j] + '0';
                }
                t = 0;
            }
        }
        //cout << ans << endl;
        string now = "";
        for(int i = 0,d = 0;i < anslen;i ++) {
            if(d == m) break;
            now += ans[i];
            if(mp[now]) printf("%c",mp[now]),now = "",d ++;
        }
		puts("");
	}
	return 0;
}
