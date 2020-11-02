#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef pair<int,int> pii;
typedef pair<ULL,int> pui;
const int SZ = 260;
const double eps = 1e-6;

int n,m,mp[SZ][SZ],ex,ey,tmp[SZ][SZ];

unordered_map<ULL,bool> H;
unordered_map<ULL,pui> pr;

struct haha {
    int mp[SZ][SZ],x,y;
    ULL h;

    ULL getHash() {
        if(h) return h;
        ULL ans = 0;
        int tot = 0;
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= m;j ++) {
                if(mp[i][j] == -2) continue;
                if(i>1&&mp[i][j]==mp[i-1][j]) tmp[i][j] = tmp[i-1][j];
                else if(j>1&&mp[i][j]==mp[i][j-1]) tmp[i][j] = tmp[i][j-1];
                else tmp[i][j] = ++ tot;
                ans = ans * 19260817 + tmp[i][j];
            }
        }
        return h = ans;
    }

    void add(int x,ULL hh) {
        getHash(); pr[h] = make_pair(hh,x);
        //cout << h << " " << hh << " " << x << endl;
    }
    void printAns() {
        vector<int> g;
        getHash();
        ULL nowH = h;
        while(pr.count(nowH)) {
            g.push_back(pr[nowH].second);
           // cout << nowH << endl;
            nowH = pr[nowH].first;
        }
        reverse(g.begin(),g.end());
        for(int i = 0;i < g.size();i ++) {
            printf("%d%c",g[i],i+1==g.size()?'\n':' ');
        }
    }

    bool canLeft() {
        if(y+2<=m && mp[x][y+1]>=0 && mp[x][y+1]==mp[x][y+2]) return true;
        return false;
    }
    void left() {
        swap(mp[x][y],mp[x][y+2]); y+=2; h=0;
    }


    bool canRight() {
        if(y-2>=1 && mp[x][y-1]>=0 && mp[x][y-1]==mp[x][y-2]) return true;
        return false;
    }
    void right() {
        swap(mp[x][y],mp[x][y-2]); y-=2; h=0;
    }


    bool canUp() {
        if(x+2<=n && mp[x+1][y]>=0 && mp[x+1][y]==mp[x+2][y]) return true;
        return false;
    }
    void up() {
        swap(mp[x][y],mp[x+2][y]); x+=2; h=0;
    }

    bool canDown() {
        if(x-2>=1 && mp[x-1][y]>=0 && mp[x-1][y]==mp[x-2][y]) return true;
        return false;
    }
    void down() {
        swap(mp[x][y],mp[x-2][y]); x-=2; h=0;
    }

}st,u,nx;

int main() {
    clock_t tt = clock();
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            scanf("%d",&st.mp[i][j]);
            if(st.mp[i][j] == -1) st.x=i,st.y=j;
        }
    }
    scanf("%d%d",&ex,&ey);
    H[st.getHash()] = 1;
    queue<haha> q; q.push(st);
    while(q.size()) {
        u = q.front(); q.pop();

        vector<pii> g;
        if(u.canDown()) g.push_back(make_pair(u.mp[u.x-1][u.y],0));
        if(u.canUp())   g.push_back(make_pair(u.mp[u.x+1][u.y],1));
        if(u.canLeft()) g.push_back(make_pair(u.mp[u.x][u.y+1],2));
        if(u.canRight())g.push_back(make_pair(u.mp[u.x][u.y-1],3));
        sort(g.begin(),g.end());

        for(pii &p : g) {
            int x = p.second,id;
            if(x == 0) {
                nx = u; id=nx.mp[nx.x-1][nx.y]; nx.down();
            }
            if(x == 3) {
                nx = u; id=nx.mp[nx.x][nx.y-1]; nx.right();
            }
            if(x == 2) {
                nx = u; id=nx.mp[nx.x][nx.y+1]; nx.left();
            }
            if(x == 1) {
                nx = u; id=nx.mp[nx.x+1][nx.y]; nx.up();
            }
            if(!H.count(nx.getHash())) H[nx.getHash()]=1,q.push(nx),nx.add(id,u.getHash());
            if(nx.x==ex&&nx.y==ey) return nx.printAns(),0;
        }
        clock_t z = clock() - tt;
		if ((double)z / CLOCKS_PER_SEC > 1.97)break;
    }
    puts("impossible");
}
