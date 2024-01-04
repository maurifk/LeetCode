class Solution {
    public int totalMoney(int n) {
        int sems = n / 7;
        int diasSobra = n % 7;
        
        return 28*sems + ((sems)*(sems-1)/2)*7 + (diasSobra)*(2*sems + 1 + diasSobra)/2;
    }
}
