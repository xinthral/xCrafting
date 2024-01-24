#include "cli.h"

CommandLine::CommandLine() { 
  this->registrar = new xRegistry();
  this->registrar->parse_csv(1, "cli/core.ib");
  this->registrar->parse_csv(2, "cli/core.rb");
}

void CommandLine::display_ingredients() { this->registrar->display_ingredients(); }
void CommandLine::display_recipes() { this->registrar->display_recipes(); }

CommandLine::~CommandLine() {}

void print_usage() {
  printf("\nUsage: bin/cookbook_%s.exe [option]\n", "core");
}

void print_help() {
  print_usage();
  printf("Help menu shows help details\n");
  printf(" 0: Unused ATM.\n");
  printf(" 1: Display Ingredients\n");
  printf(" 2: Display Recipes\n");
  printf(" 3: Unused ATM.\n");
  printf(" 4: Unused ATM.\n");
  printf("\n");
}

int main(int argc, char const *argv[]) {
  if (argc < 2) { print_help(); return -1; }
  CommandLine* cli = new CommandLine();
  int choice = atoi(argv[1]);
  switch (choice) {
    case 1:
      cli->display_ingredients();
      break;
    case 2:
      cli->display_recipes();
      break;
    case 3:
    case 4:
    default:
      printf("Defaulted\n");
      break;
  }
  return 0;
}
