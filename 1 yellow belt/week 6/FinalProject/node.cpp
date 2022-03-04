//
//  nodes.cpp
//  final_project
//
//  Created by Vladislav Kozlov on 6/27/19.
//  Copyright © 2019 Vladislav Kozlov. All rights reserved.
//

#include <string>
#include <memory>
#include "node.h"
#include "date.h"


DateComparisonNode::DateComparisonNode(const Comparison& cmp, const Date& date): _cmp(cmp), _date(date) {}

bool DateComparisonNode::Evaluate(const Date& date, const std::string& event) const{
    switch(_cmp){
        case Comparison::Less:
            return date < _date;
        case Comparison::LessOrEqual:
            return date <= _date;
        case Comparison::Greater:
            return date > _date;
        case Comparison::GreaterOrEqual:
            return date >= _date;
        case Comparison::Equal:
            return date == _date;
        case Comparison::NotEqual:
            return date != _date;
    }
}


EventComparisonNode::EventComparisonNode(const Comparison& cmp, const std::string& event):
    _cmp(cmp), _event(event) {}

bool EventComparisonNode::Evaluate(const Date& date, const std::string& event) const{
    switch(_cmp){
        case Comparison::Less:
            return event < _event;
        case Comparison::LessOrEqual:
            return event <= _event;
        case Comparison::Greater:
            return event > _event;
        case Comparison::GreaterOrEqual:
            return event >= _event;
        case Comparison::Equal:
            return event == _event;
        case Comparison::NotEqual:
            return event != _event;
    }
}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation& logical_operation,
                                           std::shared_ptr<const Node> left,
                                           std::shared_ptr<const Node> right):
_logical_operation(logical_operation), _left(left), _right(right) {
    
}

bool LogicalOperationNode::Evaluate(const Date& date, const std::string& event) const {
    switch (_logical_operation) {
        case LogicalOperation::Or:
            return _left->Evaluate(date, event) || _right->Evaluate(date, event);
        case LogicalOperation::And:
            return _left->Evaluate(date, event) && _right->Evaluate(date, event);
    }
}

bool EmptyNode::Evaluate(const Date& date, const std::string& event) const { return true; }


