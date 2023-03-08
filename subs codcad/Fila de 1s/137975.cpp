// 08/02/19 // 11:03 //

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    if( (n&(n+1))==0LL && n!=0)
        cout << "S\n";
    else
        cout << "N\n";

    return 0;
}