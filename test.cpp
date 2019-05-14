#include <iostream>
#include <sstream>
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
#include "badkan.hpp"

using namespace itertools;
using namespace std;

int main()
{
  badkan::TestCase testcase;
  int grade = 0;
  int signal = setjmp(badkan::longjmp_buffer);

  if(signal == 0)
  {
    ostringstream range_int, range_double, range_char1, range_char2;
    for(int i : range<int>(2,6))
    {
      range_int << i;
    }
    for(double d : range<double>(0.5,3.5))
    {
      range_double << d << " ";
    }
    for(char c : range<char>('C','F'))
    {
      range_char1 << c << " ";
    }
    for(char c : range<char>('a','e'))
    {
      range_char2 << c << " ";
    }

    testcase.setname("test range")
    .CHECK_OUTPUT(range_int.str(), "2345")
    .CHECK_OUTPUT(range_double.str(), "0.5 1.5 2.5 ")
    .CHECK_OUTPUT(range_char1.str(), "C D E ")
    .CHECK_OUTPUT(range_char2.str(), "a b c d ");

    grade = testcase.grade();
  }
  else
  {
    testcase.print_signal(signal);
    grade = 0;
  }
  cout << "Your grade is: " << grade << endl;
  return 0;
}
