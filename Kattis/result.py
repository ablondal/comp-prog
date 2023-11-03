def solve(nums, ops, func):
	# Solve this with Dynamic Programming
	# This is the same process with min and max, just a different func
	n = len(nums);
	DP = [[9]*n for _ in range(n)]; # Create an nxn array
	# DO NOT DO [[0]*n]*n.
	# If you do, the inner arrays will all be references to the same array.
	
	# DP[i][j] represents the max/min value attainable using the numbers
	# and operators in the range [i, j], inclusive.
	for i in range(n):
		DP[i][i] = nums[i]; # Obviously, DP[i][i] can only be nums[i].
		# print(i, i, DP[i][i]) # Debug

	for d in range(1, n):
		# Iterate on the difference between i and j. We've already done 0 above.
		for i in range(0, n-d):
			j = i+d;
			# Calculate DP[i][j] for all i,j, such that j-i = d.
			# Try every possible breaking point
			# to split up [i, j] into [i, k] (op) [k+1, j].
			# Since the DP values for those smaller ranges are already
			# optimal, so will the new DP value, since these are all possible
			# optimal choices.
			choices = [
				(DP[i][k] + DP[k+1][j]) if ops[k] == '+'
				else (DP[i][k] * DP[k+1][j])
				for k in range(i, j)
			]

			DP[i][j] = func(choices) # Either max or min

			# print(i, j, DP[i][j]) # Debug
	# Now we've calculated DP[i][j] for all relevant i, j.
	return DP[0][n-1];


def parse(exp):
	# Parse the expression
	currnum, nums, ops = 0, [], [];
	for i in range(len(exp)):
		if exp[i] in ('+', '*'):
			# Number ends
			nums.append(currnum);
			ops.append(exp[i]);
			currnum = 0; # Start a new number
		else:
			# Easiest way to iteratively build a number.
			currnum *= 10;
			currnum += ord(exp[i]) - ord('0');
			# Way nicer in C++ where chars are short integers
	nums.append(currnum);
	return nums, ops


while True:
	a = input();
	if a == "END":
		break;
	nums, ops = parse(a);
	# print(nums, ops) # Debug
	print(solve(nums, ops, min), solve(nums, ops, max))
	# Reuse code using functions
	# No copy-paste bugs
	# Only debug once
	# Functions are variables and it's cool