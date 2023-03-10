// 17/01/19 // 4:37 PM //

#include <iostream>
#include <vector>

using namespace std;

#define INF -10

int n;
long long b, c;
vector<long long> vetor;

long long merge_sort(vector<long long> &v){
    if(v.size()==1) return 0LL;

    vector<long long> u1, u2;
    int tamanho=v.size();

    for(int i=0; i<tamanho/2; i++)       u1.push_back(v[i]);
    for(int i=tamanho/2; i<tamanho; i++) u2.push_back(v[i]);

    long long inv = merge_sort(u1) + merge_sort(u2);

    u1.push_back(INF);
    u2.push_back(INF);

    int ini1=0, ini2=0;

    for(int i=0; i<tamanho; i++){
        if(u1[ini1] > u2[ini2]){
            v[i]=u1[ini1];
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
        cin >> b >> c;
        vetor.push_back( b*b + c*c );
    }

    cout << merge_sort(vetor) << "\n";

    return 0;
}
