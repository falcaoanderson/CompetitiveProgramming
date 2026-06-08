/*
19/01/26

*/

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;

    while(cin >> a >> b >> c){
        if(a==0 && b==0 && c==0){
            break;
        }

        if(2*b == a + c && a!=b){
            cout << "AP " << c + b - a << endl; 
        }
        else{
            cout << "GP " << c * (b / a) << endl;
        }
    }
    return 0;
}