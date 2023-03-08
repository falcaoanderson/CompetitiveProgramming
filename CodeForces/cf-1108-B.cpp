// 23/01/19 // 10:12 PM //

#include <iostream>
#include <algorithm>

#define MAXN 140
#define MAXNI 10010
using namespace std;

bool visitado[MAXNI];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, v[MAXN];

    cin >> n;

    for(int i=0; i<n; i++) cin >> v[i];

    if(n==2){ cout << "1 1\n"; return 0;}

    sort(v, v+n);

    int a = v[n-1] ,b;
    visitado[ v[n-1] ] = 1;

    for(int i=n-2; i>=0; i--){
        if(a%v[i]!=0 || (a%v[i]==0 && visitado[v[i]]==1)){
            b = v[i];
            break;
        }
        visitado[ v[i] ] = 1;
    }

    cout << a << " " <<b << "\n";

    return 0;
}
