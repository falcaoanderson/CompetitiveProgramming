// 22/04/19 // 10:26 PM //

#include <iostream>

using namespace std;

int mdc(int a, int b){
    if(b==0) return a;

    return mdc(b, a%b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;

    while(cin >> a >> b){
        cout << 2*(a+b)/mdc(a, b) << "\n";
    }
    return 0;
}
