#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <time.h>
//#include <algorithm>
#include <bits/stdc++.h>

using namespace std;


struct matrix {
    long User;
    long Item;
    int result;
    long UT;
};

struct node{
        node *left_chid;
        node *right_child;
        matrix data;
    };

class binary_search_tree_user{
private:
    //node *root;
public:
    node *root;
    binary_search_tree_user(){
        root = NULL;
    }
    bool check_empty() const { return root == NULL; }
    void insert(matrix);
    node *accept(node *treenode , long , long , long);

};


class binary_search_tree_item{
private:
    node *root;
public:
    binary_search_tree_item(){
        root = NULL;
    }
    bool check_empty() const { return root == NULL; }
    void insert(matrix);

};



void binary_search_tree_user::insert(matrix data){
    // user tree
    node *tree = new node;
    node *parent;
    tree->data = data;
    tree->left_chid = NULL;
    tree->right_child = NULL;
    parent = NULL;
    if(check_empty()) root = tree;
    else{
        node *temp;
        temp = root;
        while(temp){
            parent = temp;
            if(tree->data.User > temp->data.User){
                temp = temp->right_child;
            }
            else{
                temp = temp->left_chid;
            }
            if(tree->data.User < parent->data.User){
                parent->left_chid = tree;
            }
            else{
                parent->right_child = tree;
            }
        }

    }
}

node *binary_search_tree_user::accept(node *treenode , long u , long i , long t){
        if(u > treenode->data.User)
        {
                return accept(treenode->right_child , u , i , t);
        }
        else if(u < treenode->data.User)
        {
                return accept(treenode->left_chid , u , i , t);
        }
        else if(u == treenode->data.User && treenode->data.Item == i && treenode->data.UT == t)
        {
                return treenode;
        }
        else
        {
                return accept(treenode->right_child , u , i , t);
        }

}

bool cmp_by_user_by_item(const data a,const data b){
    if(a.user!=b.user) return a.user<b.user;
    if(a.item!=b.item) return a.item<b.item;


}

sort(a.begin(),a.end(),cmp_by_user_by_item());
lower_bound(a.begin(),a.end(),qwqwqw,cmp_by_user_by_item())-a.begin();

void binary_search_tree_item::insert(matrix data){
    // user tree
    node *tree = new node;
    node *parent;
    tree->data = data;
    tree->left_chid = NULL;
    tree->right_child = NULL;
    parent = NULL;
    if(check_empty()) root = tree;
    else{
        node *temp;
        temp = root;
        while(temp){
            parent = temp;
            if(tree->data.User > temp->data.User){
                temp = temp->right_child;
            }
            else{
                temp = temp->left_chid;
            }
            if(tree->data.User < parent->data.User){
                parent->left_chid = tree;
            }
            else{
                parent->right_child = tree;
            }
        }

    }
}


struct userid {
    long ut;
    int Result;
};

struct user_wrape{
    long user;
    userid info[];
};

struct item_wrape{
    long item;
    user_wrape user[];
};

struct itemid {
    item_wrape item_info;
    long accept_num;
    long recom_num;
};

/*
vector<matrix> insertion_sort (vector<matrix> data, long length){
	 	long j;
        matrix tmp;
	for (long i = 0; i < length; i++){
		j = i;

		while (j > 0 && data[j].User < data[j-1].User){
			  tmp = data[j];
			  data[j] = data[j-1];
			  data[j-1] = tmp;
			  j--;
		  }
    }
    return data;
}*/

int main(){
    vector<matrix>data;
    clock_t start , end_l;
    start = clock();
    FILE *fp;
    /*remember to change the address of relogtrain!!!!!!*/
    fp = fopen("rec_log_train.tx" , "r");


    long a = 0 , b = 0 , d = 0;
    int c = 0;

    binary_search_tree_user user_tree;
    binary_search_tree_item item_tree;
    int counter = 0;
    while(fscanf(fp , "%ld%ld%d%ld" , &a , &b , &c , &d) != EOF){


        matrix tmp;
        tmp.User = a;
        tmp.Item = b;
        tmp.result = c;
        tmp.UT = d;
        data.push_back(tmp);


        user_tree.insert(data[counter]);
        item_tree.insert(data[counter]);


        counter++;
    }
    cout<<"fuck you!!";
    int times = 0;
    cin>>times;
    string cmd = NULL;
    for(int i = 0 ; i < times ; i++){
        cin>>cmd;
        if(cmd == "accept"){
            int u = 0 , i = 0 , t = 0;
            cin>>u;
            cin>>i;
            cin>>t;
            node *result;
            result = user_tree.accept(user_tree.root , u , i , t);
            cout<<result->data.result;
        }
    }



    fclose(fp);
    end_l = clock();
    double diff = end_l - start;
    printf(" %f  ms" , diff);
    return 0;
}

