#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string ss;
    cin >> ss;

    vector<int> count(26);

    for(int i=0; i<(int)ss.size(); i++){
        count[int(ss[i])-65]++; 
    }

    int odd = 0;

    for(int i=0; i<=25; i++){
        if(count[i]&1) odd++;
    }
    
    if(odd==0 || (odd==1 && ((int)ss.size())&1)){
        for(int i=0; i<=25; i++){
            if(count[i]%2==0){
                for(int k=0; k<count[i]/2; k++){
                    cout << char(65+i);
                }
            }
        }
        for(int i=0; i<=25; i++){
            if(count[i]&1){
                for(int k=0; k<count[i]; k++){
                    cout << char(65+i);
                }
            }
        }
        for(int i=25; i>=0; i--){
            if(count[i]%2==0){
                for(int k=0; k<count[i]/2; k++){
                    cout << char(65+i);
                }
            }
        }
        cout << endl;
    }   
    else{
        cout << "NO SOLUTION" << endl; 
    }
    
    return 0;
}