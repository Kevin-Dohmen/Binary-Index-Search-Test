function SearchUnique(idx, indexLength, searchValue){ // 21 lines
    let left = 0;
    let right = indexLength - 1;
    
    while (left <= right){
        const center = Math.floor((left + right) / 2);
        const value = idx[center][1];

        if (value === searchValue){
            return idx[center][0];
        }
        else if (value < searchValue){
            left = center + 1 // right split
        }
        else {
            right = center - 1 // left split
        }
    }

    return undefined;
}

// -=-=-=-=-=- run a few times to let V8's Optimizers do their work -=-=-=-=-=-
console.log("Running search to force the V8 optimizers to run")

const dummyRows = 10000
const dummyIndex = Array.from({ length: dummyRows }, (_, i) => [
    Math.floor(Math.random() * 999999), // unique random pointer
    i + 1 // sequential value
]).sort((a, b) => a[1] - b[1]); // ensure sorted by value

dummyIndex.forEach(element => {
    _ = SearchUnique(dummyIndex, dummyRows, element[1]);
});

console.log("Warmup complete, starting test...")

// -=-=-=-=-=- start the acual test on a new dataset -=-=-=-=-=-

const rows = 5000000 // 5.000.000
const index = Array.from({ length: rows }, (_, i) => [
    Math.floor(Math.random() * 999999), // unique random pointer
    i + 1 // sequential value
]).sort((a, b) => a[1] - b[1]); // ensure sorted by value

// pick 100.000 random indecies to test on
const testIndexesCount = 100000 // 100.000
const testIndexes = []
for (let i = 0; i < testIndexesCount; i++){
    testIndexes.push(index[Math.floor(Math.random() * (rows - 1))])
}

// start test
console.log(`starting test, searching for ${testIndexesCount} indexes in an index of ${rows} rows`)

const sTime = new Date().getTime();

testIndexes.forEach(testIndex => {
    _ = SearchUnique(index, rows, testIndex[1]);
});

const eTime = new Date().getTime();

console.log(`Took ${(eTime - sTime)} ms`)
console.log(`Average per search: ${(eTime-sTime) / testIndexesCount} ms`)
