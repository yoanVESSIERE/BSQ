##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## 
##

SRC = bsq.c function.c function2.c function3.c

OBJ = bsq.o function.o function2.o function3.o

CFLAGS = -W -Wall -Wextra -O2

all: bsq

bsq: $(OBJ)
	gcc $(OBJ) -o bsq

$(OBJ): $(SRC)
	gcc $(CFLAGS) -c $(SRC)

clean:
	rm $(OBJ)

fclean:
	rm bsq

re : clean fclean all
