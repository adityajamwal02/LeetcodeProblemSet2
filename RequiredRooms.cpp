/*
A seminar of Artificial Intelligence is going on,and the number of participants from Foreign is N, while from India is M. All the participants would be staying in the same hotel.In each room equal number of participants have to stay( can be 1 in a room).Also foreign and Indian cannot stay in the same room. Find the minimum number of rooms required,if in each room the same number of participants are to be seated.

Example 1:
Input: N = 60, M = 84
Output: 12
Explaination: In each room we will keep 12
person. So total 5+7 = 12 rooms are required.

Example 2:
Input: N = 8, M = 11
Output: 19
Explaination: We can keep 1 person in each
room. So total 19 rooms are required.
Your Task:
You do not need to read input or print anything. Your task is to complete the function rooms() which takes N and M as input parameters and returns minimum required rooms.

Expected Time Complexity: O(log(max(N,M)))
Expected Auxiliary Space: O(1)
*/

//User function Template for C++

class Solution{
public:
    int rooms(int N, int M){
        int temp=__gcd(N,M);
    return ((N+M)%temp==0) ? (N+M)/temp : ((N+M)/temp)+1;
    }
};
