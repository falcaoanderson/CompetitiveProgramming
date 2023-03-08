// 28/08/19 // 8:29 //

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define MAXN 200010

int n;
vector< pair<int, int> > seq;
int resp[MAXN];

int main(){
    cin >> n;

    for(int i=1; i<=n; i++){
        int temp;
        cin >> temp;

        seq.pb( mp(temp,i) );
    }

    for(int i=1; i<=n; i++){

        for(int j=seq.size()-1; j>=0; j--){

            if(seq[j].first==0){
                resp[ seq[j].second ] = i;

                for(int k=j+1; k<seq.size(); k++) seq[k].first-=i;

                seq.erase(seq.begin()+j);

                break;
            }

        }

    }

    for(int i=1; i<=n; i++)
        cout << resp[i] << " ";
    cout << "\n";

    return 0;
}
