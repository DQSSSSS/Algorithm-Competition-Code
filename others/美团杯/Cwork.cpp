#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 2000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

bool isNum(char c) {
    return '0' <= c && c <= '9';
}

string rList;
int rListP = 0;

void ask() {
    assert(rListP == rList.size());
    return rList[rListP ++];
}

void getList() {
    freopen("C/C.out","r",stdin);
    string s;
    string ans;
    int line = 0;
    while(getline(cin,s)) {
        line ++;
        if(s.substr(0,8) == "You keep") {
            int i = 0;
            vector<int> vec;
            while(i < s.size()) {
                int num = 0;
                while(i < s.size() && !isNum(s[i])) i ++;
                while(i < s.size() && isNum(s[i])) {
                    num = num * 10 + s[i] - '0';
                    i ++;
                }
                while(i < s.size() && !isNum(s[i])) i ++;
                vec.push_back(num);
               // cout << num << " ";
            }
         //   cout << endl;
            string c = "rbg";
            for(int j = 0;j < 3;j ++) {
                if(vec[j]) {
                    ans += c[j];
                //    cout << c[j];
                }
            }
        }
    }
    rList = ans;
    fclose(stdin);
    freopen("CON","r",stdin);
}

const int n = 13,m = 17;

string s[20] = {
"#################",
"##### Bb?Gr######",
"##### ###########",
"#?RbR GgR?B??####",
"##### ###########",
"#?GrG BGR?????###",
"##### ###########",
"#?BgB G?G???Rb###",
"##### ###########",
"#   R RrG?B???Bg#",
"# ? G ###########",
"#P  B?RRRGGGBBB@#",
"#################"
};

bool isin(int x,int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}




int main() {
    getList();
    freopen("Copt.out","w",stdout);
    while(1) {

    }
}
/*
BRBGGGGGBGRBBBGBGBGBGBGGBGGBBBBB
*/

