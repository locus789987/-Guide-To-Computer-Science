#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ll                    long long int
#define ull                   unsigned long long int
#define loop(i,a,b)          for(ll i=(ll)a;i<=(ll)b;i++)
#define count_1(n)            __builtin_popcountll(n)
#define pb                    push_back
#define eb                    emplace_back
#define ab(a)                 (a<0)?(-1*a):a
#define pc                    putchar
#define gc                    getchar
#define mset(a,b,c)           loop(i,0,b) a[i]=c
#define F                     first
#define S                     second
#define mp                    make_pair
#define clr(x)                x.clear()
#define itoc(c)               ((char)(((int)'0')+c))
#define vi                    vector<int>
#define vvi                   vector<vi>
#define pll                   pair<ll,ll>
#define pii                   pair<int,int>
#define all(p)                p.begin(),p.end()
#define mid(s,e)              (s+(e-s)/2)
const int mod = 1000000007;
#define sv()                  long long int t; cin>>t; while(t--)
const int req=100005;
vector<ll> nodes(req+5,0);
vector<vector<pair<ll,ll>>> edges(req+5);
vector<ll> visited(req+5,0);
vector<ll>  lef,ri;
ll ans=0;
ll A[req+5],tree[4*req+5];
void build(ll node, ll start, ll end);
int query(ll node, ll start, ll end, ll l, ll r);
void update(ll node, ll start, ll end, ll idx, ll val);
void dfs(ll i,ll sum1,ll sum2,ll one,ll two)
{
    ans=max(ans,max(sum1,sum2));
  if(visited[i])
  {
    return;
  }
  else
  {
    visited[i]= 1;
    for(auto u:edges[i])
    {
      if(!visited[u.first])
      {
         if(one==0)
         {
             if(abs(ri[u.first]-lef[i])>=abs(lef[u.first]-lef[i]))
             {
                 sum1+=abs(ri[u.first]-lef[i]);
                 one^=1;
             }
             else{
                 sum1+=abs(lef[u.first]-lef[i]);
             }
         }
         else{
              if(abs(ri[u.first]-ri[i])>=abs(lef[u.first]-ri[i]))
             {
                 sum1+=abs(ri[u.first]-ri[i]);
                
             }
             else{
                 sum1+=abs(lef[u.first]-ri[i]);
                  one^=1;
             }
         }
         if(two==0)
         {
              if(abs(ri[u.first]-lef[i])>abs(lef[u.first]-lef[i]))
             {
                 sum2+=abs(ri[u.first]-lef[i]);
                 two^=1;
             }
             else{
                 sum2+=abs(lef[u.first]-lef[i]);
             }
         }
         else{
              if(abs(ri[u.first]-ri[i])>abs(lef[u.first]-ri[i]))
             {
                 sum2+=abs(ri[u.first]-ri[i]);
                
             }
             else{
                 sum2+=abs(lef[u.first]-ri[i]);
                  two^=1;
             }
         }
            dfs(u.first,sum1,sum2,one,two);
         }
      }
    }
  
  ans=max(ans,max(sum1,sum2));
}
void ipgraph(int n, int m){
  ll i, u, v,z;
  while(m--){
    cin>>u>>v;
    z=1;
    edges[u].pb({v,z});
    edges[v].pb({u,z});
  }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   ll t;
   cin >> t;
   for(ll o=1;o<=t;o++)
  {
    ll n;
    cin >> n;
    visited.clear();
    edges.clear();
    lef.clear();
    ri.clear();
    visited.resize(n+5,0);
    edges.resize(n+5);
    lef.resize(n+5);
    ri.resize(n+5);
    ll i,j,k;
    loop(i,1,n)
    {
        cin >> lef[i]>> ri[i];
    }
    ipgraph(n,n-1);
    ans=0;
    dfs(1,0,0,0,1);
    cout << ans << endl;
    
  }
}

void build(ll node, ll start, ll end)
{
    if(start == end)
    {
        tree[node] = A[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
void update(ll node, ll start, ll end, ll idx, ll val)
{
    if(start == end)
    {
        A[idx] += val;
        tree[node] += val;
    }
    else
    {
        ll mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            update(2*node, start, mid, idx, val);
        }
        else
        {
            update(2*node+1, mid+1, end, idx, val);
        }
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
int query(ll node, ll start, ll end, ll l, ll r)
{
    if(r < start or end < l)
    {
        return 0;
    }
    if(l <= start and end <= r)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}
