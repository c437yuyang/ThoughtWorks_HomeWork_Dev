#include <iostream>
#include <string>
#include <cstdio>
#include "RenderFactory.h"
int main(int argc, char*argv[])
{
	//if (argc < 3 || argc > 5)
	//{
	//	printf("Usage: %s <rows> <cols> \"[joints]\" \"[Initial Position]\"\n", argv[0]);
	//	printf("Example: %s 4 4 \"-0,1 0,2;0,0 1,0;0,1 1,1;0,2 1,2;1,0 1,1;1,1 1,2;1,1 2,1;1,2 2,2;2,0 2,1\"\n", argv[0]);
	//	exit(EXIT_FAILURE);
	//}
	//std::string command = "";
	//std::string initPos = "";
	//int rows = std::atoi(argv[1]), cols = std::atoi(argv[2]);
	//if (argc > 3)
	//	command = std::string(argv[3]);
	//if (argc > 4)
	//	initPos = std::string(argv[4]);

	int rows = 4, cols = 4;
	std::string command = "0,1 0,2;0,0 1,0;0,1 1,1;0,2 1,2;1,0 1,1;1,1 1,2;1,1 2,1;1,2 2,2;2,0 2,1";
	std::string initPos = "1,0 DDS";
	//std::string input = "0,1 1,0";

	//input = "";
	//std::cin >> rows >> cols;
	//std::string tmp;
	//while (std::cin >> tmp)
	//{
	//	if (input == "")
	//		input += tmp;
	//	else 
	//		input += " " + tmp;
	//}




	auto render = RenderFactory::getRender();
	std::string maze = render->doRender(rows, cols, command,initPos);
	std::cout << maze << std::endl;




	return 0;
}
