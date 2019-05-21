
namespace itertools {

template <typename T>
class _range
{

public:
  const T r1;
  const T r2;

  _range(const T r1_begin, const T r2_end) : r1(r1_begin), r2(r2_end){}

  class iterator
  {
  public:
    T iter;

    iterator(T it) : iter(it) {}

    T operator*() const
    {
      return iter;
    }

    _range::iterator &operator++()
    {
      ++iter;
      return *this;
    }

    bool operator!=(_range::iterator const &it) const
    {
      return iter != it.iter;
    }



  };

_range::iterator begin()const
{
    return _range::iterator(r1);
}

_range::iterator end()const
{
  return _range::iterator(r2);
}

};
template <typename T>
_range<T> range(const T& ran1, const T& ran2)
{
    return _range<T>(ran1, ran2);
}
}
