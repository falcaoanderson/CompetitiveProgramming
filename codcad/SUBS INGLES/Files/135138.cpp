#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 100010

int n, b_max, total=0, k=1;
int files[MAXN];

int main(){
    cin >> n >> b_max;

    for(int i=1; i<=n; i++)cin >> files[i];

    sort(files+1, files+n+1);

    for(int i=n; i>=k; i--){
        total++;

        if(files[i]+files[k]<=b_max) k++;
    }

    cout << total << endl;

    return 0;
}



