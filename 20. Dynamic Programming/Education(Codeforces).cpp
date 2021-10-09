#include <iostream>
#include <cmath>
using namespace std;
typedef long long int ll;

ll min(ll a, ll b)
{
    if(a<b)
        return a;
    return b;
}

ll fn(int i, ll c, ll total, ll a[], ll b[], int n)
{
    if(c<=total)
        return 0;
    ll way1=ceil(1.0*(c-total)/a[i]);
    if(i==(n-1))
        return way1;
    ll day_to_buy_course=ceil(1.0*(b[i]-total)/a[i]);
    if(day_to_buy_course<0)
        day_to_buy_course=0;
    ll revenue=total+day_to_buy_course*a[i]-b[i];
    return min(way1,day_to_buy_course+1+fn(i+1,c,revenue,a,b,n));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n;
    ll c;
    cin>>t;
    while(t--)
    {
        cin>>n>>c;
        ll a[n],b[n-1];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n-1;i++)
            cin>>b[i];
        cout<<fn(0,c,0,a,b,n)<<"\n";
    }
}
