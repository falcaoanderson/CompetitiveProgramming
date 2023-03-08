// 14/04/20 // 18:14 PM //

#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int)(5e2) + 10;

int n, v[MAXN];

int main(){
    cin >> n;

    for(int i=0; i<n; i++) cin >> v[i];

    int resp = 1;

    for(int a=1; a<=n; a++){
        for(int b=a+1; b<=n; b++){

            int r=0, ant = -1;

            for(int i=0; i<n; i++){
                if(v[i]!=a && v[i]!=b) continue;

                if(v[i]!=ant){
                    r++;
                    ant = v[i];
                }
            }

            resp = max(resp, r);
        }
    }

    cout << resp << endl;

    return 0;
}
