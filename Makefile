# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by                   #+#    #+#              #
#    Updated: 2024/04/29 22:13:17 by acuva-nu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS    = main.c keys.c parse_map.c utils.c check_walls.c    \
		  parse_textures.c textures.c parse_rgb.c utils2.c utils.c raycast.c \
		  player_start.c cameras.c render.c utils_lib.c utils2_lib.c utils3lib.c \
			 gnl.c gnl_util.c
			
#Add any missing folder containing a .c to the vpath
vpath %.c src/parse  src/utils src/gnl src/

OBJ_DIR = ./obj
OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
INCS 	   = ../cub3d.h
NAME       = cub3D
CC         = cc
CFLAGS     = -O3 -g -Wall -Wextra -Werror #-fsanitize=address
LDFLAGS	   = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz 
RM         = rm -rf

all: ${NAME}

$(OBJ_DIR)/%.o: %.c 
	@mkdir -p ${OBJ_DIR}
	$(CC) $(CFLAGS) -c $< -o $@
	
${NAME}: ${OBJS} 
	make -s -C minilibx-linux
	${CC} ${CFLAGS}  $^ -o $@  -I ${INCS} ${LDFLAGS}

clean:
	${RM} ${OBJ_DIR} 
	make clean -s -C minilibx-linux

fclean: clean
	${RM} ${NAME} 

re: fclean all

# norm:
# 	norminette -R CheckForbiddenSourceHeader ${SRCS}
# 	norminette -R CheckDefine ${INCS}

.PHONY: all re clean fclean 
