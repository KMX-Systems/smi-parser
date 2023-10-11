import qbs

CppApplication {
    Depends { name: 'cpp' }
    consoleApplication: true
    cpp.cxxLanguageVersion: "c++23"
    cpp.includePaths: ["inc", "inc_dep"]
    //cpp.cxxFlags: "-fsanitize=address"
    //cpp.staticLibraries: "asan"
    files: [
        "inc/kmx/smi/lexer.hpp",
        "inc/kmx/smi/token.hpp",
        "src/kmx/smi/lexer.cpp",
        "main.cpp",
        "src/kmx/smi/token.cpp",
    ]

    Group {     // Properties for the produced executable
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}

