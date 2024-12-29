# Global Variables
CC := g++
CFLAGS := -g -std=gnu++2a
EXEC := bin/cookbook
NULL := /dev/null
SEPR := /*
DOXYGEN := doxygen

# Windows Variants
ifeq ($(OS), Windows_NT)
CC := c++
RM := del
EXEC := bin\\cookbook
NULL := NUL
SEPR := \\*
DOXYGEN := doxygen.exe
endif

# Source File Peperation
DOCS := docs
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

# Make Directives
all:
	@echo make [option]
	@echo ""
	@echo  [botw] - Breath of the Wild
	@echo  [core] - main cookbook
	@echo  [cli]  - Command Line Interface
	@echo  [docs] - HTML Documentation
	@echo  [mine] - Minecraft
	@echo  [test] - test core functionality
	@echo  [cleanbin]  - cleans up binaries
	@echo  [cleancore] - cleans up the core library 
	@echo  [cleanbotw] - cleans up the botw library 
	@echo  [cleanmine] - cleans up the mine library 
	@echo  [cleantest] - cleans up the test library 
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

$(DOCS):
	$(MAKE) -B $@

doc: docs/conf.dox
	$(DOXYGEN) $<

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean Directives
clean: 
	@echo Cleaning up all Object Files
	$(RM) $(foreach d, $(MODS), $d$(SEPR).o) 2>$(NULL)

cleanbin:
	@echo Cleaning Binary Files
	$(RM) $(EXEC)_*.exe 2>$(NULL)

cleancore:
	@echo Cleaning Core Object Files
	$(RM) core$(SEPR).o

cleandocs:
	@echo Cleaning Doxygen Documents
ifeq ($(OS), Windows_NT)
	@powershell -ExecutionPolicy Bypass -File .\docs\docCleanup.ps1 
else
	find docs/html/ docs/latex/ docs/out/ ! -name .gitkeep -type f -delete
endif

cleanbotw:
	@echo Cleaning BoTW Object Files
	$(RM) botw$(SEPR).o

cleanmine:
	@echo Cleaning Minecraft Object Files
	$(RM) mine$(SEPR).o
	
cleantest:
	@echo Cleaning Test Object Files
	$(RM) test$(SEPR).o

cleanall: 
	$(MAKE) cleanbin
	$(MAKE) clean
	$(MAKE) cleandocs

.PHONEY: clean cleanall cleanbin cleanbotw cleancore cleandocs cleanmine botw mine 