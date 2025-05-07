#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

lli n, k;
vector<lli> v;

bool check(lli t){
    lli needed=0;
    lli time_left=0;

    for (lli i=0;i<n;i++){
        if (time_left>=v[i]){
            time_left-=v[i];
        } else {
            needed++;
            if (needed>k){
                return 0;
            } else {
                time_left=t;
                if (time_left<v[i]){
                    return 0;
                } else {
                    time_left-=v[i];
                }
            }
        }
        if (needed>k){
            return 0;
        }
    }

    return needed<=k;
}

void solve(){
    cin >> n >> k;

    v.clear();
    v.resize(n);

    lli lo=0, hi=0;
    for (lli i=0;i<n;i++){
        cin >> v[i];
        lo=max(lo, v[i]);
        hi+=v[i];
    }

    lli ans=0;
    while(lo<=hi){
        lli mid=lo+((hi-lo)/2);
        if (check(mid)){
            ans=mid;
            hi=mid-1;
        } else {
            lo=mid+1;
        }
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    lli t;
    cin >> t;

    while(t--){
        solve();
    }
}