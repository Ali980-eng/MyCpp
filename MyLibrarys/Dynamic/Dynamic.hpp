#pragma once
#ifndef PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_DYNAMIC_HPP
#define PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_DYNAMIC_HPP
#include "InOut.hpp"
#include <cmath>
#include <memory>
namespace udt // udt: unique data type
{

    using namespace std;

    class dynamic
    {

    private:
        unique_ptr<int> d_int = nullptr;
        unique_ptr<char> d_char = nullptr;
        unique_ptr<float> d_float = nullptr;
        unique_ptr<double> d_double = nullptr;
        unique_ptr<bool> d_bool = nullptr;
        bool allow = true, complextype = false;

    public:
        dynamic() = default;

        // Move Constructor
        dynamic(dynamic &&) = default;

        dynamic(int val) noexcept
        {
            d_int = make_unique<int>(val);
            allow = false;
        }

        dynamic(char val) noexcept
        {
            d_char = make_unique<char>(val);
            allow = false;
        }

        dynamic(float val) noexcept
        {
            d_float = make_unique<float>(val);
            allow = false;
        }

        dynamic(double val) noexcept
        {
            d_double = make_unique<double>(val);
            allow = false;
        }

        dynamic(bool val)
        {
            d_bool = make_unique<bool>(val);
            allow = false;
        }

        dynamic(const dynamic &other)
        {
            if (other.d_int)
                d_int = std::make_unique<int>(*other.d_int);
            if (other.d_char)
                d_char = std::make_unique<char>(*other.d_char);
            if (other.d_float)
                d_float = std::make_unique<float>(*other.d_float);
            if (other.d_double)
                d_double = std::make_unique<double>(*other.d_double);
            if (other.d_bool)
                d_bool = std::make_unique<bool>(*other.d_bool);
            allow = other.allow;
            complextype = other.complextype;
        }

        void complex()
        {
            complextype = true;
        }

        void uncomplex(bool reint = true,
                       bool rechar = true,
                       bool refloat = true,
                       bool redouble = true,
                       bool rebool = true)
        {
            int boolcheck = reint + refloat + rechar + redouble;
            if (boolcheck < 3)
                throw invalid_argument("to many data to hold for the uncomplex type");
            complextype = false;
            if (d_int != nullptr && reint)
                d_int = nullptr;
            if (d_float != nullptr && refloat)
                d_float = nullptr;
            if (d_double != nullptr && redouble)
                d_double = nullptr;
            if (d_char != nullptr && rechar)
                d_char = nullptr;
            if (d_bool != nullptr)
                d_bool = nullptr;
        }

        void set_bool(bool val)
        {
            if (allow || complextype)
            {
                d_bool = make_unique<bool>(val);
                allow = false;
            }
            throw invalid_argument("not complextype nor allowed changes");
        }

        void set_int(int val)
        {
            if (allow || complextype)
            {
                d_int = make_unique<int>(val);
                allow = false;
            }
            else
                throw invalid_argument("Change not allowed");
        }

        void set_char(char val)
        {
            if (allow || complextype)
            {
                d_char = make_unique<char>(val);
                allow = false;
            }
            else
                throw invalid_argument("Change not allowed");
        }

        void set_float(float val)
        {
            if (allow || complextype)
            {
                d_float = make_unique<float>(val);
                allow = false;
            }
            else
                throw invalid_argument("Change not allowed");
        }

        void set_double(double val)
        {
            if (allow || complextype)
            {
                d_double = make_unique<double>(val);
                allow = false;
            }
            else
                throw invalid_argument("Change not allowed");
        }

        bool get_bool() const
        {
            if (d_bool != nullptr)
                return *d_bool;
            else if (complextype && d_bool)
                throw invalid_argument("no set declaration for d_bool");
            else
                throw invalid_argument("Getting not allowed: the value is not boolean");
        }

        int get_int() const
        {
            if (d_int != nullptr)
                return *d_int;
            else if (complextype && d_int == nullptr)
                throw invalid_argument("no set declaration for d_int");
            else
                throw invalid_argument("Getting not allowed: the value is not integer");
            return 0;
        }

        char get_char() const
        {
            if (d_char != nullptr)
                return *d_char;
            else if (complextype && d_char == nullptr)
                throw invalid_argument("no set declaration for d_char");
            else
                throw invalid_argument("Getting not allowed: the value is not character");
            throw runtime_error("");
        }

        float get_float() const
        {
            if (d_float != nullptr)
                return *d_float;
            else if (complextype && d_float != nullptr)
                throw invalid_argument("no set declaration for d_float");
            else
                throw invalid_argument("Getting not allowed: the value is not float");
            return 0;
        }

        double get_double() const
        {
            if (d_double != nullptr)
                return *d_double;
            else if (complextype && d_double == nullptr)
                throw invalid_argument("no set declaration for d_double");
            else
                throw invalid_argument("Getting not allowed: the value is not double");
            return 0;
        }

        dynamic get_value() const
        {
            if (complextype)
                throw invalid_argument("complex type don't return specific standard data type automatically");
            if (d_int != nullptr)
                return dynamic(*d_int);
            else if (d_char != nullptr)
                return dynamic(*d_char);
            else if (d_float != nullptr)
                return dynamic(*d_float);
            else if (d_double != nullptr)
                return dynamic(*d_double);
            else if (d_bool != nullptr)
                return dynamic(*d_bool);
            throw runtime_error("no value set");
        }

        string get_name() const
        {
            if (complextype)
                return "complex";
            if (d_int != nullptr)
                return "integer";
            if (d_float != nullptr)
                return "float";
            if (d_double != nullptr)
                return "double";
            if (d_char != nullptr)
                return "character";
            if (d_bool != nullptr)
                return "boolean";
            return "undefined";
        }

        constexpr bool is_complex() const noexcept
        {
            return complextype;
        }

        bool is_empty() const noexcept
        {
            return d_int == nullptr && d_char == nullptr && d_float == nullptr && d_double == nullptr && d_bool == nullptr;
        }

        void clear_all() noexcept
        {
            d_int = nullptr;
            d_char = nullptr;
            d_float = nullptr;
            d_double = nullptr;
            d_bool = nullptr;
            allow = true;
        }

        void clear_bool() noexcept
        {
            if ((!allow || complextype) && d_bool != nullptr)
            {
                d_bool = nullptr;
                allow = true;
            }
        }

        void clear_int() noexcept
        {
            if ((!allow || complextype) && d_int != nullptr)
            {
                d_int = nullptr;
                allow = true;
            }
        }

        void clear_float() noexcept
        {
            if ((!allow || complextype) && d_float != nullptr)
            {
                d_float = nullptr;
                allow = true;
            }
        }

        void clear_double() noexcept
        {
            if ((!allow || complextype) && d_double != nullptr)
            {
                d_double = nullptr;
                allow = true;
            }
        }

        void clear_char() noexcept
        {
            if ((!allow || complextype) && d_char != nullptr)
            {
                d_char = nullptr;
                allow = true;
            }
        }

        bool has_bool() const noexcept
        {
            if (d_bool != nullptr)
                return true;
            return false;
        }

        bool has_int() const noexcept
        {
            if (d_int != nullptr)
                return true;
            return false;
        }

        bool has_float() const noexcept
        {
            if (d_float != nullptr)
                return true;
            return false;
        }

        bool has_double() const noexcept
        {
            if (d_double != nullptr)
                return true;
            return false;
        }

        bool has_char() const noexcept
        {
            if (d_char != nullptr)
                return true;
            return false;
        }

        bool has(const string &type) const
        {
            if (type == "int")
                has_int();
            if (type == "float")
                has_float();
            if (type == "double")
                has_double();
            if (type == "char")
                has_char();
            if (type == "boolean")
                has_bool();
            return false;
        }

        bool is_pure_numeric()
        {
            if (complextype)
            {
                if (d_char == nullptr && d_bool == nullptr && (d_int != nullptr || d_float != nullptr || d_double != nullptr))
                    return true;
                else
                    return false;
            }
            else
            {
                if (d_char == nullptr && d_bool == nullptr)
                    return true;
                else
                    return false;
            }
            io::println_error("type error: check the declaration process");
            throw runtime_error("the function run beyond expected");
        }

        friend ostream &operator<<(ostream &os, const dynamic &d)
        {
            if (d.complextype)
            {
                bool printed = false;
                os << "{ ";
                if (d.d_int != nullptr)
                {
                    os << "int: " << *d.d_int;
                    printed = true;
                }
                if (d.d_float != nullptr)
                {
                    if (printed)
                        os << ", ";
                    os << "float: " << *d.d_float;
                    printed = true;
                }
                if (d.d_double != nullptr)
                {
                    if (printed)
                        os << ", ";
                    os << "double: " << *d.d_double;
                    printed = true;
                }
                if (d.d_char)
                {
                    if (printed)
                        os << ", ";
                    os << "char: '" << *d.d_char << "'";
                }
                if (d.d_bool)
                {
                    if (printed)
                        os << ", ";
                    os << "bool: '" << *d.d_bool << "'";
                }
                os << " }";
                return os;
            }
            else if (d.d_int != nullptr)
                return os << *d.d_int;
            else if (d.d_float != nullptr)
                return os << *d.d_float;
            else if (d.d_double != nullptr)
                return os << *d.d_double;
            else if (d.d_char != nullptr)
                return os << *d.d_char;
            else if (d.d_bool != nullptr)
                return os << *d.d_bool;
            else
                return os << "[undefined dynamic]";
        }

        // Move Assignment Operator
        dynamic &operator=(dynamic &&) = default;

        void operator=(int val)
        {
            if (allow || complextype)
            {
                d_int = make_unique<int>(val);
                allow = false;
            }
            else
                throw invalid_argument("uncomplex type can not have more than one value");
        }

        void operator=(float val)
        {
            if (allow || complextype)
            {
                d_float = make_unique<float>(val);
                allow = false;
            }
            else
                throw invalid_argument("uncomplex type can not have more than one value");
        }

        void operator=(double val)
        {
            if (allow || complextype)
            {
                d_double = make_unique<double>(val);
                allow = false;
            }
            else
                throw invalid_argument("uncomplex type can not have more than one value");
        }

        void operator=(char val)
        {
            if (allow || complextype)
            {
                d_char = make_unique<char>(val);
                allow = false;
            }
            else
                throw invalid_argument("uncomplex type can not have more than one value");
        }

        void operator=(bool val)
        {
            if (allow || complextype)
            {
                d_bool = make_unique<bool>(val);
                allow = false;
            }
            else
                throw invalid_argument("uncomplex type can not have more than one value");
        }

        // Copy Assignment Operator
        dynamic &operator=(const dynamic &other)
        {
            if (this != &other)
            {
                clear_all();
                if (other.d_int)
                    d_int = std::make_unique<int>(*other.d_int);
                if (other.d_char)
                    d_char = std::make_unique<char>(*other.d_char);
                if (other.d_float)
                    d_float = std::make_unique<float>(*other.d_float);
                if (other.d_double)
                    d_double = std::make_unique<double>(*other.d_double);
                if (other.d_bool)
                    d_bool = std::make_unique<bool>(*other.d_bool);
                allow = other.allow;
                complextype = other.complextype;
            }
            return *this;
        }

        bool operator==(int val) const noexcept
        {
            if (d_int != nullptr && val == *d_int)
                return true;
            return false;
        }

        bool operator==(float val) const noexcept
        {
            if (d_float != nullptr && val == *d_float)
                return true;
            return false;
        }

        bool operator==(double val) const noexcept
        {
            if (d_double != nullptr && val == *d_double)
                return true;
            return false;
        }

        bool operator==(char val) const noexcept
        {
            if (d_char != nullptr && val == *d_char)
                return true;
            return false;
        }

        bool operator==(bool val) const noexcept
        {
            if (d_bool != nullptr && *d_bool == val)
                return true;
            return false;
        }

        void operator+=(int val)
        {
            if (d_int != nullptr)
                *d_int += val;
            else if (d_float != nullptr && !complextype)
                *d_float += static_cast<float>(val);
            else if (d_double != nullptr && !complextype)
                *d_double += static_cast<double>(val);
            else
                throw invalid_argument("Addition not allowed in to different types");
        }

        void operator+=(float val)
        {
            if (d_float != nullptr)
                *d_float += val;
            else if (d_int != nullptr && !complextype)
                *d_int += static_cast<int>(val);
            else if (d_double != nullptr && !complextype)
                *d_double += static_cast<double>(val);
            else
                throw invalid_argument("Addition not allowed in to different types");
        }

        void operator+=(double val)
        {
            if (d_double != nullptr)
                *d_double += val;
            else if (d_int != nullptr && !complextype)
                *d_int += static_cast<int>(val);
            else if (d_float != nullptr && !complextype)
                *d_float += static_cast<float>(val);
            else
                throw invalid_argument("Addition not allowed in to different types");
        }

        void operator+=(char val) const
        {
            if (d_int != nullptr && !complextype)
                *d_int += static_cast<int>(val);
            else if (d_float != nullptr && !complextype)
                *d_float += static_cast<float>(val);
            else if (d_double != nullptr && !complextype)
                *d_double += static_cast<double>(val);
            else
                throw invalid_argument("Addition not allowed in char type");
        }

        void operator-=(int val)
        {
            if (d_int != nullptr)
                *d_int -= val;
            else if (d_float != nullptr && !complextype)
                *d_float -= static_cast<float>(val);
            else if (d_double != nullptr && !complextype)
                *d_double -= static_cast<double>(val);
            else
                throw invalid_argument("Subtraction not allowed in to different types");
        }

        void operator-=(float val)
        {
            if (d_float != nullptr)
                *d_float -= val;
            else if (d_int != nullptr && !complextype)
                *d_int -= static_cast<int>(val);
            else if (d_double != nullptr && !complextype)
                *d_double -= static_cast<double>(val);
            else
                throw invalid_argument("Subtraction not allowed in to different types");
        }

        void operator-=(double val)
        {
            if (d_double != nullptr)
                *d_double -= val;
            else if (d_int != nullptr && !complextype)
                *d_int -= static_cast<int>(val);
            else if (d_float != nullptr && !complextype)
                *d_float -= static_cast<float>(val);
            else
                throw invalid_argument("Subtraction not allowed in to different types");
        }

        void operator-=(char val) const
        {

            if (d_int != nullptr && !complextype)
                *d_int -= static_cast<int>(val);
            else if (d_float != nullptr && !complextype)
                *d_float -= static_cast<float>(val);
            else if (d_double != nullptr && !complextype)
                *d_double -= static_cast<double>(val);
            else
                throw invalid_argument("Subtraction not allowed in char type");
        }

        void operator*=(int val)
        {
            if (d_int != nullptr)
                *d_int *= val;

            else if (d_float != nullptr && !complextype)
                *d_float *= static_cast<float>(val);
            else if (d_double != nullptr && !complextype)
                *d_double *= static_cast<double>(val);
            else
                throw invalid_argument("Multiplication not allowed in to different types");
        }

        void operator*=(float val)
        {
            if (d_float != nullptr)
                *d_float *= val;
            else if (d_int != nullptr && !complextype)
                *d_int *= static_cast<int>(val);
            else if (d_double != nullptr && !complextype)
                *d_double *= static_cast<double>(val);
            else
                throw invalid_argument("Multiplication not allowed in to different types");
        }

        void operator*=(double val)
        {
            if (d_double != nullptr)
                *d_double *= val;
            else if (d_int != nullptr && !complextype)
                *d_int *= static_cast<int>(val);
            else if (d_float != nullptr && !complextype)
                *d_float *= static_cast<float>(val);
            else
                throw invalid_argument("Multiplication not allowed in to different types");
        }

        void operator*=(char val) const
        {
            if (d_int != nullptr && !complextype)
                *d_int *= static_cast<int>(val);
            else if (d_float != nullptr && !complextype)
                *d_float *= static_cast<float>(val);
            else if (d_double != nullptr && !complextype)
                *d_double *= static_cast<double>(val);
            else
                throw invalid_argument("Multiplication not allowed in char type");
        }

        void operator/=(int val)
        {
            if (d_int != nullptr)
                *d_int /= val;
            else if (d_float != nullptr && !complextype)
                *d_float /= static_cast<float>(val);
            else if (d_double != nullptr && !complextype)
                *d_double /= static_cast<double>(val);
            else
                throw invalid_argument("Division not allowed in to different types");
        }

        void operator/=(float val)
        {
            if (d_float != nullptr)
                *d_float /= val;
            else if (d_int != nullptr && !complextype)
                *d_int /= static_cast<int>(val);
            else if (d_double != nullptr && !complextype)
                *d_double /= static_cast<double>(val);
            else
                throw invalid_argument("Division not allowed in to different types");
        }

        void operator/=(double val)
        {
            if (d_double != nullptr)
                *d_double /= val;
            else if (d_int != nullptr && !complextype)
                *d_int /= static_cast<int>(val);
            else if (d_float != nullptr && !complextype)
                *d_float /= static_cast<float>(val);
            else
                throw invalid_argument("Division not allowed in to different types");
        }

        void operator/=(char val)
        {
            if (d_int != nullptr && !complextype)
                *d_int /= static_cast<int>(val);
            else if (d_float != nullptr && !complextype)
                *d_float /= static_cast<float>(val);
            else if (d_double != nullptr && !complextype)
                *d_double /= static_cast<double>(val);
            else
                throw invalid_argument("Division not allowed in char type");
        }

        void operator%=(int val)
        {
            if (d_int != nullptr)
                *d_int %= val;
            else
                throw invalid_argument("Modulus not allowed in to different types");
        }

        void operator^=(int val)
        {
            if (d_int != nullptr)
                *d_int = pow(*d_int, val);
            else if (d_float != nullptr && !complextype)
                *d_float = pow(*d_float, static_cast<float>(val));
            else if (d_double != nullptr && !complextype)
                *d_double = pow(*d_double, static_cast<double>(val));
            else
                throw invalid_argument("Exponentiation not allowed in to different types");
        }

        void operator^=(float val)
        {
            if (d_float != nullptr)
                *d_float = pow(*d_float, val);
            else if (d_int != nullptr && !complextype)
                *d_int = pow(*d_int, static_cast<int>(val));
            else if (d_double != nullptr && !complextype)
                *d_double = pow(*d_double, static_cast<double>(val));
            else
                throw invalid_argument("Exponentiation not allowed in to different types");
        }

        void operator^=(double val)
        {
            if (d_double != nullptr)
                *d_double = pow(*d_double, val);
            else if (d_int != nullptr && !complextype)
                *d_int = pow(*d_int, static_cast<int>(val));
            else if (d_float != nullptr && !complextype)
                *d_float = pow(*d_float, static_cast<float>(val));
            else
                throw invalid_argument("Exponentiation not allowed in to different types");
        }

        void operator^=(char val) const
        {
            if (d_int != nullptr && !complextype)
                *d_int = pow(*d_int, static_cast<int>(val));
            else if (d_float != nullptr && !complextype)
                *d_float = pow(*d_float, static_cast<float>(val));
            else if (d_double != nullptr && !complextype)
                *d_double = pow(*d_double, static_cast<double>(val));
            else
                throw invalid_argument("Exponentiation not allowed in char type");
        }

        ~dynamic() = default;
    };

};
#endif // PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_DYNAMIC_HPP