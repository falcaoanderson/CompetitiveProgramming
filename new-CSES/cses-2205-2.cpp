#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<int> seq;
    seq.push_back(0);
    seq.push_back(1);    

    for(int i=2; i<=n; i++){
        for(int k=(1<<(i-1))-1; k>=0; k--){
            int ss = (1<<(i-1));
            
            seq.push_back(ss|seq[k]);
        }
    }

    for(int i=0; i<(1<<n); i++){
     
        for(int k=n-1; k>=0; k--){
            cout << (((1<<k)&seq[i])!=0);
        }
        cout << "\n";
    
    }

    return 0;
}