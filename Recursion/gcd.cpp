#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

int gcd(int a, int b){
    if (b==0){
        return a;
    } else {
        return gcd(b, a%b);
    }
}

void solve(){
    int a, b;
    cin >> a >> b;

    cout << gcd(a, b) << '\n';
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