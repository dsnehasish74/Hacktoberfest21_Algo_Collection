def binary_search(arr, n):
    st = 0
    end = len(arr)
    while(st < end):
        mid = (st+end)//2
        if arr[mid] == n:
            return True
        elif arr[mid] < n:
            end = mid-1
        else:
            st = mid+1
    return False
