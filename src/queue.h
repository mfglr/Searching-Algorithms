#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>
namespace searching_algorithms{
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
            void set(int index,double value);
            int pop();
            void clear();
            bool empty(){ return root == NULL; }
    };
}
#endif