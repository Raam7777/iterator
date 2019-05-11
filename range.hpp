#pragma once
#include "iostream"

namespace itertools {

template <typename T>
class range
{

public:
  T r_begin;
  T r_end;

  range<T>(T r_begin, T r_end):r_begin(r_begin),r_end(r_end){}

  class iterator
  {
  public:
    T *iter;

    iterator(T *iter = nullptr) : iter(iter) {}

    T &operator*() const
    {
      return *iter;
    }

    iterator &operator++()
    {
      (*iter)++;
      return *this;
    }

    const iterator operator++(int)
    {
      iterator temp = *this;
      (*iter)++;
      return temp;
    }

    bool operator==(iterator it) const
    {
      return *iter == *iter.it;
    }

    bool operator!=(iterator it) const
    {
      return *iter != *iter.it;
    }



  };

iterator begin()
{
    return range<T>::iterator{&r_begin};
}

iterator end()
{
  return range<T>::iterator{&r_end};
}

};

};
