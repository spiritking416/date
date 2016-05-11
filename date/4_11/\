/*************************************************************************
	> File Name: wy.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月09日 星期六 19时55分38秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include"Bitree.cpp"

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Tree {
public:
    int getDis(TreeNode* root) {
        TreeNode* ptr_max;
        TreeNode* ptr_min;
        vector<TreeNode*> best_max;
        vector<TreeNode*> best_min;
        vector<TreeNode*> vec_max;
        vector<TreeNode*> vec_min;
        findmin(root,ptr_min,vec_min,best_min);
        findmax(root,ptr_max,vec_max,best_max);
        int n=best_max.size()-1;
        int m=best_min.size()-1;
        for( int i=n;i>=0;--i){
            auto p=best_max[i];
            for( int j=m;j>=0;--j){
                if(p==best_min[j]){
                    return (m+n-i-j);
                }
            }
        }
        return 0;
        
    }
    
    void findmax(TreeNode*& root,TreeNode*& ptr,vector<TreeNode*>& vec,vector<TreeNode*>& best){
        if(ptr==nullptr)	return;
        vec.push_back(root);
        if(ptr->val<root->val){
            ptr=root;
            best.clear();
       		copy(vec.begin(),vec.end(),best.begin());
        }
        findmax(root->left,ptr,vec,best);
        findmax(root->right,ptr,vec,best);
        vec.pop_back();
    }
    
    void findmin(TreeNode*& root,TreeNode*& ptr,vector<TreeNode*>& vec,vector<TreeNode*>& best){
        if(ptr==nullptr)	return;
        vec.push_back(root);
        if(ptr->val>root->val){
            ptr=root;
            best.clear();
       		copy(vec.begin(),vec.end(),best.begin());
        }
        findmin(root->left,ptr,vec,best);
        findmin(root->right,ptr,vec,best);
        vec.pop_back();
    }
};


int main(){

}
