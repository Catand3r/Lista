#include "List.h"
#include <iostream>

int main()
{
    List<int> list;
    bool isListEmpty = list.isEmpty();
    list.push_back(5);
    list.push_back(20);
    int first = list.first();
    int last = list.last();
    std::cout << first << " " << last << " " << isListEmpty << "\n";
}
