// 10/02/19 // 2:41 PM //

#include <iostream>
#include <set>

using namespace std;

#define MAXK 45

int n, k;
set<int> mult;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for(int i=0; i<k; i++){
        int temp;
        cin >> temp;

        for(int j=1; j<=n/temp; j++){
            mult.insert(temp*j);
        }
    }

    cout << n - mult.size() << "\n";

    return 0;
}
