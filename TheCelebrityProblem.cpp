/// Coding Ninjas : Stack based


/// TLE

#include <bits/stdc++.h>
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B);
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
	int peopleKnow=0, heKnow=0;
	vector<int> prefix(n,0), suffix(n,0);
	// prefix -> peopleKnow : prefix[i]==n-1
	// suffix -> heKnow : suffix[i]==0
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j){
				bool temp=knows(i,j);
				if(temp==true) prefix[j]++;
				temp=knows(j,i);
				if(temp==true) suffix[j]++;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(prefix[i]==n-1 and suffix[i]==0) return i;
	}
return -1;
}


/// Stack based solution

#include <bits/stdc++.h>
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B);
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
	stack<int> st;
	for(int i=0;i<n;i++){
		st.push(i);
	}
	while(st.size()>1){
		int first=st.top();
		st.pop();
		int second=st.top();
		st.pop();
		if(knows(first,second)){
			st.push(second);
		}else st.push(first);
	}
	int result=st.top();
	for(int i=0;i<n;i++){
		if(i==result) continue;
		if(knows(result,i)) return -1;
		if(!knows(i,result)) return -1;
	}
return result;
}
