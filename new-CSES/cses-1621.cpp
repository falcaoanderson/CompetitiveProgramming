// 20/03/23 // 

#include <iostream>
#include <unordered_set>

using namespace std;

#define endl "\n"

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    unordered_set<int> v;

    for(int i=0; i<n; i++){
        int k;
        cin >> k;

        v.insert(k);
    }

    cout << v.size() << endl;

    return 0;
}