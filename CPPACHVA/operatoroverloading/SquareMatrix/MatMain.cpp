#include "Mat.hpp"

int main() {
    SquareMat mat1(3);
    mat1(0, 0) = 1; mat1(1, 1) = 2; mat1(2, 2) = 3;
    std::cout << "Matrix 1:\n" << mat1;

    SquareMat mat2(3);
    mat2(0, 0) = 4; mat2(1, 1) = 5; mat2(2, 2) = 6;
    std::cout << "Matrix 2:\n" << mat2;

    // Test addition
    SquareMat sum = mat1 + mat2;
    std::cout << "Sum of matrices:\n" << sum;

    // Test subtraction
    SquareMat diff = mat1 - mat2;
    std::cout << "Difference of matrices:\n" << diff;

    // Test scalar multiplication
    SquareMat scalarProd = mat1 * 3;
    std::cout << "Matrix 1 * 3:\n" << scalarProd;

    // Test scalar division
    SquareMat scalarDiv = mat2 / 2;
    std::cout << "Matrix 2 / 2:\n" << scalarDiv;

    // Test element-wise multiplication
    SquareMat elemMul = mat1 % mat2;
    std::cout << "Element-wise multiplication of matrices:\n" << elemMul;

    // Test negation
    SquareMat neg = -mat1;
    std::cout << "Negated matrix 1:\n" << neg;

    // Test transpose
    SquareMat transpose = ~mat1;
    std::cout << "Transpose of matrix 1:\n" << transpose;

    // Test matrix power
    SquareMat powMat = mat1 ^ 2;
    std::cout << "Matrix 1 squared:\n" << powMat;

    // Test increment/decrement
    std::cout << "Matrix 1 after pre-increment:\n" << ++mat1;
    std::cout << "Matrix 1 after post-increment:\n" << mat1++;
    std::cout << "Matrix 1 after pre-decrement:\n" << --mat1;
    std::cout << "Matrix 1 after post-decrement:\n" << mat1--;

    // Test equality and inequality
    std::cout << "Matrix 1 == Matrix 2: " << (mat1 == mat2 ? "True" : "False") << std::endl;
    std::cout << "Matrix 1 != Matrix 2: " << (mat1 != mat2 ? "True" : "False") << std::endl;

    // Test scalar * matrix
    SquareMat scalarTimesMatrix = 5 * mat1;
    std::cout << "5 * Matrix 1:\n" << scalarTimesMatrix;

    return 0;
}
