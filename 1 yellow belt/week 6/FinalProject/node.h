#ifndef _NODES_H
#define _NODES_H

#include "date.h"
#include <string>
#include <memory>


enum class Comparison{
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};


class Node{
public:
    Node() {}
    virtual bool Evaluate(const Date&, const std::string&) const = 0;
};


class DateComparisonNode: public Node{
public:
    bool Evaluate(const Date&, const std::string&) const override;
    DateComparisonNode(const Comparison& cmp, const Date& date);
private:
    Date _date;
    Comparison _cmp;
};

class EventComparisonNode: public Node{
public:
    virtual bool Evaluate(const Date&, const std::string&) const override;
    EventComparisonNode(const Comparison& cmp, const std::string& value);
private:
    Comparison _cmp;
    std::string _event;
};



enum class LogicalOperation{
    Or,
    And
};

class LogicalOperationNode: public Node{
public:
    virtual bool Evaluate(const Date&, const std::string&) const;
    LogicalOperationNode(const LogicalOperation& logical_operation,
                         std::shared_ptr<const Node> left,
                         std::shared_ptr<const Node> right);
private:
    LogicalOperation _logical_operation;
    std::shared_ptr<const Node> _left, _right;
};


class EmptyNode: public Node{
    virtual bool Evaluate(const Date&, const std::string&) const;
};

#endif
