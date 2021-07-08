#include "Block.h"

#include "Node.h"
#include "funcs.h"
#define NUM_OF_ENTITY_TYPES 4

int main(void)
{
	std::vector<Transaction> my_transacs;



	std::vector<std::string> taags;



	taags.push_back("first_tag");

	taags.push_back("second_tag");



	Transaction t("Spokane", "Boise", "1234", "5678", taags);



	my_transacs.push_back(t);





	std::vector<std::string> siggs;

	siggs.push_back("first_sig");

	siggs.push_back("second_sig");







	Block my_block(0, my_transacs, siggs, "prev_hash hashy");





	std::cout << "Prev hash: " << my_block.get_prev_hash() << std::endl;



	auto trans_vec = my_block.get_trans();

	std::cout << "Source: ";

	for (auto itr : trans_vec)

	{

		std::cout << itr.get_src() << " ";

	}

	std::cout << "\nDestination: ";

	for (auto itr : trans_vec)

	{

		std::cout << itr.get_dest() << " ";

	}



	std::cout << "";

	/*std::cout << "Sigs: " << my_block.get_sigs() << std::endl;

	std::cout << "Transactions: " << my_block.get_trans();*/
	




	std::vector<std::vector<Node*>> the_nodes;

	std::vector<Node*> manu_nodes;
	for (int i = 4000; i < 5000; i++)
	{
		Node* cur_node = new Node("Manufacturer", i, 4);
		manu_nodes.push_back(cur_node);
	}
	the_nodes.push_back(manu_nodes);



	std::vector<Node*> whare_nodes;
	for (int i = 3000; i < 4000; i++)
	{
		Node* cur_node = new Node("Wharehouse", i, 3);
		whare_nodes.push_back(cur_node);

	}
	the_nodes.push_back(whare_nodes);



	std::vector<Node*> dist_nodes;
	for (int i = 1750; i < 3000; i++)
	{
		Node* cur_node = new Node("Distributer", i, 2);

		dist_nodes.push_back(cur_node);


	}
	the_nodes.push_back(dist_nodes);



	std::vector<Node*> pharm_nodes;
	for (int i = 0; i < 1750; i++)
	{
		Node *cur_node = new Node("Pharmacy", i, 1);

		pharm_nodes.push_back(cur_node);


	}
	the_nodes.push_back(pharm_nodes);



	




	/*for (int i = 0; i < 5000; i++)
	{
		std::cout << the_nodes[i]->get_id_num() << " ";

	}*/

	std::string prev_block_str = "Hash of the previous blockss";

	for (int i = 0; i < 1; i++)
	{
		std::cout << "Test num: " << i << std::endl;
		quorum_selection_test(the_nodes, 4,  prev_block_str);
	}
	

}

