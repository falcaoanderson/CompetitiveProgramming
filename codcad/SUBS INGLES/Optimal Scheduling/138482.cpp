// 12/02/19 // 8:17 PM //

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAXV 50010
#define MAXA 200010

int nver, nare;
int grau[MAXV];
vector<int> vizinhos[MAXV];
vector<int> ordem;
priority_queue< int, vector<int>, greater<int> > grauzero;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> nver >> nare;

    for(int i=0; i<nare; i++){
        int a, b;
        cin >> a >> b;

        vizinhos[a].push_back(b);
        grau[b]++;
    }

    for(int i=0; i<nver; i++) if(grau[i]==0) grauzero.push(i);

    int processados = 0;

    while(!grauzero.empty()){

        int atual = grauzero.top();
        grauzero.pop();
        ordem.push_back(atual);
        processados++;

        for(int i=0; i<vizinhos[atual].size(); i++){
            int temp = vizinhos[atual][i];

            grau[temp]--;

            if(grau[temp]==0) grauzero.push(temp);
        }
    }

    if(processados==nver){
        for(int i=0; i<processados; i++)
            cout << ordem[i] << "\n";
    }
    else{
        cout << "*\n";
    }

    return 0;
}
