#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<cmath>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
const int SZ = 2000010;
const LL INF = 1000000010;
const LL mod = 1000000007;

LL read()
{
    LL n = 0;
    char a = getchar();
    int flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int n,m;

struct point
{
    LL x,y;
}p[SZ];

bool operator <(point a,point b)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

point operator -(point a,point b)
{
    return (point){a.x - b.x,a.y - b.y};
}

LL operator *(point a,point b)
{
    return a.x * b.y - a.y * b.x;
}

LL bits[SZ];
void add(int x,LL d)
{
    for(int i = x;i <= n;i += i & -i)
        bits[i] += d;
}

LL ask(int x)
{
    LL ans = 0;
    for(int i = x;i > 0;i -= i & -i)
        ans += bits[i];
    return ans;
}

LL get_val(point a,point b)
{
    if(a.x > b.x) swap(a,b);
    //if(!a.y || !b.y) return 0;
    return min(a.y,b.y) * (b.x - a.x - 1) - (ask(b.x - 1) - ask(a.x));
}

set<point> s;
LL ans = 0;

void insert(int id,int d)
{
    p[id].y += d;
    add(id,d);
    point x = (point){p[id].x,p[id].y};
    set<point> :: iterator r = s.lower_bound(x);
    set<point> :: iterator l = r; l --;
    if((*r - *l) * (x - *l) < 0) { ans -= d; return ; }
    ans -= get_val(*l,*r);
    //cout << id << endl;
    //cout << "1 : " << get_val(*l,*r) << endl;
    s.insert(x);
    while(233)
    {
        set<point> :: iterator it = r;
        r ++;
        if(r == s.end()) break;
        if((*r - x) * (*it - x) > 0) break;
        ans -= get_val(*r,*it);
        s.erase(*it);
    }
    while(l != s.begin())
    {
        set<point> :: iterator it = l;
        l --;
        if((*l - x) * (*it - x) < 0) break;
        ans -= get_val(*l,*it);
        s.erase(*it);
    }
    l = r = s.find(x);
    l --; r ++;
    ans += get_val(*l,x) + get_val(x,*r);
//    cout << get_val(*l,x) + get_val(x,*r) << endl;
}

int main()
{
    int T = read();
    while(T --)
    {
        s.clear();
        memset(bits,0,sizeof(bits));
        memset(p,0,sizeof(p));
        ans = 0;

        n = read(),m = read();
        s.insert((point){0,0});
        s.insert((point){n + 1,0});
        for(int i = 1;i <= n;i ++)
            p[i].x = i,insert(i,read());
        ans = 0;
        for(set<point> :: iterator it = s.begin();it != s.end();it ++)
        {
            set<point> :: iterator itt = it; itt ++;
            if(itt != s.end()) ans += get_val(*it,*itt);
        }
        while(m --)
        {
            char opt[3];
            scanf("%s",opt);
            LL x,y;
            if(opt[0] == 'U')
            {
                x = read(),y = read(),insert(x,y);
            }
            else
            {

            }
        }
    }
    return 0;
}
