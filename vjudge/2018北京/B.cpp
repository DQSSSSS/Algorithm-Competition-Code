#include<bits/stdc++.h>
#define ll long long
using namespace std;
char s[200004];
int st[200004];
char s2[1004];
int ans[204];
vector<string>vec;
int cnt,len;
bool check(string &s){
    if(s.size()==1&&s[0]=='0')return 1;
    if(s[0]=='0')return 0;
    return 1;
}
int main(){
    cnt=0;len=0;
    ios::sync_with_stdio(false);
    while(cin.getline(s2+1,1002)){
        int l=strlen(s2+1);
        ++cnt;
        for(int i=1;i<=l;i++){
            s[i+len]=s2[i];
            st[i+len]=cnt;
        }
        len+=l;
    }
    //for(int i=1;i<=len;i++)cout<<s[i];cout<<endl;
    for(int i=1,j=1;i<=len;i++){
        if(i==len || s[i] == ' '){
            string ans = "";
            int jj = j;
            while(j<i&&isdigit(s[j])) ans+=s[j],j++;
            cout << j << " " << i << endl;
            if(j==i&&check(ans)) {
                vec.push_back(ans);
                ::ans[st[jj]] ++;
            }
            j=i+1;
        }
    }
    for(int i=0;i<vec.size();i++){
        cout<<vec[i];
        if(i!=vec.size()-1)cout<<" ";
    }
    cout<<endl;
    for(int i=1;i<=cnt;i++)cout<<ans[i]<<endl;
    return 0;
}
/**
002 02 20
02
0
a  a  2
  2 0
1 0
1
00 2
z
*/
