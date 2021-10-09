#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long int ll;
#define N 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll ncr[1001][1001]={0};
    for(int i=0;i<1001;i++)
        ncr[i][i]=1;
    for(int i=0;i<1001;i++)
        ncr[0][i]=1;
    for(int i=1;i<1001;i++)
        for(int j=i+1;j<1001;j++)
            ncr[i][j]=(ncr[i][j-1]+ncr[i-1][j-1])%N;
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n);
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        for(int i=0;i<n;i++)
            m1[arr[i]]++;
        for(int i=n-1;i>=n-k;i--)
            m2[arr[i]]++;
        cout<<ncr[m2[arr[n-k]]][m1[arr[n-k]]]<<"\n";
    }
}
