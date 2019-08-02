Write your simplified implementation of the unique_ptr <T> class. The detailed specification of the standard unique_ptr can be viewed at cppreference. In this task, you do not need to do specialization for the array and you do not need to provide your own Deleter. Name your class UniquePtr. The class should have one template parameter T - the type of the element, the pointer to which will be stored inside.

Write the following functions in the class:

- The default constructor that creates an empty smart pointer.
- A constructor that accepts T * and takes possession of this dynamic memory.
- A move constructor that receives an rvalue reference to another UniquePtr as input and takes ownership of the resource from it.
- An assignment operator that receives nullptr as input (type is nullptr_t defined in the cstddef header file). As a result, the smart pointer should become empty.
- A move assignment operator that receives an rvalue reference to another UniquePtr as an input.
- Destructor.
- operator *, which returns T &.
- The operator -> (it should return a pointer to the regular structure, to which you can apply the usual ->).
- The T * Release () function that cancels ownership of an object and returns a pointer stored inside.
- The void Reset (T * ptr) function, after which the smart pointer must capture ptr.
- A void Swap (UniquePtr & other) function that shares content with another smart pointer.
- The function T * Get () const, returning a pointer.

In your class, the copy constructor and the normal assignment operator must be prohibited.

Use the standard unique_ptr and the header file <memory> is not allowed.
