#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 2e5 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

const LL N = 1e12,M = 1e10;

set<pll> s;

void del(LL x) {
    pll tmp;
    for(pll q : s) {
        if(q.first <= x && x <= q.second) {
            tmp = q;
            break;
        }
    }
    s.erase(tmp);
    if(x!=tmp.first) s.insert(make_pair(tmp.first,x-1));
    if(x+M-1!=tmp.second) s.insert(make_pair(x+M,tmp.second));
}

mt19937 rd(time(0));

LL get_nxt() {
    LL sum = 0;
    for(pll tmp : s) {
        sum += max((tmp.second-tmp.first+1) - M + 1,0ll);
    }
    if(sum == 0) return -2;
    LL x = rd()<<32^rd();
    x = x % sum + 1;
    //cout << sum << " " << x << endl;
    sum = 0;
    for(pll tmp : s) {
        LL now = tmp.second-tmp.first+1 - M + 1;
        if(now > 0) {
              //  cout << sum+now << " "<< x << endl;
            if(sum + now >= x) {
                LL d = x - sum - 1;
                return tmp.first + d;
            }
            sum += now;
        }
    }
}

int main() {
    int T = read(),W = read();
    int fail = 0;
    while(T --) {
        s.clear();
        s.insert(make_pair(1,N));
        bool fst = 0;
        while(1) {
            LL p = read();
            //LL p = get_nxt();
            //cout << p << endl; system("pause");
            if(p == -2) break;
            if(p == -3) { fail ++; break;}
            if(p == -1) return 0;

            del(p);

            LL q = -1;

            for(pll tmp : s) {
                if((tmp.second-tmp.first+1)/M > 3) {
                    q = tmp.first + 3 * M;
                    break;
                }
            }

            if(q == -1) {
                for(pll tmp : s) {
                    if((tmp.second-tmp.first+1) > 3 * M) {
                        q = tmp.first + M - 1;
                        break;
                    }
                }
            }

            if(q == -1) {
                for(pll tmp : s) {
                    if((tmp.second-tmp.first+1)/M == 2) {
                        q = tmp.first + M - 1;
                        break;
                    }
                }
            }

            if(q == -1) {
                int one = 0;
                for(pll tmp : s) {
                    if((tmp.second-tmp.first+1)/M == 1) {
                        one ++;
                    }
                }
                if(one & 1) {
                    int one = 0;
                    for(pll tmp : s) {
                        if((tmp.second-tmp.first+1)/M == 1) {
                            q = tmp.first;
                            break;
                        }
                    }
                }
                else {
                    for(pll tmp : s) {
                        if((tmp.second-tmp.first+1)/M == 3) {
                            q = tmp.first + M;
                            break;
                        }
                    }

                    if(q == -1) {
                        for(pll tmp : s) {
                            if((tmp.second-tmp.first+1)/M >= 1) {
                                q = tmp.first;
                                break;
                            }
                        }
                    }
                }
            }

            //if(q == -1) { fail ++; break; }
            printf("%lld\n",q); fflush(stdout);
            del(q);
        }
    }
  //  cout << fail << endl;
    return 0;
}
