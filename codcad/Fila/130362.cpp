#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    int n,m,temp;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
    }

    cin >> m;

    for(int i=0; i<m; i++){
        cin >> temp;
        for(int j=0; j<n; j++){
            if(v[j]==temp){
                v.erase(v.begin()+j);
                break;
            }
        }
    }

    for(int i=0; i<n-m; i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}