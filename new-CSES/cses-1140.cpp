// 26/04/23 // dp recursiva O(n*log(n))
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
 
using namespace std;
 
#define ll long long 
#define endl "\n"
#define PB push_back

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;

int n;
ll memo[MAXN];
vector<tiii> projects;

ll solve(int i){
    if(memo[i]!=-1) return memo[i];

    if(i>=n) return 0;

    int a, b, p;
    tie(a, b, p) = projects[i];

    int ind = upper_bound(projects.begin()+i+1, projects.end(), tiii(b, INF, INF)) - projects.begin();

    return memo[i] = max(solve(i+1), p + solve(ind)); 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n;

    for(int i=0; i<n; i++){
        int a, b, p;
        cin >> a >> b >> p;

        projects.PB({a, b, p});
    }

    sort(projects.begin(), projects.end());

    memset(memo, -1, sizeof(memo));
    cout << solve(0) << endl;
    
    return 0;
}