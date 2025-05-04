function SearchUnique(idx: number[][], indexLength: number, searchValue: number): number{ // 21 lines
    let left: number = 0;
    let right: number = indexLength - 1;
    
    while (left <= right){
        const center: number = Math.floor((left + right) / 2);
        const value: number = idx[center][1];

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

    return 0xFFFFFFFF; // mark as not found
}

// -=-=-=-=-=- run a few times to let V8's Optimizers do their work -=-=-=-=-=-
console.log("Running search to force the V8 optimizers to run")

const dummyRows: number = 10000
const dummyIndex: number[][] = Array.from({ length: dummyRows }, (_, i) => [
    Math.floor(Math.random() * 999999), // unique random pointer
    i + 1 // sequential value
]).sort((a, b) => a[1] - b[1]); // ensure sorted by value

dummyIndex.forEach(element => {
    void SearchUnique(dummyIndex, dummyRows, element[1]);
});

console.log("Warmup complete, starting test...")

// -=-=-=-=-=- start the acual test on a new dataset -=-=-=-=-=-

const rows: number = 5000000 // 5.000.000
const index: number[][] = Array.from({ length: rows }, (_, i) => [
    Math.floor(Math.random() * 999999), // unique random pointer
    i + 1 // sequential value
]).sort((a, b) => a[1] - b[1]); // ensure sorted by value

// pick 100.000 random indecies to test on
const testIndexesCount: number = 100000 // 100.000
const testIndexes: number[][] = []
for (let i = 0; i < testIndexesCount; i++){
    testIndexes.push(index[Math.floor(Math.random() * (rows - 1))])
}

// start test
console.log(`starting test, searching for ${testIndexesCount} indexes in an index of ${rows} rows`)

let dummySum: number = 0;

const sTime: number = new Date().getTime();

testIndexes.forEach(testIndex => {
    dummySum += SearchUnique(index, rows, testIndex[1]);
});

const eTime: number = new Date().getTime();

console.log(`DummySum: ${dummySum}`);

console.log(`Took ${(eTime - sTime)} ms`)
console.log(`Average per search: ${(eTime-sTime) / testIndexesCount} ms`)
