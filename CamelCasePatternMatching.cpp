/*
Given a dictionary of words where each word follows CamelCase notation, print all words (in lexicographical order) in the dictionary that match with a given pattern consisting of uppercase characters only.
Example: GeeksForGeeks matches the pattern "GFG", because if we combine all the capital letters in GeeksForGeeks they become GFG.
CamelCase is the practice of writing compound words or phrases such that each word or abbreviation begins with a capital letter. Common examples include PowerPoint and Wikipedia, GeeksForGeeks, CodeBlocks, etc.

Example 1:
Input:
N=3
Dictionary=["WelcomeGeek",
"WelcomeToGeeksForGeeks","GeeksForGeeks"]
Pattern="WTG"
Output:
WelcomeToGeeksForGeeks
Explanation:
Since only WelcomeToGeeksForGeeks matches
the pattern, it is the only answer.

Example 2:
Input:
N=8
Dictionary=["Hi","Hello","HelloWorld",
"HiTech","HiGeek","HiTechWorld",
"HiTechCity","HiTechLab"]
Pattern="HA"
Output:
-1
Explanation:
Since the pattern matches none of the words
of the string,the output is -1.
Your Task:
You don't need to read input or print anything. Your Task is to complete the function CamelCase() which takes an integer N, a Vector of strings Dictionary and a string Pattern and returns the strings in the dictionary that match the pattern, if not found any return -1.

Expected Time Complexity: O(N*|S|) S=Longest string in Dictionary
Expected Auxillary Space: O(26*N)
*/


class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        vector<string> result;
        int m=Pattern.size();
        for(auto word : Dictionary){
            int n=word.size();
            if(n<m) continue;
            int i=0, j=0;
            while(i<n and j<m){
                if(word[i]>='A' and word[i]<='Z'){
                    if(word[i]==Pattern[j]){
                        i++;
                        j++;
                    }else{
                        break;
                    }
                }else{
                    i++;
                }
                if(j==m){
                    result.push_back(word);
                }
            }
        }
        if(result.empty()){
            result.push_back("-1");
        }
    return result;
    }
};
