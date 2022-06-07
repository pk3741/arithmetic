#include <iostream>
#include <string>
#include <vector>
#include <utility>

struct Probability
{
public:
	char letter;
	float l;
	float r;
	Probability() : letter('\0'), l(0), r(0) {}
	Probability(char nletter, float nl, float nr) : letter(nletter), l(nl), r(nr) {}
};

Probability getRangeForLetter(char letter, std::vector<Probability> &prob)
{
	for (size_t i = 0; i < prob.size(); i++)
	{
		if (prob[i].letter == letter)
		{
			return prob[i];
		}
	}
	return Probability('x', 9999, 9999);
}

Probability getRangeForNumber(float number, std::vector<Probability>& prob)
{
	for (size_t i = 0; i < prob.size(); i++)
	{
		if (prob[i].l <= number && prob[i].r > number)
			return prob[i];
	}
	return Probability('x', 9999, 9999);
}

int main()
{
	int choose = 0;
	std::cout << "Kodujemy(0) czy dekodujemy(1)?: ";
	std::cin >> choose;
	
	if (choose==0)
	{
		// ABCD, ABBC, 0.4 0.3 0.1 0.2 - 0.2332,02368
		std::string message;
		std::cout << "Podaj wiadomosc: ";
		std::cin >> message;
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

		float l = 0, r = 0;
		std::vector<Probability> ranges;
		std::cout << "\n";
		for (size_t i = 0; i < prob.size(); i++)
		{
			r = l + prob[i];
			Probability n1;
			n1.l = l;
			n1.r = r;
			n1.letter = alf[i];
			ranges.push_back(n1);
			std::cout << n1.letter << ": [" << n1.l << ";" << n1.r << "]" << std::endl;
			l = r;
		}
		std::cout << "\n\n";

		for (size_t i = 0; i < message.size(); i++)
		{
			std::cout << "--------------------------------------------\n";
			std::cout << "Kodowany symbol: " << message[i] << std::endl;
			Probability actualRange = getRangeForLetter(message[i], ranges);
			std::vector<Probability> newRanges;
			std::cout << "rangessize: " << ranges.size() << std::endl;

			float l = actualRange.l;
			float r = actualRange.r;
			std::cout << "Zaczynajac od: " << l << " " << r << std::endl;
			float range = r - l;
			std::cout << "Range: " << range << std::endl;

			for (int j = 0; j < prob.size(); j++)
			{
				r = l + range * prob[j];
				std::cout << ranges[j].letter << " " << l << " " << r << std::endl;
				Probability newProb;
				newProb.r = r;
				newProb.l = l;
				newProb.letter = ranges[j].letter;
				newRanges.push_back(newProb);
				l = r;
			}
			ranges = newRanges;
		}

		std::cout << "\nWynik: [" << ranges.front().l << ";" << ranges.back().r << "]" << std::endl;
	}
	else if (choose == 1)
	{
		// ABCD, ABBC, 0.4 0.3 0.1 0.2 - 0.2332,02368
		std::string message = "";
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
		int length = 0;
		std::cout << "Podaj dlugosc komunikatu: ";
		std::cin >> length;

		float xka = 0;
		std::cout << "Podaj liczbe dekodujaca: \n";
		std::cin >> xka;

		float l = 0, r = 0;
		std::vector<Probability> ranges;
		std::cout << "\n";
		for (size_t i = 0; i < prob.size(); i++)
		{
			r = l + prob[i];
			Probability n1;
			n1.l = l;
			n1.r = r;
			n1.letter = alf[i];
			ranges.push_back(n1);
			std::cout << n1.letter << ": [" << n1.l << ";" << n1.r << "]" << std::endl;
			l = r;
		}

		std::string output = "";

		Probability n1;
		for (int i = 0; i < length; i++)
		{
			n1 = getRangeForNumber(xka, ranges);
			output += n1.letter;
			std::vector<Probability> newRanges;
			float l = n1.l;
			float r = n1.r;
			float range = r - l;

			for (int j = 0; j < prob.size(); j++)
			{
				r = l + range * prob[j];
				std::cout << ranges[j].letter << " " << l << " " << r << std::endl;
				Probability newProb;
				newProb.r = r;
				newProb.l = l;
				newProb.letter = ranges[j].letter;
				newRanges.push_back(newProb);
				l = r;
			}
			ranges = newRanges;
		}
		std::cout << "Output: " << output << std::endl;
		
		

	}


}