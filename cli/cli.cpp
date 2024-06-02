#include "cli.h"

CommandLine::CommandLine() { 
  this->registrar = new xRegistry();
  this->registrar->parse_csv(1, "cli/core.ib");
  this->registrar->parse_csv(2, "cli/core.rb");
}

void CommandLine::display_ingredients() { this->registrar->display_ingredients(); }
void CommandLine::display_recipes() { this->registrar->display_recipes(); }
void CommandLine::injest_ingredient() {
  std::string uuid = Utilz::get_uuid();
  printf("Input Ingredient Name: ");
  std::string name;
  scanf("%d", &name);
  Ingredient ing(uuid, name);
  this->registrar->add_ingredient(ing);
}
void CommandLine::injest_recipe() {}

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
  printf(" 3: Insert Ingredient.\n");
  printf(" 4: Insert Recipe.\n");
  printf("\n");
}

int main(int argc, char const *argv[]) {
  if (strcmp(argv[1], "-h") == 0) { return -1; }
  CommandLine* cli = new CommandLine();
  bool repeat = true;
  int choice = 11;
  while (repeat) {
    printf("Choice: ");
    std::cin.get();
    scanf("%d", &choice);
    switch (choice) {
      case 0: repeat = false; break;
      case 1:
        cli->display_ingredients();
        break;
      case 2:
        cli->display_recipes();
        break;
      case 3:
        cli->injest_ingredient();
        break;
      case 4:
        cli->injest_recipe();
        break;
      default:
        printf("Defaulted\n");
        print_help();
        break;
    }
  }
  return 0;
}
