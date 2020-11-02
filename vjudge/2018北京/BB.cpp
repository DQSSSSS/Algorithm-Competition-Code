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
    for(int i=0;i<s.size();i++)if(!isdigit(s[i]))return 0;
    if(s.size()==1&&s[0]=='0')return 1;
    if(s[0]=='0')return 0;
    return 1;
}
bool godown(int st,int now){
    if(now==st)return 1;
    if(isdigit(s[now-1])&&isdigit(s[now]))return 1;
    return 0;
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
    for(int i=1;i<=len;i++){
        if(s[i]!=' '){
            bool flag=0;
            int j=i;
            while(j<=len&&s[j]!=' '&&(st[j]==st[i]||godown(i,j))){
                if(!isdigit(s[j]))flag=1;
                j++;
            }
            if(flag){
                //cout<<i<<" "<<j<<endl;
                for(int k=i;k<j;k++)s[k]=' ';
            }
            i=j-1;
        }
    }
    string now="";
    //for(int i=1;i<=len;i++)cout<<s[i];cout<<endl;
    for(int i=1;i<=len;i++){
        if(s[i]!=' '){
            now="";
            int j=i;
            while(j<=len&&s[j]!=' '){
                now+=s[j];
                j++;
            }
            if(check(now)){
                vec.push_back(now);
                ans[st[i]]++;
            }
            i=j-1;
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

