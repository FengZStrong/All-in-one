
def calc_match_count(integer):
    figure = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]
    num = 0
    while integer//10 != 0:
        num += figure[integer%10]
        integer = integer//10
    num += figure[integer%10]
    return num

def calc_func(total):
    for i in range(0, 11112):
        for j in range(0, 11112):
            if i + j <= 11111:
                if calc_match_count(i) + calc_match_count(j) + calc_match_count(i + j) == total - 4:
                    print('%d + %d = %d' % (i, j, i + j))

if __name__ == '__main__':
    total = input('输入火柴的总数：>')
    calc_func(int(total))
