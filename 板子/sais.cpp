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
        sais(s, sa, len, type, bucket, bucket1, sigma);
        for (int i = 1; i < len; i++) rk[sa[i]] = i;
        getHeight(s, len, sa);
    }
};
SuffixArray<SZ> sa;

char s[SZ];

int main() {
    scanf("%s",s);
    int len = strlen(s);
    sa.init(s,len,256);
    for(int i = 1;i <= len;i ++) printf("%d ",sa.sa[i]+1); puts("");
    for(int i = 2;i <= len;i ++) printf("%d ",sa.ht[i]); puts("");
}
