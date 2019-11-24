#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>

const std::string VALUE_CAPTION = " value: ";
const std::string ADDRESS_CAPTION = " address: ";
const std::string PARENT_VALUE_CAPTION = " parent value: ";
const std::string PARENT_ADDRESS_CAPTION = " parent address: ";

struct TYPE {
	const std::string INT = "INT";
	const std::string DOUBLE = "DOUBLE";
	const std::string FLOAT = "FLOAT";
	const std::string STRING = "STRING";
	const std::string CHAR = "CHAR";
	const std::string UNKNOWN = "UNKNOWN";
};

const TYPE TEMPLATE_TYPES;

