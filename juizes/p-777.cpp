#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string dna, np;
    pair<int,string>v[10000];

    int aux = 0;
    while(true){
        cin >> v[aux].second;

        if(v[aux].second=="9999"){break;}

        cin >> dna;

        v[aux].first=0;

        for(int i=0; i<dna.size(); i++){
            if(dna[i]=='T'){
                v[aux].first++;
            }
        }
        aux++;
    }
    sort(v,v+aux+1);
    cout << v[aux].second << endl;
    return 0;
}
