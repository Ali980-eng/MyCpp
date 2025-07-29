#ifndef PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_VECTOR_TOOLS_HPP
#define PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_VECTOR_TOOLS_HPP
/* Vector Structures Library Documentation (Version 1.0)
    - Ali Mohammed Ali Lafi, Founder and Lead Developer
    - Introduction
        The Vector Structures Library is a comprehensive C++
        solution developed by You (the founder and lead developer)
        for advanced multi-dimensional data handling.
        Designed for computational mathematics,
        scientific computing, and data analysis applications,
        this library provides robust implementations of essential
        vector and matrix structures with specialized operations.
    - Core Objects
        1. vector_2d<T>
            Purpose: Advanced 2D matrix operations
            Key Features:
            Matrix property checks:
            Square (2x2, 3x3, NxN)
            Diagonal, identity, triangular
            Upper/lower triangular
            Matrix operations:
            Determinant calculation (2x2, 3x3)
            Transposition
            Flattening to 1D
            Memory-efficient storage
            Size validation and bounds checking
        2. vector_3d<T>
            Purpose: 3D tensor operations
            Key Features:
            Three-dimensional storage:
            Depth (w), Rows (n), Columns (m)
            Dimension transformations:
            3D to 2D flattening
            Dimension transposition
            Slice-wise operations:
            Per-layer determinant calculation
            Depth-wise access
            Multi-dimensional size management
        3. VecPair<T>
            Purpose: Paired vector operations
            Key Features:
            Dual-vector storage:
            Primary vectors (vec1, vec2)
            Auto-generated reverses (vec1_rev, vec2_rev)
            Paired operations:
            Synchronized mathematical operations
            Element-wise arithmetic
            Cross-vector comparisons
            Symmetry operations:
            Vector swapping
            Reversed vector access
        4. VecList<T> (Planned for V2)
            Purpose: Dynamic vector collections
            Planned Features:
            Collection management
            Batch operations
            Vector relationship analysis
            Set operations
    - Technical Specifications
        Language: Modern C++ (C++17 features)
        Templates: Full template support for numeric types
        Error Handling: Comprehensive exception system
        Memory: Efficient STL-based storage
        Operations: 150+ specialized functions
    - Version Information
        Version: 1.0 (Initial Release)
        Release Date: July 2025
        Author: You (The Founder)
        Design Philosophy:
        Balance between computational efficiency and developer ergonomics
*/
#include <cmath>
#include <type_traits>

#include "InOut.hpp"
namespace vt
{
    using std::vector, std::string, std::initializer_list, std::swap,
        std::overflow_error, std::runtime_error, std::invalid_argument,
        std::out_of_range, std::is_arithmetic, std::cout, std::endl, std::cerr;
    /**
     * @brief Checks if a type is a numeric type (int, float, double, etc.).
     * This is used to ensure that operations are performed only on numeric types.
     * This is a type trait that can be used in template metaprogramming.
     */
    template <typename T>
    struct is_numeric_type : std::is_arithmetic<T>
    {
    };
    /**
     * Reverses a vector of any type.
     * @param dynvec: The input vector to reverse.
     * @return A new vector containing the elements in reverse order.
     * @throws VectorEmptyException if the input vector is empty.
     */
    template <typename T>
    vector<T> reverse_vec(const vector<T> &dynvec)
    {
        if (dynvec.empty())
        {
            io::println_error("The vector is empty");
            throw("Empty Error");
        }
        vector<T> result;
        for (int i = dynvec.size() - 1; i >= 0; i--)
            result.push_back(dynvec[i]);
        return result;
    }
    /**
     * Generates the Fibonacci sequence from F(0) to F(n).
     * @param terms The index n of the last Fibonacci number to include (inclusive).
     * @return A vector containing F(0) to F(n), with (terms + 1) elements.
     */
    vector<long long> FibonacciSequence(short terms)
    {
        if (terms <= 0)
            return {};
        if (terms == 1)
            return {0};
        if (terms == 2)
            return {0, 1};
        vector<long long> Fibonacci = {0, 1};
        for (short i = 2; i <= terms; i++)
        {
            if (Fibonacci[i - 1] > LLONG_MAX - Fibonacci[i - 2])
                throw overflow_error("Fibonacci value exceeds long long capacity");
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
    int vec_end(const vector<T> &vec)
    {
        if (vec.empty())
            throw("Empty Error");
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
    bool same_vec(const vector<T> &vec1, const vector<T> &vec2)
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
     * @brief Performs Gauss-Jordan elimination on a given augmented matrix.
     *
     * This function transforms the input augmented matrix `mat` into its reduced
     * row echelon form (RREF). It is typically used to solve systems of linear
     * equations.
     *
     * @param mat The augmented matrix represented as a vector of vectors of
     * doubles. Each row should have n+1 elements for a system of n equations (n
     * variables + 1 constant).
     * @param status Reference to an integer that will be set to indicate the result
     * of the elimination:
     *        - 0: Successful elimination, unique solution found.
     *        - 1: Matrix is singular (no unique solution).
     *        - 2: Infinite solutions exist.
     *        - 3: No solution exists.
     *
     * @return The matrix in reduced row echelon form after elimination.
     *
     * @throws invalid_argument if the input matrix is empty.
     *
     * @note The input matrix is modified and returned in its transformed state.
     */
    vector<vector<double>> gauss_jordan(vector<vector<double>> mat, int &status)
    {
        if (mat.empty())
        {
            io::println_error(
                "EmptyMatrixError: Cannot perform Gauss-Jordan elimination on empty "
                "matrix");
            throw invalid_argument("Empty matrix");
        }
        int n = static_cast<int>(mat.size());
        status = 0;
        for (int i = 0; i < n; i++)
        {
            if (mat[i][i] == 0)
            {
                int c = 1;
                while ((i + c) < n && mat[i + c][i] == 0)
                    c++;
                if ((i + c) == n)
                {
                    status = 1;
                    break;
                }
                swap(mat[i], mat[i + c]);
            }
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    double pro = mat[j][i] / mat[i][i];
                    for (int k = 0; k <= n; k++)
                        mat[j][k] -= mat[i][k] * pro;
                }
            }
        }
        if (status == 1)
        {
            status = 3;
            for (int i = 0; i < n; i++)
            {
                double sum = 0;
                for (int j = 0; j < n; j++)
                    sum += mat[i][j];
                if (sum == mat[i][n])
                    status = 2;
            }
        }
        return mat;
    }
    /**
     * A generic 2D vector wrapper that provides utilities for:
     * - shape checking (square or NxM),
     * - flattening,
     * - transposition,
     * - accessors for rows and internal states.
     *
     * @tparam T Type of elements stored (int, float, string, etc.)
     */
    template <typename T>
    class vector_2d
    {
        /*///////////////////private members/////////////////////
        ///////////////////////////////////////////////////////*/
    private:
        int n = -1, m = -1;
        vector<vector<T>> vec_2D;
        vector<vector<T>> transpose_2D;
        vector<T> flatten_vec;
        /*///////////////////protected members/////////////////////
        /////////////////////////////////////////////////////////*/
        /**
         * Determines if the target matrix is a fixed 2x2 square matrix
         *
         * The function checks either:
         *   - The internal 2D vector (member `vec_2D`) when no argument is provided,
         * or
         *   - The provided 2D vector `vec` when passed as an argument
         *
         * @param vec Optional external 2D vector to evaluate (uses internal vector if
         * empty)
         * @return `true` if the matrix has exactly 2 rows and each row contains
         * exactly 2 columns, `false` otherwise
         */
        bool square2X2(const vector<vector<T>> &vec = {})
        {
            const auto &target = vec.empty() ? vec_2D : vec;
            if (target.size() != 2)
                return false;
            return target[0].size() == 2 && target[1].size() == 2;
        }
        /**
         * Determines if the target matrix is a fixed 3x3 square matrix
         *
         * Evaluates either:
         *   - The internal 2D vector (member `vec_2D`) when no argument is provided,
         * or
         *   - The provided 2D vector `vec` when specified
         *
         * @param vec Optional external matrix to check (defaults to internal vector
         * if empty)
         * @return `true` if the matrix has exactly 3 rows and each row contains
         * exactly 3 columns, `false` otherwise
         */
        bool square3X3(const vector<vector<T>> &vec = {})
        {
            const auto &target = vec.empty() ? vec_2D : vec;
            if (target.size() != 3)
                return false;
            return target[0].size() == 3 && target[1].size() == 3 &&
                   target[2].size() == 3;
        }
        /**
         * Verifies if the target matrix is an N×N square matrix
         *
         * Checks either:
         *   - The internal 2D vector (member `vec_2D`) when no argument is provided,
         * or
         *   - The provided 2D vector `vec` when specified
         *
         * @param vec Optional external matrix to evaluate (uses internal vector if
         * empty)
         * @return `true` if the matrix is square (all rows have same length as total
         * rows), `false` otherwise
         */
        bool squareNXN(const vector<vector<T>> &vec = {})
        {
            const auto &target = vec.empty() ? vec_2D : vec;
            for (const auto &row : target)
            {
                if (row.size() != target.size())
                    return false;
            }
            return true;
        }
        /**
         * Determines if the internal matrix matches specified n×m dimensions
         *
         * Checks if the 2D vector has exactly `nnum` rows and each row contains
         * exactly `mnum` columns. This only evaluates the internal member `vec_2D`.
         *
         * @param nnum Expected number of rows (first dimension)
         * @param mnum Expected number of columns (second dimension)
         * @return `true` if matrix dimensions exactly match n×m, `false` otherwise
         */
        bool isNXM(int nnum, int mnum)
        {
            if (vec_2D.size() == nnum)
            {
                for (int i = 0; i < vec_2D.size(); i++)
                {
                    if (vec_2D[i].size() != mnum)
                        return false;
                }
                return true;
            }
            return false;
        } // end of isNXM
        /**
         * Determines if the target matrix is a square matrix of any valid size
         *
         * Checks for square matrices of either:
         *   - Standard sizes (2×2, 3×3, or N×N) on internal `vec_2D` when no argument
         * is provided
         *   - Standard sizes (2×2, 3×3, or N×N) on provided matrix `mat` when
         * specified
         *
         * @param mat Optional external matrix to evaluate (uses internal vector if
         * empty)
         * @return `true` if the matrix is square (2×2, 3×3, or general N×N), `false`
         * otherwise
         */
        bool is_square_matrix(const vector<vector<T>> &mat = {})
        {
            if (mat.empty())
                return square2X2() || square3X3() || squareNXN();
            return square2X2(mat) || square3X3(mat) || squareNXN(mat);
        }
        /**
         * Determines if the target matrix is a diagonal matrix
         *
         * A diagonal matrix is a square matrix where all elements outside
         * the main diagonal are zero. The function checks either:
         *   - The internal member `vec_2D` when no argument is provided, or
         *   - The provided matrix `mat` when specified
         *
         * @param mat Optional external matrix to evaluate (uses internal matrix if
         * empty)
         * @return `true` if:
         *           - The matrix is square, AND
         *           - All non-diagonal elements are zero
         *         `false` otherwise
         */
        bool is_diagonal_matrix(const vector<vector<T>> &mat = {})
        {
            const auto &target = mat.empty() ? vec_2D : mat;
            if (!is_square_matrix(target))
                return false;
            size_t n = target.size();
            for (size_t i = 0; i < n; ++i)
            {
                for (size_t j = 0; j < n; ++j)
                {
                    if (i != j && target[i][j] != T(0))
                        return false;
                }
            }
            return true;
        }
        /**
         * Determines if the target matrix is an identity matrix
         *
         * An identity matrix is a square matrix where:
         *   - All main diagonal elements are 1, AND
         *   - All other elements are 0
         *
         * The function evaluates either:
         *   - The internal member `vec_2D` when no argument is provided, OR
         *   - The provided matrix `mat` when specified
         *
         * @param mat Optional external matrix to evaluate (defaults to internal
         * matrix if empty)
         * @return `true` if:
         *           - The matrix is square, AND
         *           - All diagonal elements equal 1, AND
         *           - All non-diagonal elements equal 0
         *         `false` otherwise
         */
        bool is_identity_matrix(const vector<vector<T>> &mat = {})
        {
            const auto &target = mat.empty() ? vec_2D : mat;
            if (!is_square_matrix(target))
                return false;
            size_t n = target.size();
            for (size_t i = 0; i < n; ++i)
            {
                for (size_t j = 0; j < n; ++j)
                {
                    if ((i == j && target[i][j] != T(1)) ||
                        (i != j && target[i][j] != T(0)))
                        return false;
                }
            }
            return true;
        }
        /**
         * Determines if the target matrix is an upper triangular matrix
         *
         * An upper triangular matrix is a square matrix where:
         *   - All elements below the main diagonal are zero
         *   - Elements on or above the diagonal may be any value
         *
         * The function evaluates either:
         *   - The internal member `vec_2D` when no argument is provided, or
         *   - The provided matrix `mat` when specified
         *
         * @param mat Optional external matrix to evaluate (defaults to internal
         * matrix if empty)
         * @return `true` if:
         *           - The matrix is square, AND
         *           - All elements below the main diagonal are zero
         *         `false` otherwise
         */
        bool is_upper_triangular(const vector<vector<T>> &mat = {})
        {
            const auto &target = mat.empty() ? vec_2D : mat;
            if (!is_square_matrix(target))
                return false;
            size_t n = target.size();
            for (size_t i = 1; i < n; ++i)
            {
                for (size_t j = 0; j < i; ++j)
                {
                    if (target[i][j] != T(0))
                        return false;
                }
            }
            return true;
        }
        /**
         * Determines if the target matrix is a lower triangular matrix
         *
         * A lower triangular matrix is a square matrix where:
         *   - All elements above the main diagonal are zero
         *   - Elements on or below the diagonal may be any value
         *
         * @param mat Optional external matrix to evaluate (uses internal matrix if
         * empty)
         * @return `true` if:
         *           - The matrix is square, AND
         *           - All elements above the main diagonal are zero
         *         `false` otherwise
         */
        bool is_lower_triangular(const vector<vector<T>> &mat = {})
        {
            const auto &target = mat.empty() ? vec_2D : mat;
            if (!is_square_matrix(target))
                return false;
            size_t n = target.size();
            for (size_t i = 0; i < n - 1; ++i)
            {
                for (size_t j = i + 1; j < n; ++j)
                {
                    if (target[i][j] != T(0))
                        return false;
                }
            }
            return true;
        } // end of lower triangluar
        /**
         * Identifies the specific type of matrix
         *
         * Tests the matrix against known matrix types in this order:
         *   1. Identity Matrix
         *   2. Diagonal Matrix
         *   3. Upper Triangular Matrix
         *   4. Lower Triangular Matrix
         *   5. Square Matrix (generic)
         *
         * @param mat Optional external matrix to evaluate (uses internal matrix if
         * empty)
         * @return String name of the matrix type or "Unknown Form" if no match found
         */
        string matrix_type(const vector<vector<T>> &mat = {})
        {
            const auto &target = mat.empty() ? vec_2D : mat;
            if (is_identity_matrix(target))
                return "Identity Matrix";
            if (is_diagonal_matrix(target))
                return "Diagonal Matrix";
            if (is_upper_triangular(target))
                return "Upper Triangular Matrix";
            if (is_lower_triangular(target))
                return "Lower Triangular Matrix";
            return is_square_matrix(target) ? "Square Matrix" : "Unknown Form";
        } // end of matrix type
        /**
         * Calculates the determinant of a 2×2 matrix
         *
         * @param vec Optional external matrix (uses internal matrix if empty)
         * @return The determinant value as long double
         * @throws When:
         *           - The matrix is empty, OR
         *           - The matrix is not 2×2
         */
        long double determinant2X2(const vector<vector<T>> &vec = {})
        {
            const auto &target = vec.empty() ? vec_2D : vec;
            if (target.empty())
                throw invalid_argument("Empty matrix");
            if (!square2X2(target))
                throw invalid_argument("Matrix is not 2x2");
            return (target[0][0] * target[1][1] - target[0][1] * target[1][0]);
        } // end of determinant2X2
        /**
         * Calculates the determinant of a 3×3 matrix using Rule of Sarrus
         *
         * @param vec Optional external matrix (uses internal matrix if empty)
         * @return The determinant value as long double
         * @throws When:
         *           - The matrix is empty, OR
         *           - The matrix is not 3×3
         */
        long double determinant3X3(const vector<vector<T>> &vec = {})
        {
            const auto &target = vec.empty() ? vec_2D : vec;
            if (target.empty())
            {
                io::println_error("empty vector hasn't determinant");
                throw invalid_argument("Empty matrix");
            }
            if (!square3X3(target))
                throw invalid_argument("Matrix is not 3x3");
            return (target[0][0] *
                        (target[1][1] * target[2][2] - target[2][1] * target[1][2]) -
                    target[0][1] *
                        (target[1][0] * target[2][2] - target[2][0] * target[1][2]) +
                    target[0][2] *
                        (target[1][0] * target[2][1] - target[2][0] * target[1][1]));
        } // end of determinant3X3
        /**
         * Calculates the determinant of an N×N matrix using Gaussian elimination with
         * partial pivoting
         * @param vec Optional external matrix (uses internal matrix if empty)
         * @return The determinant value as long double
         * @throws invalid_argument if:
         *          - The matrix is empty
         *          - The matrix is not square
         */
        long double determinantNXN(const vector<vector<T>> &vec = {})
        {
            const auto &target_ref = vec.empty() ? vec_2D : vec;
            if (target_ref.empty())
                throw invalid_argument("Empty matrix");
            if (!squareNXN(target_ref))
                throw invalid_argument("Matrix is not square");
            size_t n = target_ref.size();
            vector<vector<long double>> mat;
            mat.reserve(n);
            // Copy with casting to long double
            for (const auto &row : target_ref)
                mat.emplace_back(row.begin(), row.end());
            long double det = 1.0;
            int swap_count = 0;
            for (size_t i = 0; i < n; ++i)
            {
                // Partial pivoting
                size_t pivot_row = i;
                for (size_t j = i + 1; j < n; ++j)
                {
                    if (abs(mat[j][i]) > abs(mat[pivot_row][i]))
                    {
                        pivot_row = j;
                    }
                }
                // If pivot element is zero, determinant is zero
                if (mat[pivot_row][i] == 0.0)
                    return 0.0;
                // Swap rows if needed
                if (i != pivot_row)
                {
                    swap(mat[i], mat[pivot_row]);
                    ++swap_count;
                }
                // Eliminate below
                for (size_t j = i + 1; j < n; ++j)
                {
                    long double factor = mat[j][i] / mat[i][i];
                    for (size_t k = i; k < n; ++k)
                        mat[j][k] -= mat[i][k] * factor;
                }
            }
            // Multiply diagonal elements
            for (size_t i = 0; i < n; ++i)
                det *= mat[i][i];
            // Adjust sign based on number of swaps
            if (swap_count % 2 != 0)
                det = -det;
            return det;
        }
        /**
         * Flattens a 2D matrix into a 1D vector
         *
         * @param vec Optional external matrix to flatten (uses internal matrix if
         * empty)
         * @note Results are stored in member variable `flatten_vec`
         * @warning Will skip operation if input matrix is empty
         */
        void flatten(const vector<vector<T>> &vec = {})
        {
            const auto &target = vec.empty() ? vec_2D : vec;
            if (target.empty())
            {
                io::println_error("The 2D vector is empty");
                return;
            }
            flatten_vec.clear();
            for (const auto &row : target)
            {
                for (const auto &elem : row)
                {
                    flatten_vec.push_back(elem);
                }
            }
        }
        /**
         * Computes the transpose of a matrix
         *
         * @param vec Optional external matrix to transpose (uses internal matrix if
         * empty)
         * @note Results are stored in member variable `transpose_2D`
         * @warning Will skip operation if input matrix is empty
         */
        void transpose(const vector<vector<T>> &vec = {})
        {
            const auto &target = vec.empty() ? vec_2D : vec;
            if (target.empty() || target[0].empty())
            {
                io::println_error("The 2D vector is empty");
                return;
            }
            transpose_2D.clear();
            transpose_2D.resize(target[0].size(), vector<T>(target.size()));
            for (size_t i = 0; i < target[0].size(); ++i)
            {
                for (size_t j = 0; j < target.size(); ++j)
                {
                    transpose_2D[i][j] = target[j][i];
                }
            }
        }
        /*///////////////////public members/////////////////////
        /////////////////////////////////////////////////////*/
    public:
        /**
         * Default constructor - initializes empty matrices
         *
         * Creates a vector_2d object with:
         *   - vec_2D: Empty 2D vector
         *   - tranvec_2D: Empty transpose vector
         *   - flatten: Empty flattened vector
         */
        vector_2d()
        {
            vec_2D = {};
            transpose_2D = {};
            flatten_vec = {};
        } // end of empty constructor
        /**
         * Square matrix constructor
         *
         * @param num Size for both dimensions (n×n)
         * @throws Error if size ≤ 0
         */
        vector_2d(int num)
        {
            if (num <= 0)
                io::println_error("Size Error: the size have to be greater than zero");
            else
            {
                n = num;
                m = num;
            }
        }
        /**
         * Rectangular matrix constructor
         *
         * @param Nnum Number of rows
         * @param Mnum Number of columns
         * @throws Error if either dimension ≤ 0
         */
        vector_2d(int Nnum, int Mnum)
        {
            if (Nnum <= 0 || Nnum <= 0)
                io::println_error("Size Error: the size have to be greater than zero");
            else
            {
                n = Nnum;
                m = Mnum;
            }
        }
        /**
         * Initializer list constructor
         *
         * @param init Initializer list of vectors to create the matrix
         */
        vector_2d(initializer_list<vector<T>> init) : vec_2D(init)
        {
            size_t nnum, mnum;
            nnum = static_cast<size_t>(vec_2D.size());
            mnum = nnum > 0 ? static_cast<size_t>(vec_2D[0].size()) : -1;
            if (n != -1 && m != -1)
            {
                if (nnum != n || mnum != m)
                {
                    throw runtime_error(
                        "Dimension Error: Initializer list dimensions do not match fixed "
                        "size");
                }
            }
        }
        /**
         * Initializer list constructor with specified number of rows
         * @param init Initializer list of vectors to create the matrix
         * @param num Number of rows (must be > 0)
         */
        vector_2d(size_t num, initializer_list<vector<T>> init) : vec_2D(init)
        {
            if (num > 0)
            {
                n = static_cast<int>(num);
                m = static_cast<int>(vec_2D.size() > 0 ? vec_2D[0].size() : 0);
            }
            else
            {
                io::println_error("Size Error: the size have to be greater than zero");
                n = -1;
                m = -1;
            }
        }
        /**
         * Initializer list constructor with specified dimensions
         * @param init Initializer list of vectors to create the matrix
         * @param Nnum Number of rows (must be > 0)
         * @param Mnum Number of columns (must be > 0)
         */
        vector_2d(int Nnum, int Mnum, initializer_list<vector<T>> init)
            : vec_2D(init)
        {
            if (Nnum <= 0 || Mnum <= 0)
            {
                io::println_error("Size Error: the size have to be greater than zero");
                n = -1;
                m = -1;
            }
            else
            {
                n = Nnum;
                m = Mnum;
            }
        }
        /**
         * Copy constructor from existing 2D vector
         *
         * @param vec2d 2D vector to copy into the matrix
         */
        vector_2d(const vector<vector<T>> &vec2d) { vec_2D = vec2d; }
        /**
         * Copy constructor from another vector_2d object
         * @param other The vector_2d object to copy from
         * Initializes the new object with the same internal state as `other`:
         *   - vec_2D: Copy of the 2D vector
         *   - transpose_2D: Copy of the transpose vector
         *   - flatten_vec: Copy of the flattened vector
         */
        vector_2d(const vector_2d<T> &other)
        {
            vec_2D = other.vec_2D;
            transpose_2D = other.transpose_2D;
            flatten_vec = other.flatten_vec;
            n = other.n;
            m = other.m;
        }
        /**
         * Determines the general matrix type classification
         *
         * Classifies matrices into these categories:
         *   1. Empty Matrix
         *   2. Invalid Matrix (irregular dimensions)
         *   3. Row Matrix (1×n)
         *   4. Column Matrix (n×1)
         *   5. Square Matrix types (via matrix_type())
         *   6. Rectangular Matrix
         *
         * @param mat Optional external matrix to evaluate (uses internal matrix if
         * empty)
         * @return String name of the matrix classification
         */
        string general_matrix_type(const vector<vector<T>> &mat = {})
        {
            const auto &target = mat.empty() ? vec_2D : mat;
            if (target.empty())
                return "Empty Matrix";
            size_t n = target.size();
            size_t m = target[0].size();
            for (const auto &row : target)
            {
                if (row.size() != m)
                    return "Invalid Matrix";
            }
            if (n == 1 && m >= 2)
                return "Row Matrix";
            if (n >= 2 && m == 1)
                return "Column Matrix";
            if (n == m)
                return matrix_type(target);
            if (m != n)
                return "Rectangular Matrix";
            return "Unknown Matrix";
        }
        /*/////////////////// SET FUNCTIONS ///////////////////
        ////////////////////////////////////////////////////*/
        /**
         * Sets/updates the main 2D vector storage
         *
         * @param vec2d The new 2D vector to store as the main matrix
         * @note Overwrites any existing content in vec_2D
         */
        void set_2dvec(const vector<vector<T>> &vec2d) noexcept { vec_2D = vec2d; }
        /**
         * Sets the fixed dimensions for the matrix
         *
         * @param num Size for both dimensions (n×n)
         * @throws Error if size ≤ 0
         * @note Does not automatically resize existing matrix data
         * @warning This will not resize the internal 2D vector, only updates the size
         * attributes Use set_2dvec() to resize the internal vector if needed
         */
        void set_size(int num) noexcept
        {
            if (num <= 0)
                io::println_error("Size Error: the size have to be greater than zero");
            else
            {
                n = num;
                m = num;
            }
        }
        /**
         * Sets the fixed dimensions for the matrix
         *
         * @param Nnum Number of rows (must be > 0)
         * @param Mnum Number of columns (must be > 0)
         * @throws Error if either dimension ≤ 0
         * @note Does not automatically resize existing matrix data
         */
        void set_size(int Nnum, int Mnum) noexcept
        {
            if (Nnum <= 0 || Mnum <= 0)
                io::println_error("Size Error: the size have to be greater than zero");
            else
            {
                n = Nnum;
                m = Mnum;
            }
        }
        /**
         * Generates and stores the matrix transpose
         *
         * @param vec Optional external matrix to transpose (uses internal matrix if
         * empty)
         * @note Results are stored in tranvec_2D member variable
         * @see transpose() for implementation details
         */
        void set_transpose(const vector<vector<T>> &vec = {}) { transpose(vec); }
        /**
         * Generates and stores the flattened matrix
         *
         * @param vec Optional external matrix to flatten (uses internal matrix if
         * empty)
         * @note Results are stored in flatten member variable
         * @see flatten() for implementation details
         */
        void set_flatten(const vector<vector<T>> &vec = {}) { flatten(vec); }
        /*/////////////////// END OF SET FUNCTIONS ///////////////////
        ///////////////////////////////////////////////////////////*/
        /*/////////////////// GET FUNCTIONS ///////////////////
        ////////////////////////////////////////////////////*/
        /**
         * Returns a const reference to the internal 2D vector
         *
         * @return Const reference to vec_2D, or empty vector if matrix is empty
         * @warning Returned reference becomes invalid if matrix is modified
         */
        const vector<vector<T>> &get_2dvec() const noexcept { return vec_2D; }
        /**
         * Returns a deep copy of the internal 2D vector
         *
         * @return Copy of vec_2D, or empty vector if matrix is empty
         */
        vector<vector<T>> get_copy_2dvec() const noexcept { return vec_2D; }
        /**
         * Returns a const reference to a specific row vector
         *
         * @param index Row index (0-based)
         * @return Const reference to the requested row vector
         * @throws out_of_range if index is invalid
         */
        const vector<T> &get_2dvec(size_t index) const
        {
            if (index >= vec_2D.size())
                throw out_of_range("Index is out of range.");
            return vec_2D[index];
        }
        /**
         * Returns a deep copy of a specific row vector
         *
         * @param index Row index (0-based)
         * @return Copy of the requested row vector
         * @throws out_of_range if index is invalid
         */
        vector<T> get_copy_2dvec(size_t index)
        {
            if (index >= vec_2D.size())
                throw out_of_range("Index is out of range.");
            return vec_2D[index];
        }
        /**
         * Accesses an element in the 2D matrix
         *
         * @param ind1 Row index (0-based)
         * @param ind2 Column index (0-based)
         * @return Copy of the element at [ind1][ind2]
         * @throws out_of_range if either index is invalid
         */
        T get_2dvec(size_t ind1, size_t ind2)
        {
            if (ind1 >= vec_2D.size())
                throw out_of_range("Row index is out of range.");
            if (ind2 >= vec_2D[ind1].size())
                throw out_of_range("Column index is out of range.");
            return vec_2D[ind1][ind2];
        }
        /**
         * Returns a const reference to the transposed matrix
         *
         * @return Const reference to transpose_2D
         * @note Reference is invalid if matrix is modified
         */
        const vector<vector<T>> &get_transpose() const noexcept
        {
            return transpose_2D;
        }
        /**
         * Returns a deep copy of the transposed matrix
         *
         * @return Copy of transpose_2D
         */
        vector<vector<T>> get_copy_transpose() const noexcept { return transpose_2D; }
        /**
         * Returns a const reference to a row in the transposed matrix
         *
         * @param index Row index (0-based) in transposed matrix
         * @return Const reference to the requested row
         * @throws out_of_range if index is invalid
         */
        const vector<T> &get_transpose(size_t index) const
        {
            if (index >= transpose_2D.size())
                throw out_of_range("Index is out of range.");
            return transpose_2D[index];
        }
        /**
         * Returns a deep copy of a row in the transposed matrix
         *
         * @param index Row index (0-based) in transposed matrix
         * @return Copy of the requested row
         * @throws out_of_range if index is invalid
         */
        vector<T> get_copy_transpose(size_t index)
        {
            if (index >= transpose_2D.size())
                throw out_of_range("Index is out of range.");
            return transpose_2D[index];
        }
        /**
         * Accesses an element in the transposed matrix
         *
         * @param ind1 Row index (0-based) in transposed matrix
         * @param ind2 Column index (0-based) in transposed matrix
         * @return The element at [ind1][ind2] in transpose_2D
         * @throws out_of_range if either index is invalid
         */
        T get_transpose(size_t ind1, size_t ind2)
        {
            if (ind1 >= transpose_2D.size())
                throw out_of_range("Row index is out of range.");
            if (ind2 >= transpose_2D[ind1].size())
                throw out_of_range("Column index is out of range.");
            return transpose_2D[ind1][ind2];
        }
        /**
         * Returns a const reference to the flattened vector
         *
         * @return Const reference to flatten_vec
         * @note Reference is invalid if matrix is modified
         */
        const vector<T> &get_flatten() const noexcept { return flatten_vec; }
        /**
         * Returns a deep copy of the flattened vector
         *
         * @return Copy of flatten
         */
        vector<T> get_copy_flatten() const noexcept { return flatten_vec; }
        /**
         * Accesses an element in the flattened vector
         *
         * @param index Element position (0-based)
         * @return The element at specified position
         * @throws out_of_range if index is invalid
         */
        T get_flatten(size_t index)
        {
            if (index >= flatten_vec.size())
                throw out_of_range("Index is out of range.");
            return flatten_vec[index];
        }
        /*/////////////////// END OF GET FUNCTIONS ///////////////////
        ///////////////////////////////////////////////////////////*/
        /*/////////////////// PUSH AND POP FUNCTIONS ///////////////////
        /////////////////////////////////////////////////////////////*/
        /**
         * Appends a vector to the end of the 2D matrix
         *
         * @param vec Vector to append
         * @throws Error if:
         *           - Matrix has fixed size and is full (n×m reached), OR
         *           - Input vector dimensions don't match matrix columns
         */
        void push_vec(const vector<T> &vec)
        {
            if (n != -1 && vec_2D.size() == n)
                io::println_error("Capacity Error: Cannot exceed fixed row count");
            else if (m != -1 && vec.size() != m)
                io::println_error("Dimension Error: Vector size must match column count");
            else
                vec_2D.push_back(vec);
        }
        /**
         * Appends a default-initialized element to a specific row
         *
         * @param index Row index to modify (0-based)
         * @throws Error if:
         *           - Index is out of bounds, OR
         *           - Row has reached maximum column count
         */
        void push_element(size_t index)
        {
            if (index >= vec_2D.size())
                io::println_error("Index Error: Row index out of range");
            else if (m != -1 && vec_2D[index].size() == m)
                io::println_error("Capacity Error: Cannot exceed fixed column count");
            else
                vec_2D[index].push_back(T());
        }
        /**
         * Appends a vector to the transposed matrix
         *
         * @param vec Vector to append
         * @throws Error if transposed matrix is empty
         * @note Requires prior transpose operation
         */
        void push_transpose(const vector<T> &vec)
        {
            if (transpose_2D.empty())
                io::println_error("State Error: Transposed matrix not initialized");
            else
                transpose_2D.push_back(vec);
        }
        /**
         * Appends an element to a row in the transposed matrix
         *
         * @param element Element to append
         * @param index Row index in transposed matrix (0-based)
         * @throws Error if index is invalid
         */
        void push_transpose(T element, size_t index)
        {
            if (index >= transpose_2D.size())
                io::println_error("Index Error: Transposed row index out of range");
            else
                transpose_2D[index].push_back(element);
        }
        /**
         * Appends an element to the flattened vector
         *
         * @param element Element to append
         * @throws Error if flattened vector is empty
         * @note Flattened vector must be initialized first
         */
        void push_flatten(T element)
        {
            if (flatten_vec.empty())
                io::println_error("State Error: Flattened vector not initialized");
            else
                flatten_vec.push_back(element);
        }
        /**
         * Removes the last row from the 2D matrix
         *
         * @throws Error if matrix is empty
         */
        void pop_vec()
        {
            if (vec_2D.empty())
                io::println_error("Empty Error: Matrix has no rows to remove");
            else
                vec_2D.pop_back();
        }
        /**
         * Removes the last element from a specific row
         *
         * @param index Row index to modify (0-based)
         * @throws Error if index is invalid or row is empty
         */
        void pop_element(size_t index)
        {
            if (index >= vec_2D.size())
                io::println_error("Index Error: Row index out of range");
            else if (vec_2D[index].empty())
                io::println_error("Empty Error: Row is already empty");
            else
                vec_2D[index].pop_back();
        }
        /**
         * Removes the last row from the transposed matrix
         *
         * @throws Error if transposed matrix is empty
         */
        void pop_transpose()
        {
            if (transpose_2D.empty())
                io::println_error("Empty Error: Transposed matrix has no rows");
            else
                transpose_2D.pop_back();
        }
        /**
         * Removes the last element from a transposed matrix row
         *
         * @param index Row index in transposed matrix (0-based)
         * @throws Error if index is invalid or row is empty
         */
        void pop_transpose(size_t index)
        {
            if (index >= transpose_2D.size())
                io::println_error("Index Error: Transposed row index out of range");
            else if (transpose_2D[index].empty())
                io::println_error("Empty Error: Transposed row is already empty");
            else
                transpose_2D[index].pop_back();
        }
        /**
         * Removes the last element from the flattened vector
         *
         * @throws Error if flattened vector is empty
         */
        void pop_flatten()
        {
            if (flatten_vec.empty())
                io::println_error("Empty Error: Flattened vector has no elements");
            else
                flatten_vec.pop_back();
        }
        /*////////////////// END OF PUSH AND POP FUNCTIONS ///////////////////
        ///////////////////////////////////////////////////////////////////*/
        /*/////////////////// EMPTY CHECK FUNCTIONS ///////////////////
        ////////////////////////////////////////////////////////////*/
        /**
         * Checks if the main 2D matrix is empty
         *
         * @return true if vec_2D has no rows, false otherwise
         */
        constexpr bool empty() const noexcept { return vec_2D.empty(); }
        /**
         * Checks if a specific row in the main matrix is empty
         *
         * @param index Row index to check (0-based)
         * @return true if the specified row is empty
         * @throws Error if index is out of bounds
         */
        constexpr bool empty_vec(size_t index) const
        {
            if (index >= vec_2D.size())
            {
                io::println_error("Index Error: Row index out of range");
                throw invalid_argument("Index out of range");
            }
            return vec_2D[index].empty();
        }
        /**
         * Checks if the transposed matrix is empty
         *
         * @return true if transpose_2D has no rows, false otherwise
         */
        constexpr bool empty_transpose() const noexcept
        {
            return transpose_2D.empty();
        }
        /**
         * Checks if a specific row in the transposed matrix is empty
         *
         * @param index Row index to check (0-based)
         * @return true if the specified row is empty
         * @throws Error if index is out of bounds
         */
        constexpr bool empty_transpose(size_t index) const
        {
            if (index < 0 || index >= transpose_2D.size())
            {
                io::println_error("Index Error: Transposed row index out of range");
                throw invalid_argument("Index out of range");
            }
            return transpose_2D[index].empty();
        }
        /**
         * Checks if the flattened vector is empty
         *
         * @return true if flatten has no elements, false otherwise
         */
        bool empty_flatten() { return flatten_vec.empty(); }
        /*/////////////////// END OF EMPTY CHECK FUNCTIONS ///////////////////
        ///////////////////////////////////////////////////////////////////*/
        /*/////////////////// CLEAR FUNCTIONS ///////////////////
        //////////////////////////////////////////////////////*/
        /**
         * Clears all internal storage vectors (main, transposed, and flattened)
         *
         * @post All matrix data structures are empty:
         *       - vec_2D is cleared
         *       - tranvec_2D is cleared
         *       - flatten is cleared
         */
        void clear_all() noexcept
        {
            vec_2D.clear();
            transpose_2D.clear();
            flatten_vec.clear();
        }
        /**
         * Clears the main 2D matrix while preserving other structures
         *
         * @post vec_2D is empty
         * @note Does not affect tranvec_2D or flatten
         */
        void clear_2dvec() noexcept { vec_2D.clear(); }
        /**
         * Clears a specific row in the main 2D matrix
         *
         * @param index Row index to clear (0-based)
         * @throws Error if index is out of bounds
         * @post Specified row vector is empty
         */
        void clear_vec(size_t index)
        {
            if (index >= vec_2D.size())
            {
                io::println_error("Index Error: Row index out of range");
                throw invalid_argument("Index out of range");
            }
            vec_2D[index].clear();
        }
        /**
         * Clears the transposed matrix
         *
         * @post transpose_2D is empty
         * @note Does not affect vec_2D or flatten
         */
        void clear_transpose() noexcept { transpose_2D.clear(); }
        /**
         * Clears the flattened vector
         *
         * @post flatten is empty
         * @note Does not affect vec_2D or transpose_2D
         */
        void clear_flatten() noexcept { flatten_vec.clear(); }
        /*/////////////////// END OF CLEAR FUNCTIONS ///////////////////
        /////////////////////////////////////////////////////////////*/
        /*/////////////////// SIZE FUNCTIONS ///////////////////
        /////////////////////////////////////////////////////*/
        /**
         * Gets the row count (first dimension) of the main 2D matrix
         *
         * @return Number of rows:
         *         - Fixed size (n) if set, otherwise
         *         - Current row count of vec_2D
         */
        constexpr size_t size_2dvec() const
        {
            return (n != -1) ? static_cast<size_t>(n) : vec_2D.size();
        }
        /**
         * Gets the column count of a specific row in the main matrix
         *
         * @param index Row index to check (0-based)
         * @return Number of columns:
         *         - Fixed size (m) if set, otherwise
         *         - Current size of specified row
         * @throws Error if index is out of bounds
         */
        constexpr size_t size_vec(size_t index) const
        {
            if (index >= vec_2D.size())
            {
                io::println_error("Index Error: Row index out of range");
                throw invalid_argument("Index out of range");
            }
            return (m != -1) ? static_cast<size_t>(m) : vec_2D[index].size();
        }
        /**
         * Gets the row count of the transposed matrix
         *
         * @return Number of rows in transpose_2D (0 if empty)
         */
        constexpr size_t size_transpose() const noexcept
        {
            return transpose_2D.size();
        }
        /**
         * Gets the column count of a specific row in the transposed matrix
         *
         * @param index Row index to check (0-based)
         * @return Number of columns in specified row
         * @throws Error if index is out of bounds
         */
        constexpr size_t size_transpose(size_t index) const
        {
            if (index >= transpose_2D.size())
            {
                io::println_error("Index Error: Transposed row index out of range");
                throw invalid_argument("Index out of range");
            }
            return transpose_2D[index].size();
        }
        /**
         * Gets the element count in the flattened vector
         *
         * @return Number of elements in flatten (0 if empty)
         */
        constexpr size_t size_flat() const noexcept { return flatten_vec.size(); }
        /*/////////////////// END OF SIZE FUNCTIONS ///////////////////
        ////////////////////////////////////////////////////////////*/
        /**
         * Calculates the determinant of a square matrix (2x2 or 3x3)
         *
         * Supports both internal matrix (vec_2D) and external matrices.
         * Currently implements:
         *   - 2x2 matrices (using simple diagonal rule)
         *   - 3x3 matrices (using Rule of Sarrus)
         *   - NxN matrices (using Gaussian-Jordan elimination)
         *
         * @param vec Optional external matrix (uses internal matrix if empty)
         * @return The determinant value as long double
         * @throws When:
         *           - Input matrix is empty, OR
         *           - Matrix is not square, OR
         *           - Matrix size is not currently supported (only 2x2 and 3x3)
         *
         * @note For 2x2 matrices: det = ad - bc
         * @note For 3x3 matrices: det = a(ei−fh) − b(di−fg) + c(dh−eg)
         * @see determinant2X2()
         * @see determinant3X3()
         */
        long double determinant(const vector<vector<T>> &vec = {})
        {
            const auto &target = vec.empty() ? vec_2D : vec;
            if (target.empty())
            {
                io::println_error(
                    "EmptyMatrixError: Cannot calculate determinant of empty matrix");
                throw invalid_argument("Empty matrix");
            }
            if (is_numeric_type<T>::value)
            {
                if (square2X2(target))
                    return determinant2X2(target);
                if (square3X3(target))
                    return determinant3X3(target);
                if (squareNXN(target))
                    return determinantNXN(target);
            }
            io::println_error(
                "UnsupportedSizeError: Determinant calculation only implemented for "
                "2x2 and 3x3 matrices");
            throw runtime_error("Unsupported matrix size");
        }
        /**
         * Determines if the matrix has fixed dimensions
         *
         * @return true if both row count (n) and column count (m) are fixed, false
         * otherwise
         * @note Fixed dimensions are set through:
         *       - vector_2d(int, int) constructor
         *       - set_size() function
         */
        constexpr bool isfixedsize() const noexcept { return (n != -1) && (m != -1); }
        /*/////////////////// PRINT FUNCTIONS ///////////////////
        //////////////////////////////////////////////////////*/
        /**
         * Prints the main 2D matrix in a formatted way
         *
         * Output format:
         * | a11, a12, a13 |
         * | a21, a22, a23 |
         *
         * @note Uses borders and commas for clear matrix visualization
         */
        void print_2dvec() const noexcept
        {
            for (size_t i = 0; i < vec_2D.size(); i++)
            {
                cout << "| ";
                for (size_t j = 0; j < vec_2D[i].size(); j++)
                {
                    cout << vec_2D[i][j];
                    if (j != vec_2D[i].size() - 1)
                        cout << ", ";
                }
                cout << " |" << endl;
            }
        }
        /**
         * Prints a specific row from the main 2D matrix
         *
         * @param index Row index to print (0-based)
         * @throws out_of_range if index is invalid
         * @see PrintVec() for formatting details
         */
        void print_vec(size_t index) const
        {
            if (index >= vec_2D.size())
                throw out_of_range("Row index out of range");
            io::print_vec(vec_2D[index]);
        }
        /**
         * Prints the transposed matrix in a formatted way
         *
         * Output format same as print_2dvec()
         */
        void print_transpose() const noexcept
        {
            const auto &temp = get_transpose();
            for (size_t i = 0; i < temp.size(); i++)
            {
                cout << "| ";
                for (size_t j = 0; j < temp[i].size(); j++)
                {
                    cout << temp[i][j];
                    if (j != temp[i].size() - 1)
                        cout << ", ";
                }
                cout << " |" << endl;
            }
        }
        /**
         * Prints a specific row from the transposed matrix
         *
         * @param index Row index to print (0-based)
         * @throws out_of_range if index is invalid
         * @see PrintVec() for formatting details
         */
        void print_transpose(size_t index) const
        {
            const auto &temp = get_transpose();
            if (index >= temp.size())
                throw out_of_range("Transposed row index out of range");
            PrintVec(temp[index]);
        }
        /**
         * Prints the flattened vector
         *
         * @see PrintVec() for formatting details
         */
        void print_flatten() const
        {
            const auto &temp = get_flatten();
            if (temp.empty())
                throw runtime_error("Flattened vector is empty");
            io::print_vec(temp);
        }
        /*/////////////////// END OF PRINT FUNCTIONS ///////////////////
        /////////////////////////////////////////////////////////////*/
        /*/////////////////// OPERATOR FUNCTIONS ///////////////////
        /////////////////////////////////////////////////////////*/
        /**
         * Assignment operator for matrix replacement
         *
         * @param vec2d 2D vector to assign to the internal storage
         * @post Replaces current vec_2D with the input vector
         */
        void operator=(const vector<vector<T>> &vec2d) noexcept { vec_2D = vec2d; }
        /**
         * Assignment operator for vector_2d object
         * @param other The vector_2d object to copy from
         * Initializes the current object with the same internal state as `other`:
         *   - vec_2D: Copy of the 2D vector
         *   - transpose_2D: Copy of the transpose vector
         *   - flatten_vec: Copy of the flattened vector
         */
        void operator=(const vector_2d<T> &other) noexcept
        {
            vec_2D = other.vec_2D;
            transpose_2D = other.transpose_2D;
            flatten_vec = other.flatten_vec;
            n = other.n;
            m = other.m;
        }
        /**
         * Subscript operator for row access (mutable)
         *
         * @param i Row index (0-based)
         * @return Reference to the requested row vector
         * @warning No bounds checking - use with valid indices
         */
        vector<T> &operator[](size_t i) noexcept { return vec_2D[i]; }
        /**
         * Subscript operator for row access (const)
         *
         * @param i Row index (0-based)
         * @return Const reference to the requested row vector
         * @warning No bounds checking - use with valid indices
         */
        const vector<T> &operator[](size_t i) const noexcept { return vec_2D[i]; }
        /**
         * Equality operator for matrix comparison
         *
         * @param vec2d Matrix to compare against
         * @return true if:
         *           - Both matrices are empty, OR
         *           - All elements are equal
         *         false otherwise
         */
        bool operator==(const vector<vector<T>> &vec2d) const noexcept
        {
            if (vec2d.size() != vec_2D.size())
                return false;
            for (size_t i = 0; i < vec_2D.size(); i++)
            {
                if (vec2d[i].size() != vec_2D[i].size())
                    return false;
                for (size_t j = 0; j < vec_2D[i].size(); j++)
                {
                    if (vec_2D[i][j] != vec2d[i][j])
                        return false;
                }
            }
            return true;
        }
        /**
         * Scalar addition operator (modifies current matrix)
         *
         * @param element Value to add to all elements
         * @post Adds element to every element in the matrix
         */
        void operator+=(T element)
        {
            if (!is_numeric_type<T>::value)
                throw invalid_argument("Element type is not numeric");
            for (auto &row : vec_2D)
            {
                for (auto &elem : row)
                {
                    elem += element;
                }
            }
        }
        /**
         * Matrix addition operator (modifies current matrix)
         *
         * @param vec2d Matrix to add element-wise
         * @post Performs element-wise addition
         * @note Matrices must have identical dimensions
         */
        void operator+=(const vector<vector<T>> &vec2d)
        {
            if (!is_numeric_type<T>::value)
                throw invalid_argument("Element type is not numeric");
            if (vec2d.size() != vec_2D.size())
                throw invalid_argument("Incompatible matrix dimensions");
            for (size_t i = 0; i < vec_2D.size(); i++)
            {
                if (vec2d[i].size() != vec_2D[i].size())
                    throw invalid_argument("Incompatible matrix dimensions");
                for (size_t j = 0; j < vec_2D[i].size(); j++)
                {
                    vec_2D[i][j] += vec2d[i][j];
                }
            }
        }
        /**
         * Scalar subtraction operator (modifies current matrix)
         *
         * @param element Value to subtract from all elements
         * @post Subtracts element from every element in the matrix
         */
        void operator-=(T element)
        {
            if (!is_numeric_type<T>::value)
                throw invalid_argument("Element type is not numeric");
            if (vec_2D.empty())
                return; // No change for empty matrix
            if (element == 0)
                return; // No change for zero subtraction
            for (auto &row : vec_2D)
            {
                for (auto &elem : row)
                {
                    elem -= element;
                }
            }
        }
        /**
         * Matrix subtraction operator (modifies current matrix)
         *
         * @param vec2d Matrix to subtract element-wise
         * @post Performs element-wise subtraction
         * @note Matrices must have identical dimensions
         */
        void operator-=(const vector<vector<T>> &vec2d)
        {
            if (!is_numeric_type<T>::value)
                throw invalid_argument("Element type is not numeric");
            if (vec2d.size() != vec_2D.size())
                throw invalid_argument("Incompatible matrix dimensions");
            for (size_t i = 0; i < vec_2D.size(); i++)
            {
                if (vec2d[i].size() != vec_2D[i].size())
                    throw invalid_argument("Incompatible matrix dimensions");
                for (size_t j = 0; j < vec_2D[i].size(); j++)
                {
                    vec_2D[i][j] -= vec2d[i][j];
                }
            }
        }
        /**
         * Element-wise power operator (modifies current matrix)
         *
         * @param vec2d Exponent matrix
         * @post Raises elements to corresponding powers
         * @note Matrices must have identical dimensions
         */
        void operator^=(const vector<vector<T>> &vec2d)
        {
            if (!is_numeric_type<T>::value)
                throw invalid_argument("Element type is not numeric");
            if (vec2d.size() != vec_2D.size())
                throw invalid_argument("Incompatible matrix dimensions");
            for (size_t i = 0; i < vec_2D.size(); i++)
            {
                if (vec2d[i].size() != vec_2D[i].size())
                    throw invalid_argument("Incompatible matrix dimensions");
                for (size_t j = 0; j < vec_2D[i].size(); j++)
                {
                    vec_2D[i][j] = pow(vec_2D[i][j], vec2d[i][j]);
                }
            }
        }
        /**
         * Scalar multiplication operator (modifies current matrix)
         *
         * @param element Value to multiply all elements by
         * @post Multiplies every element by given scalar
         */
        void operator*=(T element)
        {
            if (!is_numeric_type<T>::value)
                throw invalid_argument("Element type is not numeric");
            if (vec_2D.empty())
                return; // No change for empty matrix
            for (auto &row : vec_2D)
            {
                for (auto &elem : row)
                {
                    elem *= element;
                }
            }
        }
        /**
         * Scalar division operator (modifies current matrix)
         *
         * @param element Value to divide all elements by
         * @post Divides every element by given scalar
         * @throws invalid_argument if element is zero
         */
        void operator/=(T element)
        {
            if (!is_numeric_type<T>::value)
                throw invalid_argument("Element type is not numeric");
            if (vec_2D.empty())
                return; // No change for empty matrix
            if (element == 0)
                throw invalid_argument("Division by zero");
            for (auto &row : vec_2D)
            {
                for (auto &elem : row)
                {
                    elem /= element;
                }
            }
        }
        /*/////////////////// END OF OPERATOR FUNCTIONS ///////////////////
        ////////////////////////////////////////////////////////////////*/
        /**
         * Default destructor
         *
         * @note Automatically clears all managed resources
         * @warning Does not manually clear members - relies on vector destructors
         */
        ~vector_2d() = default;
    }; // end of the object vector_2d
    /**
     * A generic 3D vector wrapper that provides access and modification utilities
     * for elements, 2D slices, and full 3D structure.
     *
     * @tparam T Type of the elements stored (int, float, string, etc.)
     */
    template <typename T>
    class vector_3d
    {
        /*///////////////////private members/////////////////////
        ///////////////////////////////////////////////////////*/
    private:
        size_t w = -1, n = -1, m = -1;
        vector<vector<vector<T>>> vec_3D;
        vector<vector<vector<T>>> transpose_3D;
        vector<vector<T>> flatten;
        vector<T> determinant;
        /*///////////////////protected members/////////////////////
        /////////////////////////////////////////////////////////*/
    protected:
        /**
         * Flattens a 3D vector into a 2D vector
         *
         * Transformation:
         *   [depth][rows][cols] -> [depth * rows][cols]
         *
         * @param vec Optional external 3D vector (uses internal vec_3D if empty)
         * @post Result stored in member 'flatten' (2D vector)
         * @warning Will skip operation if input is empty
         */
        void flatten_2dvec(const vector<vector<vector<T>>> &vec = {})
        {
            const auto &target = vec.empty() ? vec_3D : vec;
            if (target.empty())
            {
                io::println_error("The 3D vector is empty");
                return;
            }
            flatten.clear();
            for (size_t i = 0; i < target.size(); i++)
            {
                for (size_t j = 0; j < target[i].size(); j++)
                    flatten.push_back(target[i][j]);
            }
        }
        /**
         * Transposes the first two dimensions of a 3D vector
         *
         * Transformation:
         *   Original: [depth][rows][cols]
         *   Transposed: [rows][depth][cols]
         *
         * @param vec Optional external 3D vector (uses internal vec_3D if empty)
         * @post Result stored in member 'transpose_3D'
         * @warning Requires non-empty input and consistent dimensions
         */
        void transpose(const vector<vector<vector<T>>> &vec = {})
        {
            const auto &target = vec.empty() ? vec_3D : vec;
            if (target.empty() || target[0].empty())
            {
                io::println_error("The 3D vector is empty");
                return;
            }
            transpose_3D.clear();
            transpose_3D.resize(target[0].size());
            for (size_t i = 0; i < target[0].size(); i++)
            {
                for (size_t j = 0; j < target.size(); j++)
                {
                    transpose_3D[i].push_back(target[j][i]);
                }
            }
        }
        /**
         * Computes determinants for each 2D matrix in a 3D vector
         *
         * Processes each 2D slice (depth layer) independently
         *
         * @param vec Optional external 3D vector (uses internal vec_3D if empty)
         * @post Results stored in member 'determinant' (1D vector of determinants)
         * @note Uses vector_2d::determinant() for each 2D matrix
         * @warning Only works for 2x2 and 3x3 matrices
         */
        void determinant_vec(const vector<vector<vector<T>>> &vec = {})
        {
            if (!is_numeric_type<T>::value)
                throw runtime_error(
                    "TypeError: Determinant is only supported for numeric types");
            const auto &target = vec.empty() ? vec_3D : vec;
            if (target.empty())
                throw runtime_error(
                    "EmptyMatrixError: Cannot calculate determinant of empty 3D vector");
            determinant.clear();
            vector_2d<T> vt;
            for (const vector<vector<T>> &loopvec : target)
                determinant.push_back(vt.determinant(loopvec));
        }
        /*///////////////////public members/////////////////////
        //////////////////////////////////////////////////////*/
    public:
        /**
         * Default constructor - creates an empty 3D vector
         *
         * Initializes vec_3D as an empty 3-dimensional vector
         */
        vector_3d() { vec_3D = {}; } // default constructor
        /**
         * Cubic matrix constructor - creates a cube-shaped 3D vector
         *
         * @param num Size for all three dimensions (w×n×m cube)
         */
        vector_3d(size_t num)
        {
            w = num;
            n = num;
            m = num;
        }
        /**
         * Semi-cubic constructor - creates a 3D vector with equal last two dimensions
         *
         * @param num1 Size of first dimension (depth)
         * @param num2 Size for both second and third dimensions (rows and columns)
         */
        vector_3d(size_t num1, size_t num2)
        {
            w = num1;
            n = num2;
            m = num2;
        }
        /**
         * Rectangular 3D constructor - creates a 3D vector with custom dimensions
         *
         * @param num1 Size of first dimension (depth)
         * @param num2 Size of second dimension (rows)
         * @param num3 Size of third dimension (columns)
         */
        vector_3d(size_t num1, size_t num2, size_t num3)
        {
            w = num1;
            n = num2;
            m = num3;
        }
        /**
         * Initializer list constructor - creates from nested initializer lists
         *
         * @param init Initializer list of 2D vectors to form the 3D structure
         *
         * Example:
         *   vector_3d<int> v = {
         *     {{1,2}, {3,4}},
         *     {{5,6}, {7,8}}
         *   };
         */
        vector_3d(initializer_list<vector<vector<T>>> init) : vec_3D(init)
        {
            size_t wnum, nnum, mnum;
            wnum = static_cast<size_t>(vec_3D.size());
            nnum = wnum > 0 ? static_cast<size_t>(vec_3D[0].size()) : -1;
            mnum =
                (wnum > 0 && nnum > 0) ? static_cast<size_t>(vec_3D[0][0].size()) : -1;
            if (w != -1 && n != -1 && m != -1)
            {
                if (wnum != w || nnum != n || mnum != m)
                {
                    throw runtime_error(
                        "Dimension Error: Initializer list dimensions do not match fixed "
                        "size");
                }
            }
        }
        /**
         * Copy constructor from existing 3D vector
         *
         * @param vec3d 3D vector to copy into the new object
         */
        vector_3d(const vector<vector<vector<T>>> &vec3d)
        {
            vec_3D = vec3d;
        } // 3D vector copy constructor
        /**
         * @brief Copy constructor for the vector_3d class.
         *
         * Creates a new vector_3d object by copying all member variables from another
         * vector_3d instance.
         *
         * @param other The vector_3d object to copy from.
         */
        vector_3d(const vector_3d<T> &other)
        {
            vec_3D = other.vec_3D;
            transpose_3D = other.transpose_3D;
            flatten = other.flatten;
            determinant = other.determinant;
            w = other.w;
            n = other.n;
            m = other.m;
        } // copy constructor
        /*/////////////////// SET FUNCTIONS ///////////////////
        ////////////////////////////////////////////////////*/
        /**
         * Sets/updates the main 3D vector storage
         *
         * @param vec3d The new 3D vector to store as the main data
         * @note Overwrites any existing 3D vector content
         */
        void set_3dvec(const vector<vector<vector<T>>> &vec3d) noexcept
        {
            vec_3D = vec3d;
        }
        /**
         * Generates and stores the flattened 2D representation
         *
         * @param vec Optional external 3D vector to flatten
         *            (uses internal vec_3D if empty)
         * @post Result stored in member 'flatten' (2D vector)
         * @see flatten()
         */
        void set_faltten(const vector<vector<T>> &vec = {}) { flatten_2dvec(vec); }
        /**
         * Computes and stores the transpose of the 3D vector
         *
         * @param vec Optional external 3D vector to transpose
         *            (uses internal vec_3D if empty)
         * @post Result stored in member 'transpose_3D'
         * @see transpose()
         */
        void set_transpose(const vector<vector<vector<T>>> &vec = {}) noexcept
        {
            transpose(vec);
        }
        /**
         * Computes and stores determinants for each 2D matrix slice
         *
         * @param vec Optional external 3D vector to process
         *            (uses internal vec_3D if empty)
         * @post Result stored in member 'determinant' (1D vector)
         * @see determinant_vec()
         */
        void set_determinant_vec(const vector<long double> &vec = {}) noexcept
        {
            determinant_vec(vec);
        }
        /**
         * Sets fixed cubic dimensions (w×n×m cube)
         *
         * @param num Size for all three dimensions
         */
        void set_size(size_t num) noexcept
        {
            w = num;
            n = num;
            m = num;
        }
        /**
         * Sets fixed dimensions with equal last two dimensions
         *
         * @param num1 Size of first dimension (depth)
         * @param num2 Size for both second and third dimensions (rows and columns)
         */
        void set_size(size_t num1, size_t num2) noexcept
        {
            w = num1;
            n = num2;
            m = num2;
        }
        /**
         * Sets custom fixed dimensions for all three axes
         *
         * @param num1 Size of first dimension (depth)
         * @param num2 Size of second dimension (rows)
         * @param num3 Size of third dimension (columns)
         */
        void set_size(size_t num1, size_t num2, size_t num3) noexcept
        {
            w = num1;
            n = num2;
            m = num3;
        }
        /*/////////////////// END OF SET FUNCTIONS ///////////////////
        ///////////////////////////////////////////////////////////*/
        ///////////////////// GET FUNCTIONS /////////////////////
        //////////////////////////////////////////////////////*/
        /**
         * Returns a const reference to the internal 3D vector
         *
         * @return Const reference to vec_3D
         * @warning Reference becomes invalid if matrix is modified
         */
        const vector<vector<vector<T>>> &get_3dvec() const noexcept { return vec_3D; }
        /**
         * Returns a deep copy of the internal 3D vector
         *
         * @return Copy of vec_3D
         */
        vector<vector<vector<T>>> get_copy_3dvec() const noexcept { return vec_3D; }
        /**
         * Returns a const reference to a 2D slice within the 3D vector
         *
         * @param index Depth index (0-based)
         * @return Const reference to the 2D matrix at specified depth
         * @throws out_of_range if index is invalid
         */
        const vector<vector<T>> &get_2dvec(size_t index) const
        {
            if (index >= vec_3D.size())
                throw out_of_range("Depth index out of range");
            return vec_3D[index];
        }
        /**
         * Returns a deep copy of a 2D slice within the 3D vector
         *
         * @param index Depth index (0-based)
         * @return Copy of the 2D matrix at specified depth
         * @throws out_of_range if index is invalid
         */
        vector<vector<T>> get_copy_2dvec(size_t index)
        {
            if (index >= vec_3D.size())
                throw out_of_range("Depth index out of range");
            return vec_3D[index];
        }
        /**
         * Returns a const reference to a row vector within a 2D slice
         *
         * @param ind1 Depth index (0-based)
         * @param ind2 Row index (0-based)
         * @return Const reference to the row vector
         * @throws out_of_range if either index is invalid
         */
        const vector<T> &get_vec(size_t ind1, size_t ind2) const
        {
            if (ind1 >= vec_3D.size())
                throw out_of_range("Depth index out of range");
            if (ind2 >= vec_3D[ind1].size())
                throw out_of_range("Row index out of range");
            return vec_3D[ind1][ind2];
        }
        /**
         * Returns a deep copy of a row vector within a 2D slice
         *
         * @param ind1 Depth index (0-based)
         * @param ind2 Row index (0-based)
         * @return Copy of the row vector
         * @throws out_of_range if either index is invalid
         */
        vector<T> get_copy_vec(size_t ind1, size_t ind2)
        {
            if (ind1 >= vec_3D.size())
                throw out_of_range("Depth index out of range");
            if (ind2 >= vec_3D[ind1].size())
                throw out_of_range("Row index out of range");
            return vec_3D[ind1][ind2];
        }
        /**
         * Accesses an element in the 3D vector
         *
         * @param ind1 Depth index (0-based)
         * @param ind2 Row index (0-based)
         * @param ind3 Column index (0-based)
         * @return The element at [ind1][ind2][ind3]
         * @throws out_of_range if any index is invalid
         */
        T get_element(size_t ind1, size_t ind2, size_t ind3)
        {
            if (ind1 >= vec_3D.size())
                throw out_of_range("Depth index out of range");
            if (ind2 >= vec_3D[ind1].size())
                throw out_of_range("Row index out of range");
            if (ind3 >= vec_3D[ind1][ind2].size())
                throw out_of_range("Column index out of range");
            return vec_3D[ind1][ind2][ind3];
        }
        /**
         * Returns a const reference to the flattened 2D representation
         *
         * @return Const reference to the flatten member
         */
        const vector<vector<T>> &get_flatten() const noexcept { return flatten; }
        /**
         * Returns a deep copy of the flattened 2D representation
         *
         * @return Copy of the flatten member
         */
        vector<vector<T>> get_copy_flatten() const noexcept { return flatten; }
        /**
         * Returns a const reference to a row in the flattened 2D representation
         *
         * @param index Row index (0-based)
         * @return Const reference to the requested row
         * @throws out_of_range if index is invalid
         */
        const vector<T> &get_flatten(size_t index) const
        {
            if (index >= flatten.size())
                throw out_of_range("Flatten row index out of range");
            return flatten[index];
        }
        /**
         * Returns a deep copy of a row in the flattened 2D representation
         *
         * @param index Row index (0-based)
         * @return Copy of the requested row
         * @throws out_of_range if index is invalid
         */
        vector<T> get_copy_flatten(size_t index)
        {
            if (index >= flatten.size())
                throw out_of_range("Flatten row index out of range");
            return flatten[index];
        }
        /**
         * Accesses an element in the flattened 2D representation
         *
         * @param ind1 Row index (0-based)
         * @param ind2 Column index (0-based)
         * @return The element at [ind1][ind2] in flatten
         * @throws out_of_range if either index is invalid
         */
        T get_flatten(size_t ind1, size_t ind2)
        {
            if (ind1 >= flatten.size())
                throw out_of_range("Flatten row index out of range");
            if (ind2 >= flatten[ind1].size())
                throw out_of_range("Flatten column index out of range");
            return flatten[ind1][ind2];
        }
        /**
         * Returns a copy of the determinant vector
         *
         * @return Vector of determinants for each 2D slice
         */
        vector<T> get_determinant_vec() const noexcept { return determinant; }
        /**
         * Accesses a specific determinant value
         *
         * @param index Slice index (0-based)
         * @return Determinant value for the specified 2D slice
         * @throws std::out_of_range if index is invalid
         */
        T get_determinant(size_t index) const
        {
            if (index < 0 || index >= static_cast<int>(determinant.size()))
                throw out_of_range("Determinant index out of range");
            return determinant[index];
        }
        /*/////////////////// END OF GET FUNCTIONS ///////////////////
        ///////////////////////////////////////////////////////////*/
        /*/////////////////// PUSH AND POP FUNCTIONS ///////////////////
        /////////////////////////////////////////////////////////////*/
        /**
         * Appends a 2D matrix to the end of the 3D vector
         *
         * @param vec2d 2D matrix to append
         * @throws Error if fixed depth (w) is reached
         */
        void push_2dvec(const vector<vector<T>> &vec2d)
        {
            if (w != -1 && w == vec_3D.size())
                throw runtime_error("CapacityError: Cannot exceed fixed depth");
            vec_3D.push_back(vec2d);
        }
        /**
         * Appends a row vector to a specific 2D matrix in the 3D vector
         *
         * @param index Depth index of target matrix (0-based)
         * @param vec Row vector to append
         * @throws Error if:
         *           - Index is invalid, OR
         *           - Fixed row count (n) is reached
         *          - Row exceeds fixed column count (m)
         */
        void push_vec(size_t index, const vector<T> &vec)
        {
            if (index >= vec_3D.size())
                throw out_of_range("Depth index out of range");
            if (n != -1 && n == vec_3D[index].size())
                throw runtime_error("CapacityError: Cannot exceed fixed row count");
            if (vec.size() > m && m != -1)
                throw runtime_error("CapacityError: Row exceeds fixed column count");
            vec_3D[index].push_back(vec);
        }
        /**
         * Appends an element to a specific row in the 3D vector
         *
         * @param ind1 Depth index (0-based)
         * @param ind2 Row index (0-based)
         * @param ele Element to append
         * @throws Error if:
         *           - Either index is invalid, OR
         *           - Fixed column count (m) is reached
         */
        void push_element(size_t ind1, size_t ind2, T ele)
        {
            if (ind1 >= vec_3D.size())
                throw out_of_range("Depth index out of range");
            if (ind2 >= vec_3D[ind1].size())
                throw out_of_range("Row index out of range");
            if (m != -1 && m == vec_3D[ind1][ind2].size())
                throw runtime_error("CapacityError: Cannot exceed fixed column count");
            vec_3D[ind1][ind2].push_back(ele);
        }
        /**
         * Appends a 2D matrix to the transposed representation
         *
         * @param vec 2D matrix to append
         * @throws Error if transposed matrix is not initialized
         */
        void push_transpose(const vector<vector<T>> &vec)
        {
            if (transpose_3D.empty())
                throw runtime_error("Transpose not computed");
            transpose_3D.push_back(vec);
        }
        /**
         * Appends a row vector to a specific matrix in the transposed representation
         *
         * @param vec Row vector to append
         * @param index Depth index in transposed matrix (0-based)
         * @throws Error if:
         *           - Transposed matrix not initialized, OR
         *           - Index is invalid
         */
        void push_transpose(const vector<T> &vec, size_t index)
        {
            if (transpose_3D.empty())
                throw runtime_error("Transpose not computed");
            if (index >= transpose_3D.size())
                throw out_of_range("Transposed depth index out of range");
            transpose_3D[index].push_back(vec);
        }
        /**
         * Appends an element to a specific row in the transposed representation
         *
         * @param ind1 Depth index in transposed matrix (0-based)
         * @param ind2 Row index in transposed matrix (0-based)
         * @param ele Element to append
         * @throws Error if:
         *           - Transposed matrix not initialized, OR
         *           - Either index is invalid
         */
        void push_transpose(size_t ind1, size_t ind2, T ele)
        {
            if (transpose_3D.empty())
                throw runtime_error("Transpose not computed");
            if (ind1 >= transpose_3D.size())
                throw out_of_range("Transposed depth index out of range");
            if (ind2 >= transpose_3D[ind1].size())
                throw out_of_range("Transposed row index out of range");
            transpose_3D[ind1][ind2].push_back(ele);
        }
        /**
         * Appends a new row to the flattened representation
         *
         * @param vec Row vector to append
         * @throws Error if flattened matrix is not initialized
         */
        void push_flatten(const vector<T> &vec)
        {
            if (flatten.empty())
                throw runtime_error("Flattened matrix not initialized");
            flatten.push_back(vec);
        }
        /**
         * Appends an element to a specific row in the flattened representation
         *
         * @param element Element to append
         * @param index Row index in flattened matrix (0-based)
         * @throws Error if:
         *           - Flattened matrix not initialized, OR
         *           - Index is invalid
         */
        void push_flatten(T element, int index)
        {
            if (flatten.empty())
                throw runtime_error("Flattened matrix not initialized");
            if (index >= flatten.size())
                throw out_of_range("Flattened row index out of range");
            flatten[index].push_back(element);
        }
        /**
         * @brief Adds an element to the determinant vector.
         *
         * This function appends the specified element to the internal
         * determinant vector. It is typically used to store values
         * relevant to determinant calculations or tracking.
         *
         * @param element The element of type T to be added to the determinant vector.
         */
        void push_determinant_vec(T element)
        {
            if (determinant.empty())
                throw runtime_error("Determinant vector not initialized");
            if (!is_numeric_type<T>::value)
                throw invalid_argument("Element type is not numeric");
            determinant.push_back(element);
        }
        /**
         * Removes the last 2D matrix from the 3D vector
         *
         * @throws Error if 3D vector is empty
         */
        void pop_2dvec()
        {
            if (vec_3D.empty())
                throw out_of_range("3D vector is empty");
            vec_3D.pop_back();
        }
        /**
         * Removes the last row from a specific 2D matrix
         *
         * @param index Depth index (0-based)
         * @throws Error if:
         *           - Index is invalid, OR
         *           - Target matrix is empty
         */
        void pop_vec(size_t index)
        {
            if (index >= vec_3D.size())
                throw out_of_range("Depth index out of range");
            if (vec_3D[index].empty())
                throw out_of_range("Matrix at index is empty");
            vec_3D[index].pop_back();
        }
        /**
         * Removes the last element from a specific row
         *
         * @param ind1 Depth index (0-based)
         * @param ind2 Row index (0-based)
         * @throws Error if:
         *           - Either index is invalid, OR
         *           - Target row is empty
         */
        void pop_element(size_t ind1, size_t ind2)
        {
            if (ind1 >= vec_3D.size())
                throw out_of_range("Depth index out of range");
            if (ind2 >= vec_3D[ind1].size())
                throw out_of_range("Row index out of range");
            if (vec_3D[ind1][ind2].empty())
                throw out_of_range("Row vector is empty");
            vec_3D[ind1][ind2].pop_back();
        }
        /**
         * Removes the last matrix from the transposed representation
         *
         * @throws Error if transposed matrix is empty
         */
        void pop_transpose()
        {
            if (transpose_3D.empty())
                throw out_of_range("Transposed matrix is empty");
            transpose_3D.pop_back();
        }
        /**
         * Removes the last row from a specific matrix in the transposed
         * representation
         *
         * @param index Depth index in transposed matrix (0-based)
         * @throws Error if:
         *           - Index is invalid, OR
         *           - Target matrix is empty
         */
        void pop_transpose(size_t index)
        {
            if (index >= transpose_3D.size())
                throw out_of_range("Transposed depth index out of range");
            if (transpose_3D[index].empty())
                throw out_of_range("Transposed matrix at index is empty");
            transpose_3D[index].pop_back();
        }
        /**
         * Removes the last element from a specific row in the transposed
         * representation
         *
         * @param ind1 Depth index in transposed matrix (0-based)
         * @param ind2 Row index in transposed matrix (0-based)
         * @throws Error if:
         *           - Either index is invalid, OR
         *           - Target row is empty
         */
        void pop_transpose(size_t ind1, size_t ind2)
        {
            if (ind1 >= transpose_3D.size())
                throw out_of_range("Transposed depth index out of range");
            if (ind2 >= transpose_3D[ind1].size())
                throw out_of_range("Transposed row index out of range");
            if (transpose_3D[ind1][ind2].empty())
                throw out_of_range("Transposed row vector is empty");
            transpose_3D[ind1][ind2].pop_back();
        }
        /**
         * Removes the last row from the flattened representation
         *
         * @throws Error if flattened matrix is empty
         */
        void pop_flatten()
        {
            if (flatten.empty())
                throw out_of_range("Flattened matrix is empty");
            flatten.pop_back();
        }
        /**
         * Removes the last element from a specific row in the flattened
         * representation
         *
         * @param index Row index in flattened matrix (0-based)
         * @throws Error if:
         *           - Index is invalid, OR
         *           - Target row is empty
         */
        void pop_flatten(size_t index)
        {
            if (index >= flatten.size())
                throw out_of_range("Flattened row index out of range");
            if (flatten[index].empty())
                throw out_of_range("Flattened row vector is empty");
            flatten[index].pop_back();
        }
        /**
         * Removes the last element from the determinant vector
         *
         * @throws Error if determinant vector is empty
         */
        void pop_determinant_vec()
        {
            if (determinant.empty())
                throw out_of_range("Determinant vector is empty");
            determinant.pop_back();
        }
        /*/////////////////// END OF PUSH AND POP FUNCTIONS ///////////////////
        ////////////////////////////////////////////////////////////////////*/
        /*/////////////////// SIZE FUNCTIONS ///////////////////
        /////////////////////////////////////////////////////*/
        /**
         * Gets the depth dimension (first dimension) of the 3D vector
         *
         * @return Number of depth layers (w dimension)
         */
        size_t size_3dvec() const noexcept { return vec_3D.size(); }
        /**
         * Gets the row count of a specific depth layer in the 3D vector
         *
         * @param index Depth index (0-based)
         * @return Number of rows (n dimension) at specified depth
         * @throws out_of_range if depth index is invalid
         */
        size_t size_2dvec(size_t index) const
        {
            if (index >= vec_3D.size())
                throw out_of_range("Depth index out of range");
            return vec_3D[index].size();
        }
        /**
         * Gets the column count of a specific row in the 3D vector
         *
         * @param ind1 Depth index (0-based)
         * @param ind2 Row index (0-based)
         * @return Number of columns (m dimension) at specified position
         * @throws out_of_range if either index is invalid
         */
        size_t size_vec(size_t ind1, size_t ind2) const
        {
            if (ind1 >= vec_3D.size())
                throw out_of_range("Depth index out of range");
            if (ind2 >= vec_3D[ind1].size())
                throw out_of_range("Row index out of range");
            return vec_3D[ind1][ind2].size();
        }
        /**
         * Gets the depth dimension of the transposed representation
         *
         * @return Number of depth layers in transpose_3D
         */
        size_t size_transpose() const noexcept { return transpose_3D.size(); }
        /**
         * Gets the row count of a specific depth layer in transposed representation
         *
         * @param index Depth index (0-based) in transpose
         * @return Number of rows at specified depth in transpose
         * @throws out_of_range if depth index is invalid
         */
        size_t size_transpose(size_t index) const
        {
            if (index >= transpose_3D.size())
                throw out_of_range("Transposed depth index out of range");
            return transpose_3D[index].size();
        }
        /**
         * Gets the column count of a specific row in transposed representation
         *
         * @param ind1 Depth index (0-based) in transpose
         * @param ind2 Row index (0-based) in transpose
         * @return Number of columns at specified position in transpose
         * @throws out_of_range if either index is invalid
         */
        size_t size_transpose(size_t ind1, size_t ind2) const
        {
            if (ind1 >= transpose_3D.size())
                throw out_of_range("Transposed depth index out of range");
            if (ind2 >= transpose_3D[ind1].size())
                throw out_of_range("Transposed row index out of range");
            return transpose_3D[ind1][ind2].size();
        }
        /**
         * Gets the row count of the flattened representation
         *
         * @return Number of rows in flatten (2D representation)
         */
        size_t size_flatten() const noexcept { return flatten.size(); }
        /**
         * Gets the column count of a specific row in flattened representation
         *
         * @param index Row index (0-based) in flatten
         * @return Number of columns at specified row in flatten
         * @throws out_of_range if row index is invalid
         */
        size_t size_flatten(size_t index) const
        {
            if (index >= flatten.size())
                throw out_of_range("Flatten row index out of range");
            return flatten[index].size();
        }
        /**
         * @brief Returns the number of elements in the determinant vector.
         *
         * @return The size of the determinant vector as a size_t.
         */
        size_t size_determinant_vec() const { return determinant.size(); }
        /*/////////////////// END OF SIZE FUNCTIONS ///////////////////
        ////////////////////////////////////////////////////////////*/
        /*/////////////////// CLEAR FUNCTIONS ///////////////////
        //////////////////////////////////////////////////////*/
        /**
         * Clears all internal storage vectors (main, transposed, and flattened)
         *
         * @post All data structures are empty:
         *       - vec_3D cleared
         *       - transpose_3D cleared
         *       - flatten cleared
         */
        void clear_all() noexcept
        {
            vec_3D.clear();
            transpose_3D.clear();
            flatten.clear();
            determinant.clear();
        }
        /**
         * Clears the entire 3D vector while preserving other structures
         *
         * @post vec_3D is empty
         * @note Does not affect transpose_3D or flatten
         */
        void clear_3dvec() noexcept { vec_3D.clear(); }
        /**
         * Clears a specific depth layer in the 3D vector
         *
         * @param index Depth index to clear (0-based)
         * @throws out_of_range if index is invalid
         * @post Specified depth layer is empty
         */
        void clear_2dvec(size_t index)
        {
            if (index >= vec_3D.size())
                throw out_of_range("Depth index out of range");
            vec_3D[index].clear();
        }
        /**
         * Clears a specific row within a depth layer
         *
         * @param ind1 Depth index (0-based)
         * @param ind2 Row index (0-based)
         * @throws out_of_range if either index is invalid
         * @post Specified row vector is empty
         */
        void clear_vec(size_t ind1, size_t ind2)
        {
            if (ind1 >= vec_3D.size())
                throw out_of_range("Depth index out of range");
            if (ind2 >= vec_3D[ind1].size())
                throw out_of_range("Row index out of range");
            vec_3D[ind1][ind2].clear();
        }
        /**
         * Clears the entire transposed representation
         *
         * @post transpose_3D is empty
         * @note Does not affect vec_3D or flatten
         */
        void clear_transpose() noexcept { transpose_3D.clear(); }
        /**
         * Clears a specific depth layer in the transposed representation
         *
         * @param index Depth index to clear (0-based)
         * @throws out_of_range if index is invalid
         * @post Specified transposed depth layer is empty
         */
        void clear_transpose(size_t index)
        {
            if (index >= transpose_3D.size())
                throw out_of_range("Transposed depth index out of range");
            transpose_3D[index].clear();
        }
        /**
         * Clears a specific row in the transposed representation
         *
         * @param ind1 Depth index in transpose (0-based)
         * @param ind2 Row index in transpose (0-based)
         * @throws out_of_range if either index is invalid
         * @post Specified transposed row is empty
         */
        void clear_transpose(size_t ind1, size_t ind2)
        {
            if (ind1 >= transpose_3D.size())
                throw out_of_range("Transposed depth index out of range");
            if (ind2 >= transpose_3D[ind1].size())
                throw out_of_range("Transposed row index out of range");
            transpose_3D[ind1][ind2].clear();
        }
        /**
         * Clears the entire flattened representation
         *
         * @post flatten is empty
         * @note Does not affect vec_3D or transpose_3D
         */
        void clear_flatten() noexcept { flatten.clear(); }
        /**
         * Clears a specific row in the flattened representation
         *
         * @param index Row index to clear (0-based)
         * @throws out_of_range if index is invalid
         * @post Specified row in flatten is empty
         */
        void clear_flatten(size_t index)
        {
            if (index >= flatten.size())
                throw out_of_range("Flatten row index out of range");
            flatten[index].clear();
        }
        /**
         * @brief Clears the contents of the determinant vector.
         *
         * This function removes all elements from the determinant vector,
         * effectively resetting it to an empty state.
         */
        void clear_determinant_vec() noexcept { determinant.clear(); }
        /*/////////////////// END OF CLEAR FUNCTIONS ///////////////////
        /////////////////////////////////////////////////////////////*/
        /*/////////////////// EMPTY CHECK FUNCTIONS ///////////////////
        ////////////////////////////////////////////////////////////*/
        /**
         * Checks if the entire 3D vector is empty
         *
         * @return true if vec_3D has no depth layers, false otherwise
         */
        bool empty() const noexcept { return vec_3D.empty(); }
        /**
         * Checks if a specific depth layer is empty
         *
         * @param index Depth index to check (0-based)
         * @return true if the specified depth layer has no rows
         * @throws out_of_range if index is invalid
         */
        bool empty_2dvec(size_t index) const
        {
            if (index >= vec_3D.size())
                throw out_of_range("Depth index out of range");
            return vec_3D[index].empty();
        }
        /**
         * Checks if a specific row within a depth layer is empty
         *
         * @param ind1 Depth index (0-based)
         * @param ind2 Row index (0-based)
         * @return true if the specified row has no elements
         * @throws std::out_of_range if either index is invalid
         */
        bool empty_vec(size_t ind1, size_t ind2) const
        {
            if (ind1 >= vec_3D.size())
                throw out_of_range("Depth index out of range");
            if (ind2 >= vec_3D[ind1].size())
                throw out_of_range("Row index out of range");
            return vec_3D[ind1][ind2].empty();
        }
        /**
         * Checks if the entire transposed representation is empty
         *
         * @return true if transpose_3D has no depth layers, false otherwise
         */
        bool empty_transpose() const noexcept { return transpose_3D.empty(); }
        /**
         * Checks if a specific depth layer in transposed representation is empty
         *
         * @param index Depth index to check (0-based)
         * @return true if the specified transposed depth layer has no rows
         * @throws std::out_of_range if index is invalid
         */
        bool empty_transpose(size_t index) const
        {
            if (index >= transpose_3D.size())
                throw out_of_range("Transposed depth index out of range");
            return transpose_3D[index].empty();
        }
        /**
         * Checks if a specific row in transposed representation is empty
         *
         * @param ind1 Depth index in transpose (0-based)
         * @param ind2 Row index in transpose (0-based)
         * @return true if the specified transposed row has no elements
         * @throws std::out_of_range if either index is invalid
         */
        bool empty_transpose(size_t ind1, size_t ind2) const
        {
            if (ind1 >= transpose_3D.size())
                throw out_of_range("Transposed depth index out of range");
            if (ind2 >= transpose_3D[ind1].size())
                throw out_of_range("Transposed row index out of range");
            return transpose_3D[ind1][ind2].empty();
        }
        /**
         * Checks if the entire flattened representation is empty
         *
         * @return true if flatten has no rows, false otherwise
         */
        bool empty_flatten() const noexcept { return flatten.empty(); }
        /**
         * Checks if a specific row in flattened representation is empty
         *
         * @param index Row index to check (0-based)
         * @return true if the specified row in flatten has no elements
         * @throws out_of_range if index is invalid
         */
        bool empty_flatten(size_t index) const
        {
            if (index >= flatten.size())
                throw out_of_range("Flatten row index out of range");
            return flatten[index].empty();
        }
        /**
         * @brief Checks if the determinant vector is empty.
         *
         * @return true if the determinant vector is empty, false otherwise.
         *
         * @note This function does not modify the object and is noexcept.
         */
        bool empty_determinant_vec() const noexcept { return determinant.empty(); }
        /*/////////////////// END OF EMPTY CHECK FUNCTIONS ///////////////////
        ///////////////////////////////////////////////////////////////////*/
        /*/////////////////// OPERATOR FUNCTIONS ///////////////////
        /////////////////////////////////////////////////////////*/
        /**
         * Subscript operator for mutable depth layer access
         *
         * @param i Depth index (0-based)
         * @return Reference to the 2D matrix at specified depth
         * @warning No bounds checking - use with valid indices
         */
        vector<vector<T>> &operator[](size_t i) noexcept { return vec_3D[i]; }
        /**
         * Subscript operator for const depth layer access
         *
         * @param i Depth index (0-based)
         * @return Const reference to the 2D matrix at specified depth
         * @warning No bounds checking - use with valid indices
         */
        const vector<vector<T>> &operator[](size_t i) const noexcept
        {
            return vec_3D[i];
        }
        /**
         * Assignment operator for 3D vector replacement
         *
         * @param vec3d 3D vector to assign to the internal storage
         * @post Replaces current vec_3D with the input vector
         */
        void operator=(const vector<vector<vector<T>>> &vec3d) noexcept
        {
            vec_3D = vec3d;
        }
        /**
         * Equality operator for 3D vector comparison
         *
         * @param vec3d 3D vector to compare against
         * @return true if:
         *           - Both vectors are empty, OR
         *           - All depth layers have identical:
         *               - Row counts
         *               - Column counts
         *               - Element values
         *         false otherwise
         * @note Uses same_vec() for 2D matrix comparison
         */
        bool operator==(const vector<vector<vector<T>>> &vec3d) const noexcept
        {
            if (vec3d.empty() && vec_3D.empty())
                return true;
            if (vec3d.empty())
                return false;
            if (vec_3D.empty())
                return false;
            if (vec_3D.size() != vec3d.size())
                return false;
            for (size_t i = 0; i < vec3d.size(); i++)
            {
                if (vec3d[i].size() != vec_3D[i].size())
                    return false;
                for (size_t j = 0; j < vec3d[i].size(); j++)
                {
                    if (!same_vec(vec3d[i][j], vec_3D[i][j]))
                        return false;
                }
            }
            return true;
        }
        /*/////////////////// END OF OPERATOR FUNCTIONS ///////////////////
        ////////////////////////////////////////////////////////////////*/
        /**
         * Default destructor
         *
         * @note Automatically clears all managed resources
         * @warning Does not manually clear members - relies on vector destructors
         */
        ~vector_3d() = default;
    }; // end of the object vector_3d
    /**
     * A Pair-vector container that stores two vectors and their reversed versions.
     * Useful for comparing, printing, summing, and swapping two vectors together.
     *
     * @tparam T Type of elements stored in the vectors.
     */
    template <typename T>
    class VecPair
    {
        /*///////////////////private members/////////////////////
        ///////////////////////////////////////////////////////*/
    private:
        vector<T> vec1;
        vector<T> vec2;
        vector<T> vec1_rev;
        vector<T> vec2_rev;
        /*///////////////////public members/////////////////////
        //////////////////////////////////////////////////////*/
    public:
        /**
         * Default constructor
         */
        VecPair()
        {
            vec1 = {};
            vec2 = {};
            vec1_rev = {};
            vec2_rev = {};
        }
        /**
         * Parameterized constructor
         * @param v1 First vector
         * @param v2 Second vector
         */
        VecPair(const vector<T> &v1, const vector<T> &v2)
        {
            vec1 = v1;
            vec2 = v2;
            vec1_rev = reverse_vec(v1);
            vec2_rev = reverse_vec(v2);
        }
        /**
         * Copy constructor
         * @param other Another VecPair object to copy from
         */
        VecPair(const VecPair<T> &other)
        {
            vec1 = other.vec1;
            vec2 = other.vec2;
            vec1_rev = other.vec1_rev;
            vec2_rev = other.vec2_rev;
        }
        /*///////////////////empty functions/////////////////////
        //////////////////////////////////////////////////////*/
        /**
         * Checks if both vectors are empty
         * @return true if both vec1 and vec2 are empty, false otherwise
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        bool empty() const noexcept { return vec1.empty() && vec2.empty(); }
        /**
         * Checks if the first vector is empty
         * @return true if vec1 is empty, false otherwise
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        bool empty1() const noexcept { return vec1.empty(); }
        /**
         * Checks if the second vector is empty
         * @return true if vec2 is empty, false otherwise
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        bool empty2() const noexcept { return vec2.empty(); }
        /**
         * Checks if the reversed first vector is empty
         * @return true if vec1_rev is empty, false otherwise
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        bool empty_rev1() const noexcept { return vec1_rev.empty(); }
        /**
         * Checks if the reversed second vector is empty
         * @return true if vec2_rev is empty, false otherwise
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        bool empty_rev2() const noexcept { return vec2_rev.empty(); }
        /*//////////////end of empty functions//////////////////
        //////////////////////////////////////////////////////*/
        /*//////////////set and get functions//////////////////
        ////////////////////////////////////////////////////*/
        /**
         * Sets the values of both vectors and their reversed versions
         * @param v1 First vector
         * @param v2 Second vector
         */
        void set_vec(const vector<T> &v1, const vector<T> &v2) noexcept
        {
            vec1 = v1;
            vec2 = v2;
            vec1_rev = reverse_vec(v1);
            vec2_rev = reverse_vec(v2);
        }
        /**
         * Gets the first vector
         * @return A const reference to the first vector
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        const vector<T> &get_vec1() const noexcept { return vec1; }
        /**
         * Gets a copy of the first vector
         * @return A copy of the first vector
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        vector<T> get_copy_vec1() const noexcept { return vec1; }
        /**
         * Gets the second vector
         * @return A const reference to the second vector
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        const vector<T> &get_vec2() const noexcept { return vec2; }
        /**
         * Gets a copy of the second vector
         * @return A copy of the second vector
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        vector<T> get_copy_vec2() const noexcept { return vec2; }
        /**
         * Gets the reversed first vector
         * @return A const reference to the reversed first vector
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        const vector<T> &get_rev1() const noexcept { return vec1_rev; }
        /**
         * Gets a copy of the reversed first vector
         * @return A copy of the reversed first vector
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        vector<T> get_copy_rev1() const noexcept { return vec1_rev; }
        /**
         * Gets the reversed second vector
         * @return A const reference to the reversed second vector
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        const vector<T> &get_rev2() const noexcept { return vec2_rev; }
        /**
         * Gets a copy of the reversed second vector
         * @return A copy of the reversed second vector
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        vector<T> get_copy_rev2() const noexcept { return vec2_rev; }
        /*//////////////end of set and get functions//////////
        ////////////////////////////////////////////////////*/
        /**
         * Multiplies all elements of the first vector by a given number
         * @param num The number to multiply with
         * @return The result of the multiplication
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        long double Mult_vec1_ele(double num = 1) const noexcept
        {
            if (vec1.empty())
            {
                io::println_error("empty vector can not do this operation");
                return -1;
            }
            if (!num)
                return 0;
            long double result = num;
            for (const double &LNum : vec1)
                result *= LNum;
            return result;
        }
        /**
         * Multiplies all elements of the second vector by a given number
         * @param num The number to multiply with
         * @return The result of the multiplication
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        long double Mult_vec2_ele(double num = 1) const noexcept
        {
            if (vec2.empty())
            {
                io::println_error("empty vector can not do this operation");
                return -1;
            }
            if (!num)
                return 0;
            long double result = num;
            for (const double &LNum : vec2)
                result *= LNum;
            return result;
        }
        /**
         * Divides all elements of the first vector by a given number
         * @param num The number to divide with
         * @return The result of the division
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        long double Divi_vec1_ele(double num = 1) const noexcept
        {
            if (vec1.empty())
            {
                io::println_error("empty vector can not do this operation");
                return -1;
            }
            if (!num)
                return 0;
            long double result = num;
            for (const double &LNum : vec1)
                result /= LNum;
            return result;
        }
        /**
         * Divides all elements of the second vector by a given number
         * @param num The number to divide with
         * @return The result of the division
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        long double Divi_vec2_ele(double num = 1) const noexcept
        {
            if (vec2.empty())
            {
                io::println_error("empty vector can not do this operation");
                return -1;
            }
            if (!num)
                return 0;
            long double result = num;
            for (const double &LNum : vec2)
                result /= LNum;
            return result;
        }
        /**
         * Calculates the sum of all elements in the first vector
         * @param num Initial value to add to the sum (default is 0.0)
         * @return The total sum of elements in vec1
         * @note This function is noexcept, meaning it does not throw exceptions.
         * @throws Error if vec1 is empty
         */
        long double sum_vec1(double num = 0.0) const noexcept
        {
            if (vec1.empty())
            {
                io::println_error("empty vector can not do this operation");
                return -1;
            }
            long double sum = num; // Initialize properly
            for (const double &LNum : vec1)
                sum += LNum;
            return sum;
        }
        /**
         * Calculates the sum of all elements in the second vector
         * @param num Initial value to add to the sum (default is 0.0
         * @return The total sum of elements in vec2
         * @note This function is noexcept, meaning it does not throw exceptions.
         * @throws Error if vec2 is empty
         */
        long double sum_vec2(double num = 0.0) const noexcept
        {
            if (vec2.empty())
            {
                io::println_error("empty vector can not do this operation");
                return -1;
            }
            long double sum = num; // Initialize properly
            for (const double &LNum : vec2)
                sum += LNum;
            return sum;
        }
        /*//////////////size functions/////////////////////////
        ////////////////////////////////////////////////////*/
        /**
         * Returns the size of the first vector
         * @return The size of vec1
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        size_t size_vec1() const noexcept { return vec1.size(); }
        /**
         * Returns the size of the second vector
         * @return The size of vec2
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        size_t size_vec2() const noexcept { return vec2.size(); }
        /**
         * Returns the size of the reversed first vector
         * @return The size of vec1_rev
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        size_t size_rev1() const noexcept { return vec1_rev.size(); }
        /**
         * Returns the size of the reversed second vector
         * @return The size of vec2_rev
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        size_t size_rev2() const noexcept { return vec2_rev.size(); }
        /*//////////////////end of size functions//////////////////
        ////////////////////////////////////////////////////////*/
        /*//////////////////at functions//////////////////
        ///////////////////////////////////////////////*/
        /**
         * Accesses an element in the first vector by index
         * @param index Index of the element to access (0-based)
         * @return The element at the specified index in vec1
         * @throws out_of_range if index is invalid
         */
        T at_vec1(size_t index) const
        {
            if (index < 0 || index >= vec1.size())
                throw out_of_range("Index is out of range.");
            return vec1[index];
        }
        /**
         * Accesses an element in the second vector by index
         * @param index Index of the element to access (0-based)
         * @return The element at the specified index in vec2
         * @throws out_of_range if index is invalid
         */
        T at_vec2(size_t index) const
        {
            if (index < 0 || index >= vec2.size())
                throw out_of_range("Index is out of range.");
            return vec2[index];
        }
        /**
         * Accesses an element in the reversed first vector by index
         * @param index Index of the element to access (0-based)
         * @return The element at the specified index in vec1_rev
         * @throws out_of_range if index is invalid
         */
        T at_rev1(size_t index) const
        {
            if (index < 0 || index >= vec1_rev.size())
                throw out_of_range("Index is out of range.");
            return vec1_rev[index];
        }
        /**
         * Accesses an element in the reversed second vector by index
         * @param index Index of the element to access (0-based)
         * @return The element at the specified index in vec2_rev
         * @throws out_of_range if index is invalid
         */
        T at_rev2(size_t index) const
        {
            if (index < 0 || index >= vec2_rev.size())
                throw out_of_range("Index is out of range.");
            return vec2_rev[index];
        }
        /*//////////////end of at functions//////////////
        ///////////////////////////////////////////////*/
        /*/////////////////clear functions/////////////////
        ////////////////////////////////////////////////*/
        /**
         * Clears all vectors and their reversed versions
         * @post All vectors are empty
         * @note This function is noexcept, meaning it does not throw exceptions.
         * @warning Does not free memory, just clears the vectors.
         */
        void clear_all() noexcept
        {
            vec1.clear();
            vec2.clear();
            vec1_rev.clear();
            vec2_rev.clear();
        }
        /**
         * Clears the first vector
         * @post vec1 is empty
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void clear_vec1() noexcept { vec1.clear(); }
        /**
         * Clears the second vector
         * @post vec2 is empty
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void clear_vec2() noexcept { vec2.clear(); }
        /**
         * Clears the reversed first vector
         * @post vec1_rev is empty
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void clear_revvec1() noexcept { vec1_rev.clear(); }
        /**
         * Clears the reversed second vector
         * @post vec2_rev is empty
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void clear_revvec2() noexcept { vec2_rev.clear(); }
        /*///////////end of clear functions///////////
        ///////////////////////////////////////////*/
        /*/////////////////swap functions/////////////////
        ////////////////////////////////////////////////*/
        /**
         * Swaps the contents of the first and second vectors
         * @post vec1 and vec2 are swapped
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void swap_vecs() noexcept { vec1.swap(vec2); }
        /**
         * Swaps the contents of the reversed first and second vectors
         * @post vec1_rev and vec2_rev are swapped
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void swap_revvecs() noexcept { vec1_rev.swap(vec2_rev); }
        /*///////////end of swap functions/////////////////
        ////////////////////////////////////////////////*/
        /**
         * Prints the contents of both vectors
         * @note This function is noexcept, meaning it does not throw exceptions.
         * @warning Uses PrintVec() function to print each vector
         */
        void print() const noexcept
        {
            cout << "vec1: ";
            print_vec(vec1);
            cout << "vec2:";
            print_vec(vec2);
        }
        /**
         * Assignment operator for VecPair
         * @param vec Pair-vector to assign
         * @post Replaces current vec1 and vec2 with the input vector
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void operator=(const vector<T> &vec) noexcept
        {
            if (vec1.empty())
                vec1 = vec;
            else if (vec2.empty())
                vec2 = vec;
        }
        /**
         * Equality operator for VecPair
         * @param vec Pair-vector to compare
         * @return true if either vec1 or vec2 is equal to vec, false otherwise
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        bool operator==(const vector<T> &vec) const noexcept
        {
            return same_vec(vec, vec1) || same_vec(vec, vec2);
        }
        /**
         * Addition assignment operator for VecPair
         * @param vec Pair-vector to add
         * @post Adds the contents of vec to the first or second vector
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void operator+=(const vector<T> &vec) noexcept
        {
            if (vec.empty() || (vec1.empty() && vec2.empty()))
                return;
            if (vec1.empty())
                for (int i = 0; i < vec.size(); i++)
                    vec2.push_back(vec[i]);
            else if (vec2.empty())
                for (int i = 0; i < vec.size(); i++)
                    vec1.push_back(vec[i]);
            else
            {
                for (int i = 0; i < vec.size(); i++)
                    vec1.push_back(vec[i]);
                for (int i = 0; i < vec.size(); i++)
                    vec2.push_back(vec[i]);
            }
        }
        /**
         * Adds an element to the first or second vector
         * @param element Element to add
         * @post Adds the element to the first or second vector
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void operator+(T element) noexcept
        {
            if (vec1.empty() && vec2.empty())
                return;
            auto temp1 = vec1, temp2 = vec2;
            vec1.clear();
            vec2.clear();
            if (temp1.empty())
                for (int i = 0; i < temp2.size(); i++)
                    vec2.push_back(temp2[i] + element);
            else if (temp2.empty())
                for (int i = 0; i < temp1.size(); i++)
                    vec1.push_back(temp1[i] + element);
            else
            {
                for (int i = 0; i < temp1.size(); i++)
                    vec1.push_back(temp1[i] + element);
                for (int i = 0; i < temp2.size(); i++)
                    vec2.push_back(temp2[i] + element);
            }
        }
        /**
         * Adds a vector to the first or second vector
         * @param vec Vector to add
         * @post Adds the contents of vec to the first or second vector
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void operator+(const vector<T> &vec) noexcept
        {
            if (vec.empty() || (vec1.empty() && vec2.empty()))
                return;
            auto temp1 = vec1, temp2 = vec2;
            vec1.clear();
            vec2.clear();
            if (temp1.empty())
            {
                if (temp2.size() == vec.size())
                {
                    for (int i = 0; i < vec.size(); i++)
                        vec2.push_back(temp2[i] + vec[i]);
                }
                else if (temp2.size() > vec.size())
                {
                    for (int i = 0; i < vec.size(); i++)
                        vec2.push_back(temp2[i] + vec[i]);
                    for (int j = vec_end(vec.size()); j < temp2.size(); j++)
                        vec2.push_back(temp2[j]);
                }
                else
                {
                    for (int i = 0; i < temp2.size(); i++)
                        vec2.push_back(temp2[i] + vec[i]);
                    for (int j = vec_end(temp2.size()); j < vec.size(); j++)
                        vec2.push_back(vec[j]);
                }
            }
            else if (temp2.empty())
            {
                if (temp1.size() == vec.size())
                {
                    for (int i = 0; i < vec.size(); i++)
                        vec1.push_back(temp1[i] + vec[i]);
                }
                else if (temp1.size() > vec.size())
                {
                    for (int i = 0; i < vec.size(); i++)
                        vec1.push_back(temp1[i] + vec[i]);
                    for (int j = vec_end(vec.size()); j < temp1.size(); j++)
                        vec1.push_back(temp1[j]);
                }
                else
                {
                    for (int i = 0; i < temp1.size(); i++)
                        vec1.push_back(temp1[i] + vec[i]);
                    for (int j = vec_end(temp1.size()); j < vec.size(); j++)
                        vec1.push_back(vec[j]);
                }
            }
            else
            {
                if (vec.size() == temp1.size() && vec.size() == temp2.size())
                {
                    for (int i = 0; i < vec.size(); i++)
                        vec1.push_back(temp1[i] + vec[i]);
                    for (int i = 0; i < vec.size(); i++)
                        vec1.push_back(temp2[i] + vec[i]);
                }
                else if (vec.size() < temp1.size() && vec.size() < temp2.size())
                {
                    for (int i = 0; i < vec.size(); i++)
                        vec1.push_back(temp1[i] + vec[i]);
                    for (int j = vec_end(vec.size()); j < temp1.size(); j++)
                        vec1.push_back(temp1[j]);
                    for (int i = 0; i < vec.size(); i++)
                        vec2.push_back(temp2[i] + vec[i]);
                    for (int j = vec_end(vec.size()); j < temp2.size(); j++)
                        vec2.push_back(temp2[j]);
                }
                else if (vec.size() < temp1.size() && vec.size() > temp2.size())
                {
                    for (int i = 0; i < vec.size(); i++)
                        vec1.push_back(temp1[i] + vec[i]);
                    for (int j = vec_end(vec.size()); j < temp1.size(); j++)
                        vec1.push_back(temp1[j]);
                    for (int i = 0; i < temp2.size(); i++)
                        vec2.push_back(temp2[i] + vec[i]);
                    for (int j = vec_end(temp2.size()); j < vec.size(); j++)
                        vec2.push_back(vec[j]);
                }
                else
                {
                    for (int i = 0; i < temp1.size(); i++)
                        vec1.push_back(temp1[i] + vec[i]);
                    for (int j = vec_end(temp1.size()); j < vec.size(); j++)
                        vec1.push_back(vec[j]);
                    for (int i = 0; i < temp2.size(); i++)
                        vec2.push_back(temp2[i] + vec[i]);
                    for (int j = vec_end(temp2.size()); j < vec.size(); j++)
                        vec2.push_back(vec[j]);
                }
            }
        }
        /**
         * Subtraction operator for VecPair
         * @param vec Pair-vector to subtract
         * @post Subtracts the contents of vec from the first or second vector
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void operator-(T element) noexcept
        {
            if (vec1.empty() && vec2.empty())
                return;
            auto temp1 = vec1, temp2 = vec2;
            vec1.clear();
            vec2.clear();
            if (temp1.empty())
            {
                for (int i = 0; i < temp2.size(); i++)
                    vec2.push_back(temp2[i] - element);
            }
            else if (temp2.empty())
            {
                for (int i = 0; i < temp1.size(); i++)
                    vec1.push_back(temp1[i] - element);
            }
            else
            {
                for (int i = 0; i < temp1.size(); i++)
                    vec1.push_back(temp1[i] - element);
                for (int i = 0; i < temp2.size(); i++)
                    vec2.push_back(temp2[i] - element);
            }
        }
        /**
         * Subtracts a vector from the first or second vector
         * @param vec Vector to subtract
         * @post Subtracts the contents of vec from the first or second vector
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void operator-(const vector<T> &vec) noexcept
        {
            if (vec.empty() || (vec1.empty() && vec2.empty()))
                return;
            auto temp1 = vec1, temp2 = vec2;
            vec1.clear();
            vec2.clear();
            if (temp1.empty())
            {
                if (temp2.size() == vec.size())
                {
                    for (int i = 0; i < vec.size(); i++)
                        vec2.push_back(temp2[i] - vec[i]);
                }
                else if (temp2.size() > vec.size())
                {
                    for (int i = 0; i < vec.size(); i++)
                        vec2.push_back(temp2[i] - vec[i]);
                    for (int j = vec_end(vec.size()); j < temp2.size(); j++)
                        vec2.push_back(temp2[j]);
                }
                else
                {
                    for (int i = 0; i < temp2.size(); i++)
                        vec2.push_back(temp2[i] - vec[i]);
                    for (int j = vec_end(temp2.size()); j < vec.size(); j++)
                        vec2.push_back(vec[j]);
                }
            }
            else if (temp2.empty())
            {
                if (temp1.size() == vec.size())
                {
                    for (int i = 0; i < vec.size(); i++)
                        vec1.push_back(temp1[i] - vec[i]);
                }
                else if (temp1.size() > vec.size())
                {
                    for (int i = 0; i < vec.size(); i++)
                        vec1.push_back(temp1[i] - vec[i]);
                    for (int j = vec_end(vec.size()); j < temp1.size(); j++)
                        vec1.push_back(temp1[j]);
                }
                else
                {
                    for (int i = 0; i < temp1.size(); i++)
                        vec1.push_back(temp1[i] - vec[i]);
                    for (int j = vec_end(temp1.size()); j < vec.size(); j++)
                        vec1.push_back(vec[j]);
                }
            }
            else
            {
                if (vec.size() == temp1.size() && vec.size() == temp2.size())
                {
                    for (int i = 0; i < vec.size(); i++)
                        vec1.push_back(temp1[i] - vec[i]);
                    for (int i = 0; i < vec.size(); i++)
                        vec1.push_back(temp2[i] - vec[i]);
                }
                else if (vec.size() < temp1.size() && vec.size() < temp2.size())
                {
                    for (int i = 0; i < vec.size(); i++)
                        vec1.push_back(temp1[i] - vec[i]);
                    for (int j = vec_end(vec.size()); j < temp1.size(); j++)
                        vec1.push_back(temp1[j]);
                    for (int i = 0; i < vec.size(); i++)
                        vec2.push_back(temp2[i] - vec[i]);
                    for (int j = vec_end(vec.size()); j < temp2.size(); j++)
                        vec2.push_back(temp2[j]);
                }
                else if (vec.size() < temp1.size() && vec.size() > temp2.size())
                {
                    for (int i = 0; i < vec.size(); i++)
                        vec1.push_back(temp1[i] - vec[i]);
                    for (int j = vec_end(vec.size()); j < temp1.size(); j++)
                        vec1.push_back(temp1[j]);
                    for (int i = 0; i < temp2.size(); i++)
                        vec2.push_back(temp2[i] - vec[i]);
                    for (int j = vec_end(temp2.size()); j < vec.size(); j++)
                        vec2.push_back(vec[j]);
                }
                else
                {
                    for (int i = 0; i < temp1.size(); i++)
                        vec1.push_back(temp1[i] - vec[i]);
                    for (int j = vec_end(temp1.size()); j < vec.size(); j++)
                        vec1.push_back(vec[j]);
                    for (int i = 0; i < temp2.size(); i++)
                        vec2.push_back(temp2[i] - vec[i]);
                    for (int j = vec_end(temp2.size()); j < vec.size(); j++)
                        vec2.push_back(vec[j]);
                }
            }
        }
        /**
         * Multiplication operator for VecPair
         * @param element Element to multiply with
         * @post Multiplies the contents of vec1 and vec2 with the element
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void operator*(T element) noexcept
        {
            if (vec1.empty() && vec2.empty())
                return;
            auto temp1 = vec1, temp2 = vec2;
            vec1.clear();
            vec2.clear();
            if (temp1.empty())
            {
                for (int i = 0; i < temp2.size(); i++)
                    vec2.push_back(temp2[i] * element);
            }
            else if (temp2.empty())
            {
                for (int i = 0; i < temp1.size(); i++)
                    vec1.push_back(temp1[i] * element);
            }
            else
            {
                for (int i = 0; i < temp1.size(); i++)
                    vec1.push_back(temp1[i] * element);
                for (int i = 0; i < temp2.size(); i++)
                    vec2.push_back(temp2[i] * element);
            }
        }
        /**
         * Divides the contents of vec1 and vec2 by a given element
         * @param element Element to divide with
         * @post Divides the contents of vec1 and vec2 by the element
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void operator/(T element) noexcept
        {
            if (vec1.empty() && vec2.empty())
                return;
            auto temp1 = vec1, temp2 = vec2;
            vec1.clear();
            vec2.clear();
            if (temp1.empty())
            {
                for (int i = 0; i < temp2.size(); i++)
                    vec2.push_back(temp2[i] / element);
            }
            else if (temp2.empty())
            {
                for (int i = 0; i < temp1.size(); i++)
                    vec1.push_back(temp1[i] / element);
            }
            else
            {
                for (int i = 0; i < temp1.size(); i++)
                    vec1.push_back(temp1[i] / element);
                for (int i = 0; i < temp2.size(); i++)
                    vec2.push_back(temp2[i] / element);
            }
        }
        /**
         * Destructor for VecPair
         */
        ~VecPair() = default;
    };
    /**
     * A simple wrapper over std::vector to provide list-like operations,
     * such as push_front, pop_front, insert before/after, and reverse view.
     *
     * @tparam T The type of elements stored in the list.
     */
    template <typename T>
    class VecList
    {
        /*///////////////////private members/////////////////////
        ///////////////////////////////////////////////////////*/
    private:
        size_t list_size = -1; // Default size to -1 to indicate uninitialized
        vector<T> list;
        vector<T> revlist;
        /*///////////////////public members/////////////////////
        //////////////////////////////////////////////////////*/
    public:
        /**
         * Default constructor for VecList
         */
        VecList()
        {
            list = {};
            revlist = {};
        }
        /**
         * Constructor that initializes the list with an initializer list
         * @param init Initializer list to initialize the VecList
         */
        VecList(initializer_list<T> init) : list(init)
        {
            size_t num;
            list_size = static_cast<size_t>(list.size());
            if (list_size != -1)
            {
                if (list_size != num)
                {
                    throw runtime_error(
                        "Dimension Error: Initializer list dimensions do not match fixed "
                        "size");
                }
            }
        }
        /**
         * Constructor that initializes the list with a specified size and an
         * initializer list
         * @param num Size of the list
         * @param init Initializer list to initialize the VecList
         * @throws runtime_error if num is negative
         */
        VecList(int num, initializer_list<T> init) : list(init)
        {
            if (num < 0)
                throw runtime_error("size can not be negative");
            list_size = static_cast<size_t>(num);
        }
        /**
         * Constructor that initializes the list with a specified size
         * @param s Size of the list
         * @throws runtime_error if s is negative
         */
        VecList(size_t s)
        {
            if (s < 0)
            {
                io::println_error("size can not be negative");
                throw;
            }
            list_size = s;
        }
        /**
         * Copy constructor for VecList
         * @param other Another VecList to copy from
         */
        VecList(const VecList<T> &other)
        {
            list = other.list;
            revlist = other.revlist;
        }
        /**
         * Constructor that initializes the list with a vector
         * @param NewList Vector to initialize the VecList
         */
        VecList(const vector<T> &NewList)
        {
            list = NewList;
            revlist = reverse_vec(NewList);
        }
        /**
         * Constructor that initializes the list with a vector and a specified size
         * @param NewList Vector to initialize the VecList
         * @param s Size of the list
         * @throws runtime_error if s is negative
         */
        void set_list(const vector<T> &NewList) noexcept
        {
            list = NewList;
            revlist = reverse_vec(NewList);
        }
        /**
         * Sets the list with a vector and a specified size
         * @param NewList Vector to initialize the VecList
         * @param s Size of the list
         * @throws runtime_error if s is negative
         */
        void set_listsize(size_t s)
        {
            if (s < 0)
                throw runtime_error("size can not be negative");
            if (list_size != -1 && list.size() > s)
            {
                io::println_error(
                    "New size is smaller than current list size, cannot set new size");
                return;
            }
            list_size = s;
        }
        /**
         * Gets the current size of the list
         * @return The size of the list
         */
        const vector<T> &get_list() const noexcept { return list; }
        /**
         * Gets a copy of the current list
         * @return A copy of the list
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        vector<T> get_copy_list() const noexcept { return list; }
        /**
         * Gets the reversed list
         * @return A const reference to the reversed list
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        const vector<T> &get_revlist() const noexcept { return revlist; }
        /**
         * Gets a copy of the reversed list
         * @return A copy of the reversed list
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        vector<T> get_copy_revlist() const noexcept { return revlist; }
        /**
         * Gets the size of the list
         * @return The size of the list
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        T at_list(int index) const
        {
            if (index < 0 || index >= list.size())
                throw out_of_range("Index out of range");
            return list[index];
        }
        /**
         * Gets the element at the specified index in the reversed list
         * @param index Index of the element to access (0-based)
         * @return The element at the specified index in revlist
         * @throws out_of_range if index is invalid
         */
        T at_revlist(int index) const
        {
            if (index < 0 || index >= revlist.size())
                throw out_of_range("Index out of range");
            if (revlist.empty())
                throw runtime_error("Reversed list is empty");
            return revlist[index];
        }
        /**
         * Clears all elements from the list and the reversed list
         * @post Both list and revlist are empty
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void clear_all() noexcept
        {
            list.clear();
            revlist.clear();
        }
        /**
         * Clears the list
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void clear() noexcept { list.clear(); }
        /**
         * Clears the reversed list
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void clear_rev() noexcept { revlist.clear(); }
        /**
         * Reverses the list and updates the reversed list
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        long double sum(double num = 0.0) const noexcept
        {
            static_assert(is_numeric_type<T>::value,
                          "This operation is not supported for non-numeric types");
            if (list.empty())
            {
                io::println_error("empty list can not do this operation");
                return -1;
            }
            long double result = num;
            for (const double &LNum : list)
                result += LNum;
            return result;
        }
        /**
         * Multiplies all elements in the list by a given number
         * @param num The number to multiply by
         * @return The result of the multiplication
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        long double multiply(double num = 1) const noexcept
        {
            static_assert(is_numeric_type<T>::value,
                          "This operation is not supported for non-numeric types");
            if (list.empty())
            {
                io::println_error("empty list can not do this operation");
                return -1;
            }
            if (!num)
                return 0;
            long double result = num;
            for (const double &LNum : list)
                result *= num;
            return result;
        }
        /**
         * Divides all elements in the list by a given number
         * @param num The number to divide by
         * @return The result of the division
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        long double divide(double num = 1) const noexcept
        {
            static_assert(is_numeric_type<T>::value,
                          "This operation is not supported for non-numeric types");
            if (list.empty())
            {
                io::println_error("empty list can not do this operation");
                return -1;
            }
            if (!num)
                return 0;
            long double result = num;
            for (const double &LNum : list)
                result /= num;
            return result;
        }
        /**
         * Returns the size of the list
         * @return The size of the list
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        size_t size() const noexcept { return list.size(); }
        /**
         * Returns the size of the reversed list
         * @return The size of the reversed list
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        size_t size_rev() const noexcept { return revlist.size(); }
        /**
         * Pushes an element to the front of the list
         * @param Key The element to push to the front
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void push_front(T Key) noexcept
        {
            if (list_size != -1 && list.size() >= list_size)
            {
                io::println_error("List size limit reached, cannot push front");
                return;
            }
            vector<T> temp;
            temp.push_back(Key);
            for (int i = 0; i < list.size(); i++)
                temp.push_back(list[i]);
            list.clear();
            list = temp;
            temp.clear();
        }
        /**
         * Returns the element at the front of the list
         * @return The element at the front of the list
         * @throws runtime_error if the list is empty
         */
        T top_front()
        {
            if (list.empty())
                throw runtime_error("List is empty");
            return list[0];
        }
        /**
         * Pops the front element from the list
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void pop_front() noexcept
        {
            if (list.empty())
            {
                io::println_error("List is empty, cannot pop front");
                return;
            }
            vector<T> temp;
            for (int i = 1; i < list.size(); i++)
                temp.push_back(list[i]);
            list.clear();
            list = temp;
            temp.clear();
        }
        /**
         * Pushes an element to the back of the list
         * @param Key The element to push to the back
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void push_back(T Key) noexcept
        {
            if (list_size != -1 && list.size() >= list_size)
            {
                io::println_error("List size limit reached, cannot push back");
                return;
            }
            list.push_back(Key);
        }
        /**
         * Returns the element at the back of the list
         * @return The element at the back of the list
         * @throws runtime_error if the list is empty
         */
        T top_back()
        {
            if (list.empty())
                throw runtime_error("List is empty");
            return list[vec_end(list)];
        }
        /**
         * Pops the back element from the list
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void pop_back() noexcept
        {
            if (list.empty())
            {
                io::println_error("List is empty, cannot pop back");
                return;
            }
            list.pop_back();
        }
        /**
         * Inserts an element before a specified node in the list
         * @param Node The node before which to insert the new element
         * @param Key The element to insert
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        bool find(T Key) const noexcept
        {
            for (int i = 0; i < list.size(); i++)
                if (Key == list[i])
                    return true;
            return false;
        }
        /**
         * Finds the index of a specified element in the list
         * @param Key The element to find
         * @return The index of the element, or -1 if not found
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        int find_index(T Key) const noexcept
        {
            for (int i = 0; i < list.size(); i++)
                if (Key == list[i])
                    return i;
            return -1; // Not found
        }
        /**
         * Erases an element at a specified index in the list
         * @param index The index of the element to erase
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void erase(int index) noexcept
        {
            if (index < 0 || index >= list.size())
            {
                io::println_error("Index out of range");
                return;
            }
            vector<T> temp;
            for (int i = 0; i < list.size(); i++)
            {
                if (i == index)
                    continue;
                else
                    temp.push_back(list[i]);
            }
            list.clear();
            list = temp;
            temp.clear();
        }
        /**
         * Erases a specified element from the list
         * @param Key The element to erase
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void erase(T Key) noexcept
        {
            vector<T> temp;
            for (int i = 0; i < list.size(); i++)
            {
                if (Key == list[i])
                    continue;
                else
                    temp.push_back(list[i]);
            }
            list.clear();
            list = temp;
            temp.clear();
        }
        /**
         * Checks if the list is empty
         * @return True if the list is empty, false otherwise
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        bool empty() const noexcept { return list.empty(); }
        /**
         * Checks if the reversed list is empty
         * @return True if the reversed list is empty, false otherwise
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        bool empty_revlist() const noexcept { return revlist.empty(); }
        /**
         * Reverses the list and updates the reversed list
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void add_before(T Node, T Key) noexcept
        {
            vector<T> temp;
            for (int i = 0; i < list.size(); i++)
            {
                if (list[i] == Node)
                {
                    temp.push_back(Key);
                    temp.push_back(list[i]);
                }
                else
                    temp.push_back(list[i]);
            }
            list.clear();
            list = temp;
            temp.clear();
        }
        /**
         * Adds an element after a specified node in the list
         * @param Node The node after which to add the new element
         * @param Key The element to add
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void add_after(T Node, T Key) noexcept
        {
            vector<T> temp;
            for (int i = 0; i < list.size(); i++)
            {
                if (list[i] == Node)
                {
                    temp.push_back(list[i]);
                    temp.push_back(Key);
                }
                else
                    temp.push_back(list[i]);
            }
            list.clear();
            list = temp;
            temp.clear();
        }
        /**
         * Reverses the list and updates the reversed list
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void print() const noexcept
        {
            print("list: ");
            print_vec(list);
        }
        /**
         * Assignment operator for VecList
         * @param vec Vector to assign to the list
         * @post Replaces the current list with the input vector
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void operator=(const vector<T> &vec) noexcept
        {
            if (vec.size() > list_size && list_size != -1)
            {
                io::println_error(
                    "the vector size is larger than the list size limit, cannot set "
                    "list");
                return;
            }
            if (vec.empty())
                list = {};
            list = vec;
        }
        /**
         * Equality operator for VecList
         * @param vec Vector to compare with the list
         * @return True if the list is equal to the vector, false otherwise
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        bool operator==(const vector<T> &vec) const noexcept
        {
            if (vec.empty() && list.empty())
                return true;
            else if (vec.empty())
                return false;
            else if (list.empty())
                return false;
            else if (list.size() != vec.size())
                return false;
            for (int i = 0; i < vec.size(); i++)
                if (vec[i] != list[i])
                    return false;
            return true;
        }
        /**
         * Adds an element to the list
         * @param element Element to add
         * @post Adds the element to the list
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void operator+(T element)
        {
            static_assert(is_numeric_type<T>::value,
                          "This operation is not supported for non-numeric types");
            if (list.empty())
                return;
            auto temp = list;
            list.clear();
            for (int i = 0; i < temp.size(); i++)
                list.push_back(temp[i] + element);
        }
        /**
         * Adds a vector to the list
         * @param vec Vector to add
         * @post Adds the vector to the list
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void operator+(const vector<T> &vec)
        {
            static_assert(is_numeric_type<T>::value,
                          "This operation is not supported for non-numeric types");
            if (vec.empty() || list.empty())
                return;
            auto temp = list;
            list.clear();
            if (vec.size() == list.size())
            {
                for (int i = 0; i < temp.size(); i++)
                    list.push_back(temp[i] + vec[i]);
            }
            else if (temp.size() > vec.size())
            {
                if (temp.size() > list_size && list_size != -1)
                {
                    io::println_error("List size limit reached, cannot add vector");
                    return;
                }
                for (int i = 0; i < vec.size(); i++)
                    list.push_back(temp[i] + vec[i]);
                for (int j = vec.size() - 1; j < temp.size(); j++)
                    list.push_back(temp[j]);
            }
            else
            {
                if (vec.size() > list_size && list_size != -1)
                {
                    io::println_error("List size limit reached, cannot add vector");
                    return;
                }
                for (int i = 0; i < temp.size(); i++)
                    list.push_back(temp[i] + vec[i]);
                for (int j = temp.size() - 1; j < vec.size(); j++)
                    list.push_back(temp[j]);
            }
        }
        /**
         * Subtracts an element from the list
         * @param element Element to subtract
         * @post Subtracts the element from the list
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void operator-(T element)
        {
            static_assert(is_numeric_type<T>::value == false,
                          "This operation is not supported for non-numeric types");
            if (list.empty())
                return;
            auto temp = list;
            list.clear();
            for (int i = 0; i < temp.size(); i++)
                list.push_back(temp[i] - element);
        }
        /**
         * Subtracts a vector from the list
         * @param vec Vector to subtract
         * @post Subtracts the vector from the list
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void operator-(const vector<T> &vec)
        {
            static_assert(is_numeric_type<T>::value == false,
                          "This operation is not supported for non-numeric types");
            if (vec.empty() || list.empty())
                return;
            auto temp = list;
            list.clear();
            if (vec.size() == list.size())
            {
                for (int i = 0; i < temp.size(); i++)
                    list.push_back(temp[i] + vec[i]);
            }
            else if (temp.size() > vec.size())
            {
                if (temp.size() > list_size && list_size != -1)
                {
                    io::println_error("List size limit reached, cannot subtract vector");
                    return;
                }
                for (int i = 0; i < vec.size(); i++)
                    list.push_back(temp[i] - vec[i]);
                for (int j = vec.size() - 1; j < temp.size(); j++)
                    list.push_back(temp[j]);
            }
            else
            {
                if (vec.size() > list_size && list_size != -1)
                {
                    io::println_error("List size limit reached, cannot subtract vector");
                    return;
                }
                for (int i = 0; i < temp.size(); i++)
                    list.push_back(temp[i] - vec[i]);
                for (int j = temp.size() - 1; j < vec.size(); j++)
                    list.push_back(temp[j]);
            }
        }
        /**
         * Multiplies the list by a scalar
         * @param element Scalar to multiply by
         * @post Multiplies each element in the list by the scalar
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void operator*(T element)
        {
            static_assert(is_numeric_type<T>::value,
                          "This operation is not supported for non-numeric types");
            if (list.empty())
                return;
            auto temp = list;
            list.clear();
            for (int i = 0; i < temp.size(); i++)
                list.push_back(temp[i] * element);
        }
        /**
         * Divides the list by a scalar
         * @param element Scalar to divide by
         * @post Divides each element in the list by the scalar
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        void operator/(T element)
        {
            static_assert(is_numeric_type<T>::value == false,
                          "This operation is not supported for non-numeric types");
            if (list.empty())
                return;
            auto temp = list;
            list.clear();
            for (int i = 0; i < temp.size(); i++)
                list.push_back(temp[i] / element);
        }
        /**
         * Index operator for VecList
         * @param i Index to access
         * @return Reference to the element at the specified index
         * @note This function is noexcept, meaning it does not throw exceptions.
         */
        T operator[](size_t i) const
        {
            if (list.empty())
                throw("empty list don't return value");
            if (i >= list.size() || i < 0)
                throw("out limites index");
            return list[i];
        }
        /**
         * Destructor for VecList
         */
        ~VecList() = default;
    };
};
#endif // PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_VECTOR_TOOLS_HPP