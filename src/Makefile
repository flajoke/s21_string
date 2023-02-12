# REQUIRES: 
#  - check library (c unit tests)
#  - docker
#  - gcov + lcov
#  - gcc

RED    = \033[0;31m
GREEN  = \033[0;32m
YELLOW = \033[0;33m
CYAN   = \033[0;36m
RESET  = \033[0m

TARGET = s21_string
TARGET_LIB = s21_string.a

CFLAGS = -Wall -g

LIB_TOOL = ar
LIB_FLAGS = -rcs

SRC = strerror.c s21_strcpy.c s21_memchr.c s21_strncpy.c
OBJ = $(SRC:%.c=%.o)

CC = gcc
RM = rm

SYSTEM=$(shell uname -s)

ifeq ($(SYSTEM),Linux)
	OPEN_CMD=xdg-open
	BREW=.
endif
ifeq ($(SYSTEM),Darwin)
	OPEN_CMD=open
	BREW:=$(HOME)/goinfre/homebrew
endif

PATH:=$(PATH):$(BREW)/bin

TEST = check_test
TEST_SRC = tests.c
TEST_OJB = $(TEST_SRC:%.c=%.o)
TEST_LIBS =-lcheck -lm -lpthread -lrt -lsubunit 

# --------{COLORED OUTPUT}------------------------------------

define printout
	@echo 
	@echo "${1}$(2)${3}"
	@echo 
endef

# ------------------------------------------------------------

%.o: %.c
	@printf "${YELLOW} • "
	$(CC) -c $(CFLAGS) $< -o $@
	@printf "${RESET}"

all: $(TARGET_LIB)

$(TARGET_LIB): $(OBJ)
	$(call printout, $(GREEN), "$(TARGET):", $(RESET))
	$(LIB_TOOL) $(LIB_FLAGS) $@ $^ 
	$(call printout, $(GREEN), "$(TARGET):", $(CYAN))
	@$(LIB_TOOL) -t $(TARGET_LIB) | sed -e 's/^/ • /'
	$(call printout, $(GREEN), "Done!", $(RESET))

clean:
	$(call printout, $(GREEN), "Cleaning up:", $(RED))
	- $(RM) -f $(TARGET) $(TEST)
	- $(RM) -rf ./report/
	- $(RM) -rf *.dSYM
	- $(RM) -f *.info
	- $(RM) -f *.gcov 
	- $(RM) -f *.gcno 
	- $(RM) -f *.gcda 
	- $(RM) -f *.out
	- $(RM) -f *.o
	- $(RM) -f *.a
	$(call printout, $(GREEN), "Done!", $(RESET))

rebuild: clean all

test: $(TARGET_LIB)
	$(call printout, $(GREEN), "Compiling unit tests:", $(RESET))
	$(CC) -o $(TEST) $(CFLAGS) $(TEST_SRC) $^ $(TEST_LIBS)
	$(call printout, $(GREEN), "Done!", $(RESET))
	-@./$(TEST)

gcov_report: CFLAGS:=--coverage $(CFLAGS)
gcov_report: clean lcov test
	$(call printout, $(GREEN), "Generating .info coverage:", $(CYAN))
	#-@$(RM) -f $(TEST_SRC:.c=.gcda)
	@$(shell PATH=$(PATH) which lcov) -t "$(TARGET)" -o $(TARGET).info -c -d .
	$(call printout, $(GREEN), "Done!", $(RED))
	$(call printout, $(GREEN), "Generating html report:", $(CYAN))
	-mkdir report
	@$(shell PATH=$(PATH) which genhtml)  -o report $(TARGET).info
	#$(OPEN_CMD) ./report/index.html
	$(call printout, $(GREEN), "Done!", $(RESET))

lcov:
ifeq ("", "$(shell PATH=$(PATH) which lcov)")
	$(error Need to install lcov)
endif

.PHONY: setup all clean rebuild test gcov_report lcov