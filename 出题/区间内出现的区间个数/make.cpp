#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;

int read() {
    int n = 0;
    char a = getchar();
    bool flag = 0;
    while(a<'0'||a>'9') { if(a == '-') flag = 1; a = getchar();}
    while(a>='0'&&a<='9') { n=n*10+a-'0'; a = getchar();}
    if(flag) n = -n;
    return n;
}

string cov(int x) {
    if(x == 0) return "0";
    string ans;
    while(x) ans += (char)(x%10+'0'),x/=10;
    reverse(ans.begin(),ans.end());
    return ans;
}

string inname = "times.in";
string outname = "times.ou";

string in,out;

int main() {
   // freopen((inname).c_str(),"r",stdin);
    for(int i = 1;i <= 10;i ++) {
        freopen((inname+cov(i)).c_str(),"r",stdin);
        int n,m;
        scanf("%d%d",&n,&m);
        //printf("%d %d\n",n,m);
        in += cov(n); in += ' '; in += cov(m); in += '\n';
        for(int i = 1;i <= n + m;i ++){
            int l,r;
            scanf("%d%d",&l,&r);
            //printf("%d %d\n",l,r);
            in += cov(l); in += ' '; in += cov(r); in += '\n';
        }
        fclose(stdin);

        freopen((outname+cov(i)).c_str(),"r",stdin);
        for(int i = 1;i <= m;i ++){
            int l;
            scanf("%d",&l);
            //printf("%d %d\n",l,r);
            out += cov(l); out += '\n';
        }
        fclose(stdin);
    }


    freopen((inname).c_str(),"w",stdout); cout << in << endl; fclose(stdout);
    freopen((outname + "t").c_str(),"w",stdout); cout << out << endl; fclose(stdout);
}
