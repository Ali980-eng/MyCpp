# CXXLite Framework

**CXXLite** is a lightweight **mini-framework** written in **C++** that provides
a collection of essential utility libraries to simplify everyday programming tasks.  
This release consolidates and refactors previously published libraries with updated names
and improved structure.

---

## 🗂️ Included Libraries

- **CXXIO.hpp**  
  (previously `InOut.hpp v2.1`)  
  Provides simplified **console input/output** operations.

- **CXXTesting.hpp**  
  (previously `testing.hpp v2.1`)  
  A lightweight library for **testing functions** and validating results.

- **CXXBenchmark.hpp**  
  (previously part of `testing.hpp v2.1`)  
  Tools for measuring performance, including **time benchmarking** and **size benchmarking**.

- **function_stream.hpp**  
  Handles **lambda functions** safely and flexibly through "function streams."

- **CXXLite.hpp**  
  A central aggregator that unifies all the above libraries and introduces extra utilities:  
  - `txtfile_manager` for reading/writing `.txt` files.  
  - Additional helper objects for handling streams and functions.  

---

## ✨ Key Features

- 📥 Simplified **console I/O operations**.  
- 🧪 **Function testing** utilities for quick validation.  
- ⏱️ **Benchmarking tools** (time and size).  
- 📂 Built-in `.txt` **file management** with `txtfile_manager`.  
- 🔄 Safe handling of **lambda functions** via `function_stream`.  
- 🧩 **Modular structure** — use individual headers or the unified `CXXLite.hpp`.  

---

## 🚀 Installation & Usage

CXXLite is a **header-only** framework.  
Simply download the files and place them inside your project’s `include/` directory.  

Example:
```cpp
#include "CXXLite.hpp"

int main() {
    console::print("Hello, CXXLite!");
    return 0;
}
