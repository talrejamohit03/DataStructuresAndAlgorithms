#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &A) {
    int mxi=0,mx=INT_MIN;
    for(int i=0;i<A.size();i++){
        mxi+=A[i];
        mx=(mxi>mx)?mxi:mx;
        if(mxi<0)mxi=0;
    }
    return mx;
}
int main(){
    //8
    //-2 -5 6 -2 -3 1 5 -6
    //answer is 7
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<maxSubArray(arr);
    return 0;
}
