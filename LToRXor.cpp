/// L TO R XOR

// O(n)

int findXOR(int L, int R){
    int result=0;
    for(int i=L;i<=R;i++){
        result^=i;
    }
return result;
}

// Optimal Solution :

int findXOR(int L, int R){

    int result=0, len=R-L+1;

    int xorR=R%4;           // Xor result in range [0,R]
    if(xorR==0) result=R;
    else if(xorR==1) result=1;
    else if(xorR==2) result=R+1;
    else if(xorR==3) result=0;

    int xorL=(L-1)%4;       // Xor result in range [0,L-1]
    if(xorL==0) result^=(L-1);
    else if(xorL==1) result^=1;
    else if(xorL==2) result^=(L-1)+1;
    else if(xorL==3) result^=0;

return result;
}
