##BEGIN#__________________________>#_|INFO|_#<________________________________##
##                                                           ______ _         ##
## DETAILS:                                                  | ___ (_)        ##
##- FILENAME		Makefile                                 | |_/ /___  __   ##
##- PROJECT_NAME	CPP02-ex00                               |  __/| \ \/ /   ##
##- AUTHOR			Pixailz                                  | |   | |>  <    ##
##- CREATED			2023−02−03T14:54:04+0100                 \_|   |_/_/\_\   ##
##                                                                            ##
##END#____________________________<#_|INFO|_#>________________________________##

##BEGIN#_________________________>#_|CONFIG|_#<_______________________________##

TARGET					:= fixed

CC						:= g++
CFLAGS					:= -Wall -Wextra --std=c++98

SRC_DIR					:= .
OBJ_DIR					:= obj
INC_DIR					:= .

CFLAGS					+= -I$(INC_DIR)

ifeq ($(DEBUG),1)
CFLAGS					+= -g3
else
CFLAGS					+= -Werror
endif

RM						:= rm -rf
MKDIR					:= mkdir -p
MAKE					:= make
PRINTF					:= @printf

SRC_CPP					:= main.cpp				\
						   Fixed.cpp

OBJ_CPP					:= $(addprefix $(OBJ_DIR)/,$(SRC_CPP:%.cpp=%.o))
SRC_CPP					:= $(addprefix $(SRC_DIR)/,$(SRC_CPP))

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

##END#___________________________<#_|RULES|_#>________________________________##
