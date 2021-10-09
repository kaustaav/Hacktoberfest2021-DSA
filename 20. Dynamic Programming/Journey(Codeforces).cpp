// problem link 
// https://codeforces.com/contest/1476/problem/D
// codeforces Level D problem

#include <iostream>
using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        int ps[n+1],po[n+1],ns[n+1],no[n+1];
        ps[0]=0;
        po[0]=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i-1]=='L')
            {
                ps[i]=po[i-1]+1;
                po[i]=0;
            }
            else
            {
                ps[i]=0;
                po[i]=ps[i-1]+1;
            }
        }
        ns[n]=0;
        no[n]=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='R')
            {
                ns[i]=no[i+1]+1;
                no[i]=0;
            }
            else
            {
                ns[i]=0;
                no[i]=ns[i+1]+1;
            }
        }
        for(int i=0;i<=n;i++)
            cout<<1+ps[i]+ns[i]<<" ";
        cout<<"\n";
    }
}
