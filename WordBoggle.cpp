/*
Given a dictionary of distinct words and an M x N board where every cell has one character. Find all possible words from the dictionary that can be formed by a sequence of adjacent characters on the board. We can move to any of 8 adjacent characters
Note: While forming a word we can move to any of the 8 adjacent cells. A cell can be used only once in one word.

Example 1:
Input:
N = 1
dictionary = {"CAT"}
R = 3, C = 3
board = {{C,A,P},{A,N,D},{T,I,E}}
Output:
CAT
Explanation:
C A P
A N D
T I E
Words we got is denoted using same color.

Example 2:
Input:
N = 4
dictionary = {"GEEKS","FOR","QUIZ","GO"}
R = 3, C = 3
board = {{G,I,Z},{U,E,K},{Q,S,E}}
Output:
GEEKS QUIZ
Explanation:
G I Z
U E K
Q S E
Words we got is denoted using same color.

Your task:
You dont need to read input or print anything. Your task is to complete the function wordBoggle() which takes the dictionary contaning N space-separated strings and R*C board as input parameters and returns a list of words that exist on the board in lexicographical order.

Expected Time Complexity: O(N*W + R*C^2)
Expected Auxiliary Space: O(N*W + R*C)
*/

class Solution {
public:

    bool dfs(int i, int j, int n, int m, string &str, vector<vector<int>> &vis, vector<vector<char>> &board){
        if(str.size()==0) return true;
        if(i<0 or i>=n or j<0 or j>=m or board[i][j]!=str[0] or vis[i][j]==1) return false;
        string check=str.substr(1);
        vis[i][j]=1;
        bool ans=dfs(i-1,j-1,n,m,check,vis,board);
        ans|=dfs(i-1,j,n,m,check,vis,board);
        ans|=dfs(i-1,j+1,n,m,check,vis,board);
        ans|=dfs(i,j-1,n,m,check,vis,board);
        ans|=dfs(i,j+1,n,m,check,vis,board);
        ans|=dfs(i+1,j-1,n,m,check,vis,board);
        ans|=dfs(i+1,j,n,m,check,vis,board);
        ans|=dfs(i+1,j+1,n,m,check,vis,board);
        vis[i][j]=0;
    return ans;
    }

	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    int n=board.size(), m=board[0].size();
	    set<string> st;
	    for(auto str : dictionary){
	        vector<vector<int>> vis(n,vector<int>(m,0));
	        for(int i=0;i<n;i++){
	            for(int j=0;j<m;j++){
	                if(str[0]==board[i][j]){
	                    if(dfs(i,j,n,m,str,vis,board)){
	                        st.insert(str);
	                    }
	                }
	            }
	        }
	    }
	    vector<string> result(st.begin(),st.end());
	return result;
	}
};



