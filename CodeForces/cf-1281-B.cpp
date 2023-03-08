// 20/01/20 // 10:06 AM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;

bool testa(string a, string c){
    string prefix_c="";
    int sz = min(a.size(), c.size());

    for(int i=0; i<sz; i++){
        prefix_c += c[i];
        if(prefix_c==a && a!=c) return 1;
    }
    for(int i=0; i<sz; i++)
        if(a[i]!=c[i]) return a[i]<c[i];

    return 0;
}

int main(){
    fastio;

    int t;
    cin >> t;

    while(t--){
        string a, c, sorted_a;

        cin >> a >> c;

        sorted_a = a;
        sort(sorted_a.begin(), sorted_a.end());

        bool flag = false;
        for(int i=0; i<(int)a.size(); i++){
            if(a[i]!=sorted_a[i]){
                 for(int j=(int)a.size()-1; j>=0; j--)
                    if(a[j]==sorted_a[i]){
                        swap(a[i], a[j]);
                        flag = true;
                        break;
                    }
            }
            if(flag) break;
        }

        if(testa(a, c))
            cout << a << endl;
        else
            cout << "---" << endl;
    }

    return 0;
}
