// 14/01/19 // 6:13 PM //

#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 110

struct Aeroporto{
    int id, nv;
};

int n, voos, p1, p2, cont=1;
Aeroporto v[MAXN];

bool order(Aeroporto a, Aeroporto b){
    if(a.nv!=b.nv) return a.nv > b.nv;

    return a.id < b.id;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(true){
        cin >> n >> voos; if(n==0 and voos==0) break;

        for(int i=1; i<=n; i++){
            v[i].id = i;
            v[i].nv = 0;
        }

        for(int i=0; i<voos; i++){
            cin >> p1 >> p2;
            v[p1].nv = v[p1].nv + 1;
            v[p2].nv = v[p2].nv + 1;
        }


        sort(v+1, v+n+1, order);

        v[0].nv = -10;

        cout << "Teste " << cont << endl;

        for(int i=1; i<=n; i++){
            if(v[i].nv < v[i-1].nv) break;
            cout << v[i].id << " ";
        }
        cout << endl << endl;

        cont++;
    }

    return 0;
}

