#include <bits/stdc++.h>
using namespace std;


long long max(long long a,long long b){

    return (a>b)?a:b;
}
int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long maxSum = arr[0];

    long long sum =arr[0];

    for(int i=1;i<n;i++)
    {
         if(sum<0)
        {
            sum=0;
        }
        sum+=arr[i];
        maxSum = max(arr[i],maxSum);
        maxSum = max(sum,maxSum);
       
    }

    cout<<maxSum<<endl;

}

