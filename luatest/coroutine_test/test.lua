require('coroutine_test')

p = producer()
f = filter(p)
consumer(f)
