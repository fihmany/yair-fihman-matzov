//
// Created by Yair on 11-Sep-17.
//

#ifndef ARRAY_SAFEARRAY_H
#define ARRAY_SAFEARRAY_H

#include <cstddef>
#include <exception>
#include "Out_Of_Range_Exception.h"
#include <ostream>

template <class T>
class SafeArray {
public:
    /// Ctor of the SafeArray class
    /// \param size - the size of the array
    explicit SafeArray(const size_t &size);
    ///
    /// \param index the needed index
    /// \return refernce to the requested element
    T& operator[] (size_t index);
    ///
    /// \param
    /// \return the next cell of the array
    T& operator++ (int index);
    T& operator-- (int index);


    ~SafeArray();
private:
    size_t m_current_indexing;
    T* arr;
    size_t m_size;

};

template <class T>
SafeArray<T>::SafeArray(const size_t &size) : arr(new T[size]), m_size(size), m_current_indexing(0) {
}

template <class T>
T& SafeArray<T>::operator[](size_t index) {
    if (index >= 0 && index < m_size)
    {
        return arr[index + m_current_indexing];
    }
    else
    {
        throw Out_Of_Range_Exception();
    }
}

template <class T>
SafeArray<T>::~SafeArray() {
    delete [] arr;
}

template <class T>
T &SafeArray<T>::operator++(int index) {
    if ((m_current_indexing + 1) < m_size)
    {
        m_current_indexing++;
    }
    return this;
}

template <class T>
T &SafeArray<T>::operator--(int index) {
    if ((m_current_indexing - 1) <= 0)
    {
        m_current_indexing--;
    }
    return this;
}


#endif //ARRAY_SAFEARRAY_H
