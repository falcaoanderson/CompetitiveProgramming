#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ff first
#define ss second

const int MAXN = (1e5) + 10;
const int INF  = 0x3f3f3f3f;

typedef pair<int, int> pii;

int n, v[MAXN];
pii seg[3*MAXN]; // pair(menor, maior)

void build(int no, int i, int j){
    int esq = 2*no, dir = 2*no+1, meio = (i+j)/2;

    if(i==j){
        seg[no].ff = v[i];
        seg[no].ss = v[i];
    }
    else{
        build(esq,      i, meio);
        build(dir, meio+1,    j);

        seg[no].ff = min(seg[esq].ff, seg[dir].ff);
        seg[no].ss = max(seg[esq].ss, seg[dir].ss);
    }
}

void update(int no, int i, int j, int ind, int new_value){
    int esq = 2*no, dir = 2*no+1, meio = (i+j)/2;

    if(i==j){
        seg[no].ff = new_value;
        seg[no].ss = new_value;
    }
    else{
        if(ind<=meio) update(esq,      i, meio, ind, new_value);
        else          update(dir, meio+1,    j, ind, new_value);

        seg[no].ff = min(seg[esq].ff, seg[dir].ff);
        seg[no].ss = max(seg[esq].ss, seg[dir].ss);
    }
}

pii query(int no, int i, int j, int a, int b){
    int esq = 2*no, dir = 2*no+1, meio = (i+j)/2;

    if(j<a || b<i){
        return pii(INF, -INF);
    }
    else if(a<=i && j<=b){
        return seg[no];
    }
    else{
        pii op_esq = query(esq,      i, meio, a, b);
        pii op_dir = query(dir, meio+1,    j, a, b);

        return pii(min(op_esq.ff, op_dir.ff), max(op_esq.ss, op_dir.ss));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> n && n!=0){

        for(int i=1; i<=n; i++) cin >> v[i];

        build(1, 1, n);

        int q;
        cin >> q;

        while(q--){
            int op, a, b;

            cin >> op >> a >> b;

            if(op==1){ // atualizado
                update(1, 1, n, a, b);
            }
            else{
                pii temp = query(1, 1, n, a, b);

                //cout << "valores achados " << temp.ss << " " << temp.ff << endl;

                cout << (temp.ss - temp.ff) << endl;
            }
        }
    }

    return 0;
}
