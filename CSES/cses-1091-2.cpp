// 26/10/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

multiset<int, greater<int>> ticket;

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        int val;
        cin >> val;

        ticket.insert(val);
    }

    multiset<int, greater<int>>::iterator it;

    for(int i=1; i<=m; i++){
        int maxp;
        cin >> maxp;

        if(ticket.empty()){
            cout << -1 << endl;
            continue;
        }

        it = ticket.lower_bound(maxp);

        if(it==ticket.end()){
            cout << -1 << endl;
        }
        else{
            cout << (*it) << endl;
            ticket.erase(it);
        }

    }

    return 0;
}


