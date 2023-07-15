
/// Typical Stack based question

#include<bits/stdc++.h>

vector<int> nextGreaterElement(vector<int> &arr, int n) {
	vector<int> result;
	stack<int> st;
	for(int i=n-1;i>=0;i--){
		if(st.empty()){
			result.push_back(-1);
				st.push(arr[i]);
		}else if(!st.empty() and arr[i]<st.top()){
			result.push_back(st.top());
			st.push(arr[i]);
		}else if(!st.empty() and arr[i]>=st.top()){
			while(!st.empty() and arr[i]>=st.top()){
				st.pop();
			}
			if(st.empty()){
				result.push_back(-1);
				st.push(arr[i]);
			}else{
				result.push_back(st.top());
				st.push(arr[i]);
			}
		}
	}
	reverse(result.begin(),result.end());
return result;
}

/// Shorter

#include<bits/stdc++.h>

vector<int> nextGreaterElement(vector<int> &arr, int n) {
	vector<int> result(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() and arr[i] >= st.top()) {
            st.pop();
        }

        if (!st.empty()) {
            result[i] = st.top();
        }

        st.push(arr[i]);
    }

    return result;
}
