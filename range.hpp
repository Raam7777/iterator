#pragma once
#include "iostream"

namespace itertools {

template <typename T>
class range
{

public:
  T r1;
  T r2;

  range(T r1_begin, T r2_end) : r1(r1_begin), r2(r2_end){}

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

iterator begin()
{
    return iterator(r1);
}

iterator end()
{
  return iterator(r2);
}

};

};
