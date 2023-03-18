#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int a, b;
        cin >> a >> b;
        
        int x = 2*b-a, y = 2*a-b;

        if(x%3==0 && y%3==0 && x>=0 && y>=0){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}