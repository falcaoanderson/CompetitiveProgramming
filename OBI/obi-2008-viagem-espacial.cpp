// 05/11/20 // xx:xx PM //

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

struct ponto{
    ll x,  y;

    ponto(){}
    ponto(ll x_, ll y_){
        x = x_;
        y = y_;
    }

    ponto operator -(const ponto& temp){
        return ponto(x-temp.x, y-temp.y);
    }
};

ll cross(ponto a, ponto b){
    return (a.x*b.y - b.x*a.y);
}

int main(){
    fast_io;
    
    ponto circulo; ll r;
    int n;

    cin >> n >> circulo.x >> circulo.y >> r;

    int cont = 0;
    while(n--){
        ponto a, b;
        cin >> a.x >> a.y >> b.x >> b.y;
        
        b = (b-a);
        a = (circulo-a);

        if(cross(a, b)*cross(a, b)<= r*r*(b.x*b.x + b.y*b.y)) cont++;
    }

    cout << cont << endl;

    return 0;
}
