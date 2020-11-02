#include<bits/stdc++.h>
using namespace std;

const int SZ = 1e6 + 10;
typedef long long LL;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a<'0'||a>'9') { if(a=='-') flag = 1; a = getchar(); }
    while(a>='0'&&a<='9') { n=n*10+a-'0'; a = getchar(); }
    if(flag) n=-n;
    return n;
}

struct haha {
    int num[SZ],ans;
    int delta;
    vector<int> S;

    void add(int x) {
        x -= delta; x += 2e5;
     //   printf("add %d\n",x);
        S.push_back(x);
        if(num[x]) ans --;
        else ans ++;
        num[x] ^= 1;
    }

    void del(int x) {
        x -= delta; x += 2e5;
     //   printf("del %d %d\n",x,num[x]);
        if(num[x]) num[x] = 0,ans --;
    }

    bool has(int x) {
        x -= delta; x += 2e5;
        return num[x]!=0;
    }

    int ask() {
        return ans;
    }

    void allAdd(int x) {
        delta += x;
    }

    void init() {
        for(int x : S) num[x] = 0;
        ans = 0;
        delta = 0;
        S.clear();
    }

}data;

vector<int> nodes[SZ];
int lsh[SZ],X[SZ],a[SZ],p[SZ],tmp[SZ];

int main() {
    int T = read();
    while(T --) {
        int n = read(),y0 = read();
        lsh[0] = 0;
        for(int i = 1;i <= n;i ++) {
            int x = read(),y = read();
            a[i] = abs(y-y0);
            X[i] = x;
            lsh[++ lsh[0]] = x-2;
            lsh[++ lsh[0]] = x-1;
            lsh[++ lsh[0]] = x;
            lsh[++ lsh[0]] = x+1;
            lsh[++ lsh[0]] = x+2;
            nodes[x].push_back(i);
        }
        sort(lsh+1,lsh+1+lsh[0]); lsh[0]=unique(lsh+1,lsh+1+lsh[0])-lsh-1;
        for(int i = 1;i <= lsh[0];i ++) p[i] = 0;

        data.init();
        for(int i = 1;i <= lsh[0];i ++) {
            p[i] = data.ask();
            for(int id : nodes[lsh[i]]) tmp[a[id]] ++;
            for(int id : nodes[lsh[i]])
                if(tmp[a[id]]) {
                    if(tmp[a[id]]==2||data.has(a[id]))
                        data.del(a[id]);
                    else
                        data.add(a[id]);
                    tmp[a[id]]=0;
                }
            data.allAdd(lsh[i+1]-lsh[i]);
        }
        data.init();
        for(int i = lsh[0];i >= 1;i --) {
           // printf("%d %d %d %d\n",lsh[i],p[i],data.ask(),nodes[lsh[i]].size());
            p[i] += data.ask() + nodes[lsh[i]].size();
            for(int id : nodes[lsh[i]]) tmp[a[id]] ++;
            for(int id : nodes[lsh[i]])
                if(tmp[a[id]]) {
                    if(tmp[a[id]]==2||data.has(a[id]))
                        data.del(a[id]);
                    else
                        data.add(a[id]);
                    tmp[a[id]]=0;
                }
            data.allAdd(lsh[i]-lsh[i-1]);
        }
        int pmin = 1e9,pmax = -1;
        for(int i = 1;i <= lsh[0];i ++) {
            pmin = min(pmin,p[i]);
            pmax = max(pmax,p[i]);
        }
        for(int i = 1;i <= lsh[0];i ++) nodes[lsh[i]].clear();
        printf("%d %d\n",pmin,pmax);
    }
}

/**
3
3 2
1 2
2 1
3 5

4 3
2 1
2 5
4 3
0 3

2 3
1 3
4 3
*/
