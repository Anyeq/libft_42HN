# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asando <asando@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/16 14:20:33 by asando            #+#    #+#              #
#    Updated: 2025/03/17 16:03:14 by asando           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
COMP = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = .
CFILES = $(foreach X, $(SRCS), $(wildcard $(X)/ft_*))
OBJS = $(patsubst %.c, %.o, $(CFILES))
FINAL = libft.a

all : $(FINAL)

$(FINAL) : $(OBJS)
	ar cr $@ $^

%.o : %.c
	$(COMP) $(CFLAGS) $< -c -o $@ -I$(SRCS)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS)

re:
	rm -rf $(OBJS) $(FINAL)
