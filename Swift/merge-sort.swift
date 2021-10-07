func merge<T: Comparable>(_ left: [T], _ right: [T]) -> [T] {
  var leftIndex = 0
  var rightIndex = 0

  var orderedArray: [T] = []
  
  while leftIndex < left.count && rightIndex < right.count {
    let leftElement = left[leftIndex]
    let rightElement = right[rightIndex]

    if leftElement < rightElement {
      orderedArray.append(leftElement)
      leftIndex += 1
    } else if leftElement > rightElement {
      orderedArray.append(rightElement)
      rightIndex += 1
    } else { 
      orderedArray.append(leftElement)
      leftIndex += 1
      orderedArray.append(rightElement)
      rightIndex += 1
    }
  }

  while leftIndex < left.count {
    orderedArray.append(left[leftIndex])
    leftIndex += 1
  }

  while rightIndex < right.count {
    orderedArray.append(right[rightIndex])
    rightIndex += 1
  }
  
  return orderedArray
}

func mergeSort<T: Comparable>(_ list: [T]) -> [T] {
  guard list.count > 1 else { return list }

  let middleIndex = list.count / 2
  
  let leftList = mergeSort(Array(list[0..<middleIndex]))
  let rightList = mergeSort(Array(list[middleIndex..<list.count]))
  
  return merge(leftList, rightList)
}


let list1 = ["f", "e", "d", "b", "a", "c"]
print(mergeSort(list1))

let list2 = [5, 2, 1, 6, 4, 3]
print(mergeSort(list2))