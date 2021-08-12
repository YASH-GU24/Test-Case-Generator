#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#define ll long long
using namespace std;

vector<ll> D;

void divs(double N);
double mod(double &n1, double &n2);
void push(double N);
void show();
void divs(double N)
{
    for (double i = 1; i <= sqrt(N); ++i)
    {
        if (!mod(N, i)) { push(i); if(i*i!=N) push(N / i); }
    }
}

double mod(double &n1, double &n2)
{
    return(((n1/n2)-floor(n1/n2))*n2);
}

void push(double N)
{
    double s = 1, e = D.size(), m = floor((s + e) / 2);
    while (s <= e)
    {
        if (N==D[m-1]) { return; }
        else if (N > D[m-1]) { s = m + 1; }
        else { e = m - 1; }
        m = floor((s + e) / 2);
    }
    D.insert(D.begin() + m, N);
}

void show()
{
    for (double i = 0; i < D.size(); ++i) cout << D[i] << " ";
}
vector <ll> ffactors(int n)
{
    divs(n);
    D.pop_back();
    return D;
}

int main() {
	freopen ("output1.txt", "w", stdout);
	freopen ("input.txt", "r", stdin);
     int s[100000]={0};
     for (int k=1;k<100000;k++)
     {
                    vector <ll> f=ffactors(4*k+1);
        D.clear();
           long long sum=0;
           int arr[f[f.size()-1]+1]={0};
           int i=f.size()-1;
           for(;i>=0;i--)
           {    int x=(4*k+1)/f[i];
                int t=(x-1)/2;
                arr[f[i]]=arr[f[i]]+t;
                vector <ll> sf=ffactors(f[i]);
                  D.clear();
                for(int j=0;j<sf.size();j++)
                  arr[sf[j]]=arr[sf[j]]-arr[f[i]];
                sum=sum+arr[f[i]]*f[i];
           }
           s[k]=sum;

     }
     int t;
     cin>>t;
     while(t--)
     {
          int k;
          cin>>k;
           cout<<s[k]+4*k<<endl;
     }
  return 0;
}
