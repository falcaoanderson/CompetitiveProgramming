// 14/04/20 // 6:00 PM //

#include <bits/stdc++.h>
using namespace std;

const int MAXN = (int)(2e5) + 10;
int h[MAXN];

int dist(int a, int b){
    return b-a+h[a]+h[b];
}

int main(){

    int n;
    cin >> n;

    for(int i=1; i<=n; i++) cin >> h[i];

    int a=1, b=2;

    for(int i=3; i<=n; i++){
        if(max(dist(a, i), dist(b, i)) >= dist(a,b)){
            if(dist(a,i) >= dist(b,i)) b = i;
            else{
                a = b;
                b = i;
            }
        }
    }

    cout << dist(a, b) << endl;

    return 0;
}
