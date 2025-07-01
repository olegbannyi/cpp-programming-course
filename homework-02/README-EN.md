# C++ programming course [👈](../README.md)

## HW #2: Movement semantics and lambda expressions [🇺🇦👈](./README.md)

### Task

***Implement movement for the class***

```cpp
class BigData {
private:
int* data;
size_t size;

public:
BigData(size_t size);
~BigData();

// Copy constructor
BigData(const BigData& other);

// Copy operator
BigData& operator=(const BigData& other);

// Move constructor
BigData(BigData&& other) noexcept;

// Move operator
BigData& operator=(BigData&& other) noexcept;

void print() const;
};
```

***Requirements:***

- Implement a constructor, copy constructor, copy operator, move constructor, and move operator.
- Create a function that returns a BigData object (by value) to demonstrate how the move works.
- Add logs (console output) to each constructor/destructor/operator to see when an object is copied and when it is moved.

### Compile and run

```bash
~$ cd ./homework-02
~$ make
```
