##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## it makes files
##

SRC = 	$(wildcard src/*.c src/*/*.c src/*/*/*.c lib/*.c lib/*/*.c)

OBJ = $(SRC:.c=.o)

CFLAGS += -g -Wall -Wextra -I./includes

NAME = "navy"

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

all:     $(NAME)

clear:
	make
	clear
	echo "Done !"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all
