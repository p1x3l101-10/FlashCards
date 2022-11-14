NAME           = FlashCards
PROG_EXTENSION = cpp

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

CC     = g++
CFLAGS = -I$(INC_DIR)
LIBS   = -lm

_DEPS = argResolver.h   \
				operators.h     \
				loopVariables.h

_OBJ  = main.o        \
				argResolver.o \
				add.o         \
				subt.o        \
				multi.o       \
				divi.o

DEPS = $(patsubst %,$(INC_DIR)/%,$(_DEPS))
OBJ  = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(PROG_EXTENSION) $(DEPS)
	@ mkdir -p $(OBJ_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BIN_DIR)/$(NAME): $(OBJ)
	@ mkdir $(BIN_DIR)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	cp $(BIN_DIR)/* ./

clean:
	@ rm -r $(OBJ_DIR)

purge: clean
	rm -f $(BIN_DIR)/$(NAME)
	rm -f $(NAME)
	rmdir $(BIN_DIR)

fresh: purge
	$(MAKE)


install:
	@ mkdir -p $(DESTBIN_DIR)
	@ mkdir -p $(DESTLIB_DIR)
	install -d $(DESTLIB_DIR)
	install -m 755 $(LIB_DIR)/* $(DESTLIB_DIR)
	install -d $(DESTBIN_DIR)
	install -m 755 $(BIN_DIR)/* $(DESTBIN_DIR)

symadd:
	ln -s $(DESTLIB_DIR)/* $(SYM_DESTLIB_DIR)
	ln -s $(DESTBIN_DIR)/* $(SYM_DESTBIN_DIR)

symdel:
	for symlink in $(DESTBIN_DIR)/*; do \
		rm -f $(SYM_DESTBIN_DIR)/$$(echo $$symlink | cut -d'/' -f7-;); \
	done; \
	for symlink in $(DESTLIB_DIR)/*; do \
		rm -f $(SYM_DESTLIB_DIR)/$$(echo $$symlink | cut -d'/' -f7-;); \
	done; \

uninstall: symdel
	rm -rf $(DESTDIR)

.PHONY: clean purge fresh install uninstall symadd symdel
