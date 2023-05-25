################################################################################
# DIRECTORIES ##################################################################
################################################################################

# Includes
INC_DIR = inc/

# Objects and dependencies
OBJ_DIR = obj/

# Sources
SRC_DIR = src/

# Target directory
TARGET_DIR = ./

################################################################################
# BASIC ########################################################################
################################################################################

# Target name
NAME = $(TARGET_DIR)libft.a

# Sources
SRCS = \
ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_strlen.c \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memmove.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_memchr.c \
ft_memcmp.c \
ft_strnstr.c \
ft_atoi.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c \
ft_mempos.c \
get_next_line.c \
gnl_outbuf.c \
gnl_readbuf.c \
ft_max.c \
ft_abs.c \
ft_tostr.c \
fmtblock.c \
ft_digits.c \
fmt.c \
fmt_hex.c \
fmt_int.c \
fmt_parse.c \
fmt_ptr.c \
fmt_str.c \
fmt_util.c \
ft_printf.c

# Compiler
CC = cc

# Optimization flags
OPT =

# Extra flags
EXTRA = -Wall -Werror -Wextra

# Depflags
DEP = -MP -MMD

################################################################################
# CONFIG #######################################################################
################################################################################


vpath %.c src/
.PHONY: all clean fclean re debug d
override FLAGS += $(EXTRA) $(foreach DIR,$(INC_DIR),-I$(DIR)) $(OPT) $(DEP)
OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)
DEPS = $(SRCS:%.c=$(OBJ_DIR)%.d)

################################################################################
# RULES ########################################################################
################################################################################

# Default rule
all: $(NAME)

# Objects
$(OBJS): $(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	$(CC) $(FLAGS) -c -o $@ $<

# Target
$(NAME): $(OBJS) | $(TARGET_DIR)
	ar -rcs $@ $?

# Cleanup
clean:
	rm -rf $(OBJS) $(DEPS)

fclean: clean
	rm -rf $(NAME)

# Debug
debug:
	make fclean
	make all FLAGS="-g -fsanitize=address"

# Aliases
re: fclean all
d: debug

# Dir creation
$(OBJ_DIR) $(TARGET_DIR):
	@mkdir $@

-include $(DEPS)