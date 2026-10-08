#include <iostream>
#include "DynamicArray.h"

int main() {
    std::cout << "=== 1. Создание и базовое заполнение массива ===" << std::endl;
    Array arr1(3);
    std::cout << "Начальный массив: ";
    arr1.PrintArray();
    std::cout << std::endl;

    arr1.setArray(0, 10);
    arr1.setArray(1, -20);
    arr1.setArray(2, 30);
    std::cout << "После заполнения: ";
    arr1.PrintArray();
    std::cout << std::endl;

    std::cout << "\n=== Проверка получения элементов (getArray) ===" << std::endl;
    std::cout << "Элемент с индексом 1: " << arr1.getArray(1) << std::endl;
    std::cout << "Попытка получить элемент с индексом 10: ";
    arr1.getArray(10);
    std::cout << std::endl;

    std::cout << "\n=== Проверка обработки ошибок в setArray ===" << std::endl;
    std::cout << "Индекс -1: ";
    arr1.setArray(-1, 50);
    std::cout << "\nИндекс 5 (больше размера): ";
    arr1.setArray(5, 50);
    std::cout << "\nЗначение 150 (больше 100): ";
    arr1.setArray(0, 150);
    std::cout << "\nЗначение -120 (меньше -100): ";
    arr1.setArray(0, -120);
    std::cout << "\nМассив не должен был измениться: ";
    arr1.PrintArray();
    std::cout << std::endl;

    std::cout << "\n=== Добавление элемента в конец (AddEndArray) ===" << std::endl;
    arr1.AddEndArray(40);
    arr1.AddEndArray(-50);
    std::cout << "После добавления 40 и -50: ";
    arr1.PrintArray();
    std::cout << "\nПопытка добавить 200 в конец: ";
    arr1.AddEndArray(200); // Ошибка диапазона
    std::cout << std::endl;

    std::cout << "\n=== Проверка конструктора копирования ===" << std::endl;
    Array arrCopy(arr1); // Создаём копию arr1
    std::cout << "Скопированный массив arrCopy: ";
    arrCopy.PrintArray();
    std::cout << std::endl;

    //Меняем элемент в копии и проверяем, что оригинал не изменился (глубокое копирование)
    arrCopy.setArray(0, 99);
    std::cout << "arrCopy после изменения 0-го элемента на 99: ";
    arrCopy.PrintArray();
    std::cout << "\nОригинальный arr1 (должен остаться прежним): ";
    arr1.PrintArray();
    std::cout << std::endl;

    std::cout << "\n=== Сложение и вычитание массивов (addArray и subArray) ===" << std::endl;
    Array arr2(3); // Создадим массив меньшего размера (из 3 элементов, а в arr1 сейчас 5)
    arr2.setArray(0, 5);
    arr2.setArray(1, 25);
    arr2.setArray(2, -10);

    std::cout << "Массив arr1 (размер 5): ";
    arr1.PrintArray();
    std::cout << "\nМассив arr2 (размер 3): ";
    arr2.PrintArray();
    std::cout << std::endl;

    arr1.addArray(arr2);
    std::cout << "arr1 + arr2 (первые 3 элемента сложатся, остальные 2 не изменятся): ";
    arr1.PrintArray();
    std::cout << std::endl;

    arr1.subArray(arr2);
    std::cout << "arr1 - arr2 (возвращаемся к исходным значениям arr1): ";
    arr1.PrintArray();
    std::cout << std::endl;

    return 0;
}