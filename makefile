# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 15:41:13 by yregragu          #+#    #+#              #
#    Updated: 2024/05/04 11:10:59 by yregragu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror	-Wextra	
SRC_CLIENT = client.c
SRC_SERVER = server.c
SRC_CLIENT_BONUS = client_bonus.c
SRC_SERVER_BONUS = server_bonus.c
OBJEC_CLIENT = $(SRC_CLIENT:.c=.o)
OBJEC_SERVER = $(SRC_SERVER:.c=.o)
OBJEC_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)
OBJEC_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)
CLIENT_NAME = client
SERVER_NAME = server
CLIENT_NAME_BONUS = client_bonus
SERVER_NAME_BONUS = server_bonus


all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(OBJEC_CLIENT)
	$(CC) $(CFLAGS) $(OBJEC_CLIENT) -o $(CLIENT_NAME)

$(SERVER_NAME): $(OBJEC_SERVER)
	$(CC) $(CFLAGS) $(OBJEC_SERVER) -o $(SERVER_NAME)

bonus: $(CLIENT_NAME_BONUS) $(SERVER_NAME_BONUS)

$(CLIENT_NAME_BONUS): $(OBJEC_CLIENT_BONUS)
	$(CC) $(CFLAGS) $(OBJEC_CLIENT_BONUS) -o $(CLIENT_NAME_BONUS)

$(SERVER_NAME_BONUS): $(OBJEC_SERVER_BONUS)
	$(CC) $(CFLAGS) $(OBJEC_SERVER_BONUS) -o $(SERVER_NAME_BONUS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJEC_CLIENT) $(OBJEC_SERVER)
	rm -rf $(OBJEC_CLIENT_BONUS) $(OBJEC_SERVER_BONUS)
fclean: clean
	rm -rf $(CLIENT_NAME) $(SERVER_NAME)
	rm -rf $(CLIENT_NAME_BONUS) $(SERVER_NAME_BONUS)

re: fclean all

