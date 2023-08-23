/*
Given a 2D grid of n*m of characters and a word, find all occurrences of given word in grid. A word can be matched in all 8 directions at any point. Word is said to be found in a direction if all characters match in this direction (not in zig-zag form). The 8 directions are, horizontally left, horizontally right, vertically up, vertically down, and 4 diagonal directions.
Note: The returning list should be lexicographically smallest. If the word can be found in multiple directions starting from the same coordinates, the list should contain the coordinates only once.

Example 1:
Input:
grid = {{a,b,c},{d,r,f},{g,h,i}},
word = "abc"
Output:
{{0,0}}
Explanation:
From (0,0) we can find "abc" in horizontally right direction.

Example 2:
Input:
grid = {{a,b,a,b},{a,b,e,b},{e,b,e,b}}
word = "abe"
Output:
{{0,0},{0,2},{1,0}}
Explanation:
From (0,0) we can find "abe" in right-down diagonal.
From (0,2) we can find "abe" in left-down diagonal.
From (1,0) we can find "abe" in horizontally right direction.
Your Task:
You don't need to read or print anything, Your task is to complete the function searchWord() which takes grid and word as input parameters and returns a list containing the positions from where the word originates in any direction. If there is no such position then returns an empty list.

Expected Time Complexity: O(n*m*k) where k is constant
Expected Space Complexity: O(1)
*/

class Solution {
public:
    int delrow[8]={-1,-1,-1,0,0,1,1,1};
    int delcol[8]={-1,0,1,1,-1,-1,0,1};

    bool isValid(int i, int j, int n, int m, string word, vector<vector<char>> &grid, int index, int sz, int k){
        if(index==sz) return true;
        if(i>=0 and j>=0 and i<n and j<m and grid[i][j]==word[index]){
            return isValid(i+delrow[k],j+delcol[k],n,m,word,grid,index+1,sz,k);
        }
    return false;
    }

	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    int n=grid.size(), m=grid[0].size();
	    int sz=word.size();
	    vector<vector<int>> result;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==word[0]){
	                for(int k=0;k<8;k++){
	                    int nrow=i+delrow[k];
	                    int ncol=j+delcol[k];
	                    if(isValid(nrow,ncol,n,m,word,grid,1,sz,k)){
	                        result.push_back({i,j});
	                        break;
	                    }
	                }
	            }
	        }
	    }
	   return result;
	}
};
