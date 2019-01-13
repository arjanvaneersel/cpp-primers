clean:
	rm main

build:
	g++ -Wall -Wextra -Werror main.cpp -o main

run: build
	chmod +x ./main
	./main