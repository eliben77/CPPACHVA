#include <iostream>
#include <stdexcept>  // For exceptions like std::invalid_argument

class SquareMat {
private:
    int** data;  // 2D array (matrix) to hold integer values
    int size;    // Size of the square matrix

public:
    // Constructor: Allocate memory for the matrix
    SquareMat(int n) : size(n) {
        if (size <= 0) {
            throw std::invalid_argument("SquareMat size must be positive.");
        }
        
        data = new int*[size];
        for (int i = 0; i < size; ++i) {
            data[i] = new int[size];  // Allocate each row
        }

        // Initialize the matrix with zeroes
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                data[i][j] = 0;
            }
        }
    }

    // Destructor: Release allocated memory
    ~SquareMat() {
        for (int i = 0; i < size; ++i) {
            delete[] data[i];  // Delete each row
        }
        delete[] data;  // Delete the array of row pointers
    }

    // Copy constructor: Deep copy the matrix
    SquareMat(const SquareMat& other) : size(other.size), data(new int*[size]) {
        for (int i = 0; i < size; ++i) {
            data[i] = new int[size];  // Allocate each row for the new matrix
        }

        // Copy the data from the other matrix
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    // Copy assignment operator: Deep copy and release old resource
    SquareMat& operator=(const SquareMat& other) {
        if (this == &other) {
            return *this;  // Handle self-assignment
        }

        // First, release the existing memory
        for (int i = 0; i < size; ++i) {
            delete[] data[i];
        }
        delete[] data;

        // Allocate new memory based on the other matrix size
        size = other.size;
        data = new int*[size];
        for (int i = 0; i < size; ++i) {
            data[i] = new int[size];
        }

        // Copy the data from the other matrix
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                data[i][j] = other.data[i][j];
            }
        }

        return *this;
    }

    // Addition operator: Add two matrices
    SquareMat operator+(const SquareMat& other) const {
        if (size != other.size) {
            throw std::invalid_argument("Matrices must have the same size for addition");
        }

        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Multiplication operator: Multiply two matrices
    SquareMat operator*(const SquareMat& other) const {
        if (size != other.size) {
            throw std::invalid_argument("Matrices must have the same size for multiplication");
        }

        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.data[i][j] = 0;  // Initialize to zero
                for (int k = 0; k < size; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Scalar multiplication operator: Multiply matrix by scalar
    SquareMat operator*(int scalar) const {
        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.data[i][j] = data[i][j] * scalar;
            }
        }
        return result;
    }

    
    // Equality operator: Compare if two matrices are equal
    bool operator==(const SquareMat& other) const {
        if (size != other.size) {
            return false;
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (data[i][j] != other.data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    // Access element via [][] operator
    int* operator[](int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];  // Return the row at the given index
    }

    // Friend function to overload the << operator
    friend std::ostream& operator<<(std::ostream& os, const SquareMat& matrix);

    // Get size of the matrix
    int getSize() const {
        return size;
    }
};

// Overload the << operator for displaying a matrix
std::ostream& operator<<(std::ostream& os, const SquareMat& matrix) {
    for (int i = 0; i < matrix.size; ++i) {
        for (int j = 0; j < matrix.size; ++j) {
            os << matrix.data[i][j] << " ";
        }
        os << std::endl;  // Newline after each row
    }
    return os;
}

// Global function to allow scalar * SquareMat (instead of SquareMat * scalar)
SquareMat operator*(int scalar, const SquareMat& matrix) {
    return matrix * scalar;  // Reuse the SquareMat's scalar multiplication logic
}

int main() {
    try {
        // Create a 3x3 matrix and set values
        SquareMat matrix1(3);
        matrix1[0][0] = 1;
        matrix1[1][1] = 2;
        matrix1[2][2] = 3;

        std::cout << "SquareMat 1:" << std::endl;
        std::cout << matrix1 << std::endl;

        // Create another 3x3 matrix and set values
        SquareMat matrix2(3);
        matrix2[0][0] = 4;
        matrix2[1][1] = 5;
        matrix2[2][2] = 6;

        std::cout << "SquareMat 2:" << std::endl;
        std::cout << matrix2 << std::endl;

        // Test matrix addition
        SquareMat sum = matrix1 + matrix2;
        std::cout << "SquareMat 1 + SquareMat 2:" << std::endl;
        std::cout << sum << std::endl;

        // Test matrix multiplication
        SquareMat product = matrix1 * matrix2;
        std::cout << "SquareMat 1 * SquareMat 2:" << std::endl;
        std::cout << product << std::endl;

        // Test scalar multiplication (matrix * scalar)
        SquareMat scalarProduct1 = matrix1 * 5;
        std::cout << "SquareMat 1 * 5:" << std::endl;
        std::cout << scalarProduct1 << std::endl;

        // Test scalar multiplication (scalar * matrix)
        SquareMat scalarProduct2 = 5 * matrix1;
        std::cout << "5 * SquareMat 1:" << std::endl;
        std::cout << scalarProduct2 << std::endl;

        // Test matrix equality
        std::cout << "SquareMat 1 == SquareMat 2: " << (matrix1 == matrix2 ? "True" : "False") << std::endl;

        // Test matrix equality after modifying matrix2 to match matrix1
        matrix2[0][0] = 1;
        matrix2[1][1] = 2;
        matrix2[2][2] = 3;
        std::cout << "SquareMat 1 == SquareMat 2 after modification: " << (matrix1 == matrix2 ? "True" : "False") << std::endl;

        // Test invalid matrix size (this should throw an exception)
         SquareMat matrixInvalid(0);  // Uncomment this to test the exception
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        
    }

    return 0;
}

/*Here is a list of additional operators to implement in your `SquareMat` class:
 1. Subtraction Operator (`-`)
 Subtracts two matrices of the same size element-wise.
 2. Negation Operator (`-`)
 Negates all elements of the matrix, converting positive values to negative, and vice versa.
 3. Matrix Transposition (`~`)
 Transposes the matrix, swapping rows and columns.
 4. Element-wise Multiplication (`%`)
 Multiplies corresponding elements of two matrices of the same size.
 5. Scalar Division (`/`)
 Divides all elements of the matrix by a scalar.
 6. Modulus with Scalar (`% int`)
 Performs modulus operation on each matrix element with respect to an integer scalar.
 7. Power Operator (`^`)
 Raises the matrix to a given power by multiplying it with itself multiple times.
 8. Element Access with Two Indices (`()`)
 Allows access to elements using two indices, like `matrix(i, j)`.
 9. Pre- and Post-Increment/Decrement (`++`, `--`)
 Increases or decreases all matrix elements by 1, useful for quick element adjustments.
 10. Inequality Operator (`!=`)
 Checks if two matrices are not equal.
 11. Comparison Operators (`<`, `>`, `<=`, `>=`)
 Compares two matrices based on a certain rule, like comparing the sum of elements.
 12. Compound Assignment Operators (`+=`, `-=`, `*=`, `/=`, `%=`)
 Performs operations like addition, subtraction, multiplication, etc., and assigns the result to the matrix.
*/