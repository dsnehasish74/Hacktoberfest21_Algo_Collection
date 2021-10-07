func selectionSort<T:Comparable>(_ list: inout [T]) {
    let N = list.count
    for i in 0..<N {
        var minIndex = i
        for j in i+1..<N {
            if list[minIndex] > list[j] {
                minIndex = j
            }
        }
        let tmp = list[i]
        list[i] = list[minIndex]
        list[minIndex] = tmp
    }
}

func selectionSort<T:Comparable>(_ list: [T]) -> [T] {
    var temp = list
    selectionSort(&temp)
    return temp
}

var list = ["a", "d", "b", "c"]
var list2 = [4,2,1,3]
selectionSort(&list)
print(list)
print(selectionSort(list2))
