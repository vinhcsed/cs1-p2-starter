F = -std=c++20 -Wall -Wextra -Wpedantic -Wfatal-errors
P = myprogram

all: out run

out: *.cpp
	g++ $F *.cpp -o $P

run: $P
	./$P