#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 500010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-12;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

LL pri[310],id[310];

bool check(int x) {
    for(int i = 2;i * i <= x;i ++)
        if(x % i == 0)
            return false;
    return true;
}

void Pre() {
    id[2]=1;pri[1]=2;id[3]=2;pri[2]=3;id[5]=3;pri[3]=5;id[7]=4;pri[4]=7;id[11]=5;pri[5]=11;id[13]=6;pri[6]=13;id[17]=7;pri[7]=17;id[19]=8;pri[8]=19;id[23]=9;pri[9]=23;id[29]=10;pri[10]=29;id[31]=11;pri[11]=31;id[37]=12;pri[12]=37;id[41]=13;pri[13]=41;id[43]=14;pri[14]=43;id[47]=15;pri[15]=47;id[53]=16;pri[16]=53;id[59]=17;pri[17]=59;id[61]=18;pri[18]=61;id[67]=19;pri[19]=67;id[71]=20;pri[20]=71;id[73]=21;pri[21]=73;id[79]=22;pri[22]=79;id[83]=23;pri[23]=83;id[89]=24;pri[24]=89;id[97]=25;pri[25]=97;id[101]=26;pri[26]=101;id[103]=27;pri[27]=103;id[107]=28;pri[28]=107;id[109]=29;pri[29]=109;id[113]=30;pri[30]=113;id[127]=31;pri[31]=127;id[131]=32;pri[32]=131;id[137]=33;pri[33]=137;id[139]=34;pri[34]=139;id[149]=35;pri[35]=149;id[151]=36;pri[36]=151;id[157]=37;pri[37]=157;id[163]=38;pri[38]=163;id[167]=39;pri[39]=167;id[173]=40;pri[40]=173;id[179]=41;pri[41]=179;id[181]=42;pri[42]=181;id[191]=43;pri[43]=191;id[193]=44;pri[44]=193;id[197]=45;pri[45]=197;id[199]=46;pri[46]=199;id[211]=47;pri[47]=211;id[223]=48;pri[48]=223;id[227]=49;pri[49]=227;id[229]=50;pri[50]=229;id[233]=51;pri[51]=233;id[239]=52;pri[52]=239;id[241]=53;pri[53]=241;id[251]=54;pri[54]=251;id[257]=55;pri[55]=257;id[263]=56;pri[56]=263;id[269]=57;pri[57]=269;id[271]=58;pri[58]=271;id[277]=59;pri[59]=277;id[281]=60;pri[60]=281;id[283]=61;pri[61]=283;
    id[293]=62;pri[62]=293;
}

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b & 1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

ULL get_x(int b) {
    ULL x = 0;
    for(LL i = 2;i * i <= b;i ++) {
        if(b % i == 0) {
            x |= 1llu << (ULL)id[i];
            while(b % i == 0) b /= i;
        }
    }
    if(b != 1) {
        x |= 1llu << (ULL)id[b];
    }
    return x;
}

LL a[SZ];
ULL W[310];

struct seg {
    int l,r;
    LL ml,aml;
    ULL h,ah;
}tree[SZ * 4];

void update(int p) {
    tree[p].ml = tree[p << 1].ml * tree[p << 1 | 1].ml % mod;
    tree[p].h = tree[p << 1].h | tree[p << 1 | 1].h;
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].aml = 1;
    tree[p].ah = 0;
    if(l == r) {
        tree[p].ml = a[l];
        tree[p].h = W[a[l]];
        return ;
    }
    int mid = l + r >> 1;
    build(p << 1,l,mid);
    build(p << 1 | 1,mid+1,r);
    update(p);
}

void pushc(int p,ULL x,int d) {
    tree[p].h |= x;
    tree[p].ah |= x;
    (tree[p].ml *= ksm(d,tree[p].r - tree[p].l + 1)) %= mod;
    (tree[p].aml *= d) %= mod;
}

void pushdown(int p) {
    pushc(p<<1,tree[p].ah,tree[p].aml);
    pushc(p<<1|1,tree[p].ah,tree[p].aml);
    tree[p].ah = 0;
    tree[p].aml = 1;
}

void change(int p,int l,int r,ULL x,int d) {
    if(l <= tree[p].l && tree[p].r <= r) {
        pushc(p,x,d);
        return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) change(p << 1,l,r,x,d);
    if(mid < r) change(p << 1 | 1,l,r,x,d);
    update(p);
}

seg ask(int p,int l,int r) {
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p];
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    seg ans; ans.ml = 1; ans.h = 0;
    if(l <= mid) {
        seg tmp = ask(p << 1,l,r);
        ans.ml = ans.ml * tmp.ml % mod;
        ans.h = ans.h | tmp.h;
    }
    if(mid < r) {
        seg tmp = ask(p << 1 | 1,l,r);
        ans.ml = ans.ml * tmp.ml % mod;
        ans.h = ans.h | tmp.h;
    }
    return ans;
}

LL H[233];

int main() {
    Pre();
    for(int i = 1;i <= 62;i ++) {
        LL p = pri[i];
        H[i] = (p - 1) * ksm(p,mod - 2) % mod;
    }
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    for(int i = 2;i <= 300;i ++) W[i] = get_x(i);

    build(1,1,n);
    for(int i = 1;i <= m;i ++) {
        char opt[10];
        scanf("%s",opt);
        int l = read(),r = read();
        if(opt[0] == 'T') {
            seg tmp = ask(1,l,r);
            LL ans = tmp.ml;
            for(ULL j = 1;j <= 62;j ++)
                if(tmp.h >> j & 1)
                    ans = ans * H[j] % mod;
            printf("%lld\n",ans);
        }
        else {
            int b = read(),tot = 0;
            ULL x = W[b];
            if(b == 1) continue;
            change(1,l,r,x,b);
        }
    }
}
/**

*/
