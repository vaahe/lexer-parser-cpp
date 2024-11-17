#ifndef NODES_HPP
#define NODES_HPP

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

enum TokenType
{
    T_INT,
    T_FLOAT,
    T_BOOL,
    T_STRING,
    T_IDENTIFIER,
    T_NUMBER,
    T_FLOAT_NUMBER,
    T_STRING_LITERAL,
    T_PLUS,
    T_MINUS,
    T_TIMES,
    T_DIVIDE,
    T_EQUALS,
    T_LPAREN,
    T_RPAREN,
    T_LBRACE,
    T_RBRACE,
    T_SEMICOLON,
    T_COMMA,
    T_IF,
    T_RETURN,
    T_EQ,
    T_NEQ,
    T_LT,
    T_GT,
    T_LE,
    T_GE,
    T_EOF,
    T_UNKNOWN
};

struct Node
{
    virtual ~Node() = default;
};

struct Program : Node
{
    std::vector<std::unique_ptr<Node>> statements;
};

struct VariableDeclaration : Node
{
    std::string type;
    std::string identifier;
    std::unique_ptr<Node> expression;

    VariableDeclaration(const std::string &type, const std::string &identifier, std::unique_ptr<Node> expr)
        : type(type), identifier(identifier), expression(std::move(expr)) {}
};

struct FunctionDeclaration : Node
{
    std::string returnType;
    std::string identifier;
    std::vector<std::pair<std::string, std::string>> parameters;
    std::vector<std::unique_ptr<Node>> body;
};

struct IfStatement : Node
{
    std::unique_ptr<Node> condition;
    std::vector<std::unique_ptr<Node>> body;

    IfStatement(std::unique_ptr<Node> condition, std::vector<std::unique_ptr<Node>>&& body)
        : condition(std::move(condition)), body(std::move(body)) {}
};

struct ReturnStatement : Node
{
    std::unique_ptr<Node> expression;

    ReturnStatement(std::unique_ptr<Node> expr)
        : expression(std::move(expr)) {}
};

struct Expression : Node
{
};

struct BinaryOperation : Node
{
    std::unique_ptr<Expression> left;
    std::string op;
    std::unique_ptr<Expression> right;

    BinaryOperation(std::unique_ptr<Expression> l, std::string o, std::unique_ptr<Expression> r)
        : left(std::move(l)), op(std::move(o)), right(std::move(r)) {}
};

struct Literal : Expression
{
    std::string value;
    std::string type;

    Literal(const std::string &v, const std::string &t)
        : value(v), type(t) {}
};

struct Identifier : Expression
{
    std::string name;
};

struct FunctionCall : Expression
{
    std::string name;
    std::vector<std::unique_ptr<Expression>> arguments;
};

bool isNumericType(const std::string &type);
std::string getNodeType(Node *node, const std::unordered_map<std::string, std::string> &symbolTable);

#endif // NODES_HPP
