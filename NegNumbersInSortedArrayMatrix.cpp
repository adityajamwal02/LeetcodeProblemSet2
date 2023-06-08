/*

*/

/// Naive Approach (mn)

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int counter=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]<0){
                    counter++;
                }
            }
        }
    return counter;
    }
};


/// Better Approach(m+n)

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int counter=0, n=grid.size(), m=grid[0].size();
        int i=n-1, j=0;
        while(j<m and i>=0){
            if(grid[i][j]<0){
                counter+=(m-j);
                i-=1;
            }else{
                j+=1;
            }
        }
    return counter;
    }
};


/// Optimal solution (Binary Search or Upperbound) O(nlogm)


class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int counter=0;
        for(const vector<int> &g : grid){
            counter+=upper_bound(g.rbegin(),g.rend(),-1)-g.rbegin();
        }
    return counter;
    }
};


/// Binary Search

// C++ implementation of More efficient
// method to count number of negative numbers
// in row-column sorted matrix M[n][m]
#include<bits/stdc++.h>
using namespace std;

int getLastNegativeIndex(int array[], int start,
					int end,int n)
{
	if (start == end)
	{
		return start;
	}
	int mid = start + (end - start) / 2;
	if (array[mid] < 0)
	{
	    if (mid + 1 < n && array[mid + 1] >= 0)
		{
			return mid;
		}
		return getLastNegativeIndex(array,
								mid + 1, end, n);
	}
	else
	{
		return getLastNegativeIndex(array,start, mid - 1, n);
	}
}

int countNegative(int M[][4], int n, int m)
{
	int count = 0;
	int nextEnd = m - 1;
	for (int i = 0; i < n; i++)
	{
		if (M[i][0] >= 0)
		{
			break;
		}
		nextEnd = getLastNegativeIndex(M[i], 0, nextEnd, 4);
		count += nextEnd + 1;
	}
	return count;
}

int main()
{
	int M[][4] = { { -3, -2, -1, 1 },
					{ -2, 2, 3, 4 },
					{ 4, 5, 7, 8 } };
	int r = 3;
	int c = 4;
	cout << (countNegative(M, r, c));
	return 0;
}





