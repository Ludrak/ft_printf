# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrobino <lrobino@student.le-101.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/28 00:13:18 by lrobino           #+#    #+#              #
#    Updated: 2020/03/03 12:42:18 by lrobino          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

AUTHOR			= lrobino

NAME			= libftprintf.a
EXEC			= test-printf.out

VERSION			= 1.0

SRCS			= ft_printf.c					\
				  ft_printf_parser.c			\
				  ft_type_parser.c				\
				  ft_printf_utils.c				\
				  ft_printf_basic_utils.c		\
				  ft_printf_basic_utils_bis.c



BIN_DIR			= bin
OBJS			= $(addprefix $(BIN_DIR)/,$(SRCS:.c=.o))

INCLUDES		= -Iincludes -Ilibft

LIBFILES		= libft
LIB_DIR			= lib

ifdef LIBFILES
	LIBS			= $(addprefix $(LIB_DIR)/,$(addprefix $(LIBFILES),.a))
endif

RM				= rm -rf
CC				= gcc -c
LNK				= gcc
LIBLNK			= ar rcus
CFLAGS			= -Wall -Wextra -Werror -g3
OUT				= --output

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



all : v $(LIBS) $(NAME)
	@echo "$(C_RESET)Done."



bonus : all



$(NAME) : $(LIBS) $(BIN_DIR) $(OBJS)
	@echo "\r$(m_MAKE) Successfully compiled project : $(BGREEN)$(NAME)$(C_RESET)"
	@echo "$(m_LINK) Starting linker process..."
	@cp $(LIBS) ./$(NAME)
	@$(LIBLNK) $(NAME) $(OBJS)
	@echo "$(m_LINK) Link sucess ! '$(NAME)' created."



c : compile
compile : $(LIBS) $(BIN_DIR) $(OBJS)
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
	@echo "\n\n\033[1;36m#################################################################################"
	@printf "\033[1;36m#  \033[0m[\033[1;36mLIBRARY\033[0m] ->	\033[1;35mCOMPILE		\033[0;32mCompiling : \033[0;35m%-30s\033[1;36m      #\n" $<
	@echo "\033[1;36m#################################################################################\n"
	@make re -C $<
	@mv $</$<.a $(LIB_DIR)/$<.a
	@echo "\033[1;36m\n#################################################################################"
	@echo "\033[1;36m#################################################################################\n\n"



cl : clean
clean :
	@$(RM) $(BIN_DIR)
	@echo "$(m_REMV) Removed .o files."



lc : lclean
lclean :
	@$(RM) $(LIBS)
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
	@clear
	@echo "$(BBLUE)#################################################################################"
	@echo "#                                                                               #"

	@echo "#            :::      ::::::::                                                  #"
	@echo "#          :+:      :+:    :+:                                                  #"
	@echo "#       +:+ +:+         +:+                                                     #"
	@echo "#     +#+  +:+       +#+                                                        #"
	@echo "#   +#+#+#+#+#+   +#+                                                           #"
	@echo "#         #+#    #+#                                                            #"
	@echo "#        ###   ######## - lyon                                                  #"
	@echo "#                                                                               #"
	@echo "#$(C_RESET)>-----------------------------------------------------------------------------<$(BBLUE)#"
	@printf "#$(C_RESET)   Project : %-20.20s                                              $(BBLUE)#\n" $(NAME)
	@printf "#$(C_RESET)   Version : %-15.15s                       Author : %-10.10s         $(BBLUE)#\n" $(VERSION) $(AUTHOR)
	@echo "#################################################################################$(C_RESET)\n\n"



re : v fclean $(LIB_DIR)  all



recomp : v clean $(LIB_DIR) compile

.PHONY	: all c compile recomp re fclean fc lclean lc clean version v cat ce bonus 
