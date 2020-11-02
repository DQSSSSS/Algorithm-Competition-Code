#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 5e5 + 10;
const int mod = 998244353;
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

int a[SZ],n,m,L[SZ],R[SZ],X[SZ];
mt19937 rd(time(0));

int randlr(int l,int r) { return rd()%(r-l+1)+l; }

void get_data1(int maxn,int maxm) {
    int maxval = 1e6;
    n = randlr(1,maxn);
    for(int i = 1;i <= n;i ++) a[i] = randlr(1,maxval);
    m = randlr(1,maxm);
    for(int i = 1;i <= m;i ++) {
        L[i] = randlr(1,n);
        R[i] = randlr(1,n);
        X[i] = randlr(1,maxval);
        if(L[i] > R[i]) swap(L[i],R[i]);
    }

    printf("%d\n",n);
    for(int i = 1;i <= n;i ++) printf("%d ",a[i]); puts("");
    printf("%d\n",m);
    for(int i = 1;i <= m;i ++) printf("%d %d %d\n",L[i],R[i],X[i]); puts("");
}

void get_data2(int maxn) {
    int maxval = 1e6;
    n = randlr(maxn,maxn);
    for(int i = 1;i <= n;i ++) {
        int x = randlr(1,100);
        a[i] = x <= 50 ? randlr(1,1e6) : 510510;
    }
    m = randlr(100000,100000);
    for(int i = 1;i <= m;i ++) {
        L[i] = randlr(1,n);
        R[i] = randlr(1,n);
        int x = randlr(1,100);
        X[i] = x <= 50 ? randlr(1,1e6) : 510510;
        if(L[i] > R[i]) swap(L[i],R[i]);
    }

    printf("%d\n",n);
    for(int i = 1;i <= n;i ++) printf("%d ",a[i]); puts("");
    printf("%d\n",m);
    for(int i = 1;i <= m;i ++) printf("%d %d %d\n",L[i],R[i],X[i]); puts("");
}

int prime[SZ];
bool vis[1000010];
int minpri[1000010];

void shai(int n) {
    for(int i = 2;i <= n;i ++) {
        if(!vis[i]) prime[++ prime[0]] = i,minpri[i] = i;
        for(int j = 1,m;j <= prime[0] && (m=i*prime[j]) <= n;j ++) {
            vis[m] = 1;
            if(i % prime[j] == 0) {
                minpri[m] = minpri[i];
                break;
            }
            else minpri[m] = prime[j];
        }
    }
}

int getX() {
    //return prime[randlr(20,25)] * prime[randlr(20,25)] * prime[randlr(20,25)];
    return prime[randlr(150,168)] * prime[randlr(150,168)];
}

void get_data3(int maxnl,int maxnr,int maxm) {

    int maxval = 1e6;
    n = randlr(maxnl,maxnr);
    for(int i = 1;i <= n;i ++) {
        int x = randlr(1,100);
        a[i] = getX();
    }
    m = randlr(maxm,maxm);
    for(int i = 1;i <= m;i ++) {
        L[i] = randlr(1,n);
        R[i] = randlr(1,n);
        int x = randlr(1,100);
        X[i] = getX();
        if(L[i] > R[i]) swap(L[i],R[i]);
    }

    printf("%d\n",n);
    for(int i = 1;i <= n;i ++) printf("%d ",a[i]); puts("");
    printf("%d\n",m);
    for(int i = 1;i <= m;i ++) printf("%d %d %d\n",L[i],R[i],X[i]); puts("");
}

int main() {
    shai(1e3);

    for(int i = 1;i <= prime[0];i ++) cout << i << " "<< prime[i] << endl;
    system("pause");

    freopen("data.in","w",stdout);
    int T = 100000;
    printf("%d\n",T);
    get_data2(2e5);
    get_data3(2e5,2e5,1e5);
    get_data1(2e5,1e5);
    T -= 3;
    while(T --) {
        get_data3(1,3,5);
    }

    /*for(int i = 1;i <= m;i ++) {
        int l = L[i],r = R[i],x = X[i];
        int ans = 0;
        for(int j = l;j <= r;j ++) if(__gcd(x,a[j]) == 1) ans ++;
        printf("%d\n",ans);
    }*/
    return 0;
}

/**
4
6 6 17 19
9
2 2 5
3 4 9
1 2 2
3 3 4
1 2 8
1 4 4
4 4 1
2 4 5
4 4 1

1
2
0
1
0
2
1
3
1


1 2
2 3
3 5
4 7
5 11
6 13
7 17
8 19
9 23
10 29
11 31
12 37
13 41
14 43
15 47
16 53
17 59
18 61
19 67
20 71
21 73
22 79
23 83
24 89
25 97
26 101
27 103
28 107
29 109
30 113
31 127
32 131
33 137
34 139
35 149
36 151
37 157
38 163
39 167
40 173
41 179
42 181
43 191
44 193
45 197
46 199
47 211
48 223
49 227
50 229
51 233
52 239
53 241
54 251
55 257
56 263
57 269
58 271
59 277
60 281
61 283
62 293
63 307
64 311
65 313
66 317
67 331
68 337
69 347
70 349
71 353
72 359
73 367
74 373
75 379
76 383
77 389
78 397
79 401
80 409
81 419
82 421
83 431
84 433
85 439
86 443
87 449
88 457
89 461
90 463
91 467
92 479
93 487
94 491
95 499
96 503
97 509
98 521
99 523
100 541
101 547
102 557
103 563
104 569
105 571
106 577
107 587
108 593
109 599
110 601
111 607
112 613
113 617
114 619
115 631
116 641
117 643
118 647
119 653
120 659
121 661
122 673
123 677
124 683
125 691
126 701
127 709
128 719
129 727
130 733
131 739
132 743
133 751
134 757
135 761
136 769
137 773
138 787
139 797
140 809
141 811
142 821
143 823
144 827
145 829
146 839
147 853
148 857
149 859
150 863
151 877
152 881
153 883
154 887
155 907
156 911
157 919
158 929
159 937
160 941
161 947
162 953
163 967
164 971
165 977
166 983
167 991
168 997

*/
