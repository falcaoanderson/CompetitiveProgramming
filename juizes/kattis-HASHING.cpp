// 30/01/24 //
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define endl "\n"

const int NMAX = 3e5 + 10;
const ll M1 = 1e9 + 9;
const ll M2 = 1e9 + 7;
const ll p  = 31;

int q;
ll hash1[NMAX], hash2[NMAX];
string word;

ll exp(ll a, ll b, ll m=M1){ // 0^0 = 1
    ll r = 1LL;

    while(b>0LL){
        if(b&1){
            r = (r*a)%m;
            b--;
        }
        else{
            a = (a*a)%m;
            b /= 2LL;
        }
    } 

    return r;
}

ll inv_p1 = exp(p, M1-2, M1);
ll f_hash1(int l, int r){
    return ((hash1[r]-hash1[l]+M1) * exp(inv_p1, l+1, M1) )%M1;
}

ll inv_p2 = exp(p, M2-2, M2);
ll f_hash2(int l, int r){
    return ((hash2[r]-hash2[l]+M2) * exp(inv_p2, l+1, M2) )%M2;
}

int main ()
{
    ios_base :: sync_with_stdio(false);
    cin.tie();

    cin >> word >> q;

    ll pot_p1 = 1, pot_p2=1;

    for(int i = 0; i < (int)word.size(); i++){
        hash1[i + 1] = (hash1[i] + (((ll) (word[i] - 'a') + 1) * pot_p1) % M1)%M1;

        pot_p1 = (pot_p1*p)%M1;

        hash2[i + 1] = (hash2[i] + (((ll) (word[i] - 'a') + 1) * pot_p2) % M2)%M2;

        pot_p2 = (pot_p2*p)%M2;
    }

    for (int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;

        cout << f_hash1(l, r)*M2 +  f_hash2(l, r) << endl;
    }

    return 0;
}