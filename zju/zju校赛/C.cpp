#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 2e5 + 10;
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

char s[255],mp[2010][2010];
vector<vector<pii> >  opt;
vector<pii> tmp;

int get(int x,int y) {
    return 3*3*3*3*(mp[x][y]-'0')+
        3*3*3*(mp[x-1][y]-'0')+
        3*3*(mp[x+1][y]-'0')+
        3*(mp[x][y-1]-'0')+mp[x][y+1]-'0';
}

int main() {
    int T = read();
    while(T --) {
        int n = read(),m = read();
        int a = read(),b = read();
        LL k = read();
        scanf("%s",s);
        for(int i = 1;i <= n;i ++)
            scanf("%s",mp[i]+1);
        tmp.clear(); tmp.resize(m+1); opt.clear();
        for(int i = 0;i <= n+1;i ++) opt.push_back(tmp);

        int ans = 0;
        int pos = ans;
        while(k --) {
            int id = get(a,b);
            if(s[id] == 'P' && mp[a][b] == '2') {
                ans ++;
                pos = ans;
                mp[a][b] = '0';
            }
            else {
                if(opt[a][b].first == id && opt[a][b].second == pos) break;
                opt[a][b] = make_pair(id,pos);
                switch(s[id]) {
                    case 'U' : if(mp[a-1][b] != '1') a--; break;
                    case 'D' : if(mp[a+1][b] != '1') a++; break;
                    case 'L' : if(mp[a][b-1] != '1') b--; break;
                    case 'R' : if(mp[a][b+1] != '1') b++; break;
                    default : break;
                }
            }
        }
        printf("%d\n",ans);
    }
}

/**
2
5 5
2 4 1000000000000000000
RUPIRPIUDDLRUDRURLIIURDLPRDLDIRLIDPPRRRLLULPRPUPPDPRIUIUDLULIRIDIRPUPPIRRLRLULUPLRIIRLPRLLRLDLLPDRUUDLDPRRPLLPPUIUUPPLUIILLDRIDILDRRUPLPPLPDLDPDDUPIPPUIILIPLUPLURRPIIDDPPIUPRPRIRDRPPIUIRDUUUPPPDIIRPURIUIUIPLRILLDPPPURPPRRPDPRRLUDUDUDUPRLIUIRLR
11111
12021
10101
12021
11111
*/
