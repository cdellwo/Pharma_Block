#include "funcs.h"
#include "sha256.h"






void increment_entity_ids(std::vector<std::vector<Node* >> &all_nodes)
{
	std::vector<std::vector<Node*>>::iterator begin = all_nodes.begin();
	std::vector<std::vector<Node*>>::iterator end = all_nodes.end();
	int num_nodes = 0;
	for (auto i = begin; i != end; i++)
	{
		num_nodes += i->size();

	}
	//std::cout << "Number of nodes " << num_nodes;
	for (auto i = begin; i != end; i++)
	{
		for (auto j = i->begin(); j != i->end(); j++)
		{
			(*j)->increment_stake_id(num_nodes);  
		}


	}
	

}


void quorum_selection_test(std::vector<std::vector<Node*>>& all_nodes, int times_selected[4][20], std::string& prev_block_hash, int block_num)
{

	/*if ((block_num % 10) == 0)
	{
		increment_entity_ids(all_nodes);
	}*/

	std::string cur_hash = sha256(prev_block_hash);
	const int num_of_quorums = all_nodes.size() - 1;
	//std::cout << "Quorum selection test: \n" << "Number of potential quorums: " << num_of_quorums << std::endl;

	//std::cout << "Quorum size: " << quorum_size << std::endl;

	//increment_entity_ids(all_nodes);
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
	bool i_plus_one = false;
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
		std::default_random_engine rand_gen(cur_hash);
		std::uniform_int_distribution<int> distribution(0, pool_size-1);
		if (quorum_size % 2 == 0)
		{
			quorum_size += 1;
		}
		for (int j = 0; j < quorum_size; j++)
		{
			//cur_hash = cur_hash + std::to_string(j);
			//cur_hash = hash_string(cur_hash);
			cur_hash = cur_hash + std::to_string(j);
			cur_hash = sha256(cur_hash);
			//std::cout << cur_hash;

			//cur_hash = cur_hash.substr(0, cur_hash.size() / 4);
			hash_int_val = (std::stoull(cur_hash, nullptr, 16));



			//cur_selected = hash_int_val % pool_size;
			cur_selected = distribution(rand_gen);
			if (cur_selected > pool_1_size - 1) // cur selected is from entity group i + 1
			{
				duplicate = cur_quorum->add_member(all_nodes[i + 1][cur_selected - pool_1_size]);
				if (!duplicate)
				{
					times_selected[i + 1][cur_selected - pool_1_size] += 1;
				}
			}
			else
			{
				duplicate = cur_quorum->add_member(all_nodes[i][cur_selected]);
				if (!duplicate)
				{
					times_selected[i][cur_selected] += 1;
				}
				
			}
			//std::stoi(cur_hash, NULL, 16);

			//cur_option = hash_int_val % 2000;
			if (duplicate)
			{

				//std::cout << "duplicate";
				duplicate = false;
				j = j - 1;
				continue;
			}
			



		}
		/*std::cout << "Quorum " << i << ": \n";
		cur_quorum->print_quorum();*/
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


	for (int i = 0; i < num_of_quorums; i++)
	{
		the_quorums[i]->reset_membership();
	}
	//std::cout << "\nDone";
	//delete Quorum;



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


