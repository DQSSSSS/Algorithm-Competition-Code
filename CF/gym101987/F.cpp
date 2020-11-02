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

bool isAlpha(char c) {
    return c >= 'a' && c <= 'z';
}

bool isOpt(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

char s[1100];
int n;

bool iserror() {
    int t = 0,isalpha = 0,isopt = 0;
    for(int i = 1,f = 0;i <= n;i ++) {
        if(s[i] == ' ') continue;
        if(s[i] == '(') t ++,f = 1,isalpha = 0,isopt = 0;
        else if(s[i] == ')') {
            t --;
            if(t < 0) return true;
            if(isopt) return true;
            if(f) return true;
            f = 0;
        }
        else if(isAlpha(s[i])) {
           // cout << isalpha << endl;
            if(isalpha) return true;
            isalpha = 1;
            isopt = 0;
            f = 0;
        }
        else if(isOpt(s[i])) {
            //cout << i << " " << isopt << endl;
            if(isopt) return true;
            if(!isalpha) return true;
            isalpha = 0;
            isopt = 1;
            f = 0;
        }
    }
    if(t != 0) return true;
    if(isopt) return true;
    return false;
}

bool haveOpt(int l,int r) {
    int t = 0;
    for(int i = l;i <= r;i ++) {
        if(s[i] == ' ') continue;
        if(s[i] == '(') t ++;
        else if(s[i] == ')') t --;
        if(isOpt(s[i]) && t == 0) {
            return true;
        }
    }
    return false;
}

int dfs(int l,int r) {
    int t = 0,id = -1;
    for(int i = l,f = 0;i <= r;i ++) {
        if(s[i] == ' ') continue;
        if(s[i] == '(') t ++;
        else if(s[i] == ')') t --;
        if(isOpt(s[i]) && t == 0) {
            if(f) return 1;
            id = i;
            f = 1;
        }
    }
    //cout << l << " " <<r << " mid: " << id << endl;
    if(id == -1) return 1;

    int ll = l,lr = id - 1,rl = id + 1,rr = r;

    while(s[ll] == ' ') ll ++;
    while(s[lr] == ' ') lr --;

    if(ll != lr) {
        if(!haveOpt(ll,lr) && s[ll] == '(' && s[lr] == ')') {
            ll ++,lr --;
        }
        if(!haveOpt(ll,lr)) return 1;
        int d = dfs(ll,lr);
       // cout << ll << " " << lr << " " << d << endl;
        if(d) return 1;
    }

    while(s[rl] == ' ') rl ++;
    while(s[rr] == ' ') rr --;

    if(rl != rr) {
        if(!haveOpt(rl,rr) && s[rl] == '(' && s[rr] == ')') {
            rl ++,rr --;
        }
        if(!haveOpt(rl,rr)) return 1;

        int d = dfs(rl,rr);
       // cout << rl << " " << rr << " " << d << endl;
        if(d) return 1;
    }
    return 0;
}

int main() {
    gets(s+1);
        n = strlen(s + 1);
       // for(int i = 1;i <= n;i ++) printf("%3d",i); puts("");
       // for(int i = 1;i <= n;i ++) printf("%3c",s[i]); puts("");
        if(iserror()) puts("error");
        else {
            int ret = dfs(1,n);
            if(ret == 1) puts("improper");
            else puts("proper");
        }
    return 0;
}
/**
a + a
(b+( a+c )) + b
c + ((b) + a)
c+(a%/b)
x + ((y + z)
a b + (c + b)
x + y + z
((a+b)+(c+d))*(((a+b)+(c+d))%((a+b)+(c+d)))
*/
