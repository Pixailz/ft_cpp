# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 19:36:36 by brda-sil          #+#    #+#              #
#    Updated: 2023/01/28 13:45:31 by brda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET			:= prog
CC				:= c++
CFLAGS			:= -Wall -Wextra -Werror --std=c++98
RM				:= rm -rf

SRC_C			:= Contact.cpp					\
				   PhoneBook.cpp				\
				   main.cpp

OBJ_C			:= $(SRC_C:%.cpp=%.o)

$(TARGET):		$(OBJ_C)
	$(CC) $(OBJ_C) $(CFLAGS) -o $@

%.o				: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) $(OBJ_C)

fclean:			clean
	$(RM) $(TARGET)

re:	fclean $(TARGET)
