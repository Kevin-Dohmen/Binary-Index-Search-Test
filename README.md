# Binary-Index-Search-Test

comparison between languages and my ability to optimize and use them XD  
A binary search algorithm is theoretically `O(log n)` which means that the time it takes to search for a value will increase less the more data you have.

## Constraints

### Index

- An array of pointers to fictional objects (`int`) and and the indexed value (`int`).
- The array is sorted by value in ascending order.
- The value is unique.

#### example:

```python
index = [ # [pointer, value]
    [23, 1],
    [45, 2],
    [12, 3],
    [85, 4],
    [71, 5]
]
```

### Search

- Binary search algorithm.
- The search function should return the pointer to the object if found, or `None|undefined|exception` if not found.
- The search function should be able to handle large arrays efficiently (100.000.000).
- No external libraries or dependencies should be used.
- No recursion should be used.

## Test

### Average time test

#### Case

- Average time of searching for a value in the dataset.
- The test should be run for a large number of itterations (10.000+ random values picked from the index).
- High amount of data (1.000.000+)
- no specific validation of the output is needed, just the time taken to run the test. (trusting the implementation of the search function)

#### Output

- average time per search

#### Result

#### **Test 1:** 5.000.000 indexes, searching for 100.000 values in the

The Binary search algorithm should be able to find the correct value within 23 (`log2(n)`) guesses.

|language|time|note|
|:-------|:---|:---|
|Python|0,008 ms||
|JavaScript|0,00145 ms|With warmup (10.000 iterations on 10.000 indexes)|
|C++|0,00101 ms|With compile-time optimizers: `-O2 -frename-registers` (in Ubuntu)|
