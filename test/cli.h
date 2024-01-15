#ifndef XCRAFTING_TEST_H
#define XCRAFTING_TEST_H

#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include "cookbooktest.h"
#include "ingredienttest.h"
#include "recipetest.h"
#include "sqltest.h"

void TestCookBook();
void TestIngredient();
void TestRecipe();
void TestSQL();


int get_choice(char *);
void print_usage();
void print_help();

#endif // XCRAFTING_TEST_H //
