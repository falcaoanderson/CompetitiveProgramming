// 08/06/23 //
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
#include <stack>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int main(){
    fast_io;

    int n;

    while(cin >> n){
        if(n==0) break;
        
        stack<int> pilha;
        queue<int> fila;
        priority_queue<int> pri_fila;

        bool flag_pilha=1, flag_fila=1, flag_pri_fila=1;

        while(n--){
            int op, x;
            cin >> op >> x;

            if(op==1){
                pilha.push(x);
                fila.push(x);
                pri_fila.push(x);
            }
            else{
                if(pilha.empty()){
                    flag_pilha = flag_fila = flag_pri_fila = false;
                    continue;
                }

                int vpilha = pilha.top();
                pilha.pop();

                int vfila = fila.front();
                fila.pop();

                int v_pri_fila = pri_fila.top();
                pri_fila.pop();

                flag_pilha = flag_pilha && (vpilha == x);
                flag_fila  = flag_fila  && (vfila == x);
                flag_pri_fila = flag_pri_fila && (v_pri_fila==x);
            }
        }

        if(!flag_pilha && !flag_fila && !flag_pri_fila){
            cout << "impossible" << endl;
        }
        else if((flag_pilha&&flag_fila) || (flag_pilha&&flag_pri_fila) || (flag_fila&&flag_pri_fila)){
            cout << "not sure" << endl;
        }
        else if(flag_pilha){
            cout << "stack" << endl;
        }
        else if(flag_fila){
            cout << "queue" << endl;
        }
        else{
            cout << "priority queue" << endl;
        }
    }

    return 0;
}
