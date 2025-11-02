/*
08/09/25

*/
#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n';

using ll = long long;

vector<ll> v;
int solve(ll n, ll k){
	v.assign(n, 0);
    for(int i=0; i<n; i++) cin >> v[i];

	sort(v.begin(), v.end());

	ll l=2LL*v[0], r=2LL*v[n-1], resp=-1LL;

	while(l<=r){
		ll mid = (l+r)/2LL;

		// cout << "mid " << mid << endl;

		ll count_less=0, count_eq=0;
        // auto auxit = v.begin();
		for(int i=0; i<n; i++){
            if(v[i]*2LL == mid) count_eq++;
			else if(v[i]*2LL < mid) count_less++;
            
			ll idx_up = upper_bound(v.begin(), v.begin()+i, mid-v[i]) - v.begin();
			ll idx_lo = lower_bound(v.begin(), v.begin()+i, mid-v[i]) - v.begin();
            // auxit++;
            
			count_less += 2LL*idx_lo;
			count_eq   += 2LL*(idx_up-idx_lo);
        }

		if(count_less<k && k <= count_less+count_eq){
			resp = mid;
			break;
		}
		else if(count_less<k && k>count_less+count_eq){
			l = mid+1LL;
		}
		else{
			r = mid-1LL;
		}
	}

	return resp;
}

int main() {
	fast_io;

	int t;
	cin >> t;

	while(t--){
		ll n, k;
		cin >> n >> k;

		cout << solve(n, k) << endl;
	}

	return 0;
}