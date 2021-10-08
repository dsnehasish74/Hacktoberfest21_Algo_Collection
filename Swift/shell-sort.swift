func insertionSort<T: Comparable>(_ list: inout [T], start: Int, gap: Int) {
    for i in stride(from: (start + gap), to: list.count, by: gap) {
        let currentValue = list[i]
        var pos = i
        while pos >= gap && list[pos - gap] > currentValue {
            list[pos] = list[pos - gap]
            pos -= gap
        }
        list[pos] = currentValue
    }
}

func shellSort<T: Comparable>(_ list: inout [T]) {
    var sublistCount = list.count / 2
    while sublistCount > 0 {
        for pos in 0..<sublistCount {
            insertionSort(&list, start: pos, gap: sublistCount)
        }
        sublistCount = sublistCount / 2
    }
}

var list1 = ["f", "e", "d", "b", "a", "c"]
shellSort(&list1)
print(list1)

var list2 = [5, 2, 1, 6, 4, -1, 3]
shellSort(&list2)
print(list2)