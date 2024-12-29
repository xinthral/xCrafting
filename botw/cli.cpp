#include "cli.h"

CommandLine::CommandLine() {
  this->registrar = new xRegistry();
  this->registrar->parse_csv(1, "botw/core.ib");
  this->registrar->parse_csv(2, "botw/core.rb");
  this->_history = std::vector<std::string>();
}

void CommandLine::display_ingredients() {
  this->registrar->display_ingredients(); 
}

void CommandLine::display_recipes() {
  this->registrar->display_recipes();
}

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
  int step = -1;
  print_usage();
  printf("Help menu shows help details\n");
  printf(" %3d: Close.\n", step);
  printf(" %3d: Display Help.\n", step += 1);
  printf(" %3d: Display Ingredients.\n", step += 1);
  printf(" %3d: Display Recipes.\n", step += 1);
  printf(" %3d: Insert Ingredient.\n", step += 1);
  printf(" %3d: Insert Recipe.\n", step += 1);
  printf("\n");
}

int main(int argc, char const *argv[]) {
  if (argc > 1) {
    if (strcmp(argv[1], "-h") == 0) {
      print_help();
      return 0;
    }
  }

  CommandLine* cli = new CommandLine();
  bool repeat = true;
  int choice = 0;
  while (repeat) {
    switch (choice) {
      case -1:
        repeat = false; 
        break;
      case 0: 
        print_help(); 
        break;
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
        print_help();
        continue;
    }
    if (repeat) {
      printf("Choice: ");
      scanf("%d", &choice);
    }
  }

  cli->history();
  return 0;
}