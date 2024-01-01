#include <stdlib.h>
#include "queue.h"

void searching_algorithms::Queue::set(int index,double value){

    searching_algorithms::Queue::Node *n = new searching_algorithms::Queue::Node(index,value);
    
    if(root == NULL){
        root = n;
        return;
    }

    bool addFlag = false,deleteFlag = false;
    Node * iter = root,*prev = NULL;
    while(iter != NULL && (!addFlag || !deleteFlag)){

        if(!addFlag && value <= iter->value){
            addFlag = true;
            n->next = iter;
            if(prev != NULL)
                prev->next = n;
            else
                root = n;
        }

        if(index == iter->index){
            deleteFlag = true;
            if(prev != NULL){
                prev->next = iter->next;
                delete iter;
            }
            else{
                Node *temp = root;
                root = root->next;
                delete temp;
            }
        }
        prev = iter;
        iter = iter->next;
    }

    if(!addFlag) prev->next = n;
}
int searching_algorithms::Queue::pop(){
    Node *temp = root;
    double index = root->index;
    root = root->next;
    delete temp;
    return index;
}
void searching_algorithms::Queue::clear(){
    Node *iter = root,*temp;
    while(iter != NULL){
        temp = iter;
        iter = iter->next;
        delete temp;
    }
    root = NULL;
}