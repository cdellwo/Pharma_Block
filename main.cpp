#include "Block.h"

#include "Node.h"
#include "funcs.h"
#define NUM_OF_ENTITY_TYPES 4

int main(void)
{
	std::vector<Transaction> my_transacs;


	

	std::cout << "On line 14";

	std::vector<std::string> taags;



	taags.push_back("first_tag");

	taags.push_back("second_tag");



	Transaction t("Spokane", "Boise", "1234", "5678", taags);



	my_transacs.push_back(t);





	std::vector<std::string> sigs;

	sigs.push_back("first_sig");

	sigs.push_back("second_sig");







	Block my_block(0, my_transacs, sigs, "prev_hash hashy");





	//std::cout << "Prev hash: " << my_block.get_prev_hash() << std::endl;



	auto trans_vec = my_block.get_trans();

	//std::cout << "Source: ";

	for (auto itr : trans_vec)

	{

		//std::cout << itr.get_src() << " ";

	}

	//std::cout << "\nDestination: ";

	for (auto itr : trans_vec)

	{

		//std::cout << itr.get_dest() << " ";

	}



	std::cout << "";

	/*std::cout << "Sigs: " << my_block.get_sigs() << std::endl;

	std::cout << "Transactions: " << my_block.get_trans();*/
	




	std::vector<std::vector<Node*>> the_nodes;
	std::vector<Node* > all_nodes;
	std::vector<Node*> manu_nodes;
	for (int i = 60; i < 80; i++)
	{
		Node* cur_node = new Node("Manufacturer", i, 4);
		manu_nodes.push_back(cur_node);
		all_nodes.push_back(cur_node);
	}
	the_nodes.push_back(manu_nodes);



	std::vector<Node*> whare_nodes;
	for (int i = 40; i < 60; i++)
	{
		Node* cur_node = new Node("Wharehouse", i, 3);
		whare_nodes.push_back(cur_node);
		all_nodes.push_back(cur_node);
	}
	the_nodes.push_back(whare_nodes);



	std::vector<Node*> dist_nodes;
	for (int i = 20; i < 40; i++)
	{
		Node* cur_node = new Node("Distributer", i, 2);

		dist_nodes.push_back(cur_node);
		all_nodes.push_back(cur_node);

	}
	the_nodes.push_back(dist_nodes);



	std::vector<Node*> pharm_nodes;
	for (int i = 0; i < 20; i++)
	{
		Node *cur_node = new Node("Pharmacy", i, 1);

		pharm_nodes.push_back(cur_node);
		all_nodes.push_back(cur_node);

	}
	the_nodes.push_back(pharm_nodes);



	




	/*for (int i = 0; i < 5000; i++)
	{
		std::cout << the_nodes[i]->get_id_num() << " ";

	}*/

	std::string prev_block_str = "Hash of the previous blockss";

	int times_selected[4][20]{ 0 };
	std::cout << "Simulating quorum selection for 1,000 blocks:";
	for (int i = 0; i < 100000; i++)
	{
		//std::cout << "Test num: " << i << std::endl;
		//prev_block_str = prev_block_str + std::to_string(i)
		prev_block_str = std::to_string(i);
		quorum_selection_test(the_nodes, times_selected,  prev_block_str, i);
	}
	




	std::cout << "All done";




}

