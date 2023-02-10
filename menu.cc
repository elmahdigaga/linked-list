#include <iostream>

#include "linked_list.h"

int main() {
    LinkedList<int> test;

    int option = 0, index = 0;
    int value = 0;
    while (true) {
        printf("1 - Insert in beginning\n");
        printf("2 - Insert in end\n");
        printf("3 - Insert in a position\n");
        printf("4 - Remove from beginning\n");
        printf("5 - Remove from end\n");
        printf("6 - Remove from a position\n");
        printf("7 - Print\n");
        /*
        printf("8 - Find the index of an element\n");
        printf("9 - Sort the array\n");
        printf("10 - Reverse the array\n");
        printf("11 - Print the array\n");
        */
        printf("0 - Quit\n\n> ");
        scanf("%d", &option);

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
        system("cls");
#else
        system("clear");
#endif

        switch (option) {
            case 0: {
                printf("Goodbye!\n");
                return 0;
            }
            case 1: {
                printf("Enter a value:\n> ");
                scanf("%d", &value);
                test.InsertBegin(value);
                break;
            }
            case 2: {
                printf("Enter a value:\n> ");
                scanf("%d", &value);
                test.InsertEnd(value);
                break;
            }
            case 3: {
                printf("Enter a value:\n> ");
                scanf("%d", &value);
                printf("Enter an index:\n> ");
                scanf("%d", &index);
                test.InsertPos(value, index);
                break;
            }
            case 4: {
                test.RemoveBegin();
                break;
            }
            case 5: {
                test.RemoveEnd();
                break;
            }
            case 6: {
                printf("Enter an index:\n> ");
                scanf("%d", &index);
                test.RemovePos(index);
                break;
            }
            case 7: {
                test.Print();
                break;
            } /*
             case 8: {
                 printf("Enter a value:\n> ");
                 scanf("%d", &value);
                 printf("Index of %d is: %d\n", value, test.find(value));
                 break;
             }
             case 9: {
                 test.sort();
                 printf("Array sorted\n");
                 break;
             }
             case 10: {
                 test.reverse();
                 printf("Array reversed\n");
                 break;
             }
             case 11: {
                 test.print();
                 printf("\n");
                 break;
             }*/

            default: {
                printf("Invalid input!\n");
                break;
            }
        }
    }

    return 0;
}