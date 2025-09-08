/*
07/09/25 
 
*/
 
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define SZ(x) (int)(x).size()
 
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
 
const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXVAL = (1e7);
const int MOD  = (1e9) + 7;
 
int v[MAXVAL+5];
 
int main(){
    fast_io;
 
    int q;
    cin >> q;
 
    for(int i=0; i*i<=MAXVAL; i++){
        for(int j=i; i*i+j*j<=MAXVAL; j++){
            v[i*i+j*j] = i;
        }
    }

    while(q--){
        int n;
        cin >> n;
 
        for(int i=0; i<=n; i++){
            int a=v[i], b=sqrt(i - v[i]*v[i]), c=v[n-i], d=(int)sqrt((n-i) - v[n-i]*v[n-i]);
            if(i==a*a+b*b && n-i==c*c+d*d){
                cout << a << " " << b << " " << c << " " << d << endl; 
                break;
            }
        }
    }
 
    return 0;
}