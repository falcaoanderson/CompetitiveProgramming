// 28/05/19 // 10:31 AM //

#include <iostream>

using namespace std;

#define MAXN 200010

int n;
pair<char, int> v[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=0; i<n; i++){
        int a, b;
        char l;

        cin >> a >> l >> b;

        v[a] = make_pair(l,b);
    }

    int temp=0;
    while(temp!=1){
        cout << v[temp].first;
        temp = v[temp].second;
    }

    cout << "\n";

    return 0;
}
