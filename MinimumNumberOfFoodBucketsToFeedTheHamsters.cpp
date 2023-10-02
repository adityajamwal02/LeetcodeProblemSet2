/*
You are given a 0-indexed string hamsters where hamsters[i] is either:
'H' indicating that there is a hamster at index i, or
'.' indicating that index i is empty.
You will add some number of food buckets at the empty indices in order to feed the hamsters. A hamster can be fed if there is at least one food bucket to its left or to its right. More formally, a hamster at index i can be fed if you place a food bucket at index i - 1 and/or at index i + 1.
Return the minimum number of food buckets you should place at empty indices to feed all the hamsters or -1 if it is impossible to feed all of them.

Example 1:
Input: hamsters = "H..H"
Output: 2
Explanation: We place two food buckets at indices 1 and 2.
It can be shown that if we place only one food bucket, one of the hamsters will not be fed.

Example 2:
Input: hamsters = ".H.H."
Output: 1
Explanation: We place one food bucket at index 2.

Example 3:
Input: hamsters = ".HHH."
Output: -1
Explanation: If we place a food bucket at every empty index as shown, the hamster at index 2 will not be able to eat.
*/

class Solution {
public:
    int minimumBuckets(string hamsters) {
        int n=hamsters.size(), counter1=0, counter2=0;
        if(hamsters=="H" or (hamsters[0]=='H' and hamsters[1]=='H') or (hamsters[n-1]=='H' and hamsters[n-2]=='H')) return -1;
        for(int i=0;i<n-2;i++){
            if(hamsters[i]=='H' and hamsters[i+1]=='H' and hamsters[i+2]=='H') return -1;
        }
        for(int i=0;i<n-2;i++){
            if(hamsters[i]=='H' and hamsters[i+1]=='.' and hamsters[i+2]=='H'){
                counter2++;
                i+=2;
            }
        }
        counter1=count(hamsters.begin(),hamsters.end(),'H');

    return counter1-counter2;;
    }
};
