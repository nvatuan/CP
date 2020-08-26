int sumOfSquare(int n)
{
    int result = 0;
    for(long long a = 0; a*a <= n; a++) {
        for(long long b = a+1; (a*a+b*b) <= n; b++) {
            long long sc = (n - (a*a + b*b));          
            //
            if(sc <= b*b) break;
            else {
                if( ((long long)(sqrt(sc))*(long long)(sqrt(sc))) == sc ) result += 1;
            }
        }
    }
    return result;
}
