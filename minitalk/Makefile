#-*- Makefile -*-

#target : dependencies
#       action
CFLAGS = -Wall -Wextra -Werror

UTILS = utils.c
SERVER = server.c
CLIENT = client.c

SERVER_BONUS = server_bonus.c
CLIENT_BONUS = client_bonus.c

OBJ_UTILS = $(UTILS:.c=.o)
OBJ_SERVER = $(SERVER:.c=.o)
OBJ_CLIENT = $(CLIENT:.c=.o)

OBJ_SERVER_BONUS = $(SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS = $(CLIENT_BONUS:.c=.o)

all: server client

server: $(OBJ_SERVER) $(OBJ_UTILS)
		cc $(CFLAGS) $(OBJ_SERVER) $(OBJ_UTILS) -o server
		@printf [SUCCESS]"Server was created.\n"

client: $(OBJ_CLIENT) $(OBJ_UTILS)
		cc $(CFLAGS) $(OBJ_CLIENT) $(OBJ_UTILS) -o client
		@printf [SUCCESS]"Client was created.\n"

bonus: $(OBJ_CLIENT_BONUS) $(OBJ_UTILS) $(OBJ_SERVER_BONUS)
		cc $(CFLAGS) $(OBJ_CLIENT_BONUS) $(OBJ_UTILS) -o client
		cc $(CFLAGS) $(OBJ_SERVER_BONUS) $(OBJ_UTILS) -o server
		@printf [SUCCESS]"BONUS TIME.\n"
clean:
		rm -rf $(OBJ_SERVER) $(OBJ_UTILS) $(OBJ_CLIENT)
		rm -rf $(OBJ_SERVER_BONUS) $(OBJ_UTILS) $(OBJ_CLIENT_BONUS)

fclean: clean
		rm -f server client

re : fclean all
