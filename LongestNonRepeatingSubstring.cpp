


/// Mapping with Hashmap, for latest index based

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int left=0, right=0, len=0;
        vector<int> mp(256, -1);
        while(right<n){
            if(mp[s[right]]!=-1)
                left=max(mp[s[right]]+1, left);
            mp[s[right]]=right;
            len=max(len, right-left+1);
            right++;
        }
        return len;
    }
};


/// Mapping with Hashmap, count of occurences in Sliding window

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int store[256]={0}; //array to store the occurences of all the characters
        int l=0;    //left pointer
        int r=0;    //right pointer
        int ans=0;  //initializing the required length as 0

        while(r<s.length())     //iterate over the string till the right pointer reaches the end of the string
        {
            store[s[r]]++;      //increment the count of the character present in the right pointer

            while(store[s[r]]>1)    //if the occurence become more than 1 means the char is repeated
            {
                store[s[l]]--;   //reduce the occurence of temp as it might be present ahead also in the string
                l++;         //contraction of the present window till the occurence of the 't' char becomes 1
            }

            ans = max(ans,r-l+1);    //As the index starts from 0 , ans will be (right pointer-left pointer + 1)
            r++;        // now will increment the right pointer
        }
        return ans;
    }
};
