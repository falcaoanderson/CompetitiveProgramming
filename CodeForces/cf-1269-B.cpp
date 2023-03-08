// 00/02/19 // 00:00 XX //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;

bool igual(vector<int> va, vector<int> vb, int x, int m){
    for(int &i : va) i = (i+x)%m;
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    return (va==vb);
}

int main(){
    fastio;

    int n, m;
    cin >> n >> m;
    vector<int> va(n), vb(n);

    for(int i=0; i<n; i++) cin >> va[i];
    for(int i=0; i<n; i++) cin >> vb[i];

    int resp = INF;
    for(int i : va){
        int x = (vb[0]-i)%m >=0 ? (vb[0]-i)%m : m+(vb[0]-i)%m;

        if(igual(va, vb, x, m)) resp = min(resp, x);

    }
    cout << resp << endl;

    return 0;
}
