#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 2e5 + 10;
const LL mod = 1e9 + 7;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

char s[333];
mt19937 rd((19990323ll<<16ll)|19990408ll);

char get(int x) {
    vector<int> a;
    a.resize(5);
    int t = 0;
    while(x) a[t++]=x%3,x/=3;
    if(a[4] == 2) return 'P';
    else if(a[4] == 1) return 'I';
    else {
        if(a[0] == 2) return 'R';
        if(a[1] == 2) return 'L';
        if(a[2] == 2) return 'D';
        if(a[3] == 2) return 'U';

        if(a[0] == 1 && a[3] == 1) return 'D';//"LD"[rd()%2];
        if(a[0] == 1 && a[2] == 1) return 'L';//"LU"[rd()%2];
        if(a[1] == 1 && a[2] == 1) return 'U';//"RU"[rd()%2];
        if(a[1] == 1 && a[3] == 1) return 'R';//"RD"[rd()%2];

        if(a[0] == 1) return 'D';//"UDL"[rd()%3];
        if(a[1] == 1) return 'U';//"UDR"[rd()%3];
        if(a[2] == 1) return 'L';//"LRU"[rd()%3];
        if(a[3] == 1) return 'R';//"LRD"[rd()%3];

        if(a[0] == 0) return 'D';//"UDL"[rd()%3];
        if(a[1] == 0) return 'U';//"UDR"[rd()%3];
        if(a[2] == 0) return 'L';//"LRU"[rd()%3];
        if(a[3] == 0) return 'R';//"LRD"[rd()%3];

        return "UDLR"[rd()%4];
    }
}

int main() {
    for(int i = 0;i < 243;i ++) {
        s[i] = get(i);
    }
    cout << s;
}
