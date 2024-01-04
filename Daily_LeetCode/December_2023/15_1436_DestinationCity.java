import java.util.HashSet;
import java.util.List;

class Solution {
    public String destCity(List<List<String>> paths) {
        HashSet<String> outgoing = new HashSet<>();
        HashSet<String> ingoing = new HashSet<>();
        for (List<String> path : paths) {
            outgoing.add(path.get(0));
            ingoing.add(path.get(1));
        }

        ingoing.removeAll(outgoing);
        return (String) ingoing.toArray()[0];
    }
}
