/*Problem:Given an unsorted array of integers, check if it contains four elements tuple (Quadruplets) having given sum.*/
/*Solution:The idea is to consider every pair of elements in the array one by one and insert it into a map. For each pair of element (i, j), we calculate the remaining sum. If remaining sum exists in the map and elements involved in previous occurrence don’t overlap with the current pair i.e. ((i, j, i, y) or (i, j, x, i) or (i, j, j, y) or (i, j, x, j)), we print the Quadruplet and return.*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>Pair;
bool quadtuple(int arr[],int n, int sum)
{
 unordered_map<int , vector<Pair>> map;
 for(int i=0;i<n-1;i++)
   {
    for(int j=i+1;j<n;j++)
      {
       int val=sum-(arr[i]+arr[j]);
       if(map.find(val)!=map.end())
         {
           for(auto pair : map.find(val)->second)
            {
               int x=pair.first;
               int y=pair.second;
                
                if((x!=i&&x!=j)&&(y!=i&&y!=j))
              {
               cout<<"quadruplet found ("<<arr[i]<<" "<<arr[j]<<" "<<arr[x]<<" "<<arr[y]<<")"<<endl;
               return true;}
            }
         }
      map[arr[i]+arr[j]].push_back({i,j});
      }
    
   }
 return false;
}
int main()
{
int arr[]={2,7,4,0,9,5,1,3};
int sum=20;
int n=sizeof(arr)/sizeof(arr[0]);
if(!quadtuple(arr,n,sum))
   cout<<"don't exist"<<endl;
cout<<"exist"<<endl;
return 0;
}
