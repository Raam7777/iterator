
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

namespace itertools {

template <typename E>
class powerset
{

public:
  E power;


  powerset(const E _power) : power(_power){}

  template<typename T>
  class iterator
  {
  public:
    const T iter_begin;
    const T iter_end;
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

    auto operator*() const
    {
      T iter = iter_begin;
      std::vector<typename std::remove_const<typename std::remove_reference<decltype(*iter_begin)>::type>::type> S;

      unsigned int i = index;
      while (i != 0 && iter != iter_end)
      {
        unsigned int r = i % 2;
        i = i >> 1;
        if (r == 1)
          S.emplace_back(*iter);
        ++iter;
      }
      return S;
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

auto begin()const
{
  return powerset::iterator<decltype(power.begin())>(power.begin(), power.end());
}

auto end()const
{
  return powerset::iterator<decltype(power.begin())>(power.end(), power.end());
}

};

template <typename E>
ostream &operator<<(ostream &os, const vector<E> &vec)
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

}
