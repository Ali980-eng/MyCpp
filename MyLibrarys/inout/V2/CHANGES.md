
---

## 📄 CHANGES.md (V1 و V2)

```markdown
# Changes from InOut.hpp V1 to V2

## 🔄 Structural Changes
- Simplified the structure of input/output functions to make them more intuitive and user-friendly.

## 🗑️ Removed
- Removed `using std::string`, `using std::vector`, and similar directives.  
  - Reason: prevent name clashes and improve professionalism.
- Removed type-specific objects (custom wrappers for types).  
  - Reason: they introduced unnecessary complexity and caused issues.

## ✨ Improvements
- Unified and cleaner interface for input/output.
- More modular and maintainable design.
- Better consistency across the entire NTE library.

## 📢 Migration Note
Projects using `InOut.hpp V1` should update to **V2**.  
The new version is designed to reduce ambiguity and provide a smoother developer experience.
