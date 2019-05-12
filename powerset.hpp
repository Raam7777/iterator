#pragma once
#include "range.hpp"

namespace itertools
{
  template<typename T1, typename T2>

  class powerset
  {
  public:
    T1 ps_begin;
    T2 ps_end;



    powerset<T1,T2>(T1 ps_begin, T2 ps_end){}

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
      return powerset<T1,T2>::iterator{&ps_begin};
  }

  iterator end()
  {
    return powerset<T1,T2>::iterator{&ps_end};
  }
  };
};
