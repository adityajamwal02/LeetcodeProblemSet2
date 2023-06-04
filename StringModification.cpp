/*
Given a string with repeated characters, the task is to complete the function rearrangeString which rearrange characters in a string so that no two adjacent characters are same.
Note : It may be assumed that the string has only lowercase English alphabets and such transformation is always always possible.

Example 1:
Input:
S = aaabc
Output: 1
Explanation: We can transform the string
to abaca.

Example 2:
Input:
S = aaabb
Output: 1
Explanation: We can transform the string
to ababa.

Your Task:
Complete the function rearrangeString() which takes a string as an input parameter and returns the rearranged string. (The output will be 1 if the returned string has no adjacent character same, otherwise 0. Printing is done by the driver's code.)
Expected Time Complexity: O(N * log N), N = length of the string.
Expected Auxiliary Space: O(constant)
Constraints:
1< N < 105
*/

/// PQ + HashMap (26 char limited)

/* The below function should return
the transformed string */
class Solution{
  public:
    string rearrangeString(string str)
    {
       int n=str.size();
       vector<int> hashmap(26);
       for(auto it : str){
           hashmap[it-'a']++;
       }
       priority_queue<pair<int,char>> pq;
       for(char i='a';i<='z';i++){
           if(hashmap[i-'a']) pq.push({hashmap[i-'a'],i});
       }
       string result=str;
       int i=0;
       while(!pq.empty()){
           int temp=pq.top().first;
           while(temp>0){
               result[i]=pq.top().second;
               temp--;
               i+=2;
               if(i>=n) i=1;
           }
           pq.pop();
       }
      return result;
    }
};


/// PQ + unordered_map


/* The below function should return
the transformed string */
class Solution{
  public:
    string rearrangeString(string str)
    {
       int n=str.size();
       string result=str;
       map<char, int> mp;
       for(int i=0;i<n;i++){
           mp[str[i]]++;
       }
       priority_queue<pair<int,char>> pq;
       for(auto it : mp){
           pq.push({it.second,it.first});
       }
       int i=0;
       while(!pq.empty()){
           int temp=pq.top().first;
           while(temp){
               result[i]=pq.top().second;
               temp--;
               i+=2;
               if(i>=n) i=1;
           }
           pq.pop();
       }
    return result;
    }
};




