#include <iostream>

#include <vector>

#include <string>

#include <algorithm>

using namespace std;


class Dish {

private:

    string name;

    int price;


public:

    Dish(const string& dishName, int dishPrice) : name(dishName), 

price(dishPrice) {}

    string getName() const {

        return name;

    }

    int getPrice() const {

        return price;
    }

};


class RestaurantMenu {

private:

    vector<Dish> dishes;

public:

    void addDish(const string& dishName, int dishPrice) {

        Dish newDish(dishName, dishPrice);

        dishes.push_back(newDish);

    }

    vector<Dish> getDishesWithinBudget(int budget) {

        vector<Dish> dishesWithinBudget;

        for (const auto& dish : dishes) {

            if (dish.getPrice() <= budget) {

                dishesWithinBudget.push_back(dish);

            }

        }

        return dishesWithinBudget;

    }

};


void displayDishesLessThanBudget(const vector<Dish>& 

dishesWithinBudget, int budget) {

    if (dishesWithinBudget.empty()) {

        cout << "No dishes found in the given cost." << endl;

    } else {

        cout << "Dishes within your budget of " << budget << " rupees:" 
<< endl;

        for (const auto& dish : dishesWithinBudget) {

            cout << dish.getName() << " - " << dish.getPrice() << " rupees" 

<< endl;
        }

    }

}


int main() {

    RestaurantMenu menu;

    menu.addDish("Biryani", 150);

    menu.addDish("Pizza", 200);

    menu.addDish("Pasta", 180);

    menu.addDish("Burger", 120);

    menu.addDish("Noodles", 90);

    menu.addDish("Salad", 80);

    menu.addDish("Sandwich", 110);

    menu.addDish("Soup", 95);

    menu.addDish("Chickenfriedrice", 150);

    menu.addDish("SpecialDosa", 120);

    menu.addDish("Somasa", 80);

    menu.addDish("Chapatti", 80);

    menu.addDish("PannerGravy", 140);

    menu.addDish("ChickenGravy", 200);

    menu.addDish("Hamburger", 180);

    menu.addDish("Coffee", 50);

    menu.addDish("Tacos", 130);

    menu.addDish("Sushi", 250);

    int userBudget;

    cout << "Enter your budget in rupees: ";

    cin >> userBudget;

    cout << "Welcome to the BudgetDishFinder! Your budget is " << 

userBudget << " rupees." << endl;

    vector<Dish> dishesWithinBudget = 

menu.getDishesWithinBudget(userBudget);

    displayDishesLessThanBudget(dishesWithinBudget, userBudget);

    return 0;

}

