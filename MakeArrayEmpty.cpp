/*
You are given an integer array nums containing distinct numbers, and you can perform the following operations until the array is empty:
If the first element has the smallest value, remove it
Otherwise, put the first element at the end of the array.
Return an integer denoting the number of operations it takes to make nums empty.

Example 1:
Input: nums = [3,4,-1]
Output: 5
Operation	Array
1	[4, -1, 3]
2	[-1, 3, 4]
3	[3, 4]
4	[4]
5	[]

Example 2:
Input: nums = [1,2,4,3]
Output: 5
Operation	Array
1	[2, 4, 3]
2	[4, 3]
3	[3, 4]
4	[4]
5	[]

Example 3:
Input: nums = [1,2,3]
Output: 3
Operation	Array
1	[2, 3]
2	[3]
3	[]


Constraints:
1 <= nums.length <= 105
-109 <= nums[i] <= 109
All values in nums are distinct.
*/

/// Greedy Approach

class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> mat(n,vector<int>(2));
        for(int i=0;i<n;i++){
            mat[i][0]=nums[i];
            mat[i][1]=i;
        }
        sort(mat.begin(), mat.end(), [](vector<int> &a, vector<int> &b){
            return a[0]<b[0];
        });
        long long result=0, m=0;
        for(int i=0;i<n;i++){
            if(i>0 and mat[i][1]<mat[i-1][1]){
                result+=(n-m);
                m=i;
            }
        }
        result+=(n-m);
    return result;
    }
};

/// Segment Tree Approach

class Solution {
public:
    int size;
    vector<int> tree;
    void add(int pos) {
        tree[size + pos - 1] = 1;
        for (int i = (size + pos - 2) / 2; i > 0; i = (i - 1) / 2) {
            tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
        }
        if (size > 1) {
            tree[0] = tree[1] + tree[2];
        }
    }
    int getSum(int root, int l, int r, int left, int right) {
        if (right < l || left > r) return 0;
        if (left >= l && right <= r) return tree[root];
        int mid = (left + right) / 2;
        return getSum(2 * root + 1, l, r, left, mid) + getSum(2 * root + 2, l, r, mid + 1, right);
    }
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> in(n);
        iota(in.begin(), in.end(), 0);
        sort(in.begin(), in.end(), [&] (int i, int j) {
            return nums[i] < nums[j];
        });
        size = 1;
        while (size < n) {
            size *= 2;
        }
        tree = vector<int> (2 * size - 1);
        int cur = 0;
        long long sol = 0;
        for (int i = 0; i < n; i++) {
            int pos = in[i];
            if (cur <= pos) {
                int sum = getSum(0, cur, pos, 0, size - 1);
                int diff = pos - cur - sum;
                sol += diff + 1;
            } else {
                int sum = getSum(0, cur, n - 1, 0, size - 1);
                sum += getSum(0, 0, pos, 0, size - 1);
                int diff = n - (cur - pos) - sum;
                sol += diff + 1;
            }
            add(pos);
            cur = (pos + 1) % n;
        }
        return sol;
    }
};

