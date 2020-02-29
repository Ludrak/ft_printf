# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: lrobino <lrobino@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/28 00:13:18 by lrobino      #+#   ##    ##    #+#        #
#    Updated: 2020/02/04 00:12:11 by lrobino     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME			= libftprintf.a

SRCS			= ft_printf.c					\
				  ft_printf_parser.c			\
				  ft_type_parser.c				\
				  ft_printf_utils.c				\
				  ft_printf_basic_utils.c		\
				  ft_printf_basic_utils_bis.c

NB_SRCS				= $(words $(SRCS))
PROGRESS_BAR    	= 0
PROGRESS_BAR_SIZE 	= 20

LIBFILES		= libft.a

OBJDIR			= required_objs
OBJS			= $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

INCLUDES		= -Iincludes

LIBDIR			= lib
LIBS			= $(addprefix $(LIBDIR)/,$(LIBFILES)) 

RM				= rm -rf
CC				= gcc -c
LNK				= gcc
LIBLNK			= ar rcus
CFLAGS			= -Wall -Wextra -g3 #-Werror
OUT				= --output

all : $(NAME)

bonus : all





$(NAME) : pre $(OBJS)
	@echo "\033[0m[\033[1;32mMAKE\033[0m] ->	\033[1;35mINFO		\033[0;32mSuccessfully compiled project : \033[0;35m$(NAME)\n"
	@echo "\033[0m[\033[1;32mLINK\033[0m] ->	\033[1;35mINFO		\033[0;32mStarting linker process..."
	@cp $(LIBS) .
	@mv $(LIBFILES) $(NAME)
	@$(LIBLNK) $(NAME) $(OBJS)
	@echo "\033[0m[\033[1;32mLINK\033[0m] ->	\033[1;35mSUCCESS		\033[1;32mLink Success !	-> '$(NAME)' created"


#@echo "\033[0m[\033[1;32mMAKE\033[0m] ->    \033[1;35mINFO      \033[0;32mSuccessfully compiled project : \033[0;35m$(NAME)\n"
	@#@echo "\033[0m[\033[1;32mLINK\033[0m] ->    \033[1;35mINFO      \033[0;32mStarting linker process..."

	@#@echo "\033[0m[\033[1;32mLINK\033[0m] ->    \033[1;35mSUCCESS       \033[1;32mLink Success !    -> '$(NAME)' created"



c : compile
compile : pre $(OBJS)
	@$(LNK) $(OUT) $(NAME) $(OBJS) $(LIBS)
	@./$(NAME)


ce : cat
cat : pre $(OBJS)
	@$(LNK) $(OUT) $(NAME) $(OBJS) $(LIBS)
	@./$(NAME) | cat -e



l : leakchk
leakchk : pre $(OBJS)
	@echo "\033[0m[\033[1;32mMAKE\033[0m] ->    \033[1;35mINFO      \033[0;32mSuccessfully compiled project : \033[0;35m$(NAME)\n"
	@echo "\033[0m[\033[1;32mLINK\033[0m] ->    \033[1;35mINFO      \033[0;32mStarting linker process..."
	@$(LNK) $(OUT) $(NAME) $(OBJS) $(LIBS)
	@echo "\033[0m[\033[1;32mLINK\033[0m] ->    \033[1;35mSUCCESS       \033[1;32mLink Success !    -> '$(NAME)' created"
	valgrind --leak-check=full ./$(NAME)


pre : $(OBJDIR)
	@#echo "\033[1;37m\n> REQUIRED	- ############################################################################"
	@#echo "\n ----		\033[4;37mSTATUS\033[1;0m		\033[4;37mCOMMENT\033[1;0m"
	@c=0




$(OBJDIR) :
	@mkdir -p $(OBJDIR)
	@echo "\033[0m[\033[1;33mWARN\033[0m] ->	\033[1;33mWARNING		\033[0;33mFailed to locate $(OBJDIR) folder. Creating one..."




$(OBJDIR)/%.o : %.c
	@$(CC) $< $(CFLAGS) $(OUT) $@ $(INCLUDES)
	@#printf "\r%0*s" "$$(( $(words $(OBJS)) * $(PROGRESS_BAR_SIZE) / $(NB_SRCS) ))" ""
	@#c=4	\
	printf "%d" $$c



cl : clean
clean :
	@$(RM) $(OBJDIR)
	@echo "\033[0m[\033[1;31mCLEAN\033[0m] ->	\033[1;33mREMOVED		\033[0;33mRemoved '.o' files."



fc : fclean
fclean : clean
	@$(RM) $(NAME)
	@$(RM) $(NAME).dSYM
	@echo "\033[0m[\033[1;31mCLEAN\033[0m] ->	\033[1;33mREMOVED		\033[0;33mRemoved executable '$(NAME)'"




re : fclean all
