#ifndef CURSOR_H
#define CURSOR_H

#include "TextBuffer.h"

class Cursor {
    private:
        size_t currentLine;
        size_t currentCol;
        const TextBuffer* buffer;

    public:
        explicit Cursor(const TextBuffer* textBuffer);

        bool moveUp();
        bool moveDown();
        bool moveLeft();
        bool moveRight();
        bool moveToStartOfLine();
        bool moveToEndOfLine();
        bool moveTo(size_t line, size_t col);

        size_t getLine() const { return currentLine; }
        size_t getCol() const { return currentCol; }
        std::pair<size_t, size_t> getPosition() const {return currentLine, currentCol; }

        bool isValidPosition() const;

        void updateBuffer(const TextBuffer* newBuffer) {buffer = newBuffer; }
};

#endif