/*
Given an array of N strings, find the longest common prefix among all strings present in the array.

Example 1:
Input:
N = 4
arr[] = {geeksforgeeks, geeks, geek,
         geezer}
Output: gee
Explanation: "gee" is the longest common
prefix in all the given strings.

Example 2:
Input:
N = 2
arr[] = {hello, world}
Output: -1
Explanation: There's no common prefix
in the given strings.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestCommonPrefix() which takes the string array arr[] and its size N as inputs and returns the longest common prefix common in all the strings in the array. If there's no prefix common in all the strings, return "-1".


Expected Time Complexity: O(N*min(|arri|)).
Expected Auxiliary Space: O(min(|arri|)) for result.
*/


class Solution{
  public:
    string longestCommonPrefix (string arr[], int N)
    {
        string ans="";
        bool flag=true;
        for(int i=0;i<arr[0].size();i++){
            char ch=arr[0][i];
            for(int j=0;j<N;j++){
                if(arr[j].size()<i or ch!=arr[j][i]){
                    flag=false;
                    break;
                }
            }
            if(flag) ans.push_back(ch);
            else break;
        }
        return (ans.size()==0) ? "-1" : ans;
    }
};
