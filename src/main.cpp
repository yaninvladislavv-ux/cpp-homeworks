#include <iostream>
#include "DynamicArray.h"
#include <stdexcept>
#include <new>

int main() {
    Array arr1(3);
    try {
        std::cout << "Попытка getArray(10): ";
        arr1.getArray(10);
    } catch (const std::out_of_range& e) {
        std::cout << "Перехвачен out_of_range. " << e.what() << "\n";
    }
    try {
        std::cout << "Попытка setArray(0, 150): ";
        arr1.setArray(0, 150);
    } catch (const std::invalid_argument& e) {
        std::cout << "Перехвачен invalid_argument. " << e.what() << "\n";
    }
    try {
        std::cout << "Попытка выделить 10^12 элементов: ";
        Array hugeArr(-1);
    } catch (const std::bad_alloc& e) {
        std::cout << "Перехвачен bad_alloc. " << e.what() << "\n";
    }

    std::cout << "\nВсе исключения отработали корректно.\n";
    return 0;
}