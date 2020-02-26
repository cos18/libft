# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 11:37:14 by sunpark           #+#    #+#              #
#    Updated: 2020/02/26 22:50:52 by sunpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TST		= check_libc.c
TSTDIR	= tests


SRCS	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		  ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c \
		  ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c
OBJS	= $(SRCS:.c=.o)
GCNOS	= $(SRCS:.c=.gcno)
GCDAS	= $(SRCS:.c=.gcda)

TSTS	= $(addprefix $(TSTDIR)/, $(TST))
TOBJS	= $(TSTS:.c=.o)
TGCNOS	= $(TSTS:.c=.gcno)
TGCDAS	= $(TSTS:.c=.gcda)

BSRCS	= ft_isupper_bonus.c ft_islower_bonus.c
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
			ranlib $(NAME)

all:		$(NAME)

bonus:		$(OBJS) $(BOBJS)
			ar rc $(NAME) $(BOBJS) $(OBJS)
			ranlib $(NAME)

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
