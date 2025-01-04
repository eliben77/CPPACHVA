
class Box
{
    int *resource;
    int size;

public:
    Box(int s) : size(s), resource(new int[s]) {};
    ~Box() { delete resource; } // 1
    Box(const Box &o) : size(o.size), resource(new int[o.size]) {} // 2
    Box &operator=(const Box &other) // 3
    {
        if (this == &other)
            return *this;
        delete (this->resource);
        this->size = other.size;
        resource = new int[size];
        for (int i = 0; i < size; i++)
            resource[i] = other.resource[i];
    }
};

Box f(Box &b1)
{
    // do something

    return b1;
}

int main()
{
    Box b(5);

    b = f(b);

    return 0;
}