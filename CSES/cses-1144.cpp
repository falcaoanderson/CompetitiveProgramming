// 13/10/20 // 6:40 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb push_back

struct Query{
    bool op;
    int a, b;
};

const int MAXN  = (2e5)+10;
const int MAXT = (1e6);
int n, q, salary[MAXN];
int bit[MAXT], maxV;

Query query[MAXN];
vector<int> values;
unordered_map<int, int> comp;

void compress(){
    map<int, int> temp;

    for(int i=0; i<(int)values.size(); i++)
        temp[values[i]];

    int aux=0;
    comp.reserve(temp.size());

    for(map<int,int>::iterator it=temp.begin(); it!=temp.end(); ++it){
        comp[ (it->first) ] = (++aux);
    }
    maxV = aux;


    for(int i=1; i<=n; i++)
        salary[i] = comp[salary[i]];
}

void update(int i, int val){

    while(i<=maxV){
        bit[i] += val;
        i += (i&-i);
    }
}
int sum(int i){
    int total=0;

    while(i>0){
        total += bit[i];
        i -= (i&-i);
    }

    return total;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> salary[i];

        values.pb(salary[i]);
    }

    for(int i=1; i<=q; i++){
        char op;
        cin >> op >> query[i].a >> query[i].b;

        values.pb(query[i].b);

        if(op=='!')
            query[i].op = 0;
        else{
            query[i].op = 1;
            values.pb(query[i].a);
        }
    }

    compress();

    for(int i=1; i<=n; i++)
        update(salary[i], 1);

    for(int i=1; i<=q; i++){
        int op = query[i].op, a=query[i].a, b=query[i].b;


        if(op)
            cout << sum(comp[b]) - sum(comp[a]-1) << endl;
        else{
            update(salary[a], -1);
            salary[a] = comp[b];
            update(salary[a], 1);
        }
    }

    return 0;
}
