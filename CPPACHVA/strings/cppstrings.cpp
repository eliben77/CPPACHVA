#include <iostream>
#include <string>
#include <algorithm>

using std::string;

// Example 1: String Declaration and Initialization
void stringInitialization() {
    string greeting = "Hello, World!";
    std::string name = "Alice";

    std::cout << "Greeting: " << greeting << std::endl;
    std::cout << "Name: " << name << std::endl;
}

// Example 2: String Concatenation
void stringConcatenation() {
    std::string firstName = "John";
    std::string lastName = "Doe";

    std::string fullName = firstName + " " + lastName;
    std::cout << "Full Name: " << fullName << std::endl;
}

// Example 3: Accessing Characters in a String
void characterAccess() {
    std::string word = "Hello";

    std::cout << "First character: " << word[0] << std::endl;
    std::cout << "Last character: " << word[word.length() - 1] << std::endl;

    // Modifying a character
    word[0] = 'J';
    std::cout << "Modified word: " << word << std::endl;
}

// Example 4: Finding Substrings
void substringFinding() {
    std::string sentence = "The quick brown fox jumps over the lazy dog";

    // Finding the position of a substring
    size_t pos = sentence.find("fox");
    if (pos != std::string::npos) {
        std::cout << "'fox' found at position: " << pos << std::endl;
    }

    // Finding the position of a substring from the end
    pos = sentence.rfind("the");
    if (pos != std::string::npos) {
        std::cout << "Last 'the' found at position: " << pos << std::endl;
    }
}

// Example 5: Replacing Substrings
void substringReplacement() {
    std::string sentence = "I love ice cream";

    // Replacing a word
    sentence.replace(7, 4, "pizza");  // Replace "ice" with "pizza"
    std::cout << "Modified sentence: " << sentence << std::endl;
}

// Example 6: Inserting and Erasing
void stringInsertionAndErasure() {
    std::string sentence = "I programming";

    // Inserting a word
    sentence.insert(2, " love");
    std::cout << "After insertion: " << sentence << std::endl;

    // Erasing a part of the string
    sentence.erase(2, 5);
    std::cout << "After erasure: " << sentence << std::endl;
}

// Example 7: Converting Strings to Numbers and Vice Versa
void stringConversion() {
    std::string numStr = "12345";

    // Converting string to integer
    int num = std::stoi(numStr);
    std::cout << "String to int: " << num << std::endl;

    // Converting integer to string
    int anotherNum = 6789;
    std::string anotherNumStr = std::to_string(anotherNum);
    std::cout << "Int to string: " << anotherNumStr << std::endl;
}

// Example 8: Iterating Over a String
void stringIteration() {
    std::string word = "Iteration";

    // Using a range-based for loop
    for (char c : word) {
        std::cout << c << ' ';
    }
    std::cout << std::endl;

    // Using an iterator
    for (auto it = word.begin(); it != word.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

// Example 9: Transforming Strings
void stringTransformation() {
    std::string str = "Hello World";

    // Converting to uppercase
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    std::cout << "Uppercase: " << str << std::endl;

    // Converting to lowercase
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    std::cout << "Lowercase: " << str << std::endl;
}

// Example 10: String Comparison
void stringComparison() {
    std::string str1 = "Apple";
    std::string str2 = "Orange";

    if (str1 < str2) {
        std::cout << str1 << " comes before " << str2 << std::endl;
    }
    else if (str1 > str2) {
        std::cout << str1 << " comes after " << str2 << std::endl;
    }
    else {
        std::cout << str1 << " is equal to " << str2 << std::endl;
    }
}

int main() {
    //();
    //stringConcatenation();
    //characterAccess();
    substringFinding();
    substringReplacement();
    stringInsertionAndErasure();
    stringConversion();
    stringIteration();
    stringTransformation();
    stringComparison();

    return 0;
}
