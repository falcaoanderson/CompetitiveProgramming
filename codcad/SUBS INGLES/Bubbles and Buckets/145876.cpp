// 17/05/19 // 9:07 PM //

#include <iostream>
#include <vector>

using namespace std;

#define INF 2000000000
#define PB push_back

int n, temp;
vector<int> v;

int merge_sort( vector<int> &v){
    if(v.size()==1) return 0;

    vector<int> u1, u2;
    int tamanho = v.size();

    for(int i=0; i<tamanho/2; i++) u1.PB(v[i]);
    for(int i=tamanho/2; i<tamanho; i++) u2.PB(v[i]);

    int cont = merge_sort(u1) + merge_sort(u2);

    u1.PB(INF);
    u2.PB(INF);
    int ini1=0, ini2=0;

    for(int i=0; i<tamanho; i++){
        if(u1[ini1] <= u2[ini2]){
            v[i] = u1[ini1];
            ini1++;
        }
        else{
            v[i] = u2[ini2];
            ini2++;

            cont += u1.size()-1-ini1;
        }
    }

    return cont;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    while(true){
        cin >> n;

        if(n==0) break;
        v.clear();
        for(int i=0; i<n; i++){
            cin >> temp;
            v.PB(temp);
        }

        temp = merge_sort(v);

        if(temp%2==0) cout << "Carlos\n";
        else          cout << "Marcelo\n";
    }
    return 0;
}
