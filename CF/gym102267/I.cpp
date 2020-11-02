#include<bits/stdc++.h>
using namespace std;

const int SZ = 1e6 + 10;

stack<int> S;
int fa[SZ];
char s[SZ];

bool isdig(char c) {
    return '0' <= c && c <= '9';
}

int main() {
    int n;
    scanf("%d%s",&n,s);
    int len = strlen(s);
    S.push(0);
    for(int i = 0;i < len;) {
        if(s[i] == '(') {
            i ++;
        }
        else if(s[i] == ')') {
            S.pop();
            i ++;
        }
        else {
            int id = 0;
            while(i < len && isdig(s[i])) id = id * 10 + s[i] - '0',i ++;
            fa[id] = S.top();
            S.push(id);
        }
       // cout << i <<endl;
    }
    for(int i = 1;i <= n;i ++) printf("%d ",fa[i]);
}

