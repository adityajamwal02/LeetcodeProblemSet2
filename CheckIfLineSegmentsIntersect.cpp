/*
 Given the coordinates of the endpoints(p1-q1 and p2-q2) of the two line-segments. Check if they intersect or not.

Example 1:

Input:
p1=(1,1)
q1=(10,1)
p2=(1,2)
q2=(10,2)
Output:
0
Explanation:
The two line segments formed
by p1-q1 and p2-q2 do not intersect.
Example 2:

Input:
p1=(10,0)
q1=(0,10)
p2=(0,0)
q2=(10,10)
Output:
1
Explanation:
The two line segments formed
by p1-q1 and p2-q2 intersect.

Your Task:
You don't need to read input or print anything. Your task is to complete the function doIntersect() which takes the four points as input parameters and returns 1 if the line segments intersect. Otherwise, it returns 0.


Expected Time Complexity:O(1)
Expected Auxillary Space:O(1)
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int orient(int a[], int b[], int c[]){
        int x=(b[1]-a[1])*(c[0]-b[0]) - (b[0]-a[0])*(c[1]-b[1]);
        if(x==0) return 0;
    return (x>0) ? 1 : 2;
    }

    bool isCollinear(int a[], int b[], int c[]){
        if((c[0]>=min(a[0],b[0]) and c[0]<=max(a[0],b[0])) and (c[1]>=min(a[1],b[1]) and c[1]<=max(a[1],b[1])))
            return true;
    return false;
    }

    int doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        int o1=orient(p1,q1,p2);
        int o2=orient(p1,q1,q2);
        int o3=orient(p2,q2,p1);
        int o4=orient(p2,q2,q1);
        // general case (counter-clockwise and clockwise)
        if(o1!=o2 and o3!=o4) return 1;
        // Special cases
        if(o1==0 and isCollinear(p1,q1,p2)==true){
            return 1;
        }
        if(o2==0 and isCollinear(p1,q1,q2)==true){
            return 1;
        }
        if(o3==0 and isCollinear(p2,q2,p1)==true){
            return 1;
        }
        if(o4==0 and isCollinear(p2,q2,q1)==true){
            return 1;
        }
    return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p1[2], q1[2], p2[2], q2[2];
        cin >> p1[0] >> p1[1] >> q1[0] >> q1[1] >> p2[0] >> p2[1] >> q2[0] >>
            q2[1];
        Solution ob;
        cout << ob.doIntersect(p1, q1, p2, q2) << "\n";
    }
}
// } Driver Code Ends
