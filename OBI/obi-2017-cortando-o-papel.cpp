// 07/08/19 // 2:55 PM //

#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 100010

int n;
int h[MAXN];
pair<int, int> vetor[MAXN];

int main(){

    cin >> n;

    int k=1;
    for(int i=1; i<=n; i++){
        int temp;
        cin >> temp;

        if(temp!=h[k-1])
            h[k++] = temp;
    }

    int l=1;

    for(int i=1; i<k; i++){
        if(h[i-1]<h[i] && h[i+1]<h[i]){
            vetor[l].first  = h[i];
            vetor[l].second = -1;
            l++;
        }
        else if(h[i-1]>h[i] && h[i+1]>h[i]){
            vetor[l].first  = h[i];
            vetor[l].second = 1;
            l++;
        }
    }

    if(l==3 && vetor[1].first==1){cout<< "1\n";return 0;}

    sort(vetor+1, vetor+l);

    int resp = 2, aux=2;
    for(int i=1; i<l; i++){
        aux += vetor[i].second;
        resp = max(resp, aux);
    }

    cout << resp << "\n";


    return 0;
}

