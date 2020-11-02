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

int t[3][3];
map<char,int> mp;
char s[SZ],biao[] = "RGB";

int main() {
    mp['R'] = 0;
    mp['G'] = 1;
    mp['B'] = 2;
    int n = read();
    scanf("%s",s + 1);
    for(int i = 1;i <= n;i ++) {
        t[i%3][mp[s[i]]] ++;
    }
    int ans = n;
    char Ans[3];
    for(int i = 0;i < 3;i ++)
        for(int j = 0;j < 3;j ++)
            for(int k = 0;k < 3;k ++) {
                if(i == j || j == k || i == k) continue;
                int tmp = n - t[0][i] - t[1][j] - t[2][k];
                if(tmp < ans) {
                    ans = tmp;
                    Ans[0] = biao[i];
                    Ans[1] = biao[j];
                    Ans[2] = biao[k];
                }
            }
    cout << ans << endl;
    for(int i = 1;i <= n;i ++) {
        putchar(Ans[i%3]);
    }
}
