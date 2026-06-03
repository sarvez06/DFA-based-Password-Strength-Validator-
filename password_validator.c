#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

// ================= COLOR FUNCTION =================
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// ================= CYBER BANNER =================
void printBanner() {

    setColor(10);

    printf("=============================================================\n");
    printf("  ████████╗ ██████╗  ██████╗ \n");
    printf("  ╚══██╔══╝██╔═══██╗██╔════╝ \n");
    printf("     ██║   ██║   ██║██║      \n");
    printf("     ██║   ██║   ██║██║      \n");
    printf("     ██║   ╚██████╔╝╚██████╗ \n");
    printf("     ╚═╝    ╚═════╝  ╚═════╝ \n");
    printf("=============================================================\n");

    setColor(11);
    printf("      >>> PASSWORD STRENGTH VALIDATOR USING DFA <<<\n");
    printf("=============================================================\n\n");

    setColor(7);
}

// ================= PROFESSIONAL PROGRESS BAR =================
void printProgressBar(int score) {

    int totalBlocks = 20;
    int filled = (score * totalBlocks) / 100;

    printf("\nStrength Meter: [");

    if(score >= 80)
        setColor(10);
    else if(score >= 60)
        setColor(14);
    else
        setColor(12);

    for(int i = 0; i < filled; i++) {
        printf("=");
        fflush(stdout);
        Sleep(25);
    }

    setColor(7);

    for(int i = filled; i < totalBlocks; i++) {
        printf(" ");
    }

    printf("] %d%%\n", score);
}

// ================= PASSWORD SCORE =================
int analyzePassword(char password[],
                    int *hasUpper,
                    int *hasLower,
                    int *hasDigit,
                    int *hasSpecial) {

    int length = strlen(password);

    *hasUpper = 0;
    *hasLower = 0;
    *hasDigit = 0;
    *hasSpecial = 0;

    for(int i = 0; i < length; i++) {

        if(isupper(password[i])) *hasUpper = 1;
        else if(islower(password[i])) *hasLower = 1;
        else if(isdigit(password[i])) *hasDigit = 1;
        else *hasSpecial = 1;
    }

    int score = 0;

    if(length >= 8) score += 25;
    if(*hasUpper) score += 20;
    if(*hasLower) score += 20;
    if(*hasDigit) score += 20;
    if(*hasSpecial) score += 15;

    return score;
}

// ================= DFA TRANSITION DIAGRAM =================

int isSpecial(char c) {
    return !(isalnum(c));
}

const char* stateName(int s) {
    static const char *names[] = {
        "q0","q1","q2","q3","q4","q5","q6","q7",
        "q8","q9","q10","q11","q12","q13","q14","q15"
    };
    return names[s];
}

void generateDFADiagram(char pwd[]) {

    int state = 0;
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    FILE *dot = fopen("dfa.dot", "w");

    fprintf(dot, "digraph DFA {\n");
    fprintf(dot, "rankdir=LR;\n");
    fprintf(dot, "node [shape=circle, style=filled, fillcolor=white];\n");

    for (int i = 0; pwd[i]; i++) {

        char c = pwd[i];
        int prev = state;
        int bit = 0;

        if (isupper(c)) { hasUpper = 1; bit = 8; }
        else if (islower(c)) { hasLower = 1; bit = 4; }
        else if (isdigit(c)) { hasDigit = 1; bit = 2; }
        else if (isSpecial(c)) { hasSpecial = 1; bit = 1; }

        state = state | bit;

        fprintf(dot, "%s -> %s [label=\"%c\"];\n",
                stateName(prev), stateName(state), c);
    }

    int types = hasUpper + hasLower + hasDigit + hasSpecial;
    char color[20];
    char strength[50];

    if (types <= 2) {
        strcpy(strength, "WEAK");
        strcpy(color, "red");
    }
    else if (types == 3) {
        strcpy(strength, "SECURE");
        strcpy(color, "yellow");
    }
    else if (types == 4 && strlen(pwd) >= 8) {
        strcpy(strength, "MILITARY GRADE");
        strcpy(color, "green");
    }
    else {
        strcpy(strength, "SECURE");
        strcpy(color, "yellow");
    }

    fprintf(dot, "%s [shape=doublecircle, fillcolor=%s];\n",
            stateName(state), color);

    fprintf(dot, "label=\"Password Strength: %s\";\n", strength);
    fprintf(dot, "labelloc=top;\n");
    fprintf(dot, "fontsize=20;\n");

    fprintf(dot, "}\n");
    fclose(dot);

    system("dot -Tpng dfa.dot -o dfa.png");
}

// ================= OPEN DFA IMAGE =================
void showDFADiagram() {
    printf("\nOpening DFA Diagram...\n");
    system("start dfa.png");
}

// ================= MAIN =================
int main() {

    char password[MAX];
    int score;
    int hasUpper, hasLower, hasDigit, hasSpecial;

    system("chcp 65001 > nul");

    printBanner();

    setColor(11);
    printf("Enter Password to Analyze: ");
    setColor(7);
    scanf("%s", password);

    score = analyzePassword(password,
                            &hasUpper,
                            &hasLower,
                            &hasDigit,
                            &hasSpecial);

    printProgressBar(score);

    printf("\n");

    if(score < 60) {
        setColor(12);
        printf("Result: WEAK ❌\n");
    }
    else if(score < 85) {
        setColor(14);
        printf("Result: SECURE 🔐\n");
    }
    else {
        setColor(10);
        printf("Result: MILITARY GRADE 🚀\n");
    }

    setColor(7);

    // ===== SUGGESTIONS =====
    printf("\nSuggestions to Improve Password:\n");

    int suggestion = 0;

    if(!hasUpper) {
        printf("- Add at least one uppercase letter\n");
        suggestion = 1;
    }
    if(!hasLower) {
        printf("- Add at least one lowercase letter\n");
        suggestion = 1;
    }
    if(!hasDigit) {
        printf("- Add at least one digit\n");
        suggestion = 1;
    }
    if(!hasSpecial) {
        printf("- Add at least one special character\n");
        suggestion = 1;
    }
    if(strlen(password) < 8) {
        printf("- Increase length to at least 8 characters\n");
        suggestion = 1;
    }

    if(!suggestion) {
        printf("No improvements needed. Excellent password! 🔥\n");
    }

    generateDFADiagram(password);
    showDFADiagram();

    return 0;
}
