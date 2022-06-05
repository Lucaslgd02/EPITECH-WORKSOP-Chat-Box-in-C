##
## EPITECH PROJECT, 2022
## -EPITECH-WORKSOP-Chat-Box-in-C
## File description:
## Makefile
##

SRC_SERVER	=	src/server/main.c \
				src/server/error_handling.c	\
				src/server/server.c	\

SRC_CLIENT	=	src/client/main.c \
				src/client/error_handling.c	\
				src/client/client.c	\

OBJ_SERVER	=	$(SRC_SERVER:.c=.o)

OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)

CFLAGS 	= 	-Wall -Wextra -g3
CFLAGS	= 	-I./server -I./client

SERVER_NAME	=	server

CLIENT_NAME	=	client

all: server client

server: $(OBJ_SERVER)
		gcc -o $(SERVER_NAME) $(OBJ_SERVER)

client: $(OBJ_CLIENT)
		gcc -o $(CLIENT_NAME) $(OBJ_CLIENT)

clean:
		rm -f $(OBJ_SERVER)
		rm -f $(OBJ_CLIENT)

fclean: clean
		rm -f $(SERVER_NAME)
		rm -f $(CLIENT_NAME)

re:	fclean all
