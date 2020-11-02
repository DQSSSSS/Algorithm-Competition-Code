#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 200010;
const LL INF = 1e18 + 10;
const int mod = 1e9 + 7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

char s[SZ];
string S[SZ];
vector<string> str[SZ];

bool ispre(string a,string b) {
    for(int i = 0;i < min(a.size(),b.size());i ++) {
        if(a[i] != b[i]) return false;
    }
    return true;
}

bool issuf(string a,string b) {
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    //cout << a << " " << b << endl;
    return ispre(a,b);
}

int work() {
    int n = read();
    for(int i = 1;i <= n;i ++) {
        scanf("%s",s);
        S[i] = s;
    }
    for(int i = 1;i <= n;i ++){
        vector<string> v;
        for(int j = -1,lst = 0;j < (int)S[i].length();j ++) {
            if(j + 1 == S[i].length() || S[i][j + 1] == '*') {
                string ans = "";
                while(lst <= j) ans += S[i][lst ++]; lst ++;
                v.push_back(ans);
            }
        }
        str[i] = v;
    }
    string bg = "",ed = "";
    for(int i = 1;i <= n;i ++) {
        if(str[i][0].length() > bg.length())
            bg = str[i][0];
        int k = str[i].size();
        if(str[i][k-1].length() > ed.length())
            ed = str[i][k-1];
    }
    //cout << bg << " " << ed << endl;
    for(int i = 1;i <= n;i ++) {
        if(!ispre(bg,str[i][0]))
            return puts("*");
        int k = str[i].size();
        if(!issuf(ed,str[i][k-1]))
            return puts("*");
    }


    string ans = "";
    ans += bg;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j + 1 < str[i].size();j ++) {
            ans += str[i][j];
        }
    }
    ans += ed;
    printf("%s\n",ans.c_str());
}

int main() {
    int T = read(),cc = 0;
    while(T --) {
        printf("Case #%d: ",++ cc);
        work();
    }
}
