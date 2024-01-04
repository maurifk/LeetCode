
class Solution {
    public int maxProductDifference(int[] nums) {
        int mayor = Integer.MIN_VALUE;
        int segundoMayor = Integer.MIN_VALUE;
        int menor = Integer.MAX_VALUE;
        int segundoMenor = Integer.MAX_VALUE;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > mayor) {
                segundoMayor = mayor;
                mayor = nums[i];
            } else if (nums[i] > segundoMayor) {
                segundoMayor = nums[i];
            }

            if (nums[i] < menor) {
                segundoMenor = menor;
                menor = nums[i];
            } else if (nums[i] < segundoMenor) {
                segundoMenor = nums[i];
            }
        }
        return (mayor * segundoMayor) - (menor * segundoMenor);
    }
}