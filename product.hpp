
#include <utility>
using namespace std;

namespace itertools {

template <typename E1, typename E2>
class product
{

public:
  const E1& pro1;
  const E2& pro2;

  product(const E1& pro1_begin, const E2& pro2_end) : pro1(pro1_begin), pro2(pro2_end){}

  template<typename T1, typename T2>
  class iterator
  {
  public:
    T1 iter1;
    T2 iter2;
    T2 iter2_other;
    bool iter_test = true;

    iterator(T1 it1, T2 it2) : iter1(it1), iter2(it2), iter2_other(it2) {}

    pair<decltype(*iter1),decltype(*iter2)> operator*() const
    {
      return pair<decltype(*iter1),decltype(*iter2)>(*iter1,*iter2);
    }

    product::iterator<T1,T2> &operator++()
    {
      ++iter2;
      return *this;
    }

    bool operator!=(product::iterator<T1,T2> const &it)
    {
      if(iter_test){
        if(!(iter2 != it.iter2)){
          return false;
        }
        iter_test=false;
      }
      if((iter1 != it.iter1) && !(iter2 != it.iter2))
      {
        iter2 = iter2_other;
        ++iter1;
      }
      return (iter1 != it.iter1);
    }



  };

auto begin()const
{
  return product::iterator<decltype(pro1.begin()), decltype(pro2.begin())>(pro1.begin(), pro2.begin());
}

auto end()const
{
  return product::iterator<decltype(pro1.end()), decltype(pro2.end())>(pro1.end(), pro2.end());
}

};

}
