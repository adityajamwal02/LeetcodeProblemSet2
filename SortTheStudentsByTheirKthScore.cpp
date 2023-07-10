/*
There is a class with m students and n exams. You are given a 0-indexed m x n integer matrix score, where each row represents one student and score[i][j] denotes the score the ith student got in the jth exam. The matrix score contains distinct integers only.
You are also given an integer k. Sort the students (i.e., the rows of the matrix) by their scores in the kth (0-indexed) exam from the highest to the lowest.
Return the matrix after sorting it.

Example 1:
Input: score = [[10,6,9,1],[7,5,11,2],[4,8,3,15]], k = 2
Output: [[7,5,11,2],[10,6,9,1],[4,8,3,15]]
Explanation: In the above diagram, S denotes the student, while E denotes the exam.
- The student with index 1 scored 11 in exam 2, which is the highest score, so they got first place.
- The student with index 0 scored 9 in exam 2, which is the second highest score, so they got second place.
- The student with index 2 scored 3 in exam 2, which is the lowest score, so they got third place.

Example 2:
Input: score = [[3,4],[5,6]], k = 0
Output: [[5,6],[3,4]]
Explanation: In the above diagram, S denotes the student, while E denotes the exam.
- The student with index 1 scored 5 in exam 0, which is the highest score, so they got first place.
- The student with index 0 scored 3 in exam 0, which is the lowest score, so they got second place.
*/

/// Detailed Solution
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int n=score.size(), m=score[0].size();
        vector<vector<int>> result;
        vector<pair<int,int>> index;
        for(int i=0;i<n;i++){
            index.push_back({score[i][k],i});
        }
        sort(index.rbegin(),index.rend());
        for(int i=0;i<index.size();i++){
            int ind=index[i].second;
            vector<int> temp;
            for(int i=0;i<m;i++){
                temp.push_back(score[ind][i]);
            }
            result.push_back(temp);
        }
    return result;
    }
};

/// Quick Short Crisp

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(),score.end(), [k](vector<int> &a, vector<int> &b){
            return a[k]>b[k];
        });
    return score;
    }
};
