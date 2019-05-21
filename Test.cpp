#include <iostream>
#include <sstream>
#include <string>
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

    //***********************************TEST RANGE***************************************//


    ostringstream range_int, range_double, range_char1, range_char2, R_string_char;

    for(int i : range(2,6))
    {
      range_int << i;
    }
    for(double d : range(0.5,3.5))
    {
      range_double << d << " ";
    }
    for(char c : range('C','F'))
    {
      range_char1 << c << " ";
    }
    for(char c : range('a','e'))
    {
      range_char2 << c << " ";
    }
    for(char c : string("HeLLoWoRlD"))
    {
      R_string_char << c << " ";
    }

    testcase.setname("test range")
    .CHECK_OUTPUT(range_int.str(), "2345")
    .CHECK_OUTPUT(range_double.str(), "0.5 1.5 2.5 ")
    .CHECK_OUTPUT(range_char1.str(), "C D E ")
    .CHECK_OUTPUT(range_char2.str(), "a b c d ")
    .CHECK_OUTPUT(R_string_char.str(), "H e L L o W o R l D ");



    //***********************************TEST CHAIN***************************************//


    ostringstream chain_int1, chain_int2, chain_double1, chain_char1, chain_char2, chain_char3, C_string_char;

    for(int i : chain(range(1,5),range(5,10)))
    {
      chain_int1 << i;
    }
    for(int i : chain(range(1.5,5.5),range(6,10)))
    {
      chain_int2 << i;
    }
    for(double d : chain(range(0.5,3.5),range(4.5,6.5)))
    {
      chain_double1 << d << " ";
    }
    for(char c : chain(range('A','D'),range('D','H')))
    {
      chain_char1 << c;
    }
    for(char c : chain(range('a','d'),range('d','h')))
    {
      chain_char2 << c;
    }
    for(char c : chain(range('A','D'),range('d','h')))
    {
      chain_char3 << c;
    }
    for(char c : chain(range('A','D'),string("CBA")))
    {
      C_string_char << c;
    }

    testcase.setname("test chain")
    .CHECK_OUTPUT(chain_int1.str(), "123456789")
    .CHECK_OUTPUT(chain_int2.str(), "12346789")
    .CHECK_OUTPUT(chain_double1.str(), "0.5 1.5 2.5 4.5 5.5 ")
    .CHECK_OUTPUT(chain_char1.str(), "ABCDEFG")
    .CHECK_OUTPUT(chain_char2.str(), "abcdefg")
    .CHECK_OUTPUT(chain_char3.str(), "ABCdefg")
    .CHECK_OUTPUT(C_string_char.str(), "ABCCBA");


    //***********************************TEST ZIP***************************************//


    ostringstream zip_int, zip_double, zip_char1, zip_char2, zip_char3, Z_string_char, zip_zip;

    for(auto i : zip(range(1,5),range(2,6)))
    {
      zip_int << i << " ";
    }
    for(auto d : zip(range(0.5,3.5),range(1.1,4.1)))
    {
      zip_double << d << " ";
    }
    for(auto c : zip(range('A','D'),range('B','E')))
    {
      zip_char1 << c << " ";
    }
    for(auto c : zip(range('a','d'),range('b','e')))
    {
      zip_char2 << c << " ";
    }
    for(auto c : zip(range('a','d'),range(1,4)))
    {
      zip_char3 << c << " ";
    }
    for(auto c : zip(string("abc"),string("ABC")))
    {
      Z_string_char << c << " ";
    }
    for(auto z : zip(zip(range(1,4),range(1.5,4.5)), zip(range('a','d'),string("ABC"))))
    {
      zip_zip << z << " ";
    }

    testcase.setname("test zip")
    .CHECK_OUTPUT(zip_int.str(), "1,2 2,3 3,4 4,5 ")
    .CHECK_OUTPUT(zip_double.str(), "0.5,1.1 1.5,2.1 2.5,3.1 ")
    .CHECK_OUTPUT(zip_char1.str(), "A,B B,C C,D ")
    .CHECK_OUTPUT(zip_char2.str(), "a,b b,c c,d ")
    .CHECK_OUTPUT(zip_char3.str(), "a,1 b,2 c,3 ")
    .CHECK_OUTPUT(Z_string_char.str(), "a,A b,B c,C ")
    .CHECK_OUTPUT(zip_zip.str(), "1,1.5,a,A 2,2.5,b,B 3,3.5,c,C ");


    //***********************************TEST PRODUCT***************************************//


    ostringstream pro_int_int, pro_int_double, pro_int_char, pro_int_string, pro_double_string, pro_char_string, pro_string_string, pro_chain, pro_zip;

    for(auto i : product(range(1,3),range(1,4)))
    {
      pro_int_int << i << " ";
    }
    for(auto d : product(range(1,3),range(1.1,2.1)))
    {
      pro_int_double << d << " ";
    }
    for(auto c : product(range(1,3),range('a','c')))
    {
      pro_int_char << c << " ";
    }
    for(auto c : product(range(1,3),string("Bye")))
    {
      pro_int_string << c << " ";
    }
    for(auto c : product(range(1.3,2.3),string("wood")))
    {
      pro_double_string << c << " ";
    }
    for(auto c : product(range('a','c'),string("ABC")))
    {
      pro_char_string << c << " ";
    }
    for(auto z : product(string("bye"),string("ABC")))
    {
      pro_string_string << z << " ";
    }
    for(auto p : product(chain(range(1,3),range(3,4)),chain(range('a','c'),range('c','d'))))
    {
      pro_chain << p << " ";
    }
    for(auto p : product(zip(range(1,3),range(5,7)),zip(range('a','c'),range('c','f'))))
    {
      pro_zip << p << " ";
    }

    testcase.setname("test product")
    .CHECK_OUTPUT(pro_int_int.str(), "1,1 1,2 1,3 2,1 2,2 2,3 ")
    .CHECK_OUTPUT(pro_int_double.str(), "1,1.1 2,1.1 ")
    .CHECK_OUTPUT(pro_int_char.str(), "1,a 1,b 2,a 2,b ")
    .CHECK_OUTPUT(pro_int_string.str(), "1,B 1,y 1,e 2,B 2,y 2,e ")
    .CHECK_OUTPUT(pro_double_string.str(), "1.3,w 1.3,o 1.3,o 1.3,d ")
    .CHECK_OUTPUT(pro_char_string.str(), "a,A a,B a,C b,A b,B b,C ")
    .CHECK_OUTPUT(pro_string_string.str(), "b,A b,B b,C y,A y,B y,C e,A e,B e,C ")
    .CHECK_OUTPUT(pro_chain.str(), "1,a 1,b 1,c 2,a 2,b 2,c 3,a 3,b 3,c ")
    .CHECK_OUTPUT(pro_zip.str(), "1,5,a,c 1,5,b,d 2,6,a,c 2,6,b,d ");



    //***********************************TEST POWERSET***************************************//

  //
  //   ostringstream pow_int, pow_double, pow_char, pow_string, pow_chain, pow_zip, pow_pro, pow_zip_chain, pow_pro_chain;
  //
  //   for(auto i : powerset(range(1,4)))
  //   {
  //     pow_int << i << " ";
  //   }
  //   for(auto d : powerset(range(0.5,3.5)))
  //   {
  //     pow_double << d << " ";
  //   }
  //   for(auto c : powerset(range('A','D')))
  //   {
  //     pow_char << c << " ";
  //   }
  //   // for(auto s : powerset(string("do")))
  //   // {
  //   //   pow_string << s << " ";
  //   // }
  //   for(auto p : powerset(chain(range(1,3),range(3,4))))
  //   {
  //     pow_chain << p << " ";
  //   }
  //   for(auto p : powerset(zip(range(1,3),range(3,4))))
  //   {
  //     pow_zip << p << " ";
  //   }
  //   for(auto p : powerset(product(range(1,3),range(3,4))))
  //   {
  //     pow_pro << p << " ";
  //   }
  //   for(auto p : powerset(zip(chain(range(1,2),range(2,3)),chain(range(3,4),range(4,5)))))
  //   {
  //     pow_zip_chain << p << " ";
  //   }
  //   for(auto p : powerset(product(chain(range(1,2),range(2,3)),chain(range(3,4),range(4,5)))))
  //   {
  //     pow_pro_chain << p << " ";
  //   }
  //
  //   testcase.setname("test powerset")
  //   .CHECK_OUTPUT(pow_int.str(), "{} {1} {2} {1,2} {3} {1,3} {2,3} {1,2,3} ")
  //   .CHECK_OUTPUT(pow_double.str(), "{} {0.5} {1.5} {0.5,1.5} {2.5} {0.5,2.5} {1.5,2.5} {0.5,1.5,2.5} ")
  //   .CHECK_OUTPUT(pow_char.str(), "{} {A} {B} {A,B} {C} {A,C} {B,C} {A,B,C} ")
  // // .CHECK_OUTPUT(pow_string.str(), "{} {d} {o} {d,o} ")
  //   .CHECK_OUTPUT(pow_chain.str(), "{} {1} {2} {1,2} {3} {1,3} {2,3} {1,2,3} ")
  //   .CHECK_OUTPUT(pow_zip.str(), "{} {1} {2} {3} {1,2} {1,3} {2,3} {1,2,3} ")
  //   .CHECK_OUTPUT(pow_pro.str(), "{} {1,3} {2,3} {1,3,2,3} ")
  //   .CHECK_OUTPUT(pow_zip_chain.str(), "{} {1,3} {2,3} {1,3,2,3} ")
  //   .CHECK_OUTPUT(pow_pro_chain.str(), "{} {1,3} {1,4} {1,3,1,4} {2,3} {1,3,2,3} {1,4,2,3} {1,3,1,4,2,3} {2,4} {1,3,2,4} {1,4,2,4} {1,3,1,4,2,4} {2,3,2,4} {1,3,2,3,2,4} {1,4,2,3,2,4} {1,3,1,4,2,3,2,4} ");


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
