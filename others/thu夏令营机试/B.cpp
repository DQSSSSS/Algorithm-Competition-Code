#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1000010;
const LL INF = 1e18 + 10;
const LL mod = 998244353;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int blockSize;

struct Block{
    string s;
    bool use;

};

struct FileSys {

    int fileNum,blockNum;
    Block block[SZ];
    vector<int> file[1010];
    priority_queue<int> canUseBlock;

    void add(int x,int off,char st[]) {
        int len = strlen(st);
        string source;
        for(int i = 0;i < file[x].size();i ++) {
            int id = file[x][i];
            source += block[id].s;
        }
        off = min(off,(int)source.size());
        int p = 0;
        while(p < len && p+off < source.size())
            source[p+off] = st[p],p ++;
        while(p < len && source.size() % blockSize)
            source += st[p],p ++;
        while(p < len) {
            if(canUseBlock.size() == 0) break;
            int id = -canUseBlock.top();
            canUseBlock.pop();

            file[x].push_back(id);
            block[id].use = 1;
            int t = 0;
            while(p < len && t < blockSize) {
                source += st[p];
                p ++; t ++;
            }
        }

        for(int i = 0,p = 0;i < file[x].size();i ++) {
            int id = file[x][i];
            block[id].s = "";
            for(int t = 0;t < blockSize && p < source.size();t ++) {
                block[id].s += source[p];
                p ++;
            }
        }
    }

    void del(int x,int off,int y) {
        string source;
        for(int i = 0;i < file[x].size();i ++) {
            int id = file[x][i];
            source += block[id].s;
        }
        if(off >= source.size()) return;
        y = min(y,(int)source.size() - off);
        int l = off,r = off + y - 1;

       // cout << source << " " << l << " " << r << endl;

        for(int i = l/blockSize;i <= r/blockSize;i ++) {
            int id = file[x][i];
            int L = i  * blockSize;
            int R = ((i )+1) * blockSize - 1;
        //    cout << L << " " << R << " " << blockSize << endl;
            if(l <= L && R <= r) {
                file[x][i] *= -1;
          //      cout << i << "!!\n";
                canUseBlock.push(-id);
                block[id].use = 0;
                block[id].s = "";
            }
        }
        vector<int> tmp;
        for(int id : file[x]) if(id > 0) tmp.push_back(id);
        file[x].clear();
        string ss;
        for(int i = 0;i < source.size();i ++)
            if(i < l || i > r)
                ss += source[i];
        source = ss;

        int edID = -1;
        for(int i = 0,p = 0;i < tmp.size();i ++) {
            int id = tmp[i];
            block[id].s = "";
            for(int t = 0;t < blockSize && p < source.size();t ++) {
                block[id].s += source[p];
                p ++;
                edID = i;
            }
            if(p == source.size()) break;
        }

       // printf("%d\n",edID);
       // cout << source << endl;
      //  for(int id : tmp) printf("%d ",id); puts("");

        for(int i = 0;i <= edID;i ++) {
            int id = tmp[i];
            file[x].push_back(id);
        }
        for(int i = edID + 1;i < tmp.size();i ++) {
            int id = tmp[i];
            canUseBlock.push(-id);
            block[id].use = 0;
            block[id].s = "";
        }

    }

    void printBlock(int x) {
        printf("%d ",file[x].size());
        for(int id : file[x]) printf("%d ",id);
        puts("");
    }

    void printData(int x,int off,int y) {
        string source;
        for(int i = 0;i < file[x].size();i ++) {
            int id = file[x][i];
            source += block[id].s;
        }
        if(off >= source.size()) puts("-2");
        else if(source.size() - off < y) puts("-1");
        else {
            for(int i = 0;i < y;i ++) {
                printf("%c",source[off+i]);
            }
            puts("");
        }
    }

    void init(int fileNum0,int blockNum0) {
        fileNum = fileNum0;
        blockNum = blockNum0;
        for(int i = 1;i <= blockNum;i ++) {
            canUseBlock.push(-i);
        }
    }
}fs;


char st[SZ];

int main() {
  //  freopen("B.out","w",stdout);
    int n = read(),m = read(),k = read();
    blockSize = read();
    fs.init(n,m);
    for(int oo = 1;oo <= k;oo ++) {
        char opt[2];
        scanf("%s",opt);
        if(opt[0] == 'A') {
            int x = read(),off = read();
            scanf("%s",st);
            fs.add(x,off,st);

        }
        else if(opt[0] == 'D') {
            int x = read(),off = read(),y = read();
            fs.del(x,off,y);
        }
        else if(opt[0] == 'B') {
            int x = read();
            fs.printBlock(x);
        }
        else {
            int x = read(),off = read(),y = read();
            fs.printData(x,off,y);
        }
    }
}
/*
2 8 22 3
A 2 0 aaa
B 2
C 2 0 3
A 1 10 aAbBcCdDeEfFgGhHiIjJ
B 1
C 1 0 20
A 1 1 JiIiHhGgFfEeDdCcBbAa
B 1
C 1 0 20
C 1 0 21
D 2 0 3
B 2
C 2 0 1
D 1 8 9
B 1
C 1 0 12
*/
