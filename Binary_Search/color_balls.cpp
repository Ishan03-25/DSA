#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

lli n, k;
map<lli, lli> balls;

bool check(lli x){
    lli total_useful_balls=0, total_balls_req=k*x;
    for (auto i: balls){
        total_useful_balls+=min(i.second, x);
    }

    return total_useful_balls>=total_balls_req;
}

void solve(){
    cin >> n >> k;

    balls.clear();
    for (lli i=0;i<n;i++){
        lli x;
        cin >> x;
        balls[x]++;
    }

    lli lo=0, hi=n, ans=0;
    while(lo<=hi){
        lli mid=lo+((hi-lo)/2);
        if (check(mid)){
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