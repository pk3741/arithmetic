#include <iostream>
#include <string>
#include <vector>
#include <utility>

int main()
{
	std::string alf;
	std::vector<float>prob;

	std::cout << "Podaj alfabet: ";
	std::cin >> alf;
	std::cout << "Podaj prawdopodobienstwa: \n";
	for (size_t i = 0; i < alf.size(); i++)
	{
		float probx = 0.0;
		std::cout << alf[i] << ": ";
		std::cin >> probx;
		prob.push_back(probx);

	}

	std::vector<std::pair<float, float>> ranges;
	std::vector<std::pair<float, float>> rangesnew;
	float l = 0, r = 0;
	for (size_t i = 0; i < prob.size(); i++)
	{
		r = l + prob[i];
		ranges.push_back(std::pair<float, float>(l, r));
		l = r;
	}

	for (size_t i = 0; i < ranges.size(); i++)
	{
		std::cout << ranges[i].first << " " << ranges[i].second << std::endl;
	}
	std::cout << "\n";

	for (size_t i = 0; i < ranges.size(); i++)
	{
		float start = ranges[i].first;
		float end = ranges[i].second;
		float R = end - start;
		std::cout << "R: " << R << std::endl;
		float substart = start;
		for (size_t j = 0; j < ranges.size(); j++)
		{
			ranges[j].first = substart;
			ranges[j].second = substart + prob[j] * R;
			substart = ranges[j].second;
		}


		for (size_t i = 0; i < ranges.size(); i++)
		{
			std::cout << ranges[i].first << " " << ranges[i].second << std::endl;
		}
		std::cout << "\n";
	}

	std::cout << "Encoded: " << (ranges.front().first + ranges.back().second) / 2 << std::endl;
	std::cout << "Encoded range: [" << ranges.front().first << "; " << ranges.back().second << "]" << std::endl;









}


