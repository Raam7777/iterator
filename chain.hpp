#pragma once
#include "range.hpp"

namespace itertools
{
  template<template T1, template T2>

  class chain
  {
  public:
    T1 ch_begin;
    T2 ch_end;



    chain<T1,T2>(T1 ch1, T2 ch2):ch_begin(ch_begin),ch_end(ch_end){}

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
      return chain<T1,T2>::iterator{&ch_begin};
  }

  iterator end()
  {
    return chain<T1,T2>::iterator{&ch_end};
  }
  };
};
