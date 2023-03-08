// 30/08/19 // 13:10 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 150010
#define MAXC 20
#define ll long long


int q, aux[MAXC];
ll n, m;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> q;

    while(q--){
        cin >> n >> m;

        ll sum=0, resp=0;

        for(int i=1; i<=10; i++){
            aux[i] = (m*i)%10;
            sum += aux[i];
        }

        resp = ((n/m)/10) * sum;

        for(int i=1; i<=((n/m)%10); i++)
            resp += aux[i];

        cout << resp << "\n";
    }



    return 0;
}

