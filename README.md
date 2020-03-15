# EE599-HW7-Q5
You are given an undirected graph G with N nodes indexed from 0 to N-1. For each node i in the graph G, determine if there exists one shortest path from node 0 to node N-1 that passes through i: ● Write a function that takes the graph G as the input ● Output a vector of bool B, where B[i] stands for whether there exists a shortest path from 0 to N-1 that passes through node i. Example: Input:  Output: [true, true, true, false, false, true, true, false, true] Explanation: There are two possible shortest path from 0 to 8 each having length of 3:  0 - 1 - 2 - 8 And 0 - 5 - 6 - 8 Therefore, the output vector at indices 0, 1, 2, 5, 6, 8 is set to true because the shortest path between 0 and 8 passes through these nodes. 👉Hint: Try to think of an efficient algorithm for the shortest path when the graph is unweighted.
