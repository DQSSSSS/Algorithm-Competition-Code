#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 3e5 + 10;
const int mod = 1e9 + 7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a<'0'||a>'9') { if(a=='-') flag=1; a=getchar(); }
    while(a>='0'&&a<='9') { n=n*10+a-'0'; a=getchar(); }
    if(flag) n=-n;
    return n;
}

char s[SZ];

bool isyuan(char c) {
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}

int work() {
    int n = strlen(s);
    if(n == 1) return 1;
    int yuantot = 0;
    for(int i = 0;i < n;i ++) if(isyuan(s[i])) yuantot ++;
    if(yuantot && !isyuan(s[0])) return 0;
    if(!yuantot) return 1;
    if(yuantot == 1) {
        return n;
    }
    vector<int> g;
    for(int i = 1,j = 0;i < n;i ++) {
        if(isyuan(s[i])) {
            g.push_back(i-j);
            j=i;
        }
    }
    return g[g.size()/2];
}

int main() {
    while(~scanf("%s",s)) cout << work() << endl;
}
