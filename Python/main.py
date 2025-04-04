import math
import time
import timeit
import random

def SearchUnique(idx, indexLength, search_value): # 16 lines
    left = 0
    right = indexLength - 1

    while left <= right:
        center = (left + right) // 2
        value = idx[center][1]

        if value == search_value:
            return idx[center][0]
        elif value < search_value:
            left = center + 1 # right split
        else:
            right = center - 1 # left split
    
    return 0xFFFFFFFF # mark as not found

rows = 5000000 # 5.000.000
index = [[random.randint(0, 999999), i] for i in range(rows)]

# pick 100000 indexes to search for
testIndexesCount = 100000 # 100.000
testIndexes = []
for i in range(testIndexesCount):
    testIndexes.append(index[random.randint(0, rows - 1)])

# start test

print(f"starting test, searching for {testIndexesCount} indexes in an index of {rows} rows")

dummySum = 0

sTime = timeit.default_timer()

for row in testIndexes:
    dummySum += SearchUnique(index, rows, row[1])

eTime = timeit.default_timer()

print(f"DummySum: {dummySum}")

print(f"Took {(eTime - sTime) * 1000:.3f} ms")
print(f"Average per search: {(eTime - sTime) / testIndexesCount * 1000:.3f} ms")
