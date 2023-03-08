#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long

const int MAXN = 1e5  + 10;
const int MAXP = 9592 + 10;

int n, k, np=0;
int primo[MAXN];
map<int, int> freq;

void crivo(){
    for(int i=2; i<=MAXN-10; i++)
        if(!primo[i])
            for(int j=i; j<=MAXN-10; j+=i)
                if(!primo[j])
                    primo[j] = i;
}

int eleva(int num, int pot){
    if(pot==0) return 1;
    if(pot&1)  return num*eleva(num, pot-1);
    else       return eleva(num*num, pot/2);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    crivo();
    int resp = 0;

    for(int i=0; i<n; i++){
        int num;
        cin >> num;

        int current=1, need=1;
        while(num>1){

            int pcont=0, p=primo[num];
            while(num%p==0){
                num /= p;
                pcont++;
            }

            pcont %= k;

            if(pcont>0){
                current *= eleva(p, pcont);
                need    *= eleva(p,(k-pcont)%k);
            }
        }

        resp += freq[need];
        freq[current]++;
    }

    cout << resp << endl;

    return 0;
}

