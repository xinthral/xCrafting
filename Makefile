# 
CC := g++
CFLAGS := -g -std=gnu++2a -l sqlite3

CORE := core
CORESRC := $(patsubst $(CORE)/%.cpp, $(CORE)/%.o, $(wildcard $(CORE)/*.cpp))

TEST := test
TESTSRC := $(patsubst $(TEST)/%.cpp, $(TEST)/%.o, $(wildcard $(TEST)/*.cpp))

MOD1 := cli
MOD1SRC := $(patsubst $(MOD1)/%.cpp, $(MOD1)/%.o, $(wildcard $(MOD1)/*.cpp))

MOD2 := botw
MOD2SRC := $(patsubst $(MOD2)/%.cpp, $(MOD2)/%.o, $(wildcard $(MOD2)/*.cpp))

MOD3 := mine
MOD3SRC := $(patsubst $(MOD3)/%.cpp, $(MOD3)/%.o, $(wildcard $(MOD3)/*.cpp))

MODS := $(CORE) $(TEST) $(MOD1) $(MOD2) $(MOD3)
EXEC := bin/cookbook
SEPR := /

# Windows Variants
ifeq ($(OS), Windows_NT)
CC := c++
RM := del
SEPR := \\
EXEC := bin\\cookbook
endif

# 
all:
	@echo make [option]
	@echo ""
	@echo  [core] - main cookbook
	@echo  [test] - test core functionality
	@echo  [cli]  - Command Line Interface
	@echo  [botw] - Breath of the Wild
	@echo  [cleanbin]  - cleans up binaries
	@echo  [cleancore] - cleans up the core library 
	@echo  [cleanbotw] - cleans up the botw library 
	@echo ""

build: $(CORESRC) $(TESTSRC) $(MOD1SRC) $(MOD2SRC) $(MOD3SRC)

$(CORE): $(CORESRC)

$(TEST): $(TESTSRC) $(CORESRC)
	$(CC) $(CFLAGS) $^ -o $(EXEC)_$@.exe

$(MOD1): $(MOD1SRC) $(CORESRC)
	$(CC) $(CFLAGS) $^ -o $(EXEC)_core.exe

$(MOD2): $(MOD2SRC) $(CORESRC)
	$(CC) $(CFLAGS) $^ -o $(EXEC)_$@.exe

$(MOD3): $(MOD3SRC) $(CORESRC)
	$(CC) $(CFLAGS) $^ -o $(EXEC)_$@.exe

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

#
clean: 
	$(RM) $(foreach d, $(MODS), $d$(SEPR)*.o)

cleanbin:
	$(RM) $(EXEC)*.exe

cleancore:
	$(RM) core$(SEPR)*.o

cleanbotw:
	$(RM) botw$(SEPR)*.o

cleanmine:
	$(RM) mine$(SEPR)*.o

cleanall: 
	$(MAKE) cleanbin
	$(MAKE) clean

.PHONEY: clean cleanbin cleancore cleanbotw cleanmine cleanall botw mine 