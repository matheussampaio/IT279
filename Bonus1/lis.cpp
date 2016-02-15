//============================================================================
// Author      : Matheus Sampaio <msanto2@ilstu.edu>
// ULID        : msanto2
// Class       : IT279 - Algorithms And Data Structures
// Copyright   : MIT
//============================================================================

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

/**
 * Initiate random seed
 */
void set_random_seed() {
    // get current time
    time_t timer;
    time(&timer);

    // start srand seed
    srand(timer);
}

/**
 * Print array of integer. If size if greater then 25,
 * then print just the first 25 elements.
 *
 * @param size The size of the array.
 * @param array[] The array.
 */
void print_array(int size, int array[]) {
    int max_length = 25;

    if (size < max_length) {
        max_length = size;
    }

    for (int i = 0; i < max_length - 1; i++) {
        std::cout << array[i] << ", ";
    }

    std::cout << array[max_length - 1];

    if (size > max_length) {
        std::cout << ", .....";
    }

    std::cout << std::endl;
}

/**
 * Generate an array of random integers between 0 and size (size included).
 *
 * @param size The size of the array to be generated.
 * @return Array with random integers.
 */
int* generate_numbers(int size) {
    int* array = new int[size];

    for (int i = 0; i < size; i++) {
        int n = rand() % (size + 1);
        array[i] = n;
    }

    return array;
}

/**
 * Search for element in array.
 *
 * @param size The size of the array.
 * @param array[] The array.
 * @param element The element to be searched for.
 * @return True if array contains elemente. False otherwise.
 */
bool array_contains_element(int size, int array[], int element) {
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return true;
        }
    }

    return false;
}

/**
 * Find and print the longest increasing subsequence inside of numbers.
 *
 * @param size The size of numbers.
 * @param numbers[] The numbers array.
 */
void longest_sub_sequence(int size, int numbers[]) {
    int next_index[size];
    int solutions_length[size];

    int best_solution_start_index = 0; // keep track of best solution

    for (int i = 0; i < size; i++) {
        next_index[i] = -1;
        solutions_length[i] = 1;

        for (int k = 0; k < i; k++) {

            if (numbers[i] > numbers[k] && solutions_length[k] >= solutions_length[i]) {
                solutions_length[i] = solutions_length[k] + 1;

                if (solutions_length[i] > solutions_length[best_solution_start_index]) {
                    best_solution_start_index = i;
                }

                next_index[i] = k;
            }
        }
    }

    int best_solution_length = solutions_length[best_solution_start_index];
    int best_solution_array[best_solution_length];

    int index = best_solution_start_index;
    for (int i = best_solution_length - 1; i >= 0; i--) {
        best_solution_array[i] = numbers[index];
        index = next_index[index];
    }

    std::cout << "Longest increasing subsequence, length:" << best_solution_length << std::endl;
    print_array(best_solution_length, best_solution_array);
}

/**
 * The main method. You should pass the size of the array as command-line
 * argument.
 */
int main(int argc, char **argv) {
    if (argc >= 2) {
        std::istringstream iss( argv[1] );
        int size;

        if (iss >> size && size > 0) {
            // init randon seed
            set_random_seed();

            int* numbers = generate_numbers(size);
            std::cout << "Sequence length:" << size << std::endl;
            print_array(size, numbers);

            longest_sub_sequence(size, numbers);
        }
    }

    return 0;
}
