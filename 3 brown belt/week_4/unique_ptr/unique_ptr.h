#include "test_runner.h"

#include <cstddef>  // нужно для nullptr_t
#include <utility>

// Реализуйте шаблон класса UniquePtr
template <typename T>
class UniquePtr {
private:
    T* object;
public:
    UniquePtr(): object(nullptr) {}
    UniquePtr(T * ptr): object(ptr) {}
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr(UniquePtr&& other): object(other.object) {
        other.object = nullptr;
    }
    UniquePtr& operator = (const UniquePtr&) = delete;
    UniquePtr& operator = (std::nullptr_t){
        Reset(nullptr);
        return *this;
    }
    UniquePtr& operator = (UniquePtr&& other){
        Reset(other.object);
        other.object = nullptr;
        return *this;
    }
    ~UniquePtr(){
        delete object;
    }

    T& operator * () const{ return *object; }

    T * operator -> () const { return object; }

    T * Release(){
        T* result = object;
        object = nullptr;
        return result;
    }

    void Reset(T * ptr){
        delete object;
        object = ptr;
    }

    void Swap(UniquePtr& other){
        std::swap(object, other.object);
    }

    T * Get() const { return object; }
};
