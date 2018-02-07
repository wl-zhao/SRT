## Python Notes

### Python 基础

#### 运算符

`**` 表示乘方

#### 字符串

- 可用 `''` 或者`""` 。

- 如果字符串中有许多转义字符，可以使用`r''`：例如

  `print(r'\\\t\\')`

- 如果内部有换行，可以`'''...'''`：例如

  ```python
  print('''line1                                     
  line2                                             
  line3''')
  ```

- split函数可以将字符串分割：

  ```python
  >>> s='123.456'
  >>> s.split('.')
  ['123', '456']
  ```

- `s.[::-1]` 字符串倒序

#### Bool 值

- 直接用 True 或者 False表示
- 具有 and, or, not 运算

#### 空值

Python 中无意义的值，用 `None` 表示

#### 除法

- 两种除法：/和//
  - / 为精确的除法，结果为浮点数
  - // 为 c 语言中整数相除

#### list 和 tuple

- List

  用中括号声明

  ```python
  >>> classmates = ['Michael', 'Bob', 'Tracy']
  >>> classmates
  ['Michael', 'Bob', 'Tracy']
  ```
  list 可以直接通过 + 连接：

  ```python
  >>>print([1]+[2]+[3])
  [1, 2, 3]
  ```

  ​

- tuple

  用圆括号声明，一旦声明不可修改

  ```python
  >>> t = (1, 2)
  >>> t
  (1, 2)
  ```

  只有一个元素的tuple要加逗号

  ```python
  >>> t = (1,)
  >>> t
  (1,)
  ```

  ​

#### 判断

```python
a = 10
if a > 0:
    print('a > 0')
elif a = 0:
    print('a = 0')
else:
    print('a < 0')
```



#### 循环

for in 和  while

```python
names = ['Lucy', 'Williams']
for name in names:
    print(name)

sum = 0
for x in range(101):
    sum += x
print(sum)

```

```python
sum = 0
n = 99
while n > 0:
    sum = sum + n
    n = n - 2
print(sum)
```

依然有`continue` 和 `break` 语句

#### 字典

```python
>>> d = {'Michael': 95, 'Bob': 75, 'Tracy': 85}
>>> d['Michael']
95
```

用大括号声明

通过`in` 判断key是否存在

```python
>>> 'Thomas' in d
>>> False
```

通过get来获取：

```python
>>> d.get('Thomas')
>>> d.get('Lucy')
100
>>> d.get('Thomas',-1)
-1
```

#### 集合set

通过set声明：

```python
>>> s = set([1,2,3,3,4,4,4,3,3,2,3,])
>>> s
{1, 2, 3, 4}
```

add 和 remove

```python
>>> s.add(5)
>>> s.remove(4)
>>> s
{1, 2, 3, 5}
>>> 
```

& 和 |对应集合的交集和并集

```python
>>> s1 = set([1, 2, 3])
>>> s2 = set([2, 3, 4])
>>> s1 & s2
{2, 3}
>>> s1 | s2
{1, 2, 3, 4}
```

#### 可变对象与不可变对象

- list 是可变对象，例如

  ```python
  >>> a = ['c', 'b', 'a']
  >>> a.sort()
  >>> a
  ['a', 'b', 'c']
  ```

- str 是不可变对象

  ```python
  >>> a = 'abc'
  >>> a.replace('a', 'A')
  'Abc'
  >>> a
  'abc'
  ```

  需要把运算结果存下来才可以得到修改后的值

  ```python
  >>> a = 'abc'
  >>> b = a.replace('a', 'A')
  >>> b
  'Abc'
  >>> a
  'abc'
  ```

### 函数

#### 调用函数

- abs
- max
- int, float, str, bool, hex

#### 定义函数

```python
def my_abs(x):
    if x >= 0:
        return x
    else:
        return -x
```

#### 导入函数

```python
from abstest import my_abs
```

- 空函数

  ```python
  def nop():
      pass
  ```

  `pass` 语句什么也不做

- 参数检查

  ```python
  def my_abs(x):
      if not isinstance(x, (int, float)):
          raise TypeError('bad operand type')
      if x >= 0:
          return x
      else:
          return -x
  ```

  `isinstance` 检查数据类型

- 返回多个值

  ```python
  import math
  def move(x, y, step, angle=0):
      nx = x + step * math.cos(angle)
      ny = y - step * math.sin(angle)
      return nx, ny
  >>> x, y = move(100, 100, 60, math.pi / 6)
  >>> print(x, y)
  151.96152422706632 70.0
  ```

  事实上返回的是一个tuple


#### 函数参数

- 位置参数

  普通的函数参数

- 默认参数

  ```python
  def power(x, n=2):
      s = 1
      while n > 0:
          n = n - 1
          s = s * x
      return s
  ```

  > 注意默认参数列表中不要习惯性在等号两端打空格

  **默认参数必须指向不变对象！！**

  ```python
  def add_end(L=[]):
      L.append('END')
      return L
  ```

  上述代码在连续调用默认参数`add_end()`时，会改变`[]`  的值。

  应该这样写：

  ```python
  def add_end(L=None):
      if L is None:
          L = []
      L.append('END')
      return L
  ```

- 可变参数

  例如计算$a^2+b^2+\cdots$

  可以考虑用list或者tuple

  ```python
  def calc(numbers):
      s = 0
      for number in numbers:
          s += number * number
      return s
  ```

  调用时

  ```python
  print(calc([1, 2, 3]))
  print(calc(range(11)))
  ```

  使用可变参数：

  ```python
  def calc(*numbers):
      s = 0
      for number in numbers:
          s += number * number
      return s
  ```

  调用时

  ```python
  print(calc(1, 2, 3))
  print(calc(*range(11)))
  ```

  逐个直接调用，或者在list、tuple前加*

- 关键字参数

  关键字参数允许你传入0个或任意个含参数名的参数，这些关键字参数在函数内部自动组装为一个dict。

  ```python
  def person(name, age, **kw):
      print('name:', name)
      print('age:', age)
      print('other:', kw)
  ```

  调用：

  ```python
  person('John', 19, school = 'THU', love = 'Lucy')
  ```

  也可以直接用一个dict来调用：

  ```python
  di = {'school': 'SUFE', 'love': 'Williams'}
  person('Lucy', 19, **di)
  ```

- 命名关键字参数

  限制关键字参数的名字

  ```python
  def person(name, age, *, city, job):
      print(name, age, city, job)
  ```

  调用

  ```python
  >>> person('Jack', 24, city='Beijing', job='Engineer')
  Jack 24 Beijing Engineer
  ```

  如果函数定义中已经有了一个可变参数，后面跟着的命名关键字参数就不再需要一个特殊分隔符`*`了

  ```python
  def person(name, age, *arg, school, love):
      print('name:', name)
      print('age:', age)
      print(arg)
      print('school', school)
      print('love:', love)
  ```

  命名关键字参数必须传入参数名

  命名关键字参数可以有默认值

  ​

- 参数组合

  参数定义的顺序必须是：必选参数、默认参数、可变参数、命名关键字参数和关键字参数。

  ```python
  def f2(a, b, c=0, *, d, **kw):
      print('a =', a, 'b =', b, 'c =', c, 'd =', d, 'kw =', kw)
  ```

#### 递归

### 高级特性

#### 切片

```python
>>> L = ['Michael', 'Sarah', 'Tracy', 'Bob', 'Jack']
>>> L[1:3]
['Sarah', 'Tracy']
```

左闭右开

```python
>>> L[-2:-1]//倒数切片
['Bob']
```

前十个数隔两个取一个

```python
>>> L[:10:2]
[0, 2, 4, 6, 8]
```

所有数，每5个取一个：

```python
>>> L[::5]
[0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95]
```

#### 迭代

当我们使用`for`循环时，只要作用于一个可迭代对象，`for`循环就可以正常运行，而我们不太关心该对象究竟是list还是其他数据类型

通过collections模块的Iterable类型判断是否可以迭代：

```python
>>> from collections import Iterable
>>> isinstance('abc', Iterable) # str是否可迭代
True
>>> isinstance([1,2,3], Iterable) # list是否可迭代
True
>>> isinstance(123, Iterable) # 整数是否可迭代
False
```

获得下标：

```python
 for i, value in enumerate(['A', 'B', 'C']):
        print(i, value)
```

#### 列表生成式

```python
>>> list(range(1, 11))
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
```

```python
>>> [x * x for x in range(1, 11)]
[1, 4, 9, 16, 25, 36, 49, 64, 81, 100]
```

```
>>> [x * x for x in range(1, 11) if x % 2 == 0]
[4, 16, 36, 64, 100]
```

```python
>>> d = {'x': 'A', 'y': 'B', 'z': 'C' }
>>> [k + '=' + v for k, v in d.items()]
['y=B', 'x=A', 'z=C']
```

#### 生成器

一边循环一边计算

- 第一种方法很简单，只要把一个列表生成式的`[]`改成`()`，就创建了一个generator：

  ```python
  >>> g = (x * x for x in range(10))
  >>> g
  <generator object <genexpr> at 0x1022ef630>
  ```

如果要一个一个打印出来，可以通过`next()`函数获得generator的下一个返回值：

```python
>>> next(g)
0
>>> next(g)
1
>>> next(g)
4
>>> next(g)
9
```

可以用for

```python
>>> for n in g:
     print(n)
```

利用函数生成generator：

```python
def fib(max):
    n, a, b = 0, 0, 1
    while n < max:
        yield b
        a, b = b, a + b
        n = n + 1
    return 'done'
```

使用```yield```可以将fib变为generator

### 函数式编程

#### 高阶函数

- map/reduce

  map 把一个函数作用在一个list上

  ```python
  r = map(f, [1, 2, 3, 4, 5, 6])
  print(list(r))
  ```

  reduce接受一个二变量函数作为参数，并从头运算，每次结果进入继续运算：

  ```python
  reduce(f, [x1, x2, x3, x4]) = f(f(f(x1, x2), x3), x4)
  ```

  例如使用reduce求和：

  ```python
  >>> from functools import reduce
  >>> def add(x, y):
  	    return x + y
  >>> reduce(add, [1, 3, 5, 7, 9])
  ```

  ```python
  >>> from functools import reduce
  >>> def fn(x, y):
  ...     return x * 10 + y
  ...
  >>> def char2num(s):
  ...     digits = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}
  ...     return digits[s]
  ...
  >>> reduce(fn, map(char2num, '13579'))
  13579
  ```

  还可以用lambda函数化简

  ```python
  from functools import reduce

  DIGITS = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}

  def char2num(s):
      return DIGITS[s]

  def str2int(s):
      return reduce(lambda x, y: x * 10 + y, map(char2num, s))
  ```

- fiilter

  对每个元素作用函数，根据返回值是True还是False决定是否丢弃

  ```python
  def is_odd(n):
      return n % 2 == 1

  list(filter(is_odd, [1, 2, 4, 5, 6, 9, 10, 15]))
  # 结果: [1, 5, 9, 15]
  ```

  生成质数：

  ```python
  def odd():
      n = 1
      while True:
          n += 2
          yield n
  ```

  ```python
  def not_divisible(n):
      return lambda x: x % n != 0

  def prime():
      yield 2
      it = odd()
      while True:
          n = next(it)
          yield n
          it = filter(not_divisible(n), it)
  ```

  ```python
  for i in primes():
      if n < 1000:
          print(n)
      else:
          break
  ```

- sorted

  内置排序算法

  ```python
  >>> sorted(['bob', 'about', 'Zoo', 'Credit'], key=str.lower, reverse=True)
  ['Zoo', 'Credit', 'bob', 'about']
  ```


  `key` 指定一个函数，将其作用在list上再排序；reverse指定是否反向排序

#### 返回函数

```python
def createCounter():
    fs=[]
    def counter():
        if len(fs)>0:
            fs.append(fs[-1]+1)
        else:
            fs.append(1)
        return fs[-1]
    return counter
```

#### 匿名函数

```python
lambda x, y : x * x + y * y
```

#### 装饰器

```python
def log(text):
    def decorator(func):
        def wrapper(*args, **kw):
            print('%s %s():' % (text, func.__name__))
            return func(*args, **kw)
        return wrapper
    return decorator
@log('execute')
def now():
    print('2015-3-25')
```

#### 偏函数

```python
>>> import functools
>>> int2 = functools.partial(int, base=2)
>>> int2('1000000')
64
>>> int2('1010101')
85
```

### 模块

#### 作用域

在一个模块中，我们可能会定义很多函数和变量，但有的函数和变量我们希望给别人使用，有的函数和变量我们希望仅仅在模块内部使用。在Python中，是通过`_`前缀来实现的。

- 正常的函数和变量名是公开的（public），可以被直接引用，比如：`abc`，`x123`，`PI`等；
- 类似`__xxx__`这样的变量是特殊变量，可以被直接引用，但是有特殊用途，比如上面的`__author__`，`__name__`就是特殊变量，`hello`模块定义的文档注释也可以用特殊变量`__doc__`访问，我们自己的变量一般不要用这种变量名；
- 类似`_xxx`和`__xxx`这样的函数或变量就是非公开的（private），不应该被直接引用，比如`_abc`，`__abc`等；

```python
def _private_1(name):
    return 'Hello, %s' % name

def _private_2(name):
    return 'Hi, %s' % name

def greeting(name):
    if len(name) > 3:
        return _private_1(name)
    else:
        return _private_2(name)
```

利用这种方法可以封装

### 面向对象编程

```python
class Student(object):#表示从object继承

    def __init__(self, name, score):
        self.name = name
        self.score = score

    def print_score(self):
        print('name: %s, score: %s' % (self.name, self.score))


john = Student('John', 99)
lucy = Student('Lucy', 100)
john.print_score()
lucy.print_score()
```

`__init__` 注意左右两个下划线

#### 访问控制

访问控制通过变量的命名实现：

如果要让内部属性不被外部访问，可以把属性的名称前加上两个下划线`__`，在Python中，实例的变量名如果以`__`开头，就变成了一个私有变量（private）

需要注意的是，在Python中，变量名类似`__xxx__`的，也就是以双下划线开头，并且以双下划线结尾的，是特殊变量，特殊变量是可以直接访问的，不是private变量，所以，不能用`__name__`、`__score__`这样的变量名。

有些时候，你会看到以一个下划线开头的实例变量名，比如`_name`，这样的实例变量外部是可以访问的，但是，按照约定俗成的规定，当你看到这样的变量时，意思就是，“虽然我可以被访问，但是，请把我视为私有变量，不要随意访问”。

#### 继承

直接在`class newclasss(base_class) ` ，很简单

#### 获取对象信息

几种方法：

- type()

  `type('abc')`

- isinstance()

  `isinstance('abc', str)`

- dir()

  `dir('abc')`

- `getattr()`、`setattr()`以及`hasattr()`

  ```python
  >>> hasattr(obj, 'x') # 有属性'x'吗？
  True
  >>> obj.x
  9
  >>> hasattr(obj, 'y') # 有属性'y'吗？
  False
  >>> setattr(obj, 'y', 19) # 设置一个属性'y'
  >>> hasattr(obj, 'y') # 有属性'y'吗？
  True
  >>> getattr(obj, 'y') # 获取属性'y'
  19
  >>> obj.y # 获取属性'y'
  19
  ```

#### 实例属性和类属性

```python
>>> class Student(object):
...     name = 'Student'
...
>>> s = Student() # 创建实例s
>>> print(s.name) # 打印name属性，因为实例并没有name属性，所以会继续查找class的name属性
Student
>>> print(Student.name) # 打印类的name属性
Student
>>> s.name = 'Michael' # 给实例绑定name属性
>>> print(s.name) # 由于实例属性优先级比类属性高，因此，它会屏蔽掉类的name属性
Michael
>>> print(Student.name) # 但是类属性并未消失，用Student.name仍然可以访问
Student
>>> del s.name # 如果删除实例的name属性
>>> print(s.name) # 再次调用s.name，由于实例的name属性没有找到，类的name属性就显示出来了
Student
```

### 面向对象高级编程

#### 动态绑定

- 动态绑定属性

- 动态绑定实例方法

  ```python
  >>> def set_age(self, age): # 定义一个函数作为实例方法
  ...     self.age = age
  ...
  >>> from types import MethodType
  >>> s.set_age = MethodType(set_age, s) # 给实例绑定一个方法
  >>> s.set_age(25) # 调用实例方法
  >>> s.age # 测试结果
  25
  ```

- 动态绑定类方法

  ```python
  >>> def set_score(self, score):
  ...     self.score = score
  ...
  >>> Student.set_score = set_score
  ```

#### 使用`__slots__`

为了达到限制的目的，Python允许在定义class的时候，定义一个特殊的`__slots__`变量，来限制该class实例能添加的属性

```python
class Student(object):
    __slots__ = ('name', 'age') # 用tuple定义允许绑定的属性名称
```

#### 使用`@property`

可以将方法变成属性调用

```python
class Student(object):

    @property
    def score(self):
        return self._score

    @score.setter
    def score(self, value):
        if not isinstance(value, int):
            raise ValueError('score must be an integer!')
        if value < 0 or value > 100:
            raise ValueError('score must between 0 ~ 100!')
        self._score = value
```

#### 多重继承

```python
class Bat(Mammal, Flyable):
    pass
```

##### MixIn

在设计类的继承关系时，通常，主线都是单一继承下来的。但是，如果需要“混入”额外的功能，通过多重继承就可以实现，这种设计通常称之为MixIn。

#### 定制类

Python的class中有很具有特殊用途的函数。

##### `__str__`

```python
>>> class Student(object):
...     def __init__(self, name):
...         self.name = name
...     def __str__(self):
...         return 'Student object (name: %s)' % self.name
...
>>> print(Student('Michael'))
Student object (name: Michael)
```

可以使print打印出来的实例好看

此外`__repr__()`决定了直接显示变量的样子

将其重写即可

##### `__iter__`

若一个类想用于循环，需要定义`__iter__` 和`__next__`

```python
class Fib(object):
    def __init__(self):
        self.a, self.b = 0, 1 # 初始化两个计数器a，b

    def __iter__(self):
        return self # 实例本身就是迭代对象，故返回自己

    def __next__(self):
        self.a, self.b = self.b, self.a + self.b # 计算下一个值
        if self.a > 100000: # 退出循环的条件
            raise StopIteration()
        return self.a # 返回下一个值
```

##### `__getitem__`

要表现得像list那样按照下标取出元素，需要实现`__getitem__()`方法：

```python
class Fib(object):
    def __getitem__(self, n):
        a, b = 1, 1
        for x in range(n):
            a, b = b, a + b
        return a
```

事实上要想正确实现`__getitem__`需要考虑各种slice的情况

##### `__getattr__`

注意，只有在没有找到属性的情况下，才调用`__getattr__`，已有的属性，比如`name`，不会在`__getattr__`中查找。

一个链式调用的例子

```python
class Chain(object):

    def __init__(self, path=''):
        self._path = path

    def __getattr__(self, path):
        return Chain('%s/%s' % (self._path, path))

    def __str__(self):
        return self._path

    __repr__ = __str__
```

```python
>>> Chain().status.user.timeline.list
'/status/user/timeline/list'
```

##### `__call__`

定义了call之后可以直接实例加()调用函数

> 类似于实例本身是一个函数

#### 枚举类

```python
from enum import Enum

Month = Enum('Month', ('Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec'))
```

```python
for name, member in Month.__members__.items():
    print(name, '=>', member, ',', member.value)
```

```python
from enum import Enum, unique

@unique # unique装饰器帮助检查是否有重复
class Weekday(Enum):
    Sun = 0 # Sun的value被设定为0
    Mon = 1
    Tue = 2
    Wed = 3
    Thu = 4
    Fri = 5
    Sat = 6
```

##### 使用元类

- type()

```python
>>> def fn(self, name='world'): # 先定义函数
...     print('Hello, %s.' % name)
...
>>> Hello = type('Hello', (object,), dict(hello=fn)) # 创建Hello class
>>> h = Hello()
>>> h.hello()
Hello, world.
>>> print(type(Hello))
<class 'type'>
>>> print(type(h))
<class '__main__.Hello'>
```

### 错误、调试和测试

#### 错误处理

try...except...finally

```python
try:
    print('try...')
    r = 10 / int('2')
    print('result:', r)
except ValueError as e:
    print('ValueError:', e)
except ZeroDivisionError as e:
    print('ZeroDivisionError:', e)
else:
    print('no error!')
finally:
    print('finally...')
print('END')
```

### IO编程

#### 文件读写

```python
>>> f = open('/Users/michael/test.txt', 'r')
```

```python
>>> f.read()
'Hello, world!'
>>> f.close()
```

更加简洁的方法：不用调用close

```python
with open('/path/to/file', 'r') as f:
    print(f.read())
```

```python
>>> f = open('/Users/michael/test.txt', 'w') #a for append 
>>> f.write('Hello, world!')
>>> f.close()
```

二进制文件：rb模式

append：a

#### StringIO

```python
>>> from io import StringIO # 和文件类似，与fstream很像
>>> f = StringIO()
>>> f.write('hello')
5
>>> f.write(' ')
1
>>> f.write('world!')
6
>>> print(f.getvalue())
hello world!
```

#### BytesIO

```python
>>> from io import BytesIO
>>> f = BytesIO()
>>> f.write('中文'.encode('utf-8'))
6
>>> print(f.getvalue())
b'\xe4\xb8\xad\xe6\x96\x87'
```

#### 操作文件和目录

```python
>>> import os
>>> os.name # 操作系统类型
'posix'
>>> os.environ.get('PATH')# 获得环境变量

# 查看当前目录的绝对路径:
>>> os.path.abspath('.')
'/Users/michael'
# 在某个目录下创建一个新目录，首先把新目录的完整路径表示出来:
>>> os.path.join('/Users/michael', 'testdir')
'/Users/michael/testdir'
# 然后创建一个目录:
>>> os.mkdir('/Users/michael/testdir')
# 删掉一个目录:
>>> os.rmdir('/Users/michael/testdir')
# 拆分，后一部分总是最后一级的文件名
>>> os.path.split('/Users/michael/testdir/file.txt')
('/Users/michael/testdir', 'file.txt')
# 直接得到扩展名
>>> os.path.splitext('/path/to/file.txt')
('/path/to/file', '.txt')
```

列出所有目录

```python
>>> [x for x in os.listdir('.') if os.path.isdir(x)]
['.lein', '.local', '.m2', '.npm', '.ssh', '.Trash', '.vim', 'Applications', 'Desktop', ...]
```
列出所有py文件
```python
>>> [x for x in os.listdir('.') if os.path.isfile(x) and os.path.splitext(x)[1]=='.py']
['apis.py', 'config.py', 'models.py', 'pymonitor.py', 'test_db.py', 'urls.py', 'wsgiapp.py']
```
#### 序列化

```python
>>> import pickle
>>> d = dict(name='Bob', age=20, score=88)
>>> pickle.dumps(d)
b'\x80\x03}q\x00(X\x03\x00\x00\x00ageq\x01K\x14X\x05\x00\x00\x00scoreq\x02KXX\x04\x00\x00\x00nameq\x03X\x03\x00\x00\x00Bobq\x04u.'
>>> f = open('dump.txt', 'wb')
>>> pickle.dump(d, f)
>>> f.close()
```

将序列化的对象写入文件

##### JSON

```python
>>> import json
>>> d = dict(name='Bob', age=20, score=88)
>>> json.dumps(d)
'{"age": 20, "score": 88, "name": "Bob"}'
```

```python
>>> json_str = '{"age": 20, "score": 88, "name": "Bob"}'
>>> json.loads(json_str)
{'age': 20, 'score': 88, 'name': 'Bob'}
```

```python
print(json.dumps(s, default=lambda obj: obj.__dict__))# dumbps只对dict有效
```

### 进程与线程

#### 多进程

- multiprocessing

```python
from multiprocessing import Process
import os

# 子进程要执行的代码
def run_proc(name):
    print('Run child process %s (%s)...' % (name, os.getpid()))

if __name__=='__main__':
    print('Parent process %s.' % os.getpid())
    p = Process(target=run_proc, args=('test',))
    print('Child process will start.')
    p.start()
    p.join()
    print('Child process end.')
```

- 线程池

```python
  from multiprocessing import Pool
  import os, time, random

  def long_time_task(name):
      print('Run task %s (%s)...' % (name, os.getpid()))
      start = time.time()
      time.sleep(random.random() * 3)
      end = time.time()
      print('Task %s runs %0.2f seconds.' % (name, (end - start)))

  if __name__=='__main__':
      print('Parent process %s.' % os.getpid())
      p = Pool(4)
      for i in range(5):
          p.apply_async(long_time_task, args=(i,))
      print('Waiting for all subprocesses done...')
      p.close()
      p.join()
      print('All subprocesses done.')
```

