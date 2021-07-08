#ifndef TRANSACTION_H
#define TRANSACTION_H

#pragma once
#include "Block.h"
#include <string>
#include <vector>
class Transaction
{
private:
	//srcid, destid, pid, shid (shipping id), tag-info 
	std::string src_id_str;
	std::string dest_id_str;
	std::string pid_str;
	std::string shid_str;
	std::vector<std::string> carrier_tags;  /// Need to decide how we will represent these.




public:

	Transaction(const std::string &src_id, const std::string &dest_id, const std::string &pid, const std::string &shid, const std::vector<std::string> &tags)
	{
		this->src_id_str = src_id;
		this->dest_id_str = dest_id;
		this->pid_str = pid;
		this->shid_str = shid;
		this->carrier_tags = tags;


	}


	auto get_src() { return src_id_str; }

	auto get_dest() { return dest_id_str; }

	auto get_pid() { return pid_str; }

	auto get_shid() { return shid_str; }

	auto get_tags() { return carrier_tags; }




};

#endif