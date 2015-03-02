##
## Makefile for makefile in /home/durand_u/github/PSU_2014_lemipc
## 
## Made by Rémi DURAND
## Login   <durand_u@epitech.net>
## 
## Started on  Mon Mar  2 12:16:51 2015 Rémi DURAND
## Last update Mon Mar  2 13:51:58 2015 Rémi DURAND
##

SRC	=	lemipc.c	\
		init.c		\
		map.c

CC	=	gcc

RM	=	rm -f

OBJ	=	$(SRC:.c=.o)

NAME	=	lemipc

CFLAGS	+=	-W -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all	
