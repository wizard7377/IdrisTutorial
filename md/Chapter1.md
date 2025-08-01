# Chapter 1: Cartography in Idris

Cartography is the art of making maps. What does this have to do with programming? In Idris, and other functional programming languages, the answer is that maps, otherwise known as functions, have almost everything to do with programming. This might seem strange. Coming from C++, C, Rust, or the like, you likely think of programming functions (or methods) as a way of *doing* some sort of action. We might have function that proceeds to look into a database, or perhaps write a message to a terminal. This is (seemingly) in stark contrast to one's idea of mathmatical functions. Mathmatiacal functions are most useuly grasped as ones to map certain values to certain other values.

For instance, the function below in C++ seems to be unrelated to "pure" mathmatical functions.
```c++
#include <iostream>
using namespace std;

int getAndReverse() {

  int n, reversed_number = 0, remainder;

  cout << "Enter an integer: ";
  cin >> n;

  while(n != 0) {
    remainder = n % 10;
    reversed_number = reversed_number * 10 + remainder;
    n /= 10;
  }

  cout << "Reversed Number = " << reversed_number;

  return reversed_number;
}
```

This involves reading from input, writing to output. Per as a matter of fact, we can even specify exactly what we mean by the aforementioned "purity". Namely, a function is "pure" if we know that we can call it as many or as few times as we like, and absolutly nothing will change. If we had 10 bannanas that each cost a dollar, and discovered that they were at $50\%$ discount, we could think about each bannana in turn as having the discount, reasoning about bannana number one costing $50\%$ off, number 2 $50\%$ off, and so on, or we could just realize that $50\%$ off one dollar isn't likely to change just because of how many times we calculate it.

Compare this to the above function. Not only does the world around us change whenever we compute it, (the screen has text added to it), it will *also* return a different value each time we compute it, due to the fact that it reads in from input. This means that an expression like 
```c++
int n = getAndReverse() ;
n * n
```
May not be safely equivalent to (replacing `n` with its definition)
```c++
getAndReverse() * getAndReverse()
```
As we changed the code from calling `getAndReverse` once to twice