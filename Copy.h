#ifndef COPYING_COPY_H
#define COPYING_COPY_H

#include <typeinfo>
#include <iostream>

template <typename T, size_t size>
struct _copy {
    T array[size];
};

template <typename T, size_t size>
void copy(T* destination, T* source)
{
    *(_copy<T, size>*)destination = *(_copy<T, size>*)source;
}


#endif
