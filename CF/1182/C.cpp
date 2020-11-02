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

string s[SZ];
char input[SZ];

int isv(char c) {
    if(c == 'a') return 0;
    if(c == 'e') return 1;
    if(c == 'i') return 2;
    if(c == 'o') return 3;
    if(c == 'u') return 4;
    return -1;
}

pair<int,int> get(char s[]) {
    int n = strlen(s);
    int t = 0,lc = 0;
    for(int i = 0;i < n;i ++) {
        char c = s[i];
        if(isv(c) != -1) t ++,lc = isv(c);
    }
    return make_pair(t,lc);
}

vector<int> mp[1000010][5];

struct haha {
    int a[2],b[2];
}a[SZ];

set<pii> S[2];


int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) {
        scanf("%s",input);
        s[i] = input;
        auto p = get(input);
        mp[p.first][p.second].push_back(i);
       // cout << p.first << " " << p.second << endl;
    }

    for(int i = 1;i <= 1e6;i ++) {
        vector<int> tmp;
        for(int j = 0;j < 5;j ++) {
            for(int k = 0;k+1 < mp[i][j].size();k += 2) {
                pii x = make_pair(mp[i][j][k],mp[i][j][k+1]);
                S[1].insert(x);
            }
            if(mp[i][j].size() % 2 == 1) {
                tmp.push_back(mp[i][j][mp[i][j].size()-1]);
            }
        }
        for(int k = 0;k+1 < tmp.size();k += 2) {
            pii x = make_pair(tmp[k],tmp[k+1]);
            S[0].insert(x);
        }
    }

    int ans = 0;
    while(1) {
        if(S[1].empty()) break;
        pii sec = *S[1].begin(); S[1].erase(S[1].begin());
        pii fst;
        if(S[0].size()) fst = *S[0].begin(),S[0].erase(S[0].begin());
        else if(S[1].size()) fst = *S[1].begin(),S[1].erase(S[1].begin());
        else break;
        ans ++;
        a[ans].a[0] = fst.first; a[ans].a[1] = sec.first;
        a[ans].b[0] = fst.second; a[ans].b[1] = sec.second;
    }

    printf("%d\n",ans);
    for(int i = 1;i <= ans;i ++) {
        printf("%s %s\n",s[a[i].a[0]].c_str(),s[a[i].a[1]].c_str());
        printf("%s %s\n",s[a[i].b[0]].c_str(),s[a[i].b[1]].c_str());
    }
}
