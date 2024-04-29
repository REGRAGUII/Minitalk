# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/09 19:13:01 by yregragu          #+#    #+#              #
#    Updated: 2024/04/28 20:09:07 by yregragu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=   libft.a
CC  =    cc
CFLAGS  =   -Wall -Wextra -Werror

SRC    =         ft_strlen.c \
             ft_memmove.c \
             ft_memcpy.c \
             ft_strlcpy.c \
             ft_strlcat.c \
             ft_isalpha.c \
             ft_isdigit.c \
             ft_isalnum.c \
             ft_isascii.c \
             ft_isprint.c \
             ft_memset.c \
             ft_bzero.c \
             ft_toupper.c \
             ft_tolower.c \
             ft_strchr.c \
             ft_strrchr.c \
             ft_strncmp.c \
             ft_atoi.c \
             ft_calloc.c \
             ft_strdup.c \
             ft_strnstr.c \
             ft_memchr.c \
             ft_memcmp.c \
             ft_substr.c \
             ft_strjoin.c \
             ft_putchar_fd.c \
             ft_putendl_fd.c \
             ft_putstr_fd.c \
             ft_putnbr_fd.c \
             ft_strtrim.c \
             ft_strmapi.c \
             ft_split.c \
             ft_striteri.c \
             ft_itoa.c \
             ft_printf.c \
             ft_putnbr_base.c \
             ft_putnbr.c \
             ft_putstr.c \
             ft_putchar.c \

BSRC =      ft_lstadd_back_bonus.c \
             ft_lstadd_front_bonus.c \
             ft_lstnew_bonus.c \
             ft_lstsize_bonus.c \
             ft_lstlast_bonus.c \
             ft_lstdelone_bonus.c \
             ft_lstclear_bonus.c \
             ft_lstiter_bonus.c \
             ft_lstmap_bonus.c \
             


OBJEC = $(SRC:.c=.o)
BOBJEC = $(BSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJEC)

bonus : $(BOBJEC)

.c.o :
	$(CC) $(CFLAGS) -c $<
	ar rcs $(NAME) $@


clean:
	rm -rf $(BOBJEC) $(OBJEC)


fclean: clean
	rm -rf $(NAME)


re: fclean all

.PHONY: all clean fclean bonus re
