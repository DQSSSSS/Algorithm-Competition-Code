#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9+7;
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

int readg() {
    int a,b;
    scanf("%d.%d",&a,&b);
    return a*10+b;
}

LL h[SZ],a[SZ],lsh[SZ],hid[SZ];

double ask(int l,LL y,bool f) {
    int r = l + 1;
    if(h[r] == h[l]) {
        if(f) return r;
        else return l;
    }
    return 1.0*(y-h[r])*(r-l)/(h[r]-h[l])+r;
}

int main() {
    int n = read(),k = read();
    for(int i = 0;i <= n;i ++) a[i] = read();
    while(k --) {
        int g = readg();
        for(int i = 0;i <= n;i ++) {
            h[i] = a[i] - 1ll * i * g;
        }
        //for(int i = 0;i <= n;i ++) cout << h[i] << endl;

        lsh[0] = 0;
        for(int i = 0;i <= n;i ++) {
            lsh[++ lsh[0]] = h[i];
        }
        sort(lsh+1,lsh+1+lsh[0]);
        lsh[0] = unique(lsh+1,lsh+1+lsh[0])-lsh-1;
        vector<vector<int> > add,del;
        add.resize(lsh[0]+1);
        del.resize(lsh[0]+1);
        for(int i = 0;i <= n;i ++) {
            hid[i] = lower_bound(lsh+1,lsh+1+lsh[0],h[i])-lsh;
        }
        for(int i = 0;i < n;i ++) {
            if(h[i] <= h[i+1]) {
                add[hid[i]].push_back(i);
                del[hid[i+1]].push_back(i);
            }
            else {
                add[hid[i+1]].push_back(i);
                del[hid[i]].push_back(i);
            }
        }

        vector<int> maxid,minid;
        maxid.resize(lsh[0]+1);
        minid.resize(lsh[0]+1);
        set<int> S;
        for(int i = 1;i <= lsh[0];i ++) {
            for(int x : add[i]) S.insert(x);//printf("%d add:%d\n",i,x);
            maxid[i] = *prev(S.end());
            minid[i] = *S.begin();
            for(int x : del[i]) S.erase(x);//printf("%d del:%d\n",i,x);
        }

      //  for(int i = 1;i <= lsh[0];i ++) cout << maxid[i] << " "; puts("");
      //  for(int i = 1;i <= lsh[0];i ++) cout << minid[i] << " "; puts("");


        double ans = -1;
        for(int i = 0;i <= n;i ++) {
            double tmpr = -1, tmpl = -1;
            if(maxid[hid[i]] > i) tmpr = ask(maxid[hid[i]],h[i],1) - i;
            if(minid[hid[i]] < i-1) tmpl = i - ask(minid[hid[i]],h[i],0);
           // printf("%d %.10f\n",i,tmpr);
            ans = max(ans,max(tmpl, tmpr));
        }
        for(int i = 0;i < n;i ++) if(h[i] == h[i+1]) ans = max(ans,1.0);
        for(int i = 0;i < n;i ++) {
            if(h[i] < h[n]) ans = max(ans,n-i*1.0);
        }
        if(ans < 0) puts("-1");
        else printf("%.10f\n",ans);
    }
}
/*
3 233
0 30 30 0
3.0
2.0
-2.0

2
233
0 100000 200000
100.0

3 233
0 10 -20 -1
0.0

5 1
2 0 1 0 1 0
0.0


5 1
1 0 1 0 1 -1
0.0

5 1
0 0 -1 -3 -4 -7
0.0

1 1
0 0
0.0

2 1
0 0 0
0.0
*/
