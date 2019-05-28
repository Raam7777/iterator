#pragma once
#include <utility>
#include <iostream>

using namespace std;

namespace itertools {

template <typename E1, typename E2>
class zip
{

public:
  const E1& z1;
  const E2& z2;

  zip(const E1& z1_begin, const E2& z2_end) : z1(z1_begin), z2(z2_end){}

  template<typename T1, typename T2>
  class iterator
  {
  public:
    T1 iter1;
    T2 iter2;

    iterator(T1 it1, T2 it2) : iter1(it1), iter2(it2) {}

    pair<decltype(*iter1),decltype(*iter2)> operator*() const
    {
      return pair<decltype(*iter1),decltype(*iter2)>(*iter1,*iter2);
    }

    zip::iterator<T1,T2> &operator++()
    {
      ++iter1;
      ++iter2;
      return *this;
    }

    bool operator!=(zip::iterator<T1,T2> const &it)
    {
        return ((iter1 != it.iter1) && (iter2 != it.iter2));
    }



  };

auto begin()const
{
  return zip::iterator<decltype(z1.begin()), decltype(z2.begin())>(z1.begin(), z2.begin());
}

auto end()const
{
  return zip::iterator<decltype(z1.end()), decltype(z2.end())>(z1.end(), z2.end());
}

};

template <typename E1, typename E2>
ostream &operator<<(ostream &os, const pair<E1,E2> &p)
{
  os << p.first << ',' << p.second;
  return os;
}

};
