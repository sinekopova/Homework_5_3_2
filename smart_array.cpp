#pragma once

#include <iostream>
#include "smart_array.h"

smart_array::smart_array(int size) {
    _ptr = new int[size];
    _size = size;
    init_array(_last);
}

smart_array::~smart_array() {
    delete[] _ptr;
}

void smart_array::add_element(int val) {
    if ((_size == _last + 1) && _size != 0) {
        _size *= 2;
        int* new_ptr = new int[_size];
        for (int i = 0; i < _size / 2; i++)
            new_ptr[i] = _ptr[i];

        _ptr = std::move(new_ptr);
        init_array(_last);
    }
    _ptr[_last + 1] = val;
    _last++;
}

int smart_array::get_element(int idx) {
    return _ptr[idx];
}

smart_array::smart_array(const smart_array& src): smart_array( src._size) {
    for (int i = 0; i < _size; i++)
        _ptr[i] = src._ptr[i];
    _last = src._last;
}

smart_array& smart_array::operator=(const smart_array& rhs)
{
    if (this != &rhs) {
        smart_array tmp(rhs);
        swap(tmp);
    }
    return *this;
}

void smart_array::swap( smart_array& src) {
    this->_size = src._size;
    this->_last = src._last;
    auto tmp_ptr = this->_ptr;
    this->_ptr = src._ptr;
    src._ptr = tmp_ptr;
}

void smart_array::init_array(int from) {
    for (int i = from + 1; i < _size; i++)
        _ptr[i] = 0;
}

void smart_array::print() {
    std::cout << "Content: ";
    for (int i = 0; i <= _last; i++)
        std::cout << _ptr[i] << " ";
    std::cout << "\n";
}