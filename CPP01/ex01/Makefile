# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 19:36:36 by brda-sil          #+#    #+#              #
#    Updated: 2023/01/29 17:37:17 by brda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET			:= brainz
CC				:= c++
CFLAGS			:= -Wall -Wextra --std=c++98
RM				:= rm -rf

SRC_C			:= Zombie.cpp				\
				   zombieHorde.cpp			\
				   main.cpp

OBJ_C			:= $(SRC_C:%.cpp=%.o)

ifeq ($(DEBUG),1)
CFLAGS			+= -g3
else
CFLAGS			+= -Werror
endif

$(TARGET):		$(OBJ_C)
	$(CC) $(OBJ_C) $(CFLAGS) -o $@

%.o				: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) $(OBJ_C)

fclean:			clean
	$(RM) $(TARGET)

re:	fclean $(TARGET)
