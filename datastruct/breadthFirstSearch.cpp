class BreadthFirstSearch {
    public:
        void breadFirstSearch(BiTree* root) {
            queue<BiTree*> nodeQueue;
            nodeQueue.push(root);
            while(!nodeQueue.empty()) {
                BiTree* tmp = nodeQueue.front();
                cout << tmp->data << ' ';
                nodeQueue.pop();
                if(tmp->left) {
                    nodeQueue.push(tmp->left);
                }
                if(tmp->right) {
                    nodeQueue.push(tmp->right);
                }
            }
        }
}
