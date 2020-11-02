#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 4e5 + 10;
const int mod = 998244353;
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

bool isend(string s,string t) {
    for(int i = 0;i < t.length();i ++)
        if(s[s.length()-(t.length()-i)] != t[i])
            return false;
    return true;
}

int main() {
    int T = read();
    while(T --) {
        string s,ans;
        cin >> s;
        if(isend(s,"a"))
            ans = s.substr(0,s.length()-1),ans += "as";
        else if(isend(s,"i") || isend(s,"y"))
            ans = s.substr(0,s.length()-1),ans += "ios";
        else if(isend(s,"l"))
            ans = s.substr(0,s.length()-1),ans += "les";
        else if(isend(s,"n"))
            ans = s.substr(0,s.length()-1),ans += "anes";
        else if(isend(s,"ne"))
            ans = s.substr(0,s.length()-2),ans += "anes";
        else if(isend(s,"o"))
            ans = s.substr(0,s.length()-1),ans += "os";
        else if(isend(s,"r"))
            ans = s.substr(0,s.length()-1),ans += "res";
        else if(isend(s,"t"))
            ans = s.substr(0,s.length()-1),ans += "tas";
        else if(isend(s,"u"))
            ans = s.substr(0,s.length()-1),ans += "us";
        else if(isend(s,"v"))
            ans = s.substr(0,s.length()-1),ans += "ves";
        else if(isend(s,"w"))
            ans = s.substr(0,s.length()-1),ans += "was";
        else
            ans = s,ans += "us";
        cout << ans << endl;
    }
}
