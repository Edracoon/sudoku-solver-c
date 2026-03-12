NAME		=	sudoku

CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	main.c sudoku.c check.c

WASM_SRCS	=	sudoku.c check.c wasm.c

all:			$(NAME)

$(NAME):
				gcc	$(CFLAGS) $(SRCS) -o $(NAME)

wasm:
				mkdir -p module/build
				emcc $(WASM_SRCS) \
					-o module/build/sudoku.js \
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
				rm -rf module/build/

re:				fclean all

.PHONY:			all fclean wclean re wasm
