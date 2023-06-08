/*
Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item.



Example 1:

Input:
N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
Output:
240.00
Explanation:Total maximum value of item
we can have is 240.00 from the given
capacity of sack.
Example 2:

Input:
N = 2, W = 50
values[] = {60,100}
weight[] = {10,20}
Output:
160.00
Explanation:
Total maximum value of item
we can have is 160.00 from the given
capacity of sack.


Your Task :
Complete the function fractionalKnapsack() that receives maximum capacity , array of structure/class and size n and returns a double value representing the maximum value in knapsack.
Note: The details of structure/class is defined in the comments above the given function.


Expected Time Complexity : O(NlogN)
Expected Auxilliary Space: O(1)
*/

//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:

    static bool cmp(Item a, Item b){
        double one = double(a.value)/double(a.weight);
        double two = double(b.value)/double(b.weight);
        if(one>=two) return 1;
    return 0;
    }

    //Function to get the maximum total value in the knapsack.

    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,cmp);
        double sum=0;
        for(int i=0;i<n;i++){
            if(arr[i].weight<=W){
                sum+=arr[i].value;
                W-=arr[i].weight;
            }else{
                sum+=(W*(double)(arr[i].value/(double)(arr[i].weight)));
                W=0;
            }
        }
    return sum;
    }

};
