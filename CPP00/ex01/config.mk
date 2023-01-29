# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    config.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 19:36:36 by brda-sil          #+#    #+#              #
#    Updated: 2023/01/29 09:10:11 by brda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET			:= contact_app
CC				:= c++
CFLAGS			:= -Wall -Wextra --std=c++98
RM				:= rm -rf

SRC_C			:= Contact.cpp					\
				   PhoneBook.cpp				\
				   main.cpp

OBJ_C			:= $(SRC_C:%.cpp=%.o)
