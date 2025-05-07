#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

lli n, k;
vector<lli> v;

bool check(lli x){
    lli cnt=0;
    for (lli i=1;i<n;i++){
        cnt+=ceil(double(v[i]-v[i-1])/double(x))-1;
    }
    if (cnt<=k){
        return 1;
    } else {
        return 0;
    }
}

void solve(){
    cin >> n >> k;
    v.clear();
    for (lli i=0;i<n;i++){
        lli x;
        cin >> x;
        v.push_back(x);
    }

    lli lo=1, hi=0;
    for (int i=1;i<n;i++){
        hi=max(hi, v[i]-v[i-1]);
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

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}