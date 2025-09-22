#pragma once
#ifndef PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_LAB_CXXVECTOR_HPP
#define PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_LAB_CXXVECTOR_HPP
#include "vector_functions.hpp"
#include "pair_vector.hpp"
#include "multidimensional_vectors.hpp"
namespace uvt
{
    template <typename T>
    /**
     * @class vstream
     * @brief A class that provides stream-like operations for a vector of type T.
     * This class allows for easy insertion and extraction of elements,
     * as well as various utility functions to manage the underlying vector.
     */
    class vstream
    {
    private:
        std::vector<T> vs;

    public:
        /** Default constructor */
        vstream() = default;
        /** Constructor from std::vector
         * @param vec The vector to initialize the stream with
         * @note This constructor copies the vector
         */
        vstream(const std::vector<T> &vec) noexcept : vs(vec) {}
        /** Constructor from rvalue std::vector
         * @param vec The vector to initialize the stream with
         * @note This constructor moves the vector
         */
        vstream(std::vector<T> &&vec) noexcept : vs(std::move(vec)) {}
        /**
         * Constructor from initializer list
         * @param il The initializer list to initialize the stream with
         * @note This constructor copies the elements from the initializer list
         */
        vstream(std::initializer_list<T> il) noexcept : vs(il) {}
        /**
         * Copy constructor
         * @param other The other vstream to copy from
         * @note This constructor copies the underlying vector
         */
        vstream(const vstream &other) noexcept : vs(other.vs) {}
        /**
         * Move constructor
         * @param other The other vstream to move from
         * @note This constructor moves the underlying vector
         */
        vstream(vstream &&other) noexcept : vs(std::move(other.vs)) {}
        /**
         * @brief Returns the number of elements in the vector.
         *
         * @return The current size of the vector.
         * @note This function does not throw exceptions.
         */
        size_t size() const noexcept
        {
            return vs.size();
        }
        /**
         * @brief Checks whether the container is empty.
         *
         * @return true if the container contains no elements, false otherwise.
         * @note This function does not throw exceptions.
         */
        bool empty() const noexcept
        {
            return vs.empty();
        }
        /**
         * @brief Removes all elements from the container.
         *
         * After calling this function, the container will be empty.
         * No exceptions are thrown.
         */
        void clear() noexcept
        {
            vs.clear();
        }
        /**
         * @brief Returns the number of elements that the vector can hold without reallocating.
         *
         * @return The current capacity of the underlying vector.
         * @note This function does not throw exceptions.
         */
        size_t capacity() const noexcept
        {
            return vs.capacity();
        }
        /**
         * @brief Copy assignment operator for vstream.
         *
         * Assigns the contents of another vstream object to this one.
         * Performs a self-assignment check before copying the internal state.
         *
         * @param other The vstream object to copy from.
         * @return Reference to this vstream object.
         * @note This operator is marked noexcept.
         */
        vstream &operator=(const vstream &other) noexcept
        {
            if (this != &other)
                vs = other.vs;
            return *this;
        }
        /**
         * @brief Move assignment operator for the vstream class.
         *
         * Transfers ownership of resources from another vstream instance to this instance.
         * If the source and destination are not the same object, the internal stream (vs)
         * is moved from the source to this object, leaving the source in a valid but unspecified state.
         *
         * @param other The vstream instance to move from.
         * @return Reference to this vstream instance.
         */
        vstream &operator=(vstream &&other) noexcept
        {
            if (this != &other)
                vs = std::move(other.vs);
            return *this;
        }
        /**
         * @brief Assignment operator from std::vector.
         *
         * Assigns the contents of the given std::vector<T> to the internal vector 'vs'.
         *
         * @param vec The std::vector<T> whose contents will be copied.
         * @note This operation is noexcept.
         */
        void operator=(const std::vector<T> &vec) noexcept
        {
            vs = vec;
        }
        /**
         * @brief Move assignment operator from a std::vector<T>.
         *
         * Replaces the contents of the internal vector 'vs' with those of the given rvalue reference 'vec',
         * transferring ownership of the data without copying.
         *
         * @param vec Rvalue reference to a std::vector<T> whose contents will be moved.
         * @note This operation is noexcept and leaves 'vec' in a valid but unspecified state.
         */
        void operator=(std::vector<T> &&vec) noexcept
        {
            vs = std::move(vec);
        }
        /**
         * @brief Assignment operator for assigning an initializer list to the container.
         *
         * Replaces the contents of the container with the elements from the given initializer list.
         * This operation is noexcept.
         *
         * @param il The initializer list whose elements will be assigned to the container.
         */
        void operator=(std::initializer_list<T> il) noexcept
        {
            vs = il;
        }
        /**
         * @brief Inserts a value into the vector stream.
         *
         * This operator overload allows values of type T to be appended to the internal vector (vs)
         * using the stream insertion syntax. It returns a reference to the current vstream object,
         * enabling chaining of multiple insertions.
         *
         * @param value The value to be inserted into the vector stream.
         * @return Reference to the current vstream object.
         */
        vstream &operator<<(const T &value)
        {
            vs.push_back(value);
            return *this;
        }
        /**
         * @brief Inserts a value into the vector stream using move semantics.
         *
         * This operator overload allows an rvalue of type T to be added to the internal vector
         * by moving the value, which can improve performance by avoiding unnecessary copies.
         *
         * @param value The rvalue reference to the value of type T to be inserted.
         * @return Reference to the current vstream object to allow chaining.
         */
        vstream &operator<<(T &&value) noexcept
        {
            vs.push_back(std::move(value));
            return *this;
        }
        /**
         * @brief Extracts the last element from the internal vector and assigns it to the provided value.
         *
         * This operator overload removes the last element from the internal vector `vs` and assigns it to `value`.
         * If the vector is empty, it throws a `std::out_of_range` exception.
         *
         * @tparam T The type of the elements stored in the vector.
         * @param value Reference to the variable where the extracted value will be stored.
         * @return Reference to the current vstream object.
         * @throws std::out_of_range if the internal vector is empty.
         */
        vstream &operator>>(T &value)
        {
            if (!vs.empty())
            {
                value = std::move(vs.back());
                vs.pop_back();
            }
            else
                throw std::out_of_range("vstream is empty");
            return *this;
        }
        /**
         * @brief Accesses the element at the specified index with bounds checking.
         *
         * @param index The position of the element to access.
         * @return const T& A constant reference to the element at the specified index.
         * @throws std::out_of_range If the index is out of the valid range.
         */
        const T &operator[](size_t index) const
        {
            if (index >= vs.size())
                throw std::out_of_range("Index out of range");
            return vs[index];
        }
        /**
         * @brief Accesses the element at the specified index with bounds checking.
         */
        ~vstream() = default;
    };
}
#endif // PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_LAB_CXXVECTOR_HPP