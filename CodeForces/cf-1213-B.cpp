// 30/08/19 // 12:34 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 150010
#define INF 0x3f3f3f3f

int t, n;
int v[MAXN], sufix[MAXN];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while(t--){
        cin >> n;

        sufix[n+1] = INF;

        for(int i=1; i<=n; i++){
            cin >> v[i];
        }
        for(int i=n; i>=1; i--){
            sufix[i]=min(sufix[i+1], v[i]);
        }

        int resp=0;

        for(int i=1; i<=n; i++){
            if(v[i]>sufix[i+1])
                resp++;
        }

        cout << resp << "\n";
    }

    return 0;
}
