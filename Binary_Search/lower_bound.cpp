#include<bits/stdc++.h>
using namespace std;

bool check(int mid, int arr, int x){
    if (arr[mid]>=x){
        return 1;
    } else {
        return 0;
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    int x;
    cin >> x;

    //lower bound
    int lo=0, hi=n-1, ans=n;
    while(lo<=hi){
        int mid=lo+((hi-lo)/2);
        if (check(mid, arr, x)){
            ans=mid;
            hi=lo-1;
        } else {
            lo=mid+1;
        }
    }

    cout << ans << '\n';
}