#include <iostream>
#include "Vector.h"
#include "List.h"

template <typename T>
void PrintContainer(IIterator<T>* iter)
{
    for (iter->Set(); !iter->IsEnd(); iter->Next())
        std::cout << iter->Current() << " ";
    std::cout << "\n";
}


int main()
{
    srand(time(nullptr));

    Vector<int> v1;
    for (int i = 0; i < 10; i++)
        v1.PushBack(rand() % 100);
    
    for (int i = 0; i < v1.Size(); i++)
        std::cout << v1[i] << " ";
    std::cout << "\n";

    VectorIterator<int> iter1 = v1.GetIterator();

    for(iter1.Set(); !iter1.IsEnd(); iter1.Next())
        std::cout << iter1.Current() << " ";
    std::cout << "\n";
    PrintContainer(&iter1);
   

    List<int> list;
    for (int i = 0; i < 10; i++)
        list.Add(rand() % 100);

    for (int i = 0; i < list.Size(); i++)
        std::cout << list.At(i) << " ";
    std::cout << "\n";

    ListIterator<int> iter2 = list.GetIterator();
    
    for (iter2.Set(); !iter2.IsEnd(); iter2.Next())
        std::cout << iter2.Current() << " ";
    std::cout << "\n";
    PrintContainer(&iter2);
}
