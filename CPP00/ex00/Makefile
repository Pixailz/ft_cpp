# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 19:36:36 by brda-sil          #+#    #+#              #
#    Updated: 2023/01/29 09:23:17 by brda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET			:= megaphone
CC				:= c++
CFLAGS			:= -Wall -Wextra -Werror --std=c++98
RM				:= rm -rf

SRC_CPP			:= megaphone.cpp
OBJ_CPP			:= $(SRC_CPP:%.cpp=%.o)

$(TARGET):		$(OBJ_CPP)
	$(CC) $(OBJ_CPP) $(CFLAGS) -o $@

%.o				: %.cpp
	$(CC) -c $^

clean:
	$(RM) $(OBJ_CPP)

fclean:			clean
	$(RM) $(TARGET)

re:	fclean $(TARGET)
