long long oddNumbers(std::string s)
{
    set<char> basket;
    for(char c : s) basket.insert(c);
    //
    if(basket.size() == 1) return 5;
    if(basket.size() == 2) return 45;
    if(basket.size() > 10) return 0;
    //
    long long cumulate = 45;
    int digits = 8;
    for(int i = int(basket.size() - 2); i > 0 ; --i) cumulate *= digits, digits--;
    return cumulate;
}
