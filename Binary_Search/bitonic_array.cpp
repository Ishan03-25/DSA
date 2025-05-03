#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int n, q, k;
vector<int> arr;

bool Check_For_One(int mid){
    if (arr[mid]>=k){
        return 1;
    } else {
        return 0;
    }
}

bool Check_For_Two(int mid){
    if (arr[mid]<=k){
        return 1;
    } else {
        return 0;
    }
}

bool Check_For_Peak(int mid){
    if (mid==n-1){
        return 1;
    }
    if (arr[mid]>arr[mid+1]){
        return 1;
    } else {
        return 0;
    }
}

int Peak_Of_Bitonic_Array(){
    int lo=0, hi=n-1, ans=-1;
    while(lo<=hi){
        int mid=lo+((hi-lo)/2);
        if (Check_For_Peak(mid)==1){
            ans=mid;
            hi=mid-1;
        } else {
            lo=mid+1;
        }
    }

    return ans;
}

int Position_In_First(int lo, int hi, int ans){
    while(lo<=hi){
        int mid=lo+((hi-lo)/2);
        if (Check_For_One(mid)==1){
            ans=mid;
            hi=mid-1;
        } else {
            lo=mid+1;
        }
    }

    if (ans==-1){
        return ans;
    } else {
        if (arr[ans]!=k){
            ans=-1;
            return ans;
        } else {
            return ans;
        }
    }
}

int Position_In_Second(int lo, int hi, int ans){
    while(lo<=hi){
        int mid=lo+((hi-lo)/2);
        if (Check_For_Two(mid)==1){
            ans=mid;
            hi=mid-1;
        } else {
            lo=mid+1;
        }
    }

    if (ans==-1){
        return ans;
    } else {
        if (arr[ans]!=k){
            ans=-1;
            return ans;
        } else {
            return ans;
        }
    }
}

void solve(){
    arr.clear();
    cin >> n >> q;
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    int peak=Peak_Of_Bitonic_Array();
    while(q--){
        cin >> k;
        int ans1=Position_In_First(0, peak, -1);
        int ans2=Position_In_Second(peak, n-1, -1);

        if (ans1!=-1 && ans2!=-1){
            if (ans1==ans2){
                cout << ans1+1 << '\n';
            } else {
                cout << ans1+1 << " " << ans2+1 << '\n';
            }
        } else if (ans1==-1){
            cout << ans2+1 << '\n';
        } else if (ans2==-1){
            cout << ans1+1 << '\n';
        }
    }
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