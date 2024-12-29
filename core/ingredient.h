#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include "utilz.h"
#include "xobj.h"


class Ingredient : public xObject {
protected:

private:
  int quantity;
  std::string location;
  std::vector<std::string> provides;
  std::string _type;

public:
  static const std::string IName[5];
  /*!
   * @brief   Default constructor for the Ingredient class.
   *
   * @details Initializes an empty Ingredient object with default values.
  */
  Ingredient();

  /*!
   * @brief   Constructor for the Ingredient class with given ID.
   *
   * @details Initializes an Ingredient object with the provided ID and default values for other attributes.
   *
   * @param   id      The unique identifier for the Ingredient object.
   * 
   * @note    The constructor calls the parent constructor (Ingredient(std::string id))
  */
  Ingredient(std::string);

  /*!
   * @brief   Constructor for the Ingredient class with given ID and name.
   *
   * @details Initializes an Ingredient object with the provided ID and name, and default values for other attributes.
   *
   * @param   id      The unique identifier for the Ingredient object.
   * @param   name    The name of the Ingredient object.
  */
  Ingredient(std::string,std::string);

  /*!
   * @brief   Constructor for the Ingredient class with given ID, name, and count.
   *
   * @details Initializes an Ingredient object with the provided ID, name, and count,
   *          and default values for other attributes.
   *
   * @param   id      The unique identifier for the Ingredient object.
   * @param   name    The name of the Ingredient object.
   * @param   count   The quantity of the Ingredient object.
   * 
   * @note    The constructor calls the parent constructor (Ingredient(std::string id, std::string name))
   *          and then sets the type of the Ingredient object using the set_type() method.
  */
  Ingredient(std::string,std::string,int);

  /*!
   * @brief   Constructor for the Ingredient class with given ID, name, count, and type.
   *
   * @details Initializes an Ingredient object with the provided ID, name, count, and type.
   *          The default values for other attributes are set.
   *
   * @param   id      The unique identifier for the Ingredient object.
   * @param   name    The name of the Ingredient object.
   * @param   count   The quantity of the Ingredient object.
   * @param   type    The type of the Ingredient object, which should be one of the predefined types:
   *                  "Culinary", "Protein", "Produce", "Grain", or "Craft".
   *
   * @note    The constructor calls the parent constructor (Ingredient(std::string id, std::string name, int count))
   *          and then sets the type of the Ingredient object using the set_type() method.
  */
  Ingredient(std::string,std::string,int,std::string);

  /*!
   * @brief   Adds a benefit provided by the Ingredient object to the list of benefits.
   *
   * @details This function adds a new benefit to the list of benefits that the Ingredient object provides.
   *          The benefits are stored in a std::vector<std::string> called 'provides'.
   *
   * @param   benefit  The new benefit provided by the Ingredient object. This should be a string
   *                   representing the benefit.
   *
   * @return  An integer representing the new size of the 'provides' vector after adding the new benefit.
   *          This can be used to verify that the benefit was successfully added.
  */
  int add_provides(std::string);

  /*!
   * @brief   Displays the benefits provided by the Ingredient object.
   *
   * @details This function iterates over the 'provides' vector and prints each benefit
   *          to the standard output using the printf function. The benefits are
   *          stored as strings in the 'provides' vector.
   *
   * @note    The benefits are printed with a leading colon and a newline character.
   *          This function is primarily used for debugging or displaying the benefits
   *          to the user.
  */
  void display_provides();

  /*!
   * @brief   Retrieves the location of the Ingredient object.
   *
   * @details This function returns the location of the Ingredient object.
   *          The location represents the physical place where the ingredient is stored.
   *
   * @return  A string representing the location of the Ingredient object.
  */
  std::string get_location();

  /*!
   * @brief   Retrieves the quantity of the Ingredient object.
   *
   * @details This function returns the quantity of the Ingredient object.
   *          The quantity represents the amount or count of the ingredient available.
   *
   * @return  An integer representing the quantity of the Ingredient object.
  */
  int get_quantity();

  /*!
   * @brief   Retrieves the type of the Ingredient object.
   *
   * @details This function returns the type of the Ingredient object
   *
   * @return  A string representing the type of the Ingredient object.
  */
  std::string get_type();

  /*!
   * @brief   Sets the location of the Ingredient object.
   *
   * @details This function updates the location of the Ingredient object with the provided value.
   *          The location represents the physical place where the ingredient is stored.
   *
   * @param   newValue     The new location of the Ingredient object. This should be a string representing
   *                      the physical place where the ingredient is stored.
  */
  void set_location(std::string);

  /*!
   * @brief   Sets the quantity of the Ingredient object.
   *
   * @details This function updates the quantity of the Ingredient object with the provided value.
   *          The quantity represents the amount or count of the ingredient available.
   *
   * @param   newValue     The new quantity of the Ingredient object. This should be a non-negative integer.
  */
  void set_quanitity(int);

  /*!
   * @brief   Sets the type of the Ingredient object.
   *
   * @details This function sets the type of the Ingredient object based on the provided string.
   *          The function compares the provided string with the predefined types in the IName array.
   *          If a match is found, the corresponding index is returned and the type of the object is set.
   *          If no match is found, the function returns 0 and the type remains unchanged.
   *
   * @param   newType     The new type of the Ingredient object. This should be one of the predefined types:
   *                      "Culinary", "Protein", "Produce", "Grain", "Craft", etc...
   *
   * @return  An integer representing the index of the new type in the IName array.
   *          If no match is found, the function returns 0.
  */
  int set_type(std::string);

  /*!
   * @brief   Retrieves the number of benefits provided by the Ingredient object.
   *
   * @details This function returns the number of benefits that the Ingredient object provides.
   *          The benefits are stored in a std::vector<std::string> called 'provides'.
   *
   * @return  An integer representing the number of benefits provided by the Ingredient object.
   *          This can be used to iterate over the 'provides' vector and access each benefit.
  */
  int provides_length();

  /*!
   * @brief   Retrieves the string representation of the type based on the provided index.
   *
   * @details This function returns the string representation of the type based on the provided index.
   *          The string representation is obtained from the IName array, which contains predefined types.
   *          The function is used to convert the index of the type into its corresponding string representation.
   *
   * @param   index   The index of the type in the IName array. This should be a non-negative integer
   *                  and less than the size of the IName array.
   *
   * @return  A string representing the type based on the provided index.
   *          If the index is out of range, the function returns an empty string.
  */
  std::string type_repr(int);
  ~Ingredient();
};

#endif // INGREDIENT_H //
