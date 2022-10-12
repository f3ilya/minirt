# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkrajcov <vkrajcov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 13:36:25 by cmarion           #+#    #+#              #
#    Updated: 2022/08/30 13:42:44 by vkrajcov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 			miniRT
NAME_BONUS		= 			miniRT_bonus

INC				= 			-I $(LIBFT_PATH)\
							-I $(MINILIBX_PATH)\
							-I ./includes

LIBFT_PATH		=			./libft/
MINILIBX_PATH	=			./MinilibX/
SRCS_PATH		=			./srcs/
OBJ_PATH		=			./obj/
OBJ_BONUS_PATH	=			./obj_bonus/

UTILS_PATH		=			utils/
DISPLAY_PATH	=			display/
PARSER_PATH		=			parser/
OBJECTS_PATH	=			objects/

SRCS_UTILS		=			fts_fill.c \
							fts_frees.c \
							fts_vect_op1.c \
							fts_vect_op2.c \
							fts_lst.c \
							matrix.c \
							cylinder_utils.c \
							translation_rotation.c
SRCS_DISPLAY	=			display.c \
							img_actualisation.c 
SRCS_PARSER		=			checker.c \
							get_next_line.c \
							parser.c
SRCS_OBJECTS	=			init_params.c \
							sphere.c \
							plane.c \
							cylinder.c \
							ambient.c \
							camera.c \
							light.c \
							circle.c
SRCS			= 			main.c \
							$(addprefix $(UTILS_PATH), $(SRCS_UTILS)) \
							$(addprefix $(DISPLAY_PATH), $(SRCS_DISPLAY)) \
							$(addprefix $(PARSER_PATH), $(SRCS_PARSER)) \
							$(addprefix $(OBJECTS_PATH), $(SRCS_OBJECTS))

SRCS_BONUS		=			main.c \
							$(addprefix $(UTILS_PATH), $(SRCS_UTILS)) \
							$(addprefix $(PARSER_PATH), checker.c get_next_line.c) \
							$(addprefix $(OBJECTS_PATH), ambient.c camera.c cylinder.c init_params.c plane.c sphere.c circle.c) \
							$(addprefix $(DISPLAY_PATH), img_actualisation.c) \
							bonus/objects/light_bonus.c \
							bonus/display_bonus.c \
							bonus/phong_bonus.c \
							bonus/parser_bonus.c \
							bonus/objects/cone_bonus.c \
							bonus/utils/cone_utils_bonus.c
										
OBJ				=			$(addprefix $(OBJ_PATH),$(SRCS:.c=.o))
DEPS			=			$(OBJ:.o=.d)
OBJ_BONUS		=			$(addprefix $(OBJ_BONUS_PATH),$(SRCS_BONUS:.c=_bonus.o))
DEPS_BONUS		=			$(OBJ_BONUS:.o=.d)

LIBFT			=			$(addprefix $(LIBFT_PATH),libft.a)
MINILIBX		=			$(addprefix $(MINILIBX_PATH),libmlx_Linux.a libmlx.a)

LIBS			=			-Llibft -lft -lmlx -L./MinilibX -framework OpenGL -framework AppKit

CC 				=			gcc
CFLAGS			=			-Wall -Wextra -Werror  

all:						$(NAME)


$(OBJ_PATH)%.o:				$(SRCS_PATH)%.c
							@mkdir -p $(dir $@)
							$(CC) $(INC) -MMD $(CFLAGS) -c $< -o $@

$(OBJ_BONUS_PATH)%_bonus.o:	$(SRCS_PATH)%.c
							@mkdir -p $(dir $@)
							$(CC) $(INC) -MMD $(CFLAGS) -c $< -o $@			

$(NAME):					$(LIBFT) $(MINILIBX) $(OBJ) 
							$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS)

$(NAME_BONUS):				$(LIBFT) $(MINILIBX) $(OBJ_BONUS)
							$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS) $(LIBS)

$(LIBFT):			
							@echo "Compiling libft..."
							@$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX):			
							@echo "Compiling minilibx..."
							@$(MAKE) -C $(MINILIBX_PATH)

bonus:						$(NAME_BONUS)

clean:				
							rm -rf $(OBJ_PATH)
							rm -rf $(OBJ_BONUS_PATH)
							rm -rf $(addprefix $(MINILIBX_PATH),obj/)
							make fclean -C $(LIBFT_PATH)

fclean:						clean
							rm -f $(LIBFT) $(NAME) $(NAME_BONUS)

re:							fclean
							$(MAKE) all
					
re_bonus:					fclean
							$(MAKE) bonus

-include					$(DEPS)
-include					$(DEPS_BONUS)

.PHONY:						all bonus re_bonus clean fclean re 
