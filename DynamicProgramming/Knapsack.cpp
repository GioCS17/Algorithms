#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int size=10e2;

int vec[size];
int wec[size];
int res[size][size];
vector<int> elem[size][size];

int knapsack(int n,int w){
  if(n<0)
    return 0;
  if(w<=0)
    return 0;
  if(res[n][w])
    return res[n][w];

  int tmp1=0;
  int tmp2=knapsack(n-1,w);
  if(w>=wec[n])
    tmp1=knapsack(n-1,w-wec[n])+vec[n];
  if(tmp1>tmp2){
    res[n][w]=tmp1;
    elem[n][w].insert(elem[n][w].end(),elem[n-1][w-wec[n]].begin(),elem[n-1][w-wec[n]].end());
    elem[n][w].push_back(n);
  }
  else{
    res[n][w]=tmp2;
    elem[n][w].insert(elem[n][w].end(),elem[n-1][w].begin(),elem[n-1][w].end());
  }
  return res[n][w];
}
int main(){

  int n,w;
  cin>>n>>w;

  for(int i=0;i<n;i++)
    cin>>vec[i];
  for(int i=0;i<n;i++)
    cin>>wec[i];

  cout<<"max Value"<<endl;
  cout<<knapsack(n-1,w)<<endl;

  if(elem[n-1][w].empty())
    cout<<"No hay elementos "<<endl;
  else{
    cout<<"Elements con indices :"<<endl;
    for(int x:elem[n-1][w])
      cout<<x<<" ";
      cout<<endl;
  }

  return 0;
}
