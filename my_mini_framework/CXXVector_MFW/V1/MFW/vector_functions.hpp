#pragma once
#ifndef PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_VECTOR_TOOLS_HPP
#define PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_VECTOR_TOOLS_HPP
#include <type_traits>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>
namespace uvt
{
    /**
     * Reverses a vector of any type.
     * @param dynvec: The input vector to reverse.
     * @return A new vector containing the elements in reverse order.
     * @throws VectorEmptyException if the input vector is empty.
     */
    template <typename T>
    std::vector<T> reverse_v(const std::vector<T> &dynvec)
    {
        if (dynvec.empty())
            throw std::runtime_error("Empty Error");
        std::vector<T> result;
        for (int i = dynvec.size() - 1; i >= 0; i--)
            result.push_back(dynvec[i]);
        return result;
    }
    /**
     * reverses a 2D vector (vector of vectors) of any type.
     * @param dynvec: The input 2D vector to reverse.
     * @throw runtime_error if the input vector is empty.
     * @return A new 2D vector containing the elements in reverse order.
     */
    template <typename T>
    std::vector<std::vector<T>> reverse_v(const std::vector<std::vector<T>> &dynvec)
    {
        if (dynvec.empty())
            throw std::runtime_error("Empty Error");
        std::vector<std::vector<T>> result;
        for (int i = dynvec.size() - 1; i >= 0; i--)
            result.push_back(reverse_v(dynvec[i]));
        return result;
    }
    /**
     * reverses a 3D vector (vector of vector of vectors) of any type.
     * @param dynvec: The input 3D vector to reverse.
     * @throw runtime_error if the input vector is empty.
     * @return A new 3D vector containing the elements in reverse order.
     */
    template <typename T>
    std::vector<std::vector<std::vector<T>>> reverse_v(const std::vector<std::vector<std::vector<T>>> &dynvec)
    {
        if (dynvec.empty())
            throw std::runtime_error("Empty Error");
        std::vector<std::vector<std::vector<T>>> result;
        for (int i = dynvec.size() - 1; i >= 0; i--)
            result.push_back(reverse_v(dynvec[i]));
        return result;
    }
    /**
     * Generates the Fibonacci sequence from F(0) to F(n).
     * @param terms The index n of the last Fibonacci number to include (inclusive).
     * @return A vector containing F(0) to F(n), with (terms + 1) elements.
     */
    std::vector<long long> FibonacciSequence(short terms)
    {
        if (terms <= 0)
            return {};
        if (terms == 1)
            return {0};
        if (terms == 2)
            return {0, 1};
        std::vector<long long> Fibonacci = {0, 1};
        for (short i = 2; i <= terms; i++)
        {
            if (Fibonacci[i - 1] > LLONG_MAX - Fibonacci[i - 2])
                throw std::overflow_error("Fibonacci value exceeds long long capacity");
            Fibonacci.push_back(Fibonacci[i - 1] + Fibonacci[i - 2]);
        }
        return Fibonacci;
    }
    /**
     * Returns the index of the last element in the vector.
     * @param vec The input vector.
     * @return Index of the last element (vec.size() - 1), or -1 if the vector is
     * empty.
     */
    template <typename T>
    size_t v_end(const std::vector<T> &vec)
    {
        if (vec.empty())
            throw std::runtime_error("Empty Error");
        return vec.size() - 1;
    }
    /**
     * Compares two vectors element by element to check if they are identical in
     * content and order.
     * @param vec1 The first vector.
     * @param vec2 The second vector.
     * @return true if the vectors have the same size and elements in the same
     * order; false otherwise.
     */
    template <typename T>
    bool same_v(const std::vector<T> &vec1, const std::vector<T> &vec2)
    {
        if (vec1.empty() && vec2.empty())
            return true;
        if (vec1.size() != vec2.size())
            return false;
        for (int i = 0; i < vec2.size(); i++)
        {
            if (vec2[i] != vec1[i])
                return false;
        }
        return true;
    }
    /**
     * @brief Returns a subvector from the given vector within the specified range.
     *
     * This function extracts a subvector from the input vector `v`, starting from index `start` and ending at index `end` (inclusive).
     *
     * @tparam T The type of elements in the vector.
     * @param v The input vector from which to extract the subvector.
     * @param start The starting index of the subvector (inclusive).
     * @param end The ending index of the subvector (inclusive).
     * @return std::vector<T> The resulting subvector containing elements from `start` to `end`.
     *
     * @throws std::invalid_argument If the input vector is empty.
     * @throws std::out_of_range If `start` is less than 0 or `end` is greater than the last valid index of the vector.
     */
    template <typename T>
    std::vector<T> sub_v(const std::vector<T> &v, int start, int end)
    {
        if (v.empty())
            throw std::invalid_argument("Empty Error: the vector is empty no sub vector can be generate");
        if (start < 0 || end > v_end(v))
            throw std::out_of_range("the start or end is out of range of vector");
        std::vector<T> result_v;
        for (int i = start; i <= end; i++)
            result_v.push_back(v[i]);
        return result_v;
    }
    /**
     * @brief Extracts a submatrix from a 2D vector based on start and end indices for each dimension.
     *
     * This function generates a subvector (submatrix) from a given 2D vector `v`, using the provided
     * `start_v` and `end_v` vectors to specify the start and end indices for each dimension.
     * It recursively applies the subvector extraction for each dimension.
     *
     * @tparam T The type of the elements in the 2D vector.
     * @param v The input 2D vector from which to extract the submatrix.
     * @param start_v A vector of start indices for each dimension.
     * @param end_v A vector of end indices for each dimension (exclusive).
     * @return A submatrix of `v` defined by the specified ranges.
     *
     * @throws std::invalid_argument If the input vector `v` is empty.
     * @throws std::out_of_range If the start or end indices are out of range, or if the size of `start_v`
     *         does not match the dimensions of the result.
     */
    template <typename T>
    std::vector<std::vector<T>> sub_v(const std::vector<std::vector<T>> &v, const std::vector<int> &start_v, const std::vector<int> &end_v)
    {
        if (v.empty())
            throw std::invalid_argument("Empty Error: the vector is empty no sub vector can be generate");
        if (start_v[0] < 0 || end_v[0] > v.size())
            throw std::out_of_range("the start or end is out of range of vector");
        auto result = sub_v<std::vector<T>>(v, start_v[0], end_v[0]);
        if (result.size() + 1 != start_v.size())
            throw std::out_of_range("the start vector can\'n fit the size of the result");
        for (int i = 0; i < result.size(); i++)
            sub_v<T>(result[i], start_v[i + 1], end_v[i + 1]);
        return result;
    }
    /**
     * @brief Removes a row from a 2D vector at the specified index.
     *
     * @tparam T The type of the elements in the 2D vector.
     * @param v The input 2D vector from which a row will be removed.
     * @param index The zero-based index of the row to remove.
     * @return A new 2D vector with the specified row removed.
     * @throws std::out_of_range If the index is out of bounds (less than 0 or greater than or equal to the vector size).
     */
    template <typename T>
    std::vector<std::vector<T>> erase_row(const std::vector<std::vector<T>> &v, int index)
    {
        if (index > v.size() || index < 0)
            throw std::out_of_range("the vector erase index is begger than the vector size or is equal or less than zero");
        std::vector<std::vector<T>> result;
        for (int i = 0; i < v.size(); i++)
        {
            if (i == index)
                continue;
            result.push_back(v[i]);
        }
        return result;
    }
    /**
     * @brief Removes a specified column from a 2D vector.
     *
     * This function creates and returns a new 2D vector with the column at the given index removed from each row.
     * If a row does not have enough columns (i.e., its size is less than or equal to the specified index), that row is skipped.
     *
     * @tparam T The type of the elements in the 2D vector.
     * @param v The input 2D vector from which a column will be removed.
     * @param index The zero-based index of the column to remove.
     * @return std::vector<std::vector<T>> A new 2D vector with the specified column removed from each row.
     *
     * @throws std::invalid_argument If the input vector is empty.
     * @throws std::out_of_range If the index is negative.
     *
     * @note If no columns are erased due to incorrect indexing, a message is printed to std::cout.
     */
    template <typename T>
    std::vector<std::vector<T>> erase_column(const std::vector<std::vector<T>> &v, int index)
    {
        if (v.empty())
            throw std::invalid_argument("Empty Error");
        if (index < 0)
            throw std::out_of_range("the index is less then or equal to zero");
        std::vector<std::vector<T>> result_v;
        int erase_count = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].size() < index)
                continue;
            result_v.push_back({});
            for (int j = 0; j < v[i].size(); j++)
            {
                if (j != index)
                    result_v[i].push_back(v[i][j]);
            }
            erase_count++;
        }
        if (erase_count == 0)
            std::cout << "nothing was erase form the vector due to incorrect indexing" << std::endl;
        return result_v;
    }
    /**
     * @brief Removes the specified row and column from a 2D vector.
     *
     * This function creates a new 2D vector by removing the row at index `i` and the column at index `j`
     * from the input vector `v`. The original vector is not modified.
     *
     * @tparam T The type of the elements in the 2D vector.
     * @param v The input 2D vector from which a row and a column will be removed.
     * @param i The index of the row to remove.
     * @param j The index of the column to remove.
     * @return A new 2D vector with the specified row and column removed.
     *
     * @throws std::invalid_argument If the input vector is empty.
     * @throws std::out_of_range If the row index `i` is out of range.
     *
     * @note This function depends on the existence of `erase_row` and `erase_column` helper functions.
     */
    template <typename T>
    std::vector<std::vector<T>> erase_row_column(const std::vector<std::vector<T>> &v, int i, int j)
    {
        if (v.empty())
            throw std::invalid_argument("Empty Error");
        if (i < 0 || i > v.size())
            throw std::out_of_range("the indexing is out of rang vector passed to the function");
        std::vector<std::vector<T>> result_v = erase_row<T>(v, i);
        return erase_column<T>(result_v, j);
    }
}
#endif // PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_VECTOR_TOOLS_HPP