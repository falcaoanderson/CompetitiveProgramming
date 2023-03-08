// 19/08/2019 // 8:45 PM //
// Complexity O(l*c)     //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010

int l, c;
int ma[MAXN][MAXN], mb[MAXN][MAXN];
int hist[MAXN];

int MHA(int n, int h[]){
    stack<int> pilha;
    int top, area, max_area=-1;
    h[n] = -1;

    for(int i=0; i<=n; i++){
        if(pilha.empty() || h[i]>=h[pilha.top()]){
            pilha.push(i);
        }
        else{
            while(true){
                if(pilha.empty() || h[i]>=h[pilha.top()]){
                    pilha.push(i);
                    break;
                }

                top = pilha.top();
                pilha.pop();

                if(pilha.empty())
                    area = (h[top]+1) * (i + 1);
                else
                    area = (h[top]+1) * (i - pilha.top());

                max_area = max(max_area, area);
            }
        }
    }

    return max_area;
}

int main(){

    cin >> l >> c;

    for(int i=0; i<l; i++)
        for(int j=0; j<c; j++)
            cin >> ma[i][j];

    for(int i=0; i<l-1; i++)
        for(int j=0; j<c-1; j++)
            if(ma[i][j]+ma[i+1][j+1] <= ma[i+1][j]+ma[i][j+1])
                mb[i][j] = 1;

    int resp=0;
    for(int i=0; i<l-1; i++){
        for(int j=0; j<c-1; j++){
            if(mb[i][j]==1){
                hist[j] = 1 + hist[j];
            }
            else{
                hist[j] = 0;
            }
        }

        resp = max(resp, MHA(c-1, hist));
    }

    cout << resp << "\n";

    return 0;
}
