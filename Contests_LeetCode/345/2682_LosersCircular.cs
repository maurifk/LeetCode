public class Solution {
  public int[] CircularGameLosers(int n, int k)
  {
    List<bool> players = new List<bool>();
    for (int i = 0; i < n; i++)
      players.Add(i == 0 ? true : false);


    bool repeated = false;

    int round = 1;
    int currentPosition = 0;

    do
    {
      int increment = round * k;
      int newPosition = (currentPosition + increment) % n;

      if (players[newPosition])
        repeated = true;
      else
        players[newPosition] = true;

      round++;
      currentPosition = newPosition;
    } while (!repeated);

    List<int> losers = new List<int>();

    for (int i = 0; i < n; i++)
    {
      if (!players[i])
        losers.Add(i+1);
    }

    return losers.ToArray();
  }
}
