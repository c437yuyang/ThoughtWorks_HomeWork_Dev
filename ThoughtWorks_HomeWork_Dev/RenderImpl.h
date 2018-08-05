#pragma once
#include <memory>
#include "Render.h"
#include "InputCheckFactory.h"
#include "OutputFormatFactory.h"
#include "StrAlgo.h"
#include "CLibsImpl.h"
#include "CellType.h"
class RenderImpl :public Render
{
public:
	std::string doRender(int rows, int cols, std::string& command, std::string&initPos) override
	{
		auto checker = InputCheckFactory::getInputChecker();
		checker->checkFormatAndExitIfNotValid(command);

		std::vector<std::vector<int>> mat(rows * 2 + 1, std::vector<int>(cols * 2 + 1, CellType::WALL));
		initMat(mat, rows, cols);
		if (command == "")
			return OutputFormatFactory::getFormatter()->output(mat);
		std::vector<std::string> joints = yxp_utility::StrAlgo::split(command, ';');
		for (int i = 0; i < joints.size(); ++i)
		{
			int row1, col1, row2, col2;
			parseJointsGetPoints(joints[i], row1, col1, row2, col2);
			checker->checkInputAndExitIfNotValid(row1, col1, row2, col2, rows, cols);
			connectJoints(mat, row1, col1, row2, col2);
		}
		int robotPosRow, robotPosCol;
		setRobotPos(mat, initPos, robotPosRow, robotPosCol);
		moveRobot(mat, initPos, robotPosRow, robotPosCol);

		return OutputFormatFactory::getFormatter()->output(mat);
	}
private:
	void initMat(std::vector<std::vector<int>> &mat, int rows, int cols)
	{
		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j)
				mat[i * 2 + 1][j * 2 + 1] = CellType::ROAD;
	}

	void parseJointsGetPoints(const std::string& joints,
		int& row1, int& col1, int& row2, int& col2)
	{
		std::vector<std::string> pts = yxp_utility::StrAlgo::split(joints, ' ');
		std::vector<std::string> pt = yxp_utility::StrAlgo::split(pts[0], ',');
		row1 = yxp_utility::atoi(pt[0].c_str());
		col1 = yxp_utility::atoi(pt[1].c_str());
		pt = yxp_utility::StrAlgo::split(pts[1], ',');
		row2 = yxp_utility::atoi(pt[0].c_str());
		col2 = yxp_utility::atoi((pt[1]).c_str());
	}

	void connectJoints(std::vector<std::vector<int>> &mat, int row1, int col1, int row2, int col2)
	{
		if (row1 == row2 && col1 == col2)
			return; //skip same points
		else if (row1 == row2)
		{
			int mincol = std::min(col1, col2);
			mat[row1 * 2 + 1][mincol * 2 + 2] = CellType::ROAD;
		}
		else if (col1 == col2)
		{
			int minrow = std::min(row1, row2);
			mat[minrow * 2 + 2][col1 * 2 + 1] = CellType::ROAD;
		}
	}

	void setRobotPos(std::vector<std::vector<int>> &mat, std::string&initPos, int &row_, int &col_)
	{
		if (initPos == "")
			return;
		auto ptStr = yxp_utility::StrAlgo::split(initPos, ' ');
		auto pt = yxp_utility::StrAlgo::split(ptStr[0], ',');
		int row = yxp_utility::atoi(std::string(pt[0]).c_str());
		int col = yxp_utility::atoi(std::string(pt[1]).c_str());
		mat[row * 2 + 1][col * 2 + 1] = CellType::ROBOTPOS;
		row_ = row * 2 + 1;
		col_ = col * 2 + 1;
	}

	void moveRobot(std::vector<std::vector<int>> &mat, std::string&initPos, int &row, int &col)
	{
		if (initPos == "")
			return;
		auto ptStr = yxp_utility::StrAlgo::split(initPos, ' ');
		if (ptStr.size() == 1)
			return;
		mat[row][col] = CellType::ROAD;
		std::string directionStr = ptStr[1];
		for (int i = 0; i < directionStr.size(); ++i)
		{
			switch (directionStr[i])
			{
			case 'W':
				if (row > 0 && mat[row - 1][col] != CellType::WALL)
					row -= 1;
				break;
			case 'A':
				if (col > 0 && mat[row][col - 1] != CellType::WALL)
					col -= 1;
				break;
			case 'S':
				if (row < mat.size() - 1 && mat[row + 1][col] != CellType::WALL)
					row += 1;
				break;
			case 'D':
				if (col < mat[0].size() - 1 && mat[row][col + 1] != CellType::WALL)
					col += 1;
				break;
			default:
				break;
			}
		}
		mat[row][col] = CellType::ROBOTPOS;
	}
};

