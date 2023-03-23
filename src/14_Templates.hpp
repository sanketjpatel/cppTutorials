#ifndef Templates_HPP
#define Templates_HPP

template <class T>
class MyVector
{
    T *v;

public:
    int size;
    MyVector() {
        size = 0;
        std::cout << "Size: " << size << std::endl;
        v = new T[size];
        for (int i = 0; i < size; i++) {
            v[i] = 0;
        }
    }

    MyVector(MyVector &a) {
        size = a.size;
        // length(a) works only for strings. For other objects, sizeof should be used.
        // In that case, you should know the type of members in the object, and assign values accordingly
        std::cout << "Size: " << size << std::endl;
        v = new T[size];
        for (int i = 0; i < size; i++) {
            v[i] = a[i];
        }
    }

    MyVector(T *a, int n)
    {
        size = n; // Most of the times you will use this pattern for dealing with arrays
        std::cout << "Size: " << size << std::endl;
        v = new T[size];
        for (int i = 0; i < size; i++)
        {
            v[i] = a[i];
        }
    }

    void print() {
        std::cout << "Size = " << size << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;
    }

    T operator*(MyVector &y) {
        T sum = 0;
        for (int i = 0; i < size; i++) {
            sum += (this->v[i]) * (y.v[i]);
        }
        return sum;
    }
};

void Templates();

#endif