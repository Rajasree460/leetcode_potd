class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int totalBottles = numBottles;

        while (numBottles >= numExchange) {
            totalBottles += numBottles / numExchange;
            numBottles = (numBottles / numExchange) + (numBottles % numExchange);  //if numBottles is not a multiple of numExchange ,so add (numBottles % numExchange)
        }

        return totalBottles;
    }
}
