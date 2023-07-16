/// Coding Ninjas Question

void immediateSmaller(vector<int>& a)
{
	int n=a.size();
	vector<int> result(n,-1);
	for(int i=0;i<n-1;i++){
		if(a[i]>a[i+1]){
			result[i]=a[i+1];
		}
	}
	a=result;
}
