// 17/07/20 // 10:02 PM //

#include <bits/stdc++.h>

using namespace std;

struct No{
    int menor, maior, indMenor, indMaior;

    No(){}
    No(int _menor, int _maior, int _indMenor, int _indMaior){
        menor    = _menor;
        maior    = _maior;
        indMenor = _indMenor;
        indMaior = _indMaior;
    }
};

const int MAXN = 1e5 + 10;
const int INF  = 0x3f3f3f3f;

int n, m;
No seg[4*MAXN];
int v[MAXN];

No updateNo(No left, No right){
    No temp;

    if(left.menor <= right.menor){
        temp.menor    = left.menor;
        temp.indMenor = left.indMenor;
    }
    else{
        temp.menor    = right.menor;
        temp.indMenor = right.indMenor;
    }

    if(left.maior >= right.maior){
        temp.maior    = left.maior;
        temp.indMaior = left.indMaior;
    }
    else{
        temp.maior    = right.maior;
        temp.indMaior = right.indMaior;
    }

    return temp;
}


void build(int no, int i, int j){
    int left = 2*no, right = 2*no+1, mid=(i+j)/2;

    if(i==j){
        seg[no].menor = seg[no].maior =  v[i];
        seg[no].indMenor = seg[no].indMaior = i;
    }
    else{
        build( left,     i, mid);
        build(right, mid+1,   j);

        seg[no] = updateNo(seg[left], seg[right]);
    }

}

void update(int no, int i, int j, int peso, int ind){
    int left = 2*no, right = 2*no+1, mid=(i+j)/2;

    if(i==j){
        if(peso < seg[no].menor){
            seg[no].menor = peso;
        }
        if(peso > seg[no].maior){
            seg[no].maior = peso;
        }
    }
    else{
        if(ind<=mid)
            update(left, i, mid, peso, ind);
        else
            update(right, mid+1, j, peso, ind);

        seg[no] = updateNo(seg[left], seg[right]);
    }
}

No query(int no, int i, int j, int a, int b){
    int left = 2*no, right = 2*no+1, mid=(i+j)/2;

    if(a<=i && j<=b){
        return seg[no];
    }
    else if(j<a || b<i){
        return No(INF, -INF, -1, -1);
    }
    else{
        No op_left  = query(left,      i, mid, a, b);
        No op_right = query(right, mid+1,   j, a, b);

        return updateNo(op_left, op_right);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> v[i];
    }

    build(1, 1, n);

    while(m--){
        int op, a, b;
        cin >> op >> a >> b;

        if(op==1){ // update
            update(1, 1, n, a, b);
        }
        else{ // query
            int resp, x;

            No q1, q2, q3;
            // comecando pelo maior
            q1 = query(1, 1, n, a, b);
            x = q1.indMaior;

            q2 = query(1, 1, n, a, x-1);
            q3 = query(1, 1, n, x+1, b);

            resp = q1.maior - updateNo(q2, q3).menor;

            // comecando pelo menor
            x = q1.indMenor;

            q2 = query(1, 1, n, a, x-1);
            q3 = query(1, 1, n, x+1, b);

            resp = max(resp, updateNo(q2, q3).maior - q1.menor);

            cout << resp << endl;
        }
    }

    return 0;
}
