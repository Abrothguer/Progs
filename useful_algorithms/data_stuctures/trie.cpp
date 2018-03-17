#include <iostream>
#include <vector>
#include <cstdlib>

#define SIZE    26
#define MAX     1000

using namespace std;

struct Trie {
    struct Trie **children;
    bool          teotfw;
};

Trie *make_node() {
    Trie *node = (Trie *) malloc(sizeof(Trie));

    node->children = (Trie **) malloc(sizeof(Trie) * SIZE);

    for (int i = 0; i < SIZE; ++i) {
        node->children[i] = NULL;
    }

    node->teotfw = false;
    return(node);
}

void add_word(Trie *trie, string s) {
    Trie *runner = trie;

    for (unsigned i = 0; i < s.size(); ++i) {
        if (not runner->children[s[i] - 'a']) {
            runner->children[s[i] - 'a'] = make_node();
        }

        runner = runner->children[s[i] - 'a'];
    }
    runner->teotfw = true;
}

void print_trie(Trie *trie, int tabs) {
    if (not trie) {
        return;
    }

    for (int i = 0; i < SIZE; ++i) {
        if (trie->children[i]) {
            for (int j = 0; j < tabs; ++j) {
                cout << " ";
            }
            cout << ((char) ('a' + i)) << ", " << trie->children[i]->teotfw << endl;
            print_trie(trie->children[i], tabs + 4);
        }
    }
}

bool search_trie(Trie *trie, string s) {
    if (not trie) {
        return(false);
    }
    Trie *runner = trie;

    for (unsigned i = 0; i < s.size(); ++i) {
        if (not runner->children[s[i] - 'a']) {
            return(false);
        }
        runner = runner->children[s[i] - 'a'];
    }

    if (runner->teotfw) {
        return(true);
    }

    return(false);
}

void free_trie(Trie **trie) {
    if (not trie or(not (*trie))) {
        return;
    }

    for (int i = 0; i < SIZE; ++i) {
        if ((*trie)->children[i]) {
            free_trie(&(*trie)->children[i]);
        }
    }

    free((*trie)->children);
    free(*trie);
    *trie = NULL;
}

bool delete_word(Trie **trie, string s, unsigned index) {
    // Trie exists or not.
    if (not trie or not (*trie)) {
        return(false);
    }

    // Node exists or not.
    if (index != s.size() and not (*trie)->children[s[index] - 'a']) {
        return(false);
    }

    // Reached the end of fucking word.
    if (index == s.size()) {
        // It is not the end of a fucking word.
        if (not (*trie)->teotfw) {
            return(false);
        }
        (*trie)->teotfw = false;

        // Looking for its children;
        bool child = false;
        for (int i = 0; i < SIZE; ++i) {
            if ((*trie)->children[i]) {
                child = true;
                break;
            }
        }

        // Found a child.
        if (child) {
            return(false);
        }

        // No children.
        free_trie(trie);
        return(true);
    }

    // Did not reach it yet.
    else{
        bool ans = delete_word(&(*trie)->children[s[index] - 'a'], s, index + 1);
        if (not ans) {
            return(false);
        }
        if ((*trie)->teotfw) {
            return(false);
        }
        bool child = false;
        for (int i = 0; i < SIZE; ++i) {
            if ((*trie)->children[i]) {
                child = true;
                break;
            }
        }

        // Found a child.
        if (child) {
            return(false);
        }

        // No children.
        free_trie(trie);
        return(true);
    }

    return(true);
}

void print_contents(Trie *trie, char str[], int level) {
    if (not trie) {
        return;
    }
    if (trie->teotfw) {
        str[level] = '\0';
        cout << str << endl;
    }

    for (int i = 0; i < SIZE; ++i) {
        if (trie->children[i]) {
            str[level] = 'a' + i;
            print_contents(trie->children[i], str, level + 1);
        }
    }
}

int main() {
    int    n, a;
    string s;
    char   cont[MAX];

    cout << "How many strings? ";
    cin >> n;;

    struct Trie *trie = make_node();
    cout << "Type the strings: " << endl;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        add_word(trie, s);
    }
    cout << "Your trie: " << endl;
    print_trie(trie, 0);

    while (true) {
        cout << "1 - Delete, 2 - Print, 3 - Quit" << endl;
        cin >> a;
        if (a == 3) {
            break;
        }
        else if (a == 2) {
            print_contents(trie, cont, 0);
        }
        else{
            cout << "Type the word: ";
            if (not (cin >> s)) {
                break;
            }
            delete_word(&trie, s, 0);
        }
    }
    return(0);
}
