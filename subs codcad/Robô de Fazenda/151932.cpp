// 15/12/19 // 3:44 PM //

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"

int n, c, s;

int main(){
    fast_io;

    cin >> n >> c >> s;

    int pos = 0, resp=0;
    s--;

    if(pos==s) resp++;

    while(c--){
        int temp;
        cin >> temp;
        pos = ( (pos+temp)%n>=0? (pos + temp)%n: n + (pos + temp)%n );

        if(pos==s) resp++;
    }

    cout << resp << endl;

    return 0;
}
