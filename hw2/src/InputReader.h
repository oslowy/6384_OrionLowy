#pragma once

#include "ArrivalTimeline.h"
#include <fstream>

using namespace std;

class InputReader {
public:
		void extractArrivalTimeline(ifstream inputFile, ArrivalTimeline &arrivalTimeline);
};