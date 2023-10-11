// SMI Parser
// Copyright (c) 2023 KMX Systems. All rights reserved.
#include <fstream>
#include <iomanip>
#include <iostream>
#include <kmx/smi/lexer.hpp>
#include <kmx/smi/rule.hpp>
#include <vector>

namespace kmx
{
    template <typename _Char = char>
    std::vector<_Char> read_file(const char* const file_name)
    {
        using namespace std;
        ifstream file(file_name, ios::in | ios::binary | ios::ate);
        if (file.is_open())
        {
            const auto file_size = file.tellg();
            file.seekg(0, ios::beg);
            std::vector<_Char> bytes(file_size);
            file.read(reinterpret_cast<char*>(bytes.data()), file_size);
            return bytes;
        }

        return {};
    }
}

int main(const int argc, const char* const argv[])
{
    using namespace std;

    if (argc < 2)
    {
        cerr << "input MIB file not specified\n";
        return -1;
    }

    const auto mib_data = kmx::read_file(argv[1u]);
    if (!mib_data.empty())
    {
        using namespace kmx::smi;
        const text_view_t mib_data_view {mib_data.data(), mib_data.size()};

        vector<token::id> tokens {};
        tokens.reserve(5000u);
        for (lexer lexer(mib_data_view); lexer; ++lexer)
        {
            auto& token = lexer.token();
            tokens.push_back(token.id());
            cout << token << endl;
        }

        auto iter = tokens.cbegin();
        auto result = parse1(iter, tokens.cend());
        cout << "parse: " << result << endl;
    }
    else
    {
        cout << "MIB file not found\n";
    }

    return 0;
}
