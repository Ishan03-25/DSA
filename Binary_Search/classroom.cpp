#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

lli n, k;
vector<lli> v;

bool check(lli d){
    lli cnt=1, last=v[0];

    for (lli i=1;i<n;i++){
        if (v[i]-last>=d){
            cnt++;
            last=v[i];
            if (cnt>=k){
                return 1;
            }
        }
    }

    return cnt>=k;
}

void solve(){
    cin >> n >> k;

    v.clear();
    for (lli i=0;i<n;i++){
        lli x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    lli lo=1, hi=v[n-1]-v[0], ans=1;
    while(lo<=hi){
        lli mid=lo+((hi-lo)/2);
        if (check(mid)==1){
            ans=mid;
            lo=mid+1;
        } else {
            hi=mid-1;
        }
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}