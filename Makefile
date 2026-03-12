NAME		=	sudoku

CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	src/main.c src/sudoku.c src/check.c

WASM_SRCS	=	src/sudoku.c src/check.c src/wasm.c

all:			$(NAME)

$(NAME):
				gcc	$(CFLAGS) $(SRCS) -o $(NAME)

wasm:
				mkdir -p module
				emcc $(WASM_SRCS) \
					-o module/sudoku.js \
					-s MODULARIZE=1 \
					-s EXPORT_NAME='SudokuModule' \
					-s EXPORTED_FUNCTIONS='["_solve"]' \
					-s EXPORTED_RUNTIME_METHODS='["ccall","cwrap","UTF8ToString","stringToUTF8","lengthBytesUTF8"]' \
					-s EXPORT_ES6=1 \
					--emit-tsd sudoku.d.ts \
					-O2

fclean:
				rm -rf $(NAME)

wclean:
				rm -rf module/sudoku.*

re:				fclean all

.PHONY:			all fclean wclean re wasm
