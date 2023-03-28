// 28/03/23 //
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl "\n"

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n, 0);

    for(int i=0; i<n; i++) cin >> v[i];
    
    sort(v.begin(), v.end());

    int total=1;

    for(int i=1; i<n; i++){
        if(v[i]!=v[i-1]) total++;
    }

    cout << total << endl;

    return 0;
}