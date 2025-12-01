#pragma once

#include <string>
#include <vector>

// =======================
// Cantidad (número + unidad)
// =======================
struct Quantity {
    double amount = 0.0;
    std::string unit;
};

// =======================
// Ingrediente
// =======================
struct Ingredient {
    std::string name;
    Quantity quantity;

    bool hasCost = false;
    double cost = 0.0;

    bool hasCalories = false;
    int calories = 0;
};

// =======================
// Acciones de un paso
// =======================
struct StepUse {
    std::string ingredientName;
    bool hasQuantity = false;
    Quantity quantity;
};

struct StepNote {
    std::string text;
};

struct StepWait {
    int minutes = 0;
};

struct StepAction {
    enum class Kind { Use, Note, Wait } kind;

    StepUse use;
    StepNote note;
    StepWait wait;
};

// =======================
// Paso
// =======================
struct Step {
    std::string name;
    std::vector<StepAction> actions;
};

// =======================
// Receta
// =======================
struct Recipe {
    std::string name;

    int serves = 0;
    int prepTimeMin = 0;
    int cookTimeMin = 0;

    std::vector<std::string> tags;
    std::vector<Ingredient> ingredients;
    std::vector<Step> steps;

    bool requestTotalCost = false;
    bool requestTotalCalories = false;
};

// =======================
// Programa (múltiples recetas)
// =======================
struct Program {
    std::vector<Recipe> recipes;
};
