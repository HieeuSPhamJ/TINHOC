def max_money_earned(n, islands):
    # Initialize a 2D matrix dp with size (n + 1) x 2 representing the maximum amount of money and bonus received on each island
    dp = [[0] * 2 for _ in range(n + 1)]

    # Fill the first row with 0 and bonuses
    dp[1][0] = 0
    for i, bonus in enumerate(islands[0], start=1):
        dp[i][0] = bonus

    # Iterate from island 2 to n and update dp values based on the given conditions
    for i in range(2, n + 1):
        # Calculate the maximum amount of money that can be earned while going to island i
        max_money = float('-inf')
        max_bonus = float('-inf')
        for j in range(i - 1, 0, -1):  # Iterate from current island i - 1 down to island 1 (since we can only go forward)
            money_earned = dp[j][0] + islands[i - 1][j]
            if money_earned > max_money:
                max_money = money_earned
                max_bonus = dp[j][1]
            dp[i][0] = money_earned
            dp[i][1] = max_bonus

    # Return the maximum amount of money that Tuan can earn
    return max(dp[n][0], 0)

# Example input
n = 5
islands = [[6, -5, 7, 3, -2], [-4, -1, -3, 8, -6]]
result = max_money_earned(n, islands)
print("The maximum possible amount of money Tuan can earn is:", result)