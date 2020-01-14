#pragma once
#include <iostream>
#include <queue>
#include <string>
using namespace std;
template<class W>
struct HuffmanTreeNode {
	HuffmanTreeNode(const W& weight = W())
		:left(nullptr)
		, right(nullptr)
		,parent(nullptr)
		, _weight(weight)
	{}
	HuffmanTreeNode<W>* left;
	HuffmanTreeNode<W>* right;
	HuffmanTreeNode<W>* parent;
	W _weight;  //节点的权值
};

template<class W>
class Less {
	typedef HuffmanTreeNode<W> Node;
public:
	bool operator()(const Node* pLeft,const Node* pRight){
		return pLeft->_weight > pRight->_weight;
	}
};

template<class W>
class HuffmanTree {
	typedef HuffmanTreeNode<W> Node;
public:
	HuffmanTree()
		:_pRoot(nullptr)
	{}
	HuffmanTree(const vector<W>& vWeight,const W& ch){
		CreatHuffman(vWeight,ch);
	}
	~HuffmanTree()
	{
		_DestoryTree(_pRoot);
	}

	Node* getRoot() {
		return _pRoot;
	}
	void CreatHuffman(const vector<W>& vWeight,const W& ch) {
		//1.构造森林
		std::priority_queue<Node*,std::vector<Node*>,Less<W>> q;
		for (auto e : vWeight) {
			if (e == ch)continue;
			q.push(new Node(e));
		}
		//2.建树
		while (q.size() > 1) {
			Node *pLeft = q.top();
			q.pop();
			
			Node *pRight = q.top();
			q.pop();

			Node* pParent = new Node(pLeft->_weight + pRight->_weight);
			pParent->left = pLeft;
			pParent->right = pRight;

			pLeft->parent = pParent;
			pRight->parent = pParent;
			
			q.push(pParent);
		}
		_pRoot = q.top();
		_pRoot->parent = nullptr;
		q.pop();
	}
	void _DestoryTree(Node*& pParent) {//此处注意
		if (pParent !=nullptr) {
			_DestoryTree(pParent->left);
			_DestoryTree(pParent->right);
			delete pParent;
			pParent = nullptr;//注意测试别的情况
		}
	}

private:
	Node* _pRoot;
};
//void test1() {
//	vector<int> vv = { 3,1,7,5 };
//	HuffmanTree<int> h(vv,0);
//}