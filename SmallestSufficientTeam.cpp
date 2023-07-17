/*
In a project, you have a list of required skills req_skills, and a list of people. The ith person people[i] contains a list of skills that the person has.
Consider a sufficient team: a set of people such that for every required skill in req_skills, there is at least one person in the team who has that skill. We can represent these teams by the index of each person.
For example, team = [0, 1, 3] represents the people with skills people[0], people[1], and people[3].
Return any sufficient team of the smallest possible size, represented by the index of each person. You may return the answer in any order.
It is guaranteed an answer exists.

Example 1:
Input: req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
Output: [0,2]

Example 2:
Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"], people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
Output: [1,2]
*/

/// Masking for present skills: 1 for take and 0 for not take in the string (bitmask approach) + DP (0/1 knapsack)
/// Place indexes for every string to search (required skills), map every skill with index (in binary form with left shift for every req. skill)
/// Apply OR Operation within people to get all the skills of that particular person so, 10 or 100 => 110 means index 1 and index 2 element present with him)

/// (DP + Bitmask + Map) -> Memoization Solution

class Solution {
public:
    int dp[1<<16][64];
    bool choice[1<<16][64];
    int req_mask, n, m;

    int helper(int i, int mask, vector<int> &people){
        if(mask==req_mask) return 0;
        if(i==m) return 10000;
        int &result=dp[mask][i];
        if(result!=-1) return result;
        int ans1=helper(i+1,mask|people[i],people)+1;
        int ans2=helper(i+1,mask,people);

        if(ans1<ans2){
            choice[mask][i]=1;
        }

        return result=min(ans1,ans2);
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        vector<int> result;
        n=req_skills.size();
        m=people.size();

        unordered_map<string,int> skills;
        for(int i=0;i<n;i++){
            skills[req_skills[i]]=i;
        }

        vector<int> person;
        for(auto v : people){
            int h=0;
            for(string &skill : v){
                h|=1<<skills[skill];
            }
            person.push_back(h);
        }

        req_mask=(1<<n)-1;
        memset(dp,-1,1<<n+8);
        memset(choice,0,1<<n+6);

        helper(0,0,person);

        // build answer via choice matrix
        for(int i=0, mask=0;i<m;i++){
            if(choice[mask][i]){
                result.push_back(i);
                mask|=person[i];
            }
            if(mask==req_mask) break;
        }
    return result;
    }
};


/// Tabulation (Space optimized)


class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n=req_skills.size(), m=people.size();
        unordered_map<int,vector<int>> dp;
        dp.reserve(1<<n);
        dp[0]={};
        unordered_map<string,int> skill_index;
        for(int i=0;i<n;i++){
            skill_index[req_skills[i]]=i;
        }
        for(int i=0;i<m;i++){
            int currSkill=0;
            for(auto &skill : people[i]){
                currSkill|=1<<skill_index[skill];
            }
            for(auto it = dp.begin();it!=dp.end();it++){
                int combination=it->first|currSkill;
                if(dp.find(combination)==dp.end() or dp[combination].size() > 1+dp[it->first].size()){
                    dp[combination]=it->second;
                    dp[combination].push_back(i);
                }
            }
        }
    return dp[(1<<n)-1];
    }
};
