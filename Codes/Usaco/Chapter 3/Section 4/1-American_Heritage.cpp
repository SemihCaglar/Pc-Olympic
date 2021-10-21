#include<semih/competitive.h>

class Node{
    public:

    char val;
    Node *left,*right;

    Node(){
        this->left=NULL;
        this->right=NULL;
    }
    ~Node(){
        delete this->left;
        delete this->right;
    }

    Node* insert(char value){
        if(this->left==NULL){
            this->left=new Node();
            this->left->val=value;
            return this->left;
        }
        else if(this->right==NULL){
            this->right=new Node();
            this->right->val=value;
            return this->right;
        }
        return this;
    }

    void PostOrder(){
        if(this->left!=NULL)
            this->left->PostOrder();
        if(this->right!=NULL)
            this->right->PostOrder();
        cout<<this->val;
    }
    
};

string in,pre;
Node *root,*cur;
map<char,Node*> mp;

int main(){
    fast;
    // test("heritage");

    cin>>in>>pre;
    root=new Node();
    root->val=pre[0];
    mp[pre[0]]=root;
    cur=root;

    int ind1=0,ind2=1;

    for(;ind1<in.length();ind1++){
        if(mp.count(in[ind1])){
            cur=mp[in[ind1]];
            continue;
        }
        for(;ind2<pre.length() and pre[ind2]!=in[ind1];ind2++){
            cur=cur->insert(pre[ind2]);
            mp[pre[ind2]]=cur;
        }
        cur=cur->insert(in[ind1]);
        ind2++;
    }
    root->PostOrder();
    cout<<"\n";

    delete root;

    return 0;
}