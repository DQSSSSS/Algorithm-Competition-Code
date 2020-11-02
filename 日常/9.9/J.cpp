#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

typedef long long LL;
const int SZ = 200010;
const int INF = 1000000010;

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

int head[20010],nxt[SZ],tot = 1;

struct edge
{
    int f,t;
    LL d,c;
}l[SZ];

void build(int f,int t,LL d,LL c)
{
    l[++ tot] = (edge){f,t,d,c};
    nxt[tot] = head[f];
    head[f] = tot;
}

void insert(int f,int t,LL d,LL c)
{
    build(f,t,d,c); build(t,f,0,-c);
}

LL dist[20010];
deque<int> q;
int pre[20010],use[SZ];
bool spfa(int s,int e)
{
    memset(dist,63,sizeof(dist));
    memset(pre,0,sizeof(pre));

    dist[s] = 0;
    use[s] = 1;
    q.push_front(s);
    while(q.size())
    {
        int u = q.front(); q.pop_front();
        use[u] = 0;
        for(int i = head[u];i;i = nxt[i])
        {
            int v = l[i].t;
            if(l[i].d && dist[v] > dist[u] + l[i].c)
            {
                dist[v] = dist[u] + l[i].c;
                pre[v] = i;
                if(!use[v])
                {
                    use[v] = 1;
                    if(q.empty()) q.push_front(v);
                    else if(dist[q.front()] > dist[v])
                        q.push_front(v);
                    else
                        q.push_back(v);
                }
            }
        }
    }
    return dist[e] < -INF ? false : true;
}
LL dfs(int s,int e)
{
    LL x = INF,ans = 0;
    for(int i = pre[e];i;i = pre[l[i].f])
        x = min(x,l[i].d);
    for(int i = pre[e];i;i = pre[l[i].f])
        ans += x * l[i].c,l[i].d -= x,l[i ^ 1].d += x;
    return ans;
}
LL ek(int s,int e)
{
    LL ans = 0;
    while(spfa(s,e))
    {
        int tmp = dfs(s,e);
        if(tmp == 0) break;
        ans += tmp;
    }
    return ans;
}

struct haha
{
    int f,t;
};

map<string,haha> mp;

bool check(string s)
{
    int u = mp[s].f,v = mp[s].t;
    for(int i = head[u];i;i = nxt[i])
        if(l[i].t == v && l[i].d)
            return false;
    return true;
}

int main()
{
    int T = read();
    while(T --)
    {
        tot = 1; memset(head,0,sizeof(head)); mp.clear(); int n = 0;
        int m = read();
        for(int i = 1;i <= m;i ++)
        {
            char s1[30],s2[30];
            LL d;
            scanf("%s%s",s1,s2); d = read();
            string S1 = s1,S2 = s2;
            if(!mp[S1].f) mp[S1].f = ++ n,mp[S1].t = ++ n,insert(mp[S1].f,mp[S1].t,1,0);
            if(!mp[S2].f) mp[S2].f = ++ n,mp[S2].t = ++ n,insert(mp[S2].f,mp[S2].t,1,0);
            insert(mp[S1].t,mp[S2].f,1,d);
            insert(mp[S2].t,mp[S1].f,1,d);
        }
        int e = ++ n;
        insert(mp["Dalian"].t,e,1,0);
        insert(mp["Xian"].t,e,1,0);
        insert(mp["Shanghai"].f,mp["Shanghai"].t,1,0);
        int ans = ek(mp["Shanghai"].f,e);
        if(!check("Dalian") || !check("Xian")) puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}
