int32_t main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 0;
    ll dp[n];

    for (ll i = 0; i < n; i++)
        dp[i] = 1ll;
    for (ll i = 1; i < n; i++)
    {
        for (ll j = 0; j <= i; j++)
        {
            if (a[i] > a[j])
                dp[i] = max(dp[i], 1 + dp[j]);
        }
        ans = max(ans * 1ll, dp[i] * 1ll);
    }
    cout << ans << endl;
}