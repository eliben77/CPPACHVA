#include "Mat.hpp"

// Constructor
SquareMat::SquareMat(int n) : size(n) {
    if (size <= 0) throw std::invalid_argument("SquareMat size must be positive.");
    data = new int*[size];
    for (int i = 0; i < size; ++i) {
        data[i] = new int[size];
        for (int j = 0; j < size; ++j) data[i][j] = 0;
    }
}

// Destructor
SquareMat::~SquareMat() {
    for (int i = 0; i < size; ++i) delete[] data[i];
    delete[] data;
}

// Copy constructor
SquareMat::SquareMat(const SquareMat& other) : size(other.size) {
    data = new int*[size];
    for (int i = 0; i < size; ++i) {
        data[i] = new int[size];
        for (int j = 0; j < size; ++j) data[i][j] = other.data[i][j];
    }
}

// Copy assignment operator
SquareMat& SquareMat::operator=(const SquareMat& other) {
    if (this == &other) return *this;

    for (int i = 0; i < size; ++i) delete[] data[i];
    delete[] data;

    size = other.size;
    data = new int*[size];
    for (int i = 0; i < size; ++i) {
        data[i] = new int[size];
        for (int j = 0; j < size; ++j) data[i][j] = other.data[i][j];
    }
    return *this;
}

// Addition
SquareMat SquareMat::operator+(const SquareMat& other) const {
    if (size != other.size) throw std::invalid_argument("Matrices must have the same size for addition.");
    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result.data[i][j] = data[i][j] + other.data[i][j];
    return result;
}

// Subtraction
SquareMat SquareMat::operator-(const SquareMat& other) const {
    if (size != other.size) throw std::invalid_argument("Matrices must have the same size for subtraction.");
    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result.data[i][j] = data[i][j] - other.data[i][j];
    return result;
}

// Scalar multiplication
SquareMat SquareMat::operator*(int scalar) const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result.data[i][j] = data[i][j] * scalar;
    return result;
}

// Matrix-to-matrix multiplication
SquareMat SquareMat::operator*(const SquareMat& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must have the same size for multiplication.");
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

// Scalar division
SquareMat SquareMat::operator/(int scalar) const {
    if (scalar == 0) throw std::invalid_argument("Division by zero.");
    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result.data[i][j] = data[i][j] / scalar;
    return result;
}

// Modulus by scalar
SquareMat SquareMat::operator%(int scalar) const {
    if (scalar == 0) throw std::invalid_argument("Modulus by zero.");
    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result.data[i][j] = data[i][j] % scalar;
    return result;
}

// Element-wise multiplication
SquareMat SquareMat::operator%(const SquareMat& other) const {
    if (size != other.size) throw std::invalid_argument("Matrices must have the same size for element-wise multiplication.");
    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result.data[i][j] = data[i][j] * other.data[i][j];
    return result;
}

// Power operator
SquareMat SquareMat::operator^(int power) const {
    if (power < 0) throw std::invalid_argument("Negative powers not supported.");
    if (power == 0) {
        SquareMat identity(size);
        for (int i = 0; i < size; ++i) identity.data[i][i] = 1;
        return identity;
    }
    SquareMat result = SquareMat(*this);
    for (int i = 1; i < power; ++i) result = (*this)* result  ;
    return result;
}

// Negation
SquareMat SquareMat::operator-() const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result.data[i][j] = -data[i][j];
    return result;
}

// Transposition
SquareMat& SquareMat::operator~()  {
    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j){
            auto temp = data[i][j];
            data[i][j] = data[j][i];
            data[j][i] = temp;
        }
            
    return *this;
}

// Pre-increment
SquareMat& SquareMat::operator++() {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            ++data[i][j];
    return *this;
}

// Post-increment
SquareMat SquareMat::operator++(int) {
    SquareMat temp = *this;
    ++(*this);
    return temp;
}

// Pre-decrement
SquareMat& SquareMat::operator--() {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            --data[i][j];
    return *this;
}

// Post-decrement
SquareMat SquareMat::operator--(int) {
    SquareMat temp = *this;
    --(*this);
    return temp;
}

// Equality operator
bool SquareMat::operator==(const SquareMat& other) const {
    if (size != other.size) return false;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            if (data[i][j] != other.data[i][j]) return false;
    return true;
}

// Inequality operator
bool SquareMat::operator!=(const SquareMat& other) const {
    return !(*this == other);
}

// Compound assignment (+=)
SquareMat& SquareMat::operator+=(const SquareMat& other) {
    if (size != other.size) throw std::invalid_argument("Matrices must have the same size.");
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            data[i][j] += other.data[i][j];
    return *this;
}

// Compound assignment (-=)
SquareMat& SquareMat::operator-=(const SquareMat& other) {
    if (size != other.size) throw std::invalid_argument("Matrices must have the same size.");
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            data[i][j] -= other.data[i][j];
    return *this;
}

// Access operator ()
int& SquareMat::operator()(int i, int j) {
    if (i < 0 || i >= size || j < 0 || j >= size) throw std::out_of_range("Index out of bounds.");
    return data[i][j];
}

// Access operator []
int* SquareMat::operator[](int index) const {
    if (index < 0 || index >= size) throw std::out_of_range("Index out of bounds.");
    return data[index];
}

// Scalar * Matrix (global)
SquareMat operator*(int scalar, const SquareMat& matrix) {
    return matrix * scalar;
}

// Output stream operator
std::ostream& operator<<(std::ostream& os, const SquareMat& mat) {
    for (int i = 0; i < mat.size; ++i) {
        for (int j = 0; j < mat.size; ++j) {
            os << mat.data[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}
