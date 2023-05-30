/*
Design a Skiplist without using any built-in libraries.
A skiplist is a data structure that takes O(log(n)) time to add, erase and search. Comparing with treap and red-black tree which has the same function and performance, the code length of Skiplist can be comparatively short and the idea behind Skiplists is just simple linked lists.
For example, we have a Skiplist containing [30,40,50,60,70,90] and we want to add 80 and 45 into it. The Skiplist works this way:
Artyom Kalinin [CC BY-SA 3.0], via Wikimedia Commons
You can see there are many layers in the Skiplist. Each layer is a sorted linked list. With the help of the top layers, add, erase and search can be faster than O(n). It can be proven that the average time complexity for each operation is O(log(n)) and space complexity is O(n).
See more about Skiplist: https://en.wikipedia.org/wiki/Skip_list
Implement the Skiplist class:
Skiplist() Initializes the object of the skiplist.
bool search(int target) Returns true if the integer target exists in the Skiplist or false otherwise.
void add(int num) Inserts the value num into the SkipList.
bool erase(int num) Removes the value num from the Skiplist and returns true. If num does not exist in the Skiplist, do nothing and return false. If there exist multiple num values, removing any one of them is fine.
Note that duplicates may exist in the Skiplist, your code needs to handle this situation.

Example 1:
Input
["Skiplist", "add", "add", "add", "search", "add", "search", "erase", "erase", "search"]
[[], [1], [2], [3], [0], [4], [1], [0], [1], [1]]
Output
[null, null, null, null, false, null, true, false, true, false]
Explanation
Skiplist skiplist = new Skiplist();
skiplist.add(1);
skiplist.add(2);
skiplist.add(3);
skiplist.search(0); // return False
skiplist.add(4);
skiplist.search(1); // return True
skiplist.erase(0);  // return False, 0 is not in skiplist.
skiplist.erase(1);  // return True
skiplist.search(1); // return False, 1 has already been erased.
*/


/// Maps Impementation

class Skiplist {
public:
    Skiplist() {
    }
    map<int,int> mp;
    bool search(int target) {
        if(mp[target]>0) return true;
    return false;
    }

    void add(int num) {
        mp[num]++;
    }

    bool erase(int num) {
        if(mp[num]>0){
            mp[num]--;
            return true;
        }
    return false;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */


 /// LinkedList Implementation

 struct Node{
    int val=INT_MIN;
    int count=-1;
    Node* left=NULL;
    Node* right=NULL;
    Node* up=NULL;
    Node* down=NULL;
    Node(){
        count=1;
    }
    Node(int value):val(value),count(1){}
};

Node* find_up_l(Node* sentinel,int value){
    Node* temp=sentinel;
    while(temp->right && temp->right->val<=value) temp=temp->right;
    return temp;
}

Node* promotion(Node*& up_l,Node*& up_r,Node*& n){
    Node* new_node=new Node(n->val);
    new_node->down=n;
    new_node->left=up_l;
    new_node->right=up_r;
    up_l->right=new_node;
    n->up=new_node;
    if(up_r) up_r->left=new_node;
    return new_node;
}

Node* skip_search(Node* top_head_s,int target,Node* &sentinel){
    Node* temp=top_head_s;
    while(true){
        if(temp->val==target) return temp;
        if(temp->right && temp->right->val<=target){
            temp=temp->right;
        }
        else{
            if(temp->down){
                sentinel=sentinel->down;
                temp=temp->down;
            }
            else return temp;
        }
    }
}

inline int rand_toss(){
    return rand()%2;
}

void print_skipy(Node* head){
    Node* sentinel=head;
    while(sentinel){
        Node* temp=sentinel;
        while(temp) {
            cout<<temp->val<<" ";
            temp=temp->right;
        }
        cout<<endl;
        sentinel=sentinel->down;
    }
}

Node* del(Node*& temp){
    Node* u=temp->up;
    Node* l=temp->left;
    Node* r=temp->right;
    temp->left=NULL;
    temp->right=NULL;
    temp->up=NULL;
    l->right=r;
    if(r) r->left=l;
    return u;
}

void reach_bottom(Node* &sentinel,Node*& temp){
    while(temp->down){
        sentinel=sentinel->down;
        temp=temp->down;
    }
}

class Skiplist {
public:
Node* top_head_sentinel=NULL;
    Skiplist() {
       srand(time(0));
       top_head_sentinel=new Node();
    }

    bool search(int target) {
        Node* sentinel=top_head_sentinel;
        Node* temp=skip_search(top_head_sentinel,target,sentinel);
        return (temp->val==target);
    }

    void add(int num) {
        Node* sentinel=top_head_sentinel;
        Node* temp=skip_search(top_head_sentinel,num,sentinel);
        if(temp->val==num){
            reach_bottom(sentinel,temp);
            while(temp){
                temp->count++;
                temp=temp->up;
                sentinel=sentinel->up;
            }
            return;
        }
        Node* new_node=new Node(num);
        new_node->left=temp;
        new_node->right=temp->right;
        if(temp->right) temp->right->left=new_node;
        temp->right=new_node;
        while(rand_toss()){
            Node* up_l;
            Node* up_r;
            Node* n;
            if(temp->up){
                up_l=temp->up;
            }
            else if(sentinel->up){
                up_l=find_up_l(sentinel->up,num);
            }
            else{
                Node* x=new Node();
                top_head_sentinel->up=x;
                x->down=top_head_sentinel;
                top_head_sentinel=x;

                up_l=top_head_sentinel;
            }
            up_r=up_l->right;
            n=new_node;
            new_node=promotion(up_l,up_r,n);
            temp=up_l;
            sentinel=sentinel->up;
        }
    }

    bool erase(int num) {
        Node* sentinel=top_head_sentinel;
        Node* temp=skip_search(top_head_sentinel,num,sentinel);
        if(temp->val!=num) return false;
        reach_bottom(sentinel,temp);
        if(temp->count>1){
            while(temp){
                temp->count--;
                temp=temp->up;
                sentinel=sentinel->up;
            }
            return true;
        }
        while(temp){
            temp=del(temp);
            if(temp) sentinel=sentinel->up;
        }
        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
