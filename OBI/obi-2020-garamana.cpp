// 31/05/23 //
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;

int freq_a[50], freq_b[50];

int main(){
    fast_io;

    string a, b;
    cin >> a >> b;

    if(a.size()!=b.size()){
        cout << "N" << endl;
        return 0;
    }

    for(char c: a) freq_a[(int)c-97]++;

    int coringa = 0;
    for(char c: b){
        if(c=='*') coringa++;
        else freq_b[(int)c-97]++;
    }

    int dif=0;
    for(int i=0; i<=25; i++){
        if(freq_a[i]<freq_b[i]) dif=INF;

        else dif += freq_a[i]-freq_b[i];
    }

    if(dif<=coringa){
        cout << "S" << endl;
    }
    else{
        cout << "N" << endl;
    }

    return 0;
}
