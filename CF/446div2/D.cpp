#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

pii a[SZ];
int n,b[SZ];

int main()
{
    cin >> n;
    for(int i = 1;i <= n;i ++) cin >> a[i].x,a[i].y = i;
    sort(a + 1,a + 1 + n);
    for(int i = 1;i <= n - 1;i ++)
        b[a[i + 1].y] = a[i].x;
    b[a[1].y] = a[n].x;
    for(int i = 1;i <= n;i ++)
        cout << b[i] << " ";
    return 0;
}
/*


*/
