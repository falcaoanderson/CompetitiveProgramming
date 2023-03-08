// 15/02/19 // 8:56 AM //

#include <iostream>

using namespace std;

#define MAXN 200010

int n;
pair<int, char> v[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=0; i<n; i++){
        int a, c;
        char b;

        cin >> a >> b >> c;

        v[a] = make_pair(c, b);
    }

    int  temp=0;
    string saida="";

    for(int i=0; i<n; i++){
        saida += v[temp].second;
        temp = v[temp].first;
    }


    cout << saida << "\n";


    return 0;
}
