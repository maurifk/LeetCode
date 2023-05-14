public class Solution {
  public bool DoesValidArrayExist(int[] derived)
  {
    List<int> firstPossibility = new List<int> { 0 };
    List<int> secondPossibility = new List<int> { 1 };

    int size = derived.Length;
    for (int i = 0; i < size; i++)
    {
      if (derived[i] == 1)
      {
        addOpposite(firstPossibility);
        addOpposite(secondPossibility);
      }
      else
      {
        addSame(firstPossibility);
        addSame(secondPossibility);
      }

      if (i == size - 1)
        return firstPossibility.First() == firstPossibility.Last() ||
               secondPossibility.First() == secondPossibility.Last();
    }

    return false;

    void addOpposite(List<int> values)
    {
      values.Add(values.Last() == 0 ? 1 : 0);
    }

    void addSame(List<int> values)
    {
      values.Add(values.Last() == 0 ? 0 : 1);
    }
  }
}
