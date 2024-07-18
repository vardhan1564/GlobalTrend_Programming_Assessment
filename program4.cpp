#include <iostream>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    string serialize(TreeNode* root) {
        return serializeHelper(root);
    }

    TreeNode* deserialize(string data) {
        queue<string> nodes;
        string node;
        stringstream ss(data);
        while (getline(ss, node, ',')) {
            nodes.push(node);
        }
        return deserializeHelper(nodes);
    }

private:

    string serializeHelper(TreeNode* root) {
        if (root == NULL) {
            return "#,";
        }
        return to_string(root->val) + "," + serializeHelper(root->left) + serializeHelper(root->right);
    }


    TreeNode* deserializeHelper(queue<string>& nodes) {
        string node = nodes.front();
        nodes.pop();
        if (node == "#") {
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(node));
        root->left = deserializeHelper(nodes);
        root->right = deserializeHelper(nodes);
        return root;
    }
};

int main() {

    Codec ser, deser;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string serializedTree = ser.serialize(root);
    cout << "Serialized Tree: " << serializedTree << endl;

    TreeNode* deserializedTree = deser.deserialize(serializedTree);
    cout << "Deserialized Tree Root: " << deserializedTree->val << endl;

    return 0;
}
