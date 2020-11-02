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

string name[5];
string words[5];

bool find(string a,string b) {
    for(int i = 1;i <= 4;i ++)
        if(name[i] == a && words[i] == b)
            return true;
    return false;
}

int main() {
    string a;
    while(cin >> a) {
        for(int i = 1;i <= 4;i ++) cin >> name[i] >> words[i];
        if(a == "RANK") {
            if(find("IMfather","Callmefather")) puts("father");
            else puts("hello");
        }
        else {
            if(find("IMfather","Callmefather")
               && find("girl","father")) puts("father");
            else puts("hello");
        }
    }
}


