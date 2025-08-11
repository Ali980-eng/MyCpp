# udt::dynamic – A Flexible Multi-Type Data Container in C++

`udt::dynamic` is a custom C++ type designed to store and manage multiple fundamental data types within a single object.  
It uses `std::unique_ptr` for automatic memory management and takes advantage of operator overloading and type deduction to provide a seamless and flexible interface.

---

## Features
- **Automatic memory management** via `std::unique_ptr`.
- Supports fundamental types:
  - `int`
  - `char`
  - `bool`
  - `float`
  - `double`
- **Complex Type Mode** – store multiple values of different types in one object.
- Can be used with `std::vector` and other standard containers.
- Supports dynamic assignment and retrieval of multiple types.

---

## Complex Type Example
```cpp
#include "Dynamic.hpp"
#include <iostream>

int main() {
    edt::dynamic d;
    d.complex();    // Enable complex type mode
    d = 10;
    d = true;
    d = 'u';        // Multiple types stored

    // If complex() is not called, only the last assigned value is stored
}
