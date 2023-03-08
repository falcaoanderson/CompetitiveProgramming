// 03/09/19 // 15:00 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010
#define MLR int mid = (i+j)/2, left = 2*no, right = 2*no+1

typedef pair<int, pair<int, int >> pii;

int n, q;
int value[MAXN];
int pos[MAXN];
int seg[3*MAXN];
pii querys[MAXN]; // pair<r, l>
int resp[MAXN];

void update(int no, int i, int j, int ind, int sum){
    MLR;

    if(i==j){
        seg[no] += sum;
    }
    else{
        if(ind<=mid) update( left,     i, mid, ind, sum);
        else         update(right, mid+1,   j, ind, sum);

        seg[no] = seg[left] + seg[right];
    }
}
int query(int no, int i, int j, int a, int b){
    MLR;

    if(i>j || a>b || b<i || j<a)
        return 0;
    if(a<=i && j<=b)
        return seg[no];
    else
        return ( query(left, i, mid, a, b) + query(right, mid+1, j, a, b) );
}

void entrada_e_compressao(){
    pair<int, int> temp[MAXN];

    for(int i=1; i<=n; i++){
        cin >> temp[i].first;
        temp[i].second = i;
    }

    sort(temp+1, temp+n+1);

    int ind=0;
    temp[0].first = -1;

    for(int i=1; i<=n; i++){
        if(temp[i].first!=temp[i-1].first)
            value[temp[i].second] = ++ind;
        else
            value[temp[i].second] = ind;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    entrada_e_compressao();


    for(int i=0; i<q; i++){
        cin >> querys[i].second.first >> querys[i].first;
        querys[i].second.second = i;
    }

    sort(querys, querys + q);

    int ini=0;

    for(int z=0; z<q; z++){

        for(int i=ini+1; i<=querys[z].first; i++){

            update(1, 1, n, i, 1);

            if(pos[value[i]])
                update(1, 1, n, pos[value[i]], -1);

            pos[value[i]] = i;
        }

        ini = querys[z].first;

        resp[querys[z].second.second] = query(1, 1, n, querys[z].second.first, querys[z].first);
    }

    for(int i=0; i<q; i++)
        cout << resp[i] << "\n";

    return 0;
}
