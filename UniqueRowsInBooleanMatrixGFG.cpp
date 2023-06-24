

class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
    {
        vector<vector<int>> result;
        map<vector<int>,int>mp;
        for(int i=0;i<row;i++){
            vector<int> temp;
            for(int j=0;j<col;j++){
                temp.push_back(M[i][j]);
            }
            if(!mp[temp]++)
                result.push_back(temp);
        }
    return result;
    }
};
