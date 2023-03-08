// 09/12/19 // 6:13 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f

struct node{
    int maxPrefix, maxSufix, maxSub, totalSum;
    int tamPrefix, tamSufix, tamSub, tamTotal;

    node(){}
    node(int _maxPrefix,int _maxSufix,int _maxSub,int _totalSum,int _tamPrefix,int _tamSufix,int _tamSub,int _tamTotal){
        maxPrefix = _maxPrefix;
        maxSufix  = _maxSufix;
        maxSub    = _maxSub;
        totalSum  = _totalSum;
        tamPrefix = _tamPrefix;
        tamSufix  = _tamSufix;
        tamSub    = _tamSub;
        tamTotal  = _tamTotal;
    }

    node operator+ (const node &temp){
        int _maxPrefix, _maxSufix, _maxSub, _totalSum, _tamPrefix, _tamSufix, _tamSub, _tamTotal;
        _totalSum = totalSum + temp.totalSum;
        _tamTotal = tamTotal + temp.tamTotal;


        // calcula o max prefix sum da soma do nos
        if(maxPrefix <=  totalSum + temp.maxPrefix){
            _maxPrefix = totalSum + temp.maxPrefix;
            _tamPrefix = tamTotal + temp.tamPrefix;
        }
        else{
            _maxPrefix = maxPrefix;
            _tamPrefix = tamPrefix;
        }

        // calcula o max sufix sum da soma do nos
        if(temp.maxSufix <= maxSufix + temp.totalSum){
            _maxSufix = maxSufix + temp.totalSum;
            _tamSufix = tamSufix + temp.tamTotal;
        }
        else{
            _maxSufix = temp.maxSufix;
            _tamSufix = temp.tamSufix;
        }


        // calcula o max subarray sum da soma do nos
        vector< pair<int, int> > opcSub;
        opcSub.pb( mp(maxSub, tamSub));           // opc1 == manter o maior sub da esquerda
        opcSub.pb( mp(temp.maxSub, temp.tamSub)); // op2  == manter o maior sub da direita
        opcSub.pb( mp(maxSufix+temp.maxPrefix, tamSufix+temp.tamPrefix)); // op3  == construir um novo maior sub com o sufix da esquerda e o prefix da direita
        sort(opcSub.begin(), opcSub.end()); // ordenar para pegar o maior

        _maxSub = opcSub[2].first;
        _tamSub = opcSub[2].second;

        return node(_maxPrefix, _maxSufix, _maxSub, _totalSum, _tamPrefix, _tamSufix, _tamSub, _tamTotal);
    }
};

int n;
int value[MAXN];
node seg[3*MAXN];

void build(int no, int i, int j){
    int mid = (i+j)/2, left = 2*no, right = 2*no + 1;


    if(i==j){
        seg[no].tamPrefix = seg[no].tamSufix = seg[no].tamSub = seg[no].tamTotal = 1;
        seg[no].maxPrefix = seg[no].maxSufix = seg[no].maxSub = seg[no].totalSum = value[i];
    }
    else{
        build( left,     i,   mid);
        build(right, mid+1,     j);

        seg[no] = seg[left] + seg[right];
    }
}

node query(int no, int i, int j, int x, int y){
    int mid = (i+j)/2, left = 2*no, right = 2*no + 1;

    if(j<x || y<i){
        return node(-INF,-INF,-INF,-INF,-INF,-INF,-INF,-INF);
    }
    else if(x<=i && j<=y){
        return seg[no];
    }
    else{
        node op_left  = query( left,     i, mid, x, y);
        node op_right = query(right, mid+1,   j, x, y);

        if(op_left.maxSub==-INF) return op_right;
        if(op_right.maxSub==-INF)return op_left;

        return (op_left + op_right);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, q, a, b;
    cin >> t;

    while(t--){
        cin >> n;

        for(int i=1; i<=n; i++) cin >> value[i];

        build(1, 1, n);

        cin >> q;

        while(q--){

            cin >> a >> b;

            node resp = query(1, 1, n, a, b);

            cout << resp.maxSub << " " << resp.tamSub << "\n";
        }

    }

    return 0;
}