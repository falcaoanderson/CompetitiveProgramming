/*
18/10/25

*/
#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
#define endl "\n"
#define X first
#define Y second
#define PB push_back

typedef pair<int, int> pii;

void print_pii(pii elem) {
    cout << elem.X << " " << elem.Y << '\n';
}

bool alinha(pii rai_1, pii rai_2) {
    if (rai_1.X == rai_2.X) return true;
    if (rai_1.Y == rai_2.Y) return true;
    if (rai_1.X + rai_1.Y == rai_2.X + rai_2.Y) return true;
    if (rai_1.Y - rai_1.X == rai_2.Y - rai_2.X) return true;
    return false;
}

int main() {
    fast_io;

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pii> queens(n);
        for (int i = 0; i < n; i++) {
            cin >> queens[i].X >> queens[i].Y;
        }

        pii pri = queens[0], seg;
        bool achou = false;
        
        for (int i = 1; i < n; ++i) {
            if (alinha(pri, queens[i])) continue;
            achou = true;
            seg = queens[i];
            break;
        }

        if (!achou) {
            cout << "YES\n";
            print_pii(pri);
            continue;
        }

        vector<pii> candidatos;
        candidatos.PB({seg.X, pri.Y});
        candidatos.PB({pri.X, seg.Y});
        candidatos.PB({seg.X+seg.Y-pri.Y,pri.Y});
        candidatos.PB({pri.X+pri.Y-seg.Y,seg.Y});
        candidatos.PB({seg.Y+pri.X-pri.Y,seg.Y});
        candidatos.PB({pri.Y+seg.X-seg.Y,pri.Y});
        candidatos.PB({seg.X,seg.X+pri.Y-pri.X});
        candidatos.PB({pri.X,pri.X+seg.Y-seg.X});
        candidatos.PB({pri.X,seg.X+seg.Y-pri.X});
        if ((pri.X-pri.Y+seg.X+seg.Y)%2 == 0)
            candidatos.PB({(pri.X-pri.Y+seg.X+seg.Y)/2,(-pri.X+pri.Y+seg.X+seg.Y)/2});
        if ((pri.X+pri.Y+seg.X-seg.Y)%2 == 0)
            candidatos.PB({(pri.X+pri.Y+seg.X-seg.Y)/2,(pri.X+pri.Y-seg.X+seg.Y)/2});
        candidatos.PB({seg.X,pri.X+pri.Y-seg.X});

        achou = false;
        pii ret;
        for (auto cand: candidatos) {
            bool okay = true;
            for (int i = 1; i < n; ++i) {
                if (!alinha(cand, queens[i])) {
                    okay = false;
                    break;
                }
            }

            if (okay) {
                ret = cand;
                achou = true;
                break;
            }
        }

        if (achou) {
            cout << "YES" << endl;
            print_pii(ret);
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}