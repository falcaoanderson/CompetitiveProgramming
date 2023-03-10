// 14/01/19 // 5:16 PM //

#include <iostream>
using namespace std;

unsigned long long n, m, i;

unsigned long long mdc(long long x, long long y){
    if(y==0LL) return x;
    return mdc(y, x%y);
}

int main(){
    cin >> n >> m;

    for(i=m; i>=1; i--){
        if(mdc(n,i)==1LL){
            cout << i << endl;
            break;
        }
    }

    return 0;
}
