

---

## 📄 CHANGES.md

```markdown
# Changes from InOut.hpp V1 to V2

## 🔄 Structural Changes
- Simplified the function structure for input and output.
- Unified naming convention under the `io::` namespace.
- Introduced `io::input` as the standard input function.

## 🗑️ Removed
- Removed `using` directives (`std::string`, `std::vector`, etc.) to prevent namespace conflicts.
- Removed type-specific objects, which previously added unnecessary complexity.

## ✨ Improvements
- Cleaner and more intuitive API for both input and output.
- More professional design for better integration with larger projects.
- Reduced ambiguity and increased code clarity.

## 📢 Migration Note
If you used `InOut.hpp V1`, switch to **V2**. The new design provides a smoother developer experience and avoids namespace pollution.

