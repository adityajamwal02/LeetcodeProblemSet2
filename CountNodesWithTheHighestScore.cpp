/*
There is a binary tree rooted at 0 consisting of n nodes. The nodes are labeled from 0 to n - 1. You are given a 0-indexed integer array parents representing the tree, where parents[i] is the parent of node i. Since node 0 is the root, parents[0] == -1.
Each node has a score. To find the score of a node, consider if the node and the edges connected to it were removed. The tree would become one or more non-empty subtrees. The size of a subtree is the number of the nodes in it. The score of the node is the product of the sizes of all those subtrees.
Return the number of nodes that have the highest score.

Example 1:
example-1
Input: parents = [-1,2,0,2,0]
Output: 3
Explanation:
- The score of node 0 is: 3 * 1 = 3
- The score of node 1 is: 4 = 4
- The score of node 2 is: 1 * 1 * 2 = 2
- The score of node 3 is: 4 = 4
- The score of node 4 is: 4 = 4
The highest score is 4, and three nodes (node 1, node 3, and node 4) have the highest score.

Example 2:
example-2
Input: parents = [-1,2,0]
Output: 2
Explanation:
- The score of node 0 is: 2 = 2
- The score of node 1 is: 2 = 2
- The score of node 2 is: 1 * 1 = 1
The highest score is 2, and two nodes (node 0 and node 1) have the highest score.
*/


class Solution {
public:
    /* Initial thought process to create a network from parents array and calculate individual branches (for product)
    else maximum connected component for the score. DFS for this purpose while maintain map for graph / tree building.
    We can have 3 main branches: left child subsegment, right child subsegment and upper subsegment (from current node).
    upper = (n-1-left-right) -> (n-1-(left+right)) -> left and right from recursion
    */

    long long countNodes(int node, int n, unordered_map<int,vector<int>> &graph, vector<long long> &mp){
        long long counter=1;
        for(auto child : graph[node]){
            counter+=(countNodes(child,n,graph,mp));
        }
    return mp[node]=counter;
    }

    int countHighestScoreNodes(vector<int>& parents){
        int n=parents.size();
        long long result=0, maxi=0;
        unordered_map<int,vector<int>> graph;
        vector<long long> mp(n,0);
        for(int i=0;i<n;i++){
            graph[parents[i]].push_back(i);
        }
        countNodes(0,n,graph,mp);
        for(int i=0;i<n;i++){
            long long temp=1;
            temp=max(temp,n-mp[i]);
            for(auto node : graph[i]){
                temp=temp*mp[node];
            }
            if(temp>maxi){
                maxi=temp;
                result=1;
            }else if(temp==maxi){
                result++;
            }
        }
    return result;
    }
};
