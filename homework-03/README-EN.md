# C++ programming course [👈](../README-EN.md)

## HW #3: RAII and smart pointers [🇺🇦👈](./README.md)

### Task

Create a ***FileManager*** class that:

- Opens the file in its constructor (for example, using std::fopen).
- Closes the file in its destructor (for example, using std::fclose).

Add a write(const std::string&) method to write text to a file.

Handle exceptions:

- Throw an exception if the file cannot be opened.
- Ensure automatic file closure even in the event of an exception.

Write a test program that uses ***FileManager*** to write text to a file.

Write a class ***Sensor*** that:

- Stores sensor readings in std::shared_ptr\<std::vector\<int\>\>.
- Provides functions for adding and outputting readings.
- Simulate simultaneous use of shared sensor data in main().
- Create two Sensor instances that share the same std::vector\<int\> via std::shared_ptr.

### Compile and run

```bash
~$ cd ./homework-03
~$ make
```
