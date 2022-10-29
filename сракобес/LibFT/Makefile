# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: risolon <risolon@student.21-school>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/13 16:20:28 by risolon           #+#    #+#              #
#    Updated: 2021/10/14 16:14:09 by risolon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a
LIST =	ft_atoi.c		ft_bzero.c		ft_calloc.c\
	   	ft_isalnum.c	ft_isalpha.c	ft_isascii.c\
		ft_isdigit.c	ft_isprint.c	ft_itoa.c\
		ft_memchr.c		ft_memcmp.c		ft_memcpy.c\
		ft_memmove.c	ft_memset.c		ft_putchar_fd.c\
		ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c\
		ft_split.c		ft_strchr.c		ft_strdup.c\
		ft_striteri.c	ft_strjoin.c	ft_strlcat.c\
		ft_strlcpy.c	ft_strlen.c		ft_strmapi.c\
		ft_strncmp.c	ft_strnstr.c	ft_strrchr.c\
		ft_strtrim.c	ft_substr.c		ft_tolower.c\
		ft_toupper.c

BONUS = ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c\
		ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c\
		ft_lstclear.c	ft_lstiter.c		ft_lstmap.c\

OBJ = $(patsubst %.c,%.o,$(LIST))
BONUS_OBJ = $(patsubst %.c,%.o,$(BONUS))
D_FILES = $(patsubst %.c,%.d,$(LIST) $(BONUS))

FLAGS = -Wall -Werror -Wextra
OPTIFLAGS = -O2

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?
%.o : %.c
	gcc $(FLAGS) $(OPTIFLAGS) -c $< -o $@ -MD
include $(wildcard $(D_FILES))

bonus : $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ) 
clean :
	rm -f $(OBJ) $(BONUS_OBJ) $(D_FILES)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
