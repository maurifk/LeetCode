import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ThreadLocalRandom;

class RandomizedSet {
	Map<Integer, Integer> ubics = new HashMap<>();
	List<Integer> arr = new ArrayList<>();
	int tope = 0;

    public RandomizedSet() {
    }

    public boolean insert(int val) {
		if (ubics.get(val) == null) {
			if (arr.size() == tope) {
				arr.add(val);
				ubics.put(val, tope);
				tope++;
			} else {
				arr.set(tope, val);
				ubics.put(val, tope);
				tope++;
			}
			return true;
		} else {
			return false;
		}
    }

    public boolean remove(int val) {
		if (ubics.get(val) != null) {
			arr.set(ubics.get(val), arr.get(--tope));
			ubics.put(arr.get(tope), ubics.get(val));
			ubics.remove(val);
			return true;
		} else {
			return false;
		}
    }

    public int getRandom() {
		return arr.get(ThreadLocalRandom.current().nextInt(tope));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
