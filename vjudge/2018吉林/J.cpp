#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<int,LL> pil;
const int SZ = 2e5 + 10;
const int mod = 1e9+7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a=='-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n=n*10+a-'0'; a = getchar(); }
    if(flag) n=-n;
    return n;
}

int a[SZ],num,lim,colNum,col2[SZ];

void addCol(int x) {
   // printf("add color: %d\n",x);
    a[x] ++;
    if(a[x] == lim) num ++;
}

void delCol(int x) {
   // printf("del color: %d\n",x);
    if(a[x] == lim) num --;
    a[x] --;
}

int noMatchNumber;
queue<int> cols[SZ];

void init(int n,int m) {
    for(int i = 1;i <= n;i ++) {
        while(cols[i].size()) cols[i].pop();
    }
    noMatchNumber = n;
    for(int i = 1;i <= m;i ++) {
        a[i] = 0;
        col2[i] = 0;
    }
    colNum = 0;
    num = 0;
    lim = n / 2 + 1;
}

void add(pii p) {
    int id = p.first,col = p.second;
    if(col2[col] == 0) colNum ++;
    col2[col] ++;
    if(cols[id].size() == 0) {
        noMatchNumber --;
        addCol(col);
    }
    else if(cols[id].size() == 1) {
        delCol(cols[id].front());
    }
    cols[id].push(col);
}

void del(pii p) {
    int id = p.first,col = p.second;
    if(col2[col] == 1) colNum --;
    col2[col] --;
    assert(!cols[id].empty());
    assert(cols[id].front() == col);
    if(cols[id].size() == 1) {
        noMatchNumber ++;
        delCol(cols[id].front());
    }
    else if(cols[id].size() == 2) {
        addCol(cols[id].back());
    }
    cols[id].pop();
}

int n,m;

bool check() {
    if(noMatchNumber) return false;
    if(num) return false;
    if(n%2==1&&colNum <= 2) return false;
    return true;
}

int main() {
    int T = read(),cc = 0;
    while(T --) {
        n = read(),m = read();
        init(n,m);
        vector<pair<int,pii> > a;
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= m;j ++) {
                a.push_back(make_pair(read(),make_pair(i,j)));
            }
        }
        sort(a.begin(),a.end());
        int ans = 1e9;
        //for(int i = 0;i < a.size();i ++) printf("%d: %d %d %d\n",i,a[i].first,a[i].second.first,a[i].second.second);
        for(int i = 0,j = -1;i < a.size();i ++) {
            while(!check() && j+1 < (int)a.size()) add(a[j+1].second),j ++;
            if(!check()) break;
          //  printf("[%d,%d] %d\n",i,j,num);
            ans = min(ans,a[j].first - a[i].first);
            del(a[i].second);
        }
        if(ans == 1e9) ans = -1;
        printf("Case %d: %d\n",++ cc,ans);
    }
}

/**
2
3 3
1 2 100
2 1 200
1 1 300

2 2

1
5 3
2 3 7
2 5 7
2 7 5
2 6 5
7 6 8


4 1
1
1
1
1


*/
