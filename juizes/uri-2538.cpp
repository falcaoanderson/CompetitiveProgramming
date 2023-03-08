// 11/12/19 // 8:34 //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010

int ip, m;
int bit[MAXN];

void update(int x){
    for( ; x<MAXN; x+=(x&-x))
        bit[x]++;
}
int query(int x){
    int tsum = 0;

    for( ; x>0; x-=(x&-x))
        tsum += bit[x];

    return tsum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int pc, na, resp, ini, fim;
    while(cin >> ip >> m && ip!=-1){
        memset(bit, 0, sizeof(bit));

        resp=0;
        while(m--){
            cin >> pc >> na;

            if(query(min(pc + ip, MAXN-10))-query(max(pc - ip -1, 0)) <= na){
                update(pc);
                resp++;
            }
        }

        cout << resp << "\n";
    }

    return 0;
}
