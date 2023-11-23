template<typename T>
std::ostream& operator<<(std::ostream& os, const MyVector<T>& other)
{
    return other.operator<<(os);
}

template <typename T>
MyVector<T>::MyVector()
{
	m_ptr = nullptr;
	m_size = 0;
	m_capacity = 0;
}

template <typename T>
MyVector<T>::MyVector(T obj)
{
	m_capacity = 10;
	m_ptr = new T [m_capacity]{0};

	m_ptr[0] = obj;
	m_size = 1;
}

template <typename T>
MyVector<T>::MyVector(std::initializer_list<T> list)
{
	m_size = list.size();
	m_capacity = m_size + 10;
	m_ptr = new T [m_capacity];

	int index = 0;
	for (const auto& elem : list)
	{
		m_ptr[index] = elem;
		++index;
	}
}

template <typename T>
MyVector<T>::MyVector(const MyVector& other) noexcept
{
	m_size = other.m_size;
	m_capacity = other.m_capacity;

	m_ptr = new T [m_size]; 
	for (int i = 0; i < m_size; ++i)
	{
		m_ptr[i] = other[i];
	}
}

template <typename T>
MyVector<T>::MyVector(MyVector&& other)
{
	m_size = other.m_size;
	m_capacity = other.m_capacity;
	m_ptr = other.m_ptr;

	other.m_size = 0;
	other.m_capacity = 0;
	other.m_ptr = nullptr;
}

template <typename T>
MyVector<T>::~MyVector()
{
    delete[] m_ptr;
    m_ptr = nullptr;
}

template <typename T>
T* MyVector<T>::data() const
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

bool MyVector<T>::empty() const
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
T& MyVector<T>::operator[](const size_t index) const
{
    return m_ptr[index];
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(std::initializer_list<T> list)
{   
    m_size = list.size();
    
    if (m_size > m_capacity)
    {
        resize(m_size);
    }    

    int index = 0;
    for (const auto& elem: list)
    {
        m_ptr[index] = elem;
    }

    return *this;
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other)
{
    if (this != &other)
    {
        m_size = other.m_size;
        m_capacity = other.m_capacity;

        delete[] m_ptr;
        m_ptr = new T [m_capacity];
    
        for (int i = 0; i < m_size; ++i)
        {
            m_ptr[i] = other[i];
        }
    }

    return *this;
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector&& other)
{
    m_size = other.m_size;
    m_capacity = other.m_capacity;

    delete[] m_ptr;
    m_ptr = new T [m_capacity];

    other.m_size = 0;
    other.m_capacity = 0;
    other.m_ptr = nullptr;

    return *this;
}

template <typename T>
std::ostream& MyVector<T>::operator<<(std::ostream& os) const
{
    for (int i = 0; i < m_size; ++i)
    {
        std::cout << m_ptr[i] << ' ';
    }
    return os;
}


template <typename T>
T MyVector<T>::at(size_t index) const
{
    if (index >= m_size)
    {
        std::cerr << "Wrong index for at:\n";
        exit(-1);         
    }

    return m_ptr[index];
}

template <typename T>
size_t MyVector<T>::size() const
{
    return m_size;
}

template <typename T>
size_t MyVector<T>::capacity() const
{
    return m_capacity;
}

template <typename T>
const size_t MyVector<T>::max_size() const
{
    return m_max_size;
}

template <typename T>
T& MyVector<T>::front() const
{
    return m_ptr[0];
}

template <typename T>
T& MyVector<T>::back() const
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

