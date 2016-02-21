//============================================================================
// Author      : Matheus Sampaio <msanto2@ilstu.edu>
// ULID        : msanto2
// Class       : IT279 - Algorithms And Data Structures
// Copyright   : MIT
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

/**
 * Get the 9th column of string.
 */
std::string get_column_9(std::string line) {
    std::string buf;
    std::stringstream ss(line);

    for (int i = 0; i < 9; i++) {
        ss >> buf;
    }

    return buf;
}

/**
 * Split string.
 *
 * Credits: http://stackoverflow.com/posts/7408245/revisions
 */
std::vector<std::string> split(const std::string &text, char sep) {
    std::vector<std::string> tokens;
    std::size_t start = 0, end = 0;

    while ((end = text.find(sep, start)) != std::string::npos) {
        tokens.push_back(text.substr(start, end - start));
        start = end + 1;
    }

    tokens.push_back(text.substr(start));

    return tokens;
}

/**
 * Remove ':' at the end of the path, split and remove empty elements.
 */
std::vector<std::string> prep_path(std::string path) {

    // If path ends with colon, remove it.
    if (*path.rbegin() == ':') {
        path = path.substr(0, path.size() - 1);
    }

    // split path
    std::vector<std::string> path_splited = split(path, '/');

    // remove empty elements
    for (int i = 0; i < path_splited.size(); i++) {
        if (path_splited[i] == "") {
            path_splited.erase(path_splited.begin() + i);
            i = 0;
        }
    }

    return path_splited;
}

struct Node {
    std::string data;
    std::vector<Node*> children;

    /**
     * Create a Node.
     *
     * @param str The data of the node.
     */
    Node(std::string str) {
        data = str;
    }

    /**
     * Add a new children.
     *
     * @param data The data of the new children.
     * @return The Children Node.
     */
    Node* add_children(std::string data) {
        Node *node = new Node(data);
        children.push_back(node);

        return node;
    }

    /**
     * Search for a children with `data`.
     *
     * @param data Data term for search.
     * @return The Node if found, NULL otherwise.
     */
    Node* get_children(std::string data) {
        for (int i = 0; i < children.size(); i++) {
            if (children[i]->data == data) {
                return children[i];
            }
        }

        return NULL;
    }

    /**
     * Search a Node with `data` (Add if not exists) and return it.
     *
     * @param data The data for search or add.
     * @return The Node.
     */
    Node* get_or_add_children(std::string data) {
        Node *node = get_children(data);

        if (node != NULL) {
            return node;
        }

        return add_children(data);
    }

    /**
     * Print Node `data` and childrens (if deep > 0).
     *
     * @param tabs Size of the identation.
     * @param deep Print children recursively util deep = 0.
     */
    void print(int tabs, int deep) {
        for (int i = 0; i < tabs; i++) {
            std::cout << "\t";
        }

        std::cout << data << std::endl;

        if (deep > 0) {
            for (int i = 0; i < children.size(); i++) {
                children[i]->print(tabs + 1, deep - 1);
            }
        }
    }

    /**
     * Shortcut for print every Node.
     */
    void print() {
        print(0, 999999);
    }
};

/**
 * Read the file and create a Tree for representing the folders.
 */
Node *create_tree() {
    Node *root = new Node("/");

    std::string line;
    std::ifstream myfile ("allUserDir.txt");

    if (myfile.is_open()) {
        // folder paths
        while (getline(myfile, line)) {

            std::vector<std::string> path = prep_path(line);

            Node *node = root->get_or_add_children(path[0]);

            for (int i = 1; i < path.size(); i++) {
                node = node->get_or_add_children(path[i]);
            }

            // skip size line
            getline(myfile, line);

            // leaves files
            while (getline(myfile, line)) {
                if (line == "") {
                    break;
                }

                node->add_children(get_column_9(line));
            }

        }

        myfile.close();
    } else {
        std::cout << "Unable to open file";
    }

    return root;
}

/**
 * Print a section of the Tree.
 *
 * @param root Tree root.
 * @param path Section to be printed.
 */
void print_section(Node *root, std::string path) {
    std::vector<std::string> path_splited = prep_path(path);

    Node *node = root;

    for (int i = 0; i < path_splited.size(); i++) {
        node = node->get_children(path_splited[i]);

        if (node == NULL) {
            std::cout << "Error: Path not found." << std::endl;
            break;
        }
    }

    if (node != NULL) {
        node->print();
    }
}
/**
 * The main method. You should pass the size of the array as command-line
 * argument.
 */
int main(int argc, char **argv) {
    std::string path = "/home/";

    if (argc >= 2) {
        path += argv[1];
    }

    std::cout << std::endl << path << std::endl;

    Node *root = create_tree();

    print_section(root, path);

    return 0;
}
