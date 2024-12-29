#ifndef XREGISTRY_H
#define XREGISTRY_H

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "ingredient.h"
#include "recipe.h"
#include "xobj.h"

/*
1: UUID;
2: RecipeName;
3: PrepTime;
4: CookTime;
5: CookType;
6: CookTemp;
7: IngredientUUID|#|Count|Volume,...;
8: RecipeUUID|#|Count|Volume,...;
9: Instr1|...;
*/
class xRegistry : xObject {
protected:
private:
  std::fstream fin;
  std::ifstream registrar;
  std::vector<Ingredient> ingredients;
  std::vector<Recipe> recipes;
  std::map<std::string,std::string> ingMap;

public:
  /*!
   * @brief   Constructor for xRegistry class. Initializes the xRegistry object.
   *
   * @details This constructor initializes the xRegistry object by setting up the exception handling for the file stream.
   *          It also calls the constructor of the base class xObject.
  */
  xRegistry();

  /*!
   * @brief Adds a new ingredient to the registry if it doesn't already exist.
   *
   * This function checks if the given ingredient already exists in the registry. If it doesn't,
   * the ingredient is added to the list of ingredients.
   *
   * @param ingredient The ingredient to be added to the registry.
   *
   * @return True if the ingredient was successfully added to the registry, false otherwise.
  */
  bool add_ingredient(Ingredient);

  /*!
   * @brief Adds a new recipe to the registry if it doesn't already exist.
   *
   * This function checks if the given recipe already exists in the registry. If it doesn't,
   * the recipe is added to the list of recipes.
   *
   * @param recipe The recipe to be added to the registry.
   *
   * @return True if the recipe was successfully added to the registry, false otherwise.
  */
  bool add_recipe(Recipe);

  /*!
   * @brief   Displays the list of ingredients in the registry.
   *
   * @details This function iterates through the list of ingredients in the registry and prints them in a formatted manner.
   *          The ingredients are displayed in a centered column with a border.
  */
  void display_ingredients();

  /*!
   * @brief   Displays the list of recipes in the registry.
   *
   * @details This function iterates through the list of recipes in the registry and prints them in a formatted manner.
   *          The recipes are displayed in a centered column with a border.
  */
  void display_recipes();

  /*!
   * @brief   Retrieves the index of the given ingredient type name.
   *
   * @details This function iterates through the predefined ingredient type names in the Ingredient class and
   *          returns the index of the matching name. If no match is found, it returns 0.
   *
   * @param   name    The name of the ingredient type to search for.
   *
   * @return  The index of the matching ingredient type name. If no match is found, returns 0.
  */
  int get_itype_index(std::string);

  /*!
   * @brief   Parses a CSV file based on the given filetype and filename.
   *
   * @details This function opens the specified CSV file, reads each row, and calls the appropriate parsing function based on the filetype.
   *          The filetype determines which parsing function to call:
   *            - 0: Calls parse_raw() to process the raw data.
   *            - 1: Calls parse_ingredient() to process ingredient data.
   *            - 2: Calls parse_recipe() to process recipe data.
   *
   * @param   filetype The type of CSV file to parse.
   * @param   filename The name of the CSV file to open.
   *
   * @throws  std::exception If an exception occurs while opening or reading the file.
  */
  void parse_csv(int,std::string);

  /*!
   * @brief   Parses a CSV row containing ingredient data and adds it to the registry.
   *
   * @details This function takes a CSV row as input, extracts the relevant data, and creates an Ingredient object.
   *          The extracted data includes UUID, ingredient name, type, and location. The Ingredient object is then added to the registry.
   *          CSV Row is expected as:
   *           - 1: UUID;
   *           - 2: Ingedient Name;
   *           - 3: Type;
   *           - 4: Location;
   *
   * @param   row The CSV row containing ingredient data.
  */
  void parse_ingredient(std::string);

  /*!
   * @brief   Parses a CSV row containing ingredient data from a recipe and adds it to the output vector.
   *
   * @details This function takes a CSV row as input, extracts the relevant data, and adds it to the output vector.
   *          The extracted data includes UUID, ingredient count, and volume.
   *          CSV Row is expected as:
   *           - 1: UUID;
   *           - 2: Ingredient Count;
   *           - 3: Volume;
   *
   * @param   row       The CSV row containing ingredient data from a recipe.
   * @param   output    The vector to store the extracted data.
   *
   * @note    The function uses strtok() to tokenize the input row.
  */
  void parse_ingredient_from_recipe(std::string,std::vector<std::string>&);

  /*!
   * @brief   Parses a CSV row containing instruction data from a recipe and adds it to the output vector.
   *
   * @details This function takes a CSV row as input, extracts the relevant data, and adds it to the output vector.
   *          The extracted data includes the instructions for the recipe.
   *          CSV Row is expected as a series of instructions separated by '|' character.
   *
   * @param   row       The CSV row containing instruction data from a recipe.
   * @param   output    The vector to store the extracted instructions.
   *
   * @note    The function uses strtok() to tokenize the input row.
  */
  void parse_instructions_from_recipe(std::string,std::vector<std::string>&);

  /*!
   * @brief   Parses a CSV row containing nested recipe data from a recipe and adds it to the output vector.
   *
   * @details This function takes a CSV row as input, extracts the relevant data, and adds it to the output vector.
   *          The extracted data includes UUID, count, and volume of nested recipes.
   *          CSV Row is expected as:
   *          - 1: UUID;
   *          - 2: Count;
   *          - 3: Volume;
   * 
   * @param   row       The CSV row containing nested recipe data from a recipe.
   * @param   output    The vector to store the extracted data.
   *
   * @note    The function uses strtok() to tokenize the input row.
  */
  void parse_nested_from_recipe(std::string,std::vector<std::string>&);

  /*!
   * @brief   Parses a CSV row containing raw data and returns it as a formatted string.
   *
   * @details This function takes a CSV row as input, tokenizes it using ';' or '\r\n' as delimiters,
   *          and constructs a formatted string by concatenating the tokens. If a token is followed by another token,
   *          ";::;" is appended to separate them. The function then prints the raw data and returns the formatted string.
   *
   * @param   row The CSV row containing raw data.
   *
   * @return  A formatted string containing the raw data.
  */
  std::string parse_raw(std::string);

  /*!
   * @brief   Parses a CSV row containing recipe data and adds it to the registry.
   *
   * @details This function takes a CSV row as input, extracts the relevant data, and creates a Recipe object.
   *          The extracted data includes UUID, recipe name, preparation time, cooking time, cooking type, cooking temperature,
   *          ingredients, nested recipes, and instructions. The Recipe object is then added to the registry.
   *          CSV Row is expected as:
   *           - 1: UUID;
   *           - 2: RecipeName;
   *           - 3: PrepTime;
   *           - 4: CookTime;
   *           - 5: CookType;
   *           - 6: CookTemp;
   *           - 7: IngredientUUID|#Count|Volume,...;
   *           - 8: RecipeUUID|#Count|Volume,...;
   *           - 9: Instr1|...;
   *
   * @param   row The CSV row containing recipe data.
   *
   * @note    The function uses strtok() to tokenize the input row.
  */
  void parse_recipe(std::string);

  /*!
   * @brief Verifies if an ingredient already exists in the registry.
   *
   * @details This function iterates through the list of ingredients in the registry and checks if the given ingredient already exists.
   *          If an ingredient with the same UUID exists, the function returns false. Otherwise, it returns true.
   *
   * @param ingredient The ingredient to be verified.
   *
   * @return True if the ingredient does not exist in the registry, false otherwise.
  */
  bool verify_ingredient(Ingredient);

  /*!
   * @brief Verifies if a recipe already exists in the registry.
   *
   * This function iterates through the list of recipes in the registry and checks if the given recipe already exists.
   * If a recipe with the same UUID exists, the function returns false. Otherwise, it returns true.
   *
   * @param recipe The recipe to be verified.
   *
   * @return True if the recipe does not exist in the registry, false otherwise.
  */
  bool verify_recipe(Recipe);
  ~xRegistry();
};



#endif // XREGISTRY_H //