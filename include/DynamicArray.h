#pragma once

class Array{
private:
    int* data;
    int size;
public:
    Array(int size);
    ~Array();
    void PrintArray();
    void setArray(int index, int value);
    int getArray(int index);
    Array(const Array& other);
    void AddEndArray(int n);
    void addArray(const Array& other);
    void subArray(const Array& other);
};