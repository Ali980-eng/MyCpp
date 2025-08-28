
---

## 📄 README.md (`InOut.hpp V2`)

```markdown
# InOut.hpp V2
`InOut.hpp V2` is the new input/output interface for the Numerical Techniques for Engineers (NTE) library.

## ✨ Improvements in V2
- **Simplified function interfaces**: Input and output functions are easier to use.
- **Removed unnecessary `using` directives** (`std::string`, `std::vector`, etc.) to avoid namespace pollution and conflicts.
- **Removed type-specific objects** that were over-complicating the interface.
- **More professional design**: cleaner, safer, and easier to integrate into projects.

## 🚀 Example
```cpp
#include "InOut.hpp"

int main() {
    int x = io::input("Enter a number: ");
    io::print("You entered: ", x);
}
