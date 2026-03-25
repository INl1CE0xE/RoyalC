# 👑 ROCC Compiler

**A lightweight RoyalC compiler** that transforms `.rocc` source files into structured token streams via a custom lexer. Supports basic syntax including variables (`let`), output (`print`), arithmetic operations (`+ - * /`), and control flow. Designed for simplicity and extensibility.

## 🚀 Quick Start

### Prerequisites
- C++17 compiler (g++ 7.0+)

### Example `test.rocc`
```rocc
let x = 42;
let y = x + 10;
print y;
```

## 🏗️ Architecture

```
.rocc → Lexer → Tokens → Parser → AST → Codegen
├── File.h/cpp     # File handling (.rocc validation)
├── Token.h        # Token types & structure  
├── Lexer.h/cpp    # Tokenizes source → Token stream
├── main.cpp       # Entry point
└── README.md
```

## 📋 Token Types

```
LET, PRINT, ID, NUMBER, PLUS, MINUS, STAR, SLASH
ASSIGN, SEMICOLON, LPAREN, RPAREN, INVALID, END_OF_FILE
```

## 🛠️ Features
- ✅ Custom `.rocc` file validation
- ✅ Lexical analysis (numbers, identifiers, keywords)
- ✅ Position tracking (line:column)
- ✅ Move semantics for File class
- ✅ Header guards (`#pragma once`)
- ✅ RAII resource management

## 🔮 Roadmap
- [ ] Parser (AST generation)
- [ ] Semantic analysis
- [ ] Bytecode generation  
- [ ] VM interpreter
- [ ] Native code backend

## 📄 License
MIT License - see [LICENSE](LICENSE) file for details.

---

**Built with ❤️ for learning compiler construction**
