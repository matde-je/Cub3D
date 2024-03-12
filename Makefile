# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matilde <matilde@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 12:35:24 by acuva-nu          #+#    #+#              #
#    Updated: 2024/03/07 15:09:49 by matilde          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = main.c keys.c parse_map.c utils.c check_walls.c window_img.c get_next_line.c \
			get_next_line_utils.c parse_textures.c parse_rgb.c structs.c \
			cameras.c render.c
			

#Add any missing folder containing a .c to the vpath
vpath %.c gnl/ src/

OBJ_DIR = ./obj
OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
INCS 	   = inc/
NAME       = cub3d
CC         = cc
CFLAGS     = -g -Wall -Wextra -Werror #-fsanitize=address
LDFLAGS	   = -L./libft -lft
RM         = rm -rf

all: ${NAME}

$(OBJ_DIR)/%.o: %.c 
	@mkdir -p ${OBJ_DIR}
	$(CC) $(CFLAGS) -c $< -o $@
	
${NAME}: ${OBJS} 
	make -s -C libft
	${CC} ${CFLAGS}  $^ -Lminilibx-linux -I/minilibx-linux/mlx.h -L/usr/lib -lmlx -lXext -lX11 -lm -lz -o $@  -I ${INCS} ${LDFLAGS}

clean:
	${RM} ${OBJ_DIR} 
	make clean -s -C libft

fclean: clean
	${RM} ${NAME} 
	make fclean -s -C libft

re: fclean all

# norm:
# 	norminette -R CheckForbiddenSourceHeader ${SRCS}
# 	norminette -R CheckDefine ${INCS}

.PHONY: all re clean fclean 
