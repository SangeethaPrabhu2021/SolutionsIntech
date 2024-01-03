string compress(string s)
{   int num = s.length();
    int i = 0;
    // Adding A String Variable To Store and Return Result
    string result = "";
    /* Improving The Efficiency By Adding a Nested Loop to
       Count All Characters that match s[i](ch) in One Go
       Eg: aaabbbb
           Iteration 1 : a3
           Iteration 2: b4 
           
           Total Iterations : 2
           
        Using the Traditional Single Loop Method Would Give 
        Eg: aaabbbb
        Total Iterations : 6 
        ( Since i iterates from 0 to num - 1 )
    */
    while (i < num) 
    {   char ch = s[i];
        int repetition = 1;
        while (i + repetition < num && s[i + repetition] == ch) 
        {   repetition++;
        }
        result+=ch+to_string(repetition);
        i += repetition;
    }
    return result;
}
