main:53.cpp
	g++ -o main 53.cpp -Wall -Wextra -Woverflow -fsanitize=undefined
.PHONY: clean
clear:
	rm main
	