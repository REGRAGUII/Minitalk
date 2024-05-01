# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 15:41:13 by yregragu          #+#    #+#              #
#    Updated: 2024/05/01 23:21:56 by yregragu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror	-Wextra	
SRC_CLIENT = client.c
SRC_SERVER = server.c
OBJEC_CLIENT = $(SRC_CLIENT:.c=.o)
OBJEC_SERVER = $(SRC_SERVER:.c=.o)
CLIENT_NAME = client
SERVER_NAME = server

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(OBJEC_CLIENT)
	$(CC) $(CFLAGS) $(OBJEC_CLIENT) -o $(CLIENT_NAME)

$(SERVER_NAME): $(OBJEC_SERVER)
	$(CC) $(CFLAGS) $(OBJEC_SERVER) -o $(SERVER_NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJEC_CLIENT) $(OBJEC_SERVER)

fclean: clean
	rm -rf $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

