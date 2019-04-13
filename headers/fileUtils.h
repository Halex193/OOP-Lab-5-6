#ifndef LAB5_6_FILEUTILS_H
#define LAB5_6_FILEUTILS_H

#include <string>
#include <vector>

enum class CSVState
{
    UnquotedField,
    QuotedField,
    QuotedQuote
};

std::vector<std::string> readCSVRow(const std::string &row);

#endif //LAB5_6_FILEUTILS_H
