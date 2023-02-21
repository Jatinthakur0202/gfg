//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */


    bool isBalancedRec(Node *root, int* height)
{
  int lh = 0, rh = 0;
  int l = 0, r = 0;

  //if root is null, we return true.
  if(root == NULL)
  {
    *height = 0;
     return 1;
  }

  //calling the function isBalancedRec recursively for the heights of left and
  //right subtrees and storing the returned values in l and r.
  l = isBalancedRec(root->left, &lh);
  r = isBalancedRec(root->right,&rh);

  //height of current node is (max of heights of left and right subtrees) +1.
  *height = (lh > rh? lh: rh) + 1;

  //if difference between heights of left and right subtrees is 2 or more 
  //than 2 then this node is not balanced so we return false.
  if((lh - rh >= 2) || (rh - lh >= 2))
    return 0;

  //if this node is balanced and left and right subtrees are balanced 
  //then we return true.
  else 
  return l&&r;
}

//Function to check whether a binary tree is balanced or not.
class Solution{
public:
bool isBalanced(Node *root)
{
   int h = 0;
   return isBalancedRec(root, &h);
}
};


//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.isBalanced(root) << endl;
    }
    return 0;
}

// } Driver Code Ends