/*
04/03/24 
Problem: 
Complexity:
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

void solve(int n, int f){
    vector<int> left, right;
    int mid = n/2;

    for(int i=0; i<n; i++){
        int val;
        cin >> val;

        if(i<mid) left.PB(val);
        else      right.PB(val);
    }

    map<int, vector<int>> possibles;

    for(int mask=0; mask<(1<<mid); mask++){
        int left_sum = 0;

        for(int i=0; i<mid; i++){
            if(mask&(1<<i)){
                left_sum += left[i];
            }
            else{
                left_sum -= left[i];
            }
        }

        possibles[left_sum].PB(mask);
    }

    vector<int> resp(n, -1);

    for(int right_mask=0; right_mask<(1<<(n-mid)); right_mask++){
        int sum = 0;

        for(int i=0; i<(n-mid); i++){
            if(right_mask&(1<<i)){
                sum += right[i];
            }
            else{
                sum -= right[i];
            }
        }

        auto it = possibles.find(f-sum);
        if(it!=possibles.end()){
            for(int i=0; i<(n-mid); i++){
                int sign = ((right_mask&(1<<i))!=0);

                if(resp[mid+i]==-1){
                    resp[mid+i] = sign;
                }
                else if(resp[mid+i]!=sign){
                    resp[mid+i] = 2;
                }
            }

            for(int left_mask : (it->second)){
                for(int i=0; i<mid; i++){
                    int sign = ((left_mask&(1<<i))!=0);

                    if(resp[i]==-1){
                        resp[i] = sign;
                    }
                    else if(resp[i]!=sign){
                        resp[i] = 2;
                    }
                }
            }

            (it->second).clear();
        }
    }

    if(resp[0]==-1){
        cout << "*" << endl;
    }
    else{
        for(int i=0; i<n; i++){
            if(resp[i]==0) cout << '-';
            if(resp[i]==1) cout << '+';
            if(resp[i]==2) cout << '?';
        }
        cout << endl;
    }

}   

int main(){
    fast_io;

    int n, f;
    while(true){
        cin >> n >> f;

        if(n==0) break;

        solve(n, f);   
    }

    return 0;
}
