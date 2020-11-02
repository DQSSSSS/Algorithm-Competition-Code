#include<bits/stdc++.h>
using namespace std;

const int SZ = 1e6 + 10;

char input[SZ];
int val[11][33],a[11];

int main() {
    int T;
    scanf("%d",&T);
    while(T --) {
        int n = 6;
        for(int i = 1;i <= n;i ++) {
            scanf("%s",input);
            int len = strlen(input);
            memset(val[i],0,sizeof val[i]);
            for(int j = 0;j < len;j ++) {
                val[i][input[j]-'a'] = 1;
            }
        }
        for(int i = 1;i <= n;i ++) a[i] = i;
        string s = "harbin";
        int ok = 0;
        do {
            bool flag = 0;
            for(int i = 1;i <= n;i ++) {
                int x = s[i-1] - 'a';
                if(!val[a[i]][x]) flag = 1;
            }
            if(!flag) {
                ok = 1;
                break;
            }
        }while(next_permutation(a+1,a+1+n));
        puts(ok ? "Yes" : "No");
    }
}
