bool include(vector<int> nodes, int node)
{
    for (int n : nodes)
    {
        if (n == node)
            return true;
    }
    return false;
}
