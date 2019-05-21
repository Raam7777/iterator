#pragma once

namespace itertools {

template <typename T>
class range
{

public:
  const T r1;
  const T r2;

  range(const T r1_begin, const T r2_end) : r1(r1_begin), r2(r2_end){}

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

iterator begin()const
{
    return iterator(r1);
}

iterator end()const
{
  return iterator(r2);
}

};

}
