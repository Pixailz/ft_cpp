TA	:= prog
CC	:= c++
CF	:= -I. -Wall -Wextra

ifeq ($(DEBUG),1)
CF	+= -g3
else
CF	+= -Werror -std=c++98
endif

SR	:=	main.cpp \
		Warlock.cpp \
		ASpell.cpp \
		ATarget.cpp \
		Fwoosh.cpp \
		Dummy.cpp \
		BrickWall.cpp \
		Fireball.cpp \
		Polymorph.cpp \
		SpellBook.cpp \
		TargetGenerator.cpp \

OD	:= obj
OB	:= $(addprefix $(OD)/,$(SR:%.cpp=%.o))

$(TA): $(OB)
	$(CC) $(CF) $(OB) -o $(TA)

$(OB): $(OD)/%.o:%.cpp
	@test ! -d $(@D) && mkdir -p $(@D) || true
	$(CC) $(CF) -c $< -o $@

clean:
	rm -rf $(OD)

fclean:	clean
	rm -rf $(TA)

re: fclean $(TA)

run: re
	./$(TA)
