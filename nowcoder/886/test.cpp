#include <iostream>
#include <string>
using namespace std;
int whatday(int y, int m, int d) {
    // ������ȷ�����ڡ��� 0 - 6 ��ʾ ���� 1 - 7
    if(m==1||m==2)
    {
        y--;
        m+=12;
    }
    return(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
}
string weekday[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int main() {
    int y, m, d;
    cin >> y >> m >> d;
    cout << weekday[whatday(y, m, d)] << endl;
    return 0;
}
