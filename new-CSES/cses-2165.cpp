#include <iostream>

using namespace std;

#define endl "\n"

void solve(int n, int start, int destiny){
    if(n==1){
        cout << start << " " << destiny << endl;
        return;
    }

    solve(n-1, start, 6-start-destiny);
    solve(1, start, destiny);
    solve(n-1, 6-start-destiny, destiny);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout << (1<<n)-1 << endl;
    solve(n, 1, 3);
    
    return 0;
}