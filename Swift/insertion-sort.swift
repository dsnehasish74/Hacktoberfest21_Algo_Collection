func insertionSort<T: Comparable>(_ array: [T]) -> [T] {
    var sortedArray = array
    for index in 1..<sortedArray.count {
        var currentIndex = index
        let temp = sortedArray[currentIndex]
        while currentIndex > 0 && temp < sortedArray[currentIndex - 1] {
            sortedArray[currentIndex] = sortedArray[currentIndex - 1]
            currentIndex -= 1
        }
        sortedArray[currentIndex] = temp
    }
    return sortedArray
}

let list1 = ["f", "e", "d", "b", "a", "c"]
print(insertionSort(list1))

let list2 = [5, 2, 1, 6, 4, 3]
print(insertionSort(list2))