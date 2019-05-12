#pragma once
#include "range.hpp"

namespace itertools
{
  template<typename T1, typename T2>

  class product
  {
  public:
    T1 pro_begin;
    T2 pro_end;



    product<T1,T2>(T1 pro_begin, T2 pro_end){}

    class iterator
    {
    public:
      T1 *iter;

      iterator(T1 *iter = nullptr) : iter(iter) {}

      T1 &operator*() const
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
        return *iter == *it.iter;
      }

      bool operator!=(iterator it) const
      {
        return *iter != *it.iter;
      }



    };

  iterator begin()
  {
      return product<T1,T2>::iterator{&pro_begin};
  }

  iterator end()
  {
    return product<T1,T2>::iterator{&pro_end};
  }
  };
};
