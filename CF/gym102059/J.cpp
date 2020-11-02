#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 2000100;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

int n;
stack<int> S;
int pL[SZ],pR[SZ],a[SZ];

void pre() {
    for(int i = 1;i <= n;i ++) {
        while(S.size() && a[S.top()] > a[i]) S.pop();
        pL[i] = S.empty()?1:S.top()+1;
        S.push(i);
    }
    while(S.size()) S.pop();
    for(int i = n;i >= 1;i --) {
        while(S.size() && a[S.top()] >= a[i]) S.pop();
        pR[i] = S.empty()?n:S.top()-1;
        S.push(i);
    }
}

LL ask_smaller(int pos,int L,int R,LL len) {
    if(len<=0) return 0;
    len = min(len,1ll*R-L+1);
    int x = pos-L+1,y = R-pos+1;
    if(x>y) swap(x,y);

    LL d = min(1ll*x,max(0ll,x+y-len));
    LL f = max(1ll,1+x-len);
    LL ans = 1ll*(d-f+1)*(d+f)/2 + 1ll*(d-f+1)*(len-x) + 1ll*(x-d)*y;

    /*LL t = 0;
    for(int i = 1;i <= x;i ++)
        t += min(y*1ll,max(0ll,len-x+i));
    printf("[%lld %lld] %d %d %lld\n",ans,t,x,y,len);
    system("pause");*/
    return ans;
}

LL ask(int pos,int L,int R,LL len) {
    return ask_smaller(pos,L,R,len) - ask_smaller(pos,L,R,len-1);
}

int Len[SZ];

LL check(LL mid) {
    LL ans = 0;
    for(int i = 1;i <= n;i ++) {
   //     cout << i << "- " << mid/a[i] << " " << ask_smaller(i,pL[i],pR[i],mid/a[i]) << endl;
        ans += ask_smaller(i,pL[i],pR[i],mid/a[i]);
    }
    return ans;
}

LL getk(LL k) {
    LL l = 0,r = 3e15;
    while(r - l >1) {
        LL mid = l + r >> 1;
        if(check(mid) >= k) r = mid;
        else l = mid;
    }
    return r;
}

struct haha {
    LL id,val,nowt,sumt;
};

bool operator <(haha a,haha b) { return a.val > b.val; }

priority_queue<haha> q;
vector<LL> Ans;

int main() {
    n = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    pre();
    //for(int i = 1;i <= n;i ++) printf("[%d,%d]\n",pL[i],pR[i]);
    LL L = read(),R = read();

    check(10);

    LL r = getk(L),Lt = check(r);
    //cout << r << " " << Lt << endl;
    while(L <= Lt && L <= R) L++,Ans.push_back(r);
    LL now = getk(L);
    for(int i = 1;i <= n;i ++) {
        LL t = ask(i,pL[i],pR[i],(now+a[i]-1)/a[i]);
        if(t) {
            q.push((haha){i,(now+a[i]-1)/a[i]*a[i],1,t});
         //   cout << i << " " << now << " " << t << endl;
        }
    }
    while(L <= R) {
        haha x = q.top(); q.pop();
        Ans.push_back(x.val);
        L ++;
        if(x.nowt == x.sumt) {
            LL t = ask(x.id,pL[x.id],pR[x.id],x.val/a[x.id]+1);
            if(t) {
                q.push((haha){x.id,x.val+a[x.id],1,t});
            }
        }
        else {
            x.nowt ++; q.push(x);
        }
    }
    for(LL x : Ans) printf("%lld ",x);
    return 0;
}
