/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		main.cpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	CPP01-ex04                             |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−02−01T04:15:58+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

#include "main.h"

std::string	sed_replace_line(std::string line, std::string str1, std::string str2)
{
	std::string	replaced;
	size_t		find_pos;

	find_pos = line.find(str1);
	if (find_pos == std::string::npos)
		return (line);
	while (find_pos != std::string::npos)
	{
		replaced += line.substr(0, find_pos);
		replaced += str2;
		line = std::string(line, find_pos + str1.size());
		find_pos = line.find(str1);
	}
	replaced += line;
	return (replaced);
}

int	sed_for_winner(std::string filename, std::string str1, std::string str2)
{
	std::ifstream		infile;
	std::ofstream		outfile;
	std::string			line;
	std::string			file_content;
	std::string			filename_out	= filename + ".replace";

	infile.open(filename.c_str());
	if (!infile.is_open())
		return (2);
	while (std::getline(infile, line))
		file_content += sed_replace_line(line, str1, str2) + '\n';
	infile.close();
	outfile.open(filename_out.c_str());
	if (!outfile.is_open())
		return (3);
	outfile.write(file_content.c_str(), file_content.size());
	outfile.close();
	return (0);
}

int	have_error(int r_value)
{
	if (r_value == 1)
		std::cerr << "wrong number of arg" << std::endl;
	else if (r_value == 2)
		std::cerr << "opening argv[1] for reading failed" << std::endl;
	else if (r_value == 3)
		std::cerr << "opening argv[1].replace for writing failed" << std::endl;
	return (r_value);
}

int	main(int argc, char **argv)
{
	int	r_value = 0;

	if (argc != 4)
		return (have_error(1));
	r_value = sed_for_winner(argv[1], argv[2], argv[3]);
	return (have_error(r_value));
}
