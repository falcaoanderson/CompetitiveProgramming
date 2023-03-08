// 19/08/19 // 7:42 PM //
// Complexity O(n) (linear)

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000010

int n;
int h[MAXN];

int MHA(){
    stack<int> pilha;
    int top=-1, area=-1, max_area=-1;
    h[n]=-1;

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
                    area = h[top] * i;
                else
                    area = h[top] * (i - pilha.top() - 1);

                max_area = max(max_area, area);
            }
        }
    }

    return max_area;
}

int main(){
    cin >> n;

    for(int i=0; i<n; i++)
        cin >> h[i];

    cout << MHA() << "\n";

    return 0;
}
