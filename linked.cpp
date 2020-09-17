#include <iostream>
#include  <algorithm>

struct listNode{
    int val;
    listNode *next;
    listNode(): val(0), next(nullptr){}
    listNode(int v): val(v), next(nullptr){}
};

int main(){
    listNode *root = new listNode(1);
    for (int i = 2; i<7; i++){
        listNode *h = new listNode(i);
        h->next = root;
        std::cout << root << "  " << h << "\n";
        root = h;
        std::cout << root << "  " << h << "\n \n";
    }
    /*
    listNode a = listNode(1);
    listNode *root = &a, *node = &a;
    for (int i=2; i<6; i++){
        node->next = new listNode(i);
        node = node->next;
    }
    */
    for (int i = 0; i < 6; i++){
        std::cout << root->val << "\n";
        root = root->next;
    }
}
