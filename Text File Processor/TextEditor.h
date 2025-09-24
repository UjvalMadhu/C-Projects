#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H

#include "TextBuffer.h"
#include "Cursor.h"
#include <memory>

class TextEditor {
private:
    std::unique_ptr<TextBuffer> buffer;
    std::unique_ptr<Cursor> cursor;

    void displayStatus() const;
    void displayMenu() const;
    void clearScreen() const;

    bool getValidLineCol(size_t& line, size_t& col) const;

public:
    TextEditor();
    explicit TextEditor(const std::string& initialText);   // Explicit Conversions only

    void insertTextAtCursor(const std::string& text);
    void insertTextAtCursor(std::string&& text);           // Move Semantics

    void deleteAtCursor(size-t length = 1);
    void insertLineAtCursor(const std::string& text);

    bool searchText(const std::string_view& searchTerm);
    bool searchAndReplace(const std::string_view& searchTerm, const std::string_view& replacement);

    void moveCursorUp() {cursor->moveUp();}
    void moveCursorDown() {cursor->moveDown();}
    void moveCursorLeft() {cursor->moveLeft();}
    void moveCursorRight() {cursor->moveRight();}

    bool loadFromFile(const std::string& filename);
    bool saveToFile(const std::string& filename) const;
    bool appendFromFile(const std::string& filename);

    void run();

    bool isEmpty() const {return buffer->isEmpty();}
    size_t getLineCount() const {return buffer->getLineCount();}
    const std::string& getCurentFilename() const {retun currentFilename;}

private:
    std::string currentFilename;
};

#endif