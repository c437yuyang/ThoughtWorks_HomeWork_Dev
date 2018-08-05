#include <iostream>
#include <string>
#include <cstdio>
#include "RenderFactory.h"

int main(int argc, char*argv[])
{
	//if(argc < 3 || argc > 4)
	//{
	//    printf("Usage: %s <rows> <cols> \"[joints]\"\n",argv[0]);
	//    printf("Example: %s 4 4 \"-0,1 0,2;0,0 1,0;0,1 1,1;0,2 1,2;1,0 1,1;1,1 1,2;1,1 2,1;1,2 2,2;2,0 2,1\"\n",argv[0]);
	//    exit(EXIT_FAILURE);
	//}

	//int rows = std::atoi(argv[1]), cols = std::atoi(argv[2]);
	//if (argc > 3)
		//inpust = std::string(argv[3]);

	int rows = 4, cols = 4;
	//std::string input = "0,1 0,2;0,0 1,0;0,1 1,1;0,2 1,2;1,0 1,1;1,1 1,2;1,1 2,1;1,2 2,2;2,0 2,1";
	std::string input = "0,1 1,0";

	auto render = RenderFactory::getRender();
	std::string maze = render->doRender(rows, cols, input);
	std::cout << maze << std::endl;

	return 0;
}
