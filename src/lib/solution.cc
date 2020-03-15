#include "solution.h"
#include <map>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

void check_for_shortest_path(int i,vector<bool>& b,vector<int>& path_to_node,map<int,set<int>>& neighbour_map,int short_dist,int dest)
{
  int root=i;
  queue<int> q;
  q.push(root);
  map<int,int> marks;
  map<int,int> dist_from_node;
  map<int,vector<int>> path_from_node;
  marks[root]=1;
  dist_from_node[root]=0;
  path_from_node[root].push_back(root);
  while(!q.empty())
  {
    int cur=q.front();
    q.pop();
    for(auto &n:neighbour_map[cur])
    {
      if(!marks[n])
      {
        marks[n]=1;
        dist_from_node[n]=dist_from_node[cur]+1;
        path_from_node[n]=path_from_node[cur];
        path_from_node[n].push_back(n);
        q.push(n);
        if(n==dest)
          break;
      }
    }
  }
  if(short_dist>=(int(path_to_node.size()-1)+dist_from_node[dest]))
    b[root]=true;
}
vector<bool> Graph::shortest_path_nodes(map<int,set<int>>& neighbour_map,int source,int dest) 
{
  vector<bool> b(neighbour_map.size(),false);
  map<int,int> marks;
  queue<int> q;
  q.push(source);
  marks[source]=1;
  parent[source]=source;
  dist_node[source]=0;
  path_node[source].push_back(source);
  while(!q.empty())
  {
    int cur=q.front();
    q.pop();
    for(auto &n:neighbour_map[cur])
    {
      if(!marks[n])
      {
        marks[n]=1;
        dist_node[n]=dist_node[cur]+1;
        parent[n]=cur;
        path_node[n]=path_node[cur];
        path_node[n].push_back(n);
        q.push(n);
      }
    }
  }
  int shortest_path_dist=dist_node[dest];
  for(auto i:path_node[dest])
    b[i]=true;
  for(int i=0;i<b.size();i++)
  {
    if(b[i]==false)
      check_for_shortest_path(i,b,path_node[i],neighbour_map,shortest_path_dist,dest);    
  }
  return b;
}
