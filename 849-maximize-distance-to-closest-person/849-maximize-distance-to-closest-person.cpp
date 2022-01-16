class Solution {
public:
    int maxDistToClosest(vector<int> &seats)
{
    int n = seats.size(), i;
    vector<int> left(n, -1), right(n, -1);
    if (seats[0] == 0)
    {
        left[0] = INT_MAX;
    }
    for (i = 1; i < n; ++i)
    {
        if (seats[i] == 1)
        {
            continue;
        }
        if (left[i - 1] == INT_MAX)
        {
            left[i] = INT_MAX;
            continue;
        }
        if (left[i - 1] == -1)
        {
            left[i] = 1;
            continue;
        }
        left[i]= (left[i-1] + 1);
    }
    if (seats[n - 1] == 0)
    {
        right[n - 1] = INT_MAX;
    }
    for (i = n - 2; i >= 0; --i)
    {
        if (seats[i] == 1)
        {
            continue;
        }
        if (right[i + 1] == INT_MAX)
        {
            right[i] = INT_MAX;
            continue;
        }
        if (right[i + 1] == -1)
        {
            right[i] = 1;
            continue;
        }
        right[i]=(right[i + 1] + 1);
    }
    for(auto x: left){
        cout << x << " ";
    }
    cout << endl;
    for(auto x: right){
        cout << x << " ";
    }
    int res = INT_MIN;
    for (i = 0; i < n; ++i)
    {
        res = max(res, min(left[i], right[i]));
    }
    return res;
}
};