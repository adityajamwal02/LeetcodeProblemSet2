/*
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle values.
For examples, if arr = [2,3,4], the median is 3.
For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
You are given an integer array nums and an integer k. There is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Return the median array for each window in the original array. Answers within 10-5 of the actual value will be accepted.

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
Explanation:
Window position                Median
---------------                -----
[1  3  -1] -3  5  3  6  7        1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7        3
 1  3  -1  -3 [5  3  6] 7        5
 1  3  -1  -3  5 [3  6  7]       6

Example 2:
Input: nums = [1,2,3,4,2,3,1,4,2], k = 3
Output: [2.00000,3.00000,3.00000,3.00000,2.00000,3.00000,2.00000]
*/


class Solution {
public:
    void balanceHeaps(multiset<int> &minHeap, multiset<int> &maxHeap, int k){
        if(k%2==0){
            while(minHeap.size()!=maxHeap.size()){
                if(minHeap.size()>maxHeap.size()){
                    auto it=minHeap.begin();
                    maxHeap.insert(*it);
                    minHeap.erase(it);
                }else{
                    auto it=maxHeap.rbegin();
                    minHeap.insert(*it);
                    maxHeap.erase(maxHeap.find(*it));
                }
            }
        }else{
            while(abs((int)(minHeap.size()-maxHeap.size()))>1){
                if(minHeap.size()>maxHeap.size()){
                    auto it=minHeap.begin();
                    maxHeap.insert(*it);
                    minHeap.erase(it);
                }else{
                    auto it=maxHeap.rbegin();
                    minHeap.insert(*it);
                    maxHeap.erase(maxHeap.find(*it));
                }
            }
            if(minHeap.size()>maxHeap.size()){
                auto it = minHeap.begin();
                maxHeap.insert(*it);
                minHeap.erase(it);
            }
        }
    }
    double computeMedian(multiset<int> &minHeap, multiset<int> &maxHeap, int k){
        if(k%2==0){
            return ((double)*maxHeap.rbegin()+(double)*minHeap.begin())/2.0;
        }
    return (double)*maxHeap.rbegin();
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size(), i=0, j=0;
        multiset<int> minHeap, maxHeap;
        vector<double> result;
        for(;j<k-1;j++){
            maxHeap.insert(nums[j]);
        }
        j=k-1;
        while(j<n){
            if(!maxHeap.empty() and nums[j]>*maxHeap.rbegin()){
                minHeap.insert(nums[j]);
            }else{
                maxHeap.insert(nums[j]);
            }
            balanceHeaps(minHeap,maxHeap,k);
            result.push_back(computeMedian(minHeap,maxHeap,k));

            if(minHeap.find(nums[i])!=minHeap.end()){
                minHeap.erase(minHeap.find(nums[i]));
            }else{
                if(maxHeap.find(nums[i])!=maxHeap.end()){
                    maxHeap.erase(maxHeap.find(nums[i]));
                }
            }
            i++;
            j++;
        }
    return result;
    }
};
