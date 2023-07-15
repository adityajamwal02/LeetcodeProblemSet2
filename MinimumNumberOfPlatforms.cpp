/// Minimum Number Of Platforms : Coding ninjas


int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at,at+n);
    sort(dt,dt+n);
    int i=0, j=0, maxi=0, platforms=0;
    while(i<n and j<n){
        if(at[i]<=dt[j]){
            i++;
            platforms++;
        }else{
            j++;
            platforms--;
        }
        maxi=max(maxi,platforms);
    }
return maxi;
}
