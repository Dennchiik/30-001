#include <iostream>
using namespace std;

struct Element
{
    char data;
    Element* Next;
};

class List
{
    Element* Head;
    Element* Tail;
    int Count;

public:
    List();
    ~List();
    void Add(char data);
    void Del();
    void DelAll();
    void Print();
    int GetCount();
    void PrintElement(int pos);
};

List::List()
{
    Head = Tail = NULL;
    Count = 0;
}

List::~List()
{
    DelAll();
}

void List::Add(char data)
{
    Element* temp = new Element;
    temp->data = data;
    temp->Next = nullptr;

    if (Head != nullptr)
    {
        Tail->Next = temp;
        Tail = temp;
    }
    else
    {
        Head = Tail = temp;
    }

    Count++;
}

void List::Del()
{
    if (Head != nullptr)
    {
        Element* temp = Head;
        Head = Head->Next;
        delete temp;
        Count--;
    }
}

void List::DelAll()
{
    while (Head != nullptr)
        Del();
}

void List::Print()
{
    Element* temp = Head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->Next;
    }
    cout << "\n\n";
}

int List::GetCount()
{
    return Count;
}

void List::PrintElement(int pos)
{
    if (pos < 1 || pos > Count)
    {
        cout << "Invalid position!\n";
        return;
    }

    Element* temp = Head;
    for (int i = 1; i < pos; i++)
    {
        temp = temp->Next;
    }

    cout << "Element at position " << pos << ": " << temp->data << "\n";
}

int main()
{
    List lst;
    char s[] = "Hello, World !!!";
    cout << s << "\n\n";
    int len = strlen(s);
    for (int i = 0; i < len; i++)
        lst.Add(s[i]);

    lst.Print();

    lst.PrintElement(2);
    lst.PrintElement(5);

    lst.Del();
    lst.Del();
    lst.Del();

    lst.Print();

    return 0;
}
