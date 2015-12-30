from BubbleSort import random_input

def quick_sort(array, left, right):
    if left > right:
        return

    temp = array[left]
    i = left
    j = right

    while i != j:
        while array[j] >= temp and i < j:
            j -= 1
        while array[i] <= temp and i < j:
            i += 1

        if i < j:
            t = array[i]
            array[i] = array[j]
            array[j] = t

    array[left] = array[i]
    array[i] = temp

    quick_sort(array, left, i - 1)
    quick_sort(array, i + 1, right)

if __name__ == '__main__':
    array = []
    random_input(array)
    quick_sort(array, 0, len(array) - 1)
    print('快排后的数组:', array)
