//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


Node *newNode(int data);

int search(int arr[], int strt, int end, int value);


Node *buildTreeUtil(int in[], int post[], int inStrt, int inEnd, int *index) 
{
    
    if (inStrt > inEnd) return NULL;

    
    Node *tNode = new Node(post[*index]);
    (*index)--;

  
    if (inStrt == inEnd) 
    return tNode;


    int inIndex = search(in, inStrt, inEnd, tNode->data);

    
    tNode->right = buildTreeUtil(in, post, inIndex + 1, inEnd, index);
    tNode->left = buildTreeUtil(in, post, inStrt, inIndex - 1, index);

    return tNode;
}


int search(int arr[], int strt, int end, int value) 
{
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value) return i;
    }
}

//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n)
{
    int index = n - 1;
    return buildTreeUtil(in, post, 0, n - 1, &index);
}