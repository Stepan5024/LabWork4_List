#include <stdio.h>
#include <stdlib.h>
#include <iostream>

typedef int Data;
typedef struct Node Node;

struct Node {
    Data data;
    Node * next;
};


void print(Node* list);
void push(Node ** plist, Data d);
int is_empty(Node* list);
Data pop(Node** list);
Data deleteLastNode(Node** plist);
int* searchByKey(Node* list, int key);


int main()
{
    setlocale(LC_ALL, "Russian");
    system("color F0");

    Data test[] = { 21, 17, 3, 10, 3, 1, 8, 0, 6, 7, 2, 14, 17, 38, 24, 4, 3, 17, 20, 23};
    Node * list = NULL;
    //printf("Empty: %s\n", is_empty(list) ? "YES" : "NO");

    for (size_t i = 0; i < sizeof(test)/sizeof(test[0]); i++)//инициализация списка
    {
        push(&list, test[i]);
        //print(list);
    }
    
    int x = 0;
    int value = 0;
    Data d;
    do
    {
        printf("1. Включить новый элемента в начало списка\n");
        printf("2. Удалить элемент из конца списка\n");
        printf("3. Вывести список\n");
        printf("4. Удалить весь список\n");
        printf("5. Поиск элемента\n");
        printf("0. Выйти\n");
        printf("\nНомер операции > "); scanf_s("%d", &x);
        switch (x)
        {
        case 1:

            printf("Значение > "); scanf_s("%d", &value);
            push(&list, value);
            break;
        case 2:
            d = deleteLastNode(&list);
            printf("pop %d :\n", d);
            print(list);
            break;
        case 3: 
            print(list); 
            break;
        case 4: 
            //printf("Empty: %s\n", is_empty(list) ? "YES" : "NO");

            while (!is_empty(list)) {
                Data d = pop(&list);
                printf("pop %d :\n", d);
                //print(list);
            }
            printf("Empty: %s\n", is_empty(list) ? "YES" : "NO");
            printf("\nСписок удален\n");
            break;
        case 5:
            printf("Значение > "); scanf_s("%d", &value);
            int* Arr = searchByKey(list, value);
            break;
        }
    } while (x != 0);
    
    /*while (!is_empty(list)) {
        Data d = deleteLastNode(&list);
        printf("pop %d :\n", d);
        print(list);
    }*/

    printf("\n");
    return 0;
}
Data pop(Node ** plist) { // удаляет первый элемент
    
    Node* p = *plist;
    Data res = p->data;
    *plist = p->next;
    free(p);
    
    return res;
}

Data deleteLastNode(Node** plist) //7.	Удаление элемента из конца списка
{
    Node* toDelete, * secondLastNode;

        toDelete = *plist;
        secondLastNode = *plist;

        /* Traverse to the last node of the list */
        while (toDelete->next != NULL)
        {
            secondLastNode = toDelete;
            toDelete = toDelete->next;
        }

        if (toDelete == *plist)
        {
            *plist = NULL;
        }
        else
        {
            /* Disconnect link of second last node with last node */
            secondLastNode->next = NULL;
        }
        Data res = toDelete->data;
        /* Delete the last node */
        free(toDelete);
        
        
        return res;
    
}


int is_empty(Node* list) { // проверка на пустоту списка
    return list == NULL;
}
void print(Node* list) { // вывести на экран
    int index = 0;
    for (Node* p = list; p != NULL; p = p->next) {
        printf("[%d] = %d\n", index, p->data);
        index++;
    }

    printf("\n");
}
int* searchByKey(Node* list, int key) { // найти индекс элемента

    int overlap = 0;
    
    
    for (Node* p = list; p != NULL; p = p->next) {
        if (p->data == key) {
            overlap++;

        }
    }
    
    printf("\n");
    int index = -1;
    int count = 0;
    int query = 0;
    int* Arr = new int[overlap];
    for (Node* p = list; p != NULL; p = p->next) {
        if (p->data == key) {

            index = query;
            count++;
            Arr[count] = index;
            printf("Ключ %d поиска найден. Индекс равен %d\n", key, index);
        }
        query++;

    }
    if (index == -1) {
        printf("Ключ %d поиска не найден\n", key);
    }
    return Arr;
}
void push(Node** plist, Data d) { // положить элемент в начало
    Node* p = (struct Node*)malloc(sizeof(Node));
    p->data = d;
    p->next = *plist;
    *plist = p;
    
}
