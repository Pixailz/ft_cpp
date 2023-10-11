##BEGIN#__________________________>#_|INFO|_#<________________________________##
##                                                           ______ _         ##
## DETAILS:                                                  | ___ (_)        ##
##- FILENAME		Makefile                                 | |_/ /___  __   ##
##- PROJECT_NAME	None                                     |  __/| \ \/ /   ##
##- AUTHOR			Pixailz                                  | |   | |>  <    ##
##- CREATED			2023−04−18T00:19:10+0100                 \_|   |_/_/\_\   ##
##                                                                            ##
##END#____________________________<#_|INFO|_#>________________________________##

##BEGIN#_________________________>#_|CONFIG|_#<_______________________________##

TARGET					:= PmergeMe

CC						:= g++
CFLAGS					:= -Wall -Wextra --std=c++98 -g3

SHELL					:= /bin/bash

SRC_DIR					:= ./src
OBJ_DIR					:= obj
INC_DIR					:= ./inc

CFLAGS					+= -I$(INC_DIR)

ifeq ($(DEBUG),1)
CFLAGS					+= -g3 -D DEBUG=0
else
CFLAGS					+= -Werror
endif

RM						:= rm -rf
MKDIR					:= mkdir -p
MAKE					:= make
PRINTF					:= @printf

SRC_CPP					:=	main.cpp \
							PmergeMeVector.cpp \
							PmergeMeDeque.cpp \
							utils.cpp

OBJ_CPP					:= $(addprefix $(OBJ_DIR)/,$(SRC_CPP:%.cpp=%.o))
SRC_CPP					:= $(addprefix $(SRC_DIR)/,$(SRC_CPP))

PRINT_ANSI				= printf "%b" "$(1)"

##END#___________________________<#_|CONFIG|_#>_______________________________##

##BEGIN#_________________________>#_|RULES|_#<________________________________##

.DEFAULT:				$(TARGET)

.PHONY:					clean
.PHONY:					fclean
.PHONY:					re

all:					$(TARGET)

# 1 MAKE TARGET
$(TARGET):				$(OBJ_CPP)
	$(CC) $(CFLAGS) $(OBJ_CPP) -o $(TARGET)

# 2 BUILD OBJS
$(OBJ_CPP):				$(OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
## check if obj dir parent folder exist, if not create it
	$(shell [ -d $(@D) ] || $(MKDIR) $(@D))
	$(CC) $(CFLAGS) -o $@ -c $^

clean:
	$(RM) $(OBJ_DIR)

fclean:					clean
	$(RM) $(TARGET)

re:						fclean $(TARGET)

run:						$(TARGET)
	@$(call PRINT_ANSI,\x1b[2J\x1b[H)
	./$(TARGET) $$(shuf -i 1-$${MAX:-10} -n $${MAX:-10} | tr '\n' ' ')

##END#___________________________<#_|RULES|_#>________________________________##
