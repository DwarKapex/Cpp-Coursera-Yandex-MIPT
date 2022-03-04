#ifndef _CONDITION_PARSER_H
#define _CONDITION_PARSER_H
#pragma once

#include <memory>
#include <iostream>

#include "node.h"


std::shared_ptr<Node> ParseCondition(std::istream& is);

void TestParseCondition();
#endif
