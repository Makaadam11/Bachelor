#include <cstdio>
#include <cstdlib>
#include<iostream>
#include <unistd.h>
#include "AVLTree.hpp"


 int main()
  {
        
        AVLTree AVLT, AVLT2;

        int x;
        srand(time(NULL));

        std::cout << "--------------AVLTree-------------";
        for (int i = 0; i < AVLT.getMaxsize(25) - 6; i++) {

            x = rand() % 100;

            if (i == 5)
            {
                AVLT.insert(20, AVLT.getRoot());
            }
            if (i == 14)
            {
                AVLT.insert(30, AVLT.getRoot());
            }
            else 
                AVLT.insert(x, AVLT.getRoot());
            
             
        }

        std::cout << "\n printTreeInOrder: ";
        AVLT.printTreeInOrder(AVLT.getRoot());

        std::cout << "\n";
        std::cout << " findMin: " << AVLT.findMin() << " findMax: " << AVLT.findMax() << ' ' << " findMin*: " << AVLT.findMin1(AVLT.getRoot()) << " findMax*: " << AVLT.findMax1(AVLT.getRoot())
            << ' ' << " isEmpty: " << AVLT.isEmpty() << ' ' << " size: " << AVLT.size() << " contains: " << AVLT.contains(20) << " contains: " << AVLT.contains1(20, AVLT.getRoot()->left->left)
            << ' ' << " isFull: " << AVLT.isFull() << ' ' << std::endl;


        std::cout << "\n remove 20: ";
        AVLT.remove(20);
        std::cout << "\n remove subtree 30: ";
        AVLT.remove1(30, AVLT.getRoot()->right->right);
        std::cout << "\n printTreePreOrder: ";
        AVLT.printTreePreOrder(AVLT.getRoot());

        AVLT2 = AVLT;

        std::cout << "\n printTreePostOrder: ";
        AVLT.printTreePostOrder(AVLT.getRoot());
        std::cout << "\n printTreePostOrder AVLT2: ";
        AVLT.printTreePostOrder(AVLT2.getRoot());
        std::cout << "\ndominant operations AVLTree: ";
        AVLT.print_dominant_operations();

        std::cout << "\n";
        std::cout << "END";
        return 0;
}


