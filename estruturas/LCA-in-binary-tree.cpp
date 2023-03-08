// 21/03/2019 // 5:46 PM //

// Complexidade O(N)

#include <iostream>
#include <vector>

using namespace std;

#define MAXN 500
#define PB push_back

int qnt_nos;
vector<int> vizinhos[MAXN];

int LCA(int root, int no_1, int no_2){

    if(root == no_1 || root == no_2) return root;
    if(root == -1 || vizinhos[root].size()==0) return -1;

    int esquerda=-1, direita=-1;

    esquerda = LCA(vizinhos[root][0], no_1, no_2);
    if(vizinhos[root].size()==2)
        direita = LCA(vizinhos[root][1], no_1, no_2);

    if(esquerda==-1 && direita==-1) return -1;
    if(esquerda==-1 && direita!=-1) return direita;
    if(esquerda!=-1 && direita==-1) return esquerda;
    if(esquerda!=-1 && direita!=-1) return root;
}

int main(){

    cin >> qnt_nos;

    for(int i=1; i<qnt_nos; i++){
        int pai, filho;

        cin >> pai >> filho;

        vizinhos[pai].PB(filho);
    }

    while(true){
        int no_1, no_2;

        cin >> no_1 >> no_2;

        if(no_1 == 0 && no_2 == 0) break;

        cout << LCA(1, no_1, no_2) << "\n";
    }

    return 0;
}
