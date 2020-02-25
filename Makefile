# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 11:37:14 by sunpark           #+#    #+#              #
#    Updated: 2020/02/25 23:18:38 by sunpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TST		= check_libc.c
TSTDIR	= tests


SRCS	= ft_memset.c ft_bzero.c ft_memcpy.c
OBJS	= $(SRCS:.c=.o)
GCNOS	= $(SRCS:.c=.gcno)
GCDAS	= $(SRCS:.c=.gcda)

TSTS	= $(addprefix $(TSTDIR)/, $(TST))
TOBJS	= $(TSTS:.c=.o)
TGCNOS	= $(TSTS:.c=.gcno)
TGCDAS	= $(TSTS:.c=.gcda)

NAME	= libft.a
TSTNAME	= tests/ck_libft

GCC		= gcc
GCCFLAG	= -Wall -Wextra -Werror -std=c99
PFLAG	= -fprofile-arcs -ftest-coverage
TSTFLAG	= -lcheck -lm -lpthread --coverage
RM		= rm -f

.c.o:
			$(GCC) $(GCCFLAG) $(PFLAG) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

all:		$(NAME)

$(TSTNAME):	$(OBJS) $(TOBJS)
			$(GCC) $(OBJS) $(TOBJS) $(TSTFLAG) -o $(TSTNAME)

test:		$(TSTNAME)
			./$(TSTNAME)
			make fclean

clean:
			$(RM) $(OBJS) $(TOBJS) $(GCNOS) $(TGCNOS) $(GCDAS) $(TGCDAS)

fclean:		clean
			$(RM) $(NAME) $(TSTNAME)

re:			fclean all

reclean:	fclean all clean

.PHONY:		all test clean fclean re reclean .c.o
