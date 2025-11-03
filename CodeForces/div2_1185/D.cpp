/*
06/10/25 

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
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;
    
    int n;
    cin >> n;
    vector<pii> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].FF;
        v[i].SS = i+1;
    }
    sort(v.begin(), v.end());

    if(n<=3){
        cout << 1 << endl;
        return 0;
    }
    if(3<n && n<=100){
        int resp = 0;
        
        for(int j=0; j<n; j++){
            int last=INF, dif=INF;
            bool flag = 1;

            for(int i=0; i<n; i++){
                if(i==j) continue;
                
                if(last!=INF){
                    int crr_dif = v[i].FF-last;

                    if(dif==INF){
                        dif=crr_dif;
                    }
                    else if(dif!=crr_dif){
                        flag = 0;
                        break;
                    }
                }

                last = v[i].FF;
            }

            if(flag){
                resp = v[j].SS;
                break;
            }
        }

        cout << (resp!=0? resp: -1) << endl;
        
        return 0;
    }

    int resp = -1;
    int a=INF, qa=0, b=INF, qb=0, c=INF, qc=0;

    for(int i=1; i<n; i++){
        int d = v[i].FF - v[i-1].FF;

        if(a==INF || d==a){
            a = d;
            qa++;
        }
        else if(b==INF || d==b){
            b = d;
            qb++;
        }
        else if(c==INF || d==c){
            c = d;
            qc++;
        }
        else{
            cout << -1 << endl;
            return 0;
        }
    }

    if(qa < qb){
        swap(qa, qb);
        swap(a, b);
    }
    if(qa < qc){
        swap(qa, qc);
        swap(a, c);
    }
    if(qb < qc){
        swap(qb, qc);
        swap(b, c);
    }
    
    if(qb>2 || qc>1 || (qc==1 && qb>1)){
        cout << -1 << endl;
        return 0;
    }
    
    resp = 0;

    if(qb==0){
        resp = v[0].SS;
    }
    if(qb==1){
        if(v[1].FF-v[0].FF==b)
            resp = v[0].SS;
        if(v[n-1].FF-v[n-2].FF==b)
            resp = v[n-1].SS;
    }
    if(qb==2){
        for(int i=1; i+1<n && 2*b==a; i++){
            int d1 = v[i].FF-v[i-1].FF;
            int d2 = v[i+1].FF-v[i].FF;
            
            if(d1==b && d2==b){
                resp = v[i].SS;
                break;
            }
        }
    }
    if(qc==1){
        for(int i=1; i+1<n && b+c==a; i++){
            int d1 = v[i].FF-v[i-1].FF;
            int d2 = v[i+1].FF-v[i].FF;
            if(d1<d2) swap(d1, d2);
            
            if(d1==b && d2==c){
                resp = v[i].SS;
                break;
            }
        }
    }

    cout << (resp!=0? resp: -1) << endl;

    return 0;
}
