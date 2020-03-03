# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrobino <lrobino@student.le-101.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/28 00:13:18 by lrobino           #+#    #+#              #
#    Updated: 2020/03/03 12:40:31 by lrobino          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#Name if compiled as lib
NAME			= libft.a
#Name if compiled as executable
EXEC			= test-libft.out

VERSION			= 1.0
AUTHOR			= lrobino


SRCS		=	ft_memset.c			\
				ft_memcpy.c			\
				ft_memccpy.c		\
				ft_memmove.c		\
				ft_bzero.c			\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_strlen.c			\
				ft_isalpha.c		\
				ft_isdigit.c		\
				ft_isalnum.c		\
				ft_isascii.c		\
				ft_isprint.c		\
				ft_toupper.c		\
				ft_tolower.c		\
				ft_strchr.c			\
				ft_strrchr.c		\
				ft_strncmp.c		\
				ft_strlcpy.c		\
				ft_strlcat.c		\
				ft_strnstr.c		\
				ft_atoi.c			\
				ft_calloc.c			\
				ft_putchar_fd.c		\
				ft_putstr_fd.c		\
				ft_putendl_fd.c		\
				ft_strdup.c			\
				ft_putnbr_fd.c		\
				ft_substr.c			\
				ft_strjoin.c		\
				ft_itoa.c			\
				ft_strmapi.c		\
				ft_strtrim.c		\
				ft_split.c			\
				ft_ltoa_base.c		\
				ft_itoa_base.c		\
				ft_strinsert.c		\
				ft_utoa.c           \
                ft_lstnew.c			\
				ft_lstadd_front.c	\
				ft_lstsize.c		\
				ft_lstlast.c		\
				ft_lstadd_back.c	\
				ft_lstdelone.c		\
				ft_lstclear.c		\
				ft_lstiter.c		\
				ft_lstmap.c


# COMP & LIB 


#define this to use external libs compilation (need to include a Makefile to compile the lib)

#LIB_DIR			= 
#LIBFILES		= 

ifdef LIBFILES
	LIBS			= $(addprefix $(LIB_DIR)/,$(addprefix $(LIBFILES),.a))
endif

BIN_DIR			= bin
OBJS			= $(addprefix $(BIN_DIR)/,$(SRCS:.c=.o))

INCLUDES		= -I.

CC				= gcc -c
LNK				= gcc
LIBLNK			= ar rcus
CFLAGS			= -Wall -Wextra -Werror -g3
OUT				= --output

RM				= rm -rf


#
#	COLORS
#
C_RESET= \033[0m
BGREEN = \033[1;32m
GREEN = \033[0;32m
YELLOW	= \033[0;33m
BYELLOW = \033[1;33m
PURPLE = \033[0;35m
BPURPLE = \033[1;35m
BRED	= \033[1;31m
RED		= \033[0;31m
BLUE	= \033[0;34m
BBLUE	= \033[1;34m
m_MAKE		= $(C_RESET)[$(BBLUE) $(NAME) $(C_RESET)] [$(PURPLE)MAKE$(C_RESET)] :
m_INFO		= $(C_RESET)[$(BBLUE) $(NAME) $(C_RESET)] [$(PURPLE)INFO$(C_RESET)] :
m_LINK		= $(C_RESET)[$(BBLUE) $(NAME) $(C_RESET)] [$(PURPLE)LINK$(C_RESET)] :
m_COMP		= $(C_RESET)[$(BBLUE) $(NAME) $(C_RESET)] [$(PURPLE)COMP$(C_RESET)] :

m_WARN		= $(C_RESET)[$(BBLUE) $(NAME) $(C_RESET)] [$(BYELLOW)WARN$(C_RESET)] :$(YELLOW)
m_REMV		= $(C_RESET)[$(BBLUE) $(NAME) $(C_RESET)] [$(BRED)CLEAN$(C_RESET)] :$(BYELLOW)



all : v $(NAME)
	@echo "$(C_RESET)Done."



bonus : all



$(NAME) : $(LIB_DIR) $(LIBS) $(BIN_DIR) $(OBJS)
	@echo "\r$(m_MAKE) Successfully compiled project : $(BGREEN)$(NAME)$(C_RESET)"
	@echo "$(m_LINK) Starting linker process..."
	@$(LIBLNK) $(NAME) $(OBJS)
	@echo "$(m_LINK) Link sucess ! '$(NAME)' created."



c : compile
compile : $(LIB_DIR) $(LIBS) $(BIN_DIR) $(OBJS)
	@echo "\r$(m_MAKE) Successfully compiled project : $(BGREEN)$(NAME)$(C_RESET)"
	@echo "$(m_LINK) Starting linker process..."
	@$(LNK) $(OUT) $(EXEC) $(OBJS) $(LIBS)
	@echo "$(m_LINK) Link sucess ! '$(NAME)' created."
	@echo "$(m_INFO) Executing project : $(BGREEN)$(EXEC)\n$(BPURPLE)=V=[$(EXEC)]=V=$(C_RESET)"
	@./$(EXEC)
	


ce : cat
cat : $(BIN_DIR) $(OBJS)
	@$(LNK) $(OUT) $(EXEC) $(OBJS) $(LIBS)
	@./$(EXEC) | cat -e



$(BIN_DIR) :
	@mkdir -p $(BIN_DIR)
	@echo "$(m_WARN) Failed to locate $(BIN_DIR) directory. Creating it...$(C_RESET)";


$(LIB_DIR) :
	@mkdir -p $(LIB_DIR)
	@echo "$(m_WARN) Failed to locate $(LIB_DIR) directory. Creating it...$(C_RESET)";



$(BIN_DIR)/%.o : %.c
	@$(CC) $< $(CFLAGS) $(OUT) $@ $(INCLUDES)
	@printf "\r$(m_COMP) Compiled : $<"


$(LIB_DIR)/%.a : $(LIBFILES)
	@echo "\n\033[1;36m#################################################################################"
	@printf "\033[1;36m#  \033[0m[\033[1;36mLIBRARY\033[0m] ->	\033[1;35mCOMPILE		\033[0;32mCompiling : \033[0;35m%-30s\033[1;36m      #\n" $<
	@echo "\033[1;36m#################################################################################"
	@make re -C $<
	@mv $</$<.a $(LIB_DIR)/$<.a
	@echo "\033[1;36m#################################################################################"
	@echo "\033[1;36m#################################################################################\n\n"



cl : clean
clean :
	@$(RM) $(BIN_DIR)
	@echo "$(m_REMV) Removed .o files."



lc : lclean
lclean :
	@$(RM) $(LIB_DIR)
ifdef LIBFILES
	@make fclean -C $(LIBFILES)
endif
	@echo "$(m_REMV) Removed libfiles"



fc : fclean
fclean : lc cl
	@$(RM) $(NAME)
	@$(RM) $(NAME).dSYM
	@$(RM) $(EXEC)
	@$(RM) $(EXEC).dSYM
	@echo "$(m_REMV) Removed exectuable : '$(NAME)'"



v : version
version :
	@echo "$(BBLUE)#################################################################################"
	@echo "#                                                                               #"

	@echo "#            :::      ::::::::                                                  #"
	@echo "#          :+:      :+:    :+:                                                  #"
	@echo "#       +:+ +:+         +:+                                                     #"
	@echo "#     +#+  +:+       +#+                                                        #"
	@echo "#   +#+#+#+#+#+   +#+                                                           #"
	@echo "#         #+#    #+#                                                            #"
	@echo "#        ###   ######## - Lyon                                                  #"
	@echo "#                                                                               #"
	@echo "#$(C_RESET)>-----------------------------------------------------------------------------<$(BBLUE)#"
	@printf "#$(C_RESET)   Project : %-20.20s                                              $(BBLUE)#\n" $(NAME)
	@printf "#$(C_RESET)   Version : %-15.15s                       Author : %-10.10s         $(BBLUE)#\n" $(VERSION) $(AUTHOR)
	@echo "#################################################################################$(C_RESET)\n\n"



re : v fclean all



recomp : v fclean compile


ra : re-all
re-all : v fclean lclean all


.PHONY	: all c compile recomp re ra re-all fclean fc lclean lc clean version v cat ce bonus 
