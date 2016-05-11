/*************************************************************************
	> File Name: Bitree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月01日 星期五 08时15分58秒
 ************************************************************************/
#include<iostream>
#include<deque>
#include<vector>
#include<stack>
#include"Bitree.h"

using namespace std;

template<class type>
Bitree<type>::Bitree(){
    root=nullptr;
}

template<class type>
void Bitree<type>::insert(Binode<type>* node){
    if(node==nullptr)   return;
    Binode<type> *p,*s;
    p=nullptr;
    s=root;
    while(s!=nullptr){
        p=s;
        if(node->val<=s->val)
        {
            s=s->lc;
        }
        else
        {
            s=s->rc;
        }
        
    }
    node->p=p;
    if(p==nullptr)
    {
        root=node;
    }
    else{
        if(node->val<=p->val)
        {
            p->lc=node;
        }
        else{
            p->rc=node;
        }
    }
}

/*递归
template<class type>
void Bitree<type>::preorder(Binode<type>* node){
    if(node!=nullptr){
        cout<<node->val<<' ';
        preorder(node->lc);
        preorder(node->rc);
    }  
}*/



template<class type>
void Bitree<type>::preorder(Binode<type>* node){
    if(node!=nullptr){
        stack<Binode<type>* > sta;
        auto ptr=node;
        while(!sta.empty() || ptr!=nullptr){
            if(ptr!=nullptr){
                cout<<ptr->val<<' ';
                sta.push(ptr);
                ptr=ptr->lc;
            }
            else{
                sta.pop();
                if(sta.empty())
                {
                    ptr=nullptr;
                    break;
                }
                ptr=sta.top();
                ptr=ptr->rc;
                sta.pop();
            }
        }
        cout<<endl;


    }
}

/*递归
template<class type>
void Bitree<type>::inorder(Binode<type>* node){
    if(node!=nullptr){
        inorder(node->lc);
        cout<<node->val<<' ';
        inorder(node->rc);
    }  
}*/

//迭代
template<class type>
void Bitree<type>::inorder(Binode<type>* node){
    if(node!=nullptr){
        auto ptr=node;
        stack<Binode<type>* > sta;
        while(ptr!=nullptr || !sta.empty()){
            if(ptr!=nullptr){
                sta.push(ptr);
                ptr=ptr->lc;
            }
            else{
                ptr=sta.top();
                cout<<ptr->val<<' ';
                ptr=ptr->rc;
                sta.pop();
            }
        }
    }  
}

template<class type>
void Bitree<type>::postorder(Binode<type>* node){
    if(node!=nullptr){
        postorder(node->lc);
        postorder(node->rc);
        cout<<node->val<<' ';
    }  
}

template<class type>
void Bitree<type>::levelorder(Binode<type>* node){
    if(node==nullptr) return;
    deque<Binode<type>*> queue;
    queue.push_back(node);
    int index=queue.size();
    while(!queue.empty()){
        while(index!=0){
            cout<<queue[0]->val<<' ';
            --index;
            if(queue[0]->lc!=nullptr)
               queue.push_back(queue[0]->lc);
            if(queue[0]->rc!=nullptr)
               queue.push_back(queue[0]->rc);
            queue.pop_front();
        }
        index=queue.size();
        cout<<endl;
    }   
}

template<class type>
bool Bitree<type>::search(const type& value){
    Binode<type>* ptr=root;
    while(ptr!=nullptr){
        if(ptr->val==value){
            return true;
        }
        else if(ptr->val<value)
            ptr=ptr->rc;
        else
            ptr=ptr->lc;
    }
    return false;
}

template<class type>
bool Bitree<type>::search(const type& value,Binode<type>*& p){
    Binode<type>* ptr=root;
    while(ptr!=nullptr){
        if(ptr->val==value){
            p=ptr;
            return true;
        }
        else if(ptr->val<value)
            ptr=ptr->rc;
        else
            ptr=ptr->lc;
    }
    p=nullptr;
    return false;
}

template<class type>
Binode<type>* Bitree<type>::successor(Binode<type>* node){
    if(node==nullptr) return nullptr;
    Binode<type>* ptr=node;
    if(ptr->rc!=nullptr){             //存在右子树,往下找最左边的子结点
        ptr=ptr->rc;
        while(ptr->lc!=nullptr){
            ptr=ptr->lc;
        }
        return ptr;
    }
    Binode<type>* pre=ptr->p;        //往上找第一个右边的结点 
    while(pre!=nullptr && pre->rc==ptr){
        ptr=pre;
        pre=ptr->p;
    }
    return pre;
}

template<class type>
Binode<type>* Bitree<type>::successor(const type& value){
    Binode<type>* ptr;
    search(value,ptr);
    return  successor(ptr);
}

template<class type>
Binode<type>* Bitree<type>::predecessor(Binode<type>* node){
    if(node==nullptr)   return nullptr;
    Binode<type>* ptr=node;
    if(ptr->lc!=nullptr){         //存在左子树,往下找最右边的子结点
        ptr=ptr->lc;
        while(ptr->rc!=nullptr){
           ptr=ptr->rc; 
        }
        return ptr;
    }
    Binode<type>* pre=ptr->p;     //往上找第一个左边的结点 
    while(pre!=nullptr && pre->lc==ptr){
        ptr=pre;
        pre=ptr->p;
    }
    return pre;
}

template<class type>
Binode<type>* Bitree<type>::predecessor(const type& value){
    Binode<type>* ptr;
    search(value,ptr);
    return  predecessor(ptr);
}

template<class type>
void Bitree<type>::remove(Binode<type>*& node){
    if(node==nullptr) return;
    Binode<type>* ptr=node;
    Binode<type>* parent=ptr->p;
    if(ptr->lc==nullptr && ptr->rc==nullptr){    //删除叶子结点
        if(parent!=nullptr){
            if(parent->lc==ptr)
                parent->lc=nullptr;
            else if(parent->rc==ptr)
                parent->rc=nullptr;
        }
        else
            root=nullptr;
    }
    else if(ptr->lc!=nullptr && ptr->rc!=nullptr){  //删除结点有两个儿子结点
        Binode<type>* successor_p=successor(ptr);
        if(successor_p==nullptr)    return;
        if(successor_p==ptr->rc){
            if(parent==nullptr){
                successor_p->lc=ptr->lc;
                successor_p->p=nullptr;
                root=successor_p;
            }
            else{
                if(parent->lc==ptr){
                    parent->lc=successor_p;
                    successor_p->lc=ptr->lc;
                }
                else if(parent->rc==ptr){
                    parent->rc=successor_p;
                    successor_p->lc=ptr->lc;
                }
            }
        }
        else{
            if(parent==nullptr){
                Binode<type>* succ_parent=successor_p->p;
                succ_parent->lc=successor_p->rc;
                successor_p->lc=ptr->lc;
                successor_p->rc=ptr->rc;
                successor_p->p=nullptr;
                root=successor_p;
            }
            else{
                
                Binode<type>* succ_parent=successor_p->p;
                succ_parent->lc=successor_p->rc;
                if(parent->lc==ptr){
                    parent->lc=successor_p;
                    successor_p->lc=ptr->lc;
                    successor_p->rc=ptr->rc;
                }
                else if(parent->rc==ptr){
                    parent->rc=successor_p;
                    successor_p->rc=ptr->rc;
                    successor_p->lc=ptr->lc;
                }
            }
        }
    }
    else                                                //删除结点有一个儿子结点
    {
        if(parent==nullptr){
            if(ptr->lc!=nullptr)
                root=ptr->lc;
            else
                root=ptr->rc;
        }
        else{
            if(ptr==parent->lc){
                if(ptr->lc!=nullptr)
                    parent->lc=ptr->lc;
                else
                    parent->lc=ptr->rc;
                
            } 
            else if(ptr==parent->rc){
                if(ptr->lc!=nullptr)
                    parent->rc=ptr->lc;
                else
                    parent->rc=ptr->rc;
            }
        }
    }
    delete ptr;

}

template<class type>
void Bitree<type>::remove(const type& value){
    Binode<type>* ptr;
    bool flag=search(value,ptr);
    if(!flag)   return;
    remove(ptr);
}

template<class type>
Bitree<type>::~Bitree(){
    auto ptr=root;
    auto p=ptr;
    stack<Binode<type>* > sta;
    while(!sta.empty() || ptr!=nullptr){
        if(ptr!=nullptr){
            sta.push(ptr);
            ptr=ptr->lc;
        }
        else{
            p=sta.top();
            sta.pop();
            ptr=p->rc;
            delete p;
        }
    }
}
