#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
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

template<size_t size>
struct SuffixArray {
    /// 串从0开始
    /// sa[i]表示排名为i的后缀 i在[1,len]
    /// rk[i]表示sa[i]和sa[i-1]的lcp i在[2,len]
    bool type[size << 1];
    int bucket[size], bucket1[size];
    int sa[size], rk[size], ht[size];
    inline bool isLMS(const int i, const bool *type) { return i > 0 && type[i] && !type[i - 1]; }
    template<class T>
    inline void inducedSort(T s, int *sa, const int len, const int sigma, const int bucketSize, bool *type, int *bucket, int *cntbuf, int *p) {
        memset(bucket, 0, sizeof(int) * sigma);
        memset(sa, -1, sizeof(int) * len);
        for (int i = 0; i < len; i++) bucket[s[i]]++;
        cntbuf[0] = bucket[0];
        for (int i = 1; i < sigma; i++) cntbuf[i] = cntbuf[i - 1] + bucket[i];
        for (int i = bucketSize - 1; i >= 0; i--) sa[--cntbuf[s[p[i]]]] = p[i];
        for (int i = 1; i < sigma; i++) cntbuf[i] = cntbuf[i - 1] + bucket[i - 1];
        for (int i = 0; i < len; i++) if (sa[i] > 0 && !type[sa[i] - 1]) sa[cntbuf[s[sa[i] - 1]]++] = sa[i] - 1;
        cntbuf[0] = bucket[0];
        for (int i = 1; i < sigma; i++) cntbuf[i] = cntbuf[i - 1] + bucket[i];
        for (int i = len - 1; i >= 0; i--) if (sa[i] > 0 && type[sa[i] - 1]) sa[--cntbuf[s[sa[i] - 1]]] = sa[i] - 1;
    }
    template<typename T>
    inline void sais(T s, int *sa, int len, bool *type, int *bucket, int *bucket1, int sigma) {
        int i, j, bucketSize = 0, cnt = 0, p = -1, x, *cntbuf = bucket + sigma;
        type[len - 1] = 1;
        for (i = len - 2; i >= 0; i--) type[i] = s[i] < s[i + 1] || (s[i] == s[i + 1] && type[i + 1]);
        for (i = 1; i < len; i++) if (type[i] && !type[i - 1]) bucket1[bucketSize++] = i;
        inducedSort(s, sa, len, sigma, bucketSize, type, bucket, cntbuf, bucket1);
        for (i = bucketSize = 0; i < len; i++) if (isLMS(sa[i], type)) sa[bucketSize++] = sa[i];
        for (i = bucketSize; i < len; i++) sa[i] = -1;
        for (i = 0; i < bucketSize; i++) {
            x = sa[i];
            for (j = 0; j < len; j++) {
                if (p == -1 || s[x + j] != s[p + j] || type[x + j] != type[p + j]) { cnt++, p = x; break; }
                else if (j > 0 && (isLMS(x + j, type) || isLMS(p + j, type))) break;
            }
            x = (~x & 1 ? x >> 1 : x - 1 >> 1), sa[bucketSize + x] = cnt - 1;
        }
        for (i = j = len - 1; i >= bucketSize; i--) if (sa[i] >= 0) sa[j--] = sa[i];
        int *s1 = sa + len - bucketSize, *bucket2 = bucket1 + bucketSize;
        if (cnt < bucketSize) sais(s1, sa, bucketSize, type + len, bucket, bucket1 + bucketSize, cnt);
        else for (i = 0; i < bucketSize; i++) sa[s1[i]] = i;
        for (i = 0; i < bucketSize; i++) bucket2[i] = bucket1[sa[i]];
        inducedSort(s, sa, len, sigma, bucketSize, type, bucket, cntbuf, bucket2);
    }
    template<class T>
    inline void getHeight(const T *s, const int len, const int *sa) {
        for (int i = 0, k = 0; i < len; i++) {
            if (rk[i] == 0) k = 0;
            else {
                if (k > 0) k--;
                int j = sa[rk[i] - 1];
                while (i + k < len && j + k < len && s[i + k] == s[j + k]) k++;
            }
            ht[rk[i]] = k;
        }
    }
    template<class T>
    inline void init(T s, int len, int sigma) {
        len ++; sigma ++;
        memset(rk,0,sizeof(int) * len);
        sais(s, sa, len, type, bucket, bucket1, sigma);
        for (int i = 1; i < len; i++) rk[sa[i]] = i;
        getHeight(s, len, sa);
    }
};

struct seg {
    int l,r;
    LL c,sum;
}tree[SZ * 4];

void update(int p) {
    tree[p].sum = tree[p<<1].sum + tree[p<<1|1].sum;
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].c = 0;
    tree[p].sum = 0;
    if(l == r) return ;
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}

void pushc(int p,LL c) {
    tree[p].c = c;
    tree[p].sum = c * (tree[p].r - tree[p].l + 1);
}

void pushdown(int p) {
    if(tree[p].c) {
        pushc(p<<1,tree[p].c);
        pushc(p<<1|1,tree[p].c);
        tree[p].c = 0;
    }
}

void change(int p,int l,int r,LL c) {
    if(l <= tree[p].l && tree[p].r <= r) {
        pushc(p,c);
        return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) change(p<<1,l,r,c);
    if(mid < r) change(p<<1|1,l,r,c);
    update(p);
}

LL ask(int p,int l,int r) {
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p].sum;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    LL sum = 0;
    if(l <= mid) sum += ask(p<<1,l,r);
    if(mid < r) sum += ask(p<<1|1,l,r);
    return sum;
}

SuffixArray<SZ> sa;
int a[SZ],maxl[SZ],maxr[SZ];
pii b[SZ];
bool use[SZ];
vector<int> g[SZ];
LL lsh[SZ];

LL baoli(int a[],int n) {
    map<vector<int>,LL> mp;
    for(int i = 0;i < n;i ++) {
        vector<int> tmp;
        LL sum = 0;
        for(int j = i;j < n;j ++) {
            tmp.push_back(a[j]);
            sum = max(sum,(LL)a[j]);
            mp[tmp] = sum;
        }
    }
    LL ans = 0;
    for(auto it = mp.begin();it != mp.end();it ++) {
        ans += it -> second;
    }
    return ans;
}

stack<int> S;

int main() {
    //freopen("H.in","r",stdin);
    int T = read();
    while(T --) {
        int n = read();
        for(int i = 0;i < n;i ++) g[i].clear(),use[i] = 0;
        lsh[0] = 0;
       // a[n] = 0;

        for(int i = 0;i < n;i ++) {
            a[i] = read();
            lsh[++ lsh[0]] = a[i];
        }
      //  LL baolians = baoli(a,n);

        sort(lsh + 1,lsh + 1 + lsh[0]);
        lsh[0] = unique(lsh + 1,lsh + 1 + lsh[0]) - lsh - 1;
        for(int i = 0;i < n;i ++)
            a[i] = lower_bound(lsh + 1,lsh + 1 + lsh[0],a[i]) - lsh;

        sa.init(a,n,lsh[0]);

        int tot = 0;

        for(int i = 2;i <= n;i ++) {
            if(sa.ht[i])
                b[++ tot] = make_pair(sa.sa[i],sa.sa[i]+sa.ht[i]-1);
        }

        for(int i = 0;i < n;i ++) {
            while(S.size() && a[S.top()] <= a[i]) { maxr[S.top()] = i-1; S.pop();}
            if(S.size()) g[S.top()].push_back(i),use[i]=1;
            S.push(i);
        }
        while(S.size()) { maxr[S.top()] = n-1; S.pop(); }
        for(int i = n-1;i >= 0;i --) {
            while(S.size() && a[S.top()] < a[i]) { maxl[S.top()] = i+1; S.pop();}
            S.push(i);
        }
        while(S.size()) { maxl[S.top()] = 0; S.pop(); }

        LL ans = 0;
        for(int i = 0;i < n;i ++)
            ans += lsh[a[i]] * (i-maxl[i]+1) * (maxr[i]-i+1);

        build(1,0,n-1);
        for(int i = 0;i < n;i ++)
            if(!use[i]) {
                change(1,i,maxr[i],lsh[a[i]]);
            }

        sort(b+1,b+1+tot);
        for(int i = 1,j = 0;i <= tot;i ++) {
            while(j < b[i].first) {
                for(int u : g[j]) {
                    change(1,u,maxr[u],lsh[a[u]]);
                }
                j ++;
            }
            ans -= ask(1,b[i].first,b[i].second);
        }
        printf("%lld\n",ans);
      //  if(ans != baolians) return -1;
    }
}

/**
233
3
1 2 3
5
3 6 4 2 9
*/
