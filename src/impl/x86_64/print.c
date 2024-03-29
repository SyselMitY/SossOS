#include "print.h"

const static size_t NUM_COLS = 80;
const static size_t NUM_ROWS = 25;

struct Char
{
    uint8_t character;
    uint8_t color;
};

struct Char *buffer = (struct Char *)0xb8000;
size_t col = 0;
size_t row = 0;
uint8_t color = PRINT_COLOR_WHITE | PRINT_COLOR_BLACK << 4;

void clear_row(size_t row)
{
    struct Char empty;
    empty.character = ' ';
    empty.color = color;

    for (size_t curCol = 0; curCol < NUM_COLS; curCol++)
    {
        buffer[curCol + NUM_COLS * row] = empty;
    }
}

void print_clear()
{
    for (size_t i = 0; i < NUM_ROWS; i++)
    {
        clear_row(i);
    }
    col = 0;
    row = 0;
}

void print_newline()
{
    col = 0;

    if (row < NUM_ROWS - 1)
    {
        row++;
        return;
    }

    for (size_t row = 1; row < NUM_ROWS; row++)
    {
        for (size_t curCol = 0; curCol < NUM_COLS; curCol++) {
            struct Char character = buffer[curCol + NUM_COLS * row];
            buffer[curCol + NUM_COLS * (row - 1)] = character;
        }

    }

    clear_row(NUM_ROWS - 1);
}

void print_set_color(uint8_t fg, uint8_t bg)
{
    color = fg + (bg << 4);
}

void print_char(char character)
{
    if (character == '\n')
    {
        print_newline();
        return;
    }

    if (col > NUM_COLS)
    {
        print_newline();
    }

    buffer[col + NUM_COLS * row].character = (uint8_t)character;
    buffer[col + NUM_COLS * row].color = color;

    col++;
}

void print_num(uint64_t num)
{

    if (num == 0)
        print_char('0');

    char buf[256];
    buf[256] = '\0';
    int i;
    for (i = 0; i++, num > 0; num /= 10)
    {
        buf[256 - i - 1] = ('0' + num % 10);
    }
    print_str(buf + (256 - i));
}

void print_str(char *str)
{
    for (size_t i = 0; 1; i++)
    {
        char character = (uint8_t)str[i];

        if (character == '\0')
        {
            return;
        }

        print_char(character);
    }
}