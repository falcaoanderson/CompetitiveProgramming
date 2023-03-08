// 26/10/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

set<int> ticket;
unordered_map<int, int> qnt_ticket;

void remover(int num){
    qnt_ticket[num]--;

    if(qnt_ticket[num]==0)
        ticket.erase(num);
}

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;

    qnt_ticket.reserve(1<<((int)log2(n)));

    for(int i=1; i<=n; i++){
        int val;
        cin >> val;

        ticket.insert(val);
        qnt_ticket[val]++;
    }

    set<int>::iterator it;
    set<int>::reverse_iterator itr;

    for(int i=1; i<=m; i++){
        int maxp;
        cin >> maxp;

        if(ticket.empty()){
            cout << -1 << endl;
            continue;
        }
        if(qnt_ticket[maxp]>=1){
            cout << maxp << endl;
            remover(maxp);
            continue;
        }

        it = ticket.lower_bound(maxp);

        if(it==ticket.begin())
            cout << -1 << endl;
        else{
            it--;
            cout << (*it) << endl;
            remover((*it));
        }
    }

    return 0;
}

