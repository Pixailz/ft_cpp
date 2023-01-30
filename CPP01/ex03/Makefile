##BEGIN#__________________________>#_|INFO|_#<________________________________##
##                                                           ______ _         ##
## DETAILS:                                                  | ___ (_)        ##
##- FILENAME		Makefile                                 | |_/ /___  __   ##
##- AUTHOR			Pixailz                                  |  __/| \ \/ /   ##
##- CREATED			2023−01−30T10:37:01+0100                 | |   | |>  <    ##
##                                                           \_|   |_/_/\_\   ##
## DESCRIPTION:                                                               ##
### None                                                                      ##
##                                                                            ##
##                                                                            ##
## VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                     ##
##END#____________________________<#_|INFO|_#>________________________________##

##BEGIN#_________________________>#_|CONFIG|_#<_______________________________##

TARGET					:= /(.*)//(.*)//downcase:prog_name:prog_name

CC						:= g++
CFLAGS					:= -Wall -Wextra --std=c++98

SRC_DIR					:= src
OBJ_DIR					:= obj
INC_DIR					:= inc

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

SRC_CPP					:= main.cpp					\
						   utils/ft_strlen.cpp

OBJ_CPP					:= $(addprefix $(OBJ_DIR)/,$(SRC_CPP:%.cpp=%.o))
SRC_CPP					:= $(addprefix $(SRC_DIR)/,$(SRC_CPP))

##END#___________________________<#_|CONFIG|_#>_______________________________##

##BEGIN#________________________>#_|FUNCTION|_#<______________________________##

##END#__________________________<#_|FUNCTION|_#>______________________________##

##BEGIN#__________________________>#_|RULES|_#<_______________________________##

.DEFAULT:				$(TARGET)

.PHONY:					clean
.PHONY:					fclean
.PHONY:					re

all:					$(TARGET)

# 1 MAKE TARGET
$(TARGET):				$(OBJ_CPP)
	$(CC) $(CFLAGS) $(OBJ_CPP) -o $(TARGET)

# 2 BUILD OBJS
$(OBJ_DIR)/%.o:			$(SRC_DIR)/%.cpp
## check if obj dir parent folder exist, if not create it
		$(shell [ -d $(@D) ] || $(MKDIR) $(@D))
		$(CC) $(CFLAGS) -o $@ -c $^

clean:
	$(RM) $(OBJ_CPP)

fclean:					clean
	$(RM) $(TARGET)

re:						fclean $(TARGET)

##END#____________________________<#_|RULES|_#>_______________________________##
