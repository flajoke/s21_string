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

TARGET = 

CFLAGS = -Wall -g
LIB = 

SRC = 
OBJ = $(SRC:%.c=%.o)

CC = gcc
RM = rm
OPEN = 

TEST =
TEST_SRC =
TEST_OJB = $(TEST_SRC:%.c=%.o)

# --------{COLORED OUTPUT}------------------------------------

define printout
	@echo 
	@echo "${1}$(2)${RESET}"
	@echo 
endef

# ------------------------------------------------------------

%.o: %.c
	@printf "${YELLOW} • "
	$(CC) -c $(CFLAGS) $< -o $@
	@printf "${RESET}"

all: $(TARGET)

$(TARGET): $(OBJ)
	$(call printout, $(GREEN), "$(TARGET):")
	$(CC) -o $(TARGET) $(CFLAGS) $(OBJ) $(LIB)
	$(call printout, $(GREEN), "Done!")

clean:
	$(call printout, $(GREEN), "Cleaning up:")
	- $(RM) -f $(TARGET)
	- $(RM) -rf ./report/
	- $(RM) -f *.info
	- $(RM) -f *.gcov 
	- $(RM) -f *.gcno 
	- $(RM) -f *.gcda 
	- $(RM) -f *.out
	- $(RM) -f *.o
	- $(RM) -f *.a
	$(call printout, $(GREEN), "Done!")

rebuild: clean all

test: $(OBJ)

gcov_report:

.PHONY: setup all clean rebuild test gcov_report
