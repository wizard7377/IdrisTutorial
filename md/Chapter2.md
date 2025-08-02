# Chapter 2: The Universal Declaration of Function (Rights)

Let us now write some actual code.
Let us consider a very simple function, say, creates a list[^1] that contains a integer twice. In C++, we might have[^2] 
```c++
std::vector<int> twice(int x);
std::vector<int> twice(int x) {
    return {x, x};
}
```

The Idris equivalent is:

```idris
    twice : Int -> List Int
    twice x = [x, x]
```

A couple things to note here.
Firstly, the Idris definition is far more *expressive* while also being less *verbose*. 
That is, its easier to read, and it takes up less space on the screen.

The first difference between the two above samples is there syntax.
Let's compare the decleartions first:
```c++
std::vector<int> twice(int x);
```
While in Idris
```idris
twice : Int -> List Int
```
While this might seem intimidating at first, if one reads the colon, `:`, as `is (a)` and the arrow, `->`, as `function from ... to ...`, we can just read this as "`twice` is a function from `Int` to `List Int`".

Next, lets go to the definitions, those being
```c++
std::vector<int> twice(int x) {
    return {x, x};
}
```

and

```idris
    twice x = [x, x]
```

While it might be *slightly* hard to tell, the Idris shorter than the C++ one. 
By just a little bit.[^3]

Firstly, in Idris, we don't repeat what we already know.
We already have the type of `twice`, as well as of `x`, so we don't write them again.
But much more importantly is the change from imperative style to declerative style.

What is declerative style? Well, in the C++ example, the definition has two very unequal parts, the head `std::vector<int> twice(int x)` and the body `{ return {x, x}; }`. 
This is imperative, that is, it tells the program *what* to do. 
We are telling the program "when I give you an integer `x`, I want you to give me the result of two `x`. Importantly, this is not something that can be inverted easily. That is, there isn't a way in which we might reason about, say, inverses.

Compare this to the Idris definition. 
In Idris, neither side is given priority, that is, we might see that we can invert this relation to get something quite sensible. 
We can just as reasonably convert `twice 2` to `[2,2]` as we might convert `[2,2]` to `twice 2`.

## The Freedom to Anonymity


[^1]: In C++ terms, a vector
[^2]: Given that we have already written `#include <vector>`
[^3]: This comparison is a little bit unfair towards C++. In C++, almost all functions *do not* have foward declerations, while in Idris almost all functions *do* have type declerations.