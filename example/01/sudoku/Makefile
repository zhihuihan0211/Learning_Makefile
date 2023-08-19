
ifeq ($(OS),Windows_NT)
RM			:= del /q /f
else
RM = rm -f
endif

# 基础写法介绍
# target ...（目标） ： ....依赖
# 	：方法				# 注意这里是tab 不是空格
######################################################

sudoku: block.o command.o input.o main.o scene.o test.o
	g++ -o sudoku block.o command.o input.o main.o scene.o test.o

block.o: block.cpp common.h block.h color.h
	g++ -c block.cpp

command.o: command.cpp scene.h common.h block.h command.h
	g++ -c command.cpp

input.o: input.cpp common.h utility.inl
	g++ -c input.cpp

main.o: main.cpp scene.h common.h block.h command.h input.h test.h
	g++ -c main.cpp

scene.o: scene.cpp common.h scene.h block.h command.h utility.inl
	g++ -c scene.cpp

test.o: test.cpp test.h scene.h common.h block.h command.h
	g++ -c test.cpp

clean:
	$(RM) block.o command.o input.o main.o scene.o test.o
	$(RM) sudoku.exe