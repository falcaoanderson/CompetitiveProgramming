// 21/03/23 // 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl "\n"

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> desired(n, 0), ap(m, 0);

    for(int i=0; i<n; i++) cin >> desired[i];
    for(int i=0; i<m; i++) cin >> ap[i];

    sort(desired.begin(), desired.end());
    sort(ap.begin(), ap.end());

    int last = 0;
    int ans = 0;

    for(int i=0; i<n; i++){
 
        while(ap[last]+k < desired[i] && last<m){
            last++;
        }

        if(last >= m) break;

        if(ap[last]-k <= desired[i] && desired[i] <= ap[last]+k){
            ans++;
            last++;
        }
    }

    cout << ans << endl;

    return 0;
}