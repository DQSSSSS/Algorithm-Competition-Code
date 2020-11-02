#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 5e5 + 10;
const int mod = 1e9 + 7;
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

map<string,bool> ban;
map<string,int> mp;
map<pair<string,string>,int> strpair;
string words[SZ];

bool isAlpha(char c) { return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'); }
char tolower(char c) {
    if(c >= 'a' && c <= 'z') return c;
    return c - 'A' + 'a';
}

char s[4010][4010];

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) {
        fgets(s[i],INF,stdin);
    }
    int m = read();
    for(int i = 1;i <= m;i ++) {
        char s[22];
        scanf("%s",s);
        string S = s;
        ban[S] = 1;
    }

    for(int i = 1;i <= n;i ++) {
        int len = strlen(s[i]);
        for(int j = 0;j < len;j ++) {
            if(!isAlpha(s[i][j])) s[i][j] = ' ';
            else s[i][j] = tolower(s[i][j]);
        }
    }

    string lst = "";

    int sum1 = 0,sum2 = 0;

    for(int i = 1;i <= n;i ++) {
        int len = strlen(s[i]);
        for(int j = 0;j < len;j ++) {
            if((j == len - 1 && isAlpha(s[i][j]))|| (isAlpha(s[i][j]) && !isAlpha(s[i][j+1])) ) {
                int k = j;
                while(k > 0 && isAlpha(s[i][k-1])) k --;
                string w;
                for(int l = k;l <= j;l ++) w += s[i][l];
                if(ban[w]) continue;
                mp[w] ++;
                sum1 ++;
                if(lst.length()) {
                    strpair[make_pair(lst,w)] ++;
                    sum2 ++;
                }
                lst = w;
            }
        }
    }

    int q = read();
    while(q --) {
        char s1[22],s2[22];
        scanf("%s%s",s1,s2);
        string ss1 = s1,ss2 = s2;

        double pa = 1.0 * mp[ss1] / sum1;
        double pb = 1.0 * mp[ss2] / sum1;
        double pab = strpair[make_pair(ss1,ss2)];
        if(ss1 != ss2) pab += strpair[make_pair(ss2,ss1)];
        pab /= sum2;
        printf("%.10f\n",pab/pa/pb);
    }
}
