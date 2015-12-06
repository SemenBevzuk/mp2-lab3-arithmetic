#pragma once
#include "parser.h"
#include "corrector.h"
#include "switch.h"
#include "stack.h"
#include "reverse_polish_notation.h"
#include "aggregate.h"

class Calculator
{
public:
	double Calculate(string input);
};