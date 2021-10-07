func partition<T:Comparable>(_ list: inout [T], _ start: Int, _ end: Int) -> Int {
    var start = start
    var end = end
    let length = list.count
    let pivotIndex = start
    let pivot = list[pivotIndex]
    
    while start < end {
        while start < length && list[start] <= pivot {
            start += 1
        }
        while list[end] > pivot {
            end -= 1
        }
        if start < end {
            let tmp = list[start]
            list[start] = list[end]
            list[end] = tmp
        }
    }
    let tmp = list[end]
    list[end] = list[pivotIndex]
    list[pivotIndex] = tmp
    return end
}


func quickSort<T:Comparable>(_ list: inout [T], _ start: Int=0, _ end: Int? = nil) {
    let end = end ?? list.count - 1
    if start < end {
        let p = partition(&list, start, end)
        quickSort(&list, start, p-1)
        quickSort(&list, p+1, end)
    }
}

func quickSort<T:Comparable>(_ list: [T]) -> [T] {
    var temp = list
    quickSort(&temp)
    return temp
}

var list = ["a", "d", "b", "c"]
var list2 = [4,2,1,3]
quickSort(&list)
print(list)
print(quickSort(list2))
