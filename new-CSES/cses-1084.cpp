// 20/03/23 // 

/* terminar depois
#include <iostream>
#include <vector>

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

    for(int i=0; i<m; i++){
        if(last >= m) break;

        if(desired[i]-k<=ap[last]){
            if(ap[last]<=desired[i]+k){
                ans++;
                last++;
            }
        }
    
    }

    return 0;
}