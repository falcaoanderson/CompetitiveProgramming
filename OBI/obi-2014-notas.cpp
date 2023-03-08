// 31/05/20 // 7:45 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int MAXN = (int)(2e2) + 10;

int n, v[MAXN];

int main(){

    cin >> n;
    for(int i=1; i<=n; i++) cin >> v[i];
    sort(v+1, v+n+1);

    int freq = 1, mfreq=-1, r=v[n];
    v[0] = v[n+1] = -1;

    for(int i=1; i<=n+1; i++){
        if(v[i]==v[i-1])freq++;
        else{
            if(freq>=mfreq){
                mfreq = freq;
                r = v[i-1];
            }

            freq = 1;
        }
    }

    cout << r << endl;

    return 0;
}
