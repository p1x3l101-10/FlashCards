NAME = FlashCards

PREFIX         ?= /usr/local
DESTDIR         = $(PREFIX)/pkg/$(NAME)
DESTBIN_DIR     = $(DESTDIR)/bin
DESTLIB_DIR     = $(DESTDIR)/lib
SYM_DESTBIN_DIR = $(PREFIX)/bin
SYM_DESTLIB_DIR = $(PREFIX)/lib

SRC_DIR = src
INC_DIR = inc
LIB_DIR = lib
OBJ_DIR = $(SRC_DIR)/obj
BIN_DIR = bin

CC     = gcc
CFLAGS = -I$(INC_DIR)
LIBS   = -lm

_DEPS = loopvars.h  \
				operators.h \

_OBJ  = main.o        \
				argResolver.o \
				add.o         \
				subt.o        \
				multi.o       \
				divi.o

DEPS = $(patsubst %,$(INC_DIR)/%,$(_DEPS))
OBJ  = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	@ mkdir -p $(OBJ_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BIN_DIR)/$(NAME): $(OBJ)
	@ mkdir -p $(BIN_DIR)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	cp $(BIN_DIR)/* ./

clean:
	@ rm -f $(OBJ_DIR)/*.o

install:
	@ mkdir -p $(DESTBIN_DIR)
	#mkdir -p $(DESTLIB_DIR)
	#install -d $(DESTLIB_DIR)
	#install -m 755 $(LIB_DIR)/* $(DESTLIB_DIR)
	install -d $(DESTBIN_DIR)
	install -m 755 $(BIN_DIR)/* $(DESTBIN_DIR)

symadd:
	ln -s $(DESTLIB_DIR)/* $(SYM_DESTLIB_DIR)
	ln -s $(DESTBIN_DIR)/* $(SYM_DESTBIN_DIR)

uninstall:
	rm -rf $(DESTDIR)

.PHONY: clean install uninstall symadd