/*
N people from 1 to N are standing in the queue at a movie ticket counter. It is a weird counter, as it distributes tickets to the first K people and then the last K people and again first K people and so on, once a person gets a ticket moves out of the queue. The task is to find the last person to get the ticket.

Example 1:
Input:
N = 9
K = 3
Output:
6
Explanation:
Starting queue will like {1, 2, 3, 4, 5, 6, 7, 8, 9}. After the first distribution queue will look like {4, 5, 6, 7, 8, 9}. And after the second distribution queue will look like {4, 5, 6}. The last person to get the ticket will be 6.

Example 2:
Input:
N = 5
K = 1
Output:
3
Explanation:
Queue start as {1, 2, 3, 4, 5} -> {2, 3, 4, 5} -> {2, 3, 4} -> {3, 4} -> {3}
Last person to get ticket will be 3.
Your Task:
You don't need to read input or print anything. Your task is to complete the function distributeTicket() which takes N and K as inputs and returns the last person to get the ticket.

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)
Try to solve it using O(1) space complexity.
*/

/// Deque soln

class Solution {
  public:
    int distributeTicket(int N, int K) {
        deque<int> dq;
        for(int i=1;i<=N;i++){
            dq.push_front(i);
        }
        int i=0, j=N-1, cL=0, cR=0;
        while(dq.size()!=1){
            int count=K;
            while(count!=0 and dq.size()!=1){
                dq.pop_back();
                count--;
            }
            count=K;
            while(count!=0 and dq.size()!=1){
                dq.pop_front();
                count--;
            }
        }
    return dq.front();
    }
};


/// 2 pointer straight

class Solution {
  public:
    int distributeTicket(int N, int K) {
        int left = 1;
        int right = N;
        while(left < right) {
           int temp = K;
           while(left < right && temp--) left++;
           temp = K;
           while(left < right && temp--) right--;
        }
        return left;
    }
};

/// O(1) Solution (Efficient)

class Solution {
  public:
    int distributeTicket(int N, int K) {
       int i=N/K;
       int left = ceil(i/2.0)*K +1  ,right=N-(i/2)*K;
       if(right<left){
            if(i & 1) return right;
            return left;
        }
        if(i & 1) return left;
    return right;
    }
};
