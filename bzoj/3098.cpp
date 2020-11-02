#include<ctime>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
    srand(19260817);
    int n = 100000,m = 20;
    printf("%d %d\n",n,m);
    for(int i = 1;i <= n;i ++)
        printf("%c",'a' + rand() % 26);
    return 0;
}
