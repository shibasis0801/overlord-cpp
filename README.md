# Overlord C++ library

These are a set of header files and implementations being designed by me to simplify and accelerate C++ development.

# Example Usage

## Range (Inspired from python)

range(start, stop, stride)

A range is a datatype you can use in range for loops. It is made with only primitive data and some simple functions stiched together. As a result it is very fast.

### Basic

```cpp
for (int i : range(0, 10))
    cout << i << ", ";
```
will print 

0, 1, 2, 3, 4, 5, 6, 7, 8, 9,

Python equivalent
```python
    for i in range(0, 10):
        print(f"{i}, ", end='')
```

### With custom step

```cpp
for (int i : range(0, 10).step(2))
    cout << i << ", ";
```
will print

0, 2, 4, 6, 8

#### Python equivalent
```python
for i in range(0, 10, 2):
    print(f"{i}, ", end='')
```
#### Or
```python
for i in range(0, 10)[::2]:
    print(f"{i}, ", end='')
```

### Reverse
```cpp
for (int i : range(10, 0).step(-1))
    cout << i << ", ";
```

#### Python equivalent
```python
for i in range(10, 0, -1)
    print(f"{i}, ", end='')
```

Lots more documentation to come.