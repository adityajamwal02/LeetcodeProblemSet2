/// Breaak The Board :

#include <bits/stdc++.h>
int minimumCost(vector<int> row, vector<int> column, int l, int w) {
	sort(row.begin(),row.end());
	sort(column.begin(),column.end());
	int result=0, h=1, v=1;
	int i=l-2, j=w-2;
	while(i>=0 and j>=0){
		if(row[i]>column[j]){
			result+=(row[i]*v);
			i--;
			h++;
		}else{
			result+=(column[j]*h);
			j--;
			v++;
		}
	}
	while(i>=0){
		result+=(row[i]*v);
		i--;
		h++;
	}
	while(j>=0){
		result+=(column[j]*h);
		j--;
		v++;
	}
	return result;
}
