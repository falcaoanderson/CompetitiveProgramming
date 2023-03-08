// 06/06/19 // 6:21 PM //

#include <iostream>

using namespace std;

#define MAXN 10010

int n, q, t;
long long mask[MAXN];

int qnt_ligados(long long a){
    int qnt = 0;

    while(a!=0){
        qnt++;
        a -= ( a&(-a) );
    }

    return qnt;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    for(int z=0; z<t; z++){

        int qnt, bit;

        cin >> n;

        for(int i=1; i<=n; i++){

            cin >> qnt;

            mask[i] = 0LL;

            for(int j=0; j<qnt; j++){

                cin >> bit;

                mask[i] |= (1LL<<bit);
            }
        }

        cin >> q;

        for(int i=0; i<q; i++){
            int a, b, c;

            cin >> a >> b >> c;

            if(a==1)
                cout << qnt_ligados(mask[b]&mask[c]) << "\n";
            else
                cout << qnt_ligados(mask[b]|mask[c]) << "\n";
        }

    }

    return 0;
}
