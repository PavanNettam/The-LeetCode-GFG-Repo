//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void preorder(Node* root, unordered_map<Node*,Node*> &m, Node* &req,int target){
        if(root == NULL) return;
        if(root->data == target) req = root;
        if(root->left != NULL) m[root->left] = root;
        if(root->right != NULL) m[root->right] = root;
        preorder(root->left,m,req,target);
        preorder(root->right,m,req,target);
    }
    void dfs(Node* root, int &ans, set<Node*> &vis, int dist, unordered_map<Node*,Node*> &m){
        if(root == NULL) return;
        ans = max(ans,dist);
        vis.insert(root);
        //cout<<ans<<" "<<dist<<" "<<root->data<<endl;
        if(vis.find(m[root]) == vis.end()) dfs(m[root],ans,vis,dist+1,m);
        if(vis.find(root->left) == vis.end()) dfs(root->left,ans,vis,dist+1,m);
        if(vis.find(root->right) == vis.end()) dfs(root->right,ans,vis,dist+1,m);
    }
    int minTime(Node* root, int target) 
    {
        Node* req;
        unordered_map<Node*,Node*> m;
        preorder(root,m,req,target);
        m[root] = NULL;
        
        set<Node*> vis;
        int ans = 0;
        dfs(req,ans,vis,0,m);
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends