#include <bits/stdc++.h>
using namespace std;

int crossSum(int a[],int left,int mid,int right){
    int sum=0,leftsum=INT_MIN;
    for(int l=mid;l>=left;l--){
        sum+=a[l];
        if(sum>leftsum)
            leftsum=sum;
    }
    sum=0;
    int rightsum=INT_MIN;
    for(int r=mid+1;r<=right;r++){
        sum+=a[r];
        if(sum>rightsum)
            rightsum=sum;
    }
    return leftsum+rightsum;
}
int maxSubArrSum(int a[],int i,int j){
    if(i==j){
        return a[i];
    }
    int mid=(i+j)/2;
    int maxleft=maxSubArrSum(a,i,mid);
    int maxright=maxSubArrSum(a,mid+1,j);
    int cSum=crossSum(a,i,mid,j);
    return max(maxleft,max(maxright,cSum));
}

int main(){
    //8
    //-2 -5 6 -2 -3 1 5 -6
    //answer is 7
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<maxSubArrSum(arr,0,n-1);
    return 0;
}
