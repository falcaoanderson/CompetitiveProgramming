/*
17/10/23 
Problem: ICPC Latam 2020 Regional - J. Job Allocator
Complexity: O(n * 2^k)
*/

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
#include <functional>
#include <cmath>

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

const int MAXVAL = 38263752 + 5;

vector< vector<int> > cpus;
int avaliable[MAXVAL];
int nine[10];

void update(int i, int qnt, int number, const vector<int> &v, int op){

    if(i>=8 || qnt==0){
        avaliable[number] += op;
        return;
    }

    for(int d=0; d<=min(qnt, v[i]); d++){
        update(i+1, qnt-d, number + nine[i] * d, v, op);
    }
}

int main(){ 
    fast_io;

    nine[0]=1;
    for(int i=1; i<=7; i++) nine[i] = 9 * nine[i-1];

    int n, k;    
    cin >> n >> k;  

    while(n--){
        char op;
        int qnt;
        
        cin >> op;

        if(op=='C'){
            cin >> qnt;
            
            cpus.PB(vector<int>(8));
            int id = (int)cpus.size() - 1;

            for(int i=0; i<qnt; i++){
                int val;
                cin >> val;

                cpus[id][val-1]++;
            }
            
            update(0, qnt, 0, cpus[id], 1);
        }
        else if(op=='J'){
            cin >> qnt;

            vector<int> req(8);
            for(int i=0; i<qnt; i++){
                int val;
                cin >> val;

                req[val-1]++;
            }

            int number = 0;
            for(int i=0; i<8; i++) number += nine[i] * req[i];

            cout << avaliable[number] << endl;
        }
        else{
            int del;
            cin >> del;
            
            int qnt=0;
            for(int i=0; i<8; i++) qnt+=cpus[del-1][i];

            update(0, qnt, 0, cpus[del-1], -1);
        }
    }

    return 0;
}