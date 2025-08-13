/*
12/08/25 

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

ll exp(ll a, ll b, ll m=MOD){ // 0^0 = 1
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

int main(){
    fast_io;

    int pop_a, pop_b;
    ll c;
    cin >> pop_a >> pop_b >> c;

    int pop_c = __builtin_popcountll(c);
    bool flag_swap = 0;
    if(pop_a>pop_b){
        flag_swap = 1;
        swap(pop_a, pop_b);
    }
    
    ll a=0, b=0;
    if(pop_c>=pop_b-pop_a && pop_a+pop_b-pop_c>=0 && (pop_a+pop_b-pop_c)%2==0){
        int duplo = (pop_a+pop_b-pop_c)/2;

        for(ll i=0; i<60 && (pop_a>0 || pop_b>0); i++){
            ll bit = (1LL<<i);

            if((bit&c)!=0){ // bit de a e b sao diferentes
                if(pop_a<pop_b){
                    b += bit;
                    pop_b--;
                }
                else{
                    a += bit;
                    pop_a--;
                }
            }
            else if(duplo>0){
                a += bit;
                b += bit;
                pop_a--;
                pop_b--;
                duplo--;
            }
        }
    }

    // cout << pop_a << " " << pop_b << endl;
    // cout << a << " " << b << " " << (a^b) << endl;

    if(pop_a==0 && pop_b==0 && (a^b)==c && a<(1LL<<60LL) && b<(1LL<<60LL)){
        if(flag_swap){
            cout << b << " " << a << endl;
        }
        else{
            cout << a << " " << b << endl;
        }
    }
    else{
        cout << "-1" << endl;
    }

    return 0;
}
