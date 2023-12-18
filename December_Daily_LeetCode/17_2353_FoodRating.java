import java.util.HashMap;
import java.util.PriorityQueue;

class Food implements Comparable<Food>{
    String name;
    int rating;
    public Food(String name, int rating) {
        this.name = name;
        this.rating = rating;
    }
    @Override
    public int compareTo(Food other) {
        if (this.rating == other.rating) {
            return this.name.compareTo(other.name);
        }
        return other.rating - this.rating;
    }

}

class FoodRatings {
    HashMap<String, PriorityQueue<Food>> mapPQs;
    HashMap<String, String> foodToCuisine;
    HashMap<String, Integer> foodToRating;

    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        mapPQs = new HashMap<>();
        foodToCuisine = new HashMap<>();
        foodToRating = new HashMap<>();
        for (int i = 0; i < foods.length; i++) {
            Food food = new Food(foods[i], ratings[i]);
            foodToCuisine.put(foods[i], cuisines[i]);
            foodToRating.put(foods[i], ratings[i]);
            if (!mapPQs.containsKey(cuisines[i])) {
                mapPQs.put(cuisines[i], new PriorityQueue<>());
            }
            mapPQs.get(cuisines[i]).add(food);
        }
    }
    
    public void changeRating(String food, int newRating) {
        String cuisine = foodToCuisine.get(food);
        mapPQs.get(cuisine).add(new Food(food, newRating));
        foodToRating.put(food, newRating);
    }
    
    public String highestRated(String cuisine) {
        Food highestFood = mapPQs.get(cuisine).peek();
        while (highestFood.rating != foodToRating.get(highestFood.name)) {
            mapPQs.get(cuisine).poll();
            highestFood = mapPQs.get(cuisine).peek();
        }
        return highestFood.name;
    }
}