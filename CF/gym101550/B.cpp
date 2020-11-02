#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 + 10;

int ch[SZ][27],totp,val[SZ],Id[SZ],ed[SZ],son[SZ];

void insert(char s[],int id) {
    int len = strlen(s),p = 0;
    int minlen = 1e9;
    val[0] = 0;
    for(int i = 0;i < len;i ++) {
        int c = s[i] - 'a';
        if(!ch[p][c]) {
            ch[p][c] = ++ totp;
            Id[totp] = id;
            val[totp] = i + 1;
            if(Id[p] == id) son[p] = totp;
        }
        p = ch[p][c];
    }
    ed[id] = p;
        //     cout << p << " " << minlen << endl;
}

int dfs(int u,int fa) {
    if(fa != -1) val[u] = min(val[u],val[fa] + 1);
    val[ed[Id[u]]] = min(val[ed[Id[u]]],val[u] + 1);
    if(son[u]) {
        int v = son[u];
        dfs(v,u);
        val[u] = min(val[u],val[v] + 1);
    }
    for(int c = 0;c < 26;c ++) {
        int v = ch[u][c];
        if(!v || v == son[u]) continue;
        dfs(v,u);
        val[u] = min(val[u],val[v] + 1);
        val[ed[Id[u]]] = min(val[ed[Id[u]]],val[u] + 1);
    }


  //  printf("%4d%4d%4d\n",u,val[u],ed[Id[u]]);
}

int ask(char s[]) {
    int len = strlen(s),p = 0;
    int ans = len;
    for(int i = 0;i < len;i ++) {
        int c = s[i] - 'a';
        if(ch[p][c]) p = ch[p][c];
        else break;
    //    printf("%d %d %d\n",i,val[p],len - i - 1);
        ans = min(ans,val[p] + len - i - 1);
    }
    return ans;
}

char s[SZ];

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i ++) {
        scanf("%s",s);
        insert(s,i);
    }

    dfs(0,-1);
    for(int i = 1;i <= m;i ++) {
        scanf("%s",s);
        printf("%d\n",ask(s));
    }
}
/*
2 1
ausa
autooooct
autooootion

3 1
abc
abcdeaafgh
abcdeaafghaaaaa
abcdeaafaaaabbb


10

*/
