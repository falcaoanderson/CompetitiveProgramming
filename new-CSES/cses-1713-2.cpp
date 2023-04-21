// 21/04/23 //
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>

using namespace std;

#define ll long long 
#define endl "\n"

const int MAXN = 1e6+5;

int sieve[MAXN];

void init_sieve(int n){
    for(int i=2; i<=n; i++){
        if(sieve[i]) continue;

        for(int j=i; j<=n; j+=i) sieve[j] = i;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    init_sieve(1000000);

    while(n--){
        int a;
        cin >> a;

        int count=1;

        while(a>1){
            int qnt = 0, p = sieve[a];

            while(a%p==0){
                qnt += 1;
                a /= p;
            }

            count *= (qnt+1); 
        }

        cout << count << endl;
    }

    return 0;
}