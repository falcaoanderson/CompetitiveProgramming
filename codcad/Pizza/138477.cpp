// 09/02/19 // 5:45 //

#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 100010

int n, qnt=0;
int v[MAXN];

int soma_maxima(){
    int sum_max=0,sub_max=0, maior=0, menor=0, total=0;

    for(int i=0; i<n; i++){
        total += v[i];

        maior   = max(0, maior + v[i]);
        sum_max = max(sum_max, maior);

        menor   = min(0, menor+v[i]);
        sub_max = min(sub_max, menor);
    }

    return max(sum_max, total-sub_max);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=0; i<n; i++) cin >> v[i];

    cout << soma_maxima() << "\n";

    return 0;
}
