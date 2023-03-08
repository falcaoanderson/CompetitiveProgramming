// 17/01/19 // 12:55 PM

#include <iostream>
#include <vector>

using namespace std;

#define INF 70000

int n, temp;
vector<int> sequencia;

int merge_sort(vector<int> &v){

    if(v.size()==1) return 0;

    int tamanho=v.size();
    vector<int> u1, u2;

    for(int i=0; i<tamanho/2; i++)       u1.push_back(v[i]);
    for(int i=tamanho/2; i<tamanho; i++) u2.push_back(v[i]);

    int inv=0;

    inv += merge_sort(u1) + merge_sort(u2);

    u1.push_back(INF);
    u2.push_back(INF);

    int ini1=0, ini2=0;

    for(int i=0; i<tamanho; i++){
        if(u1[ini1] <= u2[ini2]){
            v[i] = u1[ini1];
            ini1++;
        }
        else{
            v[i]=u2[ini2];
            ini2++;

            inv += u1.size()-1-ini1;
        }
    }

    return inv;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=0; i<n; i++){
        cin>>temp;
        sequencia.push_back(temp);
    }

    cout << merge_sort(sequencia) << "\n";

    return 0;
}
