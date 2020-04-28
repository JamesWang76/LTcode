main:13.cpp
	g++ -o main 13.cpp -Wall -Wextra -Woverflow -fsanitize=undefined
.PHONY: clean
clear:
	rm main
	