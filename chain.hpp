

namespace itertools {

template <typename E1, typename E2>
class _chain
{

public:
  const E1& ch1;
  const E2& ch2;

  _chain(const E1& ch1_begin, const E2& ch2_end) : ch1(ch1_begin), ch2(ch2_end){}

  template<typename T1, typename T2>
  class iterator
  {
  public:
    T1 iter1;
    T2 iter2;
    bool it_bool;

    iterator(T1 it1, T2 it2) : iter1(it1), iter2(it2), it_bool(true) {}

    decltype(*iter1) operator*() const
    {
      if(it_bool)
        return *iter1;
      else
        return *iter2;
    }

    _chain::iterator<T1,T2> &operator++()
    {
      if(it_bool)
        ++iter1;
      else
        ++iter2;
      return *this;
    }

    bool operator!=(_chain::iterator<T1,T2> const &it)
    {
      if(it_bool && !(iter1 != it.iter1))
        it_bool=false;

      if(it_bool)
        return iter1 != it.iter1;
      else
        return iter2 != it.iter2;
    }



  };

auto begin()const
{
  return _chain::iterator<decltype(ch1.begin()), decltype(ch2.begin())>(ch1.begin(), ch2.begin());
}

auto end()const
{
  return _chain::iterator<decltype(ch1.end()), decltype(ch2.end())>(ch1.end(), ch2.end());
}

};
template <typename E1, typename E2>
_chain<E1,E2> chain(const E1& ran1, const E2& ran2)
{
    return _chain<E1,E2>(ran1, ran2);
}
}
