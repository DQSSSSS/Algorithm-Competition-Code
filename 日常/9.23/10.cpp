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

struct haha
{
    string s;
    int d;
    int getid()
    {
        int ans = 0;
        for(int i = 0;i < s.length();i ++)
            ans = ans * 9 + s[i] - 'a' + 1;
        ans = ans * 9 + d + 1;
        return ans;
    }
};

int mp[50000007];

int head[SZ],nxt[500010],tot = 1;

struct edge
{
    int t,d;
}l[500010];

void build(int f,int t,int d)
{
    l[++ tot] = (edge){t,d};
    nxt[tot] = head[f];
    head[f] = tot;
}

int dist[SZ];
bool use[SZ];
queue<int> q;

void spfa(int s)
{
    memset(dist,63,sizeof(dist));
    dist[s] = 0;
    q.push(s);
    use[s] = 1;
    while(q.size())
    {
        int u = q.front(); q.pop();
        use[u] = 0;
        for(int i = head[u];i;i = nxt[i])
        {
            int v = l[i].t;
            if(dist[v] > dist[u] + l[i].d)
            {
                dist[v] = dist[u] + l[i].d;
                if(!use[v]) use[v] = 1,q.push(v);
            }
        }
    }
}

string get(string s,int pos)
{
    string ans;
    for(int i = 0;i < pos;i ++)
        ans += s[i];
    for(int i = pos + 1;i < s.length();i ++)
        ans += s[i];
    return ans;
}

string insert(string s,int pos,char c)
{
    string ans;
    for(int i = 0;i < pos;i ++)
        ans += s[i];
    ans += c;
    for(int i = pos;i < s.length();i ++)
        ans += s[i];
    return ans;
}

char s[10];
bool vis[10];
int totp = 0;

void dfs(int d)
{
    if(d > 1)
    {
        string x;
        for(int i = 1;i < d;i ++)
            x += s[i];
        int len = x.length();
        for(int i = 0;i <= len;i ++)
        {
            haha uu = (haha){x,i},vv;
            if(!mp[uu.getid()]) mp[uu.getid()] = ++ totp;
            int u = mp[uu.getid()];
            int v;
            if(i > 0) //左移一位
            {
                vv = (haha){x,i - 1};
                v = mp[vv.getid()] ? mp[vv.getid()] : mp[vv.getid()] = ++ totp;
                build(u,v,1);
            }
            if(i < len) //右移一位
            {
                vv = (haha){x,i + 1};
                v = mp[vv.getid()] ? mp[vv.getid()] : mp[vv.getid()] = ++ totp;
                build(u,v,1);
            }
            if(i > 0) //delete left
            {
                string sv = get(x,i - 1);
                vv = (haha){sv,i - 1};
                v = mp[vv.getid()] ? mp[vv.getid()] : mp[vv.getid()] = ++ totp;
            /*    if(len == 1)
                {
                    cout << x << " " << i << " "  << sv << " " << i - 1 << endl;
                    cout << u << " -> " << v << " " << 2 << endl;
                }*/
                build(u,v,2);
            }
            if(i < len) //delete right
            {
                string sv = get(x,i);
                vv = (haha){sv,i};
                v = mp[vv.getid()] ? mp[vv.getid()] : mp[vv.getid()] = ++ totp;
                build(u,v,2);
            }
            for(int j = 0;j < 7;j ++)
            {
                if(vis[j]) continue;
                char c = j + 'a';
                string sv = insert(x,i,c);
                vv = (haha){sv,i + 1};
                v = mp[vv.getid()] ? mp[vv.getid()] : mp[vv.getid()] = ++ totp;
                /*if(x == "b" || x == "ba" || x == "bac" || x == "bacg" || x == "bacge")
                {
                    cout << x << " " << i << " " << sv << " " << i + 1 << endl;
                    cout << u << " -> " << v << " " << 2 << endl;
                }*/
                build(u,v,2);
            }
        }
    }
    if(d == 8) return ;

    for(int i = 0;i < 7;i ++)
    {
        if(vis[i]) continue;
        vis[i] = 1;
        char c = i + 'a';
        s[d] = c;
        dfs(d + 1);
        vis[i] = 0;
        s[d] = '\0';
    }
}

bool check(string s)
{
    if(s.length() > 7) return false;
    bool use[10] = {};
    for(int i = 0;i < s.length();i ++)
    {
        int c = s[i] - 'a';
        if(use[c]) return false;
        use[c] = 1;
        if(s[i] > 'g' || s[i] < 'a') return false;
    }
    return true;
}

bool init()
{
    int s = 3;
    for(int j = 0;j < 7;j ++)
    {
        char c = j + 'a';
        string sv; sv += c;
        haha vv = (haha){sv,1};
        int v = mp[vv.getid()] ? mp[vv.getid()] : mp[vv.getid()] = ++ totp;
        build(s,v,2);
    }
}

int main()
{
	//freopen("data.in","r",stdin); freopen("10.out","w",stdout);
    dfs(1);
    init();
/*    cout << totp << endl;
    for(int i = 0;i <= 50000000;i ++)
        if(mp[i])
            cout << h[i].s << " " << h[i].d << " " << mp[i] << endl;*/
    string s1,s2; int d;
    while(cin >> s1 >> d >> s2)
    {
        if(!check(s1) || d > s1.length() || !check(s2)) {puts("-1"); continue;}
        int s = mp[((haha){s1,d}).getid()];
        spfa(s);
        int ans = INF;
        for(int i = 0;i <= s2.length();i ++)
            ans = min(ans,dist[ mp[((haha){s2,i}).getid()] ]);
        if(ans == INF) puts("-1");
        else printf("%.1f\n",(double)ans * 1.0 / 2.0);
    }
    return 0;
}
/*
d 1 bacge
*/
