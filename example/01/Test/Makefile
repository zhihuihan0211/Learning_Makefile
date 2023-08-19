
# 测试 makefile 命令
# 使用.DEFAULT_GOAL来修改默认最终目标
# .DEFAULT_GOAL = main

# .PHONY: all
# 	@echo 11111111

# all:
# 	@echo all

# main:
# 	@echo main

test.o: test.cpp test.h
	g++ -c test.cpp

.PHONY: clean test.o; all
