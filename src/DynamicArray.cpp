#include <iostream>
#include "DynamicArray.h"
#include <stdexcept>

Array::Array(int size){
    this->size = size;
    data = new int[this->size];
    for(int i = 0; i < size; i++){
        data[i] = 0;
    }
}
Array::~Array(){
    delete[] data;
}

void Array::PrintArray(){
    for(int i = 0; i < size; i++){
        std::cout << data[i] <<  " ";
    }
}

void Array::setArray(int index, int value){
    if(index<0 || index >=size){
        throw std::out_of_range("Выход за границы массива");
    }
    if(value < -100 || value > 100){
        throw std::invalid_argument("Выход за диапазон");
    }
    data[index] = value;
}

int Array::getArray(int index){
    if(index < 0 || index >= size){
        throw std::out_of_range("Выход за границы массива");
    }
    return data[index];
}

//конструктор копирования
Array::Array(const Array& other){
    size = other.size;
    data = new int[size];
    for(int i = 0; i < size; i++){
        data[i] = other.data[i];
    }
}
//функция добавления значения в конец массива
void Array::AddEndArray(int n){
    if(n < -100 || n > 100){
        throw std::invalid_argument("Выход за диапазон");
    }
    else{
        int* NewData = new int[size + 1];
        for(int i = 0 ; i < size;i++){
            NewData[i] = data[i];
        }
        NewData[size] = n;
        delete[] data;
        data = NewData;
        size++;
    }
}

//сложение и вычитание
void Array::addArray(const Array& other){
    if(size != other.size){
        throw std::out_of_range("Размеры массивов не совпадают");
    }
    for(int i = 0; i < size; i++){
            data[i] = data[i] + other.data[i];
    }
}

void Array::subArray(const Array& other){
    if(size != other.size){
        throw std::out_of_range("Размеры массивов не совпадают");
    }
    for(int i = 0; i < size; i++){
            data[i] = data[i] - other.data[i];
    }
}