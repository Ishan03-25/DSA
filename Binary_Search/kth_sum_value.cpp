#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

lli n, m, k;
vector<lli> a, b;

bool check(lli x){
    lli cnt=0;
    for (lli i=0;i<n;i++){
        cnt+=upper_bound(b.begin(), b.end(), x-a[i])-b.begin();
        if (cnt>=k){
            return 1;
        }
    }
    return cnt>=k;
}

void solve(){
    cin >> n >> m >> k;

    a.clear();
    for (lli i=0;i<n;i++){
        lli x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());

    b.clear();
    for (lli i=0;i<m;i++){
        lli x;
        cin >> x;
        b.push_back(x);
    }
    sort(b.begin(), b.end());

    if (n>m){
        swap(a, b);
        swap(n, m);
    }

    lli lo=a[0]+b[0], hi=a[n-1]+b[m-1], ans=0;
    while(lo<=hi){
        lli mid=lo+((hi-lo)/2);
        if (check(mid)==1){
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

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}