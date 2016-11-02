#include "stdafx.h"
#include <map>
#include <string>
#include "Decode.h"
#include "ReplaceSubString.h"

using namespace std;

string Decode(const string &inputLine, map<string, string> dictionary)
{
	string result(inputLine);
	for (auto currentPair : dictionary)
		ReplaceSubString(result, currentPair.first, currentPair.second);
	return result;
}