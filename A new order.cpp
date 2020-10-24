  #include <bits/stdc++.h>
#define ll  long long int
#define N 1000000
#define M 1000000007
#define f(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define cot cout.tie(0)
using namespace std;
/**
  * @author :: Sawlani
  *
  */
   bool vis[N+1]={false};
ll level[N+1]={0};
bool vis2[27]={false};
ll mini=INT_MAX;
ll val[N+1]={0};
 vector <ll> v[N+1];
ll ans[N+1];
  void dfs(int ch)
  {
    f(j,0,v[ch].size()-1)
    {
           ll p=v[ch][j];
           level[p]=max(level[p],level[ch]+1);
            dfs(p);
        }
  }

  int main()
  {
    ll n;
    cin >> n;
    string s[n+1];
    f(i,1,n)
    {
      cin >> s[i];
      f(j,0,s[i].length()-1)
      {
         vis2[((int)(s[i][j])-97)]=true;
      }
    }
     f(i,1,n-1)
     {
      f(j,0,s[i].length()-1)
      {
         if(j<s[i+1].length()&&s[i][j]!=s[i+1][j])
         {
             v[(int)(s[i][j])-97].pb((int)(s[i+1][j])-97);
              break;
          }
      }
    }
//     cout << "madar " << endl;
 /*   for(int ch=0;ch<=25;ch++)
     {
         f(j,0,v[ch].size()-1)
         {
             cout << (char)(v[ch][j]+97) << " ";

         }
         if(v[ch].size()!=0)
            cout << endl;
    }*/
     for(int ch=0;ch<=25;ch++)
     {
         if(v[ch].size()!=0)
         {
             for(ll i=0;i<v[ch].size();i++)
             {
                 vis[(v[ch][i])]=true;
             }
         }
     }
     f(i,0,25)
     {
        if(!vis[i]&&vis2[i])
        dfs(i);
     }
vector <pair <ll,char > > vp;
f(i,0,25)
{
    if(vis2[i])
    {
        vp.pb({level[i],(char)(i+97)});

    }
}
sort(vp.begin(),vp.end());
f(j,0,vp.size()-1)
{
      if(j!=vp.size()-1&&vp[j].first==vp[j+1].first)
      cout << vp[j].second ;
      else
      cout << vp[j].second  << endl;
    }
}






