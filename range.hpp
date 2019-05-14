#pragma once
#include "iostream"

namespace itertools {

template <typename T>
class range
{

public:
  T r1;
  T r2;

  range<T>(T r1_begin, T r2_end) : r1(r1_begin), r2(r2_end){}

  range<T> _range(T r1_begin, T r2_end)
  {
    return range<T>(r1_begin, r2_end);
  }

  class iterator
  {
  public:
    T iter;

    iterator(T it) : iter(it) {}

    T operator*() const
    {
      return iter;
    }

    range::iterator &operator++()
    {
      ++iter;
      return *this;
    }

    bool operator!=(range::iterator const &it) const
    {
      return iter != it.iter;
    }



  };

range<T>::iterator begin()
{
    return range<T>::iterator(r1);
}

range<T>::iterator end()
{
  return range<T>::iterator(r2);
}

};

};
