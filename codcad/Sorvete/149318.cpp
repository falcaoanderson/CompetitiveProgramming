// 11/08/19 // 9:44 PM //

#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 5010
#define make_pair MP

int p, s;
pair<int, int> intervalos[MAXN];

int main(){
    cin >> p >> s;

    for(int i=1; i<=s; i++)
        cin >> intervalos[i].first >> intervalos[i].second;

    if(s==0) return 0;

    sort(intervalos+1, intervalos+s+1);


    cout << intervalos[1].first << " ";
    for(int i=2; i<=s; i++){
        if(intervalos[i].first > intervalos[i-1].second){
            cout << intervalos[i-1].second << "\n" << intervalos[i].first << " ";
        }
        else{
            intervalos[i].second = max(intervalos[i].second, intervalos[i-1].second);
        }
    }
    cout << intervalos[s].second << "\n";

    return 0;
}
