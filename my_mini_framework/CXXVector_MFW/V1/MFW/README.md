# CXXVector (formerly `vector_tools.hpp`)

**CXXVector** is a lightweight mini-framework focused on enhancing and extending the capabilities of C++ vectors.  
It provides a set of specialized headers for multidimensional vectors, paired vectors, vector utilities, and a unified interface.

---

## 🚀 Overview

Unlike `std::vector`, this framework does not reinvent the data structure.  
Instead, it **wraps and extends `std::vector`** to provide additional functionality and abstractions,  
making it easier to work with multidimensional, paired, and functional-style vector operations.

---

## 📂 Components

### 1. `multidimensional_vector.hpp`
Provides tools for multidimensional vectors:
- `uvt::vector<T>` — wrapper around `std::vector<T>`.
- `uvt::vector_2d<T>` — two-dimensional vectors.
- `uvt::vector_3d<T>` — three-dimensional vectors.

> Note: These are **not new containers**, but wrappers around `std::vector` that add new features and simplified handling.

---

### 2. `pair_vector.hpp`
Provides data structures for paired vectors:
- `uvt::pair_v<T>` — a pair of vectors holding the **same type**.
- `uvt::pair__v<T1, T2>` — a pair of vectors holding **different types**.

These abstractions are useful for managing correlated vector data.

---

### 3. `vector_functions.hpp`
A collection of utility functions for working with vectors:
- `sub_v()` — extract sub-vectors.  
- `v_end()` — advanced handling of vector endings.  
- `...and more`.

---

### 4. `CXXVector.hpp`
The **main entry point** of the framework:
- Includes all other headers with a single `#include`.
- Adds extra features such as **`vstream`**, which allows treating a vector as a data stream.

---

## ✨ Key Features
- Lightweight (~5500 lines of code with documentation).
- Extends `std::vector` without replacing it.  
- Multidimensional vector support.  
- Paired vector types for correlated data.  
- Functional utilities for vector manipulation.  
- Stream-like abstraction for vectors.  

---

## 📜 License
This project is licensed under a **custom license by Ali Lafi**.  
- Free to use and modify.  
- Redistribution is only allowed via the **official link provided by the author**.  
- The author retains copyright.  
- See [[LICENSE](./LICENSE)](https://github.com/Ali980-eng/MyCpp/blob/main/my_mini_framework/CXXVector_MFW/V1/LICENSE) for details.
