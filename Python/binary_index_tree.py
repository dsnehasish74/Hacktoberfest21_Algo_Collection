def init_bit(arr):
    result = [0] + arr
    for i in range(1, len(result)):
        index = i + (i & -i)
        if index < len(result):
            result[index] += result[i]

    return result

def sum(arr, index):
    index += 1
    result = 0
    while index:
        result += arr[index]
        index -= index & -index 

    return result

def update(arr, index):
    index += 1
    while index < len(arr):
        arr[index] += 1
        index += index & -index