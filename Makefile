##
## Makefile for makefile in /home/durand_u/github/PSU_2014_lemipc
## 
## Made by Rémi DURAND
## Login   <durand_u@epitech.net>
## 
## Started on  Mon Mar  2 12:16:51 2015 Rémi DURAND
## Last update Wed Mar  4 15:22:19 2015 Ambroise Coutarel
##

SRC	=	lemipc.c	\
		player.c	\
		map.c		\
		display.c	\
		semaphore.c	\
		move.c		\
		perception.c

CC	=	gcc

RM	=	rm -f

OBJ	=	$(SRC:.c=.o)

NAME	=	lemipc

CFLAGS	+=	-W -Wall -Wextra -Werror -lncurses

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all	
