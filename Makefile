main:14.cpp
	g++ -o main 14.cpp -Wall -Wextra -Woverflow -fsanitize=undefined
.PHONY: clean
clear:
	rm main
	