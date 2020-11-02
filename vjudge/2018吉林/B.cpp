#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int main() {
    int T,cc = 0;
    scanf("%d",&T);
    map<string,int> mp;
    mp["Beijing"] = 8;
    mp["Washington"] = -5;
    mp["London"] = 0;
    mp["Moscow"] = 3;
    while(T --) {
        int h,m;
        string s,name1,name2;
        scanf("%d:%d",&h,&m);
        cin >> s >> name1 >> name2;
        h %= 12;
        if(s == "PM") h += 12;
        int delta = mp[name2] - mp[name1];
        h += delta;
        //cout << h << endl;
        string rq;
        if(h >= 24) rq = "Tomorrow";
        else if(h < 0) rq = "Yesterday";
        else rq = "Today";
        h += 24; h %= 24;
        string ans;
        if(h <= 11) ans = "AM";
        else ans = "PM",h -= 12;
        if(h == 0) h = 12;
        printf("Case %d: %s %d:%02d %s\n",++ cc,rq.c_str(),h,m,ans.c_str());
    }
}
