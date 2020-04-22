main:7.cpp
	g++ -o main 7.cpp -Wall -Wextra -Woverflow -fsanitize=undefined
.PHONY: clean
clear:
	rm main
	