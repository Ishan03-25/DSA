#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
lli n;
vector<lli> arr;

bool check(int mid){
    if (arr[mid]<arr[0]){
        return 1;
    } else {
        return 0;
    }
}

void solve(){
    arr.clear();
    cin >> n;
    for (lli i=0;i<n;i++){
        lli num;
        cin >> num;
        arr.push_back(num);
    }

    lli lo=0, hi=n-1, ans=0;
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

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}