#ifndef TEXT_BUFFER_H
#define TEXT_BUFFER_H

#include <deque>
#include <string>
#include <string_view>
#include <memory>

class TextBuffer {
    private:
        std::deque<std::string> lines;
        size_t totalSize;

        void updateTotalSize();
        bool isValidPosition(size_t lineNum, size_t colNum) const;

    public:
        TextBuffer();
        explicit TextBuffer(const std::string& initialText);

        void insertLine(size_t position, const std::string& text);
        void insertText(size_t lineNum, size_t colNum, const std::string& text);
        void insertText(size_t lineNum, size_t colNum, std::string&& text);

        bool deleteLine(size_t lineNum);
        bool deleteText(size_t lineNum, size_t colNum, size_t length);

        const std::string& getLine(size_t lineNum) const;
        std::string& getLineRef(size_t lineNum);

        char* findText(const std::string_view& searchTerm, size_t& foundLine, size_t& foundCol);
        const char* findTextConst(const std::string_view& searchTerm, size_t& foundLine, size_t& foundCol) const;

        size_t getLineCount() const { return lines.size(); }
        size_t getTotalSize() const { return totalSize; }
        size_t getLineLength(size_t lineNum) const;
        bool isEmpty() const { return lines.empty(); }

        void resesrveLines(size_t capacity);
        void clear();

        void displayBuffer() const;
};

#endif