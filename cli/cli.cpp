#include "cli.h"

CommandLine::CommandLine() {
  this->registrar = new xRegistry();
  this->registrar->parse_csv(1, "cli/core.ib");
  this->registrar->parse_csv(2, "cli/core.rb");
  this->_history = std::vector<int>();
}

void CommandLine::display_ingredients() {
  this->registrar->display_ingredients(); 
}

void CommandLine::display_recipes() {
  this->registrar->display_recipes();
}

void CommandLine::injest_ingredient() {
  std::string uuid = Utilz::CreateUUID();
  std::string name;
  name = Utilz::UserInput("Input Ingredient Name: ");
  Ingredient ing(uuid, name);
  printf("Registering %s\n", name.c_str());
  this->registrar->add_ingredient(ing);
  sleep(1);
}

void CommandLine::injest_recipe() {
  std::string uuid = Utilz::CreateUUID();
  std::string name;
  name = Utilz::UserInput("Input Recipe Name: ");
  Recipe recipe(uuid, name);
  recipe.user_input_instructions();
  this->registrar->add_recipe(recipe);
  sleep(1);
}

void CommandLine::history() {
  int step = 0;
  printf("History: \n");
  for (auto s : this->_history) {
    printf(" %3d :: %d\n", step++, s);
  }
}

void CommandLine::append_history(int input) {
  this->_history.push_back(input);
}

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
      cli->append_history(choice);
    }
  }

  cli->history();
  return 0;
}