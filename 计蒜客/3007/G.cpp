#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-8;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

char s[SZ];

int main() {
    int T = read();
    while(T --) {
        scanf("%s",s);
        int a = read();
        int len = strlen(s);
        LL n = 0;
        if(len > 16) {
            double ans = ((3 + sqrt(69)) * a) / 10;
            printf("%.10f\n",ans);
        }
        else {
            for(int i = 0;i < len;i ++) n = n * 10 + s[i] - '0';
            long double A = 5.0/3;
            for(int i = 2;i <= n;i ++) {
                long double B = 1+(2*A+1)/(3*A+2);
                if(fabs(A-B) < 1e-8) break;
                A = B;
            }
            printf("%.10f\n",(double)A*a);
        }
    }
}
/**
biao[1]= new BigDecimal("1.6666666666666666666");
biao[2]= new BigDecimal("1.6190476190476190476");
biao[3]= new BigDecimal("1.6180555555555555555");
biao[4]= new BigDecimal("1.6180344478216818642");
biao[5]= new BigDecimal("1.6180339985218033998");
biao[6]= new BigDecimal("1.6180339889579020013");
biao[7]= new BigDecimal("1.6180339887543225376");
biao[8]= new BigDecimal("1.6180339887499890970");
biao[9]= new BigDecimal("1.6180339887498968544");
biao[10]=new BigDecimal("1.6180339887498948909");
biao[11]=new BigDecimal("1.6180339887498948491");
biao[12]=new BigDecimal("1.6180339887498948482");
biao[13]=new BigDecimal("1.6180339887498948482");
biao[14]=new BigDecimal("1.6180339887498948482");
biao[15]=new BigDecimal("1.6180339887498948482");
biao[16]=new BigDecimal("1.6180339887498948482");
biao[17]=new BigDecimal("1.6180339887498948482");
biao[18]=new BigDecimal("1.6180339887498948482");
biao[19]=new BigDecimal("1.6180339887498948482");
biao[20]=new BigDecimal("1.6180339887498948482");
biao[21]=new BigDecimal("1.6180339887498948482");
biao[22]=new BigDecimal("1.6180339887498948482");
biao[23]=new BigDecimal("1.6180339887498948482");
biao[24]=new BigDecimal("1.6180339887498948482");
biao[25]=new BigDecimal("1.6180339887498948482");
biao[26]=new BigDecimal("1.6180339887498948482");
biao[27]=new BigDecimal("1.6180339887498948482");
biao[28]=new BigDecimal("1.6180339887498948482");
biao[29]=new BigDecimal("1.6180339887498948482");
biao[30]=new BigDecimal("1.6180339887498948482");
biao[31]=new BigDecimal("1.6180339887498948482");
biao[32]=new BigDecimal("1.6180339887498948482");
biao[33]=new BigDecimal("1.6180339887498948482");
biao[34]=new BigDecimal("1.6180339887498948482");
biao[35]=new BigDecimal("1.6180339887498948482");
biao[36]=new BigDecimal("1.6180339887498948482");
biao[37]=new BigDecimal("1.6180339887498948482");
biao[38]=new BigDecimal("1.6180339887498948482");
biao[39]=new BigDecimal("1.6180339887498948482");
biao[40]=new BigDecimal("1.6180339887498948482");
biao[41]=new BigDecimal("1.6180339887498948482");
biao[42]=new BigDecimal("1.6180339887498948482");
biao[43]=new BigDecimal("1.6180339887498948482");
biao[44]=new BigDecimal("1.6180339887498948482");
biao[45]=new BigDecimal("1.6180339887498948482");
biao[46]=new BigDecimal("1.6180339887498948482");
biao[47]=new BigDecimal("1.6180339887498948482");
biao[48]=new BigDecimal("1.6180339887498948482");
biao[49]=new BigDecimal("1.6180339887498948482");
biao[50]=new BigDecimal("1.6180339887498948482");
biao[51]=new BigDecimal("1.6180339887498948482");
biao[52]=new BigDecimal("1.6180339887498948482");
biao[53]=new BigDecimal("1.6180339887498948482");
biao[54]=new BigDecimal("1.6180339887498948482");
biao[55]=new BigDecimal("1.6180339887498948482");
biao[56]=new BigDecimal("1.6180339887498948482");
biao[57]=new BigDecimal("1.6180339887498948482");
biao[58]=new BigDecimal("1.6180339887498948482");
biao[59]=new BigDecimal("1.6180339887498948482");
biao[60]=new BigDecimal("1.6180339887498948482");
biao[61]=new BigDecimal("1.6180339887498948482");
biao[62]=new BigDecimal("1.6180339887498948482");
biao[63]=new BigDecimal("1.6180339887498948482");
biao[64]=new BigDecimal("1.6180339887498948482");
*/
