
# 测试 makefile 命令
# 使用.DEFAULT_GOAL来修改默认最终目标
# .DEFAULT_GOAL = main

# .PHONY: all
# 	@echo 11111111

# all:
# 	@echo all

# main:
# 	@echo main


# test.o: test.cpp | test.h
# 	g++ -c test.cpp

# .PHONY: clean test.o

# VPATH

# VPATH = include:src

# main: main.o test.o
# 	g++ -o main main.o

# test.o: test.cpp test.h
# 	g++ -c $< 
# # g++ -c $< -I include/


# main.o: main.cpp 
# 	g++ -c $< 


# 第一版
# main: main.o test.o 
# 	g++ -o main main.o test.o 

# main.o: main.cpp test.h
# 	g++ -c main.cpp 

# test.o: test.cpp test.h	
# 	g++ -c test.cpp

# VPATH = include:src


# 第2版
# 使用 "$<" 这个自动变量
# VPATH = include:src

# main: main.o test.o 
# 	g++ -o main $<

# main.o: main.cpp test.h
# 	g++ -c $<

# test.o: test.cpp test.h	
# 	g++ -c $<

# VPATH = include:src

#  make -n
# g++ -c src/main.cpp
# g++ -c include/test.cpp
# g++ -o main main.o

# 执行make指令之后 依然报错
# g++ -c src/main.cpp
# src/main.cpp:2:10: fatal error: test.h: No such file or directory
#     2 | #include "test.h"
#       |          ^~~~~~~~
# compilation terminated.
# Makefile:58: recipe for target 'main.o' failed
# make: *** [main.o] Error 1

# 第3版
# 使用 "$<" 这个自动变量

# main: main.o test.o 
# 	g++ -o main $<

# main.o: main.cpp test.h
# 	g++ -c $< -I include

# test.o: test.cpp test.h	
# 	g++ -c $< -I include

# VPATH = include:src

# 执行 make -n
# g++ -c src/main.cpp -I include
# g++ -c src/test.cpp -I include
# g++ -o main main.o

# 执行 make
# g++ -c src/main.cpp -I include
# g++ -c src/test.cpp -I include
# g++ -o main main.o

# 没有报错

main: main.o test.o 
	g++ -o main $<

main.o: main.cpp test.h
	g++ -c $< -I include

test.o: test.cpp test.h	
	g++ -c $< -I include

vpath %.h include
vpath % src

.DEFAULT_GOAL = main

ifeq ($(OS),Windows_NT)
RM := del /q /f
else
RM = rm -f
endif

.PHONY: clean
clean:
	$(RM) main.exe *.o