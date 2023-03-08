// 12/06/19 // 2:17 PM //

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

#define MAXN 20
#define MAXK (1<<17)
#define INF 2000000000

typedef pair<double, double> PAR;

int n, t;
PAR cord[MAXN];

double memo[MAXK];

double dist(int i, int j){

    PAR a = cord[i];
    PAR b = cord[j];

    a.first  = a.first  - b.first;
    a.second = a.second - b.second;

    return sqrt(a.first*a.first + a.second*a.second);
}

double funcao(int i, int mask){
    if(memo[mask]>=0) return memo[mask];

    if( (mask==((1<<n)-1)) ) return memo[mask] = 0;

    if( (mask&(1<<i-1))!=0 ) return memo[mask] =funcao(i+1, mask);

    mask |= 1<<i-1;

    memo[mask]=INF;

    for(int k=1; k<=n; k++)
        if( (mask&(1<<(k-1)))==0)
            memo[mask] = min(memo[mask], dist(i, k) + funcao(i+1, mask|1<<(k-1)));

    return memo[mask];
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    for(int l=0; l<t; l++){

        memset(memo, -1, sizeof(memo));

        cin >> n;

        for(int i=1; i<=n; i++)
            cin >> cord[i].first >> cord[i].second;

        cout.precision(2);
        cout.setf(ios::fixed);

        cout << funcao(1, 0) << "\n";

    }

    return 0;
}
