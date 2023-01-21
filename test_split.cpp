/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"


int main(int argc, char* argv[])
{

  Node* odd1=nullptr;
    Node* even1= nullptr;

    int arr[8] = {3, 4, 9, 6, 11, 12, 7, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    Node*  head = new Node(2, nullptr);
    Node* current = head;

    for(int i=0; i<n; i++){

            current->next = new Node(arr[i], nullptr);
            current = current->next;
        }


    split(head,odd1, even1);


    while(odd1 != nullptr)
    {
        std::cout << odd1->value << " ";
        odd1 = odd1->next;
    }

}
