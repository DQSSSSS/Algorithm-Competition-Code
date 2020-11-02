#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 3e5 + 10;
const int mod = 1e9 + 7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a<'0'||a>'9') { if(a=='-') flag=1; a=getchar(); }
    while(a>='0'&&a<='9') { n=n*10+a-'0'; a=getchar(); }
    if(flag) n=-n;
    return n;
}

struct Ds {
    int num[SZ],n;

    void add(int x,int d) {
      //  printf("%d: %d\n",x,d);
        num[x] += d;
    }

    int ask(int x) {
        return num[x];
    }

    int ask_max() {
        int ans = 0;
        for(int i = 1;i <= n;i ++) ans = max(ans,num[i]);
        return ans;
    }

    void init(int nn) {
        n = nn;
        for(int i = 1;i <= n;i ++) num[i] = 0;
    }
}data;

int len[SZ],col[SZ];

set<int> s;

void change(int l,int r,int c) {
    //cout << l << " " << r << " " << c << endl;
    auto it = s.upper_bound(l); it --;
    vector<int> nodes;
    vector<pair<int,pii> > tmp;
    while(it != s.end() && *it <= r) {
        if(*it+len[*it]-1 > r) {
            tmp.push_back(make_pair(r+1,make_pair(*it+len[*it]-1-r,col[*it])));
        }
        if(*it < l) {
            tmp.push_back(make_pair(*it,make_pair(l-*it,col[*it])));
        }
        nodes.push_back(*it);
        it ++;
    }
    for(int x : nodes) {
        s.erase(x);
        data.add(col[x],-len[x]);
    }
    for(pair<int,pii> p : tmp) {
        int pos = p.first;
        len[pos] = p.second.first;
        col[pos] = p.second.second;
        s.insert(pos);
        data.add(col[pos],len[pos]);
    }
    s.insert(l);
    len[l] = r-l+1;
    col[l] = c;
    data.add(col[l],len[l]);
}

int main() {
    int L = read(),c = read(),n = read();
    s.insert(0);
    len[0] = L; col[0] = 1;
    data.init(c);
    data.add(1,L);
    for(int i = 1;i <= n;i ++) {
        int P = read(),X = read();
        int A = read(),B = read();

        int S = data.ask(P);
       // cout << S << endl;
        int l = (A + 1ll * S * S % L) % L;
        int r = (A + 1ll * (S+B) * (S+B) % L) % L;
        if(l>r) swap(l,r);


        change(l,r,X);
    }
    printf("%d\n",data.ask_max());
}

/**
7 5 2
1 2 5 3
3 3 0 1
*/
