#include <iostream>

using namespace std;

void AddInList(int value, int position);
int DeleteList();
int DeleteIndexInList(int position);
void PrintList();
void InitList();
int SearchElement(int elem);
struct list* init(int a);
struct list* addelem(list* lst, int number);
struct list* deletelem(list* lst);
void listprint(list* lst);
struct list* deletehead(list* root);
int SearchElement(list* lst, int key);


struct DoubleList //описание узла списка
{
    int data; //информационное поле
    DoubleList* next; //указатель на следующий элемент
    DoubleList* prev; //указатель на предыдущий элемент
};

struct list
{
    int field; // поле данных
    struct list* next; // указатель на следующий элемент
    struct list* prev; // указатель на предыдущий элемент
};

DoubleList* head; //указатель на первый элемент списка
int Kol_Element = 0;

int main()
{
    setlocale(LC_ALL, "Russian");
    system("color F0");
    srand(time(NULL));

    cout << "Hello World!\n";

    list* head, * cur;
    int num;
    // Создаем список из 20 элементов
    cout << "a =  > "; cin >> num;
   
    head = init(num);
    cur = head;
    int max = 30;
    int min = 0;
    for (int i = 0; i < 20; i++) {
        num = rand() % (int)max + min;
        cur = addelem(cur, num);
    }
    listprint(head);

    printf("\n");
    cur = addelem(head, 55);
    listprint(head);
    printf("\n");
    // Удаляем третий элемент списка
    cur = head->next->next;
    deletelem(cur);
    listprint(head);
    printf("\n");

    /*InitList();*/

    int value, position, x;
    do
    {
        cout << "1. Добавить элемент в начало списка" << endl;
        cout << "2. Удалить элемент из конца списка" << endl;
        cout << "3. Вывести список" << endl;
        cout << "4. Удалить весь список" << endl;
        cout << "5. Поиск элемента" << endl;
        cout << "0. Выйти" << endl;
        cout << "\nНомер операции > "; cin >> x;
        switch (x)
        {
        case 1:
            cout << "Значение > "; cin >> value;
            cur = addelem(cur, value); 
            break;
        case 2:
            // Удаляем последний элемент списка
            //cur = head->next->next; // например 3-ий элемент
            
            while (cur->next != head->prev) {
                cur = head->next;
            }
            deletelem(cur);
            break;
        case 3: listprint(head); break;
        case 4: DeleteList(); break;
        case 5:
            cout << "Ключ поиска > "; cin >> position;
            SearchElement(position); break;
        }
    } while (x != 0);
}


//**********************ДОБАВЛЕНИЕ ЭЛЕМЕНТА**********************
void AddInList(int value, int position)
{
    DoubleList* node = new DoubleList; //создание нового элемента
    node->data = value; //присвоение элементу значения
    if (head == NULL) //если список пуст
    {
        node->next = node; //установка указателя next
        node->prev = node; //установка указателя prev
        head = node; //определяется голова списка
    }
    else
    {
        DoubleList* temp = head;
        int data = temp->data;
        DoubleList* temp_next = temp->next;
        DoubleList* temp_prev = temp->prev;

        
        //
        DoubleList* p = new DoubleList;
        node->next = temp_next;
        node->prev = temp->prev;
        head = node;
        for (int i = 1; i < Kol_Element; i++) p = p->next;
        p->prev->next = node;
        node->prev = p->prev;
        node->next = p;
        p->prev = node;
        /*
        DoubleList * p = head;
        for (int i = position; i > 1; i--) p = p->next;
        p->prev->next = node;
        node->prev = p->prev;
        node->next = p;
        p->prev = node;*/
    }
    Kol_Element++;
    cout << "\nЭлемент добавлен...\n\n";
}

int DeleteIndexInList(int position) //Удаление элемента по индексу
{

    if (head == NULL) { cout << "\nСписок пуст\n\n"; return 0; }
    if (head == head->next)
    {
        delete head;
        head = NULL;
    }
    else
    {
        DoubleList* a = head;
        for (int i = position; i > 1; i--) a = a->next;
        if (a == head) head = a->next;
        a->prev->next = a->next;
        a->next->prev = a->prev;
        delete a;
    }
    cout << "\nЭлемент удален...\n\n";
}


int DeleteList() { // удаление списка


    DoubleList* a = head;
    if (head == NULL) {
        cout << "\nСписок пуст\n\n"; return 0;
    }
    int i = 0;
    do
    {
        if (head == head->next)
        {
            delete head;
            head = NULL;
        }
        else
        {
            DoubleList* a = head;
            for (int i = Kol_Element; i > 1; i--) a = a->next;
            if (a == head) head = a->next;
            (*a).prev->next = a->next;
            (*a).next->prev = a->prev;
            delete a;
        }


    } while (head != NULL); cout << "\n\n";
    cout << "\nCписок удален" << endl;

}
void FillRand(int* arr, int n, int min, int max) {

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (int)max + min;
    }

}
void InitList() {
    int max = 40;
    int min = 0;
    DoubleList* node = new DoubleList; //создание нового элемента
    if (head == NULL) //если список пуст
    {
        node->data = rand() % (int)max + min;
        node->next = node; //установка указателя next
        //node->prev = NULL; //установка указателя prev
        cout << node;
        node->prev = node; //установка указателя prev
        head = node; //определяется голова списка
        Kol_Element++;
    }
    for (int i = 0; i < 20; i++) {
        DoubleList* node = new DoubleList; //создание нового элемента
        node->data = rand() % (int)max + min; //присвоение элементу значения

        DoubleList* p = head;
        for (int i = Kol_Element; i > 1; i--) p = p->next;
        p->prev->next = node;
        node->prev = p->prev;
        node->next = p;
        
        p->prev = node;

        Kol_Element++;
    }

}
int SearchElement(int key) {

    if (head == NULL) { 
        cout << "\nЭлемент не найден\n\n"; 
        return -1;
    }
    else
    {
        DoubleList* a = head;
 
        int i = 0;
        do
        {
            if (a->data == key) {
                cout << "Индекс ключа " << key << " равен " << i << endl;
                return i;

            }
            
            a = a->next;
            i++;
        } while (a != head); cout << "\n\n";
    }
    cout << "Индекс ключа " << key << " не найден"<< endl;
    return -1;
    
}

void PrintList() //Печать списка на консоль
{
    if (head == NULL) cout << "\nСписок пуст\n\n";
    else
    {
        DoubleList* a = head;
        cout << "\nЭлементы списка: " << endl;

        int i = 0;
        do
        {
            cout << "[" << i << "] " << a->data << endl;
            a = a->next;
            i++;
        } while (a != head); cout << "\n\n";
    }
}


struct list* init(int a)  // а- значение первого узла
{
    struct list* lst = new list;
    // выделение памяти под корень списка
    lst = (struct list*)malloc(sizeof(struct list));
    lst->field = a;
    lst->next = NULL; // указатель на следующий узел
    lst->prev = NULL; // указатель на предыдущий узел
    return(lst);
}
struct list* addelem(list* lst, int number)
{
    struct list* temp, * p;
    temp = (struct list*)malloc(sizeof(list));
    p = lst->next; // сохранение указателя на следующий узел
    lst->next = temp; // предыдущий узел указывает на создаваемый
    temp->field = number; // сохранение поля данных добавляемого узла
    temp->next = p; // созданный узел указывает на следующий узел
    temp->prev = lst; // созданный узел указывает на предыдущий узел
    
    return(temp);
}
struct list* deletelem(list* lst)
{
    struct list* prev, * next;
    prev = lst->prev; // узел, предшествующий lst
    next = lst->next; // узел, следующий за lst
    if (prev != NULL)
        prev->next = lst->next; // переставляем указатель
    if (next != NULL)
        next->prev = lst->prev; // переставляем указатель
    free(lst); // освобождаем память удаляемого элемента
    return(prev);
}
void listprint(list* lst)
{
    struct list* p;
    p = lst;
    int i = 0;
    do {
        cout << "[" << i << "] " << p->field << endl;
        p = p->next; // переход к следующему узлу
        i++;
    } while (p != NULL); // условие окончания обхода

   

}
int SearchElement(list* lst, int key)
{
    if (head == NULL) {
        cout << "\nЭлемент не найден\n\n";
        return -1;
    }
    struct list* p;
    p = lst;
    int i = 0;
    do {
        if (p->field == key) {
            cout << "Индекс ключа " << key << " равен " << i << endl;
            return i;
        }
        
        p = p->next; // переход к следующему узлу
        i++;
    } while (p != NULL); // условие окончания обхода

    cout << "Индекс ключа " << key << " не найден" << endl;
    return -1;

}
struct list* deletehead(list* root)
{
    struct list* temp;
    temp = root->next;
    temp->prev = NULL;
    free(root);   // освобождение памяти текущего корня
    return(temp); // новый корень списка
}