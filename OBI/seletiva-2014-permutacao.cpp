// 29/08/19 // 12:32 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000010
#define pb push_back

int n;
vector<int> antes
vector<int> depois;
vector<int> resp;

int main(){
    cin >> n;

    for(int i=1; i<=n; i++) cin >> antes[i];
    for(int i=1;  i<n; i++) cin >> depois[i];

    for(int i=1; i<=n; i++){
        int aux1=0, aux2=0;

        for(int j=1; j<n; j++){
            if(depois[j]>=i)
                aux1++;
            else
                aux2++;
        }

        if(aux1==n-i && aux2==i-1)
            resp.pb(i);
    }

    for(int i=0; i<resp.size(); i++)
        cout << resp[i] << " ";
    cout << "\n";

    return 0;
}
