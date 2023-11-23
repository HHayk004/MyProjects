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
            
            /*
            class iterator
            {
                using iterator_category = std::forward_iterator_tag;
                using difference_type = ptrdiff_t;
                using value_type = T;
                using pointer = value_type*;
                using reference = value_type&;

                private:
                    pointer m_it;
            
                public:
                    Iterator(pointer ptr);

                    Iterator& operator++();
                    Iterator& operator--();
                    Iterator& operator+(const int);
                    Iterator& operator-(const int);
                    bool operator==(Iterator);
                    bool operator!=(Iterator);
            };
            */

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

    template <>
    class MyVector<uint8_t>
    {
        private:
            size_t m_size;
            size_t m_capacity;
            const size_t m_max_size = std::numeric_limits<size_t>::max() / sizeof(bool);
            uint8_t* m_ptr;

        public:
            MyVector();
		    MyVector(bool);
		    MyVector(std::initializer_list<bool>);
		    MyVector(const MyVector<uint8_t>&) noexcept;
            MyVector(MyVector<uint8_t>&&);
		    ~MyVector();
    
            std::ostream& operator<<(std::ostream&) const;

            uint8_t* data() const;
            bool at(size_t) const;

            void shrink_to_fit();
        
            void resize(size_t);
            bool empty() const;        
        
            void push_back(bool);
            void pop_back();
        
            void swap(MyVector<bool>&);

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
