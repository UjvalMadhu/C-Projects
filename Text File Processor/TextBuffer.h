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

        

}