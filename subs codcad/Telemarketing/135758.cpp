#include <iostream>
#include <queue>
using namespace std;

#define MAXN 1010

int n, l, t, tempo=0, v[MAXN];
priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > ligacoes;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    pair<int, int> temp; // first=tempo // second=identificador

    cin >> n >> l;

    for(int i=1; i<=n; i++){
        temp.first  = 0;
        temp.second = i;
        ligacoes.push(temp);
    }

    for(int i=0; i<l; i++){
        cin >> t;

        temp = ligacoes.top();
        v[temp.second]++;

        if(tempo < temp.first) tempo=temp.first;

        temp.first = tempo + t;
        ligacoes.pop();
        ligacoes.push(temp);
    }

    for(int i=1; i<=n; i++){
        cout << i << " " << v[i] << endl;
    }

    return 0;
}
