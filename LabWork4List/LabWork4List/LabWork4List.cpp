// ЛР 4 Выполнили студенты группы м3о-219Бк-20 Бокарев С., Катвалян А.
//

#include <iostream>

using namespace std;

void AddInList(int value, int position);
int DeleteList();
int DeleteIndexInList(int position);
void PrintList();
void InitList();

struct DoubleList //описание узла списка
{
    int data; //информационное поле
    DoubleList* next; //указатель на следующий элемент
    //DoubleList* prev; //указатель на предыдущий элемент
};
DoubleList* head; //указатель на первый элемент списка
int Kol_Element = 0;

int main()
{
    setlocale(LC_ALL, "Russian");
    system("color F0");
    srand(time(NULL));

    cout << "Hello World!\n";
    InitList();

    int value, position, x;
    do
    {
        cout << "1. Добавить элемент в конец списка" << endl;
        cout << "2. Удалить элемент в списоке по индексу" << endl;
        cout << "3. Вывести список" << endl;
        cout << "4. Удалить весь список" << endl;
        cout << "0. Выйти" << endl;
        cout << "\nНомер операции > "; cin >> x;
        switch (x)
        {
        case 1:
            cout << "Значение > "; cin >> value;
            position = Kol_Element;
            AddInList(value, position); break;
        case 2:
            cout << "Позиция > "; cin >> position;
            DeleteIndexInList(position + 1); break;
        case 3: PrintList(); break;
        case 4: DeleteList(); break;
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
        head = node; //определяется голова списка
    }
    else
    {
        cout << "kol_elem " << position << endl;
        DoubleList* p = head;
        while( p-> next != head) { p = p->next; }
         
        node->next = node;
        p->next = node;

        node->next = head;
        

        /*p->prev->next = node;
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
        /*DoubleList* p = head;
        for (int i = Kol_Element; i > 1; i--) p = p->next;
        p->next = node;

        node->next = head;*/

        DoubleList* a = head;
        for (int i = position; i > 1; i--) a = a->next;
        if (a == head) head = a->next;
        a->next = a->next;

        /*a->prev->next = a->next;
        a->next->prev = a->prev;*/
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
            a->next = a->next;
            //a->next->prev = a->prev;
            /*a->prev->next = a->next;
            a->next->prev = a->prev;*/
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
        //node->prev = node; //установка указателя prev
        head = node; //определяется голова списка
        Kol_Element++;
    }
    for (int i = 0; i < 20; i++) {
        DoubleList* node = new DoubleList; //создание нового элемента
        node->data = rand() % (int)max + min; //присвоение элементу значения

        DoubleList* p = head;
        for (int i = Kol_Element; i > 1; i--) p = p->next;
        p->next = node;

        node->next = head;

        /*p->prev->next = node;
        node->prev = p->prev;
        node->next = p;
        p->prev = node;*/

        Kol_Element++;
    }
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