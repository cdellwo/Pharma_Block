#include "funcs.h"
#include "sha256.h"

void quorum_selection_test(std::vector<std::vector<Node*>>& all_nodes, int num_entity_types, std::string& prev_block_hash)
{

	std::string cur_hash = sha256(prev_block_hash);
	const int num_of_quorums = all_nodes.size() - 1;
	std::cout << "Quorum selection test: \n" << "Number of potential quorums: " << num_of_quorums << std::endl;

	//std::cout << "Quorum size: " << quorum_size << std::endl;


	unsigned long long hash_int_val = 0;
	int cur_option = 0;
	std::vector<Quorum*> the_quorums;
	//const int quorum_size = std::ceil(std::log(all_nodes.size())); ///////CHANGE this connor. Not getting enough since length is num of vectors since we switched to multiple quorums
	unsigned short quorum_size = 0;
	/// ask if all quorums should be odd or if even is okay. 
	std::hash<std::string> hash_string;
	unsigned int pool_size = 0;
	unsigned int pool_1_size = 0;
	unsigned int pool_2_size = 0;
	unsigned int cur_selected = 0;
	bool duplicate = false; // cur node selected already in a pool?? or not. false obvs means not.
	int i = 0; 
	while (i < num_of_quorums)
	{
		std::vector<Node*> q_members;
		/*int q_src_1 = i;
		int q_src_2 = i + 1;*/
		pool_1_size = all_nodes[i].size();
		pool_2_size = all_nodes[i + 1].size();
		quorum_size = std::ceil(std::log(pool_1_size + pool_2_size));
		Quorum* cur_quorum = new Quorum(quorum_size);
		pool_size = pool_1_size + pool_2_size;
		if (quorum_size % 2 == 0)
		{
			quorum_size += 1;
		}
		for (int j = 0; j < quorum_size; j++)
		{
			//cur_hash = cur_hash + std::to_string(j);
			//cur_hash = hash_string(cur_hash);
			cur_hash = sha256(cur_hash + std::to_string(j));
			//std::cout << cur_hash;
			cur_hash = cur_hash.substr(0, cur_hash.size() / 4);
			hash_int_val = (std::stoull(cur_hash, nullptr, 16));


			cur_selected = hash_int_val % pool_size;
			if (cur_selected > pool_1_size - 1) // cur selected is from entity group i + 1
			{
				duplicate = cur_quorum->add_member(all_nodes[i + 1][cur_selected - pool_1_size]);
			}
			else
			{
				duplicate = cur_quorum->add_member(all_nodes[i][cur_selected]);
			}
			//std::stoi(cur_hash, NULL, 16);

			//cur_option = hash_int_val % 2000;
			if (duplicate)
			{
				duplicate = false;
				continue;
			}
			



		}
		std::cout << "Quorum " << i << ": \n";
		cur_quorum->print_quorum();
		the_quorums.push_back(cur_quorum);
		i++;

	}
	//for (int i = 0; i < num_of_quorums; i++)
	//{

	//	

	//	switch (i)
	//	{
	//	case 0: //size of selection pool == 2000, 1000 manufacturer, 1000 wharehouse 
	//	{
	//		
	//	}
	//		break;
	//	case 1: // size of selection pool == 2250, 1000 wharehouse, 1250 distributer
	//		break;
	//	case 2:
	//		break; //size of selection pool == 3000, 1750 pharmacy, 1250 distributer

	//	default:
	//		std::cout << "Error, code needs updating to support this number of quoroms. Disregard all results. Contact Connor.";

	//	}





	//	

	//	the_quorums.push_back(cur_quorum);

	std::cout << "\nDone";




	//}

}


void single_quorum_test(std::vector<std::vector<Node*>>& all_nodes, int num_entity_types, std::string& prev_block_hash)
{
	///Code following is code for forming a single quorum -- needs updating however, hash is not what should be used. Connor 7/6/21

//const int num_of_quorums = std::ceil(std::log(all_nodes.size()));


int num_nodes = all_nodes.size();
//int* q_members = new int[quorum_size];



std::string prev_hash = "dummy_str";

//time_t cur_time;
//time(&cur_time);

//auto prev_hash = cur_time;

//bool duplicate = false;
//for (int i = 0; i < quorum_size; i++)
//{
//	std::hash<int> cur_hash;

//	prev_hash = (cur_hash((prev_hash) + (i)));
//	
//	int cur_option = (prev_hash) % num_nodes;

//	for (int j = 0; j < i; j++)
//	{
//		if (q_members[j] == cur_option)
//		{
//			duplicate = true;
//		}

//	}
//	if (duplicate)
//	{
//		i = i - 1;
//		std::cout << "Duplicate averted...";
//		continue;
//	}
//	q_members[i] = cur_option;



//}

//std::cout << "Current quorum members: \n";
//for (int i = 0; i < quorum_size; i++)
//{
//	std::cout << "Member " << i << ": " << q_members[i] << std::endl;
//}


//delete[] q_members;
	


///Code following is code for forming a single quorum -- needs updating however, hash is not what should be used. Connor 7/6/21

//const int num_of_quorums = std::ceil(std::log(all_nodes.size()));


//int num_nodes = all_nodes.size();
//int* q_members = new int[quorum_size];



////std::string prev_hash = "dummy_str";

//time_t cur_time;
//time(&cur_time);

//auto prev_hash = cur_time;

//bool duplicate = false;
//for (int i = 0; i < quorum_size; i++)
//{
//	std::hash<int> cur_hash;

//	prev_hash = (cur_hash((prev_hash) + (i)));
//	
//	int cur_option = (prev_hash) % num_nodes;

//	for (int j = 0; j < i; j++)
//	{
//		if (q_members[j] == cur_option)
//		{
//			duplicate = true;
//		}

//	}
//	if (duplicate)
//	{
//		i = i - 1;
//		std::cout << "Duplicate averted...";
//		continue;
//	}
//	q_members[i] = cur_option;



//}

//std::cout << "Current quorum members: \n";
//for (int i = 0; i < quorum_size; i++)
//{
//	std::cout << "Member " << i << ": " << q_members[i] << std::endl;
//}


//delete[] q_members;

}


