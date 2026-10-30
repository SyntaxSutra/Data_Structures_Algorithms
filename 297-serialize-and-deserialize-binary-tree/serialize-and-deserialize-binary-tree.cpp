class Codec {
private:
    void serializeDFS(TreeNode* node, string& out)
    {
        if (!node)
        {
            out += "#,";
            return;
        }

        out += to_string(node->val) + ",";

        serializeDFS(node->left, out);
        serializeDFS(node->right, out);
    }

    TreeNode* deserializeDFS(stringstream& ss)
    {
        string token;

        if (!getline(ss, token, ','))
        {
            return nullptr;
        }

        if (token == "#")
        {
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(token));

        node->left = deserializeDFS(ss);
        node->right = deserializeDFS(ss);

        return node;
    }

public:
    string serialize(TreeNode* root) {
        string out;
        serializeDFS(root, out);
        return out;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeDFS(ss);
    }
};