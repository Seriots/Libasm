NAME		=	libasm.a

EXECUTABLE  = 	test

define SRCS :=
	ft_strlen.s
	ft_strcpy.s
	ft_strcmp.s
	ft_write.s
	ft_read.s
	ft_strdup.s
	ft_atoi_base.s
	ft_list_push_front.s
	ft_list_size.s
	ft_list_sort.s
	ft_list_remove_if.s

endef
SRCS := $(strip $(SRCS))

OBJS_DIR	=	objs
SRCS_DIR	=	srcs
LIB_DIR		=	lib
OBJS		= 	$(addprefix $(OBJS_DIR)/,$(SRCS:.s=.o))
DEPS		=	$(OBJS:.o=.d)

AS			= 	nasm
LD			=	ld
ASFLAGS		= 	-f elf64 -g
LDFLAGS		=

LIB_PATH	=	./lib
LIB_NAME	=	asm

CC			=	clang
CFLAGS		=	-Wall -Werror -Wextra -g3

SRC_MAIN	=	main.c
OBJ_MAIN	=	$(addprefix $(OBJS_DIR)/,$(SRC_MAIN:.c=.o))
DEPS_MAIN	=	$(OBJ_MAIN:.o=.d)


# Color
# -------------------------------------------------------------------------
_GREY		= \033[30m
_RED		= \033[31m
_GREEN		= \033[32m
_YELLOW		= \033[33m
_BLUE		= \033[34m
_PURPLE		= \033[35m
_CYAN		= \033[36m
_WHITE		= \033[37m
_NO_COLOR	= \033[0m
# -------------------------------------------------------------------------

.PHONY: all clean fclean re

all: $(LIB_DIR)/$(NAME)

libasm: $(LIB_DIR)/$(NAME)

bonus: all

$(LIB_DIR)/$(NAME): $(OBJS)
	@if [ ! -d $(LIB_DIR) ]; then \
		mkdir -p  $(LIB_DIR); \
		echo "\n$(_BLUE)$(LIB_DIR): Create$(_NO_COLOR)"; \
	fi
	ar rcs $@ $^

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.s
	@if [ ! -d $(dir $@) ]; then \
		mkdir -p $(dir $@); \
		echo "\n$(_BLUE)$(dir $@): Create$(_NO_COLOR)"; \
	fi
	$(AS) $(ASFLAGS) $< -o $@ -MD $(@:.o=.d)

$(OBJS_DIR)/%.o: %.c
	@if [ ! -d $(dir $@) ]; then \
		mkdir -p $(dir $@); \
		echo "\n$(_BLUE)$(dir $@): Create$(_NO_COLOR)"; \
	fi
	$(CC) $(CFLAGS) -MMD -o $@ -c $<

$(EXECUTABLE): $(LIB_DIR)/$(NAME) $(OBJ_MAIN)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIB_PATH) -l$(LIB_NAME)

clean:
	rm -Rf $(OBJS_DIR) 2> /dev/null || true
	rm -Rf $(LIB_DIR) 2> /dev/null || true
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)
	rm -f $(EXECUTABLE)

re: fclean all

-include $(DEPS)
-include $(DEPS_MAIN)

