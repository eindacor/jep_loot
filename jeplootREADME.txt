--------------------------------------------------------------------------------
                              jeploot library README
--------------------------------------------------------------------------------


To build this as a shared library from the source file, use the following:

g++ -fPIC -c jeploot.cpp
g++ -shared -o libjeploot.so jeploot.o

To use this library, source code must #include "jeploot.h", and the file 
libjeploot.so must be placed in your shared library directory.


Function                         Description
--------                         -----------
jep::init()                      Initializes jeploot file. 


jep::booRoll(double d)           Returns true based on percent chance passed (in 
                                 decimal form). Values greater than or equal to
                                 1 will always return true, values less than or
                                 equal to 0 will always return false.


jep::intRoll(int n1, int n2)     Returns a random int, from a range between the
                                 two integers passed.


jep::catRoll(int n, ...)         Takes n values (ints). Each value represents
                                 categories 1-n respectively. Each category's
                                 chance of rolling is equal to that category's
                                 ratio to the sumtotal of all values. For 
                                 instance, jep::catRoll(4, 10, 20, 60, 45) would
                                 have 4:135 odds to return 1, 10:135 odds to 
                                 return 2, 20:135 odds to return 3, 60:135 odds
                                 to return 4, and 45:135 odds to return 5.


--------------------------------------------------------------------------------

