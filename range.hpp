#pragma once

namespace itertools {

template <typename T>
class range
{

public:
  T r1;
  T r2;

  range(const T r1_begin, const T r2_end) : r1(r1_begin), r2(r2_end){}
  range(const range& other) : r1(other.r1), r2(other.r2){}


  class iterator
  {
  public:
    T iter;

    iterator(T it) : iter(it) {}

    iterator(const iterator& other) : iter(other.iter) {}

    const T operator*() const
    {
      return iter;
    }

    iterator &operator++()
    {
      ++iter;
      return *this;
    }

    bool operator!=(range::iterator const &it) const
    {
      return iter != it.iter;
    }



  };

iterator begin()const
{
    return range::iterator(r1);
}

iterator end()const
{
  return range::iterator(r2);
}

};

}
