//
// Created by Yair on 15-Aug-17.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

typedef struct {
    char *key;
    int numOfSynonyms;
    char **synonyms;
} dictionaryNode;

///prints the correct form of use of the program
void printUsage();

/// Creates the edited tmp file
/// \param read_file the file we need to change
/// \param write_file the tmp file
/// \param dictionary pointer to the dictionary struct
/// \param size the size of the dictionary
void create_tmp_file(FILE *read_file, FILE *write_file, dictionaryNode **dictionary, int size);

/// count the num of lines(words) in the dictionary file
/// \param f the dictionary file
/// \return the num of lines
int count_lines(FILE *f);

/// split the str into words
/// \param a_str the str
/// \param a_delim the char to split at
/// \return array of the splited str
char **str_split(char *a_str, char a_delim);

/// compare two dictoanry nodes alphbticly by the key
/// \param a first node
/// \param b second node
/// \return
int compare(const void *a, const void *b);

/// create a dictonary struct from the file
/// \param dictionary_file
/// \return pointer to array of the dictionary nodes
dictionaryNode **createDictionary(FILE *dictionary_file);

/// free the memory the dictionary used
/// \param dictionary
/// \param size the size of the dictionary
void freeDictionary(dictionaryNode **dictionary, int size);

/// print the dictionary
/// \param dictionary
/// \param size
void printDictionary(dictionaryNode **dictionary, int size);

/// gives a synontmy to the word passed if exist otherwise returns the word itself
/// \param word the word
/// \param dictionary
/// \param size of the dictionary
void getMatchingWord(char *word, dictionaryNode **dictionary, int size);

/// find a word in the sorted dictionary
/// \param word
/// \param dictionary sorted
/// \param size the size of the dictionary
/// \return word location
int getWordLocation(char *word, dictionaryNode **dictionary, int size);

int main(int argc, char *argv[]) {
    FILE *fileToChange = NULL;
    FILE *dictionary = NULL;
    FILE *tmp = NULL;
    dictionaryNode **dictionaryStructs = NULL;
    int dictionarySize = 0;
    srand((unsigned int) time(NULL));

    if (argc != 3) {
        printUsage();
        return (0);
    }

    fileToChange = fopen(argv[1], "r");
    if (fileToChange == NULL) {
        printf("Problem with opening %s\n", argv[1]);
        return (0);
    }

    dictionary = fopen(argv[2], "r");
    if (dictionary == NULL) {
        printf("Problem with opening %s\n", argv[1]);
        return (0);
    }

    tmp = fopen("tmp.txt", "w");
    if (tmp == NULL) {
        printf("Problem with opening %s\n", "tmp.txt");
        return (0);
    }

    dictionarySize = count_lines(dictionary);

    dictionaryStructs = createDictionary(dictionary);

    qsort(dictionaryStructs, (size_t) dictionarySize, sizeof(dictionaryNode *), compare);//sorts the dictionary
    create_tmp_file(fileToChange, tmp, dictionaryStructs, dictionarySize);


    freeDictionary(dictionaryStructs, dictionarySize);
    free(dictionaryStructs);
    fclose(dictionary);
    fclose(fileToChange);
    fclose(tmp);

    remove(argv[1]);
    rename("tmp.txt", argv[1]);
    remove("tmp.txt");

    //system("PAUSE");
    return (0);
}

void create_tmp_file(FILE *read_file, FILE *write_file, dictionaryNode **dictionary, int size) {
    fseek(read_file, 0, SEEK_SET);
    ssize_t read = 0;
    char *line;
    size_t len = 0;
    char **words;
    line = malloc(sizeof(char) * 1024);
    while ((read = getline(&line, &len, read_file)) != -1) {
        line[read] = 0;
        words = str_split(line, ' ');
        if (words) {
            int i;
            for (i = 0; *(words + i); ++i) {
                getMatchingWord(words[i], dictionary, size);
                char *p = strchr(words[i], '\n');  // finds first, if any, \n
                if (p != NULL) {
                    *p = '\0';
                    fprintf(write_file, "%s\n", words[i]);
                } else {
                    fprintf(write_file, "%s ", words[i]);
                }
                free(words[i]);
            }
        }
        free(words);
    }
    free(line);
}

int count_lines(FILE *f) {
    int ch = 0;
    int lines = 0;

    lines++;
    while (!feof(f)) {
        ch = fgetc(f);
        if (ch == '\n') {
            lines++;
        }
    }
    return lines;
}

void printUsage() {
    printf("the correct user: <text file> <dictionary file>");
}

char **str_split(char *a_str, const char a_delim) {
    char **result = 0;
    size_t count = 0;
    char *tmp = a_str;
    char *last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp) {
        if (a_delim == *tmp) {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    //Add space for trailing token.
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char *) * count);

    if (result) {
        size_t idx = 0;
        char *token = strtok(a_str, delim);

        while (token) {
            if (idx < count) {
                *(result + idx++) = strdup(token);
                token = strtok(0, delim);
            }

        }
        if (idx == count - 1) {
            *(result + idx) = 0;
        }
    }

    return result;
}

int compare(const void *a, const void *b) {
    dictionaryNode *NodeA = *(dictionaryNode **) a;
    dictionaryNode *NodeB = *(dictionaryNode **) b;
    return (strcmp(NodeA->key, NodeB->key));
}

dictionaryNode **createDictionary(FILE *dictionary_file) {
    fseek(dictionary_file, 0, SEEK_SET);
    ssize_t read = 0;
    char *line;
    size_t len = 0;
    char **words;
    int word_in_line;
    int keys = count_lines(dictionary_file);
    int keys_counter = 0;
    fseek(dictionary_file, 0, SEEK_SET);
    line = malloc(sizeof(char) * 1024);
    dictionaryNode **dictionary = NULL;
    dictionary = malloc(sizeof(dictionaryNode *) * keys);
    if (dictionary == NULL) {
        printf("Error allocating memory");
        exit(-1);
    }
    while ((read = getline(&line, &len, dictionary_file)) != -1) {
        line[read] = 0;
        words = str_split(line, ' ');
        if (words) {
            int i;
            for (word_in_line = 0; *(words + word_in_line); ++word_in_line);
            for (i = 0; *(words + i); ++i) {
                char *p = strchr(*(words + i), '\n');  // finds first, if any, \n
                if (p != NULL) {
                    *p = '\0';
                }
                if (i == 0) {
                    dictionary[keys_counter] = NULL;
                    dictionary[keys_counter] = malloc(sizeof(dictionaryNode));
                    if (dictionary[keys_counter] != NULL) {
                        dictionary[keys_counter]->key = NULL;
                        dictionary[keys_counter]->key = malloc(sizeof(char) * (strlen(words[i]) + 1));
                        if (dictionary[keys_counter]->key == NULL) {
                            printf("Error allocating memory in: %d", i);
                            exit(-1);
                        }
                        strcpy(dictionary[keys_counter]->key, words[i]);
                        dictionary[keys_counter]->key[strlen(words[i])] = 0;
                        free(words[i]);
                        dictionary[keys_counter]->numOfSynonyms = word_in_line - 1;
                        dictionary[keys_counter]->synonyms = NULL;
                        dictionary[keys_counter]->synonyms = malloc(sizeof(char *) * (word_in_line - 1));
                        if (dictionary[keys_counter]->synonyms == NULL) {
                            printf("Error allocating memory in: %d", i);
                            exit(-1);
                        }
                    }
                } else {
                    dictionary[keys_counter]->synonyms[i - 1] = NULL;
                    dictionary[keys_counter]->synonyms[i - 1] =
                            malloc(sizeof(char) * (strlen(words[i]) + 1));
                    if (dictionary[keys_counter]->synonyms[i - 1] == NULL) {
                        printf("Error allocating memory in: %d", i - 1);
                        exit(-1);
                    }
                    strcpy(dictionary[keys_counter]->synonyms[i - 1], words[i]);
                    dictionary[keys_counter]->synonyms[i - 1][strlen(words[i])] = 0;
                    free(words[i]);
                }
            }
        }
        ++keys_counter;
        free(words);
    }
    free(line);
    return dictionary;
}

void freeDictionary(dictionaryNode **dictionary, int size) {
    for (int i = 0; i < size; ++i) {
        free(dictionary[i]->key);
        for (int j = 0; j < dictionary[i]->numOfSynonyms; ++j) {
            free(dictionary[i]->synonyms[j]);
        }
        free(dictionary[i]->synonyms);
        free(dictionary[i]);
    }
}

void printDictionary(dictionaryNode **dictionary, int size) {
    for (int i = 0; i < size; ++i) {
        printf("key: [%s] synonyms:", dictionary[i]->key);
        for (int j = 0; j < dictionary[i]->numOfSynonyms; ++j) {
            printf("[%s]", dictionary[i]->synonyms[j]);
        }
        printf("\n");
    }
}

void getMatchingWord(char *word, dictionaryNode **dictionary, int size) {
    int location;
    int max_number;
    int synonym_location;
    location = getWordLocation(word, dictionary, size);
    if (location != -1) {
        max_number = dictionary[location]->numOfSynonyms;
        synonym_location = rand() % (max_number);
        strcpy(word, dictionary[location]->synonyms[synonym_location]);
        word[strlen(dictionary[location]->synonyms[synonym_location])] = 0;
    }
}

int getWordLocation(char *word, dictionaryNode **dictionary, int size) {
    int first, last, middle;
    first = 0;
    last = size - 1;
    middle = (first + last) / 2;

    while (first <= last) {
        if (strcmp(dictionary[middle]->key, word) < 0) {
            first = middle + 1;
        } else if (strcmp(dictionary[middle]->key, word) == 0) {
            return (middle);
        } else
            last = middle - 1;
        middle = (first + last) / 2;
    }
    if (first > last) {
        return (-1);
    }
}
