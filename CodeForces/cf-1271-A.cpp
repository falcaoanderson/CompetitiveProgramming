// 00/02/19 // 00:00 XX //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;

int main(){
    fastio;

    int  n;
    cin >> n;
    vector<int> v(n), seq1, seq2, vtemp;

    for(int i=0; i<n; i++){
        char temp;
        cin >> temp;
        v[i] = (temp=='W'? 0: 1);
    }

    vtemp = v;
    int op1=0;
    bool flag = true;

    while(op1<=3*n+1 && flag){
        flag = false;
        for(int i=0; i<n-1; i++){
            if(~vtemp[i]&1 || (i==n-2 && ~vtemp[i+1]&1)){
                vtemp[i]   = ~vtemp[i]&1;
                vtemp[i+1] = ~vtemp[i+1]&1;

                op1++;
                seq1.pb(i+1);
                flag=true;
            }
        }
    }

    vtemp = v;
    int op2=0;
    flag = true;
    while(op2<=3*n+1 && flag){
        flag = false;
        for(int i=0; i<n-1; i++){
            if(vtemp[i]&1 || (i==n-2 && vtemp[i+1]&1)){
                vtemp[i]   = ~vtemp[i]&1;
                vtemp[i+1] = ~vtemp[i+1]&1;

                op2++;
                seq2.pb(i+1);
                flag=true;
            }
        }
    }

    if(op1<=op2 && op1<=3*n){
        cout << op1 << endl;
        for(int i : seq1)
            cout << i << " ";
        cout << endl;
    }
    else if(op2<=3*n){
        cout << op2 << endl;
        for(int i : seq2)
            cout << i << " ";
        cout << endl;
    }
    else{
        cout << "-1\n";
    }


    return 0;
}
