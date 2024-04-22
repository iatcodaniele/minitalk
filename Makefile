# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diatco <diatco@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 16:33:58 by diatco            #+#    #+#              #
#    Updated: 2024/04/22 15:22:15 by diatco           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --VARIABLES--

SERVER =	server
CLIENT =	client
CC =	cc
CFLAGS =	-Wall -Wextra -Werror
RM =	rm -f
SRC =	server.c client.c minitalk_utils.c
OBJ =	$(SRC:.c=.o)

# --RULES--

all:	$(SERVER) $(CLIENT) $(UTILS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER):	$(SRC)
	$(CC) $(CFLAGS) -o $(SERVER) server.c minitalk_utils.c  

$(CLIENT):	$(SRC)
	$(CC) $(CFLAGS) -o $(CLIENT) client.c minitalk_utils.c

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(SERVER) $(CLIENT)
	

re:	fclean all

.PHONY: all clean fclean re
.SILENT: all $(SERVER) $(CLIENT) clean fclean re