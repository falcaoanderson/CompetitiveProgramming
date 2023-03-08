// 01/10/19 // 11:25 AM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 500010
#define x first
#define y second
#define ll long long

typedef pair<ll, ll> pii;

int n;
ll p, q, cont=0;
pii pontos[MAXN];

int main(){

    cin  >> n >> p >> q;

    for(int i=1; i<=n; i++){
        cin >> pontos[i].x >> pontos[i].y;
    }
    sort(pontos+1, pontos+n+1);


    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){

            if(q>0){
                if(q*pontos[j].y - p*pontos[j].x >= (q*pontos[i].y - p*pontos[i].x))
                    cont++;
            }
            else{
                if(q*pontos[j].y - p*pontos[j].x <= (q*pontos[i].y - p*pontos[i].x))
                    cont++;
            }
        }
    }

    cout << cont << "\n";

    return 0;
}

