// 29/10/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int n, k;
vector<int> v;
multiset<int> esq, dir;

void equilibra(){
    if(esq.size()+2==dir.size()){
        auto it = dir.begin();
        esq.insert(*it);
        dir.erase(it);
    }
    else if(esq.size()==dir.size()+2){
        auto it2 = esq.rbegin();
        dir.insert(*it2);
        esq.erase(esq.find(*it2));
    }

    if(esq.size()<dir.size()){
            auto it = dir.begin();
            esq.insert(*it);
            dir.erase(it);
    }
    
    if(!esq.empty() && !dir.empty()){
        int maior_esq = *esq.rbegin();
        int menor_dir = *dir.begin();

        if(maior_esq>menor_dir){
            esq.erase(esq.find(maior_esq));
            dir.erase(dir.find(menor_dir));

            esq.insert(menor_dir);
            dir.insert(maior_esq);
        }
    }
}

void add(int val){
    auto it = dir.begin();

    if(esq.empty() || (!dir.empty() && (*it)>val)) // se o menor da direita for maior que val
        esq.insert(val);
    else 
        dir.insert(val);
    
    equilibra();
}

void remover(int val){
    if(esq.find(val)!=esq.end())   // se estiver na esquerda removo
        esq.erase(esq.find(val));
    else                           // se estiver na direita
        dir.erase(dir.find(val));

    equilibra();
}


void print(){
    for(auto i: esq)
        cout << i << " ";
    cout << " | ";
    for(auto i: dir)
        cout << i << " ";
    cout << endl;
}

int main(){
    //fast_io;

    cin >> n >> k;
    v.resize(n+1);

    for(int i=1; i<=n; i++){
        cin >> v[i];

        if(i<=k){ 
            add(v[i]);
            //print();
        }
    }

    auto mediana = esq.rbegin();
    cout << *mediana << " ";

    for(int i=k+1; i<=n; i++){
        add(v[i]);
        remover(v[i-k]);
        
        mediana = esq.rbegin();
        cout << *mediana << " ";
        //print();
    }
    cout << endl;

    return 0;
}
