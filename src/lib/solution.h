#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Graph{
public:
  Graph(map<int,set<int>>& vertices):v_(vertices){}
  map<int,set<int>> v_;
  vector<bool> shortest_path_nodes(map<int,set<int>>&,int,int);
  map<int,int> dist_node;
  map<int,vector<int>> path_node;
  map<int,int> parent;
};

#endif