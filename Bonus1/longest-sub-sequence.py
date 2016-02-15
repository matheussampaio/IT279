import random
import sys

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

    size = 10

    if (sys.argv[1] and int(sys.argv[1]) > 0):
        size = int(sys.argv[1])

    numbers = [random.randint(1, size) for i in xrange(size)]

    print "**** size: %d ****" % size
    print len(longestSubSequence(numbers))

if __name__ == "__main__":
    main()
