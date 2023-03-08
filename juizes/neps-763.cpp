// 23/05/20 // 14:02 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb push_back
#define mp make_pair

const int INF  = 0x3f3f3f3f;
const int MAXN = (int)(1e5) + 10;

set<int> mat;

int main(){
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;

        mat.insert(temp);
    }

    cout << mat.size() << endl;

    return 0;
}

