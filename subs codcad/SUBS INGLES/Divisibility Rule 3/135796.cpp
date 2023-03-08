// 13/01/19 // 00:39 AM //

#include <iostream>
using namespace std;

int main(){
    string num;
    cin >> num;

    int total_p=0, total_i=0;

    for(int i=0; i<num.size(); i+=2) total_i += (num[i]-'0');
    for(int i=1; i<num.size(); i+=2) total_p += (num[i]-'0');

    if((total_p*10+total_i)%11==0)
        cout << "S\n";
    else
        cout << "N\n";

    return 0;
}
