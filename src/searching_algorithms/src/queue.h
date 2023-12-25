#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>
#include <stdio.h>

class Queue{
    private :
        
        class Node{
            public :
                int index;
                double value;
                Node *next;
            
                Node(int index,double value){
                    this->index = index;
                    this->value = value;
                    next = NULL;
                }
        };

        Node *root = NULL;

    public :

        void upsert(int index,double value){
            
            Node *n = new Node(index,value);
            
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
       
        int pop(){
            Node *temp = root;
            double index = root->index;
            root = root->next;
            delete temp;
            return index;
        }
        bool empty(){
            return root == NULL;
        }

        void write(){
            printf("%s\n","****************");
            Node *iter = root;
            while(iter != NULL){
                printf("value : %f - index : %d\n",iter->value,iter->index);
                iter = iter->next;
            }
            printf("%s\n","****************");
        }
};

#endif