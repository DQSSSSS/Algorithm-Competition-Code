#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 2000010;
const int INF = 1e9 + 10;
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

const int N = 13,M = 17;

string s[20] = {
"#################",
"##### Bb?Gr######",
"##### ###########",
"#?RbR GgR?B??####",
"##### ###########",
"#?GrG BGR?????###",
"##### ###########",
"#?BgB G?G???Rb###",
"##### ###########",
"#   R RrG?B???Bg#",
"# ? G ###########",
"#P  B?RRRGGGBBB@#",
"#################"
};

int main() {
    freopen("C.out","w",stdout);
    puts("47095460");
    for(int i = 1;i <= 1e5/3+1;i ++) {
        printf("D\nW\nR\n");
    }
    for(int i = 1;i <= 1000;i ++) {
        string a = "WASD";
        printf("%c\n",a[rand()%4]);
    }
}
/*
BRBGGGGGBGRBBBGBGBGBGBGGBGGBBBBB
*/
