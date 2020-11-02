#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 + 10;

string s[SZ];
map<string,string> dy;
map<string,int> no,yes;

char input[222];

int main() {
    int n,m;
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++) {
        scanf("%s",input);
        s[i] = input;
    }
    scanf("%d",&m);
    for(int i = 1;i <= m;i ++) {
        scanf("%s",input);
        string ss = input;
        scanf("%s",input);
        string ss2 = input;
        dy[ss] = ss2;
        scanf("%s",input);
        if(input[0] == 'i') no[ss] ++;
        else yes[ss] ++;
    }
    LL all = 1,dui = 1;
    for(int i = 1;i <= n;i ++) {
        string ss = s[i];
        all *= yes[ss] + no[ss];
        dui *= yes[ss];
    }
    if(all == 1) {
        for(int i = 1;i <= n;i ++) {
            printf("%s ",dy[s[i]].c_str());
        }
        puts("");
        if(!dui) puts("incorrect");
        else puts("correct");
    }
    else {
        printf("%lld correct\n%lld incorrect",dui,all-dui);
    }
}
