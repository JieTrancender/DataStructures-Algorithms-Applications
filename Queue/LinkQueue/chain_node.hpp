#ifndef CHAINNODE_HPP
#define CHAINNODE_HPP

/*
@Author:Jie Mo
@Email:582865471@vip.qq.com
@Time:13th October
@Github:www.github.com/JieTrancender
*/

//MLQ stand for My Link Queue
namespace MLQ
{
	//链表节点的结构定义
	template <typename anytype>
	struct ChainNode
	{
		anytype element;
		ChainNode<anytype> *next;
		ChainNode() {};//默认构造函数
		ChainNode(const anytype &element)
		{
			this->element = element;
		}
		//构造函数:前向插入链表节点
		ChainNode(const anytype &element, ChainNode<anytype> *next)
		{
			this->element = element;
			this->next = next;
		}
	};
}

#endif
