#ifndef RECIPE_H
#define RECIPE_H

#include <fstream>
#include "ingredient.h"
#include "xobj.h"

// Recipe_Name;
// UUID;
// Recipe Name;
// PrepTime(minutes);
// CookTime(minutes);
// CookType;
// CookTemp;
// Ingredient List: UUID|#|Volume,...;
// Nested Recipe List: UUID|#|Volume,...;
// Instruction List: Do thing1|Do thing2|Do thing3|consume!|...;

class Recipe : public xObject {
protected:
private:
  std::map<std::string, std::string> contains;
  std::vector<std::string> instructions;
  std::string cooktemp;
  int cooktime;
  int preptime;
  int cooktimemax;

public:
  /*!
   * @brief   Constructor for Recipe class. Initializes cooktimemax to 604,800.
   *
   * @details This constructor initializes the Recipe object with default values.
   *          It calls the constructor of the base class xObject with no parameters.
   *
   * @return  No return value.
  */
  Recipe();

  /*!
   * @brief   Constructor for Recipe class with ID parameter.
   *
   * @details Initializes the Recipe object with the given ID and default cooktimemax value of 604,800.
   *          Calls the constructor of the base class xObject with the provided ID.
   *
   * @param   id  Unique identifier for the Recipe object.
  */
  Recipe(std::string);

  /*!
   * @brief   Constructor for Recipe class with ID and name parameters.
   *
   * @details Initializes the Recipe object with the given ID and name, and sets the default cooktimemax value to 604,800.
   *          Calls the constructor of the base class xObject with the provided ID and name.
   *
   * @param   id  Unique identifier for the Recipe object.
   * @param   name  Descriptive name for the Recipe object.
  */
  Recipe(std::string,std::string);

  /*!
   * @brief   Displays the ingredients of the recipe.
   *
   * @details This function iterates through the ingredients map and prints each ingredient's UUID.
   *          If the 'headers' parameter is set to true, it prints a header before displaying the ingredients.
   *
   * @param   headers If true, prints a header before displaying the ingredients.
  */
  void display_ingredients(bool);

  /*!
   * @brief   Displays the cooking instructions for the recipe.
   *
   * @details This function prints the cooking instructions for the recipe.
   *          If the 'showtime' parameter is set to true, it also prints the cooktime and preptime.
   *
   * @param   showtime  If true, prints the cooktime and preptime before displaying the instructions.
  */
  void display_instructions(bool);

  /*!
   * @brief   Retrieves the cooking temperature for the recipe.
   *
   * @details This function returns the cooking temperature for the recipe.
   *          The cooking temperature is stored in the 'cooktemp' member variable.
   *
   * @return  A string representing the cooking temperature.
  */
  int get_cooktime();

  /*!
   * @brief   Retrieves the cooking time for the recipe.
   *
   * @details This function returns the cooking time for the recipe.
   *          The cooking time is stored in the 'cooktime' member variable.
   *
   * @return  An integer representing the cooking time in seconds.
  */
  std::string get_cooktemp();

  /*!
   * @brief   Retrieves the preparation time for the recipe.
   *
   * @details This function returns the preparation time for the recipe.
   *          The preparation time is stored in the 'preptime' member variable.
   *
   * @return  An integer representing the preparation time in seconds.
  */
  int get_preptime();

  /*!
   * @brief   Retrieves the number of ingredients in the recipe.
   *
   * @details This function returns the count of ingredients present in the recipe.
   *          The ingredients are stored in a map called 'contains', where the key is the UUID and the value is the ingredient name.
   *
   * @return  An integer representing the number of ingredients in the recipe.
  */
  int ingredient_count();

  /*!
   * @brief   Inserts a new ingredient into the recipe.
   *
   * @details This function adds a new ingredient to the recipe's 'contains' map.
   *          The ingredient is identified by its UUID and has a corresponding name.
   *          After inserting the ingredient, it calls the 'ingredient_count' function to update the count of ingredients.
   *
   * @param   uuid        Unique identifier for the ingredient.
   * @param   ingredient  Descriptive name for the ingredient.
   *
   * @return  An integer representing the updated count of ingredients in the recipe.
  */
  int insert_ingredient(std::string,std::string);

  /*!
   * @brief   Removes an ingredient from the recipe.
   *
   * @details This function removes the ingredient identified by the given UUID from the recipe's 'contains' map.
   *          After removing the ingredient, it calls the 'ingredient_count' function to update the count of ingredients.
   *
   * @param   uuid  Unique identifier for the ingredient to be removed.
   *
   * @return  An integer representing the updated count of ingredients in the recipe.
  */
  int remove_ingredient(std::string);

  /*!
   * @brief   Sets the ingredients for the recipe.
   *
   * @details This function takes a vector of strings representing the ingredients and populates the 'contains' map.
   *          Each string in the vector is tokenized using ';' or '\r\n' as delimiters. The token is used as the key
   *          and the original string as the value in the 'contains' map.
   *
   * @param   ingredientlist  A vector of strings representing the ingredients. Each string should be in the format
   *                          "UUID;Ingredient Name".
  */
  void set_ingredients(std::vector<std::string>);

  /*!
   * @brief   Sets the cooking temperature for the recipe.
   *
   * @details This function updates the cooking temperature for the recipe.
   *          The cooking temperature is stored in the 'cooktemp' member variable.
   *
   * @param   temp  A string representing the cooking temperature.
   *                The string should be in a format that is meaningful to the user.
   *                For example, "200°C" or "High".
  */
  void set_cooktime(int);

  /*!
   * @brief   Sets the cooking time for the recipe.
   *
   * @details This function updates the cooking time for the recipe.
   *          The cooking time is stored in the 'cooktime' member variable.
   *          If the provided cooktime is less than 0 or greater than the maximum allowed cooktime (cooktimemax),
   *          it prints an error message and does not update the cooktime.
   *
   * @param   newtime  An integer representing the new cooking time in seconds.
   *
   * @note    If the cooktime is less than 0 or greater than the maximum allowed cooktime, then time is rejected
  */
  void set_cooktemp(std::string);

  /*!
   * @brief   Sets the cooking instructions for the recipe.
   *
   * @details This function updates the cooking instructions for the recipe.
   *          The cooking instructions are stored in the 'instructions' vector.
   *          The function iterates through the input vector and adds each string to the 'instructions' vector.
   *
   * @param   input  A vector of strings representing the cooking instructions.
   *                 Each string should contain a single instruction.
  */
  void set_instructions(std::vector<std::string>);

  /*!
   * @brief   Sets the nested recipes for the recipe.
   *
   * @details This function updates the nested recipes for the recipe.
   *          The nested recipes are stored in the 'contains' map, where the key is the UUID and the value is the recipe name.
   *          The function iterates through the input vector and extracts the UUID and recipe name using the strtok function.
   *          The extracted UUID and recipe name are then added to the 'contains' map.
   *
   * @param   recipelist  A vector of strings representing the nested recipes.
   *                      Each string should be in the format "UUID;Recipe Name".
   *
   * @note    The strtok function is used to tokenize the input strings using ';' or '\r\n' as delimiters.
   *          The first token is used as the UUID, and the original string is used as the recipe name.
  */
  void set_nested_recipes(std::vector<std::string>);

  /*!
   * @brief   Sets the preparation time for the recipe.
   *
   * @details This function updates the preparation time for the recipe.
   *          The preparation time is stored in the 'preptime' member variable.
   *          If the provided preparation time is less than 0, it prints an error message and does not update the preparation time.
   *
   * @param   preptime  An integer representing the new preparation time in seconds.
   *
   * @note    If the preptime is less than 0, then time is rejected.
  */
  void set_preptime(int);

  /*!
   * @brief   Prompts the user to input cooking instructions for the recipe.
   *
   * @details This function allows the user to input cooking instructions for the recipe.
   *          It continuously prompts the user for input until the user enters "!exit".
   *          The input instructions are stored in the 'instructions' vector.
   *          The function starts by adding a header to the instructions vector indicating the recipe name.
   *
   * @note    The function uses the 'get_name' and 'get_prompt' member functions to retrieve the recipe name and prompt string, respectively.
   *          The 'Utilz::UserInput' function is used to obtain user input.
   *
   * @return  No return value.
  */
  void user_input_instructions();
  ~Recipe();
};

#endif // RECIPE_H //