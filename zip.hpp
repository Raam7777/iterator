#pragma once
#include "range.hpp"

namespace itertools
{
  template<template T1, template T2>

  class zip
  {
  public:
    T1 z_begin;
    T2 z_end;



    zip<T1,T2>(T1 z_begin, T2 z_end){}

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
        return *iter == *iter.it;
      }

      bool operator!=(iterator it) const
      {
        return *iter != *iter.it;
      }



    };

  iterator begin()
  {
      return zip<T1,T2>::iterator{&z_begin};
  }

  iterator end()
  {
    return zip<T1,T2>::iterator{&z_end};
  }
  };
};
