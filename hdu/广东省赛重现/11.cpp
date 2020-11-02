#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
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

char s[22][11];

int get(string str) {
    int ans = 0;
    for(int i = 1;i <= 14;i ++) {
        string a = s[i];
        if(a == str) ans ++;
    }
    return ans;
}

bool c1() {
    if(get("1s")&&get("1p")&&get("1w"))
        if(get("9s")&&get("9p")&&get("9w")) {
            string ss[] = {"dong","nan","xi","bei","zhong","fa","bai"};
            for(int i = 0;i < 7;i ++)
                if(!get(ss[i])) return false;
            return true;
        }
    return false;
}

bool isNum(char c) {
    return c >= '0' && c <= '9';
}

bool c2() {
    string ss[] = {"s","p","w"};
    for(int i = 0;i < 3;i ++) {
        bool flag = 0;
        for(int j = 1;j <= 14;j ++) {
            if(isNum(s[j][0]) && s[j][1] != ss[i][0])
                flag = 1;
        }
        if(flag) continue;
        string one = "1"; one += ss[i];
        string nine = "9"; nine += ss[i];
        string two = "2"; two += ss[i];
        string eight = "8"; eight += ss[i];
        if(get(one)>=3 && get(nine)>=3 && get(two) && get(eight))
            return true;
    }
    return false;
}

int main() {
    for(int i = 1;i <= 14;i ++)
        scanf("%s",s[i]);
    if(c1()) puts("shisanyao!");
    else if(c2()) puts("jiulianbaodeng!");
    else puts("I dont know!");
}
