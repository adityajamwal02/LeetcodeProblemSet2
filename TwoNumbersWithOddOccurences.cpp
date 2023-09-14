/// Two Numbers with odd occurrences


vector<int> twoOddNum(vector<int> arr){
    int xorResult=0;
    for(int i=0;i<arr.size();i++){
        xorResult^=arr[i];
    }
    // Finding rightmost set bit
    int k=xorResult&(~(xorResult-1));
    int xor1=0, xor2=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]&k){
            xor1=xor1^arr[i];
        }else{
            xor2=xor2^arr[i];
        }
    }
    if(xor1<xor2)
        return { xor2, xor1 };

    return { xor1, xor2 };
}
