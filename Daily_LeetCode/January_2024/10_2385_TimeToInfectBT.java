import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;
import javafx.util.Pair;

import Extra_Classes.TreeNode;

class Solution {
    private List<List<Integer>> graph = new ArrayList<List<Integer>>();

    int i = 0;

    private Map<Integer, Integer> mapa = new HashMap<>();

    private void creadorGrafo(TreeNode root) {
        if (root.left != null) {
            graph.get(mapa.get(root.val)).add(root.left.val);
            graph.add(new ArrayList<>());
            graph.get(i).add(root.val);

            mapa.put(root.left.val, i++);
            creadorGrafo(root.left);
        }

        if (root.right != null) {
            graph.get(mapa.get(root.val)).add(root.right.val);
            graph.add(new ArrayList<>());
            graph.get(i).add(root.val);
            mapa.put(root.right.val, i++);
            creadorGrafo(root.right);
        }
    }

    private int bfs(int start) {
        Set<Integer> visitados = new HashSet<>();
        Queue<Pair<Integer, Integer>> q = new ArrayDeque<>();
        q.add(new Pair<>(start, 0));
        int distance = 0;
        int maxDist = 0;

        while (!q.isEmpty()) {
            Pair<Integer, Integer> u = q.poll();
            distance = u.getValue();
            if (!visitados.contains(u.getKey())){
                visitados.add(u.getKey());
                maxDist = distance;
                for (int v : graph.get(mapa.get(u.getKey()))) {
                    if (!visitados.contains(v)) {
                        q.add(new Pair<Integer, Integer>(v, distance+1));
                    }
                }
            }
        }
        return maxDist;
    }

    public int amountOfTime(TreeNode root, int start) {
        graph.add(new ArrayList<>());
        mapa.put(root.val, i++);
        creadorGrafo(root);
        return bfs(start);
    }
}
