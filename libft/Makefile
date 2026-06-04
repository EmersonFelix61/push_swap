# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emda-sil <emda-sil@student.42school.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/23 11:45:05 by emda-sil          #+#    #+#              #
#    Updated: 2026/06/04 13:51:46 by raferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
C_LIB = ar rcs
RM = rm -rf
LIB_SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		  ft_strlen.c ft_toupper.c ft_tolower.c ft_memcmp.c ft_atoi.c \
		  ft_strchr.c ft_memchr.c ft_strnstr.c ft_strncmp.c ft_memmove.c \
		  ft_memset.c ft_bzero.c ft_memcpy.c ft_strlcpy.c ft_split.c \
		  ft_strlcat.c ft_strrchr.c ft_calloc.c ft_strdup.c ft_substr.c \
		  ft_strtrim.c ft_strjoin.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		  ft_lstnew.c ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c \
		  ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstsize.c ft_lstclear.c \
		  ft_printf.c ft_print_hex.c ft_print_text.c ft_print_ptr.c \
		  ft_print_numbers.c ft_format.c

OBJ = $(LIB_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(C_LIB) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
