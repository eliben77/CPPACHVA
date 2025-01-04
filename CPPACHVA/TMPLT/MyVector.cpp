#include <iostream>
#include <stdexcept>
#include <initializer_list>

// Template class for a generic vector-like container
template <typename T>
class SimpleVector {
private:
    T* data;               // Pointer to dynamically allocated array
    size_t capacity;       // Total capacity of the container
    size_t size;           // Current number of elements in the container

    // Resize the container when needed
    void resize(size_t new_capacity) {
        T* new_data = new T[new_capacity];  // Allocate new array
        for (size_t i = 0; i < size; ++i) { // Copy old data
            new_data[i] = data[i];
        }
        delete[] data;                      // Free old memory
        data = new_data;
        capacity = new_capacity;
    }

public:
    // Default Constructor
    SimpleVector(size_t initial_capacity = 10)
        : capacity(initial_capacity), size(0) {
        data = new T[capacity];
    }

    // Initializer list constructor
    SimpleVector(std::initializer_list<T> init_list)
        : capacity(init_list.size()), size(init_list.size()) {
        data = new T[capacity];
        size_t index = 0;
        for (const auto& elem : init_list) {
            data[index++] = elem;
        }
    }

    // Copy Constructor (Deep Copy)
    SimpleVector(const SimpleVector& other)
        : capacity(other.capacity), size(other.size) {
        data = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Move Constructor
    SimpleVector(SimpleVector&& other) noexcept
        : data(other.data), capacity(other.capacity), size(other.size) {
        other.data = nullptr; // Leave the old object in a valid state
        other.capacity = 0;
        other.size = 0;
    }

    // Destructor
    ~SimpleVector() {
        delete[] data; // Free allocated memory
    }

    // Assignment Operator (Copy Assignment)
    SimpleVector& operator=(const SimpleVector& other) {
        if (this == &other) return *this; // Self-assignment check
        delete[] data;                    // Free old memory

        capacity = other.capacity;
        size = other.size;
        data = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        return *this;
    }

    // Move Assignment Operator
    SimpleVector& operator=(SimpleVector&& other) noexcept {
        if (this == &other) return *this; // Self-assignment check
        delete[] data;                    // Free old memory

        data = other.data;
        capacity = other.capacity;
        size = other.size;

        other.data = nullptr; // Leave the old object in a valid state
        other.capacity = 0;
        other.size = 0;
        return *this;
    }

    // Access Operators
    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Equality Operators
    bool operator==(const SimpleVector& other) const {
        if (size != other.size) return false;
        for (size_t i = 0; i < size; ++i) {
            if (data[i] != other.data[i]) return false;
        }
        return true;
    }

    bool operator!=(const SimpleVector& other) const {
        return !(*this == other);
    }

    // Add an element to the vector
    void push_back(const T& value) {
        if (size == capacity) {
            resize(capacity * 2); // Double the capacity if full
        }
        data[size++] = value;
    }

    // Remove the last element
    void pop_back() {
        if (size == 0) {
            throw std::underflow_error("Cannot pop from an empty vector");
        }
        --size;
    }

    // Insert an element at a specific position
    void insert(size_t index, const T& value) {
        if (index > size) {
            throw std::out_of_range("Index out of range");
        }
        if (size == capacity) {
            resize(capacity * 2);
        }
        for (size_t i = size; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++size;
    }

    // Erase an element at a specific position
    void erase(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }

    // Get the current size of the vector
    size_t get_size() const {
        return size;
    }

    // Nested Iterator class
    class Iterator {
    private:
        T* current;

    public:
        Iterator(T* start) : current(start) {}

        T& operator*() { return *current; }            // Dereference operator
        Iterator& operator++() { ++current; return *this; } // Prefix increment
        Iterator& operator--() { --current; return *this; } // Prefix decrement
        bool operator!=(const Iterator& other) const { return current != other.current; }
        bool operator==(const Iterator& other) const { return current == other.current; }
    };

    // Begin iterator
    Iterator begin() { return Iterator(data); }

    // End iterator
    Iterator end() { return Iterator(data + size); }
};

// Main function demonstrating extended functionality
int main() {
    // Example 1: Initialize with initializer list
    SimpleVector<int> vec = {10, 20, 30, 40, 50};
    std::cout << "Initial vector: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Example 2: Insert and erase
    vec.insert(2, 25); // Insert 25 at index 2
    std::cout << "After inserting 25 at index 2: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    vec.erase(4); // Erase element at index 4
    std::cout << "After erasing element at index 4: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Example 3: Copy and move semantics
    SimpleVector<int> vecCopy = vec; // Copy
    SimpleVector<int> vecMove = std::move(vec); // Move

    std::cout << "Copy of vector: ";
    for (auto it = vecCopy.begin(); it != vecCopy.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
