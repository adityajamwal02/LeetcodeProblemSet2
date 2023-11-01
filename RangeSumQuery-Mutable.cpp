/*
Given an integer array nums, handle multiple queries of the following types:
Update the value of an element in nums.
Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:
NumArray(int[] nums) Initializes the object with the integer array nums.
void update(int index, int val) Updates the value of nums[index] to be val.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

Example 1:
Input
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
Output
[null, 9, null, 8]

Explanation
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
*/


class SegmentTree{
public:
    vector<int> segmentTree;

    SegmentTree(int n){
        segmentTree.resize(4*n);
    }

    void build(int i, int low, int high, vector<int> &nums){
        if(low==high){
            segmentTree[i]=nums[low];
        return;
        }
        int mid=(low+high)/2;
        build(2*i+1,low,mid,nums);
        build(2*i+2,mid+1,high,nums);

    segmentTree[i]=segmentTree[2*i+1]+segmentTree[2*i+2];
    }

    int query(int i, int low, int high, int left, int right){
        if(high<left or low>right) return 0;
        if(low>=left and high<=right) return segmentTree[i];
        int mid=(low+high)/2;
        int leftSide=query(2*i+1,low,mid,left,right);
        int rightSide=query(2*i+2,mid+1,high,left,right);

    return leftSide+rightSide;
    }

    void update(int i, int low, int high, int index, int val){
        if(low==index and high==index){
            segmentTree[i]=val;
            return;
        }
        int mid=(low+high)/2;
        if(index<=mid) update(2*i+1,low,mid,index,val);
        else update(2*i+2,mid+1,high,index,val);

    segmentTree[i]=segmentTree[2*i+1]+segmentTree[2*i+2];
    }
};

class NumArray {
public:
    SegmentTree *st;
    int n;
    NumArray(vector<int>& nums){
        n=nums.size();
        st=new SegmentTree(n);
        st->build(0,0,n-1,nums);
    }
    void update(int index, int val){
        st->update(0,0,n-1,index,val);
    }
    int sumRange(int left, int right){
        return st->query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
