int sumOfAllDigitsInRange(int L, int R)
{
    vector<int> sumDigits(10001, 0);
    for(int i = 1; i < 10001; i++) {
        sumDigits[i] = sumDigits[i/10] + (i%10);
    }
    //
    int res = 0;
    for(int i = L; i <= R; i++) res += sumDigits[i];
    return res;
}