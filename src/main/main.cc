#include <iostream>
#include "src/lib/solution.h"
#include <map>
#include <set>
using namespace std;

int main()
{
    map<int,set<int>> vertices {{0,{1,4,5}}, 
    {1,{0,2,3}},
    {2,{1,3,8}},
    {3,{1,2}},
    {4,{0}},
    {5,{0,6}},
    {6,{5,7,8}},
    {7,{6,8}},
    {8,{2,6,7}}};
    Graph g(vertices);
    int start=0;
    int end=int(vertices.size()-1);
    vector<bool> b=g.shortest_path_nodes(vertices,start,end);
    cout<<"[ ";
    for(auto i:b)
    {
        if(i==true)
            cout<<"true ";
        else
            cout<<"false ";
    }
    cout<<"]"<<endl;    
    return EXIT_SUCCESS;
}