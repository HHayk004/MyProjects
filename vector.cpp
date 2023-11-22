#include <iostream>
#include <limits>

template <typename T>
class MyVector 
{
    private:
        T* m_ptr;
        size_t m_size;
		const size_t m_max_size = std::numeric_limits<size_t>::max() / sizeof(T);
        size_t m_capacity;
        
    public:
		MyVector();
        ~MyVector();
    
        T* data();

        T& operator[](const size_t);
        T at(size_t);
    
        T& back();
        T& front();

        void shrink_to_fit();
        
        void resize(size_t);
        bool empty();        
        
        void push_back(T);
        void pop_back();
        
        void swap(MyVector&);

        size_t size();
        const size_t max_size();
        size_t capacity();

        void clear();
};

int main()
{
    MyVector<int> vec;
    int n = 0;
    
    do {
        std::cout << "Enter the vec size: ";
        std::cin >> n;
    } while (n < 1);

    for (int i = 0; i < n; ++i)
    {
        int tmp = 0;

        std::cout << "Vec[" << i << "] = ";
        std::cin >> tmp;

        vec.push_back(tmp);
    }

    MyVector<int> vec1;
    int n1 = 0;
    
    do {
        std::cout << "Enter the vec1 size: ";
        std::cin >> n1;
    } while (n1 < 1);

    for (int i = 0; i < n1; ++i)
    {
        int tmp = 0;

        std::cout << "Vec1[" << i << "] = ";
        std::cin >> tmp;

        vec1.push_back(tmp);
    }  

    vec.swap(vec1);

    std::cout << vec.size() << ' ' << vec.capacity() << std::endl;
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << vec1.size() << ' ' << vec1.capacity() << std::endl;
    for (int i = 0; i < vec1.size(); ++i)
    {
        std::cout << vec1[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}

template <typename T>
MyVector<T>::MyVector()
{
	m_ptr = nullptr;
	m_size = 0;
	m_capacity = 0;
}

template <typename T>
MyVector<T>::~MyVector()
{
    delete[] m_ptr;
    m_ptr = nullptr;
}

template <typename T>
T* MyVector<T>::data()
{
    return m_ptr;
}

template <typename T>
void MyVector<T>::push_back(T val)
{
    if (m_size > m_max_size - 10)
    {
        std::cerr << "m_size > m_max_size - 10 in push_back:\n";
        exit(-1);
    }

    if (m_size == m_capacity)
    {
        resize(m_capacity + 10);    
    }

    m_ptr[m_size++] = val;
}

template <typename T>
void MyVector<T>::pop_back()
{
    if (m_size == 0)
    {
        std::cerr << "Wrong index for pop:\n";
        exit(-1);
    }

    --m_size;
}

template <typename T>

bool MyVector<T>::empty()
{
    return m_size == 0;
}

template <typename T>
void MyVector<T>::resize(size_t new_size)
{
    if (new_size > m_max_size)
    {
        std::cerr << "new_size > m_max_size in resize:\n";
        exit(-1);
    }

    if (m_ptr == nullptr)
    {
        m_capacity = new_size;
        m_ptr = new T [m_capacity]{0};
    }
    
    else if (new_size > m_capacity)
    {
        m_capacity = new_size;
        T* new_ptr = new T [m_capacity]{};
        for (int i = 0; i < m_size; ++i)
        {
            new_ptr[i] = m_ptr[i];
        }

        delete[] m_ptr;
        m_ptr = new_ptr;
        new_ptr = nullptr;
    }

    else
    {
        m_size = new_size;
    }
}

template <typename T>
void MyVector<T>::shrink_to_fit()
{
    if (m_size < m_capacity)
    {
        m_capacity = m_size;
        T* new_ptr = new T [m_capacity];
        for (int i = 0; i < m_size; ++i)
        {
            new_ptr[i] = m_ptr[i];
        }

        delete[] m_ptr;
        m_ptr = new_ptr;
        new_ptr = nullptr;
    }
}

template <typename T>
T& MyVector<T>::operator[](const size_t index)
{
    return m_ptr[index];
}

template <typename T>
T MyVector<T>::at(size_t index)
{
    if (index >= m_size)
    {
        std::cerr << "Wrong index for at:\n";
        exit(-1);         
    }

    return m_ptr[index];
}

template <typename T>
size_t MyVector<T>::size()
{
    return m_size;
}

template <typename T>
size_t MyVector<T>::capacity()
{
    return m_capacity;
}

template <typename T>
const size_t MyVector<T>::max_size()
{
    return m_max_size;
}

template <typename T>
T& MyVector<T>::front()
{
    return m_ptr[0];
}

template <typename T>
T& MyVector<T>::back()
{    
    return m_ptr[m_size - 1];
}

template <typename T>
void MyVector<T>::swap(MyVector& vec)
{
    std::swap(m_ptr, vec.m_ptr);
    std::swap(m_size, vec.m_size);
    std::swap(m_capacity, vec.m_capacity);
}

template <typename T>
void MyVector<T>::clear()
{
    for (int i = 0; i < m_size; ++i)
    {
        m_ptr[i] = 0;
    }
    m_size = 0;
}
