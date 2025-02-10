#include "PrintHelper.h"

/* *************************************
 * * Fundamental types and expressions *
 * *************************************
 *
 * Tasks:
 * ------
 * - Compile the program and analyse the output of the different expressions
 * - Discuss with other students or your tutor in case the result of an expression is a surprise
 * - Fix the marked expressions by changing types such that they produce meaningful results
 * - Answer the questions in the code
 */

int main() {
  std::cout << "Using literals of different number types:\n";
  print(5);
  print(5.f/2.f);           //FIXME changed to float division
  print(100/2ull);
  print(2 + 4ull);
  print(2.f + 4ull);
  print(0 - 1);       // FIXME changed to signed operation
  print(1.0000000001L); // FIXME Why is this number not represented correctly?
  // A: Floating-point numbers have limited precision, 
  //    so certain decimal fractions cannot be represented exactly in binary.
  print(1.L + 1.E-18L);   // FIXME Use long double for a clearer result

  std::cout << "\nUsing increment and decrement operators:\n";
  int a = 1;
  int b;
  int c;
  print(b = a++);       // Q: What is the difference between a++ and ++a?
    /*
    A: a++ (postfix) returns the old value of 'a' and then increments it,
       while ++a (prefix) increments 'a' first and then returns the new value.
  */
  print(c = ++a);
  print(a);
  print(b);
  print(c);

  std::cout << "\nCompound assignment operators:\n";
  int n = 1;
  print(n *= 2);        // Q: Is there a difference between this and the next line?
    /*
    A: Here n is multiplied by 2 (an integer literal).
       In the next line, multiplication involves a floating-point literal 2.9, 
       but 'n' is still an int, so the fractional part is truncated.
  */
  print(n *= 2.9);
  print(n -= 1.1f);
  print(n /= 4);        // Q: Based on the results of these expressions, is there a better type to be used for n?
  /*
    A: Using a floating-point type (like float or double) could be better to preserve any fractional part 
       in calculations, if that's desired.
  */

  std::cout << "\nLogic expressions:\n";
  const bool alwaysTrue = true;
  bool condition1 = false;
  bool condition2 = true;
  print( alwaysTrue && condition1 && condition2 );
  print( alwaysTrue || condition1 && condition2 );  // Q: Why does operator precedence render this expression useless?
    /*
    A: && has higher precedence than ||, so condition1 && condition2 is evaluated first, 
       but since alwaysTrue is true, the overall expression is always true (short-circuits).
  */
  print( alwaysTrue && condition1 || condition2 );
  print(condition1 != condition1);                  // Q: What is the difference between this and the following expression?
    /*
    A: '!=' is a comparison that returns true or false, comparing the two operands. 
       In this example, it checks if condition1 is not equal to itself, which is always false.
  */
  print(condition2 = !condition2);
    /*
    A: Here, '=' is the assignment operator, which assigns the negated value of condition2 to condition2.
  */  
  print( alwaysTrue && condition1 && condition2 );
  print( alwaysTrue || condition1 && condition2 );
  print( alwaysTrue && condition1 || condition2 );

  std::cout << '\n';
  print( false || 0b10 );     // Q: What is the difference between || and | ?
   /*
    A: '||' is a logical OR (with short-circuiting), 
       while '|' is a bitwise OR (no short-circuiting, operates on bits).
  */
  print( false | 0b10 );
  printBinary( 0b1 & 0b10 );
  printBinary( 0b1 | 0b10 );
  printBinary( 0b1 && 0b10 ); // Q: Are the operators && and || appropriate for integer types?
    /*
    A: Technically they can be used since non-zero integers become 'true', but they are meant for boolean logic.
       For bitwise operations on integers, use & or |, not && or ||.
  */
  printBinary( 0b1 || 0b10 );

  std::cout << "\nPlay with characters and strings:\n";
  print("a");                 // Q: Why is this expression two bytes at run time, the next only one?
    /*
    A: The string literal "a" includes both 'a' and the null terminator '\0', 
       thus occupying 2 bytes in memory. 
  */
  print('a');

  char charArray[20] = {}; // We zero-initialize the array so it doesn't contain uninitialized data
  char* charPtr = charArray;
  charArray[19] = 0; // Make sure that our string is terminated with the null byte

  print(charArray);
  print(charArray[0] = 'a');
  print(charArray);
  print(charArray[1] = 98);
  print(charArray);
  print(charPtr);
  // FIXME: Ensure that no unexpected garbage is printed above

  return 0;
}
