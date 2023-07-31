// 31/07/23 //
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
#include <stack>

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

int main(){
    fast_io;

    int a, b;
    cin >> a >> b;
    a += 15;
    b += 15;
    
    int fase=0;
    while(a!=b){
        a /= 2;
        b /= 2;

        fase++;
    }

    if(fase==1){
        cout << "oitavas" << endl;
    }
    else if(fase==2){
        cout << "quartas" << endl;
    }
    else if(fase==3){
        cout << "semifinal" << endl;
    }
    else{
        cout << "final" << endl;
    }   

    return 0;
}