// 29/12/19 // 7:26 PM //

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

int main(){

    int n;
    vector<pair<int,int>> v;

    cin >> n;

    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        v.pb(mp(temp, i));
    }
    sort(v.begin(), v.end());

    for(auto i : v){
        cout << i.ss << " ";
    }

}
