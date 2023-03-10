// 15/01/19 // 11:30 PM //

#include <iostream>
#include <vector>

using namespace std;

#define MAXN 100010

vector<int> v[MAXN];

int n, m;
int t, a, b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0; i<m; i++){
        cin >> t >> a >> b;
        if(!t){
            bool saida=0;
            for(int i=0; i<v[a].size(); i++){
                if(v[a][i]==b){saida=1; break;}
            }
            cout << saida << "\n";
        }
        else{
            v[a].push_back(b);
            v[b].push_back(a);
        }
    }

    return 0;
}
