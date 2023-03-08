// 29/09/20 // 7:00 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int c[5];
int v[10], q[10];
int memo[5][105][20][20][20];

bool solve(int i, int val, int q1, int q2, int q3){
    int& ans = memo[i][val][q1][q2][q3];

    if(ans!=-1) return ans;

    if(val==0){
        if(i==3) return 1;
        else return solve(i+1, c[i+1], q1, q2, q3);
    }

    bool t1=0, t2=0, t3=0;
    if(val-v[1]>=0 && q1>0) t1 = solve(i, val-v[1], q1-1,   q2,   q3);
    if(val-v[2]>=0 && q2>0) t2 = solve(i, val-v[2],   q1, q2-1,   q3);
    if(val-v[3]>=0 && q3>0) t3 = solve(i, val-v[3],   q1,   q2, q3-1);

    return ans = t1 || t2 || t3;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        cin >> c[1] >> c[2] >> c[3];
        for(int i=1; i<=3; i++) cin >> q[i] >> v[i];

        memset(memo, -1, sizeof(memo));

        if(solve(1, c[1], q[1], q[2], q[3]))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
