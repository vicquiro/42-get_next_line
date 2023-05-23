# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vquiroga <vquiroga@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 16:24:05 by vquiroga          #+#    #+#              #
#    Updated: 2022/10/15 16:34:16 by vquiroga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar 
ARFLAGS = -rcs
NAME = getNextLineLib
RM = rm -rf
HDRS = includes/get_next_line.h

################################################################################
##								MANDATORY									  ##
################################################################################
CFILES = \
		srcs/get_next_line.c
		srcs/get_next_line_utils.c 
#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #
OBJS = $(CFILES:.c=.o)
################################################################################
.PHONY: all re fclean clean
################################################################################

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(AR) $(ARFLAGS) $@ $^
			
.c.o:
		 	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HDRS}

re:     	fclean all

fclean:     clean
			@$(RM) $(NAME)

clean:		
			@$(RM) $(OBJS)

