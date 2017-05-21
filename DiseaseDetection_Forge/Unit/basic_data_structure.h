/**************************************************************************
File:         basic_data_structure.h
Author:       Song Xiaofeng
Date:         2016-05
Description:
**************************************************************************/
#pragma once
#include "basic_table_structure.h"
//////////////////////////////////////////////////////////////////
///    Class:  CAssetTreeNode
///    Brief:  
//////////////////////////////////////////////////////////////////
class CAssetTreeNode {
public:
	Data_Asset data;
	CAssetTreeNode * lchild; 
	CAssetTreeNode * rsibling;
public:
	CAssetTreeNode() {  lchild = NULL; rsibling = NULL; }
	CAssetTreeNode(const Data_Asset data ,CAssetTreeNode * lchild = NULL,
		CAssetTreeNode* rsibling = NULL) {
		this->data = data;
		this->lchild = lchild;
		this->rsibling = rsibling;
	}
	void addSibling(CAssetTreeNode* node) {
		if (this->rsibling == 0)
			this->rsibling = node;
		else {
			CAssetTreeNode * tmp = this->rsibling;
			while (tmp->rsibling != 0) { tmp = tmp->rsibling;  }
			tmp->rsibling = node;
		}
	}
};