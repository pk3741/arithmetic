#include <iostream>
#include <string>
#include <vector>
#include <utility>

int main()
{
	std::string alf;
	std::vector<float>prob;

	std::cout << "Alphabet: ";
	std::cin >> alf;
	std::cout << "Probabilities: \n";
	for (size_t i = 0; i < alf.size(); i++)
	{
		float probx = 0.0;
		std::cout << alf[i] << ": ";
		std::cin >> probx;
		prob.push_back(probx);

	}
	int choose = 0;
	std::cout << "\nEncoding(0) or decoding(1): ";
	std::cin >> choose;

	std::vector<std::pair<float, float>> ranges;
	std::vector<std::pair<float, float>> rangesnew;
	float l = 0, r = 0;
	for (size_t i = 0; i < prob.size(); i++)
	{
		r = l + prob[i];
		ranges.push_back(std::pair<float, float>(l, r));
		l = r;
	}

	if (choose == 0)
	{

		std::cout << "Initial ranges: " << std::endl;
		for (size_t i = 0; i < ranges.size(); i++)
		{
			std::cout << "subrange " << i << ": [" << ranges[i].first << ";" << ranges[i].second << "]" << std::endl;
		}
		std::cout << "\n";
		// Encoding
		for (size_t i = 0; i < ranges.size(); i++)
		{
			std::cout << "Step: " << i << std::endl;
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
				std::cout << "subrange " << i << ": [" << ranges[i].first << ";" << ranges[i].second << "]" << std::endl;
			}

			std::cout << "\n";
		}

		std::cout << "Encoded: " << (ranges.front().first + ranges.back().second) / 2 << std::endl;
		std::cout << "Encoded range: [" << ranges.front().first << "; " << ranges.back().second << "]" << std::endl;
	}
	else if (choose == 1)
	{
		std::string decoded;
		float value = 0;
		std::cout << "Value: ";
		std::cin >> value;
		// Encoding

		std::cout << "Initial ranges: " << std::endl;
		for (size_t i = 0; i < ranges.size(); i++)
		{
			std::cout << "subrange " << i << ": [" << ranges[i].first << ";" << ranges[i].second << "]" << std::endl;
		}
		std::cout << "\n";
		for (size_t i = 0; i < ranges.size(); i++)
		{
			std::cout << "Step: " << i << std::endl;
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
				std::cout << "subrange " << i << ": [" << ranges[i].first << ";" << ranges[i].second << "]" << std::endl;
			}
			if ((ranges.front().first < value) && (value < ranges.back().second))
			{
				std::cout << "Value " << value << " falls within " << ranges.front().first << ":" << ranges.back().second << " and '" << alf[i] << "' appears in decoded message" << std::endl;
				decoded += alf[i];
			}
			else
			{
				std::cout << "Value " << value << " not falls within " << ranges.front().first << ":" << ranges.back().second << " and no letter appears in decoded message" << std::endl;
			}

			std::cout << "\n";
		}
		std::cout << "Decoded message: " << decoded << std::endl;

	}
}


