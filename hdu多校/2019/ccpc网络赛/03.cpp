#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

struct SuffixArray {
    /// 串从0开始,a[len]是非法字符
    /// sa[i]表示排名为i的后缀 i在[0,len-1]
    /// lcp[i]表示sa[i]和sa[i-1]的lcp i在[1,len-1]
    int lcp[SZ],sa[SZ],rk[SZ],len;
    bool cmp(int *y,int a,int b,int k) {
        int a1 = y[a],b1 = y[b];
        int a2 = a + k >= len ? -1 : y[a + k];
        int b2 = b + k >= len ? -1 : y[b + k];
        return a1 == b1 && a2 == b2;
    }

    int t1[SZ],t2[SZ],cc[SZ];

    void get_sa(char s[],int m) {
        int *x = t1,*y = t2; /// 字符集
        for(int i = 0;i < m;i ++) cc[i] = 0;
        for(int i = 0;i < len;i ++) ++ cc[x[i] = s[i]];
        for(int i = 1;i < m;i ++) cc[i] += cc[i - 1];
        for(int i = len - 1;~i;i --) sa[-- cc[x[i]]] = i;
        for(int k = 1;k < len;k <<= 1) {
            int p = 0;
            for(int i = len - k;i < len;i ++)  y[p ++] = i;
            for(int i = 0;i < len;i ++) if(sa[i] >= k) y[p ++] = sa[i] - k;
            for(int i = 0;i < m;i ++) cc[i] = 0;
            for(int i = 0;i < len;i ++) ++ cc[x[y[i]]];
            for(int i = 1;i < m;i ++) cc[i] += cc[i - 1];
            for(int i = len - 1;~i;i --) sa[-- cc[x[y[i]]]] = y[i];
            swap(x,y); m = 1; x[sa[0]] = 0;

            for(int i = 1;i < len;i ++)
                x[sa[i]] = cmp(y,sa[i - 1],sa[i],k) ? m - 1 : m ++;
            if(m >= len) break;
        }
    }

    void get_lcp(char s[]) {
        for(int i = 0;i < len;i ++) rk[sa[i]] = i;
        int h = 0;
        lcp[0] = 0;
        for(int i = 0;i < len;i ++) {
            if(!rk[i]) continue;
            int j = sa[rk[i] - 1];
            if(h) h --;
            while(s[i + h] == s[j + h]) h ++;
            lcp[rk[i]] = h;
        }
    }

    void init(char *s,int n,int m) {
        len = n;
        get_sa(s,m); get_lcp(s);
    }
}sa;

int st[SZ][22];

void get_st(int a[],int n) {
    for(int i = 1;i <= n;i ++) st[i][0] = a[i];

    for(int j = 1;j <= log2(n);j ++) {
        for(int i = 1;i + (1<<j) - 1 <= n;i ++) {
            st[i][j] = min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }

  /*  for(int i = 1;i <= n;i ++) {
        for(int j = 0;j <= log2(n);j ++) {
            printf("%4d",st[i][j]);
        }
        puts("");
    }*/
}

int ask_min(int l,int r) {
    int k = log2(r-l+1);
    return min(st[l][k],st[r-(1<<k)+1][k]);
}

struct seg {
    int l,r,sz;
}tree[30000010];

int Tcnt = 0,rt[SZ];

void insert(int l,int r,int last,int &now,int v,int x) {
    now = ++ Tcnt;
    tree[now] = tree[last];
    tree[now].sz += x;
    if(l == r) return;
    int mid = (l + r) >> 1;
    if(v <= mid) insert(l,mid,tree[last].l,tree[now].l,v,x);
    else insert(mid + 1,r,tree[last].r,tree[now].r,v,x);
}

int ask_kth(int l,int r,int k) {
   // printf("[%d,%d] %d\n",l,r,k);
    if(r-l+1 < k) return -2;
    int L = 0,R = sa.len-1;
    int tl = rt[l-1],tr = rt[r];
    while(L != R) {
        int mid = L + R >> 1;
        int sz = tree[tree[tr].l].sz - tree[tree[tl].l].sz;
        if(sz >= k) {
            tl = tree[tl].l; tr = tree[tr].l; R = mid;
        }
        else {
            tl = tree[tl].r; tr = tree[tr].r; L = mid+1;
            k -= sz;
        }
    }
    return L;
}

pii ask(int p,int v) {
 //   cout << p << " " <<v << endl;
    pii ans;
    int L,R;
    if(sa.lcp[p] >= v) {
        L = 0,R = p;
        while(R - L > 1) {
            int mid = L + R >> 1;
         //   printf("[%d,%d] min: %d\n",mid,p,ask_min(mid,p));
            if(ask_min(mid,p) >= v) R = mid;
            else L = mid;
        }
        ans.first = R - 1;
    }
    else ans.first = p;

    L = p,R = sa.len;
    while(R - L > 1) {
        int mid = L + R >> 1;
        if(ask_min(p+1,mid) >= v) L = mid;
        else R = mid;
    }
    ans.second = L;
    return ans;
}

char s[SZ];

int main() {
    int T = read();
    while(T --) {
        int n = read(),m = read();
        scanf("%s",s);
        sa.len = strlen(s);
        sa.get_sa(s,256);
        sa.get_lcp(s);
/*
        for(int i = 0;i < sa.len;i ++) printf("%3d",i); puts("");
        for(int i = 0;i < sa.len;i ++) printf("%3d",sa.sa[i]); puts("");
        for(int i = 0;i < sa.len;i ++) printf("%3d",sa.lcp[i]); puts("");
        for(int i = 0;i < sa.len;i ++) printf("%3d",sa.rk[i]); puts("");
*/
        Tcnt = 0;
        for(int i = 1;i <= sa.len;i ++) insert(0,sa.len-1,rt[i-1],rt[i],sa.sa[i-1],1);

        get_st(sa.lcp,sa.len-1);

        while(m --) {
            int l = read(),r = read(),k = read();
            int ll = r - l + 1;
            l --;
            pii qj = ask(sa.rk[l],ll);
            printf("%d\n",ask_kth(qj.first+1,qj.second+1,k) + 1);
        }
    }
}
/**
233
5 5
aabaa
2 3 1

233
5 5
ababc
1 2 2
*/
