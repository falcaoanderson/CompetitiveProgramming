#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<string> seq;
    seq.push_back("0");
    seq.push_back("1");    

    for(int i=2; i<=n; i++){
        for(int k=(int)seq.size()-1; k>=0; k--){
            string ss = "1";
            
            for(int j=0; j<(i-(int)seq[k].size()-1); j++){
                seq[k] = "0" + seq[k];
            }
            ss += seq[k];

            seq.push_back(ss);

            for(int j=0; j<(i-(int)seq[k].size()); j++){
                seq[k] = "0" + seq[k];
            }
        }
    }

    for(int i=0; i<(int)seq.size(); i++){
        cout << seq[i] << "\n";
    }

    return 0;
}