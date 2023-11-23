#ifndef VECTOR_PROTO_H
#define VECTOR_PROTO_H
#include <iostream>
#include <initializer_list>
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
		MyVector(T);
		MyVector(std::initializer_list<T>);
		MyVector(const MyVector&) noexcept;
        MyVector(MyVector&&);
		~MyVector();

        T& operator[](const size_t) const;

        MyVector& operator=(std::initializer_list<T>);
        MyVector& operator=(const MyVector&);
        MyVector& operator=(MyVector&&);

        std::ostream& operator<<(std::ostream&) const;

        T* data() const;
        T at(size_t) const;
    
        T& back() const;
        T& front() const;

        void shrink_to_fit();
        
        void resize(size_t);
        bool empty() const;        
        
        void push_back(T);
        void pop_back();
        
        void swap(MyVector&);

        size_t size() const;
        const size_t max_size() const;
        size_t capacity() const;

        void clear();
};
#endif

#ifndef VECTOR_IMPL_HPP
#define VECTOR_IMPL_HPP
#include "vector_impl.hpp"
#endif
