#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

lli n, s;

lli sum_of_digits(lli x){
    lli sum=0;
    while(x!=0){
        lli temp=x%10;
        sum+=temp;
        x/=10;
    }

    return sum;
}

bool check(lli x){
    lli digit_sum=sum_of_digits(x);
    if (s+digit_sum<=x){
        return 1;
    } else {
        return 0;
    }
}

void solve(){
    cin >> n >> s;

    lli lo=1, hi=n, ans=0;
    while(lo<=hi){
        lli mid=lo+((hi-lo)/2);
        if (check(mid)){
            hi=mid-1;
        } else {
            ans=mid;
            lo=mid+1;
        }
    }

    cout << n-ans << '\n';
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