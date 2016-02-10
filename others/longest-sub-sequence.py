def longestSubSequence(numbers):
    dp = [ [ numbers[0] ] ]
    solution = dp[0]

    for e in numbers[1:]:
        solutionWithE = []

        for r in dp:
            if e > r[-1] and len(r) > len(solutionWithE):
                solutionWithE = r[:]

        if e not in solutionWithE:
            solutionWithE.append(e)

        dp.append(solutionWithE)

        if (len(solutionWithE) > len(solution)):
            solution = solutionWithE

    return solution

def main():
    numbers = [3, 15, 13, 17, 3, 13, 2, 14, 15, 4, 10, 15, 10, 14, 15, 14, 5, 10, 17, 9]

    print longestSubSequence(numbers)

if __name__ == "__main__":
    main()
