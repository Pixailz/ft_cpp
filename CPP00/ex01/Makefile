# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 19:36:36 by brda-sil          #+#    #+#              #
#    Updated: 2023/01/29 09:23:11 by brda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET			:= contact_app
CC				:= c++
CFLAGS			:= -Wall -Wextra --std=c++98
RM				:= rm -rf

SRC_CPP			:= Contact.cpp					\
				   PhoneBook.cpp				\
				   main.cpp

OBJ_CPP			:= $(SRC_CPP:%.cpp=%.o)

ifeq ($(DEBUG),1)
CFLAGS			+= -g3
else
CFLAGS			+= -Werror
endif

$(TARGET):		$(OBJ_CPP)
	$(CC) $(OBJ_CPP) $(CFLAGS) -o $@

%.o				: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) $(OBJ_CPP)

fclean:			clean
	$(RM) $(TARGET)

re:	fclean $(TARGET)
