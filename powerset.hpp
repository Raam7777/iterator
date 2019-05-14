#pragma once
#include <utility>
#include <cmath>
#include <vector>
#include "iostream"
using namespace std;

namespace itertools {

template <typename E>
class powerset
{

public:
  E power;


  powerset<E>(E _power) : power(_power){}

  powerset<E> _powerset(E _power)
  {
    return powerset<E>(_power);
  }

  template<typename T>
  class iterator
  {
  public:
    T iter_begin;
    T iter_end;
    uint index;
    uint num;

    iterator(T it_begin, T it_end) : iter_begin(it_begin), iter_end(it_end), index(0), num(0)
    {
      for(T iter = iter_begin; iter!=iter_end; ++iter)
      {
        ++num;
      }
      num = pow(2,num);
    }

    vector<decltype(*iter_begin)> operator*() const
    {
      vector<decltype(*iter_begin)> vec;
      uint i = index;
      for(T iter = iter_begin; iter!=iter_end && i!=0; ++iter){
        uint r = i%2;
        i = i >> 1;

        if(r==1){
          vec.push_back(*iter);
        }
      }
      return vec;
    }

    powerset::iterator<T> &operator++()
    {
      ++index;
      return *this;
    }

    bool operator!=(powerset::iterator<T> const &it)
    {
      return ((num - index) != (it.num - it.index - 1));
    }

  };

auto begin()
{
  return iterator<decltype(power.begin())>(power.begin(), power.end());
}

auto end()
{
  return iterator<decltype(power.begin())>(power.end(), power.end());
}

};

template <typename U>
ostream &operator<<(ostream &os, const vector<U> &vec)
{
  os << "{";

  auto it = vec.begin();
  if(it != vec.end())
  {
    os << *it;
    ++it;
  }
  while(it != vec.end())
  {
    os << "," << *it;
    ++it;
  }
  os << "}";

  return os;
}

};
