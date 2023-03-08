// 27/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e6) + 10;
const int MAXIND = (1e3)+10;

int n, qnt_indios;  
pii indio[MAXIND];
bool inicial[MAXN], atual[MAXN];

int mod(int a, int b){
    return (a%b<0 ? b + a%b : a%b);
}

int main(){
    fast_io;

    cin >> n >> qnt_indios;

    for(int i=1; i<=qnt_indios; i++){
        int pos, dir;
        cin >> pos >> dir;

        indio[i] = {pos-1, dir};
        inicial[pos-1] = 1; 
    }

    sort(indio+1, indio+1+qnt_indios);

    int resp = INF;

    for(int i=2; i<=qnt_indios; i++){
        memset(atual, 0, sizeof(atual));

        int time = indio[i].first - indio[1].first;
        if(indio[1].second == -1) time = n - time;

        bool flag=0;

        for(int j=1; j<=qnt_indios; j++){
            int newpos = mod(indio[j].first + time*indio[j].second, n);

            if(!inicial[newpos] || atual[newpos]){flag = 1;break;}

            atual[newpos] = 1;
        }

        if(flag) continue;
        
        resp = min(resp, time);
    }

    if(resp==INF) cout << n << endl;
    else          cout << resp << endl;

    return 0;
}
