# 
CC := g++
CFLAGS := -g -std=gnu++17
MOD1 := core
MOD1SRC := $(patsubst $(MOD1)/%.cpp, $(MOD1)/%.o, $(wildcard $(MOD1)/*.cpp))
MOD2 := botw
MOD2SRC := $(patsubst $(MOD2)/%.cpp, $(MOD2)/%.o, $(wildcard $(MOD2)/*.cpp))
MOD2SRC += $(MOD1SRC) 
# MOD2		:= botw
# MOD1SRC := $(patsubst %.cpp, %.o, $(wildcard ./$(MOD2)/*.cpp))
MODS := $(MOD1) $(MOD2)
EXEC := ./bin/cookbook
SEPR := /

# Windows Variants
ifeq ($(OS), Windows_NT)
CC := c++
RM := del
SEPR := \\
EXEC := .\\bin\\cookbook
endif

# 
all:
	@echo make [option]
	@echo ""
	@echo  [core] - main cookbook
	@echo  [botw] - Breath of the Wild
	@echo  [cleanbin] - cleans up binaries
	@echo  [cleancore] - cleans up the core library 
	@echo  [cleanbotw] - cleans up the botw library 
	@echo ""

$(MOD1): $(MOD1SRC)
	$(CC) $(CFLAGS) -c $(MOD1)$(SEPR)cli.c++ -o $(MOD1)$(SEPR)cli.o
	$(CC) $(CFLAGS) $(MOD1)$(SEPR)cli.o $^ -o $(EXEC).exe

$(MOD2): $(MOD2SRC)
	$(CC) $(CFLAGS) -c $(MOD2)$(SEPR)cli.c++ -o $(MOD2)$(SEPR)cli.o
	$(CC) $(CFLAGS) $(MOD2)$(SEPR)cli.o $^ -o $(EXEC).exe

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
#
clean: 
	$(foreach d, $(MODS), $(RM) $d$(SEPR)*.o &&) true 2>&1 > /dev/null

cleanbin:
	$(RM) $(EXEC).exe

cleancore:
	$(RM) core$(SEPR)*.o

cleanbotw:
	$(RM) botw$(SEPR)*.o

cleanall: 
	$(MAKE) clean
	$(MAKE) cleanbin

.PHONEY: core botw 