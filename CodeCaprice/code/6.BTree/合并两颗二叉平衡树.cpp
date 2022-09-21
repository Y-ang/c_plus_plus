/*
1） 按中序遍历第一棵树，并将遍历存储在一个临时数组arr1[]中。此步骤需要O(m)的时间。

2） 按中序遍历第二棵树，并将遍历存储在另一个临时数组arr2[]中。此步骤需要O(n)的时间。

3） 在步骤1和2中创建的数组是排序数组。将两个排序的数组合并为一个大小为m+n的数组。这一步需要O(m+n)时间。

4） 使用本文的方法从合并的数组构造一个平衡树。这一步需要O(m+n)时间。
*/


void inorderTraverse(TreeNode* node, vector<int> vec) {
    if (node == nullptr) return;
    inorderTraverse(node->left);
    vec.push_back(node->val);
    inorderTraverse(node->right);
}
vector<int> merge(vector<int> vec1, vector<int> vec2) {
    vector<int> vec;
    int startIndex1 = 0;
    int startIndex2 = 0;
    int index = 0;
    while (startIndex1 < vec1.size() && startIndex2 < vec2.size()) {
        if 
    }
}

TreeNode* buildTree(vector<int> vec, int left, int right) {
    if (left > right) return nullptr;
    int mid == left + ((right - left) >> 2);
    TreeNode* node = new TreeNode(vec[mid]);
    TreeNode->left = buildTree(vec, left, mid - 1);
    TreeNode->left = buildTree(vec, mid + 1, right);
    return node;
}


int main() {
    inorderTraverse(head1, vec1);
    inorderTraverse(head2, vec2);
    vec = merge(vec1, vec2);
    buildTree(vec, left, right);
}


