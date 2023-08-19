# Learning_Makefile

## Makefile文件内容组成
一个Makefile文件通常由五种类型的内容组成：显式规则、隐式规则、变量定义、指令和注释  
**显式规则(explicit rules)**：显式指明何时以及如何生成或更新目标文件，显式规则包括目标、依赖和更新方法三个部分  
**隐式规则(implicit rules)**：根据文件自动推导如何从依赖生成或更新目标文件。    
**变量定义(variable definitions)**：定议变量并指定值，值都是字符串，类似C语言中的宏定义(#define)，在使用时将值展开到引用位置    
**指令(directives)**：在make读取Makefile的过程中做一些特别的操作，包括：    
读取(包含)另一个makefile文件(类似C语言中的#include) 
确定是否使用或略过makefile文件中的一部分内容(类似C语言中的#if)  
**定义多行变量**    
**注释(comments)**：一行当中 # 后面的内容都是注释，不会被make执行。make当中只有单行注释。如果需要用到#而不是注释，用\#。

 例如：
 ``` Makefile
sudoku: block.o command.o input.o main.o scene.o test.o
    g++ -o sudoku block.o command.o input.o main.o scene.o test.o

block.o: block.cpp common.h block.h color.h
    g++ -c block.cpp

command.o: command.cpp scene.h common.h block.h command.h
    g++ -c command.cpp

input.o: input.cpp common.h utility.inl
    g++ -c input.cpp

main.o: main.cpp scene.h common.h block.h command.h input.h
    g++ -c main.cpp

scene.o: scene.cpp common.h scene.h block.h command.h utility.inl
    g++ -c scene.cpp

test.o: test.cpp test.h scene.h common.h block.h command.h
    g++ -c test.cpp

hello.o: hello.cpp
    g++ -c hello.cpp


clean:
    rm block.o command.o input.o main.o scene.o test.o
    rm sudoku.exe
 ```

 **让make去识别当前的依赖：g++ -MM xxx.cpp**    
 ![Alt text](img/g++_MM_XXcpp.png)


 ## 目标：  

Makefile中会有很多目标，但最终目标只有一个，其他所有内容都是为这个最终目标服务的，写Makefile的时候先写出最终目标，再依次解决总目标的依赖    
**一般情况第一条规则中的目标会被确立为最终目标，第一条规则默认会被make执行**        
通常来说目标是一个文件，一条规则的目的就是生成或更新目标文件。  
make会根据目标文件和依赖文件最后修改时间判断是否需要执行更新目标文件的方法。如果目标文件不存在或者目标文件最后修改时间早于其中一个依赖文件最后修改时间，则重新执行更新目标文件的方法。否则不会执行。    
除了最终目标对应的更新方法默认会执行外，如果Makefile中一个目标不是其他目标的依赖，那么这个目标对应的规则不会自动执行。需要手动指定，方法为
```Makefile
make <target>  # 如 make clean , make hello.o
```
可以使用.DEFAULT_GOAL来修改默认最终目标
```makefile
.DEFAULT_GOAL = main
all: 
    @echo all

main:
    @echo main
```

### 伪目标  

如果一个标并不是一个文件，则这个目标就是伪目标。例如前面的clean目标。如果说在当前目录下有一个文件名称和这个目标名称冲突了，则这个目标就没法执行。这时候需要用到一个特殊的目标 .PHONY，将上面的clean目标改写如下     
```makefile
.PHONY: clean
clean:
    rm block.o command.o input.o main.o scene.o test.o
    rm sudoku.exe
```
**这样即使当前目录下存在与目标同名的文件，该目标也能正常执行。**    

**伪目标的其他应用方式**
如果一条规则的依赖文件没有改动，则不会执行对应的更新方法。如果需要每次不论有没有改动都执行某一目标的更新方法，可以把对应的目标添加到.PHONY的依赖中，例如下面这种方式，则每次执行make都会更新test.o，不管其依赖文件有没有改动 
```makefile
test.o: test.cpp test.h
        g++ -c test.cpp

.PHONY: clean test.o
```

