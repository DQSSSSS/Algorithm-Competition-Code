#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
typedef pair<int,LL> pil;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;

LL read(){
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
    int n = read();
    scanf("%s",s+1);
    string ans = "";
    for(int i = 1,lst = 1;i <= n;i ++) {
        if(i == n || s[i+1] != s[i]) {
            if(i-lst+1 > 1) {
                if(ans.size()%2==0) ans += s[i];
                else {
                    ans += s[i];
                    ans += s[i];
                }
            }
            else ans += s[i];
            lst=i+1;
        }
    }
    if(ans.size() & 1) ans.erase(ans.begin()+ans.size()-1);
    cout << n - ans.length() << endl;
    printf("%s",ans.c_str());
}
