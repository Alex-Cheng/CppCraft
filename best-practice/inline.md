# inline的最佳实践
inline这个关键字引入C++标准是两个目的：一、如同名字所表述的那样，“内联”是指在调用该函数的地方直接插入函数的代码（称为内联展开），而没有调用指令（通常是汇编的CALL指令），以省去函数调用的成本；二、解决重复定义的问题，通常出现在头文件上定义函数然后在多个源文件中包含（#include）的情况。

## 函数调用内联展开
inline对于编译器是否内联展开只起到一个指示作用，并不是一定会内联展开。随着编译器越来越聪明，这个指示的作用可能越来越弱。

## 解决重复定义问题
因为头文件可能会被多个源文件（一般后缀cpp）包含，每个源文件都是一个编译单元，那么就会产生符号冲突。而在头文件上为函数定义上加上inline后，即使多个源文件都包含这个头文件（当然就是会包含同名的函数的定义），但是实际编译器只会当成同一个函数定义，这个函数的符号是唯一的，在链接时就不会出现多个符号冲突的问题。

这里需要满足几个条件：一、定义的内容相同；二、单词的含义相同；三、多个源文件包含。如果一个内联函数多次定义且内容不一样，编译器要么报错，要么只选择其中一个定义（这可能带来错误）。


## 在类的定义中的成员函数不需要加inline
类、模板、枚举可以看作自带内联，不需要inline关键字。它们的定义可以放心放在头文件并由多个源文件包含，不用担心符号冲突的问题。

在类的定义中的成员函数不需要加inline。这是因为默认是带了inline的。

## 内联变量
C++17把内联的概念扩展到了变量，使得全局变量的声明和使用变得更加简单和安全。内联变量允许在头文件中定义变量，而不必担心在多个源文件中包含该头文件时会导致重复定义的问题。与内联函数类似，内联变量的定义在多个翻译单元中是唯一的。

它不会像static定义的静态变量那样每个翻译单元都有一份实例。

它比extern方便的地方在于：可以直接在头文件中直接定义和初始化，不需要在某个源文件中定义和初始化。
