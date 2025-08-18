// 16/08/25
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    int resp = 1e9;
    
    for(int x=0; x<n; x++){
        int cost=0;
        
        for(int i=0; i<n; i++){
            cost += v[i] * (abs(x-i) + i + x) * 2;
        }
        
        resp = min(cost, resp);
    }
    cout << resp << endl;

    return 0;
}