/// Slot Game

#include <bits/stdc++.h>
int slotScore(string &original, string &guess)
{
	int totalScore=0, n=original.size();
	unordered_map<char,int> mp;
	for(int i=0;i<n;i++){
		if(guess[i]==original[i]){
			totalScore+=2;
			original[i]='#';
			guess[i]='#';
		}else{
			mp[original[i]]++;
		}
	}
	for(int i=0;i<n;i++){
		if(mp[guess[i]]!=0){
			totalScore++;
			mp[guess[i]]--;
		}
	}
return totalScore;
}
