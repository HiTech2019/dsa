/*
 * http://www.cnblogs.com/dolphin0520/archive/2011/08/25/2153720.html
 * 树的3种深度遍历:前、中、后
 * 递归和非递归
 */
class DepthFirstSearch{
    void preTravel(BiTree* root) {
        if(!root){
            return;
        }
        cout << root->data;
        preTravel(root->left);
        preTravel(root->right);
    }
    void inTravel(BiTree* root) {
        if(!root){
            return;
        }
        preTravel(root->left);
        cout << root->data << ' ';
        preTravel(root->right);
    }
    void postTravel(BiTree* root) {
        if(!root){
            return;
        }
        preTravel(root->left);
        preTravel(root->right);
        cout << root->data << ' ';
    }

    void preTravelNonRecur(BiTree* root) {
        if(root) {
            stack<BiTree*> st;
            st.push(root);
            while(!st.empty()) {
                BiTree* tmp = st.top();
                st.pop();
                cout << tmp->data << ' ';
                if(tmp->right) {
                    st.push(tmp->right);
                }
                if(tmp->left) {
                    st.push(tmp->left);
                }
            }
        }
    }

    void inTravelNonRecur(BiTree* root) {
        if(root) {
            stack<BiTree*> st;
            BiTree* cur = root;
            while(cur || !st.empty()) {    //直到P为NULL并且栈为空则遍历结束
                while(cur) {       //当前节点不为空就压入他的左子树
                    st.push(cur);
                    cur = cur->left;
                }
                if(!st.empty()) {   //压完之后不空就弹出
                    BiTree* tmp = st.top();
                    st.pop();
                    cout << tmp->data << ' ';
                    cur = tmp->right;  //准备下次循环压入右子树
                }
            }
        }
    }

    /*
     * 对于任一结点P, 先将其入栈.
     * 如果P不存在左孩子和右孩子, 则可以直接访问它
     * 或者P存在左孩子或者右孩子, 但是其左孩子和右孩子都已被访问过了, 则同样可以直接访问该结点.
     * 若非上述两种情况, 则将P的右孩子和左孩子依次入栈
     */
    void postTravelNonRecur(BiTree* root) {
        if(root) {
            stack<BiTree*> st;
            BiTree* cur;
            BiTree* pre = NULL;
            st.push(root);
            while(!st.empty()) {
                cur = st.top();
                //如果当前结点没有孩子结点或者孩子节点都已被访问过 
                if((!cur->left && !cur->right) ||
                        (pre && (pre == cur->left || pre == cur->right))) {
                    cout << cur->data << ' ';
                    st.pop();
                    pre = cur;
                } else {
                    if(cur->right) {
                        st.push(cur->right);
                    }
                    if(cur->left) {
                        st.push(cur->left);
                    }
                }
            }
        }
    }
};
