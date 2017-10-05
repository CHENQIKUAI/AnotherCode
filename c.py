from functools import reduce

str = '12345.12345'

def f(x):
	return {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5,
	 '6': 6, '7': 7, '8': 8, '9': 9, '.':'.'}[x]

str = map(f, str)

print str

mark = 0
i = 1
def func(x, y):
	global mark
	global i
	if y == '.':
		mark = 1
		return x
	if mark == 0:
		return x * 10 + y
	else:
		i *= 10
		return x + y * 1. / i

print reduce(func, str)