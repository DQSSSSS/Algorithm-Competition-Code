#include "lcs.h"
#include <bits/stdc++.h>
using namespace std;
void find_permutation(int n, int res[]) {
    srand(time(NULL));
    for(int i = 0; i < n; i++) res[i] = i + 1;
    for(int i = 1;i < n;i ++) {
        int l = 0,r = i+1;
        while(r-l>1) {
            int mid = l + r >>1;
            swap(res[mid],res[i]);
            int len = get_lcs(mid+1,res);
            if(len == mid+1) l = mid;
            else r = mid;
            swap(res[mid],res[i]);
        }
     //   cout << l << endl;
        for(int j = i;j > l;j --) res[j] = res[j-1];
        res[l] = i+1;
    }
}
