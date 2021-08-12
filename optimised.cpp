#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
#define ll long long
long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);

}
vector <int> ffactors(int n)
{
    vector<int> v;
  for (int i = 1; i*i < n; i++) {
    if (n % i == 0)
      v.push_back(i);
  }
  for (int i = sqrt(n); i >= 1; i--) {
    if (n % i == 0)
      v.push_back(n / i);
  }
  v.pop_back();
    return v;
}
vector <int> factors(int n)
{
    vector<int> v;
  for (int i = 1; i*i < n; i++) {
    if (n % i == 0)
      v.push_back(i);
  }
  for (int i = sqrt(n); i >= 1; i--) {
    if (n % i == 0)
      v.push_back(n / i);
  }
    return v;
}
int main() {
    	freopen ("output2.txt", "w", stdout);
	freopen ("input.txt", "r", stdin);
     int t;
     cin>>t;
     while(t--)
     {
          int k;
          cin>>k;
          vector <int> f=ffactors(4*k+1);
           long long sum=0;
           int arr[f[f.size()-1]+1]={0};
           int i=f.size()-1;
           for(;i>=0;i--)
           {    int x=(4*k+1)/f[i];
                int t=(x-1)/2;
                arr[f[i]]=arr[f[i]]+t;
                //vector <int> sf=ffactors(f[i]);
                //for(int j=0;j<sf.size();j++)
                  //arr[sf[j]]=arr[sf[j]]-arr[f[i]];
                sum=sum+arr[f[i]]*f[i];
           }
           cout<<sum+4*k<<endl;
     }
	return 0;
}
