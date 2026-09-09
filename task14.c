#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#define MAX_HISTORY 100
#define BUF_SIZE 1024

char history[MAX_HISTORY][BUF_SIZE];
int history_count = 0;

static struct termios old_termios, new_termios;

void enable_raw_mode() {
    tcgetattr(STDIN_FILENO, &old_termios);
    new_termios = old_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
}

void disable_raw_mode() {
    tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);
}

int main() {
    char buf[BUF_SIZE];
    int pos = 0;
    int history_index = history_count;

    printf("Interactive Shell with History Support. Type 'exit' to quit.\n");

    while (1) {
        printf("myshell> ");
        fflush(stdout);

        pos = 0;
        buf[0] = '\0';
        history_index = history_count;

        enable_raw_mode();

        while (1) {
            char c;
            if (read(STDIN_FILENO, &c, 1) <= 0) break;

            if (c == '\n') { // Enter Key
                buf[pos] = '\0';
                printf("\n");
                break;
            } else if (c == 127 || c == 8) { // Backspace
                if (pos > 0) {
                    pos--;
                    buf[pos] = '\0';
                    printf("\b \b");
                    fflush(stdout);
                }
            } else if (c == 27) { // Escape Sequences (Arrows)
                char seq[2];
                if (read(STDIN_FILENO, &seq[0], 1) > 0 && read(STDIN_FILENO, &seq[1], 1) > 0) {
                    if (seq[0] == '[') {
                        if (seq[1] == 'A') { // Up Arrow
                            if (history_index > 0) {
                                history_index--;
                                while (pos > 0) { printf("\b \b"); pos--; }
                                strcpy(buf, history[history_index]);
                                pos = strlen(buf);
                                printf("%s", buf);
                                fflush(stdout);
                            }
                        } else if (seq[1] == 'B') { // Down Arrow
                            if (history_index < history_count) {
                                history_index++;
                                while (pos > 0) { printf("\b \b"); pos--; }
                                if (history_index < history_count) {
                                    strcpy(buf, history[history_index]);
                                } else {
                                    buf[0] = '\0';
                                }
                                pos = strlen(buf);
                                printf("%s", buf);
                                fflush(stdout);
                            }
                        }
                    }
                }
            } else {
                if (pos < BUF_SIZE - 1) {
                    buf[pos++] = c;
                    buf[pos] = '\0';
                    printf("%c", c);
                    fflush(stdout);
                }
            }
        }

        disable_raw_mode();

        if (strcmp(buf, "exit") == 0) {
            printf("Exiting shell...\n");
            break;
        } else if (strcmp(buf, "history") == 0) {
            for (int i = 0; i < history_count; i++) {
                printf("%d: %s\n", i + 1, history[i]);
            }
        } else if (strlen(buf) > 0) {
            if (history_count < MAX_HISTORY) {
                strcpy(history[history_count++], buf);
            }
            printf("Executed: %s\n", buf);
        }
    }

    return 0;
}
