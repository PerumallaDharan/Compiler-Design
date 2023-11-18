#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Parser {
    char* expression;
    int index;
};

void initParser(struct Parser* parser, char* input) {
    parser->expression = input;
    parser->index = 0;
}

int parseE(struct Parser* parser);
int parseE_prime(struct Parser* parser);
int parseT(struct Parser* parser);
int parseT_prime(struct Parser* parser);
int parseF(struct Parser* parser);

int match(struct Parser* parser, char token) {
    if (parser->expression[parser->index] == token) {
        parser->index++;
        return 1;
    }
    return 0;
}

int parseE(struct Parser* parser) {
    if (parseT(parser) && parseE_prime(parser)) {
        return 1;
    }
    return 0;
}

int parseE_prime(struct Parser* parser) {
    if (parser->expression[parser->index] == '+') {
        parser->index++;
        if (parseT(parser) && parseE_prime(parser)) {
            return 1;
        }
        return 0;
    }
    return 1;  // E' can be epsilon
}

int parseT(struct Parser* parser) {
    if (parseF(parser) && parseT_prime(parser)) {
        return 1;
    }
    return 0;
}

int parseT_prime(struct Parser* parser) {
    if (parser->expression[parser->index] == '*') {
        parser->index++;
        if (parseF(parser) && parseT_prime(parser)) {
            return 1;
        }
        return 0;
    }
    return 1;  // T' can be epsilon
}

int parseF(struct Parser* parser) {
    if (parser->expression[parser->index] == '(') {
        parser->index++;
        if (parseE(parser) && parser->expression[parser->index] == ')') {
            parser->index++;
            return 1;
        }
    } else if (isalpha(parser->expression[parser->index])) {
        parser->index++;
        return 1;
    }
    return 0;
}

int parse(struct Parser* parser) {
    return parseE(parser) && parser->expression[parser->index] == '\0';
}

int main() {
    char input[100];
    struct Parser parser;

    while (1) {
        printf("Enter an expression:\n");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        // Remove the newline character from input
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        if (strlen(input) == 0) {
            break;  // Exit when an empty line is entered
        }

        initParser(&parser, input);

        if (parse(&parser)) {
            printf("Parsing successful\n");
        } else {
            printf("Parsing failed\n");
        }
    }

    return 0;
}
