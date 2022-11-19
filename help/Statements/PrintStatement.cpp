#include "PrintStatement.h"

void PrintStatement::accept(Visitor* visitor) {
    visitor->visit(shared_from_this());
}

PrintStatement::PrintStatement(std::string format, bool new_line):
    format_string(std::move(format)), add_newline(new_line) {

}

PrintStatement::PrintStatement(std::string format, std::shared_ptr<ExpressionList> subs, bool new_line):
    format_string(std::move(format)), substitutors(std::move(subs)), add_newline(new_line) {

}

const std::string PrintStatement::get_string() {
    return format_string;
}

std::shared_ptr<Expression> PrintStatement::get_substitution(size_t index) {
    return substitutors->get_expression(index);
}

size_t PrintStatement::subs_number() {
    return substitutors->subs_number();
}

bool PrintStatement::newline() {
    return add_newline;
}

std::string PrintStatement::remove_escape_chars(const std::string& string) {
//    \'	single quote	byte 0x27 in ASCII encoding
//    \"	double quote	byte 0x22 in ASCII encoding
//    \?	question mark	byte 0x3f in ASCII encoding
//    \\	backslash	byte 0x5c in ASCII encoding
//    \a	audible bell	byte 0x07 in ASCII encoding
//    \b	backspace	byte 0x08 in ASCII encoding
//    \f	form feed - new page	byte 0x0c in ASCII encoding
//    \n	line feed - new line	byte 0x0a in ASCII encoding
//    \r	carriage return	byte 0x0d in ASCII encoding
//    \t	horizontal tab	byte 0x09 in ASCII encoding
//    \v
    std::string result;
    auto it = string.begin();
    while (it != string.end()) {
        char c = *it++;
        if (c == '\\' && it != string.end()) {
            switch (*it++) {
                case '\'':
                    c = '\'';
                    break;
                case '\"':
                    c = '\"';
                    break;
                case '\?':
                    c = '\?';
                    break;
                case '\\':
                    c = '\\';
                    break;
                case 'a':
                    c = '\a';
                    break;
                case 'b':
                    c = '\b';
                    break;
                case 'f':
                    c = '\f';
                    break;
                case 'n':
                    c = '\n';
                    break;
                case 'r':
                    c = '\r';
                    break;
                case 't':
                    c = '\t';
                    break;
                case 'v':
                    c = '\v';
                    break;
                default:
                    continue;
            }
        }
        result += c;
    }

    return result;
}
PrintStatement::~PrintStatement() = default;
