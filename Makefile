# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 11:37:14 by sunpark           #+#    #+#              #
#    Updated: 2020/03/01 23:20:02 by sunpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TST		= check_libc.c
TSTDIR	= tests


SRCS	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		  ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c \
		  ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
		  ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c \
		  ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
		  ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJS	= $(SRCS:.c=.o)
GCNOS	= $(SRCS:.c=.gcno)
GCDAS	= $(SRCS:.c=.gcda)

TSTS	= $(addprefix $(TSTDIR)/, $(TST))
TOBJS	= $(TSTS:.c=.o)
TGCNOS	= $(TSTS:.c=.gcno)
TGCDAS	= $(TSTS:.c=.gcda)

BSRCS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		  ft_lstmap.c \
		  ft_isupper_bonus.c ft_islower_bonus.c ft_isnumber_bonus.c \
		  ft_isblank_bonus.c
BOBJS	= $(BSRCS:.c=.o)

NAME	= libft.a
TSTNAME	= tests/ck_libft

GCC		= gcc
GCCFLAG	= -Wall -Wextra -Werror -std=c99
PFLAG	= -fprofile-arcs -ftest-coverage
TSTFLAG	= -lcheck -lm -lpthread --coverage
RM		= rm -f

.c.o:
			$(GCC) $(GCCFLAG) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

all:		$(NAME)

bonus:		$(OBJS) $(BOBJS)
			ar rc $(NAME) $(BOBJS) $(OBJS)

$(TSTNAME):	$(OBJS) $(TOBJS)
			$(GCC) $(OBJS) $(TOBJS) $(TSTFLAG) -o $(TSTNAME)

test:		$(TSTNAME)
			./$(TSTNAME)
			make fclean

clean:
			$(RM) $(OBJS) $(TOBJS) $(GCNOS) $(TGCNOS) $(GCDAS) $(TGCDAS)
			$(RM) $(BOBJS)

fclean:		clean
			$(RM) $(NAME) $(TSTNAME)

re:			fclean all

reclean:	fclean all clean

.PHONY:		all test clean fclean re reclean .c.o
