// 23/05/20 // 14:11 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb push_back
#define mp make_pair

const int INF  = 0x3f3f3f3f;
const int MAXN = (int)(1e5) + 10;

int n, k;
map<string, int> nomes;
vector< pair<int, pair<string, int>> > ranq;
// { xp, {nome, tempo}}

bool ord(pair<int, pair<string, int>> a, pair<int, pair<string, int>> b){
    return (a.first > b.first) || (a.first == b.first && a.second.first < b.second.first);
}

int main(){

    cin >> n >> k;

    for(int i=0; i<n; i++){
        string nome;
        int tempo;

        cin >> nome >> tempo;

        if(nomes.find(nome)==nomes.end()){
            ranq.pb( {1,{nome, tempo}} );
            nomes[nome] = (int)ranq.size() -1;
        }
        else{
            int id = nomes[nome];

            if(ranq[id].second.second + k <= tempo){
                ranq[id].first++;
                ranq[id].second.second = tempo;
            }
        }
    }
    cout << "--Rank do Nepscord--" << endl;

    sort(ranq.begin(), ranq.end(), ord);

    for(int i=0; i<3; i++){
        cout << "#" << i+1 << ". ";

        if(ranq.size() >= i+1)
            cout << ranq[i].second.first << " - Nivel " << ranq[i].first/4 +1;

        cout << endl;
    }

    return 0;
}


