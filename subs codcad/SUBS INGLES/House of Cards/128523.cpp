#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100005

int main(){
    int n,m;
    pair<pair< int , int >, int>v[MAXN];
    //        dvamp , ddep, d
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >>v[i].second;
        v[i].first.first = v[i].second%m;
        v[i].first.second = v[i].second/m;
    }
    sort(v,v+n);

    for(int i=n-1; i>=0; i--){
        cout<<v[i].second<<" ";
    }
    cout<<endl;
    return 0;
}
