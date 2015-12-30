book = [0,0,0,0,0,0,0,0,0,0]
box = [0,0,0,0,0,0,0,0,0,0]

def depth_first_search(n,step):
    if step == n+1:
        print(box)
        return
    for i in range(1, n+1):
        if book[i] == 0:
            box[step] = i
            book[i] = 1
            depth_first_search(n,step+1)
            book[i] = 0

if __name__ == '__main__':
    parameter = input('输入参数：>')
    depth_first_search(int(parameter), 1)
