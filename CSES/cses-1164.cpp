// 28/10/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int main(){
    fast_io;

    int n;
    cin >> n;
    vector< pair< pair<int,int>, int> > costumer(n);

    for(int i=0; i<n; i++){
        cin >> costumer[i].first.first >> costumer[i].first.second;
        costumer[i].second = i;
    }
    sort(costumer.begin(), costumer.end());

    priority_queue<pii, vector<pii>, greater<pii> > quartos;
    vector<int> resp(n);

    for(int i=0; i<n; i++){

        if(i==0 || quartos.top().first>=costumer[i].first.first){
            quartos.push( mp(costumer[i].first.second, (int)quartos.size()+1));
            
            resp[ costumer[i].second ] = quartos.size();
        }
        else{
            int id = quartos.top().second;
            quartos.pop();
            quartos.push(mp(costumer[i].first.second, id));

            resp[ costumer[i].second ] = id;
        }
    }

    cout << quartos.size() << endl;
    for(int i: resp)
        cout << i << " ";
    cout << endl;

    return 0;
}
