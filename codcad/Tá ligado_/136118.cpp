// 15/01/19 // 11:30 PM //

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

#define MAXN 100010

set< pair<int, int> > conjunto;

int n, m;
int t, a, b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0; i<m; i++){
        cin >> t >> a >> b;
        if(a>b)swap(a,b);

        if(!t){
            if( conjunto.find(make_pair(a,b))!=conjunto.end() )
                cout << "1\n";
            else
                cout << "0\n";
        }
        else{
            conjunto.insert( make_pair(a,b) );
        }
    }

    return 0;
}
