RM =			rm -f
CC =			clang
CFLAGS =		-Wall -Wextra -Werror
OFLAGS =		-O2
DBFLAGS =		-fsanitize=address -g3
NAME =			cub3D
NAME_DB =		cub3D_db
NAME_MMS =		cub3D_mms
NAME_MMS_DB =	cub3D_mms_db
NAME_LINUX =	cub3D_linux
NAME_L_DB =		cub3D_linux_db
EXECUTABLES =	$(NAME) $(NAME_DB) $(NAME_MMS) $(NAME_MMS_DB) $(NAME_LINUX) $(NAME_L_DB)
LIBFT_DIR =		libft
LIBFT =			$(LIBFT_DIR)/libft.a
PRINTF_DIR =	ft_printf
PRINTF =		$(PRINTF_DIR)/libftprintf.a
LFLAGS_LIBFT =	-L$(LIBFT_DIR) -lft
LFLAGS_PRINTF =	-L$(PRINTF_DIR) -lftprintf
LFLAGS_OPENGL = -L$(OPENGL_DIR) -lmlx -framework OpenGL -framework AppKit $(LFLAGS_PRINTF) $(LFLAGS_LIBFT)
LFLAGS_MMS =	-L$(MMS_DIR) -lmlx $(LFLAGS_PRINTF) $(LFLAGS_LIBFT)
LFLAGS_LINUX =	-L$(LINUX_DIR) -lmlx -lXext -lX11 -lm $(LFLAGS_PRINTF) $(LFLAGS_LIBFT)
LINUX_FLAG =	-D USE_LINUX
IFLAGS =		-Iinclude -I$(LIBFT_DIR) -I$(PRINTF_DIR)
IFLAGS_OPENGL =	-I$(OPENGL_DIR) $(IFLAGS)
IFLAGS_MMS =	-I$(MMS_DIR) $(IFLAGS)
IFLAGS_LINUX =	-I$(LINUX_DIR) $(IFLAGS)
MKDIR =			mkdir -p
OPENGL_DIR =	libopengl/
OPENGL_FILES =	libmlx.a mlx.h
OPENGL_PATHS =	$(addprefix $(OPENGL_DIR), $(OPENGL_FILES))
MMS_DIR =		libmms/
MMS_FILES =		libmlx.dylib mlx.h
MMS_PATHS =		$(addprefix $(MMS_DIR), $(MMS_FILES))
LINUX_DIR =		liblinux/
LINUX_FILES =	libmlx.a mlx.h
LINUX_PATHS =	$(addprefix $(LINUX_DIR), $(LINUX_FILES))
DIRS =			engine files hooks ia main minimap parsing utils
SRC_PATH =		src/
OBJ_O_PATH =	obj/
OBJ_M_PATH =	obj_mms/
OBJ_L_PATH =	obj_linux/
OBJ_PATHS =		$(OBJ_O_PATH) $(OBJ_M_PATH) $(OBJ_L_PATH)
SRC_DIRS =		$(addprefix $(SRC_PATH), $(DIRS))
OBJ_DIRS_O =	$(addprefix $(OBJ_O_PATH), $(DIRS))
OBJ_DIRS_MMS =	$(addprefix $(OBJ_M_PATH), $(DIRS))
OBJ_DIRS_L =	$(addprefix $(OBJ_L_PATH), $(DIRS))
SRC_ENGINE =	$(addprefix engine/, collision.c collision_correct.c collision_teleport.c \
				ray_march.c render.c render_lives.c render_sprites.c render_walls.c)
SRC_FILES =		$(addprefix files/, file_errors.c file_utils.c generate_bmp.c )
SRC_HOOKS =		$(addprefix hooks/, hooks_end.c hooks_render_enemy1.c \
				hooks_render_enemy2.c hooks_render_movements.c hooks_render_utils.c \
				hooks_start.c )
SRC_IA =		$(addprefix ia/, ia.c ia_add_neighbors.c ia_algo_utils.c ia_path_memory.c ia_path_utils.c )
SRC_MINIMAP =	$(addprefix minimap/, minimap.c minimap_enemies.c minimap_pacu.c minimap_peas.c minimap_walls.c )
SRC_PARSING =	$(addprefix parsing/, file_to_list.c get_next_line.c get_next_line_utils.c \
				image_create.c image_errors.c image_load.c image_utils.c map_check.c \
				map_errors.c map_new1.c map_new2.c map_objects_init.c map_objects_init_utils.c \
				map_objects_init_utils2.c pack_init1.c pack_init2.c params_parse.c params_parse2.c \
				params_parse3.c params_parse_funs.c params_parse_funs2.c params_parse_utils.c \
				params_parse_utils2.c params_parse_utils3.c params_parse_utils4.c parse.c \
				split_utils.c textual_check.c)
SRC_UTILS =		$(addprefix utils/, basic_utils.c free_others.c gen_draw_utils.c \
				generic_errors.c image_pix_utils1.c image_pix_utils2.c image_render_utils.c \
				image_render_utils2.c image_utils.c list_utils.c map_coord_utils.c \
				map_coord_utils2.c math_ipt2d_utils.c math_norm_utils.c math_pt2d_utils.c \
				math_pt_ipt_utils.c rotation_utils.c)
OPENGL_SRCS =	hooks/hooks_render.c hooks/hooks_transitions.c utils/free_pack.c \
				utils/loop_utils.c main/main.c
MMS_SRCS =		hooks/mms_hooks_render.c hooks/mms_hooks_transitions.c utils/mms_free_pack.c \
				utils/loop_utils.c main/main.c
LINUX_SRCS =	hooks/linux_hooks_render.c hooks/linux_hooks_transitions.c utils/linux_free_pack.c \
				utils/linux_loop_utils.c main/linux_main.c
SRCS_NAMES =	$(SRC_ENGINE) $(SRC_FILES) $(SRC_HOOKS) $(SRC_IA) $(SRC_MINIMAP) $(SRC_PARSING) $(SRC_UTILS)
SRCS_NAMES_O =	$(SRCS_NAMES) $(OPENGL_SRCS)
SRCS_NAMES_M =	$(SRCS_NAMES) $(MMS_SRCS)
SRCS_NAMES_L =	$(SRCS_NAMES) $(LINUX_SRCS)
SRCS =			$(addprefix $(SRC_PATH), $(SRC_NAMES_O))
SRCS_MMS =		$(addprefix $(SRC_PATH), $(SRC_NAMES_M))
SRCS_LINUX =	$(addprefix $(SRC_PATH), $(SRC_NAMES_L))
OBJS_NAMES_O =	$(SRCS_NAMES_O:.c=.o)
OBJS_NAMES_M =	$(SRCS_NAMES_M:.c=.o)
OBJS_NAMES_L =	$(SRCS_NAMES_L:.c=.o)
OBJS =			$(addprefix $(OBJ_O_PATH), $(OBJS_NAMES_O))
OBJS_MMS =		$(addprefix $(OBJ_M_PATH), $(OBJS_NAMES_M))
OBJS_LINUX =	$(addprefix $(OBJ_L_PATH), $(OBJS_NAMES_L))
HEADERS_PATH=	include/
HEADERS_NAMES =	cub3d.h cub3d_files.h cub3d_memory.h cub3d_utils.h engine.h get_next_line.h hooks.h ia.h \
				parse_types.h map_new.h map_objects_init.h minimap.h params_parse_funs.h \
				params_parse_utils.h parse.h symbols_const.h types.h values_const.h
HEADERS =		$(addprefix $(HEADERS_PATH), $(HEADERS_NAMES) keycodes.h)
HEADERS_LINUX =	$(addprefix $(HEADERS_PATH), $(HEADERS_NAMES) keycodes_linux.h)

all:			$(OPENGL_PATHS) switch_opengl $(NAME)
all_mms:		$(MMS_PATHS) switch_mms $(NAME_MMS)
all_linux:		$(LINUX_PATHS) switch_linux $(NAME_LINUX)

db:				$(OPENGL_PATHS) switch_opengl $(NAME_DB)
db_mms:			$(MMS_PATHS) switch_mms $(NAME_MMS_DB)
db_linux:		$(LINUX_PATHS) switch_linux $(NAME_L_DB)

switch_opengl:
	cp $(OPENGL_PATHS) .

$(OPENGL_PATHS):
	make -C libopengl

switch_mms:
	cp $(MMS_PATHS) .

$(MMS_PATHS):
	make -C libmms

switch_linux:
	cp $(LINUX_PATHS) .

$(LINUX_PATHS):
	make -C liblinux

$(NAME):		$(OBJ_DIRS_O) $(OBJS) $(LIBFT) $(PRINTF) $(HEADERS) $(OPENGL_PATHS)
	$(CC) -o $@ $(OFLAGS) $(OBJS) $(IFLAGS_OPENGL) $(LFLAGS_OPENGL)

$(NAME_DB):		$(OBJ_DIRS_O) $(OBJS) $(LIBFT) $(PRINTF) $(HEADERS) $(OPENGL_PATHS)
	$(CC) -o $@ $(DBFLAGS) $(OBJS) $(IFLAGS_OPENGL) $(LFLAGS_OPENGL)

$(NAME_MMS):	$(OBJ_DIRS_MMS) $(OBJS_MMS) $(LIBFT) $(PRINTF) $(HEADERS_MMS) $(MMS_PATHS)
	$(CC) -o $@ $(OFLAGS) $(OBJS_MMS) $(IFLAGS_MMS) $(LFLAGS_MMS)

$(NAME_MMS_DB):	$(OBJ_DIRS_MMS) $(OBJS_MMS) $(LIBFT) $(PRINTF) $(HEADERS_MMS) $(MMS_PATHS)
	$(CC) -o $@ $(DBFLAGS) $(OBJS_MMS) $(IFLAGS_MMS) $(LFLAGS_MMS)

$(NAME_LINUX):	$(OBJ_DIRS_L) $(OBJS_LINUX) $(HEADERS_LINUX) $(LINUX_PATHS)
	@make -C libft fclean
	@make -C libft bonus
	@make -C ft_printf re
	$(CC) -o $@ $(OBJS_LINUX) $(IFLAGS_LINUX) $(LFLAGS_LINUX) $(LINUX_FLAG)
	@make -C libft fclean
	@make -C ft_printf fclean

$(NAME_L_DB):	$(OBJ_DIRS_L) $(OBJS_LINUX) $(HEADERS_LINUX) $(LINUX_PATHS)
	@make -C libft fclean
	@make -C libft bonus
	@make -C ft_printf re
	$(CC) -o $@ $(DBFLAGS) $(OBJS_LINUX) $(IFLAGS_LINUX) $(LFLAGS_LINUX) $(LINUX_FLAG)
	@make -C libft fclean
	@make -C ft_printf fclean

$(OBJ_DIRS_O):
	mkdir -p $(OBJ_O_PATH)
	mkdir -p $@

$(OBJ_DIRS_MMS):
	mkdir -p $(OBJ_M_PATH)
	mkdir -p $@

$(OBJ_DIRS_L):
	mkdir -p $(OBJ_L_PATH)
	mkdir -p $@

$(addprefix $(OBJ_O_PATH), %.o):	src/%.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS) $(IFLAGS_OPENGL)

$(addprefix $(OBJ_M_PATH), %.o):	src/%.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS) $(IFLAGS_MMS)

$(addprefix $(OBJ_L_PATH), %.o):	src/%.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS) $(IFLAGS_LINUX) $(LINUX_FLAG)

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

$(PRINTF):
	make -C $(PRINTF_DIR)

bonus:	all

clean:
	rm -rf $(OBJ_PATHS)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	make -C $(OPENGL_DIR) clean
	make -C $(MMS_DIR) clean
	make -C $(LINUX_DIR) clean

fclean:	clean
	$(RM) $(EXECUTABLES)
	$(RM) $(OPENGL_DIR)libmlx.a
	$(RM) $(MMS_DIR)libmlx.dylib
	$(RM) $(LINUX_DIR)libmlx.a
	$(RM) $(LINUX_DIR)libmlx_Linux.a
	$(RM) libmlx.a libmlx.dylib mlx.h
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	$(RM) result.bmp

re:	fclean all

.PHONY:	clean fclean re bonus \
		all all_mms all_linux \
		db db_mms db_linux \
		switch_opengl switch_mms switch_linux
