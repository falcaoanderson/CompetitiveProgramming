// 09/07/23 //
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

    set<char> charset = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 
    'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'x', 'z'};

    string frase;
    getline(cin, frase);

    for(char c: frase){
        if(charset.find(c)!=charset.end()) charset.erase(c);
    }

    cout << (charset.empty()? 'S': 'N') << endl;

    return 0;
}
