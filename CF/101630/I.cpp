#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
const int INF = 1073741823 + 10;
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

struct haha {
    int l,r;
};

bool operator <(haha a,haha b) {
    return a.l<b.l;
}

set<haha> s;

int id[SZ],e[SZ],o[SZ];
char b[SZ];

int ee[SZ];
int oo[SZ];
int tot = 0;

char ask(int x,int y) {
    printf("? %d %d\n",x,y); fflush(stdout);
    char s[3];
    scanf("%s",s);
    tot ++;
    //assert(tot <= 300000);
    //s[0] = ee[x] < oo[y] ? '<' : '>';
    return s[0];
}


int main() {
    int n = read();
   /* for(int i = 1;i <= (n/2);i ++) ee[i] = i*2;
    for(int i = 1;i <= n-(n/2);i ++) oo[i] = i*2-1;
    random_shuffle(ee+1,ee+1+n/2);
    random_shuffle(oo+1,oo+1+n-n/2);*/

    int nji = (n+1)/2,nou = n/2;
    s.insert((haha){1,nou});
    for(int i = 1;i <= nou;i ++) id[i] = i;
    for(int i = 1;i <= nji;i ++) {
        vector<haha> a;
        for(haha p : s) a.push_back(p);
        int l = 0,r = a.size();
        while(r-l>1) {
            int mid = l + r >> 1;
            if(ask(id[a[mid].l],i) == '<') l = mid;
            else r = mid;
        }
        bool flag = 0,one = 0,two = 0;
        for(int k = l;k < min((int)a.size(),l + 2);k ++) {
            haha p = a[k];
            int dy = 0,xy = 0;
            for(int j = p.l;j <= p.r;j ++) {
                b[j] = ask(id[j],i);
                if(b[j] == '>') dy ++;
                else xy ++;
            }
            if(xy == 0) one = 1;
            else if(dy == 0) two = 1;
            else {
                vector<int> zuo,you;
                for(int j = p.l;j <= p.r;j ++) {
                    if(b[j] == '<') zuo.push_back(id[j]);
                    else you.push_back(id[j]);
                }
                o[i] = (p.l + zuo.size() - 1) * 2 + 1;
            //    printf("--- %d %d\n",i,o[i]);
                s.erase(p);
                s.insert((haha){p.l,p.l+zuo.size()-1});
                s.insert((haha){p.l+zuo.size(),p.r});
                for(int j = p.l,k = 0;k < zuo.size();k ++,j ++) {
                    id[j] = zuo[k];
                }
                for(int j = p.l+zuo.size(),k = 0;k < you.size();k ++,j ++) {
                    id[j] = you[k];
                }
                flag = 1;
                break;
            }
        }
        if(!flag) {
            if(one) o[i] = 1;
            else o[i] = n;
        }
       // cout << l << endl;
       // printf("%d %d %d %d %d\n",i,o[i],flag,one,two);
    }

    for(int i = 1,j = 2;i <= nou;i ++,j += 2) e[id[i]] = j;

    printf("! ");
    for(int i = 1;i <= nou;i ++) printf("%d ",e[i]);
    for(int i = 1;i <= nji;i ++) printf("%d ",o[i]);

   /* puts("");
    for(int i = 1;i <= nou;i ++) printf("%d ",ee[i]);
    for(int i = 1;i <= nji;i ++) printf("%d ",oo[i]);
    puts("");*/

   /* for(int i = 1;i <= nou;i ++) assert(e[i] == ee[i]);
    for(int i = 1;i <= nji;i ++) assert(o[i] == oo[i]);
    cout << tot << endl;*/
}
/**
10 4 8 6 2 1 5 7 9 3

4 2|10 8 6

6 4 8 10 2 1 5 4 4 3
*/
