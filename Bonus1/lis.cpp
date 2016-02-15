#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void set_random_seed() {
    // get current time
    time_t timer;
    time(&timer);

    // start srand seed
    srand(timer);
}

void print_sequence(vector<int> seq) {
    int max_length = 25;

    if (seq.size() < max_length) {
        max_length = seq.size();
    }

    for (int i = 0; i < max_length - 1; i++) {
        cout << seq[i] << ", ";
    }

    cout << seq[max_length - 1];

    if (seq.size() > max_length) {
        cout << ", .....";
    }

    cout << endl;
}

vector<int> generate_numbers(int size) {
    vector<int> numbers;

    for (int i = 0; i < size; i++) {
        int n = rand() % (size + 1);
        numbers.push_back(n);
    }

    return numbers;
}

bool contains(vector<int> v, int x) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == x) {
            return true;
        }
    }

    return false;
}

vector<int> longest_sub_sequence(vector<int> numbers) {
    vector< vector<int> > dp;

    vector<int> temp;
    // dp = [ [ numbers[0] ] ]

    temp.push_back(numbers[0]);
    dp.push_back(temp);

    vector<int> solution = dp[0];


    for (int i = 1; i < numbers.size(); i++) {
        vector<int> solution_with_element;

        for (int j = 0; j < dp.size(); j++) {
            int last_element_index = dp[j][ dp[j].size() - 1];

            if (numbers[i] > last_element_index && dp[j].size() > solution_with_element.size()) {
                solution_with_element = dp[j];
            }
        }

        if (!contains(solution_with_element, numbers[i])) {
            solution_with_element.push_back(numbers[i]);
        }

        dp.push_back(solution_with_element);

        if (solution_with_element.size() > solution.size()) {
            solution = solution_with_element;
        }
    }

    return solution;
    // for e in numbers[1:]:
    //     solutionWithE = []
    //
    //     for r in dp:
    //         if e > r[-1] and len(r) > len(solutionWithE):
    //             solutionWithE = r[:]
    //
    //     if e not in solutionWithE:
    //         solutionWithE.append(e)
    //
    //     dp.append(solutionWithE)
    //
    //     if (len(solutionWithE) > len(solution)):
    //         solution = solutionWithE
    //
    // return solution
}

int main(int argc, char **argv)
{
    if (argc >= 2)
    {
        std::istringstream iss( argv[1] );
        int size;

        if (iss >> size)
        {
            // init randon seed
            // set_random_seed();

            // Generate numbers and print them
            vector<int> numbers = generate_numbers(size);
            cout << "Sequence length:" << numbers.size() << endl;
            print_sequence(numbers);

            // find the longest sub sequence and print the result
            vector<int> solution = longest_sub_sequence(numbers);

            cout << "Longest increasing subsequence, length:" << solution.size() << endl;
            print_sequence(solution);
        }
    }

    return 0;
}
