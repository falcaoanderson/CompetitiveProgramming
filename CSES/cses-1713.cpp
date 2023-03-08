// 15/11/20 // xx:xx PM //

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
const int MAXV = (1e6);

bool eh_primo[MAXV+10];
vector<int> primos;

int factors(int val){
    int resp = 1;

    for(int i=2; i*i<=val; i++){
        int cont = 1;
        while(val%i==0){
            cont++;
            val /= i;
        }
        resp *= cont;   
    }
    if(val>1) resp *= 2;
    
    return resp;
}

int main(){
    fast_io;
 
    int n;
    cin >> n;

    while(n--){
        int val;
        cin >> val;

        cout << factors(val) << endl;
    }

    return 0;
}
