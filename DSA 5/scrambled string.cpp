{
    if (A == B)
        return true;
    if (A.size() <= 1)
        return false;
    string key = A;
    key.push_back(' ');
    key.append(B);
    if (m.find(key) != m.end())
        return m[key];
    int n = A.size();
    bool flag = false;
    for (int i = 1; i < n; i++)
    {
        bool condition1 = (solve(A.substr(0, i), B.substr(n - i, i)) && solve(A.substr(i, n - i), B.substr(0, n - i)));
        bool condition2 = (solve(A.substr(0, i), B.substr(0, i)) && solve(A.substr(i, n - i), B.substr(i, n - i)));
        if (condition1 || condition2)
        {
            flag = true;
            break;
        }
    }
    m[key] = flag;
    return flag;
}
int32_t main()
{
    string a, b;
    cin >> a >> b;
    int m = a.size(), n = b.size();
    if (m != n)
        cout << 0 << endl;
    if (m == 0 && n == 0)
        cout << 1 << endl;
    if (solve(a, b))
        cout << "Scrambled string";
    else
        cout << "Not a scrambled string";
}