// 07/02/19 // 5:55 PM //

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string seq;
    getline(cin,seq);


    vector<int> v, pilha;
    vector<int>::iterator it;

    for(int i=0; i<seq.size(); i++){
        v.push_back( int(seq[i]) );

        it = upper_bound(pilha.begin(), pilha.end(), v[i]);

        if(it==pilha.end()) pilha.push_back(v[i]);
        else *it = v[i];
    }


    cout << pilha.size() << "\n";

    return 0;
}
