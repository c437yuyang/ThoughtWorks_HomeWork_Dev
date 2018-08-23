#pragma once
#include <string>
#include <vector>
#include "OutputFormat.h"
#include "CharSet.h"
#include "CellType.h"
class OutputFormatImpl :public OutputFormat
{
public:
	std::string output(const std::vector<std::vector<int>>& mat) override
	{
		int m = mat.size();
		int n = mat[0].size();
		std::string res;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				res += '[';
				res += mat[i][j] == CellType::WALL ? CharSet::WALL : 
					(mat[i][j] == CellType::ROAD ? CharSet::ROAD : CharSet::ROTOBPOS);
				res += ']';
				if (j != n - 1)
					res += ' ';
			}
			if (i != m - 1)
				res += '\n';
		}
		return res;
	}
};