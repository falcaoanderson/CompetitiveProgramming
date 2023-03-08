// 13/10/20 // 5:45 PM //

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, b;
    cin >> n >> b;

    vector<int> bits(n);

    for(int i=0; i<n; i++) cin >> bits[i];
    sort(bits.begin(), bits.end());

    int qnt=0, i=0, j=n-1;

    while(i<=j){
        if(i==j){
            qnt++;
            break;
        }
        if(bits[i]+bits[j]<=b){
            qnt++;
            j--;
            i++;
        }
        else{
            qnt++;
            j--;
        }
    }

    cout << qnt << endl;

    return 0;
}
