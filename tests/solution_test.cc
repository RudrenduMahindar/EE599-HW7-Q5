#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

TEST(ShortestPathNodesTest, ReturnBool) {
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
  vector<bool> actual_bool=g.shortest_path_nodes(vertices,start,end);
  vector<bool> expected_bool={true, true, true, false, false, true, true, false, true};
  EXPECT_EQ(expected_bool, actual_bool);
}