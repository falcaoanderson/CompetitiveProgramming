// 08/02/19 // 11:21 //

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int total=0;
    long long n;
    cin >> n;

    while(n!=0){
        n -= (n&-n);
        total ++;
    }
    cout << total;

    return 0;
}
